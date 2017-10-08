/*
  *
  *  GRACENOTE, INC. PROPRIETARY INFORMATION
  *  This software is supplied under the terms of a license agreement or
  *  nondisclosure agreement with Gracenote, Inc. and may not be copied
  *  or disclosed except in accordance with the terms of that agreement.
  *  Copyright(c) 2000-2013. Gracenote, Inc. All Rights Reserved.
  *
 */

/* gnsdk_musicid_file.h: Public interface for the MusicID-File SDK.
*/

#ifndef _GNSDK_MUSICID_FILE_H_
#define _GNSDK_MUSICID_FILE_H_

#include "gnsdk_manager_gdo.h"

#ifdef __cplusplus
extern "C"{
#endif
#ifndef SWIG
/********************************************************************************
 * Typedefs
 ******************************************************************************/

/** @internal gnsdk_musicidfile_query_handle_t @endinternal
*  Handle to query instance for MusicID-File. The application creates this handle
for each set of files designated for MusicID-File recognition.
*  <p><b>Remarks:</b></p>
*  An application may create as many of these handles as needed using
gnsdk_musicidfile_query_create()
* @ingroup Music_MusicIDFile_TypesEnums
*/
GNSDK_DECLARE_HANDLE( gnsdk_musicidfile_query_handle_t );


/** @internal gnsdk_musicidfile_fileinfo_handle_t @endinternal
*  Handle containing all input and output data for a single file. Each handle is associated with a
gnsdk_musicidfile_query_handle_t.
*  <p><b>Remarks:</b></p>
*  An application may create this handle as needed. This handle is owned by the
gnsdk_musicidfile_query_handle_t it was created with, and is automatically destroyed when
gnsdk_musicidfile_query_handle_t is destroyed.
* @ingroup Music_MusicIDFile_TypesEnums
*/
GNSDK_DECLARE_HANDLE( gnsdk_musicidfile_fileinfo_handle_t );



/********************************************************************************
 * MusicID-File SDK Initialization APIs
 ******************************************************************************/


/** @internal gnsdk_musicidfile_initialize @endinternal
*  Initializes Gracenote MusicID-File library.
*  @param sdkmgr_handle [in] Handle from successful gnsdk_manager_initialize call
*  @return MIDFERR_InvalidArg Given sdkmgr_handle parameter is null
*  @return MIDFERR_HandleObjectInvalid Given sdkmgr_handle is not a valid GNSDK Manager handle
*  @return MIDFERR_InitFailed Initialization failed
*  @return MIDFERR_NoError Initialization succeeded
*  <p><b>Remarks:</b></p>
*  This function must be successfully called before any other MusicID-File APIs will succeed. This
function can be called multiple times without issue, however all successful calls must be paired
with a call to gnsdk_musicidfile_shutdown. If gnsdk_musicidfile_initialize returns an error, then
gnsdk_musicidfile_shutdown should not be called.
* @ingroup Music_MusicIDFile_InitializationFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_initialize(
	gnsdk_manager_handle_t	sdkmgr_handle
	);



/** @internal gnsdk_musicidfile_shutdown @endinternal
*  Shuts down and release resources for the MusicID-File library.
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_NoError Shut down succeeded
*  <p><b>Remarks:</b></p>
*  All gnsdk_musicidfile_shutdown calls must be paired with an initial call to
gnsdk_musicidfile_initialize.
*  The final gnsdk_musicidfile_shutdown call results in the library being completely shut down; all
MusicID-File APIs cease to function until the library is again initialized.
* @ingroup Music_MusicIDFile_InitializationFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_shutdown(void);



/** @internal gnsdk_musicidfile_get_version @endinternal
*  Retrieves the MusicID-File library's version string.
*  This API can be called at any time, even before initialization and after shutdown. The returned
string is a constant. Do not attempt to modify or delete.
*  Example: 1.2.3.123 (Major.Minor.Improvement.Build)
*  Major: New functionality
*  Minor: New or changed features
*  Improvement: Improvements and fixes
*  Build: Internal build number
* @ingroup Music_MusicIDFile_InitializationFunctions
*/
gnsdk_cstr_t GNSDK_API
gnsdk_musicidfile_get_version(void);



/** @internal gnsdk_musicidfile_get_build_date @endinternal
*  Retrieves the MusicID-File library's build date string.
*  @return Note Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  This API can be called at any time, even before initialization and after shutdown. The returned
string is a constant. Do not attempt to modify or delete.
*  Example
*  Example build date string: 2008-02-12 00:41 UTC
* @ingroup Music_MusicIDFile_InitializationFunctions
*/
gnsdk_cstr_t GNSDK_API
gnsdk_musicidfile_get_build_date(void);



/********************************************************************************
 * Callbacks
 *
 * The MusicID-File SDK can use callbacks to report status and lookups results.
 * Use of these callbacks is optional, except when the
 * GNSDK_MUSICIDFILE_QUERY_FLAG_ASYNC flag is used. In that case, the
 * gnsdk_musicidfile_callback_musicid_complete_fn must be set.
 ******************************************************************************/
#endif

/** @internal gnsdk_musicidfile_callback_status_t @endinternal
*  Status codes passed to the gnsdk_musicidfile_callback_status_fn() callback.
* @ingroup Music_MusicIDFile_TypesEnums
*/
typedef enum
{
/** @internal gnsdk_musicidfile_status_fileinfo_processing_begin @endinternal
	  *
	  *   MusicID-File processing is beginning for a given FileInfo.
	* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_status_fileinfo_processing_begin = 0x100,


/** @internal gnsdk_musicidfile_status_fileinfo_query @endinternal
	  *
	  *   Performing a Gracenote query for given FileInfo.
	* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_status_fileinfo_query = 0x150,


/** @internal gnsdk_musicidfile_status_fileinfo_processing_complete @endinternal
	  *
	  *   MusicID-File processing is complete for a given FileInfo.
	* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_status_fileinfo_processing_complete = 0x199,

/** @internal gnsdk_musicidfile_status_fileinfo_processing_error @endinternal
	 *
	 *   MusicID-File processing for a given FileInfo has encountered an
	 *   error.
* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_status_fileinfo_processing_error = 0x299,


/** @internal gnsdk_musicidfile_status_error @endinternal
*
*   An error in MusicID-File querying or processing has occurred.
* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_status_error = 0x999

} gnsdk_musicidfile_callback_status_t;

#ifndef SWIG

/** @internal gnsdk_musicidfile_callback_status_fn @endinternal
*  Callback function declaration for MusicID-File progress status.
*  @param userdata [in] Value passed to the user_data parameter of the function this callback was
passed to
*  @param musicidfile_query_handle [in] MusicID-File query handle that the Fileinfo handle belongs
to
*  @param fileinfo [in] MusicID-File FileInfo handle that the callback operates on
*  @param status [in] One of gnsdk_musicidfile_callback_status_t values
*  @param current_file [in] Current number of the file being processed (if applicable to status,
otherwise 0)
*  @param total_files [in] Total number of files to be processed (if applicable to status, otherwise
0)
*  @param p_abort [out] Set dereferenced value to GNSDK_TRUE to abort the operation that is calling
the callback
* @ingroup Music_MusicIDFile_Callbacks
*/
typedef gnsdk_void_t
(GNSDK_CALLBACK_API *gnsdk_musicidfile_callback_status_fn)(
	gnsdk_void_t*						callback_data,
	gnsdk_musicidfile_query_handle_t	musicidfile_query_handle,
	gnsdk_musicidfile_fileinfo_handle_t	fileinfo,
	gnsdk_musicidfile_callback_status_t	status,
	gnsdk_uint32_t						current_file,
	gnsdk_uint32_t						total_files,
	gnsdk_bool_t*						p_abort
	);



/** @internal gnsdk_musicidfile_callback_get_fingerprint_fn @endinternal
*  Callback function declaration for a fingerprint generation request.
*  @param callback_data [in] Value passed to the user_data parameter of the function this callback was
passed to
*  @param musicidfile_query_handle [in] MusicID-File query handle that the FileInfo handle belongs
to
*  @param fileinfo [in] MusicID-File FileInfo handle that the callback operates on
*  @param current_file [in] Current number of the file being processed
*  @param total_files [in] Total number of files to be processed
*  @param p_abort [out] Set the dereferenced value to GNSDK_TRUE to abort the operation that calls
the callback
*  <p><b>Remarks:</b></p>
*  The application can implement this callback to use the
gnsdk_musicidfile_fileinfo_fingerprint_begin(), gnsdk_musicidfile_fileinfo_fingerprint_write(),
and gnsdk_musicidfile_fileinfo_fingerprint_end() APIs with the given fileinfo handle to
generate a fingerprint from raw audio. If your application already has created the fingerprint
for the respective file, it can use gnsdk_musicidfile_fileinfo_metadata_set() API with the
GNSDK_MUSICIDFILE_FILEINFO_VALUE_FINGERPRINT value to set the fingerprint to the fileinfo
handle.
This callback is called only if no fingerprint has already been set for the passed fileinfo.
* @ingroup Music_MusicIDFile_Callbacks
*/
typedef gnsdk_void_t
(GNSDK_CALLBACK_API *gnsdk_musicidfile_callback_get_fingerprint_fn)(
	gnsdk_void_t*						callback_data,
	gnsdk_musicidfile_query_handle_t	musicidfile_query_handle,
	gnsdk_musicidfile_fileinfo_handle_t	fileinfo,
	gnsdk_uint32_t						current_file,
	gnsdk_uint32_t						total_files,
	gnsdk_bool_t*						p_abort
	);



/** @internal gnsdk_musicidfile_callback_get_metadata_fn @endinternal
*  Callback function declaration for a metadata gathering request.
*  @param callback_data [in] Value passed to the user_data parameter of the function this callback was
passed to
*  @param musicidfile_query_handle [in] MusicID-File query handle that the FileInfo handle belongs
to
*  @param fileinfo [in] MusicID-File FileInfo handle that the callback operates on
*  @param current_file [in] Current number of the file being processed
*  @param total_files [in] Total number of files to be processed
*  @param p_abort [out] Set dereferenced value to GNSDK_TRUE to abort the operation that is calling
the callback
*  <p><b>Remarks:</b></p>
*  The application should implement this callback to use the
gnsdk_musicidfile_fileinfo_metadata_set() API to set any metadata values to the fileinfo
handle.
This callback is called only if no metadata has already been set for the passed fileinfo.
* @ingroup Music_MusicIDFile_Callbacks
*/
typedef gnsdk_void_t
(GNSDK_CALLBACK_API *gnsdk_musicidfile_callback_get_metadata_fn)(
	gnsdk_void_t*						callback_data,
	gnsdk_musicidfile_query_handle_t	musicidfile_query_handle,
	gnsdk_musicidfile_fileinfo_handle_t	fileinfo,
	gnsdk_uint32_t						current_file,
	gnsdk_uint32_t						total_files,
	gnsdk_bool_t*						p_abort
	);



/** @internal gnsdk_musicidfile_callback_result_available_fn @endinternal
*  Callback function declaration for a result available notification.
*  @param callback_data [in] Value passed to the user_data parameter of the function this callback was
passed to
*  @param musicidfile_query_handle [in] MusicID-File query handle that the callback operates on
*  @param response_gdo [in] GDO handle of an album in the response
*  @param current_album [in] Current number of the album in this response
*  @param total_albums [in] Total number of albums in this response
*  @param p_abort [out] Set the dereferenced value to GNSDK_TRUE to abort the operation that calls
the callback
*  <p><b>Remarks:</b></p>
* The provided response_gdo will include results for one or more files.
* @ingroup Music_MusicIDFile_Callbacks
*/
typedef gnsdk_void_t
(GNSDK_CALLBACK_API *gnsdk_musicidfile_callback_result_available_fn)(
	gnsdk_void_t*						callback_data,
	gnsdk_musicidfile_query_handle_t	musicidfile_query_handle,
	gnsdk_gdo_handle_t					response_gdo,
	gnsdk_uint32_t						current_album,
	gnsdk_uint32_t						total_albums,
	gnsdk_bool_t*						p_abort
	);



/** @internal gnsdk_musicidfile_callback_result_not_found_fn @endinternal
*  Callback function declaration for a no results notification.
*  @param callback_data [in] Value passed to the user_data parameter of the function this callback was
passed to
*  @param musicidfile_query_handle [in] MusicID-File query handle that the FileInfo handle belongs
to
*  @param fileinfo [in] MusicID-File FileInfo handle that the callback operates on
*  @param current_file [in] Current number of the file that is not found
*  @param total_files [in] Total number of files to be processed
*  @param p_abort [out] Set dereferenced value to GNSDK_TRUE to abort the operation that is calling
the callback
* @ingroup Music_MusicIDFile_Callbacks
*/
typedef gnsdk_void_t
(GNSDK_CALLBACK_API *gnsdk_musicidfile_callback_result_not_found_fn)(
	gnsdk_void_t*						callback_data,
	gnsdk_musicidfile_query_handle_t	musicidfile_query_handle,
	gnsdk_musicidfile_fileinfo_handle_t	fileinfo,
	gnsdk_uint32_t						current_file,
	gnsdk_uint32_t						total_files,
	gnsdk_bool_t*						p_abort
	);



/** @internal gnsdk_musicidfile_callback_musicid_complete_fn @endinternal
*  Callback function declaration for MusicID-File processing completion.
*  @param callback_data [in] Value passed to the user_data parameter of the function this callback was
passed to
*  @param musicidfile_query_handle [in] MusicID-File query handle that the callback operates on
*  @param musicidfile_complete_error [in] Final error value of MusicID-File operation
* @ingroup Music_MusicIDFile_Callbacks
*/
typedef gnsdk_void_t
(GNSDK_CALLBACK_API *gnsdk_musicidfile_callback_musicid_complete_fn)(
	gnsdk_void_t*						callback_data,
	gnsdk_musicidfile_query_handle_t	musicidfile_query_handle,
	gnsdk_error_t						musicidfile_complete_error
	);



/** @internal _gnsdk_musicidfile_callbacks_s @endinternal
*  Structure of callback functions for data retrieval and status updates as various MusicID-File
operations are performed.
*
*  <p><b>Remarks:</b></p>
* <p><b>Note:</b></p>
*   Ensure that callback functions that access the same global variable(s) use serialized access
methods to the shared variable(s).
* @ingroup Music_MusicIDFile_Callbacks
*/
typedef struct _gnsdk_musicidfile_callbacks_s
{
/** @internal gnsdk_musicidfile_callbacks_t::callback_status @endinternal
	  *
	  *   Callback function for MusicID-File progress status.
	* @ingroup Music_MusicIDFile_Callbacks
*/
	gnsdk_musicidfile_callback_status_fn					callback_status;


/** @internal gnsdk_musicidfile_callbacks_t::callback_get_fingerprint @endinternal
	  *
	  *   Request for application to generate fingerprint for given FileInfo.
	* @ingroup Music_MusicIDFile_Callbacks
*/
	gnsdk_musicidfile_callback_get_fingerprint_fn			callback_get_fingerprint;


/** @internal gnsdk_musicidfile_callbacks_t::callback_get_metadata @endinternal
	  *
	  *   Request for application to retrieve metadata for given FileInfo.
	* @ingroup Music_MusicIDFile_Callbacks
*/
	gnsdk_musicidfile_callback_get_metadata_fn				callback_get_metadata;


/** @internal gnsdk_musicidfile_callbacks_t::callback_result_available @endinternal
	  *
	  *   Result for one or more FileInfo has been determined by MusicID-File.
	* @ingroup Music_MusicIDFile_Callbacks
*/
	gnsdk_musicidfile_callback_result_available_fn			callback_result_available;


/** @internal gnsdk_musicidfile_callbacks_t::callback_result_not_found @endinternal
	  *
	  *   No results were found for FileInfo.
	* @ingroup Music_MusicIDFile_Callbacks
*/
	gnsdk_musicidfile_callback_result_not_found_fn			callback_result_not_found;


/** @internal gnsdk_musicidfile_callbacks_t::callback_musicid_complete @endinternal
	  *
	  *   MusicID-File processing complete for the given MusicID-File
	  *   query handle.
	* @ingroup Music_MusicIDFile_Callbacks
*/
	gnsdk_musicidfile_callback_musicid_complete_fn			callback_musicid_complete;

} gnsdk_musicidfile_callbacks_t;



/** @internal _gnsdk_musicidfile_fileinfo_callbacks_s @endinternal
*  Structure of callback functions for data retrieval for a specific FileInfo.
*
*  <p><b>Remarks:</b></p>
* <p><b>Note:</b></p>
*   Ensure that callback functions that access the same global variable(s) use serialized access
methods to the shared variable(s).
* @ingroup Music_MusicIDFile_Callbacks
*/
typedef struct _gnsdk_musicidfile_fileinfo_callbacks_s
{
/** @internal gnsdk_musicidfile_fileinfo_callbacks_t::callback_get_fingerprint @endinternal
	  *
	  *   Request for application to generate fingerprint for given Fileinfo.
	* @ingroup Music_MusicIDFile_Callbacks
*/
	gnsdk_musicidfile_callback_get_fingerprint_fn	callback_get_fingerprint;


/** @internal gnsdk_musicidfile_fileinfo_callbacks_t::callback_get_metadata @endinternal
	  *
	  *   Request for application to retrieve metadata for given FileInfo.
	* @ingroup Music_MusicIDFile_Callbacks
*/
	gnsdk_musicidfile_callback_get_metadata_fn		callback_get_metadata;

} gnsdk_musicidfile_fileinfo_callbacks_t;




/** @internal gnsdk_musicidfile_fileinfo_userdata_delete_fn @endinternal
*  Delete callback function declaration for gnsdk_musicidfile_query_fileinfo_userdata_set.
*  @param musicidfile_query_handle [in] MusicID-File query handle that the FileInfo handle belongs
to
*  @param fileinfo_handle [in] MusicID-File FileInfo handle that the userdata belongs to
*  @param userdata [in] Value provided to userdata parameter of
gnsdk_musicidfile_fileinfo_userdata_set that is to be deleted
*  <p><b>Remarks:</b></p>
*  This callback is set to the structure gnsdk_musicidfile_callbacks_t. The structure can then be
supplied to gnsdk_musicidfile_fileinfo_userdata_set.
* @ingroup Music_MusicIDFile_Callbacks
*/
typedef gnsdk_void_t
(GNSDK_CALLBACK_API *gnsdk_musicidfile_fileinfo_userdata_delete_fn)(
	gnsdk_musicidfile_query_handle_t	musicidfile_query_handle,
	gnsdk_musicidfile_fileinfo_handle_t	fileinfo_handle,
	gnsdk_void_t*						userdata
	);



/********************************************************************************
 * MusicID-File SDK query handle APIs
 ******************************************************************************/


/** @internal gnsdk_musicidfile_query_create @endinternal
*  Creates a MusicID-File query handle.
*  @param user_handle [in] User handle for the user making the query request
*  @param callbacks [in_opt] Callback function for status and progress
*  @param callback_data [in_opt] Data that is passed back through calls to the callback
functions
*  @param p_musicidfile_query_handle [out] Pointer to receive the MusicID-File query handle
*  @return MIDFERR_NotInited
*  @return MIDFERR_InvalidArg
*  @return MIDFERR_HandleObjectInvalid
*  @return MIDFERR_NoMemory
*  @return MIDFERR_NoError
* @ingroup Music_MusicIDFile_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_query_create(
	gnsdk_user_handle_t					user_handle,
	gnsdk_musicidfile_callbacks_t*		callbacks,
	gnsdk_void_t*						callback_data,
	gnsdk_musicidfile_query_handle_t*	p_musicidfile_query_handle
	);

#endif
/******************************************************************************
 * GNSDK_MUSICIDFILE_QUERY_FLAG_* values
 ******************************************************************************/

/** @internal GNSDK_MUSICIDFILE_QUERY_FLAG_RESPONSE_ALBUMS @endinternal
* Return Album responses for each fileinfo.
* This is the default mode.
* @ingroup Music_MusicIDFile_QueryFlags
*/
#define GNSDK_MUSICIDFILE_QUERY_FLAG_RESPONSE_ALBUMS		0x00000000

/** @internal GNSDK_MUSICIDFILE_QUERY_FLAG_RESPONSE_MATCHES @endinternal
* Return Album or Contributor matches for each fileinfo.
*  <p><b>Remarks:</b></p>
* When using this query flag, applications must implement response handling
* to accomodate non Album response GDOs.
* @ingroup Music_MusicIDFile_QueryFlags
*/
#define GNSDK_MUSICIDFILE_QUERY_FLAG_RESPONSE_MATCHES		0x10000000

/** @internal GNSDK_MUSICIDFILE_QUERY_FLAG_RETURN_SINGLE @endinternal
*  Return the single best result for each FileInfo. Do not use in conjunction with
GNSDK_MUSICIDFILE_QUERY_FLAG_RETURN_ALL.
*  <p><b>Remarks:</b></p>
*  This setting has MusicID-File return the single best result for each given FileInfo. The single
results are based on many internal matching heuristics and identification methods. Each FileInfo
only exists (at most) once in the set of results.
*  If no satisfactory result is determined for a FileInfo, no results are given for that FileInfo.
If a result is given, it is appropriate for the application to assume the result was arrived at with
confidence.
*  This is the recommended setting for MusicID-File.
* @ingroup Music_MusicIDFile_QueryFlags
*/
#define	GNSDK_MUSICIDFILE_QUERY_FLAG_RETURN_SINGLE			0x00000001

/** @internal GNSDK_MUSICIDFILE_QUERY_FLAG_RETURN_ALL @endinternal
*  Return all possible results for each FileInfo. Do not use in conjunction with
GNSDK_MUSICIDFILE_QUERY_FLAG_RETURN_SINGLE.
*  <p><b>Remarks:</b></p>
*  This setting has MusicID-File return all results found for each given FileInfo. These results can
arise from
*  more than one identification method and therefore the number of results can be extensive.
*  Results are returned ordered from most preferred to least. Each FileInfo can exist on more than
one result. This is not the recommended setting for MusicID-File.
* @ingroup Music_MusicIDFile_QueryFlags
*/
#define	GNSDK_MUSICIDFILE_QUERY_FLAG_RETURN_ALL				0x00000010

/** @internal GNSDK_MUSICIDFILE_QUERY_FLAG_AGGRESSIVE @endinternal
*  Indicates use of an aggressive search method when attempting to find matches.
*  <p><b>Remarks:</b></p>
*  Using this flag increases the number of network queries and resources it takes to compute a final
result. It can also result in a higher rate of false positives, since it adds more potential results
to the processing.
* @ingroup Music_MusicIDFile_QueryFlags
*/
#define	GNSDK_MUSICIDFILE_QUERY_FLAG_AGGRESSIVE				0x00000020


/** @internal GNSDK_MUSICIDFILE_QUERY_FLAG_ASYNC @endinternal
*  Processes MusicID-File on a separate thread and return immediately.
*  <p><b>Remarks:</b></p>
* This flag can be used in conjunction with GNSDK_MUSICIDFILE_QUERY_FLAG_NO_THREADS.
* @ingroup Music_MusicIDFile_QueryFlags
*/
#define	GNSDK_MUSICIDFILE_QUERY_FLAG_ASYNC					0x00000200


/** @internal GNSDK_MUSICIDFILE_QUERY_FLAG_NO_THREADS @endinternal
*  Disallows MusicID-File from creating threads for background gathering of fingerprints
* and metadata.
*  <p><b>Remarks:</b></p>
* This flag can be used in conjunction with GNSDK_MUSICIDFILE_QUERY_FLAG_ASYNC.
* @ingroup Music_MusicIDFile_QueryFlags
*/
#define	GNSDK_MUSICIDFILE_QUERY_FLAG_NO_THREADS				0x00001000

/** @internal GNSDK_MUSICIDFILE_QUERY_FLAG_DEFAULT @endinternal
*  Indicates use of default MusicID-File processing options.
* @ingroup Music_MusicIDFile_QueryFlags
*/
#define	GNSDK_MUSICIDFILE_QUERY_FLAG_DEFAULT				(GNSDK_MUSICIDFILE_QUERY_FLAG_RESPONSE_ALBUMS|GNSDK_MUSICIDFILE_QUERY_FLAG_RETURN_SINGLE)


#ifndef SWIG

/** @internal gnsdk_musicidfile_query_release @endinternal
*  Releases resources for given MusicID-File query handle.
*  @param musicidfile_query_handle [in] MusicID-File query handle to release
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_HandleObjectInvalid Given MusicID-File query handle is not a valid handle
*  @return MIDFERR_HandleObjectWrongType Given MusicID-File query handle is not a valid
*  @return MusicID-File query handle
*  @return MIDFERR_NoError MusicID-File query handle was successfully released
*  <p><b>Remarks:</b></p>
*  After gnsdk_musicidfile_query_release returns, all handles to FileInfos retrieved from the given
handle are invalid. However, all GDO handles remain valid until they are released, whether they are
retrieved from this handle or any of its FileInfos.
*  Thread Termination
*  <p><b>Important:</b></p>
*  Note that gnsdk_musicidfile_query_release attempts to cancel and wait for any processing still
occurring with the MusicID-File query handle. The application must ensure that all callbacks
will complete or this API will hang.
*  An application can use gnsdk_musicidfile_query_wait_for_complete() if a timeout interval of
is desired. When gnsdk_musicidfile_query_wait_for_complete() returns, MusicID-File is guaranteed
to be done processing, and gnsdk_musicidfile_query_release will not block.
* @ingroup Music_MusicIDFile_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_query_release(
	gnsdk_musicidfile_query_handle_t	musicidfile_query_handle
	);



/** @internal gnsdk_musicidfile_query_do_trackid @endinternal
*  Initiates TrackID processing.
*  @param musicidfile_query_handle [in] MusicID-File query handle to perform TrackID with
*  @param query_flags [in] One or more MusicID-File Query Flag values
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_HandleObjectInvalid Given MusicID-File query handle is not a valid handle
*  @return MIDFERR_HandleObjectWrongType Given MusicID-File query handle is not a valid
*  MusicID-File query handle
*  @return MIDFERR_NoMemory System is out of memory
*  @return MIDFERR_Busy MusicID-File query handle is already processing
*  @return GNSDKERR_LicenseDisallowed The functionality is not allowed by the license
*  @return GNSDKERR_LicenseExpired The license has expired for this functionality
*  @return GNSDKERR_LicenseTrialExpired The trial period has expired for this functionality
*  @return MIDFERR_NoError MusicID-File query handle was successfully created
*  <p><b>Remarks:</b></p>
*  TrackID processing performs MusicID-File recognition on each given FileInfo independently
*  and is intended to be used with small number of tracks that do not relate to other tracks in
*  the user’s collection.
* @ingroup Music_MusicIDFile_QueryFunctions
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup), complex cpu processing
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_query_do_trackid(
	gnsdk_musicidfile_query_handle_t	musicidfile_query_handle,
	gnsdk_uint32_t						query_flags
	);



/** @internal gnsdk_musicidfile_query_do_albumid @endinternal
*  Initiates AlbumID processing.
*  @param musicidfile_query_handle [in] MusicID-File query handle to perform AlbumID
*  processing with
*  @param query_flags [in] One or more MusicID-File Query Flag
*  values
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_HandleObjectInvalid Given MusicID-File query handle is not a valid handle
*  @return MIDFERR_HandleObjectWrongType Given MusicID-File query handle is not a valid
*  MusicID-File query handle
*  @return MIDFERR_NoMemory System is out of memory
*  @return MIDFERR_Busy MusicID-File query handle is already processing
*  @return  GNSDKERR_LicenseDisallowed The functionality is not allowed by the license
*  @return  GNSDKERR_LicenseExpired The license has expired for this functionality
*  @return  GNSDKERR_LicenseTrialExpired The trial period has expired for this functionality
*  @return  MIDFERR_NoError MusicID-File query handle was successfully created
*  <p><b>Remarks:</b></p>
*  AlbumID processing performs MusicID-File recognition on all of the given FileInfos as a group.
*  This type of processing can be more accurate than TrackID processing, as AlbumID processing matches
*  the files to albums. Intended to be used with a small number of related tracks.
* @ingroup Music_MusicIDFile_QueryFunctions
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup), complex cpu processing
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_query_do_albumid(
	gnsdk_musicidfile_query_handle_t	musicidfile_query_handle,
	gnsdk_uint32_t						query_flags
	);



/** @internal gnsdk_musicidfile_query_do_libraryid @endinternal
*  Initiates LibraryID processing.
*  @param musicidfile_query_handle [in] MusicID-File query handle to perform LibraryID
*  processing with
*  @param query_flags [in] One or more MusicID-File Query Flag values
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_HandleObjectInvalid Given MusicID-File query handle is not a valid handle
*  @return MIDFERR_HandleObjectWrongType Given MusicID-File query handle is not a valid
*  MusicID-File query handle
*  @return MIDFERR_NoMemory System is out of memory
*  @return MIDFERR_Busy MusicID-File query handle is already processing
*  @return  GNSDKERR_LicenseDisallowed The functionality is not allowed by the license
*  @return  GNSDKERR_LicenseExpired The license has expired for this functionality
*  @return  GNSDKERR_LicenseTrialExpired The trial period has expired for this functionality
*  @return  MIDFERR_NoError MusicID-File query handle was successfully created
*  <p><b>Remarks:</b></p>
*  LibraryID processing performs MusicID-File recognition on a large number of given FileInfos. This
processing divides the given group of FileInfos into workable batches, and then processes each batch
using AlbumID functionality.
* @ingroup Music_MusicIDFile_QueryFunctions
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup), complex cpu processing
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_query_do_libraryid(
	gnsdk_musicidfile_query_handle_t	musicidfile_query_handle,
	gnsdk_uint32_t						query_flags
	);



/** @internal gnsdk_musicidfile_query_cancel @endinternal
*  Sets the internal cancel flag for a MusicID-File query handle that is currently being processed.
*  @param musicidfile_query_handle [in] MusicID-File query handle to cancel
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_HandleObjectInvalid Given MusicID-File query handle is not a valid handle
*  @return MIDFERR_HandleObjectWrongType Given MusicID-File query handle is not a valid MusicID-File
query handle
*  @return MIDFERR_NoError MusicID-File query handle was successfully canceled
*  <p><b>Remarks:</b></p>
*  This function instructs the processing MusicID-File handle to cancel any current processing. This
call does not wait for the actual processing to terminate and returns immediately. To wait for the
processing to officially stop, you must follow this call with a call to
gnsdk_musicidfile_query_wait_for_complete.
* @ingroup Music_MusicIDFile_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_query_cancel(
	gnsdk_musicidfile_query_handle_t	musicidfile_query_handle
	);

#endif

/** @internal gnsdk_musicidfile_handle_status_t @endinternal
*  Status codes retrieved from gnsdk_musicidfile_query_status().
* @ingroup Music_MusicIDFile_TypesEnums
*/
typedef enum
{
/** @internal gnsdk_musicidfile_status_unknown @endinternal
*
*  The MusicID-File query handle status is unknown.
* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_status_unknown,

/** @internal gnsdk_musicidfile_status_unprocessed @endinternal
*
*  The MusicID-File query handle has yet to be processed.
* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_status_unprocessed			= 1,

/** @internal gnsdk_musicidfile_status_trackid_processing @endinternal
*
*   The MusicID-File query handle is currently performing TrackID
*   processing.
* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_status_trackid_processing		= 100,

/** @internal gnsdk_musicidfile_status_trackid_complete @endinternal
*
*   The MusicID-File query handle has completed TrackID processing.
* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_status_trackid_complete		= 101,

/** @internal gnsdk_musicidfile_status_trackid_cancelling @endinternal
*
*   The MusicID-File query handle is currently cancelling TrackID
*   processing.
* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_status_trackid_cancelling		= 102,

/** @internal gnsdk_musicidfile_status_trackid_cancelled @endinternal
*
*   The MusicID-File query handle has cancelled TrackID processing.
* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_status_trackid_cancelled		= 103,

/** @internal gnsdk_musicidfile_status_albumid_processing @endinternal
*
*   The MusicID-File query handle is currently performing AlbumID
*   processing.
* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_status_albumid_processing		= 200,

/** @internal gnsdk_musicidfile_status_albumid_complete @endinternal
*
*   The MusicID-File query handle has completed AlbumID processing.
* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_status_albumid_complete		= 201,

/** @internal gnsdk_musicidfile_status_albumid_cancelling @endinternal
*
*   The MusicID-File query handle is currently cancelling AlbumID
*   processing.
* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_status_albumid_cancelling		= 202,

/** @internal gnsdk_musicidfile_status_albumid_cancelled @endinternal
*
*   The MusicID-File query handle has cancelled AlbumID processing.
* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_status_albumid_cancelled		= 203,

/** @internal gnsdk_musicidfile_status_libraryid_processing @endinternal
*
*   The MusicID-File query handle is currently performing LibraryID
*   processing.
* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_status_libraryid_processing	= 300,

/** @internal gnsdk_musicidfile_status_libraryid_complete @endinternal
*
*   The MusicID-File query handle has completed LibraryID processing.
* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_status_libraryid_complete		= 301,

/** @internal gnsdk_musicidfile_status_libraryid_cancelling @endinternal
*
*   The MusicID-File query handle is currently cancelling LibraryID
*   processing.
* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_status_libraryid_cancelling	= 302,

/** @internal gnsdk_musicidfile_status_libraryid_cancelled @endinternal
*
*   The MusicID-File query handle has cancelled LibraryID processing.
* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_status_libraryid_cancelled	= 303

} gnsdk_musicidfile_handle_status_t;


#ifndef SWIG
/** @internal gnsdk_musicidfile_query_status @endinternal
*  Retrieves the processing status of a given MusicID-File query handle.
*  @param musicidfile_query_handle [in] MusicID-File query handle to retrieve status for
*  @param p_musicidfile_handle_status [out] Pointer to receive handle status value
*  @param p_musicidfile_complete_error [out] Pointer to receive last processing error value
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_NoError MusicID-File query processing status successfully retrieved
* @ingroup Music_MusicIDFile_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_query_status(
	gnsdk_musicidfile_query_handle_t	musicidfile_query_handle,
	gnsdk_musicidfile_handle_status_t*	p_musicidfile_handle_status,
	gnsdk_error_t*						p_musicidfile_complete_error
	);



/** @internal gnsdk_musicidfile_query_wait_for_complete @endinternal
*  Sets a wait time for a MusicID-File operation to complete.
*  @param musicidfile_query_handle [in] MusicID-File query handle currently processing
asynchronously
*  @param timeout_value [in] Length of time to wait in milliseconds, or the
GNSDK_MUSICIDFILE_TIMEOUT_INFINITE flag
*  @param p_musicidfile_complete_error [out] Pointer to receive error value that is returned from
MusicID-File processing upon completion.
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_HandleObjectInvalid Given MusicID-File query handle is not a valid handle
*  @return MIDFERR_HandleObjectWrongType Given MusicID-File query handle is not a valid MusicID-File
query handle
*  @return MIDFERR_Timeout Timeout value reached (processing not completed)
*  @return MIDFERR_NoError MusicID-File processing was successfully completed
*  <p><b>Remarks:</b></p>
*  Use this function to set a wait for TrackID, AlbumID or LibraryID processing to complete for
* given MusicID-File query handle.
* @ingroup Music_MusicIDFile_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_query_wait_for_complete(
	gnsdk_musicidfile_query_handle_t	musicidfile_query_handle,
	gnsdk_uint32_t						timeout_value,
	gnsdk_error_t*						p_musicidfile_complete_error
	);

#endif

/** @internal GNSDK_MUSICIDFILE_TIMEOUT_INFINITE @endinternal
*  Value for infinite wait in a call to gnsdk_musicidfile_query_wait_for_complete.
*  Otherwise enter the timeout duration in milliseconds.
* @ingroup Music_MusicIDFile_Flags
*/
#define GNSDK_MUSICIDFILE_TIMEOUT_INFINITE						0xffffffff

#ifndef SWIG
/** @internal gnsdk_musicidfile_query_option_set @endinternal
*  Sets an option for a given MusicID-File query handle.
*  @param musicidfile_query_handle [in] MusicID-File query handle to set option for
*  @param option_key   [in] An option from the available query options 
*									defined here or in gnsdk_manager.h
*  @param option_value [in] String value or one of MusicID-File Option Values that corresponds to
option key
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_InvalidArg Given value for option_key or option_value parameter is invalid
*  @return MIDFERR_HandleObjectInvalid Given MusicID-File query handle is not a valid handle
*  @return MIDFERR_HandleObjectWrongType Given MusicID-File query handle is not a valid MusicID-File
query handle
*  @return GNSDKERR_LicenseDisallowed The functionality is not allowed by the license
*  @return GNSDKERR_LicenseExpired The license has expired for this functionality
*  @return GNSDKERR_LicenseTrialExpired The trial period has expired for this functionality
*  @return MIDFERR_NoError Option was successfully set gnsdk_musicidfile_query_option_set
*  <p><b>Remarks:</b></p>
*  The option value provided for GNSDK_MUSICIDFILE_OPTION_BATCH_SIZE must be greater than zero (0).
*  The option value provided for GNSDK_MUSICIDFILE_OPTION_THREADPRIORITY must be one of the defined
MusicID-File Option Values for priority.
* @ingroup Music_MusicIDFile_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_query_option_set(
	gnsdk_musicidfile_query_handle_t	musicidfile_query_handle,
	gnsdk_cstr_t						option_key,
	gnsdk_cstr_t						option_value
	);



/** @internal gnsdk_musicidfile_query_option_get @endinternal
*  Retrieves an option for a given MusicID-File query handle.
*  @param musicidfile_query_handle [in] MusicID-File query handle to retrieve option from
*  @param option_key   [in] An option from the available query options 
*									defined here or in gnsdk_manager.h
*  @param p_option_value [out] Pointer to receive option value
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_InvalidArg Given value for option_key is invalid or given value for
p_option_value parameter is null
*  @return MIDFERR_HandleObjectInvalid Given MusicID-File query handle is not a valid handle
*  @return MIDFERR_HandleObjectWrongType Given MusicID-File query handle is not a valid MusicID-File
query handle
*  @return MIDFERR_NoError Option was successfully retrieved
* @ingroup Music_MusicIDFile_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_query_option_get(
	gnsdk_musicidfile_query_handle_t	musicidfile_query_handle,
	gnsdk_cstr_t						option_key,
	gnsdk_cstr_t*						p_option_value
	);


/********************************************************************************
 * GNSDK_MUSICIDFILE_OPTION_* values
 ******************************************************************************/

#endif

/** @internal GNSDK_MUSICIDFILE_OPTION_THREADPRIORITY @endinternal
*  Sets or retrieves the thread priority level option.
* @ingroup Music_MusicIDFile_OptionKeys
*/
#define	GNSDK_MUSICIDFILE_OPTION_THREADPRIORITY				"gnsdk_midf_option_thread_priority"


/** @internal GNSDK_MUSICIDFILE_OPTION_BATCH_SIZE @endinternal
*  Sets or retrieves the LibraryID batch size option.
*  <p><b>Remarks:</b></p>
*  When given a large number of files, LibraryID processes the files in batches. This option allows
you to configure the size of the batches.
*  The larger the batch, the fewer potential break-ups in any groupings; however, large batches
require more resources to process the batch.
* @ingroup Music_MusicIDFile_OptionKeys
*/
#define	GNSDK_MUSICIDFILE_OPTION_BATCH_SIZE					"gnsdk_midf_option_batch_size"


/** @internal GNSDK_MUSICIDFILE_OPTION_LOOKUP_MODE @endinternal
  * Indicates whether the musicidfile queries should be performed against local embedded databases or on-line.
  *
* @ingroup Music_MusicIDFile_OptionKeys
*/
#define GNSDK_MUSICIDFILE_OPTION_LOOKUP_MODE				GNSDK_QUERY_OPTION_LOOKUP_MODE

/** @internal GNSDK_MUSICIDFILE_OPTION_ENABLE_CLASSICAL_DATA @endinternal
*  Indicates whether a response should include any associated classical music data.
*  <p><b>Remarks:</b></p>
*  To retrieve classical music data, define this option key with a True value for a specific
MusicID-File query handle. This retrieves the data and automatically renders it into the XML output.
*  An application's license must be entitled to retrieve this specialized data. Contact your
Gracenote Professional Services representative with any questions about this enhanced functionality.
* @ingroup Music_MusicIDFile_OptionKeys
*/
#define GNSDK_MUSICIDFILE_OPTION_ENABLE_CLASSICAL_DATA		"gnsdk_midf_option_enable_classical"

/** @internal GNSDK_MUSICIDFILE_OPTION_ENABLE_GLOBALIDS @endinternal
*  Indicates whether a response should include any associated GlobalID data.
*  <p><b>Remarks:</b></p>
*  To retrieve GlobalID data, define this option key with a True value for a specific MusicID-File
query handle. This retrieves the data and automatically renders it into the XML output.
*  An application's license must be entitled to retrieve this specialized data. Contact your
Gracenote Professional Services representative with any questions about this enhanced functionality.
* @ingroup Music_MusicIDFile_OptionKeys
*/
#define GNSDK_MUSICIDFILE_OPTION_ENABLE_GLOBALIDS		"gnsdk_midf_option_enable_globalids"

/** @internal GNSDK_MUSICIDFILE_OPTION_ENABLE_SONIC_DATA @endinternal
*  Indicates whether a response should include any associated sonic attribute data.
*  <p><b>Remarks:</b></p>
*  To retrieve Sonic data, define this option key with a True value for a specific MusicID-File query
handle. This retrieves the data and automatically renders it into the XML output.
*  An application's license must be entitled to retrieve this specialized data. Contact your
Gracenote Professional Services
*  representative with any questions about this enhanced functionality.
* @ingroup Music_MusicIDFile_OptionKeys
*/
#define GNSDK_MUSICIDFILE_OPTION_ENABLE_SONIC_DATA			"gnsdk_midf_option_enable_sonic"

/* Will be deprecated in a future release. Use GNSDK_MUSICIDFILE_OPTION_ENABLE_SONIC_DATA instead. */
#define GNSDK_MUSICIDFILE_OPTION_ENABLE_DSP_DATA			"gnsdk_midf_option_enable_dsp"

/** @internal GNSDK_MUSICIDFILE_OPTION_ENABLE_PLAYLIST @endinternal
*  Indicates whether a response should include associated attribute data for GNSDK Playlist.
*  <p><b>Remarks:</b></p>
*  To retrieve Playlist attribute data, define this option key with a True value for a specific
MusicID-File query handle. This retrieves the data and automatically renders it into the XML output.
*  An application's license must be entitled to retrieve this specialized data. Contact your
Gracenote Professional Services representative with any questions about this enhanced functionality.
* @ingroup Music_MusicIDFile_OptionKeys
*/
#define GNSDK_MUSICIDFILE_OPTION_ENABLE_PLAYLIST			"gnsdk_midf_option_enable_playlist"

/** @internal GNSDK_MUSICIDFILE_OPTION_ENABLE_EXTERNAL_IDS @endinternal
*  Indicates whether a response should include any external IDs (third-party IDs).
*  <p><b>Remarks:</b></p>
*  External IDs are third-party IDs associated with the results (such as an Amazon ID), 
configured specifically for your application.
*  An application's license must be entitled to retrieve this specialized data. Contact your
Gracenote Professional Services representative with any questions about this enhanced functionality.
*  External IDs are supported in the following types, for the listed child and value GDOs:
*  GNSDK_GDO_TYPE_ALBUM
*  GNSDK_GDO_CHILD_EXTERNAL_ID
*  GNSDK_GDO_TYPE_TRACK
*  GNSDK_GDO_CHILD_EXTERNAL_ID
* @ingroup Music_MusicIDFile_OptionKeys
*/
#define GNSDK_MUSICIDFILE_OPTION_ENABLE_EXTERNAL_IDS			"gnsdk_midf_option_enable_xids"

/** @internal GNSDK_MUSICIDFILE_OPTION_ENABLE_CONTENT_DATA @endinternal
*  Indicates whether a response should include data for use in fetching content (like images).
*  <p><b>Remarks:</b></p>
*  To allow the GDO to be efficiently used to retrieve content data, define this option key with a True value for a specific MusicID query
handle. 
*  An application's client ID must be entitled to retrieve this specialized data. Contact your
Gracenote Professional Services representative with any questions about this enhanced functionality.
* @ingroup Music_MusicIDFile_OptionKeys
*/
#define GNSDK_MUSICIDFILE_OPTION_ENABLE_CONTENT_DATA			"gnsdk_midf_option_enable_content"

/* Will be deprecated in a future release. 
For content (like cover art, artist images, etc), use GNSDK_MUSICIDFILE_OPTION_ENABLE_CONTENT_DATA instead. 
For external 3rd party IDs, use GNSDK_MUSICIDFILE_OPTION_ENABLE_EXTERNAL_IDS instead. */
#define GNSDK_MUSICIDFILE_OPTION_ENABLE_LINK_DATA				"gnsdk_midf_option_enable_link"

/** @internal GNSDK_MUSICIDFILE_OPTION_PREFERRED_LANG @endinternal
*  Specifies the preferred language of the results that are returned.
* @ingroup Music_MusicIDFile_OptionKeys
*/
#define GNSDK_MUSICIDFILE_OPTION_PREFERRED_LANG					"gnsdk_midf_preferred_lang"

/** @internal GNSDK_MUSICIDFILE_OPTION_ONLINE_PROCESSING @endinternal
*  Indicates whether MusicID-File should Process the responses Online, this may reduce the amount of resources used by the client.
* @ingroup Music_MusicIDFile_QueryFlags
*/
#define GNSDK_MUSICIDFILE_OPTION_ONLINE_PROCESSING				"gnsdk_midf_option_online_processing"

/** @internal GNSDK_MUSICIDFILE_OPTION_PREFER_XID @endinternal
* Use this option to specify an XID which MusicID-File should try to include in any responses that are returned.
*  <p><b>Remarks:</b></p>
* This option is currently only supported when GNSDK_MUSICIDFILE_OPTION_ONLINE_PROCESSING is set to "true".
* @ingroup Music_MusicIDFile_QueryFlags
*/
#define GNSDK_MUSICIDFILE_OPTION_PREFERRED_XID					"gnsdk_midf_option_preferred_xid"

/********************************************************************************
 * GNSDK_MUSICIDFILE_OPTION_VALUE_* values
 ******************************************************************************/



/** @internal GNSDK_MUSICIDFILE_OPTION_VALUE_PRIORITY_IDLE @endinternal
*  Sets MusicID-File processing threads to idle priority.
*  GNSDK_MUSICIDFILE_OPTION_VALUE_PRIORITY_IDLE
* @ingroup Music_MusicIDFile_OptionValues
*/
#define	GNSDK_MUSICIDFILE_OPTION_VALUE_PRIORITY_IDLE		"-5"


/** @internal GNSDK_MUSICIDFILE_OPTION_VALUE_PRIORITY_LOW @endinternal
*  Sets MusicID-File processing threads to low priority (default).
*  GNSDK_MUSICIDFILE_OPTION_VALUE_PRIORITY_LOW
* @ingroup Music_MusicIDFile_OptionValues
*/
#define	GNSDK_MUSICIDFILE_OPTION_VALUE_PRIORITY_LOW			"-3"


/** @internal GNSDK_MUSICIDFILE_OPTION_VALUE_PRIORITY_NORM @endinternal
*  Sets MusicID-File processing threads to normal priority.
* @ingroup Music_MusicIDFile_OptionValues
*/
#define	GNSDK_MUSICIDFILE_OPTION_VALUE_PRIORITY_NORM		"0"


/** @internal GNSDK_MUSICIDFILE_OPTION_VALUE_PRIORITY_HIGH @endinternal
*  Sets MusicID-File processing threads to high priority.
* @ingroup Music_MusicIDFile_OptionValues
*/
#define	GNSDK_MUSICIDFILE_OPTION_VALUE_PRIORITY_HIGH		"3"


/** @internal GNSDK_MUSICIDFILE_OPTION_VALUE_PRIORITY_DEFAULT @endinternal
*  Indicates use of default MusicID-File processing thread priority.
*  GNSDK_MUSICIDFILE_OPTION_VALUE_PRIORITY_DEFAULT
* @ingroup Music_MusicIDFile_OptionValues
*/
#define GNSDK_MUSICIDFILE_OPTION_VALUE_PRIORITY_DEFAULT		GNSDK_MUSICIDFILE_OPTION_VALUE_PRIORITY_LOW


/** @internal GNSDK_MUSICIDFILE_OPTION_VALUE_BATCH_SIZE_DEFAULT @endinternal
*  Sets the LibraryID default batch size.
* @ingroup Music_MusicIDFile_OptionValues
*/
#define	GNSDK_MUSICIDFILE_OPTION_VALUE_BATCH_SIZE_DEFAULT	"150"


/** @internal gnsdk_musicidfile_query_get_response_gdo @endinternal
*  Retrieves a GDO handle containing a response with albums or contributors for all matching FileInfos.
*  @param musicidfile_query_handle [in] MusicID -File query handle to retrieve response GDO for
*  @param p_response_gdo [out] Pointer to receive the response GDO
*  handle
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return  MIDFERR_InvalidArg fileinfo_handle parameter is null
*  @return MIDFERR_HandleObjectInvalid fileinfo_handle parameter is not a valid handle value
*  @return MIDFERR_HandleObjectWrongType fileinfo_handle parameter is not a valid FileInfo handle
*  @return MIDFERR_StillProcessing MusicID-File is currently processing results, and the response
GDO is not yet available
*  @return MIDFERR_InvalidCall Cannot use this API when performing LibraryID processing
*  @return MIDFERR_NotFound Response GDO is not available
*  @return  MIDFERR_NoError MusicID-File query handle was successfully created
*  <p><b>Remarks:</b></p>
*  This function retrieves the complete response GDO for all matches for the given query handle.
*  Because of the potentially large size of the response GDO, this function is available only after
performing TrackID
*  and AlbumID processing; it will not succeed after performing LibraryID processing.
*  The response GDO (if available) is of a #GNSDK_GDO_TYPE_RESPONSE_ALBUM or #GNSDK_GDO_TYPE_RESPONSE_MATCH type.
*  Use gnsdk_musicidfile_query_status to determine if a response handle is available.
* @ingroup Music_MusicIDFile_QueryFunctions
*/
#ifndef SWIG
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_query_get_response_gdo(
	gnsdk_musicidfile_query_handle_t	musicidfile_query_handle,
	gnsdk_gdo_handle_t*					p_response_gdo
	);


/********************************************************************************
 * MusicID-File SDK filinfo handle APIs
 ******************************************************************************/

/********************************************************************************
 * GNSDK_MUSICIDFILE_FILEINFO_VALUE_* keys
 * These keys are used to get/set data from/to a gnsdk_musicidfile_fileinfo_handle_t
 ******************************************************************************/



/** @internal GNSDK_MUSICIDFILE_FILEINFO_VALUE_IDENT @endinternal
*  Retrieves an identifier string from a FileInfo object.
*  <p><b>Remarks:</b></p>
*  This macro can only be used to retrieve the identifier provided to
gnsdk_musicidfile_query_fileinfo_create when the FileInfo object was created.
*  It cannot be used to set or change the identifier.
* @ingroup Music_MusicIDFile_FileInfoValues
*/
#define GNSDK_MUSICIDFILE_FILEINFO_VALUE_IDENT					"gnsdk_midf_fileinfo_value_ident"


/** @internal GNSDK_MUSICIDFILE_FILEINFO_VALUE_FILENAME @endinternal
*  Sets or retrieves the path and file name for a FileInfo object.
*  <p><b>Remarks:</b></p>
*  When the GNSDK_MUSICIDFILE_FILEINFO_VALUE_FILENAME value is set, MusicID-File parses the file
name and extracts extra metadata to aid in identification.
* <p><b>Note:</b></p>
*  This macro only uses the specified file name value as metadata; it does not access the file in
any way.
*  Set a value of GNSDSK_NULL for this key to remove the file name and all parsed metadata from a
FileInfo object.
* @ingroup Music_MusicIDFile_FileInfoValues
*/
#define GNSDK_MUSICIDFILE_FILEINFO_VALUE_FILENAME				"gnsdk_midf_fileinfo_value_filename"


/** @internal GNSDK_MUSICIDFILE_FILEINFO_VALUE_TAGID @endinternal
*  Sets or retrieves a Gracenote TagID value for a FileInfo object.
*  <p><b>Remarks:</b></p>
*  Use this macro to set or retrieve a TAGID (also known as a PRODUCTID) for a FileInfo object. For
a discussion of Gracenote identifiers TAGID and TUI, see Identifier Comparison.
* @ingroup Music_MusicIDFile_FileInfoValues
*/
#define GNSDK_MUSICIDFILE_FILEINFO_VALUE_TAGID					"gnsdk_midf_fileinfo_value_tagid"


/** @internal GNSDK_MUSICIDFILE_FILEINFO_VALUE_TUI @endinternal
*  Sets or retrieves the TUI value for a FileInfo object.
*  <p><b>Remarks:</b></p>
*  TUIs are values provided in special cases by Gracenote. If you received TUIs from Gracenote, use
this macro to set them for a
*  FileInfo object.
*  For a discussion of Gracenote identifiers TAGID and TUI, see Identifier Comparison.
* @ingroup Music_MusicIDFile_FileInfoValues
*/
#define GNSDK_MUSICIDFILE_FILEINFO_VALUE_TUI					"gnsdk_midf_fileinfo_value_tui"


/** @internal GNSDK_MUSICIDFILE_FILEINFO_VALUE_TUI_TAG @endinternal
*  Sets or retrieves the TUI Tag value for a FileInfo object.
*  <p><b>Remarks:</b></p>
*  TUI Tags are values provided in special cases by Gracenote. If you received TUI Tags from
*  Gracenote, use this macro to set them for a FileInfo object.
* @ingroup Music_MusicIDFile_FileInfoValues
*/
#define GNSDK_MUSICIDFILE_FILEINFO_VALUE_TUI_TAG				"gnsdk_midf_fileinfo_value_tuitag"



/** @internal GNSDK_MUSICIDFILE_FILEINFO_VALUE_CDDB_IDS @endinternal
*  Retrieves or sets a Gracenote CDDB ID value for a FileInfo object.
*  <p><b>Remarks:</b></p>
*  This value is generally found in audio file tags that have been created by Apple iTunesô. For
MP3s, it is stored in a comment frame with description iTunes_CDDB_ID.
*  If the provided value does not conform to the expected iTunes_CDDB_ID format, the value is
rejected.
* @ingroup Music_MusicIDFile_FileInfoValues
*/
#define GNSDK_MUSICIDFILE_FILEINFO_VALUE_CDDB_IDS				"gnsdk_midf_fileinfo_value_cddb_ids"


/** @internal GNSDK_MUSICIDFILE_FILEINFO_VALUE_MUI @endinternal
*  Sets or retrieves the Media Unique ID (MUI) value for a FileInfo object.
*  <p><b>Remarks:</b></p>
*  MUIs are values provided in special cases by Gracenote. If you received MUIs from Gracenote, use
this macro to set them for a
*  FileInfo object.
* @ingroup Music_MusicIDFile_FileInfoValues
*/
#define GNSDK_MUSICIDFILE_FILEINFO_VALUE_MUI					"gnsdk_midf_fileinfo_value_mui"


/** @internal GNSDK_MUSICIDFILE_FILEINFO_VALUE_MEDIA_ID @endinternal
*  Sets or retrieves the Media ID value for a FileInfo object.
*  <p><b>Remarks:</b></p>
*  Media IDs are values provided in special cases by Gracenote. If you received Media IDs from
Gracenote, use this macro to set them for a FileInfo object.
* @ingroup Music_MusicIDFile_FileInfoValues
*/
#define GNSDK_MUSICIDFILE_FILEINFO_VALUE_MEDIA_ID				"gnsdk_midf_fileinfo_value_mediaid"


/** @internal GNSDK_MUSICIDFILE_FILEINFO_VALUE_ALBUMARTIST @endinternal
*  Sets or retrieves the Album Artist value for a FileInfo object.
*  <p><b>Remarks:</b></p>
*  Use this macro to set or retrieve the album level artist for a FileInfo, or to set an artist
value that is not the specific artist for the track.
*  The album artist is generally the person or persons who created the album, generally one of the
following:
*  A solo artist; for example, Erykah Badu.
*  A band; for example, the Dave Matthews Band.
*  Various artists for a compilation album; for example, an album of Christmas carols.
* <p><b>Note:</b></p>
*   For compilation albums with no clearly defined primary album artist, it is best to use Various
as the album artist.
*  At query time, algorithms in MusicID -File and Gracenote Service evaluate all provided values and
select the most appropriate artist value(s) to display. As such, you should set both the
GNSDK_MUSICIDFILE_FILEINFO_VALUE_ALBUMARTIST and GNSDK_MUSICIDFILE_FILEINFO_VALUE_TRACKARTIST fields
as much as possible, to help ensure robust results.
*  When setting only a single artist value, we advise using the
GNSDK_MUSICIDFILE_FILEINFO_VALUE_TRACKARTIST field; however, the system performs an equivalent
evaluation operation when you set only the GNSDK_MUSICIDFILE_FILEINFO_VALUE_ALBUMARTIST field.
*  The following values for this field are ignored as they are detrimental for recognition:
*   Artist
*      Data
*      Unknown
*      VA
*      Various Artists
* @ingroup Music_MusicIDFile_FileInfoValues
*/
#define GNSDK_MUSICIDFILE_FILEINFO_VALUE_ALBUMARTIST			"gnsdk_midf_fileinfo_value_albumartist"


/** @internal GNSDK_MUSICIDFILE_FILEINFO_VALUE_ALBUMTITLE @endinternal
*  Sets or retrieves the Album Title value for a FileInfo object.
*  <p><b>Remarks:</b></p>
*  Use this macro to set or retrieve the album title for a FileInfo object. The following values for
this field are ignored as they are detrimental for recognition:
*   Album
*      Data
*      Unknown
* @ingroup Music_MusicIDFile_FileInfoValues
*/
#define GNSDK_MUSICIDFILE_FILEINFO_VALUE_ALBUMTITLE				"gnsdk_midf_fileinfo_value_albumtitle"


/** @internal GNSDK_MUSICIDFILE_FILEINFO_VALUE_TRACKARTIST @endinternal
*  Sets or retrieves the Track Artist value for a FileInfo object.
*  <p><b>Remarks:</b></p>
*  Use this macro to set or retrieve the track level artist for a FileInfo object.
*  The track artist is generally the person or persons featured on the specific track, which may be:
*  The primary album artist; for example, Erykah Badu.
*  The primary album artist with one or more guest artists, whether the primary album artist is or
is not heard on the track; for example:
*  Erykah Badu with Steve Marley
*  Moby featuring MC Lyte and Angie Stone
*  The lead singer for a band; for example, Dave Matthews of the Dave Matthews Band.
*  An artist for track on a compilation album; for example, Billie Holiday on an album of classic
jazz standards.
*  At query time, algorithms in MusicID -File and Gracenote Service evaluate all provided values and
select the most appropriate artist value(s) to display. As such, you should set both the
GNSDK_MUSICIDFILE_FILEINFO_VALUE_ALBUMARTIST and GNSDK_MUSICIDFILE_FILEINFO_VALUE_TRACKARTIST fields
as much as possible, to help ensure robust results.
*  When setting only a single artist value, we advise using the
GNSDK_MUSICIDFILE_FILEINFO_VALUE_TRACKARTIST field; however, the system performs an equivalent
evaluation operation when you set only the GNSDK_MUSICIDFILE_FILEINFO_VALUE_ALBUMARTIST field.
*  The following values for this field are ignored as they are detrimental for recognition:
*   Album
*      Artist
*      Data
*      Unknown
*      VA
*      Various Artists
* @ingroup Music_MusicIDFile_FileInfoValues
*/
#define GNSDK_MUSICIDFILE_FILEINFO_VALUE_TRACKARTIST			"gnsdk_midf_fileinfo_value_trackartist"


/** @internal GNSDK_MUSICIDFILE_FILEINFO_VALUE_TRACKTITLE @endinternal
*  Sets or retrieves the Track Title value for a FileInfo object.
*  <p><b>Remarks:</b></p>
*  Use this macro to set or retrieve the track title for a FileInfo object.
*  A certain value for this field is ignored as it is detrimental for recognition; this value is any
value of the form Track01.
* @ingroup Music_MusicIDFile_FileInfoValues
*/
#define GNSDK_MUSICIDFILE_FILEINFO_VALUE_TRACKTITLE				"gnsdk_midf_fileinfo_value_tracktitle"


/** @internal GNSDK_MUSICIDFILE_FILEINFO_VALUE_TRACKNUMBER @endinternal
*  Sets or retrieves the Track Number value for a FileInfo object.
*  <p><b>Remarks:</b></p>
*  Use this macro to set the track number for the album that this track originated from. This value
must range between 1 and 99 to be considered valid.
* @ingroup Music_MusicIDFile_FileInfoValues
*/
#define GNSDK_MUSICIDFILE_FILEINFO_VALUE_TRACKNUMBER			"gnsdk_midf_fileinfo_value_tracknumber"


/** @internal GNSDK_MUSICIDFILE_FILEINFO_VALUE_DISCNUMBER @endinternal
*  Sets or retrieves the Disc Number value for a FileInfo object.
*  <p><b>Remarks:</b></p>
*  Use this macro to set or retrieve the album number for a FileInfo object. This aids in
recognition when the album is part of a multi-disc set.
* @ingroup Music_MusicIDFile_FileInfoValues
*/
#define GNSDK_MUSICIDFILE_FILEINFO_VALUE_DISCNUMBER				"gnsdk_midf_fileinfo_value_discnumber"


/** @internal GNSDK_MUSICIDFILE_FILEINFO_VALUE_FINGERPRINT @endinternal
*  Sets or retrieves the Fingerprint value for a FileInfo object.
* @ingroup Music_MusicIDFile_FileInfoValues
*/
#define GNSDK_MUSICIDFILE_FILEINFO_VALUE_FINGERPRINT			"gnsdk_midf_fileinfo_value_fingerprint"


/** @internal GNSDK_MUSICIDFILE_FILEINFO_VALUE_TOC_OFFSETS @endinternal
*  Sets or retrieves the TOC offsets value for a FileInfo object.
*  <p><b>Remarks:</b></p>
*  Use this macro to set the TOC for a FileInfo object when you have the original CD that the audio
track originated from, and can provide the CD TOC.
*  CD TOCs are in the format: 150 2355 43789 89999 123456 Ö
* @ingroup Music_MusicIDFile_FileInfoValues
*/
#define GNSDK_MUSICIDFILE_FILEINFO_VALUE_TOC_OFFSETS			"gnsdk_midf_fileinfo_value_toc_offsets"



/********************************************************************************
 * Fileinfo data source values
 * Values for the possible sources of input information for MusicID
 ******************************************************************************/



/** @internal GNSDK_MUSICIDFILE_FILEINFO_VALUE_SOURCE_APPLICATION @endinternal
*  Indicates the FileInfo value is provided by the application.
*  "gnsdk_midf_fileinfo_value_source_application"
*  GNSDK_MUSICIDFILE_FILEINFO_VALUE_SOURCE_APPLICATION
* @ingroup Music_MusicIDFile_FileInfoValues
*/
#define GNSDK_MUSICIDFILE_FILEINFO_VALUE_SOURCE_APPLICATION		"gnsdk_midf_fileinfo_value_source_application"


/** @internal GNSDK_MUSICIDFILE_FILEINFO_VALUE_SOURCE_FILENAME @endinternal
*  Indicates the FileInfo value is derived from parsing the file.
*  GNSDK_MUSICIDFILE_FILEINFO_VALUE_SOURCE_FILENAME
* @ingroup Music_MusicIDFile_FileInfoValues
*/
#define GNSDK_MUSICIDFILE_FILEINFO_VALUE_SOURCE_FILENAME		"gnsdk_midf_fileinfo_value_source_filename"


/********************************************************************************
 * File Info Result values
 * Match values associated with a File Info object.
 ******************************************************************************/

#endif

/** @internal gnsdk_musicidfile_fileinfo_status_t @endinternal
*  The status value of the current query.
* @ingroup Music_MusicIDFile_TypesEnums
*/
typedef enum
{
/** @internal gnsdk_musicidfile_fileinfo_unprocessed @endinternal
	  *
	  *   FileInfo has not been processed.
	* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_fileinfo_unprocessed		= 0,


/** @internal gnsdk_musicidfile_fileinfo_processing @endinternal
	  *
	  *   FileInfo is currently being processed.
	* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_fileinfo_processing		= 1,


/** @internal gnsdk_musicidfile_fileinfo_error @endinternal
	  *
	  *   An error occurred while processing the FileInfo.
	* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_fileinfo_error			= 2,


/** @internal gnsdk_musicidfile_fileinfo_result_none @endinternal
	  *
	  *   No results were found for FileInfo.
	* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_fileinfo_result_none		= 3,


/** @internal gnsdk_musicidfile_fileinfo_result_single @endinternal
	  *
	  *   Single preferred response available for FileInfo.
	* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_fileinfo_result_single	= 4,


/** @internal gnsdk_musicidfile_fileinfo_result_all @endinternal
	  *
	  *   All retrieved results available for FileInfo.
	* @ingroup Music_MusicIDFile_TypesEnums
*/
	gnsdk_musicidfile_fileinfo_result_all		= 5

} gnsdk_musicidfile_fileinfo_status_t;
#ifndef SWIG
/*
 * File Info Match values
 * Match values associated with an Album Result GDO.
 */

/** @internal GNSDK_MUSICIDFILE_MATCH_HIGH_CONFIDENCE @endinternal
*  Indicates MusicID-File has flagged this result as high confidence.
*  <p><b>Remarks:</b></p>
*  The result confidence gives an indication of how the metadata provided by the application
correlates to the result metadata found by MusicID-File. A high confidence means the given metadata
matches strongly with the found result. A low confidence means the given metadata (or lack of given
metadata) does not match strongly with the found result.
*  The confidence does not indicate the strength of the final result. If, for example, only an audio
fingerprint is given for identification, but no metadata, the result could be very strongóhowever,
since there is no metadata to compare the result to, the confidence will be low. It can also
frequently be the case where MusicID-File determines the FileInfo to be something other than the
metadata provided, again this would result in a low confidence indicator but the result itself is
correct.
*  MusicID-File will always try to determine the correct result. If no suitable result is
determined, than no result is given for a FileInfo. The existence of a result should indicate to the
application an expectation of correctness, not the value of the confidence flag.
* @ingroup Music_MusicIDFile_ConfidenceValues
*/
#define GNSDK_MUSICIDFILE_MATCH_HIGH_CONFIDENCE					1

/** @internal GNSDK_MUSICIDFILE_MATCH_LOW_CONFIDENCE @endinternal
  *
  *   Indicates MusicID-File has not flagged this result as high
  *   confidence.
* @ingroup Music_MusicIDFile_ConfidenceValues
*/
#define GNSDK_MUSICIDFILE_MATCH_LOW_CONFIDENCE					0

/** @internal GNSDK_MUSICIDFILE_GDO_VALUE_IDENT @endinternal
*  Retrieve an identifier value from matching Track GDO (Track type).
*  <p><b>Remarks:</b></p>
*  MusicID-File matches each FileInfo to a Track within an Album. A result returned from
MusicID-File is of the type GNSDK_GDO_TYPE_RESPONSE_ALBUM, which contains one or more Albums
(GNSDK_GDO_TYPE_ALBUM). Each Album contains one or more Tracks (GNSDK_GDO_TYPE_TRACK).
*  Retrieve the Track child GDO and then use gnsdk_manager_gdo_value_get with
GNSDK_MUSICIDFILE_GDO_VALUE_IDENT to retrieve the identifier value given by the application for the
matching FileInfo.
* @ingroup Music_MusicIDFile_GDOValueKeys
*/
#define GNSDK_MUSICIDFILE_GDO_VALUE_IDENT						GNSDK_GDO_VALUE_IDENT

/** @internal GNSDK_MUSICIDFILE_GDO_VALUE_FILENAME @endinternal
*  Retrieve a file name value from matching Track GDO (Track type).
*  <p><b>Remarks:</b></p>
*  MusicID-File matches each FileInfo to a Track within an Album. A result returned from
MusicID-File is of the type GNSDK_GDO_TYPE_RESPONSE_ALBUM, which contains one or more Albums
(GNSDK_GDO_TYPE_ALBUM). Each Album contains one or more Tracks (GNSDK_GDO_TYPE_TRACK).
*  Retrieve the Track child GDO and then use gnsdk_manager_gdo_value_get with
GNSDK_MUSICIDFILE_GDO_VALUE_FILENAME to retrieve the file name value given by the application for
the matching FileInfo.
* @ingroup Music_MusicIDFile_GDOValueKeys
*/
#define GNSDK_MUSICIDFILE_GDO_VALUE_FILENAME					"gnsdk_midf_val_filename"


/** @internal GNSDK_MUSICIDFILE_GDO_VALUE_MATCH_TYPE @endinternal
*  Retrieve a match type value for matching Track (Track type).
*  <p><b>Remarks:</b></p>
*  MusicID-File matches each FileInfo to a Track within an Album. A result returned from
MusicID-File is of the type #GNSDK_GDO_TYPE_RESPONSE_ALBUM, which contains one or more Albums
(#GNSDK_GDO_TYPE_ALBUM). Each Album contains one or more Tracks (#GNSDK_GDO_TYPE_TRACK).
*  Retrieve the Track child GDO and then use gnsdk_manager_gdo_value_get() with
* GNSDK_MUSICIDFILE_GDO_VALUE_MATCH_TYPE to retrieve the identification method used to determine the
* match to the given Track.
*
* The match type indicates which query type was the most authoritative matching type for a given file.
* MusicID-File does a query for each type of input data, and each type of input data has an authoritative rank. 
* The match type indicates the highest authoritative matched type for this file.
* The match type is only useful in comparison to other match types. By itself it does not indicate
a strong or poor match. The higher the match type, the more authoritative the identification process
used.
* 
* The online MusicID-File query option, GNSDK_MUSICIDFILE_OPTION_ONLINE_PROCESSING, enables AlbumID to 
* group tracks into albums using Gracenote Service instead of on the client.  This option greatly improves
* AlbumID performance by reducing the amount of client-side processing and number of queries to Gracenote 
* Service. Two match types support this feature: MIDF_MATCH_TYPE_ONLINE_ALBUMID_FP and 
* MIDF_MATCH_TYPE_ONLINE_ALBUMID_TEXT.  These types indicate which query type was the most authoritative
* matching type for a given file. For more information, see the API Reference description for the
* GNSDK_GDO_VALUE_TRACK_MATCH_TYPE value key.
* 
* The following table lists all possible match type values:
* <table>
* <tr><th>Match Type</th><th>Notes</th></tr>
* <tr><td>MIDF_MATCH_TYPE_ONLINE_ALBUMID_FP</td><td>This option allows for processing tracks into albums to occur on Gracenote Service.  When using this method, an application will see large performance gains.</td></tr>
* <tr><td>MIDF_MATCH_TYPE_ONLINE_ALBUMID_TEXT</td><td>This option allows for processing tracks into albums to occur on Gracenote Service.  When using this method, an application will see large performance gains.</td></tr>
* <tr><td>MIDF_MATCH_TYPE_TUI</td><td></td></tr>
* <tr><td>MIDF_MATCH_TYPE_MUI</td><td></td></tr>
* <tr><td>MIDF_MATCH_TYPE_TOC</td><td></td></tr>
* <tr><td>MIDF_MATCH_TYPE_ASSOCIATED_ID</td><td></td></tr>
* <tr><td>MIDF_MATCH_TYPE_WF</td><td></td></tr>
* <tr><td>MIDF_MATCH_TYPE_TEXT_ON_WF</td><td></td></tr>
* <tr><td>MIDF_MATCH_TYPE_ASSOCIATED_TEXT</td><td></td></tr>
* <tr><td>MIDF_MATCH_TYPE_TEXT_TRACK</td><td></td></tr>
* <tr><td>MIDF_MATCH_TYPE_TEXT_ALBUM</td><td></td></tr>
* <tr><td>MIDF_MATCH_TYPE_TEXT_CONTRIBUTOR</td><td></td></tr>
* <tr><td>MIDF_MATCH_TYPE_NONE</td><td></td></tr>
* <tr><td>MIDF_MATCH_TYPE_INVALID</td><td></td></tr>
* </table>
* @ingroup Music_MusicIDFile_GDOValueKeys
*/
#define GNSDK_MUSICIDFILE_GDO_VALUE_MATCH_TYPE					GNSDK_GDO_VALUE_TRACK_MATCH_TYPE


/** @internal GNSDK_MUSICIDFILE_GDO_VALUE_MATCH_SCORE @endinternal
*  Retrieve a match score value for matching Track (Track type).
*  <p><b>Remarks:</b></p>
*  MusicID-File matches each FileInfo to a Track within an Album. A result returned from
MusicID-File is of the type #GNSDK_GDO_TYPE_RESPONSE_ALBUM, which contains one or more Albums
(#GNSDK_GDO_TYPE_ALBUM). Each Album contains one or more Tracks (#GNSDK_GDO_TYPE_TRACK).
*  Retrieve the Track child GDO and then use gnsdk_manager_gdo_value_get() with
* GNSDK_MUSICIDFILE_GDO_VALUE_MATCH_SCORE to retrieve the score of the match to the given Track.
*
* The match score gives a correlation between the input text and the matched track,
* indicating how well the input text matched the track. However, any result that is returned
* is considered to be a good match. The match score is only useful in comparison to other match 
* scores. By itself it does not indicate a strong or poor match.
* @ingroup Music_MusicIDFile_GDOValueKeys
*/
#define GNSDK_MUSICIDFILE_GDO_VALUE_MATCH_SCORE					GNSDK_GDO_VALUE_TEXT_MATCH_SCORE


/** @internal GNSDK_MUSICIDFILE_GDO_VALUE_MATCH_CONFIDENCE @endinternal
*  Retrieves a match confidence value for a matching Track (Track type). The confidence value is based on the match score and the match type. 
* @ingroup Music_MusicIDFile_GDOValueKeys
*/
#define GNSDK_MUSICIDFILE_GDO_VALUE_MATCH_CONFIDENCE			"gnsdk_midf_val_matchconf"


/** @internal GNSDK_MUSICIDFILE_GDO_VALUE_ALBUM_GROUP_ID @endinternal
*  Retrieve a value identifying an Album group a FileInfo is a part of.
*  <p><b>Remarks:</b></p>
*  MusicID-File matches each FileInfo to a Track within an Album. A result returned from
MusicID-File is of the type GNSDK_GDO_TYPE_RESPONSE_ALBUM, which contains one or more Albums
(GNSDK_GDO_TYPE_ALBUM). Each Album contains one or more Tracks (GNSDK_GDO_TYPE_TRACK).
*  Retrieve the Track child GDO and then use gnsdk_manager_gdo_value_get with
GNSDK_MUSICIDFILE_GDO_VALUE_ALBUM_GROUP_ID to retrieve the Album group ID for the matching FileInfo.
*  The Album group ID can help the application determine which FileInfo(s) matched to the same
Album. Two
*  FileInfos that have the same Album group ID are part of the same Album.
* @ingroup Music_MusicIDFile_GDOValueKeys
*/
#define GNSDK_MUSICIDFILE_GDO_VALUE_ALBUM_GROUP_ID				"gnsdk_midf_val_groupid"


/** @internal GNSDK_MUSICIDFILE_GDO_VALUE_ALBUM_CERTIFIED @endinternal
*  Retrieve a certification value for an Album.
* @ingroup Music_MusicIDFile_GDOValueKeys
*/
#define GNSDK_MUSICIDFILE_GDO_VALUE_ALBUM_CERTIFIED				"gnsdk_midf_val_cert"




/** @internal gnsdk_musicidfile_query_fileinfo_create @endinternal
*  Creates a gnsdk_musicidfile_fileinfo_handle_t for a MusicID-File query handle.
*  @param musicidfile_query_handle [in] MusicID-File query handle to create FileInfo for
*  @param ident_str [in] Unique string identifier for the media file this FileInfo represents
*  @param callbacks [in_opt] Callback function for status and progress for this FileInfo
*  @param callback_data [in_opt] Data that is passed back through calls to the callback
functions for this FileInfo
*  @param p_fileinfo_handle [out] Pointer to receive created FileInfo
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_InvalidArg Given value for file_name is empty or given value for
p_fileinfo_handle parameter is null
*  @return MIDFERR_HandleObjectInvalid Given MusicID-File query handle is not a valid handle
*  @return MIDFERR_HandleObjectWrongType Given MusicID-File query handle is not a valid MusicID-File
query handle
*  @return MIDFERR_NoMemory System is out of memory
*  @return MIDFERR_IdentExists The identifier already exists, and identifiers must be unique
*  @return MIDFERR_NoError MusicID-File query was handle successfully created
*  <p><b>Remarks:</b></p>
*  A FileInfo object must be created for each media file the application needs to process. Once
successfully created, the FileInfo is owned by the MusicID-File query handle and is freed when that
handle is released. An application should not release a FileInfo handle directly.
*  The identifier must be unique within the set of FileInfos for a query handle. The identifier can
be set to any string value that the application can use to uniquely identify a piece of media. This
value is not interpreted by MusicID-File during processing.
* @ingroup Music_MusicIDFile_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_query_fileinfo_create(
	gnsdk_musicidfile_query_handle_t			musicidfile_query_handle,
	gnsdk_cstr_t								ident_str,
	gnsdk_musicidfile_fileinfo_callbacks_t*		callbacks,
	gnsdk_void_t*								callback_data,
	gnsdk_musicidfile_fileinfo_handle_t* const	p_fileinfo_handle
	);



/** @internal gnsdk_musicidfile_query_fileinfo_remove @endinternal
*  Removes a FileInfo object from a MusicID-File query handle.
*  @param musicidfile_query_handle [in] MusicID-File query handle to remove FileInfo from
*  @param fileinfo_handle [in] FileInfo handle to remove
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_InvalidArg Given value for musicidfile_query_handle or fileinfo_handle parameter
is null
*  @return MIDFERR_HandleObjectInvalid Given handle for the musicidfile_query_handle or
fileinfo_handle parameter is not a valid handle
*  @return MIDFERR_HandleObjectWrongType Given musicidfile_query_handle is not a valid MusicID-File
query handle or given fileinfo_handle is not a valid FileInfo handle
*  @return MIDFERR_NoMemory System is out of memory
*  @return MIDFERR_NoError FileInfo was successfully removed from a MusicID-File query handle
*  <p><b>Remarks:</b></p>
*  In a successful removal, the resources for the given FileInfo handle are freed and the handle
becomes invalid.
* @ingroup Music_MusicIDFile_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_query_fileinfo_remove(
	gnsdk_musicidfile_query_handle_t		musicidfile_query_handle,
	gnsdk_musicidfile_fileinfo_handle_t		fileinfo_handle
	);



/** @internal gnsdk_musicidfile_query_fileinfo_create_from_xml @endinternal
*  Creates and populate FileInfos from a given XML source.
*  @param musicidfile_query_handle [in] MusicID-File query handle to remove FileInfo from
*  @param fileinfo_xml [in] XML source containing FileInfo data
*  @param p_count [out] Pointer to receive number of FileInfo elements created
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_InvalidArg Given value for fileinfo_xml is empty or given value for
musicidfile_query_handle is null
*  @return MIDFERR_HandleObjectInvalid Given MusicID-File query handle is not a valid handle
*  @return MIDFERR_HandleObjectWrongType Given MusicID-File query handle is not a valid MusicID-File
query handle
*  @return MIDFERR_NoMemory System is out of memory
*  @return MIDFERR_NoError FileInfos were successfully created from a given XML source
*  <p><b>Remarks:</b></p>
*  Instead of manually creating and populating FileInfos for a query handle, this function creates
and populate FileInfos from an
*  XML source. The format of the XML is as follows:
*  <pre>
*  {@code
*  <FILEINFOS>
*  <FILEINFO IDENT="identifier">
*  <FILENAME>path/filename of media file</FILENAME>
*  <TRACK_NAME>title of song for media file</TRACK_NAME>
*  <TRACK_ARTIST_NAME>artist or performer for song</TRACK_ARTIST_NAME>
*  <ARTIST_NAME>artist, performer or band name for album</ARTIST_NAME>
*  <ALBUM_NAME>title of album for media file</ALBUM_NAME>
*  <TRACK_NUM>number of track in album</TRACK_NUM>
*  <TAG_ID>Gracenote identifier for track found in file metadata tags (eg: ID3)</TAG_ID>
*  <FP_DATA>set of values representing a Gracenote media file fingerprint</FP_DATA>
*  </FILEINFO>
*  ... repeat <FILEINFO> for each media file to import
*  </FILEINFOS>
*  }
*  </pre>
* @ingroup Music_MusicIDFile_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_query_fileinfo_create_from_xml(
	gnsdk_musicidfile_query_handle_t	musicidfile_query_handle,
	gnsdk_cstr_t						fileinfo_xml,
	gnsdk_uint32_t*						p_count
	);


/** @internal gnsdk_musicidfile_query_fileinfo_render_to_xml @endinternal
* Renders FileInfo to XML.
*  @param musicidfile_query_handle [in] MusicID-File query handle to retrieve FileInfo count from
*  @param p_fileinfo_xml [out] Pointer to receive rendered XML
*
*  <p><b>Remarks:</b></p>
*  Use this function to render data in a MusicID-File query handle XML.<br>
*  Use <code>gnsdk_manager_string_free</code> to free the output string when the application is finished using it.
* @ingroup Music_MusicIDFile_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_query_fileinfo_render_to_xml(
	gnsdk_musicidfile_query_handle_t	musicidfile_query_handle,
	gnsdk_str_t*						p_fileinfo_xml
	);

/** @internal gnsdk_musicidfile_query_fileinfo_count @endinternal
*  Retrieves the number of the FileInfo objects created in a given MusicID-File query handle.
*  @param musicidfile_query_handle [in] MusicID-File query handle to retrieve FileInfo count from
*  @param p_count [out] Pointer to receive FileInfo count
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_InvalidArg Given value for musicidfile_query_handle or fileinfo_handle parameter
is null
*  @return MIDFERR_HandleObjectInvalid Given musicidfile_query_handle or fileinfo_handle is not a
valid handle
*  @return MIDFERR_HandleObjectWrongType Given musicidfile_query_handle is not a valid MusicID-File
query handle
*  @return MIDFERR_NoMemory System is out of memory
*  @return MIDFERR_NoError FileInfos count was successfully retrieved from the MusicID-File query
handle
*  <p><b>Remarks:</b></p>
*  Use this function to retrieve the FileInfo count of a given MusicID-File query handle.
* @ingroup Music_MusicIDFile_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_query_fileinfo_count(
	gnsdk_musicidfile_query_handle_t	musicidfile_query_handle,
	gnsdk_uint32_t*						p_count
	);



/** @internal gnsdk_musicidfile_query_fileinfo_get_by_index @endinternal
*  Retrieves the index'th FileInfo object associated with a MusicID-File handle.
*  @param musicidfile_query_handle [in] MusicID-File query handle to retrieve FileInfo from
*  @param index [in] Index of FileInfo to retrieve
*  @param p_fileinfo_handle [out] Pointer to receive FileInfo handle
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_InvalidArg Given value for musicidfile_query_handle or p_fileinfo_handle
parameter is null
*  @return MIDFERR_HandleObjectInvalid Given musicidfile_query_handle is not a valid handle
*  @return MIDFERR_HandleObjectWrongType Given musicidfile_query_handle is not a valid MusicID-File
query handle
*  @return MIDFERR_NoMemory System is out of memory
*  @return MIDFERR_NoError FileInfo was successfully retrieved from MusicID-File query handle
*  <p><b>Remarks:</b></p>
*  Retrieve the count of FileInfo in a MusicID -File query handle with
gnsdk_musicidfile_query_fileinfo_count.
* @ingroup Music_MusicIDFile_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_query_fileinfo_get_by_index(
	gnsdk_musicidfile_query_handle_t			musicidfile_query_handle,
	gnsdk_uint32_t								index,
	gnsdk_musicidfile_fileinfo_handle_t* const	p_fileinfo_handle
	);



/** @internal gnsdk_musicidfile_query_fileinfo_get_by_ident @endinternal
*  Retrieves the FileInfo object that matches the given identifier string and is associated with the
given MusicID-File handle.
*  @param musicidfile_query_handle [in] MusicID-File query handle to retrieve FileInfo from
*  @param ident_str [in] String identifier of FileInfo to retrieve
*  @param p_fileinfo_handle [out] Pointer to receive FileInfo handle
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_InvalidArg Given value for musicidfile_query_handle or p_fileinfo_handle
parameter is null
*  @return MIDFERR_HandleObjectInvalid Given musicidfile_query_handle is not a valid handle
*  @return MIDFERR_HandleObjectWrongType Given musicidfile_query_handle is not a valid MusicID-File
query handle
*  @return MIDFERR_NoMemory System is out of memory
*  @return MIDFERR_NoError FileInfo was successfully retrieved from MusicID-File query handle
*  <p><b>Remarks:</b></p>
*  The string identifier of each FileInfo is set on the call to
gnsdk_musicidfile_query_fileinfo_create.
*  MusicID-File enforces FileInfo identifiers to be unique.
* @ingroup Music_MusicIDFile_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_query_fileinfo_get_by_ident(
	gnsdk_musicidfile_query_handle_t			musicidfile_query_handle,
	gnsdk_cstr_t								ident_str,
	gnsdk_musicidfile_fileinfo_handle_t* const	p_fileinfo_handle
	);

/** @internal gnsdk_musicidfile_query_fileinfo_get_by_filename @endinternal
*  Retrieves the FileInfo object that matches the given file name and is associated with the given
MusicID-File
*  handle.
*  @param musicidfile_query_handle [in] MusicID-File query handle to retrieve FileInfo from
*  @param file_name [in] File name or other string identifier of FileInfo to retrieve
*  @param p_fileinfo_handle [out] Pointer to receive FileInfo handle
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_InvalidArg Given value for musicidfile_query_handle or p_fileinfo_handle
parameter is null
*  @return MIDFERR_HandleObjectInvalid Given musicidfile_query_handle is not a valid handle
*  @return MIDFERR_HandleObjectWrongType Given musicidfile_query_handle is not a valid MusicID-File
query handle
*  @return MIDFERR_NoMemory System is out of memory
*  @return  MIDFERR_NoError FileInfo was successfully retrieved from MusicID-File query handle
*  <p><b>Remarks:</b></p>
*  Only FileInfos that have file name information set through
gnsdk_musicidfile_fileinfo_metadata_set using the GNSDK_MUSICIDFILE_FILEINFO_VALUE_FILENAME
parameter can be retrieved with this function.
* <p><b>Note:</b></p>
*  MusicID-File does not enforce unique FileInfo file names. Consequently, to use this function
well, it is important to give unique file names to each FileInfo created (such as the full path and
file name).
*  MusicID-File does not check if the given file name given is a valid path or file name, nor is it
required to be one. MusicID-File only performs a match against the existing FileInfo path and file
names.
* @ingroup Music_MusicIDFile_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_query_fileinfo_get_by_filename(
	gnsdk_musicidfile_query_handle_t			musicidfile_query_handle,
	gnsdk_cstr_t								file_name,
	gnsdk_musicidfile_fileinfo_handle_t* const	p_fileinfo_handle
	);



/** @internal gnsdk_musicidfile_query_fileinfo_get_by_folder @endinternal
*  Retrieves the index'th FileInfo object matching the given folder name and associated with the
given MusicID-File handle.
*  @param musicidfile_query_handle [in] MusicID-File query handle to retrieve FileInfo from
*  @param folder_name [in] Folder name of FileInfo to retrieve
*  @param index [in] Index of FileInfo in folder name to retrieve
*  @param p_fileinfo_handle [out] Pointer to receive FileInfo handle
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_InvalidArg Given value for musicidfile_query_handle or p_fileinfo_handle
parameter is null
*  @return MIDFERR_HandleObjectInvalid Given musicidfile_query_handle is not a valid handle
*  @return MIDFERR_HandleObjectWrongType Given musicidfile_query_handle is not a valid MusicID-File
query handle
*  @return MIDFERR_NoMemory System is out of memory
*  @return  MIDFERR_NoError FileInfo was successfully retrieved from
*  MusicID-File query handle
*  <p><b>Remarks:</b></p>
*  Only a FileInfo that has path information set through gnsdk_musicidfile_fileinfo_metadata_set
using the GNSDK_MUSICIDFILE_FILEINFO_VALUE_FILENAME parameter can be retrieved with this function.
*  MusicID-File does not check if the given folder name is a valid path, nor is it required to be
one. MusicID-File only performs a match against existing FileInfo folder names.
* @ingroup Music_MusicIDFile_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_query_fileinfo_get_by_folder(
	gnsdk_musicidfile_query_handle_t			musicidfile_query_handle,
	gnsdk_cstr_t								folder_name,
	gnsdk_uint32_t								index,
	gnsdk_musicidfile_fileinfo_handle_t* const	p_fileinfo_handle
	);



/** @internal gnsdk_musicidfile_fileinfo_metadata_set @endinternal
*  Sets metadata information for a FileInfo object.
*  @param fileinfo_handle [in] FileInfo object handle to set metadata for
*  @param metadata_key [in] One of the FileInfo value keys
*  @param metadata_value [in] String value for the specified metadata_key
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_InvalidArg Given value for fileinfo_handle parameter is null
*  @return MIDFERR_HandleObjectInvalid Given fileinfo_handle is not a valid handle
*  @return MIDFERR_HandleObjectWrongType Given fileinfo_handle is not a valid FileInfo handle
*  @return MIDFERR_NoMemory System is out of memory
*  @return MIDFERR_NoError FileInfo metadata value was successfully set
*  <p><b>Remarks:</b></p>
*  Use this function to set metadata information for a FileInfo object using a provided FileInfo
value with a corresponding string value.
*  <p><b>Important:</b></p>
*  Ensure that all created FileInfos are set with metadata, as MusicID-File will not process
FileInfos that do not contain metadata.
* @ingroup Music_MusicIDFile_FileInfoFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_fileinfo_metadata_set(
	gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle,
	gnsdk_cstr_t						metadata_key,
	gnsdk_cstr_t						metadata_value
	);



/** @internal gnsdk_musicidfile_fileinfo_metadata_get @endinternal
*  Retrieves a metadata input value from a FileInfo object.
*  @param fileinfo_handle [in] Fileinfo object handle to retrieve metadata for
*  @param metadata_key [in] One of the Fileinfo value keys
*  @param p_data_value [out] Pointer to receive the data value defined for the specified
metadata_key
*  @param p_data_value_source [out] Pointer to receive a FileInfo value source value indicating the
whether the data value's source is either the application or a file
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_InvalidArg Given value for fileinfo_handle or p_data_value parameter is null
*  @return MIDFERR_HandleObjectInvalid Given fileinfo_handle is not a valid handle
*  @return MIDFERR_HandleObjectWrongType Given fileinfo_handle is not a valid FileInfo handle
*  @return MIDFERR_NoMemory System is out of memory
*  @return MIDFERR_NoError FileInfo metadata value was successfully retrieved
*  <p><b>Remarks:</b></p>
*  Use this function to retrieve metadata (optionally, from a specific source) defined for a
FileInfo object.
*  The p_data_value_source parameter receives a FileInfo value source value. This enables
MusicID-File to determine if the metadata is supplied by the application or retrieved by parsing a
given file. When this parameter is not defined, MusicID -File uses the application as the default
source for metadata retrieval.
* @ingroup Music_MusicIDFile_FileInfoFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_fileinfo_metadata_get(
	gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle,
	gnsdk_cstr_t						metadata_key,
	gnsdk_cstr_t*						p_data_value,
	gnsdk_cstr_t*						p_data_value_source
	);



/** @internal gnsdk_musicidfile_fileinfo_status @endinternal
*  Retrieves the current status for a specific FileInfo handle.
*  @param fileinfo_handle [in] FileInfo object handle to retrieve response code for
*  @param p_fileinfo_status [out] Pointer to receive status value
*  @param pp_error_info [out] Pointer to an error info pointer to receive extended error info
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_InvalidArg Given value for p_response_code parameter is null
*  @return MIDFERR_HandleObjectInvalid Given FileInfo handle is not a valid handle
*  @return MIDFERR_HandleObjectWrongType Given FileInfo handle is not a valid FileInfo handle
*  @return MIDFERR_NoError Response status code was successfully retrieved
*  <p><b>Remarks:</b></p>
*  The fileinfo's state value indicates what kind of response is available for a FileInfo handle after
MusicID-File. In the case of an error, the error info will be populated with diagnostic info.
*  processing has completed.
* @ingroup Music_MusicIDFile_FileInfoFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_fileinfo_status(
	gnsdk_musicidfile_fileinfo_handle_t		fileinfo_handle,
	gnsdk_musicidfile_fileinfo_status_t*	p_fileinfo_status,
	const gnsdk_error_info_t**				pp_error_info
	);



/** @internal gnsdk_musicidfile_fileinfo_get_response_gdo @endinternal
*  Retrieves a GDO handle containing the response for the given FileInfo handle.
*  @param fileinfo_handle [in] FileInfo handle to retrieve GDO from
*  @param p_response_gdo [out] Pointer to receive the GDO handle
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_InvalidArg p_response_code parameter is null
*  @return MIDFERR_HandleObjectInvalid fileinfo_handle parameter is not a valid handle value
*  @return MIDFERR_HandleObjectWrongType fileinfo_handle parameter is not a valid FileInfo handle
*  @return MIDFERR_NoError Response GDO was successfully retrieved
*  <p><b>Remarks:</b></p>
*  This function retrieves the response GDO of the match (if available) for the given query handle.
*  The response GDO (if available) is of a GNSDK_GDO_TYPE_RESPONSE_ALBUM type.
*  Use gnsdk_musicidfile_fileinfo_status to determine if a response is available for a FileInfo
handle.
* @ingroup Music_MusicIDFile_FileInfoFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_fileinfo_get_response_gdo(
	gnsdk_musicidfile_fileinfo_handle_t	fileinfo_handle,
	gnsdk_gdo_handle_t*					p_response_gdo
	);



/** @internal gnsdk_musicidfile_fileinfo_userdata_set @endinternal
*  Sets application data for a specific FileInfo handle.
*  @param fileinfo_handle [in] FileInfo object handle to set application user data for
*  @param userdata [in] Application-defined user data
*  @param delete_callback [in_opt] Application-provided delete callback for user data
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_InvalidArg Given value for fileinfo_handle parameter is null
*  @return MIDFERR_HandleObjectInvalid Given fileinfo_handle is not a valid handle
*  @return MIDFERR_HandleObjectWrongType Given fileinfo_handle is not a valid FileInfo handle
*  @return MIDFERR_NoMemory System is out of memory
*  @return MIDFERR_NoError FileInfo userdata value was successfully set
*  <p><b>Remarks:</b></p>
*  An application can attach its own data to a FileInfo to use as needed. If the delete_callback
parameter value is given, MusicID-File calls the delete callback with the userdata value when the
FileInfo is released.
* @ingroup Music_MusicIDFile_FileInfoFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_fileinfo_userdata_set(
	gnsdk_musicidfile_fileinfo_handle_t				fileinfo_handle,
	gnsdk_void_t*									userdata,
	gnsdk_musicidfile_fileinfo_userdata_delete_fn	delete_callback
	);



/** @internal gnsdk_musicidfile_fileinfo_userdata_get @endinternal
*  Retrieves application user data from a specific FileInfo handle.
*  @param fileinfo_handle [in] FileInfo object handle to retrieve application user data from
*  @param p_userdata [out] Pointer to receive application user data value
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_InvalidArg Given value for fileinfo_handle or p_data_value parameter is null
*  @return MIDFERR_HandleObjectInvalid Given fileinfo_handle is not a valid handle
*  @return MIDFERR_HandleObjectWrongType Given fileinfo_handle is not a valid Fileinfo handle
*  @return MIDFERR_NoMemory System is out of memory
*  @return MIDFERR_NoError FileInfo userdata value was successfully retrieved
*  <p><b>Remarks:</b></p>
*  The value and type of data returned is defined by the application.
* @ingroup Music_MusicIDFile_FileInfoFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_fileinfo_userdata_get(
	gnsdk_musicidfile_fileinfo_handle_t		fileinfo_handle,
	gnsdk_void_t**							p_userdata
	);



/********************************************************************************
 * MusicID-File SDK Fingerprint Generation APIs
 ******************************************************************************/



/** @internal gnsdk_musicidfile_fileinfo_fingerprint_begin @endinternal
*  Initializes fingerprint generation for a FileInfo handle.
*  @param fileinfo_handle [in] FileInfo handle to generate the fingerprint for
*  @param audio_sample_rate [in] Sample frequency of audio to be provided: 11 kHz, 22 kHz, or 44 kHz
*  @param audio_sample_size [in] Sample rate of audio to be provided (in 8-bit, 16-bit, or
*  32-bit bytes per sample)
*  @param audio_channels [in] Number of channels for audio to be provided (1 or 2)
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_InvalidArg
*  @return MIDFERR_HandleObjectInvalid
*  @return MIDFERR_HandleObjectWrongType
*  @return MIDFERR_LibraryNotLoaded
*  @return MIDFERR_Unsupported
*  @return MIDFERR_NoError
*  <p><b>Remarks:</b></p>
*  The MusicID-File fingerprinting APIs allow applications to provide audio data as a method of
identification. This enables MusicID-File to perform identification based on the audio itself, as
opposed to performing identification using only the associated metadata.
*  Use the MusicID-File fingerprinting APIs either before processing has begun, or during a
gnsdk_musicidfile_callback_get_fingerprint_fn callback.
* <p><b>Note:</b></p>
*   The application must successfully initialize the GNSDK DSP library prior to using the
MusicID-File
*  fingerprinting APIs' functionality.
* <p><b>Note:</b></p>
*   When necessary for a fingerprint query, MusicID-File automatically performs a text query and
reports the resulting metadata in the **Text Request** section of the midf.log.gnsdk_version_number
file.
* @ingroup Music_MusicIDFile_FileInfoFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_fileinfo_fingerprint_begin(
	gnsdk_musicidfile_fileinfo_handle_t	fileinfo_handle,
	gnsdk_uint32_t						audio_sample_rate,
	gnsdk_uint32_t						audio_sample_size,
	gnsdk_uint32_t						audio_channels
	);



/** @internal gnsdk_musicidfile_fileinfo_fingerprint_write @endinternal
*  Provides uncompressed audio data to a FileInfo handle for fingerprint generation.
*  @param fileinfo_handle [in] FileInfo handle to generate the fingerprint for
*  @param audio_data [in] Pointer to audio data buffer that matches the audio format described to
gnsdk_musicidfile_fileinfo_fingerprint_begin
*  @param audio_data_size [in] Size of audio data buffer (in bytes)
*  @param pb_complete [out] Pointer to receive whether the fingerprint generation has received
enough audio data
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_InvalidArg fileinfo_handle parameter is null
*  @return MIDFERR_HandleObjectInvalid fileinfo_handle parameter is not a valid handle value
*  @return MIDFERR_HandleObjectWrongType fileinfo_handle parameter is not a valid FileInfo handle
*  @return MIDFERR_LibraryNotLoaded GNSDK DSP library was not successfully initiated
*   MIDFERR_NotReady gnsdk_musicidfile_fileinfo_fingerprint_begin was not successfully initiated
*   MIDFWARN_Aborted Fingerprint generation process was aborted; additional audio data is no longer
needed
*   MIDFERR_NoError Audio for fingerprinting was accepted
*  <p><b>Remarks:</b></p>
*  The provided audio data must be uncompressed PCM data and must match the format given to
gnsdk_musicidfile_fileinfo_fingerprint_begin.
*  The p_complete parameter receives a GNSDK_TRUE value when the fingerprinting process has received
enough audio data to perform its processing. Any further provided audio data is ignored.
*  The application must provide audio data until the p_complete parameter receives a GNSDK_TRUE
value to successfully generate an audio fingerprint.
*  The application must complete the fingerprinting process by calling
gnsdk_musicidfile_fileinfo_fingerprint_end when either the audio data terminates, or after receiving
a GNSDK_TRUE value.
*  Use the MusicID-File fingerprinting APIs either before processing has begun, or during a
gnsdk_musicidfile_callback_get_fingerprint_fn callback.
* <p><b>Note:</b></p>
*   The application must successfully initialize the GNSDK DSP library prior to using the
MusicID-File
*  fingerprinting APIs' functionality.
* <p><b>Note:</b></p>
*   When necessary for a fingerprint query, MusicID-File automatically performs a text query and
reports the resulting metadata in the **Text Request** section of the midf.log.gnsdk_version_number
file.
* @ingroup Music_MusicIDFile_FileInfoFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_fileinfo_fingerprint_write(
	gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle,
	const gnsdk_void_t*					audio_data,
	gnsdk_size_t						audio_data_size,
	gnsdk_bool_t*						pb_complete
	);



/** @internal gnsdk_musicidfile_fileinfo_fingerprint_end @endinternal
*  Finalizes fingerprint generation for a FileInfo handle.
*  @param fileinfo_handle [in] FileInfo handle to generate the fingerprint for
*  @return MIDFERR_NotInited gnsdk_musicidfile_initialize was not successfully initiated
*  @return MIDFERR_InvalidArg fileinfo_handle parameter is null
*  @return MIDFERR_HandleObjectInvalid fileinfo_handle parameter is not a valid handle value
*  @return MIDFERR_HandleObjectWrongType fileinfo_handle parameter is not a valid FileInfo handle
*  @return MIDFERR_LibraryNotLoaded GNSDK DSP library was not successfully initiated
*   MIDFERR_NotReady gnsdk_musicidfile_fileinfo_fingerprint_begin was not successfully initiated
*   MIDFERR_NoError Fingerprinting was successfully finalized
*  <p><b>Remarks:</b></p>
*  The application must complete the fingerprinting process by calling
gnsdk_musicidfile_fileinfo_fingerprint_end when either the audio data terminates, or after receiving
a GNSDK_TRUE value.
*  Use the MusicID-File fingerprinting APIs either before processing has begun, or during a
gnsdk_musicidfile_callback_get_fingerprint_fn callback.
* <p><b>Note:</b></p>
*   The application must successfully initialize the GNSDK DSP library prior to using the
MusicID-File
*  fingerprinting APIs' functionality.
* <p><b>Note:</b></p>
*   When necessary for a fingerprint query, MusicID-File automatically performs a text query and
reports the resulting metadata in the **Text Request** section of the midf.log.gnsdk_version_number
file.
* @ingroup Music_MusicIDFile_FileInfoFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicidfile_fileinfo_fingerprint_end(
	gnsdk_musicidfile_fileinfo_handle_t fileinfo_handle
	);

#endif
#ifdef __cplusplus
}
#endif

#endif /* _GNSDK_MUSICID_FILE_H_ */
