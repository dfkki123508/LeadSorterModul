/**
 * Main functionality, uses GNSDK and FFmpeg
 *
 */


#define GNSDK_MUSICID          		1
#define GNSDK_MUSICID_STREAM       	1
#define GNSDK_DSP                   1

#include "gnsdk.h"

/* Standard C headers - used by the sample app, but not required for GNSDK */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gnsdk_musicid_file.h>
#include <stdint.h>

#include "DecodeContainer.h"

static int
init_gnsdk(const char *client_id,
		   const char *client_id_tag,
		   const char *client_app_version,
		   const char *license_path,
		   gnsdk_user_handle_t *p_user_handle,
		   gnsdk_manager_handle_t *p_man_handle);

static int
process_audio(
		gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle,
		gnsdk_cstr_t s_audio_file);

void
get_gdo_rendered_full(
		gnsdk_musicidfile_query_handle_t query_handle,
		gnsdk_str_t *result_str);

void
get_gdo_rendered_min(
		gnsdk_musicidfile_query_handle_t query_handle,
		char *result_str);


char* lookup_audio(const char* client_id,
				   const char* client_id_tag,
				   const char* license_path,
				   const char* file_path,
                   const char* result_str)
{
//	printf("Starting... log lvl %d\n", av_log_get_level());

	// Set verbosity
	av_log_set_level(0);

	gnsdk_manager_handle_t 				sdkmgr_handle	   	= GNSDK_NULL;
	gnsdk_user_handle_t 				user_handle        	= GNSDK_NULL;
	gnsdk_musicidfile_query_handle_t 	query_handle  		= GNSDK_NULL;
	gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle		= GNSDK_NULL;
//	char 			result_str[1024] 	= {0};
//	const char*		client_id 			= "1312006557";
//	const char*		client_id_tag 		= "9CE95C3EBC19CBA3C1F0C604EDA46464";
	const char*		client_app_version 	= "1.0.0.0"; /* Version of your application */
//	const char*		license_path 		= "/home/dudeson/Documents/gnsdk/LICENSE";
//	const char*		file_path 			= "/home/dudeson/Music/TEST/Queen - Bohemian Rhapsody (Official Video).mp3";
	int rc = 0;

	// Check if file is mp3 by file extension
	if (check_file_extension(file_path,"mp3") < 1){
		fprintf(stderr,"Warning: No mp3 extension! file %s!\n", file_path);
//		return "";
	}

	//  Initialize the GNSDK and the MusicID-File and DSP (for fingerprinting) modules
//	printf("Initializing...\n");
	rc = init_gnsdk(
			client_id,
			client_id_tag,
			client_app_version,
			license_path,
			&user_handle,
			&sdkmgr_handle
	);

	//	Create a MusicID-File query handle
//	printf("Create Query handle...\n");
	gnsdk_musicidfile_query_create(
			user_handle,
			GNSDK_NULL,       /* Callback function for status and progress */
			GNSDK_NULL,       /* Callback data */
			&query_handle
	);

	//	Create a FileInfo object for each media file you want to submit and add to MusicID-File query handle
//	printf("Create Fileinfo object...\n");
	gnsdk_musicidfile_query_fileinfo_create(
			query_handle,              /* MusicID-File query handle to create FileInfo for */
			file_path,                 /* Media file path */
			GNSDK_NULL,                /* No callback function for status and progress */
			GNSDK_NULL,                /* No callback data */
			&fileinfo_handle           /* Pointer to receive created FileInfo */
	);

	//	Add identification (fingerprinting and metadata) to each FileInfo object
//	printf("Fingerprinting...\n");
	process_audio( fileinfo_handle, file_path);


	//	Make TrackID or AlbumID query
//	printf("Make query...\n");
	gnsdk_uint32_t midf_options = GNSDK_MUSICIDFILE_QUERY_FLAG_RETURN_SINGLE |
								  GNSDK_MUSICIDFILE_QUERY_FLAG_NO_THREADS;
	gnsdk_musicidfile_query_do_trackid(query_handle, midf_options);

	//	Handle query results and statuses
//	printf("Waiting...\n");
	gnsdk_musicidfile_query_wait_for_complete(
			query_handle,
			GNSDK_MUSICIDFILE_TIMEOUT_INFINITE,  /* Time to wait in milliseconds or until done (INFINITE) */
			GNSDK_NULL                           /* Pointer to error returned upon completion */
	);

	//  Process responses
//	printf("Process responses...\n");
	get_gdo_rendered_min(query_handle, result_str);
	if (result_str == GNSDK_NULL)
	{
		fprintf(stderr, "Result is NULL\n");
		rc = -1;
		return "";
	}

//	printf("Result: %s\n", result_str);

	//	Release resources and shutdown MusicID-File, DSP, and GNSDK
	gnsdk_musicidfile_query_release(query_handle);
	gnsdk_musicidfile_shutdown();

	return 0;
}

/******************************************************************
 *
 *    _DISPLAY_LAST_ERROR
 *
 *    Echo the error and information.
 *
 *****************************************************************/
static void
_display_last_error(
		int line_num
)
{
	/* Get the last error information from the SDK */
	const gnsdk_error_info_t* error_info = gnsdk_manager_error_info();


	/* Error_info will never be GNSDK_NULL.
	 * The SDK will always return a pointer to a populated error info structure.
	 */
	printf(
			"\nerror from: %s()  [on line %d]\n\t0x%08x %s\n",
			error_info->error_api,
			line_num,
			error_info->error_code,
			error_info->error_description
	);

} /* _display_last_error() */


/******************************************************************
 *
 *    _GET_USER_HANDLE
 *
 *    Load existing user handle, or register new one.
 *
 *    GNSDK requires a user handle instance to perform queries.
 *    User handles encapsulate your Gracenote provided Client ID
 *    which is unique for your application. User handles are
 *    registered once with Gracenote then must be saved by
 *    your application and reused on future invocations.
 *
 *****************************************************************/
static int
get_user_handle(
		const char*          client_id,
		const char*          client_id_tag,
		const char*          client_app_version,
		gnsdk_user_handle_t* p_user_handle
)
{
	gnsdk_user_handle_t user_handle               = GNSDK_NULL;
	gnsdk_cstr_t		user_reg_mode             = GNSDK_NULL;
	gnsdk_str_t         serialized_user           = GNSDK_NULL;
	gnsdk_char_t		serialized_user_buf[1024] = {0};
	gnsdk_bool_t        b_localonly               = GNSDK_FALSE;
	gnsdk_error_t       error                     = GNSDK_SUCCESS;
	FILE*               file                      = NULL;
	int                 rc                        = 0;

	/* Creating a GnUser is required before performing any queries to Gracenote services,
	 * and such APIs in the SDK require a GnUser to be provided. GnUsers can be created
	 * 'Online' which means they are created by the Gracenote backend and fully vetted.
	 * Or they can be create 'Local Only' which means they are created locally by the
	 * SDK but then can only be used locally by the SDK.
	 */
	user_reg_mode = GNSDK_USER_REGISTER_MODE_ONLINE;


	/* Do we have a user saved locally? */
	file = fopen("user.txt", "r");
	if (file)
	{
		fgets(serialized_user_buf, sizeof(serialized_user_buf), file);
		fclose(file);

		/* Create the user handle from the saved user */
		error = gnsdk_manager_user_create(serialized_user_buf, client_id, &user_handle);
		if (GNSDK_SUCCESS == error)
		{
			error = gnsdk_manager_user_is_localonly(user_handle, &b_localonly);
			if (!b_localonly || (strcmp(user_reg_mode, GNSDK_USER_REGISTER_MODE_LOCALONLY) == 0))
			{
				*p_user_handle = user_handle;
				return 0;
			}

			/* else desired regmode is online, but user is localonly - discard and register new online user */
			gnsdk_manager_user_release(user_handle);
		}

		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
		}
	}
	else
	{
		printf("\nInfo: No stored user - this must be the app's first run.\n");
	}

	/*
	 * Register new user
	 */
	error = gnsdk_manager_user_register(
			user_reg_mode,
			client_id,
			client_id_tag,
			client_app_version,
			&serialized_user
	);
	if (GNSDK_SUCCESS == error)
	{
		/* Create the user handle from the newly registered user */
		error = gnsdk_manager_user_create(serialized_user, client_id, &user_handle);
		if (GNSDK_SUCCESS == error)
		{
			/* save newly registered user for use next time */
			file = fopen("user.txt", "w");
			if (file)
			{
				fputs(serialized_user, file);
				fclose(file);
			}
		}

		gnsdk_manager_string_free(serialized_user);
	}

	if (GNSDK_SUCCESS == error)
	{
		*p_user_handle = user_handle;
		rc = 0;
	}
	else
	{
		_display_last_error(__LINE__);
		rc = -1;
	}

	return rc;

} /* _get_user_handle() */


/*****************************************************************************
 *
 *    _SET_LOCALE
 *
 *  Set application locale. Note that this is only necessary if you are using
 *  locale-dependant fields such as genre, mood, origin, era, etc. Your app
 *  may or may not be accessing locale_dependent fields, but it does not hurt
 *  to do this initialization as a matter of course .
 *
 ****************************************************************************/
static int
set_locale(
		gnsdk_user_handle_t user_handle
)
{
	gnsdk_locale_handle_t locale_handle = GNSDK_NULL;
	gnsdk_error_t         error         = GNSDK_SUCCESS;
	int                   rc            = 0;


	error = gnsdk_manager_locale_load(
			GNSDK_LOCALE_GROUP_MUSIC,               /* Locale group */
			GNSDK_LANG_ENGLISH,                     /* Language */
			GNSDK_REGION_DEFAULT,                   /* Region */
			GNSDK_DESCRIPTOR_SIMPLIFIED,            /* Descriptor */
			user_handle,                            /* User handle */
			GNSDK_NULL,                             /* User callback function */
			0,                                      /* Optional data for user callback function */
			&locale_handle                          /* Return handle */
	);
	if (GNSDK_SUCCESS == error)
	{
		/* Setting the 'locale' as default
		 * If default not set, no locale-specific results would be available
		 */
		error = gnsdk_manager_locale_set_group_default(locale_handle);
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
			rc = -1;
		}

		/* The manager will hold onto the locale when set as default
		 * so it's ok to release our reference to it here
		 */
		gnsdk_manager_locale_release(locale_handle);
	}
	else
	{
		_display_last_error(__LINE__);
		rc = -1;
	}

	return rc;

}  /* _set_locale() */


/***************************************************************************
 *
 *    _SHUTDOWN_GNSDK
 *
 *     When your program is terminating, or you no longer need GNSDK, you should
 *     call gnsdk_manager_shutdown(). No other shutdown operations are required.
 *     gnsdk_manager_shutdown() also shuts down all other modules, regardless
 *     of the number of times they have been initialized.
 *     You can shut down individual modules while your program is running with
 *     their dedicated shutdown functions in order to free up resources.
 *
 ***************************************************************************/
static void
shutdown_gnsdk(
		gnsdk_user_handle_t user_handle
)
{
	gnsdk_error_t error = GNSDK_SUCCESS;

	error = gnsdk_manager_user_release(user_handle);
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
	}

	/* Shutdown the Manager to shutdown all libraries */
	gnsdk_manager_shutdown();

}  /* _shutdown_gnsdk() */


static int
init_gnsdk(const char *client_id,
		   const char *client_id_tag,
		   const char *client_app_version,
		   const char *license_path,
		   gnsdk_user_handle_t *p_user_handle,
		   gnsdk_manager_handle_t *p_man_handle)
{
	gnsdk_manager_handle_t sdkmgr_handle = GNSDK_NULL;
	gnsdk_error_t          error         = GNSDK_SUCCESS;
	gnsdk_user_handle_t    user_handle   = GNSDK_NULL;
	int                    rc            = 0;

	// init manager
	error = gnsdk_manager_initialize(&sdkmgr_handle,license_path,GNSDK_MANAGER_LICENSEDATA_FILENAME);
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
		return -1;
	}

	// init musicid-file
	error = gnsdk_musicidfile_initialize(sdkmgr_handle);
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
		return -1;
	}

	// init dsp module
	error = gnsdk_dsp_initialize(sdkmgr_handle);          /* Required for fingerprinting */
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
		return -1;
	}

	/* Get a user handle for our client ID.  This will be passed in for all queries */
	if (0 == rc)
	{
		rc = get_user_handle(
				client_id,
				client_id_tag,
				client_app_version,
				&user_handle
		);
	}

	/* Set the 'locale' to return locale-specifc results values. This examples loads an English locale. */
//	if (0 == rc)
//	{
//		rc = set_locale(user_handle);
//	}

	if (0 != rc)
	{
		/* Clean up on failure. */
		shutdown_gnsdk(user_handle);
	}
	else
	{
		/* return the User handle for use at query time */
		*p_user_handle	= user_handle;
	}

	*p_man_handle	= sdkmgr_handle;

	return rc;
}



int is_wav_file(gnsdk_cstr_t s_audio_file)
{
	char* ext = strrchr(s_audio_file, '.');
	if (ext) {
		printf("\textension is %s\n", ++ext);
		if ((strcmp(ext,"wav") == 0) || (strcmp(ext,"WAV"))) {
			return 1;
		}
		return 0;
	}
	return -1;
}

int check_file_extension(gnsdk_cstr_t s_audio_file, gnsdk_cstr_t ext)
{
	char* pt = strrchr(s_audio_file, '.');
	if (pt) {
		if (strcmp(++pt,ext) == 0) {
			return 1;
		}
		return 0;
	}
	return -1;
}


/***************************************************************************
 *
 *    _PROCESS_AUDIO
 *
 * This function simulates streaming audio into the Channel handle to give
 * MusicId-Stream audio to identify
 *
 ***************************************************************************/
static int
process_audio(
		gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle,
		gnsdk_cstr_t s_audio_file
)
{
	gnsdk_error_t 	error           = GNSDK_SUCCESS;
	gnsdk_bool_t  	complete		= GNSDK_FALSE;
//	gnsdk_byte_t  	pcm_audio[2048] = {0};
	FILE*         	p_file          = NULL;
	DecodeContainer dec_ctn;
	int			  	read_size		= 0;
	int			  	skip_frames	  	= 5;
	int           	rc              = 0;
	int			  	i;

	init_decode_container(&dec_ctn,s_audio_file);

//	printf("\tsample rate: %d, ch: %d\n",dec_ctn.audio_dec_ctx->sample_rate,dec_ctn.audio_dec_ctx->channels);

	/* initialize the fingerprinter
	   Note: The sample file shipped is a 44100Hz 16-bit stereo (2 channel) wav file */
	error = gnsdk_musicidfile_fileinfo_fingerprint_begin(
			fileinfo_handle,
			dec_ctn.audio_dec_ctx->sample_rate, 16, dec_ctn.audio_dec_ctx->channels
	);
	if (GNSDK_SUCCESS != error)
	{
		_display_last_error(__LINE__);
		fclose(p_file);
		return -1;
	}

	// skip first frames, since error: "header missing"
	// raises when avcodec_send_packet is called
	for (i = 0; i < skip_frames;i++) {
		if (av_read_frame(dec_ctn.fmt_ctx, &(dec_ctn.pkt)) < 0) {
			return -1;
		}
	}

	read_size = get_next_chunk(&dec_ctn);
	while (read_size > 0)
	{
		if (complete == GNSDK_TRUE)
		{
//			printf("\tCompleted (before stream end!).\n");
			break;
		}

//		printf("Read %d byte\n", read_size);
		/* write audio to the fingerprinter */
		error = gnsdk_musicidfile_fileinfo_fingerprint_write(
				fileinfo_handle,
				dec_ctn.data,
				read_size,
				&complete
		);
		if (GNSDK_SUCCESS != error)
		{
			if (GNSDKERR_SEVERE(error)) /* 'aborted' warnings could come back from write which should be expected */
			{
				_display_last_error(__LINE__);
			}
			rc = -1;
			break;
		}

		read_size = get_next_chunk(&dec_ctn);
	}

	release_decode_container(&dec_ctn);

	/*signal that we are done*/
	if (GNSDK_SUCCESS == error)
	{
		error = gnsdk_musicidfile_fileinfo_fingerprint_end(fileinfo_handle);
		if (GNSDK_SUCCESS != error)
		{
			_display_last_error(__LINE__);
		}
	}

	return rc;

}  /* _process_audio() */


/***************************************************************************
 *
 *    _DISPLAY_TRACK_GDO
 *
 ***************************************************************************/
static void
_display_track_gdo(
		gnsdk_gdo_handle_t track_gdo
)
{
	gnsdk_error_t      error     = GNSDK_SUCCESS;
	gnsdk_gdo_handle_t title_gdo = GNSDK_NULL;
	gnsdk_cstr_t       value     = GNSDK_NULL;
	// gnsdk_cstr_t       value_2     = GNSDK_NULL;

	/* Track Title */
	error = gnsdk_manager_gdo_child_get( track_gdo, GNSDK_GDO_CHILD_TITLE_OFFICIAL, 1, &title_gdo );
	if (GNSDK_SUCCESS == error)
	{
		error = gnsdk_manager_gdo_value_get( title_gdo, GNSDK_GDO_VALUE_DISPLAY, 1, &value );
		if (GNSDK_SUCCESS == error)
		{
			printf( "\"%s\": \"%s\"", "track", value );
		}
		else
		{
			_display_last_error(__LINE__);
		}
		gnsdk_manager_gdo_release(title_gdo);
	}
	else
	{
		_display_last_error(__LINE__);
	}

	/* Track number on album. */
	// error = gnsdk_manager_gdo_value_get( track_gdo, GNSDK_GDO_VALUE_TRACK_NUMBER, 1, &value_1 );
	// if (GNSDK_SUCCESS == error)
	// {
	// 	printf( "%26s %s\n", "Track number:", value_1 );
	// }
	// else
	// {
	// 	_display_last_error(__LINE__);
	// }

	/* Track duration. */
	// error = gnsdk_manager_gdo_value_get( track_gdo, GNSDK_GDO_VALUE_DURATION, 1, &value_1 );
	// if (GNSDK_SUCCESS == error)
	// {
	// 	error = gnsdk_manager_gdo_value_get( track_gdo, GNSDK_GDO_VALUE_DURATION_UNITS, 1, &value_2 );
	// 	if (GNSDK_SUCCESS == error)
	// 	{
	// 		printf( "%26s %s %s\n", "Track duration:", value_1, value_2 );
	// 	}
	// 	else
	// 	{
	// 		_display_last_error(__LINE__);
	// 	}
	// }
	// else
	// {
	// 	_display_last_error(__LINE__);
	// }

	/* Position in track where the fingerprint matched. */
	// error = gnsdk_manager_gdo_value_get( track_gdo, GNSDK_GDO_VALUE_MATCH_POSITION_MS, 1, &value_1 );
	// if (GNSDK_SUCCESS == error)
	// {
	// 	printf( "%26s %s ms\n", "Match position:", value_1 );
	// }
	// else
	// {
	// 	_display_last_error(__LINE__);
	// }

	/* Duration of the matched fingerprint. */
	// error = gnsdk_manager_gdo_value_get( track_gdo, GNSDK_GDO_VALUE_MATCH_DURATION_MS, 1, &value_1 );
	// if (GNSDK_SUCCESS == error)
	// {
	// 	printf( "%26s %s ms\n", "Match duration:", value_1 );
	// }

}  /* _display_track_gdo() */


static void
get_track_string(
		gnsdk_gdo_handle_t track_gdo,
		char* result_str
)
{
	gnsdk_error_t error = GNSDK_SUCCESS;
	gnsdk_gdo_handle_t title_gdo = GNSDK_NULL;
	gnsdk_cstr_t value = GNSDK_NULL;
	// gnsdk_cstr_t       value_2     = GNSDK_NULL;

	/* Track Title */
	error = gnsdk_manager_gdo_child_get(track_gdo, GNSDK_GDO_CHILD_TITLE_OFFICIAL, 1, &title_gdo);
	if (GNSDK_SUCCESS == error) {
		error = gnsdk_manager_gdo_value_get(title_gdo, GNSDK_GDO_VALUE_DISPLAY, 1, &value);
		if (GNSDK_SUCCESS == error) {
			sprintf(result_str + strlen(result_str), "\"%s\": \"%s\"", "track", value);
		} else {
			_display_last_error(__LINE__);
		}
		gnsdk_manager_gdo_release(title_gdo);
	} else {
		_display_last_error(__LINE__);
	}
}

/***************************************************************************
 *
 *    _DISPLAY_ALBUM_GDO
 *
 ***************************************************************************/
static void
_display_album_gdo(
		gnsdk_gdo_handle_t album_gdo
)
{
	gnsdk_error_t      error     = GNSDK_SUCCESS;
	gnsdk_gdo_handle_t title_gdo = GNSDK_NULL;
	gnsdk_gdo_handle_t track_gdo = GNSDK_NULL;
	gnsdk_gdo_handle_t artist_gdo = GNSDK_NULL;
	gnsdk_cstr_t       value     = GNSDK_NULL;

	printf("{");

	/* Artist Title */
	error = gnsdk_manager_gdo_child_get( album_gdo, GNSDK_GDO_CHILD_ARTIST, 1, &artist_gdo );
	if (GNSDK_SUCCESS == error)
	{
		error = gnsdk_manager_gdo_child_get( artist_gdo, GNSDK_GDO_CHILD_NAME_OFFICIAL, 1, &title_gdo );
		if (GNSDK_SUCCESS == error)
		{
			error = gnsdk_manager_gdo_value_get( title_gdo, GNSDK_GDO_VALUE_DISPLAY, 1, &value );
			if (GNSDK_SUCCESS == error)
			{
				printf( "\"%s\": \"%s\", ", "artist", value );
			}
			else
			{
				_display_last_error(__LINE__);
			}
			gnsdk_manager_gdo_release(title_gdo);
		}
		else
		{
			_display_last_error(__LINE__);
		}
		gnsdk_manager_gdo_release(artist_gdo);
	}
	else
	{
		_display_last_error(__LINE__);
	}


	/* Album Title */
	error = gnsdk_manager_gdo_child_get( album_gdo, GNSDK_GDO_CHILD_TITLE_OFFICIAL, 1, &title_gdo );
	if (GNSDK_SUCCESS == error)
	{
		error = gnsdk_manager_gdo_value_get( title_gdo, GNSDK_GDO_VALUE_DISPLAY, 1, &value );
		if (GNSDK_SUCCESS == error)
		{
			printf( "\"%s\": \"%s\", ", "album", value );

			/* Matched track number. */
			error = gnsdk_manager_gdo_value_get( album_gdo, GNSDK_GDO_VALUE_TRACK_MATCHED_NUM, 1, &value );
			if (GNSDK_SUCCESS == error)
			{
				error = gnsdk_manager_gdo_child_get( album_gdo, GNSDK_GDO_CHILD_TRACK_MATCHED, 1, &track_gdo );
				if (GNSDK_SUCCESS == error)
				{
					_display_track_gdo(track_gdo);
					gnsdk_manager_gdo_release(track_gdo);
				}
				else
				{
					_display_last_error(__LINE__);
				}
			}
			else
			{
				_display_last_error(__LINE__);
			}
		}
		else
		{
			_display_last_error(__LINE__);
		}
		gnsdk_manager_gdo_release(title_gdo);
	}
	else
	{
		_display_last_error(__LINE__);
	}

	printf("}");

}  /* _display_album_gdo() */


/***************************************************************************
 *
 *    RENDER_MIN_GDO as JSON {artist:value, album:value, track:value}
 *
 ***************************************************************************/
static void
render_min_gdo(
		gnsdk_gdo_handle_t album_gdo,
		char* result_str
)
{
	gnsdk_error_t      	error     	= GNSDK_SUCCESS;
	gnsdk_gdo_handle_t 	title_gdo 	= GNSDK_NULL;
	gnsdk_gdo_handle_t 	track_gdo 	= GNSDK_NULL;
	gnsdk_gdo_handle_t 	artist_gdo 	= GNSDK_NULL;
	gnsdk_cstr_t       	value     	= GNSDK_NULL;

	sprintf(result_str, "{");

	/* Artist Title */
	error = gnsdk_manager_gdo_child_get( album_gdo, GNSDK_GDO_CHILD_ARTIST, 1, &artist_gdo );
	if (GNSDK_SUCCESS == error)
	{
		error = gnsdk_manager_gdo_child_get( artist_gdo, GNSDK_GDO_CHILD_NAME_OFFICIAL, 1, &title_gdo );
		if (GNSDK_SUCCESS == error)
		{
			error = gnsdk_manager_gdo_value_get( title_gdo, GNSDK_GDO_VALUE_DISPLAY, 1, &value );
			if (GNSDK_SUCCESS == error)
			{
//				printf("%s strlen %d\n",result_str, strlen(result_str));
				sprintf(result_str + strlen(result_str), "\"%s\": \"%s\", ", "artist", value );
			}
			else
			{
				_display_last_error(__LINE__);
			}
			gnsdk_manager_gdo_release(title_gdo);
		}
		else
		{
			_display_last_error(__LINE__);
		}
		gnsdk_manager_gdo_release(artist_gdo);
	}
	else
	{
		_display_last_error(__LINE__);
	}


	/* Album Title */
	error = gnsdk_manager_gdo_child_get( album_gdo, GNSDK_GDO_CHILD_TITLE_OFFICIAL, 1, &title_gdo );
	if (GNSDK_SUCCESS == error)
	{
		error = gnsdk_manager_gdo_value_get( title_gdo, GNSDK_GDO_VALUE_DISPLAY, 1, &value );
		if (GNSDK_SUCCESS == error)
		{

//			printf("%s strlen %d\n",result_str, strlen(result_str));
			sprintf(result_str+ strlen(result_str), "\"%s\": \"%s\", ", "album", value );

			/* Matched track number. */
			error = gnsdk_manager_gdo_value_get( album_gdo, GNSDK_GDO_VALUE_TRACK_MATCHED_NUM, 1, &value );
			if (GNSDK_SUCCESS == error)
			{
				error = gnsdk_manager_gdo_child_get( album_gdo, GNSDK_GDO_CHILD_TRACK_MATCHED, 1, &track_gdo );
				if (GNSDK_SUCCESS == error)
				{
//					_display_track_gdo(track_gdo);
					get_track_string(track_gdo,result_str);
					gnsdk_manager_gdo_release(track_gdo);
				}
				else
				{
					_display_last_error(__LINE__);
				}
			}
			else
			{
				_display_last_error(__LINE__);
			}
		}
		else
		{
			_display_last_error(__LINE__);
		}
		gnsdk_manager_gdo_release(title_gdo);
	}
	else
	{
		_display_last_error(__LINE__);
	}


	sprintf(result_str+ strlen(result_str), "}");

}  /* _display_album_gdo() */


void get_gdo_rendered_full(gnsdk_musicidfile_query_handle_t query_handle, gnsdk_str_t *result_str)
{
	gnsdk_uint32_t  count = 0;
	gnsdk_musicidfile_query_fileinfo_count(query_handle, &count);
	gnsdk_musicidfile_fileinfo_handle_t file_info;

	if (count == 0)
	{
//		printf("No infos found for the input.\n");
		return;
	}
//	printf("Found %d infos.\n", count);
	for (int i = 0; i < count; i++)
	{
		gnsdk_musicidfile_query_fileinfo_get_by_index(query_handle, i, &file_info);

		gnsdk_musicidfile_fileinfo_status_t  fileinfo_status = gnsdk_musicidfile_fileinfo_unprocessed;
		gnsdk_error_info_t*                  p_error_info    = GNSDK_NULL;
		gnsdk_gdo_handle_t                   response_gdo    = GNSDK_NULL;
		gnsdk_error_t 						 error           = GNSDK_SUCCESS;

		/*
		 * Check status. If ok, get Response GDO
 		 */
		gnsdk_musicidfile_fileinfo_status(file_info, &fileinfo_status, &p_error_info);
		if (gnsdk_musicidfile_fileinfo_error != fileinfo_status)
		{
			if ((gnsdk_musicidfile_fileinfo_result_single == fileinfo_status) ||
				(gnsdk_musicidfile_fileinfo_result_all == fileinfo_status))
			{
				gnsdk_musicidfile_fileinfo_get_response_gdo(file_info, &response_gdo);

				// Parse Response GDO
//				_display_album_gdo(response_gdo);

//				gnsdk_str_t 	result_str = GNSDK_NULL;
				error = gnsdk_manager_gdo_render(
										response_gdo,
										GNSDK_GDO_RENDER_DEFAULT | GNSDK_GDO_RENDER_JSON,
										result_str
								);

				if (GNSDK_SUCCESS != error)
				{
					_display_last_error(__LINE__);
					*result_str = GNSDK_NULL;
					return;
				}

			}
		}
	}

}


void get_gdo_rendered_min(gnsdk_musicidfile_query_handle_t query_handle, char* result_str)
{
	gnsdk_uint32_t  count = 0;
	gnsdk_musicidfile_query_fileinfo_count(query_handle, &count);
	gnsdk_musicidfile_fileinfo_handle_t file_info;

	if (count == 0)
	{
//		printf("No infos found for the input.\n");
		return;
	}
//	printf("Found %d infos.\n", count);
	for (int i = 0; i < count; i++)
	{
		gnsdk_musicidfile_query_fileinfo_get_by_index(query_handle, i, &file_info);

		gnsdk_musicidfile_fileinfo_status_t  fileinfo_status = gnsdk_musicidfile_fileinfo_unprocessed;
		gnsdk_error_info_t*                  p_error_info    = GNSDK_NULL;
		gnsdk_gdo_handle_t                   response_gdo    = GNSDK_NULL;
		gnsdk_error_t 						 error           = GNSDK_SUCCESS;
		gnsdk_gdo_handle_t 					 album_gdo		 = GNSDK_NULL;
		/*
		 * Check status. If ok, get Response GDO
 		 */
		gnsdk_musicidfile_fileinfo_status(file_info, &fileinfo_status, &p_error_info);
		if (gnsdk_musicidfile_fileinfo_error != fileinfo_status)
		{
			if ((gnsdk_musicidfile_fileinfo_result_single == fileinfo_status) ||
				(gnsdk_musicidfile_fileinfo_result_all == fileinfo_status))
			{
				gnsdk_musicidfile_fileinfo_get_response_gdo(file_info, &response_gdo);


				error = gnsdk_manager_gdo_child_get(
						response_gdo,
						GNSDK_GDO_CHILD_ALBUM,
						1,                 /* n'th instance (1-based) */
						&album_gdo
				);

				// Parse Response GDO
				render_min_gdo(album_gdo, result_str);


			}
		}
	}


}
