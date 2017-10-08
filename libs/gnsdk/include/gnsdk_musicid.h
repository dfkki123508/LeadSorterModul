/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2013. Gracenote, Inc. All Rights Reserved.
 *
 */

#ifndef _GNSDK_MUSICID_H_
#define _GNSDK_MUSICID_H_

#include "gnsdk_status.h"
#include "gnsdk_manager_gdo.h"

#ifdef __cplusplus
extern "C"{
#endif

#ifndef SWIG
/******************************************************************************
 * Typedefs
 ******************************************************************************/

/** @internal gnsdk_musicid_query_handle_t @endinternal
*  Handle to a single MusicID query that is created by the gnsdk_musicid_query_create().
*  The application must create this handle for each MusicID query it needs to execute.
* @ingroup Music_MusicID_TypesEnums
*/
GNSDK_DECLARE_HANDLE( gnsdk_musicid_query_handle_t );


/******************************************************************************
 * Initialization APIs
 ******************************************************************************/

/** @internal gnsdk_musicid_initialize @endinternal
*  Initializes the MusicID library.
*  @param sdkmgr_handle [in] Handle from a successful gnsdk_manager_initialize() call
*  @return MIDERR_InvalidArg Given sdkmgr_handle parameter is invalid
*  @return MIDERR_HandleObjectInvalid Given sdkmgr_handle is not a valid GNSDK Manager handle
*  @return MIDERR_InitFailed Initialization failed
*  @return MIDERR_NoError Initialization succeeded
*  <p><b>Remarks:</b></p>
*  This function must be successfully called before any calls to other MusicID APIs will succeed.
This function can be called multiple times, however, all successful calls must be paired with a call
to gnsdk_musicid_shutdown(). If a call to gnsdk_musicid_initialize returns an error, then its
corresponding gnsdk_musicid_shutdown() call must not be called.
* @ingroup Music_MusicID_InitializationFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicid_initialize(
	gnsdk_manager_handle_t	sdkmgr_handle
	);

/** @internal gnsdk_musicid_shutdown @endinternal
*  Shuts down and release resources for the MusicID library.
*  @return MIDERR_NotInited gnsdk_musicid_initialize was not successfully initiated
*  @return MIDERR_NoError Shut down succeeded
*  <p><b>Remarks:</b></p>
*  All gnsdk_musicid_shutdown calls must be paired with an initial call to gnsdk_musicid_initialize().
*  The final gnsdk_musicid_shutdown call results in the library being completely shut down; all
MusicID APIs cease to function until the library is again initialized.
* @ingroup Music_MusicID_InitializationFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicid_shutdown(void);

/** @internal gnsdk_musicid_get_version @endinternal
*  Retrieves the MusicID SDK version string.
*  @return version string if successful
*  @return GNSDK_NULL if not successful
*  <p><b>Remarks:</b></p>
*  This API can be called at any time, even before initialization and after shutdown. The returned
string is a constant. Do not attempt to modify or delete.
*  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build)
*  Major: New functionality
*  Minor: New or changed features
*  Improvement: Improvements and fixes
*  Build: Internal build number
* @ingroup Music_MusicID_InitializationFunctions
*/
gnsdk_cstr_t GNSDK_API
gnsdk_musicid_get_version(void);

/** @internal gnsdk_musicid_get_build_date @endinternal
*  Retrieves the MusicID SDK's build date string.
*  @return Note Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  This API can be called at any time, even before initialization and after shutdown. The returned
string is a constant. Do not attempt to modify or delete.
*  Example build date string: 2008-02-12 00:41 UTC
* @ingroup Music_MusicID_InitializationFunctions
*/
gnsdk_cstr_t GNSDK_API
gnsdk_musicid_get_build_date(void);


/******************************************************************************
 * MusicID Query Instance Handle - for the life of the query
 ******************************************************************************/

/** @internal gnsdk_musicid_query_create @endinternal
*  Creates a MusicID query handle.
*  @param user_handle [in] User handle for the user requesting the query
*  @param callback_fn [in_opt] Callback function for status and progress
*  @param callback_data [in_opt] Data that is passed back through calls to the callback function
*  @param p_musicid_query_handle [out] Pointer to receive a MusicID query handle
*  @return MIDERR_NotInited
*  @return MIDERR_InvalidArg
*  @return MIDERR_HandleObjectInvalid
*  @return MIDERR_NoMemory
*  @return MIDERR_NoError
*  <p><b>Remarks:</b></p>
*  The application must create a gnsdk_musicid_query_handle_t for each independent MusicID operation
it needs to perform.
*  The application can create and operate multiple query handles that run simultaneously, however,
each query handle must be used only by the original thread that created it.
* @ingroup Music_MusicID_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicid_query_create(
	gnsdk_user_handle_t				user_handle,
	gnsdk_status_callback_fn		callback_fn,
	gnsdk_void_t*					callback_data,
	gnsdk_musicid_query_handle_t*	p_musicid_query_handle
	);

/** @internal gnsdk_musicid_query_release @endinternal
*  Invalidates and releases resources for a given MusicID query handle.
*  @param musicid_query_handle [in] MusicID query handle to release
*  @return MIDERR_NotInited gnsdk_musicid_initialize was not successfully initiated
*  @return MIDERR_HandleObjectInvalid Given MusicID query handle is not a valid handle
*  @return MIDERR_HandleObjectWrongType Given MusicID query handle is not a valid MusicID query
handle type
*  @return MIDERR_NoError MusicID query handle was released
* @ingroup Music_MusicID_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicid_query_release(
	gnsdk_musicid_query_handle_t	musicid_query_handle
	);


/******************************************************************************
 * MID Query Inputs APIs
 ******************************************************************************/

/** @internal gnsdk_musicid_query_set_toc_string @endinternal
*  Sets a CD TOC to allow querying of the applicable MusicID query handle.
*  @param musicid_query_handle [in] MusicID query handle this CD TOC applies to
*  @param toc_string [in] Externally produced CD TOC string
*  @return MIDERR_NotInited gnsdk_musicid_initialize was not successfully initiated
*  @return MIDERR_InvalidArg Empty value given for toc_string parameter
*  @return MIDERR_HandleObjectInvalid Parameter musicid_query_handle is not a valid handle
*  @return MIDERR_HandleObjectWrongType Parameter musicid_query_handle is not a valid MusicID query
handle
*  @return MIDERR_NoMemory System is out of memory
*  @return MIDERR_NoError CD TOC string value was successfully set
*  <p><b>Remarks:</b></p>
*  The application must retrieve the TOC string from the CD using its own methods.
*  The TOC string can contain a maximum of 100 values. The string must be formatted in increasing
value order and have each value separated by a space.
*  Example TOC String
*  "150 12659 29591 40233 54815 59277 73310 95832 108074 119356 128568 139330 148742 164924 182436
190198 198210 211200"
* <p><b>Note:</b></p>
*   Set either a CD TOC string or CD TOC offset values; do not set both functions.
*  Use both a TOC and a fingerprint in a query to help improve the accuracy of the results returned
from Gracenote Service. The use of a fingerprint as additional identification criteria aids in
increasing the number of single- and multi-exact matches and decreasing the number of fuzzy match
results. This query method is especially useful when searching Albums that contain few (four or
less) Tracks, such as CD singles.
* @ingroup Music_MusicID_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicid_query_set_toc_string(
	gnsdk_musicid_query_handle_t	musicid_query_handle,
	gnsdk_cstr_t					toc_string
	);

/** @internal gnsdk_musicid_query_add_toc_offset @endinternal
*  Sets CD TOC offset values to allow querying of the applicable MusicID query handle.
*  @param musicid_query_handle [in] MusicID query handle this TOC offset applies to.
   @param toc_offset [in] Value of CD TOC offset
*  @return MIDERR_NotInited gnsdk_musicid_initialize was not successfully initiated
*  @return MIDERR_HandleObjectInvalid Parameter musicid_query_handle is not a valid handle
*  @return MIDERR_HandleObjectWrongType Parameter musicid_query_handle is not a valid MusicID query
handle
*  @return MIDERR_NoMemory System is out of memory
*  @return MIDERR_InvalidTOC Given TOC offset value is not greater than the previous value, or
exceeded the maximum number of offsets allowed to be added
*  @return MIDERR_NoError CD TOC offset value was successfully set
*  <p><b>Remarks:</b></p>
*  This function allows an application to individually set each TOC offset value instead of having
to format a TOC string.
*  The application must retrieve the TOC values from the CD using its own methods.
*  The TOC string created by this API can contain a maximum of 100 offset values. The string must be
formatted in increasing value order and have each value separated by a space. If a given entry does
not exceed the value for the previous entry, then the call returns MIDCDERR_InvalidTOC.
* <p><b>Note:</b></p>
*   Set either a CD TOC string or CD TOC offset values; do not set both functions.
*  Cumulative TOC and Fingerprint Query Method
*  Use both a TOC and a fingerprint in a query to help improve the returned results. This querying
method is especially useful when searching Albums that contain few (four or less) Tracks, such as CD
singles. For more information, see gnsdk_musicid_query_set_toc_string() function's Remarks.
* @ingroup Music_MusicID_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicid_query_add_toc_offset(
	gnsdk_musicid_query_handle_t	musicid_query_handle,
	gnsdk_uint32_t					toc_offset
	);

/** @internal gnsdk_musicid_query_set_text @endinternal
*  Sets text for a search field used to search a MusicID query handle.
*  @param musicid_query_handle [in] MusicID query handle the text applies to
*  @param search_field [in] Search fields the search text applies to
*  @param search_text [in] Actual text set to perform a search
*  @return MIDERR_NotInited gnsdk_musicid_initialize was not successfully initiated
*  @return MIDERR_InvalidArg Empty value given for search_field parameter
*  @return MIDERR_HandleObjectInvalid Given search query handle is not a valid handle
*  @return MIDERR_HandleObjectWrongType Given search query handle is not a valid search query handle
type
*  @return MIDERR_NoMemory System is out of memory
*  @return MIDERR_NoError Query search text was successfully added
*  <p><b>Remarks:</b></p>
*  Use this function when you have album, artist, title, or lyric text you want to directly query.
* @ingroup Music_MusicID_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicid_query_set_text(
	gnsdk_musicid_query_handle_t	musicid_query_handle,
	gnsdk_cstr_t					search_field,
	gnsdk_cstr_t					search_text
	);
#endif
/** @internal GNSDK_MUSICID_FIELD_ALBUM_ARTIST @endinternal
  * Specifies text for an album artist search field that is used with gnsdk_musicid_query_set_text().
* @ingroup Music_MusicID_SearchFields
*/

#define GNSDK_MUSICID_FIELD_ALBUM_ARTIST					"gnsdk_musicid_field_album_artist"

/** @internal GNSDK_MUSICID_FIELD_TRACK_ARTIST @endinternal
* Specifies text for a track artist search field that is used with gnsdk_musicid_query_set_text().
Note: If both ALBUM_ARTIST and TRACK_ARTIST are provided, TRACK_ARTIST is given preference in matching.
* @ingroup Music_MusicID_SearchFields
*/

#define GNSDK_MUSICID_FIELD_TRACK_ARTIST					"gnsdk_musicid_field_track_artist"

/** @internal GNSDK_MUSICID_FIELD_ALBUM @endinternal
*  Specifies text for an album title search field that is used with gnsdk_musicid_query_set_text().
* @ingroup Music_MusicID_SearchFields
*/
#define GNSDK_MUSICID_FIELD_ALBUM				"gnsdk_musicid_field_album"

/** @internal GNSDK_MUSICID_FIELD_TITLE @endinternal
*  Specifies text for a track title search field that is used with gnsdk_musicid_query_set_text().
* @ingroup Music_MusicID_SearchFields
*/
#define GNSDK_MUSICID_FIELD_TITLE				"gnsdk_musicid_field_title"

/** @internal GNSDK_MUSICID_FIELD_COMPOSER @endinternal
*  Specifies text for a composer search field that is used with gnsdk_musicid_query_set_text().
* @ingroup Music_MusicID_SearchFields
*/
#define GNSDK_MUSICID_FIELD_COMPOSER			"gnsdk_musicid_field_composer"

/** @internal GNSDK_MUSICID_FIELD_LYRIC_FRAGMENT @endinternal
*  Specifies text for an lyric fragment search field that is used with gnsdk_musicid_query_set_text().
* @ingroup Music_MusicID_SearchFields
*/
#define GNSDK_MUSICID_FIELD_LYRIC_FRAGMENT		"gnsdk_musicid_field_fragment"

/** @internal GNSDK_MUSICID_FIELD_ARTIST @endinternal
* Deprecated, will be removed in a future release. 
* Specifies text for an artist name search field that is used with gnsdk_musicid_query_set_text().
* @ingroup Music_MusicID_SearchFields
*/
#define GNSDK_MUSICID_FIELD_ARTIST				"gnsdk_musicid_field_artist" /* deprecated */


#ifndef SWIG
/** @internal gnsdk_musicid_query_set_fp_data @endinternal
*  Sets externally-generated fingerprint data used to query a MusicID query handle.
*  @param musicid_query_handle [in] MusicID query handle this fingerprint data applies to
*  @param fp_data [in] String representation of fingerprint data
*  @param fp_data_type [in] One of the available fingerprint data types given by fp_data_type,
either Gracenote Fingerprint Extraction (GNFPX) or Cantametrix (CMX).
*  @return MIDERR_NotInited gnsdk_musicid_initialize was not successfully initiated
*  @return MIDERR_InvalidArg Empty value given for search_field parameter
*  @return MIDERR_HandleObjectInvalid Given search query handle is not a valid handle
*  @return MIDERR_HandleObjectWrongType Given search query handle is not a valid search query handle
type
*  @return MIDERR_NoMemory System is out of memory
*  @return MIDERR_NoError Fingerprint data was successfully added
*  <p><b>Remarks:</b></p>
*  Use this function to set externally-generated (by Gracenote Audio Thin Client) fingerprint data
for all gnsdk_musicid_find_* queries. For most applications, set the fp_data_type to the GNFPX data
type, unless you know this parameter must be set for CMX data types. Contact Gracenote with any
questions about setting this parameter.
*  After successfully calling this function, call gnsdk_musicid_query_get_fp_data().
* @ingroup Music_MusicID_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicid_query_set_fp_data(
	gnsdk_musicid_query_handle_t	musicid_query_handle,
	gnsdk_cstr_t					fp_data,
	gnsdk_cstr_t					fp_data_type
	);

/** @internal gnsdk_musicid_query_get_fp_data @endinternal
*  Retrieves externally-generated and internally-generated Gracenote Fingerprint Extraction (GNFPX)
or Cantametrix (CMX)
*  fingerprint data.
*  @param musicid_query_handle [in] MusicID query handle to retrieve the fingerprint for
*  @param p_fp_data [out] Pointer to receive the fingerprint data
*  @return MIDERR_NotInited gnsdk_musicid_initialize was not successfully initiated
*  @return MIDERR_LibraryNotLoaded GNSDK DSP library has not been successfully initialized
*  @return MIDERR_NoError Fingerprint data was successfully retrieved
*  <p><b>Remarks:</b></p>
*  Use this function to retrieve externally-generated and internally-generated (meaning, native)
GNFPX or CMX fingerprint data for cases where the application stores the fingerprint for various
purposes.
*  To explicitly set an externally-generated fingerprint, call gnsdk_musicid_query_set_fp_data() then
gnsdk_musicid_query_get_fp_data.
*  To retrieve an internally-generated fingerprint, call gnsdk_musicid_query_get_fp_data last, as
shown in the following calling sequence:
*  <ol>
*  <li>gnsdk_musicid_query_fingerprint_begin()
*  <li>gnsdk_musicid_query_fingerprint_write()
*  <li>gnsdk_musicid_query_fingerprint_end()
*  <li>gnsdk_musicid_query_get_fp_data
*  </ol>
*
* <p><b>Note:</b></p>
*   You can also implement the following advanced calling sequence for scenarios when enough data
may be available during the gnsdk_musicid_query_fingerprint_write process (as indicated by the
returned pb_complete parameter value):
*  <ol>
*  <li>gnsdk_musicid_query_fingerprint_begin()
*  <li>gnsdk_musicid_query_fingerprint_write() and the pb_complete value indicates True
*  <li>gnsdk_musicid_query_get_fp_data
*  </ol>
* @ingroup Music_MusicID_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicid_query_get_fp_data(
	gnsdk_musicid_query_handle_t	musicid_query_handle,
	gnsdk_cstr_t					*p_fp_data
	);
#endif
/** @internal GNSDK_MUSICID_FP_DATA_TYPE_STREAM3 @endinternal
*  Specifies a fingerprint used for identifying an ~3-second excerpt from an audio stream.
*  Use this fingerprint type when identifying a continuous stream of audio data and when retrieving
*  Track Match Position values with #GNSDK_GDO_VALUE_MATCH_POSITION_MS. The fingerprint represents a
*  specific point in time of the audio stream as denoted by the audio provided when the fingerprint
*  is generated.
*  <p><b>Note:</b></p>
*  Do not design your application to submit only 3 seconds of audio data; the
*  application must submit audio data until GNSDK indicates it has received enough input.
*  You must use this fingerprint or its 6-second counterpart when generating results for use with
*  GNSDK_GDO_VALUE_MATCH_POSITION_MS.
*  The usage of this type of fingerprint must be configured to your specific User ID, otherwise queries
*  of this type will not succeed.
*  Stream fingerprints are generated by one of the following methods:
*  The MusicID fingerprint generation functions:
*  gnsdk_musicid_query_fingerprint_begin()
*  gnsdk_musicid_query_fingerprint_write()
*  gnsdk_musicid_query_fingerprint_end()
*  External Thin Clients provided by Gracenote
* @ingroup Music_MusicID_FingerprintDataTypes
*/
#define GNSDK_MUSICID_FP_DATA_TYPE_STREAM3			"gnsdk_musicid_fp_3stream"
/** @internal GNSDK_MUSICID_FP_DATA_TYPE_STREAM6 @endinternal
*  Specifies a fingerprint used for identifying an ~6-second excerpt from and audio stream.
*  This is the same as GNSDK_MUSICID_FP_DATA_TYPE_STREAM3 but requires more audio data to generate
*  but could be more accurate.
*  For additional notes see GNSDK_MUSICID_FP_DATA_TYPE_STREAM3.
* @ingroup Music_MusicID_FingerprintDataTypes
*/
#define GNSDK_MUSICID_FP_DATA_TYPE_STREAM6			"gnsdk_musicid_fp_6stream"
/** @internal GNSDK_MUSICID_FP_DATA_TYPE_GNFPX @endinternal
*
* @deprecated NB: This key has been marked as deprecated and will be removed from the next major release.
*      Use GNSDK_MUSICID_FP_DATA_TYPE_STREAM3 or GNSDK_MUSICID_FP_DATA_TYPE_STREAM6 instead.
*
* @ingroup Music_MusicID_FingerprintDataTypes
*/
#define GNSDK_MUSICID_FP_DATA_TYPE_GNFPX			GNSDK_MUSICID_FP_DATA_TYPE_STREAM3
/** @internal GNSDK_MUSICID_FP_DATA_TYPE_FILE @endinternal
*  Specifies a fingerprint data type for generating fingerprints used with MusicID-File.
*  <p><b>Remarks:</b></p>
*  A MusicID-File fingerprint is a fingerprint of the beginning 16 seconds of the file.
* <p><b>Note:</b></p>
*  Do not design your application to submit only 16 seconds of a file; the
*  application must submit data until GNSDK indicates it has received enough input.
*  Use this fingerprint type when identifying audio from a file source (MusicID-File).
*
* @ingroup Music_MusicID_FingerprintDataTypes
*/
#define GNSDK_MUSICID_FP_DATA_TYPE_FILE				"gnsdk_musicid_fp_file"

/** @internal GNSDK_MUSICID_FP_DATA_TYPE_CMX @endinternal
*
* @deprecated NB: This key has been marked as deprecated and will be removed from the next major release.
*      Use GNSDK_MUSICID_FP_DATA_TYPE_FILE instead.
*
* @ingroup Music_MusicID_FingerprintDataTypes
*/
#define GNSDK_MUSICID_FP_DATA_TYPE_CMX				GNSDK_MUSICID_FP_DATA_TYPE_FILE

#ifndef SWIG
/** @internal gnsdk_musicid_query_set_gdo @endinternal
*  Sets a GDO to be used as input for a followup query.
*  @param musicid_query_handle [in] MusicID query handle this GDO applies to
*  @param query_gdo [in] Handle of GDO to query
*  @return MIDERR_NotInited
*  @return MIDERR_InvalidArg
*  @return MIDERR_HandleObjectInvalid
*  @return MIDERR_HandleObjectWrongType
*  @return MIDERR_NoMemory
*  @return MIDERR_NoError
*  <p><b>Remarks:</b></p>
*  This function allows the application to perform a follow-up query on a GDO. Use this function
when you have a GDO from a previous GNSDK result that you want to use as input to a MusicID query.
The GDO may originate from a previous MusicID query, from a deserialized GDO string, or from another
Gracenote SDK. Note that the type of the GDO has a bearing on the returned result.
* @ingroup Music_MusicID_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicid_query_set_gdo(
	gnsdk_musicid_query_handle_t	musicid_query_handle,
	gnsdk_gdo_handle_t				query_gdo
	);


gnsdk_error_t GNSDK_API
gnsdk_musicid_query_set_locale(
	gnsdk_musicid_query_handle_t	musicid_query_handle,
	gnsdk_locale_handle_t			locale_handle
	);



/** @internal gnsdk_musicid_query_fingerprint_begin @endinternal
*  Initializes native fingerprint generation for a query handle.
*  @param musicid_query_handle [in] MusicID query handle to generate the fingerprint for
*  @param fp_data_type [in] One of the available fingerprint data types given by fp_data_type,
either Gracenote Fingerprint Extraction (GNFPX) or Cantametrix (CMX).
*  @param audio_sample_rate [in] Sample rate of audio to be provided in Hz. (for example,44100)
*  @param audio_sample_size [in] Size of a single sample of audio to be provided: 8 for 8-bit audio
(0-255 integers), 16 for 16-bit audio (-32767�32768 integers), and 32 for 32-bit audio (-1.0�1.0
floating point)
*  @param audio_channels [in] Number of channels for audio to be provided (1 or 2)
*  @return MIDERR_NotInited
*  @return MIDERR_InvalidArg
*  @return MIDERR_LibraryNotLoaded
*  @return MIDERR_Unsupported
*  @return MIDERR_NoError
* @ingroup Music_MusicID_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicid_query_fingerprint_begin(
	gnsdk_musicid_query_handle_t	musicid_query_handle,
	gnsdk_cstr_t					fp_data_type,
	gnsdk_uint32_t					audio_sample_rate,
	gnsdk_uint32_t					audio_sample_size,
	gnsdk_uint32_t					audio_channels
	);

/** @internal gnsdk_musicid_query_fingerprint_write @endinternal
*  Provides uncompressed audio data to a query handle for native fingerprint generation and returns
boolean value indicating when enough data has been received.
*  @param musicid_query_handle [in] MusicID query handle to generate the fingerprint for
*  @param audio_data [in] Pointer to audio data buffer that matches audio format described to
gnsdk_musicid_query_fingerprint_begin
*  @param audio_data_size [in] Size of audio data buffer in bytes
*  @param pb_complete [out] Pointer to receive boolean value indicating whether the fingerprint
generation process gathered enough audio data
*  @return MIDERR_NotInited gnsdk_musicid_initialize was not successfully initiated
*  @return MIDERR_LibraryNotLoaded GNSDK DSP library has not been successfully initialized
*  @return MIDERR_NoError Fingerprint generation successfully written
*  <p><b>Remarks:</b></p>
*  Call this API after gnsdk_musicid_query_fingerprint_begin() to:
*  <ul>
*  <li>Generate a native Gracenote Fingerprint Extraction (GNFPX) or Cantametrix (CMX) fingerprint.
*  <li>Receive a boolean value through the pb_complete parameter indicating whether MusicID has
received sufficient audio data to generate the fingerprint.
*  </ul>
*  Additionally, if fingerprints have been generated (as shown by the returned pb_complete parameter
value):
*  <ul>
*  <li>Optimally, stop calling gnsdk_musicid_query_fingerprint_write after pb_complete returns TRUE
to conserve application resources.
*  <li>Call gnsdk_musicid_query_get_fp_data() for cases where the application needs to retrieve the
raw fingerprint value from storage.
*  </ul>
* <p><b>Note:</b></p>
*   Once gnsdk_musicid_query_fingerprint_write generates a fingerprint, it remains part of the query
handle until the handle is released (through gnsdk_musicid_query_release() ) or the fingerprint is
replaced by a subsequent call, regardless of whether gnsdk_musicid_query_get_fp_data is called. See
the Remarks of gnsdk_musicid_query_get_fp_data() for the specific uses of this function.
* @ingroup Music_MusicID_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicid_query_fingerprint_write(
	gnsdk_musicid_query_handle_t	musicid_query_handle,
	const gnsdk_void_t*				audio_data,
	gnsdk_size_t					audio_data_size,
	gnsdk_bool_t*					pb_complete
	);

/** @internal gnsdk_musicid_query_fingerprint_end @endinternal
*  Finalizes native fingerprint generation for a MusicID query handle.
*  @param musicid_query_handle [in] MusicID query handle to generate the fingerprint for
*  @return MIDERR_LibraryNotLoaded GNSDK DSP library has not been successfully initialized
*  @return MIDERR_NoMemory System is out of memory
*  <p><b>Remarks:</b></p>
*  Call this API when the audio stream ends; this alerts the system that it has received all the
available audio for the particular stream.
*  If the pb_complete parameter of gnsdk_musicid_query_fingerprint_write()
*  returns TRUE before the stream ends, we recommend that you:
*  <ul>
*  <li>Stop providing audio at that time, since enough has been received.
*  <li>Do not call gnsdk_musicid_query_fingerprint_end, as this is unnecessary.
*  </ul>
*  Fingerprints may be generated based on the call to this API; however, this is not guaranteed.
* @ingroup Music_MusicID_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicid_query_fingerprint_end(
	gnsdk_musicid_query_handle_t	musicid_query_handle
	);


/** @internal gnsdk_musicid_query_option_set @endinternal
*  Sets an option for a given MusicID query handle.
*  @param musicid_query_handle [in] MusicID query handle to set an option for
*  @param option_key [in] An option from the available query options 
*									defined here or in gnsdk_manager.h
*  @param option_value [in] A string value or one of the available MusicID Option Values that
corresponds to the defined option key
*  @return MIDERR_NotInited gnsdk_musicid_initialize was not successfully initiated
*  @return MIDERR_InvalidArg Given option_key parameter value is empty
*  @return MIDERR_HandleObjectInvalid Given MusicID query handle is not a valid handle
*  @return MIDERR_HandleObjectWrongType Given MusicID query handle is not a valid MusicID query
handle
*  @return GNSDKERR_LicenseDisallowed The functionality is not allowed by the license
*  @return GNSDKERR_LicenseExpired The license has expired for this functionality
*  @return GNSDKERR_LicenseTrialExpired The trial period has expired for this functionality
*  @return MIDERR_NoError Option was successfully set
*  <p><b>Remarks:</b></p>
* <p><b>Note:</b></p>
* @ingroup Music_MusicID_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicid_query_option_set(
	gnsdk_musicid_query_handle_t	musicid_query_handle,
	gnsdk_cstr_t					option_key,
	gnsdk_cstr_t					option_value
	);

/** @internal gnsdk_musicid_query_option_get @endinternal
*  Retrieves an option for a given MusicID query handle.
*  @param musicid_query_handle [in] MusicID query handle to retrieve an option from
*  @param option_key [in] An option from the available query options 
*									defined here or in gnsdk_manager.h
*  @param p_option_value [out] Pointer to receive option value
*  @return MIDERR_NotInited gnsdk_musicid_initialize() was not successfully initiated
*  @return MIDERR_InvalidArg Empty value given for option_key or null value given for p_option_value
parameter
*  @return MIDERR_HandleObjectInvalid Given MusicID query handle is not a valid handle
*  @return MIDERR_HandleObjectWrongType Given MusicID query handle is not a valid MusicID query
handle
*  @return MIDERR_NoError Option was successfully retrieved
* @ingroup Music_MusicID_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_musicid_query_option_get(
	gnsdk_musicid_query_handle_t	musicid_query_handle,
	gnsdk_cstr_t					option_key,
	gnsdk_cstr_t*					p_option_value
	);
#endif
/** @internal GNSDK_MUSICID_OPTION_LOOKUP_MODE @endinternal
  * Indicates whether the musicid query should be performed against local embedded databases or on-line.
  * Option values must be one of GNSDK_LOOKUP_MODE_* keys.
  *
* @ingroup Music_MusicID_OptionKeys
*/
#define GNSDK_MUSICID_OPTION_LOOKUP_MODE				GNSDK_QUERY_OPTION_LOOKUP_MODE

/** @internal GNSDK_MUSICID_OPTION_ENABLE_CLASSICAL_DATA @endinternal
*  Indicates whether a response should include any associated classical music data.
*  <p><b>Remarks:</b></p>
*  To retrieve classical music data, define this option key with a True value for a specific MusicID
query handle. This retrieves the data and automatically renders it into the XML output.
*  An application's license must be entitled to retrieve this specialized data. Contact your
Gracenote Professional Services representative with any questions about this enhanced functionality.
* @ingroup Music_MusicID_OptionKeys
*/
#define GNSDK_MUSICID_OPTION_ENABLE_CLASSICAL_DATA		"gnsdk_musicid_option_enable_classical"

/** @internal GNSDK_MUSICID_OPTION_ENABLE_GLOBALIDS @endinternal
*  Indicates whether a response should include any associated GlobalID data.
*  <p><b>Remarks:</b></p>
*  To retrieve GlobalID data, define this option key with a True value for a specific MusicID query
handle. This retrieves the data and automatically renders it into the XML output.
*  An application's license must be entitled to retrieve this specialized data. Contact your
Gracenote Professional Services representative with any questions about this enhanced functionality.
* @ingroup Music_MusicID_OptionKeys
*/
#define GNSDK_MUSICID_OPTION_ENABLE_GLOBALIDS			"gnsdk_musicid_option_enable_globalids"

/** @internal GNSDK_MUSICID_OPTION_ENABLE_SONIC_DATA @endinternal
*  Indicates whether a response should include any associated sonic attribute data.
*  <p><b>Remarks:</b></p>
*  To retrieve sonic attribute data, define this option key with a True value for a specific
MusicID query handle. This retrieves the data and automatically renders it into the XML output.
*  An application's license must be entitled to retrieve this specialized data. Contact your
Gracenote Professional Services representative with any questions about this enhanced functionality.
* @ingroup Music_MusicID_OptionKeys
*/
#define GNSDK_MUSICID_OPTION_ENABLE_SONIC_DATA			"gnsdk_musicid_option_enable_sonic"

/** @internal GNSDK_MUSICID_OPTION_ENABLE_DSP_DATA @endinternal
* Deprecated, will be removed in a future release. 
* Use #GNSDK_MUSICID_OPTION_ENABLE_SONIC_DATA instead.
* @ingroup Music_MusicID_OptionKeys
*/
#define GNSDK_MUSICID_OPTION_ENABLE_DSP_DATA			"gnsdk_musicid_option_enable_dsp"

/** @internal GNSDK_MUSICID_OPTION_ENABLE_PLAYLIST @endinternal
*  Indicates whether a response should include associated attribute data for GNSDK Playlist.
*  <p><b>Remarks:</b></p>
*  To retrieve Playlist attribute data, define this option key with a True value for a specific
MusicID query handle. This retrieves the data and automatically renders it into the XML output.
*  An application's license must be entitled to retrieve this specialized data. Contact your
Gracenote Professional Services representative with any questions about this enhanced functionality.
* @ingroup Music_MusicID_OptionKeys
*/
#define GNSDK_MUSICID_OPTION_ENABLE_PLAYLIST			"gnsdk_musicid_option_enable_playlist"

/** @internal GNSDK_MUSICID_OPTION_ENABLE_EXTERNAL_IDS @endinternal
*  Indicates whether a response should include external IDs (third-party IDs).
*  <p><b>Remarks:</b></p>
*  External IDs are third-party IDs associated with the results (such as an Amazon ID), 
configured specifically for your application.
*  An application's client ID must be entitled to retrieve this specialized data. Contact your
Gracenote Professional Services representative with any questions about this enhanced functionality.
*  External IDs are supported in the following types, for the listed child and value GDOs:
*  #GNSDK_GDO_TYPE_ALBUM
*  #GNSDK_GDO_CHILD_EXTERNAL_ID
*  #GNSDK_GDO_TYPE_TRACK
*  #GNSDK_GDO_CHILD_EXTERNAL_ID
* @ingroup Music_MusicID_OptionKeys
*/
#define GNSDK_MUSICID_OPTION_ENABLE_EXTERNAL_IDS		"gnsdk_musicid_option_enable_xids"

/** @internal GNSDK_MUSICID_OPTION_ENABLE_CONTENT_DATA @endinternal
*  Indicates whether a response should include data for use in fetching content (like images).
*  <p><b>Remarks:</b></p>
*  To allow the GDO to be efficiently used to retrieve content data, define this option key with a True value for a specific MusicID query
handle. 
*  An application's client ID must be entitled to retrieve this specialized data. Contact your
Gracenote Professional Services representative with any questions about this enhanced functionality.
* @ingroup Music_MusicID_OptionKeys
*/
#define GNSDK_MUSICID_OPTION_ENABLE_CONTENT_DATA		"gnsdk_musicid_option_enable_content"

/** @internal GNSDK_MUSICID_OPTION_ENABLE_LINK_DATA @endinternal
* Deprecated, will be removed in a future release. 
* For content (such as cover art, artist images, etc.), use #GNSDK_MUSICID_OPTION_ENABLE_CONTENT_DATA instead. 
* For external third-party IDs, use #GNSDK_MUSICID_OPTION_ENABLE_EXTERNAL_IDS instead.
* @ingroup Music_MusicID_OptionKeys
*/
#define GNSDK_MUSICID_OPTION_ENABLE_LINK_DATA			"gnsdk_musicid_option_enable_link"

/** @internal GNSDK_MUSICID_OPTION_ADDITIONAL_CREDITS @endinternal
  * Indicates that additional credits are enabled and will be returned from service.
  * @ingroup Music_MusicID_OptionKeys
  */
#define GNSDK_MUSICID_OPTION_ADDITIONAL_CREDITS			"gnsdk_musicid_option_additional_credits"

/** @internal GNSDK_MUSICID_OPTION_PREFERRED_LANG @endinternal
*  Indicates the preferred language of the returned results.
* @ingroup Music_MusicID_OptionKeys
*/
#define GNSDK_MUSICID_OPTION_PREFERRED_LANG				"gnsdk_musicid_preferred_lang"

/** @internal GNSDK_MUSICID_OPTION_RESULT_SINGLE @endinternal
*  Indicates whether a response must return only the single best result.
*  <p><b>Remarks:</b></p>
*  The MusicID library selects the single best result based on the query type and input.
*  To set or clear this option use a string representing a boolean value such as "true" or "false"
*  or GNSDK equivalent GNSDK_VALUE_TRUE or GNSDK_VALUE_FALSE.
* @ingroup Music_MusicID_OptionKeys
*/
#define GNSDK_MUSICID_OPTION_RESULT_SINGLE				"gnsdk_musicid_single_result"

/** @internal GNSDK_MUSICID_OPTION_RESULT_PREFER_XID @endinternal
*  Indicates the custom non-Gracenote identifier used to prefer the returned results.
*  Only available where a single result is requested with GNSDK_MUSICID_OPTION_RESULT_SINGLE.
*  <p><b>Note:</b></p>  
*  If you specify both  PREFER_XID and PREFER_COVER in an album query, and there is 
*  no single match that satisfies both criteria, Gracenote Service returns the  PREFER_COVER 
*  match first, followed by the PREFER_XID match.If you prefer to use cover art provided 
*  by an external partner, consider using only PREFER_XID in the query. Note that there 
*  is no guarantee that the album returned through the XID match will contain cover art.
* @ingroup Music_MusicID_OptionKeys
*/
#define GNSDK_MUSICID_OPTION_RESULT_PREFER_XID			"gnsdk_musicid_result_prefer_xid"

/** @internal GNSDK_MUSICID_OPTION_RESULT_PREFER_COVERART @endinternal
*
*  Indicates use cover art to prefer the returned results.
*  <p><b>Remarks:</b><p>
*  To set or clear this option use a string representing a boolean value such as "true" or "false"
*  or GNSDK equivalent GNSDK_VALUE_TRUE or GNSDK_VALUE_FALSE.
* @ingroup Music_MusicID_OptionKeys
*/
#define GNSDK_MUSICID_OPTION_RESULT_PREFER_COVERART		"gnsdk_musicid_result_prefer_coverart"

/** @internal GNSDK_MUSICID_OPTION_RESULT_RANGE_START @endinternal
*  Indicates whether a response must return a range of results that begin at a specified value.
*  <p><b>Remarks:</b></p>
*  This option is useful for paging through results.
* <p><b>Note:</b></p>
*  Gracenote Service enforces that the range start value must be less than or equal to the total
*  number of results. If you specify a range start value that is greater than the total number of
*  results, no results are returned.  
* <p><b>Note:</b></p>
*  If you specify both  PREFER_XID and PREFER_COVER in an album query, and there is 
*  no single match that satisfies both criteria, Gracenote Service returns the  PREFER_COVER 
*  match first, followed by the PREFER_XID match.If you prefer to use cover art provided 
*  by an external partner, consider using only PREFER_XID in the query. Note that there 
*  is no guarantee that the album returned through the XID match will contain cover art.
* @ingroup Music_MusicID_OptionKeys
*/
#define GNSDK_MUSICID_OPTION_RESULT_RANGE_START			"gnsdk_musicid_result_range_start"

/** @internal GNSDK_MUSICID_OPTION_RESULT_RANGE_SIZE @endinternal
*  Indicates whether a response can return up to a specified maximum number of results.
*  <p><b>Remarks:</b></p>
*  This option is useful for paging through results.
* <p><b>Note:</b></p>
*   Gracenote Service limits the range size for some queries. If you specify a range size greater
than the limit, the results are constrained. Additionally, neither Gracenote Service nor GNSDK
returns an error about this behavior.
*  <p><b>Important:</b></p>
*  The number of results actually returned for a query may not equal the number of results initially
requested. To accurately iterate through results, always check the range start, end, and total
values and the responses returned by Gracenote Service for the query (or queries). Ensure that you
are incrementing by using the actual last range end value plus one (range_end+1), and not by simply
using the initial requested value.
* @ingroup Music_MusicID_OptionKeys
*/
#define GNSDK_MUSICID_OPTION_RESULT_RANGE_SIZE		"gnsdk_musicid_result_range_size"

/** @internal GNSDK_MUSICID_OPTION_REVISION_CHECK @endinternal
*  Indicates whether a response must return results only when an updated revision exists.
*  <p><b>Remarks:</b></p>
*  To set or clear this option use a string representing a boolean value such as "true" or "false"
*  or GNSDK equivalent GNSDK_VALUE_TRUE or GNSDK_VALUE_FALSE.
* @ingroup Music_MusicID_OptionKeys
*/
#define GNSDK_MUSICID_OPTION_REVISION_CHECK			"gnsdk_musicid_option_revision_check"


/******************************************************************************
 * MID Query APIs
 ******************************************************************************/

#ifndef SWIG
/** @internal gnsdk_musicid_query_find_albums @endinternal
*  Performs a MusicID query for album results.
*  @param musicid_query_handle [in] MusicID query handle to perform query with
*  @param p_response_gdo [out] Pointer to receive the GDO handle with the album results
*  @return MIDERR_NotInited
*  @return MIDERR_InvalidArg
*  @return MIDERR_Busy
*  @return MIDERR_InsufficientInputData
*  @return MIDERR_HandleObjectInvalid
*  @return MIDERR_HandleObjectWrongType
*  @return MIDERR_NoMemory
*  @return MIDERR_LicenseDisallowed
*  @return MIDERR_LicenseExpired
*  @return MIDERR_LicenseTrialExpired
*  @return MIDERR_NoError
*  <p><b>Remarks:</b></p>
*  Use this function to retrieve albums based on an input defined for the query handle.
*  <p><b>Important:</b></p>
*  For all queries other than cumulative TOC and fingerprint queries, the API processes only one
single input set for a handle using the gnsdk_musicid_query_set_* functions. This means that when a
handle is defined with multiple inputs, the function processes only the last input, and disregards
all preceding inputs.
*  The response GDO, if available, is of #GNSDK_GDO_TYPE_RESPONSE_ALBUM type.
*  Valid search fields for finding albums are album title, artist name, and track title. Entering
only a lyric fragment returns an
*  MIDERR_InsufficientInputData error message. When there is insufficient input to find an album, no
results are returned.
*  This API performs the following behavior when it successfully finds no results for the query with
no errors:
*  <ul>
*  <li>Displays a return code indicating processing success; generally, a *IDERR_NoError code.
*  <li>Sets the match type to None.
*  <li>Returns a GDO for the None match type response.
*  </ul>
*  As the GDO returns only a None value, ensure that the GDO is released to conserve system
resources.
*  Licensing requirements:
*  <ul>
*  <li>To query by text requires MusicID-Search licensing.
*  <li>To query by TOC and #GNSDK_MUSICID_FP_DATA_TYPE_CMX fingerprint requires MusicID-File
licensing.
*  <li>To query by #GNSDK_MUSICID_FP_DATA_TYPE_GNFPX
*  </ul>
* <p><b>Note:</b></p>
*   Fingerprinting requires MusicID-Stream licensing.
* @ingroup Music_MusicID_QueryFunctions
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/
gnsdk_error_t GNSDK_API
gnsdk_musicid_query_find_albums(
	gnsdk_musicid_query_handle_t	musicid_query_handle,
	gnsdk_gdo_handle_t*				p_response_gdo
	);

/** @internal gnsdk_musicid_query_find_tracks @endinternal
*  Performs a MusicID query for track results.
*  @param musicid_query_handle [in] MusicID query handle to perform query with
*  @param p_response_gdo [out] Pointer to receive the GDO handle with the track results
*  @return MIDERR_NotInited
*  @return MIDERR_InvalidArg
*  @return MIDERR_Busy
*  @return MIDERR_InsufficientInputData
*  @return MIDERR_HandleObjectInvalid
*  @return MIDERR_HandleObjectWrongType
*  @return MIDERR_NoMemory
*  @return MIDERR_LicenseDisallowed
*  @return MIDERR_LicenseExpired
*  @return MIDERR_LicenseTrialExpired
*  @return MIDERR_NoError
*  <p><b>Note:</b></p>This function is being deprecated.
*  <p><b>Note:</b></p>This function does not support lookup from local databases.
*  <p><b>Remarks:</b></p>
*  Use this function to retrieve tracks based on an input defined for the query handle.
*  <p><b>Important:</b></p>
*  The API processes only one single input set for a handle (using the gnsdk_musicid_query_set_*
functions). This means that when a handle is defined with multiple inputs, the function processes
only the last input, and disregards all preceding inputs.
*  The response GDO, if available, is of #GNSDK_GDO_TYPE_RESPONSE_TRACK type.
*  The primary valid search field for finding tracks is #GNSDK_MUSICID_FIELD_TITLE, When there is
insufficient input to find a track, no results are returned.
*  Also, when performing text-based searches, the search input must closely match the resulting
track.
*  This API performs the following behavior when it successfully finds no results for the query with
no errors:
*  Displays a return code indicating processing success; generally, a *IDERR_NoError code.
*  Sets the match type to None.
*  Returns a GDO for the None match type response.
* <p><b>Note:</b></p>
*   As the GDO returns only a None value, ensure that the GDO is released to conserve system
resources.
*  Licensing requirements:
*  <ul>
*  <li>To query by text requires MusicID-Search licensing.
*  <li>To query by TOC and #GNSDK_MUSICID_FP_DATA_TYPE_CMX fingerprint requires MusicID-File
licensing.
*  <li>To query by #GNSDK_MUSICID_FP_DATA_TYPE_GNFPX fingerprint requires MusicID-Stream licensing.
*  </ul>
* @ingroup Music_MusicID_QueryFunctions
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/
GNSDK_DEPRECATED_API( \
	gnsdk_error_t GNSDK_API \
	gnsdk_musicid_query_find_tracks( \
		gnsdk_musicid_query_handle_t	musicid_query_handle, \
		gnsdk_gdo_handle_t*				p_response_gdo \
		) \
	);

/**	@internal gnsdk_musicid_query_find_matches @endinternal
  * Performs a MusicID query for matches of the best fit type (albums or contributors)
  * <p><b>Notes:</b></p>
  * <ul><li>This function does not support matching based on GDOs.</li>
  * <li>Contributor matches returned from this function cannot be used to fetch online artist images.</li></ul>
  *
  * @param musicid_query_handle [in] MusicID query handle to perform query with
  * @param p_response_gdo [out] Pointer to receive the GDO handle with the results
  *
  * @return GNSDK_SUCCESS or error.
  *
  *	@ingroup Music_MusicID_QueryFunctions
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/
gnsdk_error_t GNSDK_API
gnsdk_musicid_query_find_matches(
	gnsdk_musicid_query_handle_t	musicid_query_handle,
	gnsdk_gdo_handle_t*				p_response_gdo
	);

/** @internal gnsdk_musicid_query_find_lyrics @endinternal
*  Performs a MusicID query for lyric results.
*  @param musicid_query_handle [in] MusicID query handle to perform query with
*  @param p_response_gdo [out] Pointer to receive the GDO handle with the lyric results
*  @return MIDERR_NotInited
*  @return MIDERR_InvalidArg
*  @return MIDERR_Busy
*  @return MIDERR_InsufficientInputData
*  @return MIDERR_HandleObjectInvalid
*  @return MIDERR_HandleObjectWrongType
*  @return MIDERR_NoMemory
*  @return MIDERR_LicenseDisallowed
*  @return MIDERR_LicenseExpired
*  @return MIDERR_LicenseTrialExpired
*  @return MIDERR_NoError
*  <p><b>Remarks:</b></p>
*  Use this function to retrieve lyrics through a text-based input defined for the query handle.
(This function does not support GDO input.)
*  <p><b>Important:</b></p>
*  The API processes only one single input set for a handle (using the gnsdk_musicid_query_set_*
functions). This means that when a handle is defined with multiple inputs, the function processes
only the last input, and disregards all preceding inputs.
*  The response GDO, if available, is of #GNSDK_GDO_TYPE_RESPONSE_LYRIC type.
*  The primary valid search field for finding lyrics is #GNSDK_MUSICID_FIELD_LYRIC_FRAGMENT, and any
additional information in the album title, artist name, and track title search fields. When there is
insufficient input to find a lyric, no results are returned.
*  This API performs the following behavior when it successfully finds no results for the query with
no errors:
*  Displays a return code indicating processing success; generally, a *IDERR_NoError code.
*  Sets the match type to None.
*  Returns a GDO for the None match type response.
* <p><b>Note:</b></p>
*   As the GDO returns only a None value, ensure that the GDO is released to conserve system
resources.
*  Licensing requirements:
*  To query by text requires MusicID-Search licensing.
*  To query by TOC and #GNSDK_MUSICID_FP_DATA_TYPE_CMX fingerprint requires MusicID-File licensing.
*  To query by #GNSDK_MUSICID_FP_DATA_TYPE_GNFPX fingerprint requires MusicID-Stream licensing.
* @ingroup Music_MusicID_QueryFunctions
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/
GNSDK_DEPRECATED_API( \
	gnsdk_error_t GNSDK_API \
	gnsdk_musicid_query_find_lyrics( \
		gnsdk_musicid_query_handle_t	musicid_query_handle, \
		gnsdk_gdo_handle_t*				p_response_gdo \
		) \
	);

#endif

#ifdef __cplusplus
}
#endif

#endif /* _GNSDK_MUSICID_H_ */
