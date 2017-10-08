/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */

#ifndef _GNSDK_MUSICID_STREAM_H_
#define _GNSDK_MUSICID_STREAM_H_

#include "gnsdk_status.h"
#include "gnsdk_manager_gdo.h"

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************
 * Typedefs
 ******************************************************************************/

/** @internal gnsdk_musicidstream_channel_handle_t @endinternal
 *  Handle to channel instance for MusicID-Stream. The application creates this handle
 *  for each channel designated for MusicID-Stream fingerprint generation and recognition.
 *  <p><b>Remarks:</b></p>
 *  An application may create as many of these handles as needed using 
 *  gnsdk_musicidstream_channel_create()
 * @ingroup Music_MusicIDStream_TypesEnums
 */
GNSDK_DECLARE_HANDLE( gnsdk_musicidstream_channel_handle_t );



/********************************************************************************
 * MusicID-Stream SDK Initialization APIs
 ******************************************************************************/


/** @internal gnsdk_musicidstream_initialize @endinternal
 *  Initializes Gracenote MusicID-Stream library.
 *  @param sdkmgr_handle [in] Handle from successful gnsdk_manager_initialize call
 *  <p><b>Remarks:</b></p>
 *  A GNSDK module must be initialized before any of its APIs can be called. The GNSDK Manager 
 *  module must be initialized first, followed at some point by any modules the application needs. 
 *  Modules can be initialized at any time prior to use, and can be initialized multiple times. 
 *  Each initialization of a module adds to an initialization count for that module. The same number 
 *  of calls to the module shutdown routine need to occur to actually cause the module to 
 *  deinitialize and shutdown.
 * @ingroup Music_MusicIDStream_InitializationFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_musicidstream_initialize(gnsdk_manager_handle_t sdkmgr_handle);



/** @internal gnsdk_musicidstream_shutdown @endinternal
 *  Shuts down and release resources for the MusicID-Stream library.
 *  <p><b>Remarks:</b></p>
 *  All gnsdk_musicidstream_shutdown calls must be paired with an initial call to
 *  gnsdk_musicidstream_initialize.
 *  The final gnsdk_musicidstream_shutdown call results in the library being completely shut down; all
 *  MusicID-Stream APIs cease to function until the library is again initialized.
 * @ingroup Music_MusicIDStream_InitializationFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_musicidstream_shutdown(void);



/** @internal gnsdk_musicidstream_get_version @endinternal
 *  Retrieves the MusicID-Stream library's version string.
 *  This API can be called at any time, even before initialization and after shutdown. The returned
 *  string is a constant. Do not attempt to modify or delete.
 *  Example: 1.2.3.123 (Major.Minor.Improvement.Build)
 *  Major: New functionality
 *  Minor: New or changed features
 *  Improvement: Improvements and fixes
 *  Build: Internal build number
 * @ingroup Music_MusicIDStream_InitializationFunctions
 */
gnsdk_cstr_t GNSDK_API
gnsdk_musicidstream_get_version(void);



/** @internal gnsdk_musicidstream_get_build_date @endinternal
 *  Retrieves the MusicID-Stream library's build date string.
 *  <p><b>Remarks:</b></p>
 *  This API can be called at any time, even before initialization and after shutdown. The returned
 *  string is a constant. Do not attempt to modify or delete.
 *  Example
 *  Example build date string: 2008-02-12 00:41 UTC
 * @ingroup Music_MusicIDStream_InitializationFunctions
 */
gnsdk_cstr_t GNSDK_API
gnsdk_musicidstream_get_build_date(void);


/********************************************************************************
 * Callbacks
 *
 * The MusicID-Stream SDK can use callbacks to report status and lookups results.
 * Use of these callbacks is optional.
 ******************************************************************************/

/** 
 *  <b>Experimental</b>:
 *  An application should only use this option if it is advised by Gracenote Global Services and Support representative.  
 *  Contact your Gracenote Global Services and Support representative with any questions about this enhanced functionality.
 * @ingroup Music_MusicIDStream_TypesEnums
 */

typedef enum
{
	/** @ingroup Music_MusicIDStream_TypesEnums */
	gnsdk_musicidstream_processing_status_invalid = 0,

	/** @ingroup Music_MusicIDStream_TypesEnums */
	gnsdk_musicidstream_processing_status_audio_none,

	/** @ingroup Music_MusicIDStream_TypesEnums */
	gnsdk_musicidstream_processing_status_audio_silence,

	/** @ingroup Music_MusicIDStream_TypesEnums */
	gnsdk_musicidstream_processing_status_audio_noise,

	/** @ingroup Music_MusicIDStream_TypesEnums */
	gnsdk_musicidstream_processing_status_audio_speech,

	/** @ingroup Music_MusicIDStream_TypesEnums */
	gnsdk_musicidstream_processing_status_audio_music,

	/** @ingroup Music_MusicIDStream_TypesEnums */
	gnsdk_musicidstream_processing_status_transition_channel_change,

	/** @ingroup Music_MusicIDStream_TypesEnums */
	gnsdk_musicidstream_processing_status_transition_content_to_content,

	/** @ingroup Music_MusicIDStream_TypesEnums */
	gnsdk_musicidstream_processing_status_error_noclassifier,

	/** @ingroup Music_MusicIDStream_TypesEnums
	*	MusicID-Stream has created a new audio session, ready for receiving audio.
	*/
	gnsdk_musicidstream_processing_status_audio_started,

	/** @ingroup Music_MusicIDStream_TypesEnums
	*	MusicID-Stream has flagged the current audio session as ended and will no longer receive audio
	*/
	gnsdk_musicidstream_processing_status_audio_ended

} gnsdk_musicidstream_processing_status_t;


/** @internal gnsdk_musicidstream_identifying_status_t @endinternal
 *  Status codes passed to the gnsdk_musicidstream_identifying_status_callback_fn() callback for audio channel identification events.
 * @ingroup Music_MusicIDStream_TypesEnums
 */
typedef enum
{
/** @internal gnsdk_musicidstream_identifying_status_invalid @endinternal
 *  MusicID-Stream can't determine what status is in while identifying.
 * @ingroup Music_MusicIDStream_TypesEnums
 */
	gnsdk_musicidstream_identifying_status_invalid = 0,


/** @internal gnsdk_musicidstream_identifying_started @endinternal
 *  MusicID-Stream has started identifying process for a given audio input through a MID-Stream channel.
 * @ingroup Music_MusicIDStream_TypesEnums
 */
	gnsdk_musicidstream_identifying_started,


/** @internal gnsdk_musicidstream_identifying_fp_generated @endinternal
 *  MusicID-Stream has generated a fingerprint for a given audio input through a MID-Stream channel.
 * @ingroup Music_MusicIDStream_TypesEnums
 */
	gnsdk_musicidstream_identifying_fp_generated,


/** @internal gnsdk_musicidstream_identifying_local_query_started @endinternal
 *  MusicID-Stream has started a query against local Database for a generated fingerprint.
 * @ingroup Music_MusicIDStream_TypesEnums
 */
	gnsdk_musicidstream_identifying_local_query_started,


/** @internal gnsdk_musicidstream_identifying_local_query_ended @endinternal
 *  MusicID-Stream hascompleted a query against local Database for a generated fingerprint.
 * @ingroup Music_MusicIDStream_TypesEnums
 */
	gnsdk_musicidstream_identifying_local_query_ended,


/** @internal gnsdk_musicidstream_identifying_online_query_started @endinternal
 *  MusicID-Stream has started an online query for a generated fingerprint.
 * @ingroup Music_MusicIDStream_TypesEnums
 */
	gnsdk_musicidstream_identifying_online_query_started,


/** @internal gnsdk_musicidstream_identifying_online_query_ended @endinternal
 *  MusicID-Stream has completed an online query for a generated fingerprint.
 * @ingroup Music_MusicIDStream_TypesEnums
 */
	gnsdk_musicidstream_identifying_online_query_ended,


/** @internal gnsdk_musicidstream_identifying_ended @endinternal
 *  MusicID-Stream has completed all identifying events for a given audio input through a MID-Stream channel.
 * @ingroup Music_MusicIDStream_TypesEnums
 */
	gnsdk_musicidstream_identifying_ended


} gnsdk_musicidstream_identifying_status_t;


/** @internal gnsdk_musicidstream_event_t @endinternal
 * <b>Experimental</b>:
 *  Event codes passed to the gnsdk_musicidstream_event() to notify event changes in the application.
 * @ingroup Music_MusicIDStream_TypesEnums
 */
typedef enum
{
	/** @internal gnsdk_musicidstream_event_invalid @endinternal
	 *  MusicID-Stream can't determine what event occured while identifying.
	 * @ingroup Music_MusicIDStream_TypesEnums
	 */
	gnsdk_musicidstream_event_invalid = 0,
	
	/** @internal gnsdk_musicidstream_event_broadcast_metadata_change @endinternal
	 *  Notify MusicID-Stream a broadcast metadata change event
	 * @ingroup Music_MusicIDStream_TypesEnums
	 */
	gnsdk_musicidstream_event_broadcast_metadata_change
	
} gnsdk_musicidstream_event_t;
	
/** @internal gnsdk_musicidstream_audio_quality_t @endinternal
 * <b>Experimental</b>:
 *  Input Audio stream setting codes passed to gnsdk_musicidstream_channel_create() for setting audio input based presets.
 * @ingroup Music_MusicIDStream_TypesEnums
 */
typedef enum
{
	/** @internal gnsdk_musicidstream_preset_invalid @endinternal
	 *  MusicID-Stream input audio stream is set not found.
	 * @ingroup Music_MusicIDStream_TypesEnums
	 */
	gnsdk_musicidstream_preset_invalid = 0,
	
	/** @internal gnsdk_musicidstream_preset_microphone @endinternal
	 *  MusicID-Stream input audio stream is set to a microphone.
	 * @ingroup Music_MusicIDStream_TypesEnums
	 */
	gnsdk_musicidstream_preset_microphone,
	
	/** @internal gnsdk_musicidstream_preset_radio @endinternal
	 *  MusicID-Stream input audio stream is set to a direct line in.
	 * @ingroup Music_MusicIDStream_TypesEnums
	 */
	gnsdk_musicidstream_preset_radio
	
} gnsdk_musicidstream_preset_t;
	
/**  
 *  <b>Experimental</b>:
 *  An application should only use this option if it is advised by Gracenote Global Services and Support representative.  
 *  Contact your Gracenote Global Services and Support representative with any questions about this enhanced functionality. 
 * @ingroup Music_MusicIDStream_Callbacks
 */
typedef gnsdk_void_t (GNSDK_CALLBACK_API *gnsdk_musicidstream_processing_status_callback_fn)(
	gnsdk_void_t*								callback_data,
	gnsdk_musicidstream_processing_status_t		status,
	gnsdk_bool_t*								pb_abort
	);



/** @internal gnsdk_musicidstream_identifying_status_callback_fn @endinternal
 *  Callback function declaration for MusicID-Stream channel identifying status.
 *  @param callback_data [in] Value passed to the user_data parameter of the function this callback was
 *  passed to
 *  @param status [in] One of gnsdk_musicidstream_identifying_status_t values
 *  @param p_abort [out] Set dereferenced value to GNSDK_TRUE to abort the operation that is calling
 *  the callback
 * @ingroup Music_MusicIDStream_Callbacks
 */
typedef gnsdk_void_t (GNSDK_CALLBACK_API *gnsdk_musicidstream_identifying_status_callback_fn)(
	gnsdk_void_t*								callback_data,
	gnsdk_musicidstream_identifying_status_t	status,
	gnsdk_bool_t*								pb_abort
	);


/** @internal gnsdk_musicidstream_result_available_callback_fn @endinternal
 *  Callback function declaration for a response available notification.
 *  @param callback_data [in] Value passed to the user_data parameter of the function this callback was
 *  passed to
 *  @param gnsdk_musicidstream_channel_handle_t [in] MusicID-Stream channel handle that the callback operates on
 *  @param response_gdo [in] GDO handle for the album response (of type GNSDK_GDO_TYPE_RESPONSE_ALBUM)
 *  @param p_abort [out] Set the dereferenced value to GNSDK_TRUE to abort the operation that calls
 *  the callback
 * @ingroup Music_MusicIDStream_Callbacks
 */
typedef gnsdk_void_t (GNSDK_CALLBACK_API *gnsdk_musicidstream_result_available_callback_fn)(
	gnsdk_void_t*								callback_data,
	gnsdk_musicidstream_channel_handle_t		p_musicidstream_channel_handle,
	gnsdk_gdo_handle_t 							response_gdo,
	gnsdk_bool_t*								pb_abort
	);



/** @internal gnsdk_musicidstream_completed_with_error_callback_fn @endinternal
 *  Callback function declaration for an error occurs during identifcation stage in MusicID-Stream.
 *  @param callback_data [in] Value passed to the user_data parameter of the function this callback was
 *  passed to
 *  @param p_musicidstream_channel_handle [in] MusicID-Stream channel handle that the callback operates on
 *  @param p_error_info [out] Final error value of MusicID-Stream operation
 * @ingroup Music_MusicIDStream_Callbacks
 */
typedef gnsdk_void_t (GNSDK_CALLBACK_API * gnsdk_musicidstream_completed_with_error_callback_fn)(
	gnsdk_void_t* 								callback_data,
	gnsdk_musicidstream_channel_handle_t		p_musicidstream_channel_handle,
	const gnsdk_error_info_t* 					p_error_info
	);



/** @internal _gnsdk_musicidstream_callbacks_s @endinternal
 *  Structure of callback functions for status updates as various MusicID-Stream
 *  operations are performed.
 *
 *  <p><b>Remarks:</b></p>
 * <p><b>Note:</b></p>
 *  Ensure that callback functions that access the same global variable(s) use serialized access
 *  methods to the shared variable(s).
 * @ingroup Music_MusicIDStream_Callbacks
 */
typedef struct _gnsdk_musicidstream_callbacks_s
{
/** @internal gnsdk_musicidstream_callbacks_t::callback_status @endinternal
 *  Callback function during identification when an online query is performed.
 * @ingroup Music_MusicIDStream_Callbacks
 */
	gnsdk_status_callback_fn								callback_status;


/** @internal gnsdk_musicidstream_callbacks_t::callback_processing_status @endinternal
  *  <b>Experimental</b>:
  *  An application should only provide this callback if it is advised by Gracenote Global Services and Support representative.  
  *  Contact your Gracenote Global Services and Support representative with any questions about this enhanced functionality. 
  * @ingroup Music_MusicIDStream_Callbacks
  */
	gnsdk_musicidstream_processing_status_callback_fn		callback_processing_status;


/** @internal gnsdk_musicidstream_callbacks_t::callback_identifying_status @endinternal
 *  Callback function during audio processing when a significant event occurs
 *  such as large classification change or transition.
 * @ingroup Music_MusicIDStream_Callbacks
 */
	gnsdk_musicidstream_identifying_status_callback_fn		callback_identifying_status;


/** @internal gnsdk_musicidstream_callbacks_t::callback_result_available @endinternal
 *  Result has been determined by MusicID-Stream for a given audio stream within a MusicID-Stream channel.
 * @ingroup Music_MusicIDStream_Callbacks
 */
	gnsdk_musicidstream_result_available_callback_fn		callback_result_available;


/** @internal gnsdk_musicidstream_callbacks_t::callback_error @endinternal
 *  MusicID-Stream audio returns an error during identification for the given MusicID-Stream
 *  channel handle.
 *  Due to the error, no result will be provided.
 * @ingroup Music_MusicIDStream_Callbacks
*/
	gnsdk_musicidstream_completed_with_error_callback_fn	callback_error;

} gnsdk_musicidstream_callbacks_t;



/********************************************************************************
 * GNSDK_MUSICIDSTREAM_OPTION_* values
 ******************************************************************************/

/** @internal GNSDK_MUSICIDSTREAM_OPTION_LOOKUP_MODE @endinternal
 *  Indicates whether the musicidstream channel handle should be performed against local embedded databases or on-line.
 * @ingroup Music_MusicIDStream_OptionKeys
 */
#define GNSDK_MUSICIDSTREAM_OPTION_LOOKUP_MODE                      GNSDK_QUERY_OPTION_LOOKUP_MODE

/** @internal GNSDK_MUSICIDSTREAM_OPTION_ENABLE_CLASSICAL_DATA @endinternal
 *  Indicates whether a response should include any associated classical music data.
 *  <p><b>Remarks:</b></p>
 *  To retrieve classical music data, define this option key with a True value for a specific
 *  MusicID-Stream channel handle. This retrieves the data and automatically renders it into the XML output.
 *  An application's license must be entitled to retrieve this specialized data. Contact your
 *  Gracenote Global Services and Support representative with any questions about this enhanced functionality.
 * @ingroup Music_MusicIDStream_OptionKeys
 */
#define GNSDK_MUSICIDSTREAM_OPTION_ENABLE_CLASSICAL_DATA            "gnsdk_musicidstream_option_enable_classical"

/** @internal GNSDK_MUSICIDSTREAM_OPTION_ENABLE_ALTERNATE_NAMES @endinternal
 *  Indicates whether a response should include any associated alternate names for all the artists.
 *  <p><b>Remarks:</b></p>
 *  To retrieve alternate names, define this option key with a True value for a specific
 *  MusicID-Stream channel handle. This retrieves the data and automatically renders it into the XML output.
 *  An application's license must be entitled to retrieve this specialized data. Contact your
 *  Gracenote Global Services and Support representative with any questions about this enhanced functionality.
 * @ingroup Music_MusicIDStream_OptionKeys
 */
#define GNSDK_MUSICIDSTREAM_OPTION_ENABLE_ALTERNATE_NAMES           "gnsdk_musicidstream_option_enable_altnames"

/** @internal GNSDK_MUSICIDSTREAM_OPTION_ENABLE_GLOBALIDS @endinternal
 *  Indicates whether a response should include any associated GlobalID data.
 *  <p><b>Remarks:</b></p>
 *  To retrieve GlobalID data, define this option key with a True value for a specific MusicID-Stream
 *  channel handle. This retrieves the data and automatically renders it into the XML output.
 *  An application's license must be entitled to retrieve this specialized data. Contact your
 *  Gracenote Global Services and Support representative with any questions about this enhanced functionality.
 * @ingroup Music_MusicIDStream_OptionKeys
 */
#define GNSDK_MUSICIDSTREAM_OPTION_ENABLE_GLOBALIDS                 "gnsdk_musicidstream_option_enable_globalids"

/** @internal GNSDK_MUSICIDSTREAM_OPTION_ENABLE_SONIC_DATA @endinternal
 *  Indicates whether a response should include any associated sonic attribute data.
 *  <p><b>Remarks:</b></p>
 *  To retrieve Sonic data, define this option key with a True value for a specific MusicID-Stream channel
 *  handle. This retrieves the data and automatically renders it into the XML output.
 *  An application's license must be entitled to retrieve this specialized data. Contact your
 *  Gracenote Global Services and Support
 *  representative with any questions about this enhanced functionality.
 * @ingroup Music_MusicIDStream_OptionKeys
 */
#define GNSDK_MUSICIDSTREAM_OPTION_ENABLE_SONIC_DATA                "gnsdk_musicidstream_option_enable_sonic"

/**
 *  @deprecated Will be deprecated in a future release. Use GNSDK_MUSICIDSTREAM_OPTION_ENABLE_DSP_DATA instead. 
 * @ingroup Music_MusicIDStream_OptionKeys 
 */
#define GNSDK_MUSICIDSTREAM_OPTION_ENABLE_DSP_DATA                  "gnsdk_musicidstream_option_enable_dsp"

/** @internal GNSDK_MUSICIDSTREAM_OPTION_ENABLE_PLAYLIST @endinternal
 *  Indicates whether a response should include associated attribute data for GNSDK Playlist.
 *  <p><b>Remarks:</b></p>
 *  To retrieve Playlist attribute data, define this option key with a True value for a specific
 *  MusicID-Stream channel handle. This retrieves the data and automatically renders it into the XML output.
 *  An application's license must be entitled to retrieve this specialized data. Contact your
 *  Gracenote Global Services and Support representative with any questions about this enhanced functionality.
 * @ingroup Music_MusicIDStream_OptionKeys
 */
#define GNSDK_MUSICIDSTREAM_OPTION_ENABLE_PLAYLIST                  "gnsdk_musicidstream_option_enable_playlist"

/** @internal GNSDK_MUSICIDSTREAM_OPTION_ENABLE_EXTERNAL_IDS @endinternal
 *  Indicates whether a response should include any external IDs (third-party IDs).
 *  <p><b>Remarks:</b></p>
 *  External IDs are third-party IDs associated with the results (such as an Amazon ID), 
 *  configured specifically for your application.
 *  An application's license must be entitled to retrieve this specialized data. Contact your
 *  Gracenote Global Services and Support representative with any questions about this enhanced functionality.
 *  External IDs are supported in the following types, for the listed child and value GDOs:
 *  GNSDK_GDO_TYPE_ALBUM
 *  GNSDK_GDO_CHILD_EXTERNAL_ID
 *  GNSDK_GDO_TYPE_TRACK
 *  GNSDK_GDO_CHILD_EXTERNAL_ID
 * @ingroup Music_MusicIDStream_OptionKeys
 */
#define GNSDK_MUSICIDSTREAM_OPTION_ENABLE_EXTERNAL_IDS              "gnsdk_musicidstream_option_enable_xids"

/** @internal GNSDK_MUSICIDSTREAM_OPTION_ENABLE_CONTENT_DATA @endinternal
 *  Indicates whether a response should include data for use in fetching content (like images).
 *  <p><b>Remarks:</b></p>
 *  To allow the GDO to be efficiently used to retrieve content data, define this option key with a True value for a specific MusicID stream
 *  channel handle. 
 *  An application's client ID must be entitled to retrieve this specialized data. Contact your
 *  Gracenote Global Services and Support representative with any questions about this enhanced functionality.
 * @ingroup Music_MusicIDStream_OptionKeys
 */
#define GNSDK_MUSICIDSTREAM_OPTION_ENABLE_CONTENT_DATA              "gnsdk_musicidstream_option_enable_content"

/**
 *  @deprecated Will be deprecated in a future release.
 *  For content (like cover art, artist images, etc), use GNSDK_MUSICIDSTREAM_OPTION_ENABLE_CONTENT_DATA instead. 
 *  For external 3rd party IDs, use GNSDK_MUSICIDSTREAM_OPTION_ENABLE_EXTERNAL_IDS instead. 
 * @ingroup Music_MusicIDStream_OptionKeys
 */
#define GNSDK_MUSICIDSTREAM_OPTION_ENABLE_LINK_DATA                 "gnsdk_musicidstream_option_enable_link"

/** @internal GNSDK_MUSICIDSTREAM_OPTION_ADDITIONAL_CREDITS @endinternal
  * Indicates that additional credits are enabled and will be returned from service.
  * @ingroup Music_MusicIDStream_OptionKeys
  */
#define GNSDK_MUSICIDSTREAM_OPTION_ADDITIONAL_CREDITS               "gnsdk_musicidstream_option_additional_credits"

/**
 *  @deprecated Will be deprecated in a future release.
 *  The application should set the default locale, or to set a locale to the query/channel handle to indicate the 
 *  preferred language the results should appear in.  Developer should understand that this setting is only a ﾑpreferenceﾒ. 
 *  If the preferred language cannot be retrieved an alternate language result will be returned. Applications can inspect 
 *  the language and script of the returned results to determine if the preference has been met. 
 * @ingroup Music_MusicIDStream_OptionKeys
 */
#define GNSDK_MUSICIDSTREAM_OPTION_PREFERRED_LANG                   "gnsdk_musicidstream_preferred_lang"

/** @internal GNSDK_MUSICIDSTREAM_OPTION_RESULT_SINGLE @endinternal
 *  Indicates whether a response must return only the single best result.
 *  <p><b>Remarks:</b></p>
 *  The MusicID library selects the single best result based on the query type and input.
 *  To set or clear this option use a string representing a boolean value such as "true" or "false"
 *  or GNSDK equivalent GNSDK_VALUE_TRUE or GNSDK_VALUE_FALSE.
 * @ingroup Music_MusicIDStream_OptionKeys
 */
#define GNSDK_MUSICIDSTREAM_OPTION_RESULT_SINGLE                    "gnsdk_musicidstream_single_result"

/** @internal GNSDK_MUSICIDSTREAM_OPTION_RESULT_PREFER_XID @endinternal
 *  Indicates the custom non-Gracenote identifier used to prefer the returned results.
 *  Only available where a single result is requested with GNSDK_MUSICIDSTREAM_OPTION_RESULT_SINGLE.
 *  <p><b>Remarks:</b></p>
 *  This option is useful for if applicaton choose to only access XIDs for a particular vendor.
 *  An application needs a specific key as an input parameter for this option to retrieve the specified data. Contact your
 *  Gracenote Global Services and Support representative with any questions about this enhanced functionality.
 * @ingroup Music_MusicIDStream_OptionKeys
 */
#define GNSDK_MUSICIDSTREAM_OPTION_RESULT_PREFER_XID                "gnsdk_musicidstream_result_prefer_xid"

/** @internal GNSDK_MUSICIDSTREAM_OPTION_RESULT_PREFER_COVERART @endinternal
 *  Indicates use cover art to prefer the returned results.
 *  <p><b>Remarks:</b><p>
 *  To set or clear this option use a string representing a boolean value such as "true" or "false"
 *  or GNSDK equivalent GNSDK_VALUE_TRUE or GNSDK_VALUE_FALSE.
 * @ingroup Music_MusicIDStream_OptionKeys
 */
#define GNSDK_MUSICIDSTREAM_OPTION_RESULT_PREFER_COVERART           "gnsdk_musicidstream_result_prefer_coverart"

/** @internal GNSDK_MUSICIDSTREAM_OPTION_RESULT_RANGE_START @endinternal
 *  Indicates whether a response must return a range of results that begin at a specified value.
 *  <p><b>Remarks:</b></p>
 *  This option is useful for paging through results.
 * <p><b>Note:</b></p>
 *  Gracenote Service enforces that the range start value must be less than or equal to the total
 *  number of results. If you specify a range start value that is greater than the total number of
 *  results, no results are returned.
 * @ingroup Music_MusicIDStream_OptionKeys
 */
#define GNSDK_MUSICIDSTREAM_OPTION_RESULT_RANGE_START               "gnsdk_musicidstream_result_range_start"

/** @internal GNSDK_MUSICIDSTREAM_OPTION_RESULT_RANGE_SIZE @endinternal
 *  Indicates whether a response can return up to a specified maximum number of results.
 *  <p><b>Remarks:</b></p>
 *  This option is useful for paging through results.
 * <p><b>Note:</b></p>
 *  Gracenote Service limits the range size for some queries. If you specify a range size greater
 *  than the limit, the results are constrained. Additionally, neither Gracenote Service nor GNSDK
 *  returns an error about this behavior.
 *  <p><b>Important:</b></p>
 *  The number of results actually returned for a query may not equal the number of results initially
 *  requested. To accurately iterate through results, always check the range start, end, and total
 *  values and the responses returned by Gracenote Service for the query (or queries). Ensure that you
 *  are incrementing by using the actual last range end value plus one (range_end+1), and not by simply
 *  using the initial requested value.
 * @ingroup Music_MusicIDStream_OptionKeys
 */
#define GNSDK_MUSICIDSTREAM_OPTION_RESULT_RANGE_SIZE                "gnsdk_musicidstream_result_range_size"

/** @internal GNSDK_MUSICIDSTREAM_OPTION_REVISION_CHECK @endinternal
 *  Indicates whether a response must return results only when an updated revision exists.
 *  <p><b>Remarks:</b></p>
 *  To set or clear this option use a string representing a boolean value such as "true" or "false"
 *  or GNSDK equivalent GNSDK_VALUE_TRUE or GNSDK_VALUE_FALSE.
 * @ingroup Music_MusicIDStream_OptionKeys
 */

 /*  Code in the request code to implement this option is not in place yet 
  */
 /*  #define GNSDK_MUSICIDSTREAM_OPTION_REVISION_CHECK                   "gnsdk_musicidstream_option_revision_check"
  */

/**
 *  <b>Experimental</b>:
 *  An application should only use this option if it is advised by Gracenote Global Services and Support representative.  
 *  Contact your Gracenote Global Services and Support representative with any questions about this enhanced functionality. 
 * @ingroup Music_MusicIDStream_OptionKeys
 */
#define GNSDK_MUSICIDSTREAM_OPTION_AUDIO_QUALITY                    "gnsdk_musicidstream_option_audio_quality"
	
/**
 *  <b>Experimental</b>:
 *  An application should only use this option if it is advised by Gracenote Global Services and Support representative.
 *  Contact your Gracenote Global Services and Support representative with any questions about this enhanced functionality.
 * @ingroup Music_MusicIDStream_OptionKeys
 */
#define GNSDK_MUSICIDSTREAM_AUDIO_QUALITY_MICROPHONE				"gnsdk_musicidstream_audio_quality_microphone"
	
/**
 *  <b>Experimental</b>:
 *  An application should only use this option if it is advised by Gracenote Global Services and Support representative.
 *  Contact your Gracenote Global Services and Support representative with any questions about this enhanced functionality.
 * @ingroup Music_MusicIDStream_OptionKeys
 */
#define GNSDK_MUSICIDSTREAM_AUDIO_QUALITY_TUNER						"gnsdk_musicidstream_audio_quality_tuner"
	
	
/******************************************************************************
 * GNSDK_MUSICIDSTREAM_BROADCAST_METADATA_* keys
 ******************************************************************************/

/**
 *  <b>Experimental</b>:
 *  An application should only use this option if it is advised by Gracenote Global Services and Support representative.
 *  Contact your Gracenote Global Services and Support representative with any questions about this enhanced functionality.
 * @ingroup Music_MusicIDStream_BroadcastMetadataKeys
 */
#define GNSDK_MUSICIDSTREAM_BROADCAST_METADATA_SHOUTCAST			"gnsdk_musicidstream_broadcast_metadata_shoutcast"

/**
 *  <b>Experimental</b>:
 *  An application should only use this option if it is advised by Gracenote Global Services and Support representative.
 *  Contact your Gracenote Global Services and Support representative with any questions about this enhanced functionality.
 * @ingroup Music_MusicIDStream_BroadcastMetadataKeys
 */
#define GNSDK_MUSICIDSTREAM_BROADCAST_METADATA_RDS_RT				"gnsdk_musicidstream_broadcast_metadata_rds_rt"

/**
 *  <b>Experimental</b>:
 *  An application should only use this option if it is advised by Gracenote Global Services and Support representative.
 *  Contact your Gracenote Global Services and Support representative with any questions about this enhanced functionality.
 * @ingroup Music_MusicIDStream_BroadcastMetadataKeys
 */
#define GNSDK_MUSICIDSTREAM_BROADCAST_METADATA_RDS_PTY				"gnsdk_musicidstream_broadcast_metadata_rds_pty"

/**
 *  <b>Experimental</b>:
 *  An application should only use this option if it is advised by Gracenote Global Services and Support representative.
 *  Contact your Gracenote Global Services and Support representative with any questions about this enhanced functionality.
 * @ingroup Music_MusicIDStream_BroadcastMetadataKeys
 */
#define GNSDK_MUSICIDSTREAM_BROADCAST_METADATA_RDS_PI				"gnsdk_musicidstream_broadcast_metadata_rds_pi"
	
/**
 *  <b>Experimental</b>:
 *  An application should only use this option if it is advised by Gracenote Global Services and Support representative.
 *  Contact your Gracenote Global Services and Support representative with any questions about this enhanced functionality.
 * @ingroup Music_MusicIDStream_BroadcastMetadataKeys
 */
#define GNSDK_MUSICIDSTREAM_BROADCAST_METADATA_ARTIST				"gnsdk_musicidstream_broadcast_metadata_artist"

/**
 *  <b>Experimental</b>:
 *  An application should only use this option if it is advised by Gracenote Global Services and Support representative.
 *  Contact your Gracenote Global Services and Support representative with any questions about this enhanced functionality.
 * @ingroup Music_MusicIDStream_BroadcastMetadataKeys
 */
#define GNSDK_MUSICIDSTREAM_BROADCAST_METADATA_TRACK_TITLE			"gnsdk_musicidstream_broadcast_metadata_track_title"
	
/********************************************************************************
 * MusicID-Stream SDK APIs
 ******************************************************************************/

/******************************************************************************
 * MusicID Stream Channel Handle - for the life of the channel handle
 ******************************************************************************/

/** @internal gnsdk_musicidstream_prodcut_type_channel_create @endinternal
 *  <b>Experimental</b>
 *  Creates a MusicID-Stream channel handle with a specific product setting.
 *  @param user_handle [in] User handle for the user requesting the query
 *  @param preset [in] Preset type for the channel requesting the query
 *  @param p_callbacks [in_opt] Callback functions for status and progress
 *  @param callback_data [in_opt] Data that is passed back through calls to the callback functions
 *  @param p_musicidstream_channel_handle [out] Pointer to receive a MusicID-Stream channel handle
 *  <p><b>Remarks:</b></p>
 *  The application must create a gnsdk_musicidstream_channel_handle_t for each independent MusicID-Stream channel operation
 *  it needs to perform.
 *  The application can create and operate multiple channel handles that run simultaneously, however,
 *  each channel handle must be used only by the original thread that created it.
 * @ingroup Music_MusicIDStream_QueryFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_musicidstream_channel_create(
	gnsdk_user_handle_t						user_handle,
	gnsdk_musicidstream_preset_t			preset,
	gnsdk_musicidstream_callbacks_t*		p_callbacks,
	gnsdk_void_t*							callback_data,
	gnsdk_musicidstream_channel_handle_t*	p_musicidstream_channel_handle
	);
	
/** @internal gnsdk_musicidstream_channel_release @endinternal
 *  Invalidates and releases resources for a given MusicIDStream channel handle.
 *  @param musicidstream_channel_handle [in] MusicIDStream channel handle to release
 * @ingroup Music_MusicIDStream_QueryFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_musicidstream_channel_release(
	gnsdk_musicidstream_channel_handle_t musicidstream_channel_handle
	);


gnsdk_error_t GNSDK_API
gnsdk_musicidstream_channel_set_locale(
	gnsdk_musicidstream_channel_handle_t musicidstream_channel_handle,
	gnsdk_locale_handle_t                locale_handle
	);


/** @internal gnsdk_musicidstream_channel_option_set @endinternal
 *  Sets an option for a given MusicIDStream channel handle.
 *  @param musicidstream_channel_handle [in] MusicIDStream channel handle to set an option for
 *  @param option_key [in] An option from the available query options 
 *									defined here or in gnsdk_manager.h
 *  @param option_value [in] A string value or one of the available MusicIDStream Option Values that
 corresponds to the defined option key
 * @ingroup Music_MusicIDStream_QueryFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_musicidstream_channel_option_set(
	gnsdk_musicidstream_channel_handle_t musicidstream_channel_handle,
	gnsdk_cstr_t                         option_key,
	gnsdk_cstr_t                         option_value
	);

/** @internal gnsdk_musicidstream_channel_option_get @endinternal
 *  Retrieves an option for a given MusicIDStream channel handle.
 *  @param musicidstream_channel_handle [in] MusicIDStream channel handle to retrieve an option from
 *  @param option_key [in] An option from the available query options 
 *									defined here or in gnsdk_manager.h
 *  @param p_option_value [out] Pointer to receive option value
 * @ingroup Music_MusicIDStream_QueryFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_musicidstream_channel_option_get(
	gnsdk_musicidstream_channel_handle_t musicidstream_channel_handle,
	gnsdk_cstr_t                         option_key,
	gnsdk_cstr_t*                        p_option_value
	);
	
	
/** @internal gnsdk_musicidstream_channel_audio_begin @endinternal
 *  Initializes MusicID-Stream channel handle with the specified configuration to prepare writing audio data(PCM) to the channel.
 *  @param musicidstream_channel_handle [in] MusicID-Stream channel handle to write audio to circular buffer, 
 *  generate the fingerprint and identify for
 *  @param audio_sample_rate [in] Sample rate of audio to be provided in Hz. (for example,44100)
 *  @param audio_sample_size [in] Size of a single sample of audio to be provided: 8 for 8-bit audio
 *  (0-255 integers), 16 for 16-bit audio (-32767~32768 integers), and 32 for 32-bit audio (-1.0~1.0
 *  floating point)
 *  @param audio_channels [in] Number of channels for audio to be provided (1 or 2)
 * @ingroup Music_MusicIDStream_QueryFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_musicidstream_channel_audio_begin(
	gnsdk_musicidstream_channel_handle_t musicidstream_channel_handle,
	gnsdk_uint32_t                       audio_sample_rate,
	gnsdk_uint32_t                       audio_sample_size,
	gnsdk_uint32_t                       audio_channels
	);

/** @internal gnsdk_musicidstream_channel_audio_write @endinternal
 *  Provides uncompressed audio data to a query handle for native fingerprint generation and identification.
 *  @param musicidstream_channel_handle [in] MusicID-Stream channel handle to write audio to circular buffer, 
 *  generate the fingerprint and identify for
 *  @param p_audio_data [in] Pointer to audio data buffer that matches audio format described to
 *  gnsdk_musicidstream_channel_audio_begin
 *  @param audio_data_length [in] Size of audio data buffer in bytes
 *  <p><b>Remarks:</b></p>
 *  Call this API after gnsdk_musicidstream_channel_audio_begin() to:
 *  <ul>
 *  <li>Generate Gracenote Fingerprint and identify it when gnsdk_musicidstream_channel_identify() is called.
 *  </ul>
 * <p><b>Note:</b></p>
 *  If the specified MusicID-Stream channel is in identification mode, 
 *  once gnsdk_musicidstream_channel_audio_write enough data to generate a fingerprint, 
 *  application will be notified through callback function with status gnsdk_musicidstream_identifying_fp_generated.
 *  If the specified MusicID-Stream channel is in buffering mode,
 *  all data will be written to circular buffer for future fingerprint generation and identification usage when
 *  gnsdk_musicidstream_channel_identify() is called
 * @ingroup Music_MusicIDStream_QueryFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_musicidstream_channel_audio_write(
	gnsdk_musicidstream_channel_handle_t musicidstream_channel_handle,
	const gnsdk_byte_t*                  p_audio_data,
	gnsdk_size_t                         audio_data_length
	);

/** @internal gnsdk_musicidstream_channel_audio_end @endinternal
 *  Finalizes writing audio data input for a MusicID-Stream channel handle.
 *  @param musicidstream_channel_handle [in] MusicID-Stream channel handle to write audio to circular buffer, 
 *  generate the fingerprint and identify for
 *  <p><b>Remarks:</b></p>
 *  Call this API when the audio stream ends; this alerts the system that it has received all the
 *  available audio for the particular stream.
 * @ingroup Music_MusicIDStream_QueryFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_musicidstream_channel_audio_end(
	gnsdk_musicidstream_channel_handle_t musicidstream_channel_handle
	);

/** @internal gnsdk_musicidstream_channel_identify @endinternal
 *  Identify audio data stored within the specified MusicID-Stream channel handle.
 *  @param musicidstream_channel_handle [in] MusicID-Stream channel handle to generate the fingerprint and identify for
 *  <p><b>Remarks:</b></p>
 *  This API will processing the incoming audio data (PCM) asynchronously.
 * @ingroup Music_MusicIDStream_QueryFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_musicidstream_channel_identify(
	gnsdk_musicidstream_channel_handle_t	musicidstream_channel_handle
	);

/** @internal gnsdk_musicidstream_channel_identify_cancel @endinternal
 *  Cancels an ongoing Identify process within the specified MusicID-Stream channel handle, blocks until the Identify
 *  process has stopped. Cannot be called from within a MusicID-Stream callback, use the aborted flag provided in the
 *  callback instead.
 *  @param musicidstream_channel_handle [in] MusicID-Stream channel handle to generate the fingerprint and identify for
 *  <p><b>Remarks:</b></p>
 *  This API will cancel the identify if its in progress asyncronously.
 * @ingroup Music_MusicIDStream_QueryFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_musicidstream_channel_identify_cancel(
	gnsdk_musicidstream_channel_handle_t	musicidstream_channel_handle
	);

/** @internal gnsdk_musicidstream_channel_wait_for_identify @endinternal
 *  Sets a wait time for a MusicID-Stream identify to complete.
 *  @param musicidstream_channel_handle [in] MusicID-Stream channel handle currently processing
 *  asynchronously
 *  @param timeout_ms [in] Length of time to wait in milliseconds, or the
 *  GNSDK_MUSICIDFILE_TIMEOUT_INFINITE flag
 *  <p><b>Remarks:</b></p>
 *  Use this function to set a wait for identification to complete for
 *  given MusicID-Stream channel handle.
 *  <p><b>Note:</b></p>
 *	API will wait for identification process to complete or until timeout value is reached.
 *	Using GNSDK_MUSICIDSTREAM_TIMEOUT_INFINITE for the timeout_ms parameter will wait until
 *	there is enough data to generate a fingerprint or until gnsdk_musicidstream_channel_audio_end
 *	is called.
 * @ingroup Music_MusicIDStream_QueryFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_musicidstream_channel_wait_for_identify(
	gnsdk_musicidstream_channel_handle_t	musicidstream_channel_handle,
	gnsdk_uint32_t							timeout_ms
	);


/** @internal gnsdk_musicidstream_channel_automatic_set @endinternal
 *  <b>Experimental</b>
 *  Sets automatic lookup mode for a given MusicIDStream channel handle. This is only supported when
 *  the channel handle is created with the gnsdk_musicidstream_preset_radio value.
 *  @param musicidstream_channel_handle [in] MusicIDStream channel handle to retrieve an option from
 *  @param b_auto_set [in] True or False to set or unset automatic mode
 * @ingroup Music_MusicIDStream_QueryFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_musicidstream_channel_automatic_set(
	gnsdk_musicidstream_channel_handle_t	musicidstream_channel_handle,
	gnsdk_bool_t							b_auto_set
	);
	
/** @internal gnsdk_musicidstream_channel_automatic_get @endinternal
 *  <b>Experimental</b>
 *  Gets the set lookup mode for a given MusicIDStream channel handle.
 *  @param musicidstream_channel_handle [in] MusicIDStream channel handle to retrieve an option from
 *  @param p_auto_get [out] True or False for a set or unset automatic mode
 * @ingroup Music_MusicIDStream_QueryFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_musicidstream_channel_automatic_get(
	gnsdk_musicidstream_channel_handle_t	musicidstream_channel_handle,
	gnsdk_bool_t*							p_auto_get
	);

/** @internal gnsdk_musicidstream_channel_event @endinternal
 *  <b>Experimental</b>
 *  Specifies a change in application for a given MusidIDstream channel handle.
 *  @param musicidstream_channel_handle [in] MusicIDStream channel handle to retrieve an option from
 *  @param event_t [in] One of the MusicIDStream Event Enum Values
 * @ingroup Music_MusicIDStream_QueryFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_musicidstream_channel_event(
	gnsdk_musicidstream_channel_handle_t	musicidstream_channel_handle,
	gnsdk_musicidstream_event_t             event_t
	);
	
/** @internal gnsdk_musicidstream_channel_broadcast_metadata_write @endinternal
 *  <b>Experimental</b>
 *  Provides broadcast metadata to a query handle for improved match resolution.
 *  @param musicidstream_channel_handle [in] MusicIDStream channel handle to retrieve an option from
 *  @param broadcast_metadata_key [in] A brodcast metadata input type from the available MusicIDStream Broadcast Metadata Keys
 *  @param broadcast_metadata_value [in] A string value that corresponds to the defined broadcast metadata key
 *  <p><b>Note:</b></p>
 *	API is suported only when using gnsdk_musicidstream_preset_radio channel create option
 * @ingroup Music_MusicIDStream_QueryFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_musicidstream_channel_broadcast_metadata_write(
	gnsdk_musicidstream_channel_handle_t		musicidstream_channel_handle,
	gnsdk_cstr_t								broadcast_metadata_key,
	gnsdk_cstr_t								broadcast_metadata_value
	);

/** @internal GNSDK_MUSICIDSTREAM_TIMEOUT_INFINITE @endinternal
 *  Value for infinite wait in a call to gnsdk_musicidstream_channel_wait_for_identify.
 *  Otherwise enter the timeout duration in milliseconds.
 * @ingroup Music_MusicIDStream_Flags
 */
#define GNSDK_MUSICIDSTREAM_TIMEOUT_INFINITE					(gnsdk_uint32_t)-1


#ifdef __cplusplus
}
#endif

#endif /* _GNSDK_MUSICID_STREAM_H_ */

