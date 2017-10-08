/*
  *
  *  GRACENOTE, INC. PROPRIETARY INFORMATION
  *  This software is supplied under the terms of a license agreement or
  *  nondisclosure agreement with Gracenote, Inc. and may not be copied
  *  or disclosed except in accordance with the terms of that agreement.
  *  Copyright(c) 2000-2013. Gracenote, Inc. All Rights Reserved.
  *
 */

#ifndef _GNSDK_VIDEO_H_

/* gnsdk_video.h: primary interface for the VideoID SDK
*/
#define _GNSDK_VIDEO_H_

#ifdef __cplusplus
extern "C"{
#endif

/*
 * gnsdk_video.h
 * Primary interface for Video SDK.
 */

/******************************************************************************
 * Typdefs
 ******************************************************************************/

/** @internal gnsdk_video_query_handle_t @endinternal
*  The VideoID query handle.
* @ingroup Video_TypesEnums
*/
GNSDK_DECLARE_HANDLE( gnsdk_video_query_handle_t );


/** @internal gnsdk_video_search_type_t @endinternal
*  The type of text search that is used to find results.
* @ingroup Video_TypesEnums
*/
typedef enum
{
/** @internal gnsdk_video_search_type_unknown @endinternal
*
*   Unknown search type; the default state.
* @ingroup Video_TypesEnums
*/
	gnsdk_video_search_type_unknown = 0,

/** @internal gnsdk_video_search_type_anchored @endinternal
*
*   Anchored text search, used for product title and suggestion searches.
*   Retrieves results that begin with the same characters as exactly
*   specified; for example, entering <i>dar</i>, <i>dark</i>, <i>dark k</i>,
*   or <i>dark kni</i> retrieves the title <i>Dark Knight,</i> but entering<i>
*   knight</i> will not retrieve<i> Dark Knight</i>. Note that this search
*   type recognizes both partial and full words.
* @ingroup Video_TypesEnums
*/
	gnsdk_video_search_type_anchored,

/** @internal gnsdk_video_search_type_default @endinternal
*
*   Normal keyword filter search for contributor, product, and work title
*   searches; for example, a search using a keyword of <i>dark</i>, <i>knight</i>,
*   or <i>dark knight </i>retrieves the title <i>Dark Knight</i>. Note that
*   this search type recognizes only full words, not partial words; this
*   means that entering only <i>dar</i> for <i>dark</i> is not recognized.
* @ingroup Video_TypesEnums
*/
	gnsdk_video_search_type_default

} gnsdk_video_search_type_t;


/** @internal gnsdk_video_initialize @endinternal
*  Initializes Gracenote VideoID and Video Explore library.
*  @param sdkmgr_handle [in] Handle from a successful gnsdk_manager_initialize call
*  @return VIDERR_InvalidArg - Given <code>sdkmgr_handle</code> parameter is invalid
*  @return VIDERR_HandleObjectInvalid - Given <code>sdkmgr_handle</code> is not a valid GNSDK Manager handle
*  @return VIDERR_InitFailed - Initialization failed
*  @return VIDERR_NoError - Initialization succeeded
*  <p><b>Remarks:</b></p>
*  This function must be successfully called before any other VideoID and Video Explore APIs will
succeed.
*  This function can be called multiple times, however, all successful calls must be paired with a
call to <code>gnsdk_video_shutdown</code>.
*  If this API returns an error, then its corresponding <code>gnsdk_video_shutdown</code>
call must not be called.
* @ingroup Video_InitializationFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_video_initialize(
	gnsdk_manager_handle_t sdkmgr_handle
	);

/** @internal gnsdk_video_shutdown @endinternal
*  Shuts down and release resources for the VideoID and Video Explore library.
*  @return VIDERR_NotInited - <code>gnsdk_video_initialize</code> was not successfully initiated
*  @return VIDERR_NoError - Success
*  <p><b>Remarks:</b></p>
*  All <code>gnsdk_video_shutdown</code> calls must be paired with a previous call to <code>gnsdk_video_initialize</code>. The
final <code>gnsdk_video_shutdown call</code> results in the library being shut down - all VideoID and Video
Explore APIs will cease to function until the library is again initialized.
* @ingroup Video_InitializationFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_video_shutdown(void);

/** @internal gnsdk_video_get_version @endinternal
*  Retrieves the VideoID and Video Explore library's version string.
*
*  This API can be called at any time, even before initialization and after shutdown. The returned
string is a constant. Do not attempt to modify or delete.
*
*  Example: <code>1.2.3.123</code> (Major.Minor.Improvement.Build)<br>
*  Major: New functionality<br>
*  Minor: New or changed features<br>
*  Improvement: Improvements and fixes<br>
*  Build: Internal build number<br>
*  @return version string if successful
*  @return GNSDK_NULL if not successful
* @ingroup Video_InitializationFunctions
*/
gnsdk_cstr_t GNSDK_API
gnsdk_video_get_version(void);

/** @internal gnsdk_video_get_build_date @endinternal
*  Retrieves the VideoID and Video Explore library's build date as a string.
*  @return String with format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  This API can be called at any time, even before initialization and after shutdown. The returned
string is a constant. Do not attempt to modify or delete.
*
*  Example:<code>"2008-02-12 00:41 UTC"</code>
* @ingroup Video_InitializationFunctions
*/
gnsdk_cstr_t GNSDK_API
gnsdk_video_get_build_date(void);

/******************************************************************************
 * VideoID Query Handle - for the life of the query
 ******************************************************************************/

/** @internal gnsdk_video_query_create @endinternal
*  Creates a VideoID or Video Explore query handle.
*  @param user_handle [in] User handle for the user requesting the query
*  @param callback_fn [in_opt] Callback function for status and progress
*  @param callback_data [in_opt] Data that is passed back through calls to the callback
functions
*  @param p_video_query_handle [out] Pointer to receive the VideoID or Video Explore query handle
*  @return VIDERR_NotInited - <code>gnsdk_video_initialize</code> was not successfully initiated
*  @return VIDERR_InvalidArg - One of the given parameter values is empty or invalid
*  @return VIDERR_HandleObjectInvalid - Given user handle is not a valid handle
*  @return VIDERR_NoMemory - System is out of memory
*  @return VIDERR_NoError - Video query handle was successfully created
*  <p><b>Remarks:</b></p>
*  Your app <b>must</b> create a <code>gnsdk_video_query_handle_t</code> for each independent set of VideoID or
Video Explore operations it needs to perform.
*
*  Your app can create and operate multiple query handles that run simultaneously, however,
each query handle <b>must</b> be used only by the original thread that created it.
* @ingroup Video_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_video_query_create(
	gnsdk_user_handle_t			user_handle,
	gnsdk_status_callback_fn	callback_fn,
	gnsdk_void_t*				callback_data,
	gnsdk_video_query_handle_t*	p_video_query_handle
	);


/** @internal gnsdk_video_query_set_toc_string @endinternal
*  Sets a video disc TOC to enable querying the applicable VideoID query handle.
*  @param video_query_handle [in] VideoID query handle this video disc TOC applies to
*  @param toc_string [in] Externally produced video TOC string
*  @param toc_string_flags [in] TOC flags for video TOC query modifiers
*  @return VIDERR_NotInited - <code>gnsdk_video_initialize</code> was not successfully initiated
*  @return VIDERR_InvalidArg - A given parameter value is empty or invalid
*  @return VIDERR_HandleObjectInvalid - Given user handle is not a valid handle
*  @return VIDERR_NoMemory - System is out of memory
*  @return VIDERR_NoError - Video TOC string value was successfully set
*  <p><b>Remarks:</b></p>
*  Use this function to set a video disc TOC string value for a product. To use this function, the
application must be licensed for VideoID.
*
*  The TOC string must be an XML string constructed by the Gracenote Video Thin Client component.
*  <p><b>Important:</b></p>
*  For most applications, set the <code>toc_string_flags</code> parameter to <code>GNSDK_VIDEO_TOC_FLAG_DEFAULT</code>.
*
*  Enable Commerce Type<br>
*  To retrieve VideoID commerce type data from Gracenote Service, use this function with
<code>GNSDK_VIDEO_OPTION_QUERY_ENABLE_COMMERCE_TYPE</code> set to <code>TRUE</code>.
* @ingroup Video_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_video_query_set_toc_string(
	gnsdk_video_query_handle_t	video_query_handle,
	gnsdk_cstr_t				toc_string,
	gnsdk_uint32_t				toc_string_flags
	);


/** @internal GNSDK_VIDEO_TOC_FLAG_DEFAULT @endinternal
*  Generally recommended flag to use when setting a video TOC.
*  <p><b>Remarks:</b></p>
*  Use this flag for the toc_string_flags parameter that is set with the
<code>gnsdk_video_query_set_toc_string</code> API, for generally all cases; this includes when using Gracenote
Video Thin Client component to produce TOC strings.
*  For cases when other VideoID TOC flags seem necessary, contact Gracenote for guidance on setting
the correct flag.
* @ingroup Video_TOCFlags
*/
#define	GNSDK_VIDEO_TOC_FLAG_DEFAULT			0x00
/** @internal GNSDK_VIDEO_TOC_FLAG_PAL @endinternal
*  Flag to indicate a given simple video TOC is from a PAL disc.
*  <p><b>Remarks:</b></p>
*  Use this flag only when directed to by Gracenote. Only special video TOCs that are provided by
Gracenote and external to the
*  GNSDK may require this flag.
* @ingroup Video_TOCFlags
*/
#define	GNSDK_VIDEO_TOC_FLAG_PAL				0x10
/** @internal GNSDK_VIDEO_TOC_FLAG_ANGLES @endinternal
*  Flag to indicate a given simple video TOC contains angle data.
*  <p><b>Remarks:</b></p>
*  Use this flag only when directed to by Gracenote. Only special video TOCs that are provided by
Gracenote and external to the
*  GNSDK may require this flag.
* @ingroup Video_TOCFlags
*/
#define	GNSDK_VIDEO_TOC_FLAG_ANGLES				0x20

/** @internal gnsdk_video_query_set_external_id @endinternal
*  Sets a video's external ID string information used to query a VideoID or Video Explore query
handle.
*  @param video_query_handle [in] VideoID or Video Explore query handle this ID applies to
*  @param external_id [in] External ID string
*  @param external_id_type [in_opt] External ID type (such as a UPC)
*  @param external_id_source [in_opt] External ID source (such as a custom external ID source)
*  @return VIDERR_NotInited - <code>gnsdk_video_initialize</code> was not successfully initiated
*  @return VIDERR_InvalidArg - A given parameter value is empty or invalid
*  @return VIDERR_NoMemory - System is out of memory
*  @return VIDERR_NoError - External ID was successfully set
*  <p><b>Remarks:</b></p>
*  Use this function to set an external ID for a product. You can set only one external ID per
product.
* @ingroup Video_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_video_query_set_external_id(
	gnsdk_video_query_handle_t	video_query_handle,
	gnsdk_cstr_t				external_id,
	gnsdk_cstr_t				external_id_type,
	gnsdk_cstr_t				external_id_source
	);

/** @internal GNSDK_VIDEO_EXTERNAL_ID_TYPE_UPC @endinternal
*  Sets a Universal Product Code (UPC) value as an external ID for a Products query.
*  <p><b>Remarks:</b></p>
*  Use as the external_id_type parameter set with the <code>gnsdk_video_query_set_external_id</code> API when
providing a video UPC value for identification.
* @ingroup Video_ExternalIDOptions
*/
#define	GNSDK_VIDEO_EXTERNAL_ID_TYPE_UPC			"gnsdk_video_xid_type_upc"

/** @internal GNSDK_VIDEO_EXTERNAL_ID_TYPE_ISAN @endinternal
*  Sets a International Standard Audiovisual Number (ISAN) code as an external ID for a Works
*  query.
*  <p><b>Remarks:</b></p>
*  Use as the <code>external_id_type</code> parameter set with the <code>gnsdk_video_query_set_external_id</code> API when
providing a video ISAN value for identification.
* @ingroup Video_ExternalIDOptions
*/
#define	GNSDK_VIDEO_EXTERNAL_ID_TYPE_ISAN			"gnsdk_video_xid_type_isan"

/** @internal GNSDK_VIDEO_EXTERNAL_ID_SOURCE_DEFAULT @endinternal
*  Sets the default external ID source.
*  <p><b>Remarks:</b></p>
*  Use for the <code>external_id_source</code> parameter with the <code>gnsdk_video_query_set_external_id</code> API when
setting custom external IDs.
*  <p><b>Important:</b></p>
*  Most applications do not require setting external IDs for products. Contact Gracenote before
using this API.
* @ingroup Video_ExternalIDOptions
*/
#define	GNSDK_VIDEO_EXTERNAL_ID_SOURCE_DEFAULT		"gnsdk_video_xid_source_gn"


/** @internal gnsdk_video_query_set_filter_by_list_element @endinternal
*  Sets a filter for a Video Explore query handle, using a value from a list.
*  @param video_query_handle [in] Video Explore query handle this filter applies to
*  @param filter_key [in] One of the video filter keys
*  @param list_element [in] A list element handle used to populate the filter value. The list
element must be from a list that corresponds to the filter name.
*  @return VIDERR_NotInited - <code>gnsdk_video_initialize</code> was not successfully initiated
*  @return VIDERR_InvalidArg - One of the given parameter values is empty or invalid
*  @return VIDERR_InvalidData - The <code>filter_value</code> is not valid with the <code>filter_key</code>
*  @return VIDERR_NoMemory - System is out of memory
*  @return VIDERR_NoError - Filter was successfully set
*  <p><b>Remarks:</b></p>
*  Use this function with the GNSDK Manager Lists functionality to apply filters on and improve the
relevance of specific Video Explore search results. To use this function, the application must be
licensed for Video Explore.
* <p><b>Note:</b></p>
*  The system disregards filters when performing non-text related video queries, and that filtering
by list elements is restricted to performing a Works search using the following Filter Values:
*  <ul>
*  <li>GNSDK_VIDEO_FILTER_KEY_GENRE_INCLUDE</li>
*  <li>GNSDK_VIDEO_FILTER_KEY_GENRE_EXCLUDE</li>
*  <li>GNSDK_VIDEO_FILTER_KEY_PRODUCTION_TYPE_INCLUDE</li>
*  <li>GNSDK_VIDEO_FILTER_KEY_PRODUCTION_TYPE_EXCLUDE</li>
*  <li>GNSDK_VIDEO_FILTER_KEY_SERIAL_TYPE_INCLUDE GNSDK_LIST_TYPE_VIDEOSERIALTYPES</li>
*  <li>GNSDK_VIDEO_FILTER_KEY_SERIAL_TYPE_EXCLUDE GNSDK_LIST_TYPE_VIDEOSERIALTYPES</li>
*  <li>GNSDK_VIDEO_FILTER_KEY_ORIGIN_INCLUDE GNSDK_LIST_TYPE_ORIGINS</li>
*  <li>GNSDK_VIDEO_FILTER_KEY_ORIGIN_EXCLUDE GNSDK_LIST_TYPE_ORIGINS</li>
*  </ul>
* @ingroup Video_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_video_query_set_filter_by_list_element(
	gnsdk_video_query_handle_t	video_query_handle,
	gnsdk_cstr_t				filter_key,
	gnsdk_list_element_handle_t	list_element
	);

/** @internal gnsdk_video_query_set_filter @endinternal
*  Sets a filter for a VideoID or Video Explore query handle.
*  @param video_query_handle [in] VideoID or Video Explore query handle this filter applies to
*  @param filter_key [in] One of the available filter keys
*  @param filter_value [in] String value for corresponding data key, generally one of the available
Genre or Production Type values
*  @return VIDERR_NotInited - <code>gnsdk_video_initialize</code> was not successfully initiated
*  @return VIDERR_InvalidArg - A given parameter value is empty or invalid
*  @return VIDERR_InvalidData - The <code>filter_value</code> is not valid with the <code>filter_key</code>
*  @return VIDERR_NoMemory - System is out of memory
*  @return VIDERR_NoError - Filter was successfully set
*  <p><b>Remarks:</b></p>
*  Use this function to apply certain filters on and improve the relevance of Work text search query
results.
* <p><b>Note:</b></p>
*  The system disregards filters when performing non-text related video queries, and that filtering by<br>
*  list elements is restricted to performing a Works search using the following Filter Values:
*  <ul>
*  <li>GNSDK_VIDEO_FILTER_KEY_GENRE_INCLUDE GNSDK_VIDEO_FILTER_VALUE_GENRE_*</li>
*  <li>GNSDK_VIDEO_FILTER_KEY_GENRE_EXCLUDE GNSDK_VIDEO_FILTER_VALUE_GENRE_*</li>
*  <li>GNSDK_VIDEO_FILTER_KEY_PRODUCTION_TYPE_INCLUDE GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_*</li>
*  <li>GNSDK_VIDEO_FILTER_KEY_PRODUCTION_TYPE_EXCLUDE GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_*</li>
*  <li>GNSDK_VIDEO_FILTER_KEY_SEASON_NUM text (integer as a string)</li>
*  <li>GNSDK_VIDEO_FILTER_KEY_SEASON_EPISODE_NUM text (integer as a string)</li>
*  <li>GNSDK_VIDEO_FILTER_KEY_SERIES_EPISODE_NUM text (integer as a string)</li>
*  </ul>
*
* @ingroup Video_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_video_query_set_filter(
	gnsdk_video_query_handle_t	video_query_handle,
	gnsdk_cstr_t				filter_key,
	gnsdk_cstr_t				filter_value
	);


/** @internal GNSDK_VIDEO_FILTER_KEY_SEASON_NUM @endinternal
*  Filter for Season numbers; not list-based.
* @ingroup Video_FilterKeys
*/
#define GNSDK_VIDEO_FILTER_KEY_SEASON_NUM					"gnsdk_video_key_season_num"

/** @internal GNSDK_VIDEO_FILTER_KEY_SEASON_EPISODE_NUM @endinternal
*  Filter for season episode numbers; not list-based.
* @ingroup Video_FilterKeys
*/
#define GNSDK_VIDEO_FILTER_KEY_SEASON_EPISODE_NUM			"gnsdk_video_key_season_episode_num"

/** @internal GNSDK_VIDEO_FILTER_KEY_SERIES_EPISODE_NUM @endinternal
*  Filter for series episode numbers; not list-based.
* @ingroup Video_FilterKeys
*/
#define GNSDK_VIDEO_FILTER_KEY_SERIES_EPISODE_NUM			"gnsdk_video_key_series_episode_num"

/** @internal GNSDK_VIDEO_FILTER_KEY_GENRE_INCLUDE @endinternal
*  List-based filter to include genres.
* @ingroup Video_FilterKeys
*/

#define GNSDK_VIDEO_FILTER_KEY_GENRE_INCLUDE				"gnsdk_video_key_genre_include"
/** @internal GNSDK_VIDEO_FILTER_KEY_GENRE_EXCLUDE @endinternal
*  List-based filter to exclude genres.
* @ingroup Video_FilterKeys
*/
#define GNSDK_VIDEO_FILTER_KEY_GENRE_EXCLUDE				"gnsdk_video_key_genre_exclude"

/** @internal GNSDK_VIDEO_FILTER_KEY_PRODUCTION_TYPE_INCLUDE @endinternal
*  List-based filter to include production types.
* @ingroup Video_FilterKeys
*/
#define GNSDK_VIDEO_FILTER_KEY_PRODUCTION_TYPE_INCLUDE		"gnsdk_video_key_production_type_include"

/** @internal GNSDK_VIDEO_FILTER_KEY_PRODUCTION_TYPE_EXCLUDE @endinternal
*  List-based filter to exclude production types.
* @ingroup Video_FilterKeys
*/
#define GNSDK_VIDEO_FILTER_KEY_PRODUCTION_TYPE_EXCLUDE		"gnsdk_video_key_production_type_exclude"

/** @internal GNSDK_VIDEO_FILTER_KEY_SERIAL_TYPE_INCLUDE @endinternal
*  List-based filter to include serial types.
* @ingroup Video_FilterKeys
*/
#define GNSDK_VIDEO_FILTER_KEY_SERIAL_TYPE_INCLUDE			"gnsdk_video_key_serial_type_include"

/** @internal GNSDK_VIDEO_FILTER_KEY_SERIAL_TYPE_EXCLUDE @endinternal
*  List-based filter to exclude serial types.
* @ingroup Video_FilterKeys
*/
#define GNSDK_VIDEO_FILTER_KEY_SERIAL_TYPE_EXCLUDE			"gnsdk_video_key_serial_type_exclude"

/** @internal GNSDK_VIDEO_FILTER_KEY_ORIGIN_INCLUDE @endinternal
*  List-based filter to include origin.
* @ingroup Video_FilterKeys
*/
#define GNSDK_VIDEO_FILTER_KEY_ORIGIN_INCLUDE				"gnsdk_video_key_origin_include"

/** @internal GNSDK_VIDEO_FILTER_KEY_ORIGIN_EXCLUDE @endinternal
*  List-based filter to exclude origin.
* @ingroup Video_FilterKeys
*/
#define GNSDK_VIDEO_FILTER_KEY_ORIGIN_EXCLUDE				"gnsdk_video_key_origin_exclude"


/* Production type filter values */


/** @internal GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_ANIMATION @endinternal
*  Filter on all production types classified at and under the top-level category: Animation
* @ingroup Video_FilterValues_ProductionType
*/
#define GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_ANIMATION              GNSDK_LIST_PRODUCTION_TYPE_ANIMATION

/** @internal GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_DOCUMENTARY @endinternal
*  Filter on all production types classified at and under the top-level category: Documentary
* @ingroup Video_FilterValues_ProductionType
*/
#define GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_DOCUMENTARY            GNSDK_LIST_PRODUCTION_TYPE_DOCUMENTARY

/** @internal GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_EDUCATIONAL @endinternal
*  Filter on all production types classified at and under the top-level category: Educational
* @ingroup Video_FilterValues_ProductionType
*/
#define GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_EDUCATIONAL            GNSDK_LIST_PRODUCTION_TYPE_EDUCATIONAL

/** @internal GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_GAME_SHOW @endinternal
*  Filter on all production types classified at and under the top-level category: Game Show
* @ingroup Video_FilterValues_ProductionType
*/
#define GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_GAME_SHOW              GNSDK_LIST_PRODUCTION_TYPE_GAME_SHOW

/** @internal GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_INSTRUCTIONAL @endinternal
*  Filter on all production types classified at and under the top-level category: Instructional
* @ingroup Video_FilterValues_ProductionType
*/
#define GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_INSTRUCTIONAL          GNSDK_LIST_PRODUCTION_TYPE_INSTRUCTIONAL

/** @internal GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_KARAOKE @endinternal
*  Filter on all production types classified at and under the top-level category: Karaoke
* @ingroup Video_FilterValues_ProductionType
*/
#define GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_KARAOKE	            GNSDK_LIST_PRODUCTION_TYPE_KARAOKE

/** @internal GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_LIVE_PERFORMANCE @endinternal
*  Filter on all production types classified at and under the top-level category: Live Performance
* @ingroup Video_FilterValues_ProductionType
*/
#define GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_LIVE_PERFORMANCE       GNSDK_LIST_PRODUCTION_TYPE_LIVE_PERFORMANCE

/** @internal GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_MINI_SERIES @endinternal
*  Filter on all production types classified at and under the top-level category: Mini Series
* @ingroup Video_FilterValues_ProductionType
*/
#define GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_MINI_SERIES		    GNSDK_LIST_PRODUCTION_TYPE_MINI_SERIES

/** @internal GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_MOTION_PICTURE @endinternal
*  Filter on all production types classified at and under the top-level category Motion Picture
* @ingroup Video_FilterValues_ProductionType
*/
#define GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_MOTION_PICTURE	        GNSDK_LIST_PRODUCTION_TYPE_MOTION_PICTURE

/** @internal GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_MUSIC_VIDEO @endinternal
*  Filter on all production types classified at and under the top-level category: Music Video
* @ingroup Video_FilterValues_ProductionType
*/
#define GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_MUSIC_VIDEO		    GNSDK_LIST_PRODUCTION_TYPE_MUSIC_VIDEO

/** @internal GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_SERIAL @endinternal
*  Filter on all production types classified at and under the top-level category: Serial
* @ingroup Video_FilterValues_ProductionType
*/
#define GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_SERIAL			        GNSDK_LIST_PRODUCTION_TYPE_SERIAL

/** @internal GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_SHORT_FEATURE @endinternal
*  Filter on all production types classified at and under the top-level category: Short Feature
* @ingroup Video_FilterValues_ProductionType
*/
#define GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_SHORT_FEATURE		    GNSDK_LIST_PRODUCTION_TYPE_SHORT_FEATURE

/** @internal GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_SPORTING_EVENT @endinternal
*  Filter on all production types classified at and under the top-level category: Sporting Event
* @ingroup Video_FilterValues_ProductionType
*/
#define GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_SPORTING_EVENT	        GNSDK_LIST_PRODUCTION_TYPE_SPORTING_EVENT

/** @internal GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_STAGE_PRODUCTION @endinternal
*  Filter on all production types classified at and under the top-level category: Stage Production
* @ingroup Video_FilterValues_ProductionType
*/
#define GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_STAGE_PRODUCTION	    GNSDK_LIST_PRODUCTION_TYPE_STAGE_PRODUCTION

/** @internal GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_TV_SERIES @endinternal
*  Filter on all production types classified at and under the top-level category: Television Series
* @ingroup Video_FilterValues_ProductionType
*/
#define GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_TV_SERIES			    GNSDK_LIST_PRODUCTION_TYPE_TV_SERIES

/** @internal GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_VARIETY_SHOW @endinternal
*  Filter on all production types classified at and under the top-level category: Variety Show
* @ingroup Video_FilterValues_ProductionType
*/
#define GNSDK_VIDEO_FILTER_VALUE_PRODUCTION_TYPE_VARIETY_SHOW		    GNSDK_LIST_PRODUCTION_TYPE_VARIETY_SHOW

/* Genre filter values */

/** @internal GNSDK_VIDEO_FILTER_VALUE_GENRE_ACTION_ADVENTURE @endinternal
*  Filter on all genres classified at and under the top-level category: Action Adventure
* @ingroup Video_FilterValues_Genre
*/
#define GNSDK_VIDEO_FILTER_VALUE_GENRE_ACTION_ADVENTURE	                GNSDK_LIST_VIDEO_GENRE_ACTION_ADVENTURE

/** @internal GNSDK_VIDEO_FILTER_VALUE_GENRE_ADULT @endinternal
*  Filter on all genres classified at and under the top-level category: Adult
* @ingroup Video_FilterValues_Genre
*/
#define GNSDK_VIDEO_FILTER_VALUE_GENRE_ADULT				            GNSDK_LIST_VIDEO_GENRE_ADULT

/** @internal GNSDK_VIDEO_FILTER_VALUE_GENRE_ANIMATION @endinternal
*  Filter on all genres classified at and under the top-level category: Animation
* @ingroup Video_FilterValues_Genre
*/
#define GNSDK_VIDEO_FILTER_VALUE_GENRE_ANIMATION			            GNSDK_LIST_VIDEO_GENRE_ANIMATION

/** @internal GNSDK_VIDEO_FILTER_VALUE_GENRE_CHILDREN @endinternal
*  Filter on all genres classified at and under the top-level category: Children
* @ingroup Video_FilterValues_Genre
*/
#define GNSDK_VIDEO_FILTER_VALUE_GENRE_CHILDREN			                GNSDK_LIST_VIDEO_GENRE_CHILDREN

/** @internal GNSDK_VIDEO_FILTER_VALUE_GENRE_COMEDY @endinternal
*  Filter on all genres classified at and under the top-level category: Comedy
* @ingroup Video_FilterValues_Genre
*/
#define GNSDK_VIDEO_FILTER_VALUE_GENRE_COMEDY			                GNSDK_LIST_VIDEO_GENRE_COMEDY

/** @internal GNSDK_VIDEO_FILTER_VALUE_GENRE_DOCUMENTARY @endinternal
*  Filter on all genres classified at and under the top-level category: Documentary
* @ingroup Video_FilterValues_Genre
*/
#define GNSDK_VIDEO_FILTER_VALUE_GENRE_DOCUMENTARY		                GNSDK_LIST_VIDEO_GENRE_DOCUMENTARY

/** @internal GNSDK_VIDEO_FILTER_VALUE_GENRE_DRAMA @endinternal
*  Filter on all genres classified at and under the top-level category: Drama
* @ingroup Video_FilterValues_Genre
*/
#define GNSDK_VIDEO_FILTER_VALUE_GENRE_DRAMA				            GNSDK_LIST_VIDEO_GENRE_DRAMA

/** @internal GNSDK_VIDEO_FILTER_VALUE_GENRE_HORROR @endinternal
*  Filter on all genres classified at and under the top-level category: Horror
* @ingroup Video_FilterValues_Genre
*/
#define GNSDK_VIDEO_FILTER_VALUE_GENRE_HORROR			                GNSDK_LIST_VIDEO_GENRE_HORROR

/** @internal GNSDK_VIDEO_FILTER_VALUE_GENRE_MUSICAL @endinternal
*  Filter on all genres classified at and under the top-level category: Musical
* @ingroup Video_FilterValues_Genre
*/
#define GNSDK_VIDEO_FILTER_VALUE_GENRE_MUSICAL			                GNSDK_LIST_VIDEO_GENRE_MUSICAL

/** @internal GNSDK_VIDEO_FILTER_VALUE_GENRE_MYSTERY_AND_SUSPENSE @endinternal
*  Filter on all genres classified at and under the top-level category: Mystery and Suspense
* @ingroup Video_FilterValues_Genre
*/
#define GNSDK_VIDEO_FILTER_VALUE_GENRE_MYSTERY_AND_SUSPENSE	 	        GNSDK_LIST_VIDEO_GENRE_MYSTERY_AND_SUSPENSE

/** @internal GNSDK_VIDEO_FILTER_VALUE_GENRE_ART_AND_EXPERIMENTAL @endinternal
*  Filter on all genres classified at and under the top-level category: Art and Experimental
* @ingroup Video_FilterValues_Genre
*/
#define GNSDK_VIDEO_FILTER_VALUE_GENRE_ART_AND_EXPERIMENTAL 		    GNSDK_LIST_VIDEO_GENRE_ART_AND_EXPERIMENTAL

/** @internal GNSDK_VIDEO_FILTER_VALUE_GENRE_OTHER @endinternal
*  Filter on all genres classified at and under the top-level category: Other
* @ingroup Video_FilterValues_Genre
*/
#define GNSDK_VIDEO_FILTER_VALUE_GENRE_OTHER						    GNSDK_LIST_VIDEO_GENRE_OTHER

/** @internal GNSDK_VIDEO_FILTER_VALUE_GENRE_ROMANCE @endinternal
*  Filter on all genres classified at and under the top-level category: Romance
* @ingroup Video_FilterValues_Genre
*/
#define GNSDK_VIDEO_FILTER_VALUE_GENRE_ROMANCE					        GNSDK_LIST_VIDEO_GENRE_ROMANCE

/** @internal GNSDK_VIDEO_FILTER_VALUE_GENRE_SCIFI_FANTASY @endinternal
*  Filter on all genres classified at and under the top-level category: Science Fiction and Fantasy
* @ingroup Video_FilterValues_Genre
*/
#define GNSDK_VIDEO_FILTER_VALUE_GENRE_SCIFI_FANTASY				    GNSDK_LIST_VIDEO_GENRE_SCIFI_FANTASY

/** @internal GNSDK_VIDEO_FILTER_VALUE_GENRE_SPECIAL_INTEREST_EDUCATION @endinternal
*  Filter on all genres classified at and under the top-level category: Special Interest and
Education
* @ingroup Video_FilterValues_Genre
*/
#define GNSDK_VIDEO_FILTER_VALUE_GENRE_SPECIAL_INTEREST_EDUCATION	    GNSDK_LIST_VIDEO_GENRE_SPECIAL_INTEREST_EDUCATION

/** @internal GNSDK_VIDEO_FILTER_VALUE_GENRE_MUSIC_AND_PERFORMING_ARTS @endinternal
*  Filter on all genres classified at and under the top-level category: Music and Performing Arts
* @ingroup Video_FilterValues_Genre
*/
#define GNSDK_VIDEO_FILTER_VALUE_GENRE_MUSIC_AND_PERFORMING_ARTS		GNSDK_LIST_VIDEO_GENRE_MUSIC_AND_PERFORMING_ARTS

/** @internal GNSDK_VIDEO_FILTER_VALUE_GENRE_SPORTS @endinternal
*  Filter on all genres classified at and under the top-level category: Sports
* @ingroup Video_FilterValues_Genre
*/
#define GNSDK_VIDEO_FILTER_VALUE_GENRE_SPORTS						    GNSDK_LIST_VIDEO_GENRE_SPORTS

/** @internal GNSDK_VIDEO_FILTER_VALUE_GENRE_TELEVISION_AND_INTERNET @endinternal
*  Filter on all genres classified at and under the top-level category: Television and Internet
* @ingroup Video_FilterValues_Genre
*/
#define GNSDK_VIDEO_FILTER_VALUE_GENRE_TELEVISION_AND_INTERNET		    GNSDK_LIST_VIDEO_GENRE_TELEVISION_AND_INTERNET

/** @internal GNSDK_VIDEO_FILTER_VALUE_GENRE_MILITARY_AND_WAR @endinternal
*  Filter on all genres classified at and under the top-level category: Military and War
* @ingroup Video_FilterValues_Genre
*/
#define GNSDK_VIDEO_FILTER_VALUE_GENRE_MILITARY_AND_WAR				    GNSDK_LIST_VIDEO_GENRE_MILITARY_AND_WAR

/** @internal GNSDK_VIDEO_FILTER_VALUE_GENRE_WESTERN @endinternal
*  Filter on all genres classified at and under the top-level category: Western
* @ingroup Video_FilterValues_Genre
*/
#define GNSDK_VIDEO_FILTER_VALUE_GENRE_WESTERN							GNSDK_LIST_VIDEO_GENRE_WESTERN


/** @internal gnsdk_video_query_set_text @endinternal
*  Sets text information used to search a VideoID or Video Explore query handle.
*  @param video_query_handle [in] VideoID or Video Explore query handle this text applies to
*  @param search_field [in] Search field this text applies to, from the available video search
fields
*  @param search_text [in] Actual text to search
*  @param search_type [in] Search type to perform with the given text
*  @return VIDERR_NotInited
*  @return VIDERR_InvalidArg
*  @return VIDERR_Unsupported
*  @return VIDERR_NoMemory
*  @return VIDERR_NoError
*  <p><b>Remarks:</b></p>
*  Use this function to set video text that can be directly queried; use for Contributors, Products,
Series and Works queries and suggestion searches.
*  The available search field value(s) depends on the query type.
*  Contributors, Products, and Series have one available search field:
*  <ul>
*  <li>Contributors: GNSDK_VIDEO_SEARCH_FIELD_CONTRIBUTOR_NAME</li>
*  <li>Products: GNSDK_VIDEO_SEARCH_FIELD_PRODUCT_TITLE</li>
*  <li>Series: GNSDK_VIDEO_SEARCH_FIELD_SERIES_TITLE</li>
*  </ul>
*
*  Works has these available search fields:
*  <ul>
*  <li>GNSDK_VIDEO_SEARCH_FIELD_CONTRIBUTOR_NAME
*  <li>GNSDK_VIDEO_SEARCH_FIELD_CHARACTER_NAME
*  <li>GNSDK_VIDEO_SEARCH_FIELD_SERIES_TITLE
*  <li>GNSDK_VIDEO_SEARCH_FIELD_WORK_FRANCHISE
*  <li>GNSDK_VIDEO_SEARCH_FIELD_WORK_TITLE
*  <li>GNSDK_VIDEO_SEARCH_FIELD_WORK_SERIES
*  </ul>
*
*  The GNSDK_VIDEO_SEARCH_FIELD_ALL search field searches all relevant fields for a given search
type, and returns any data found in any fields. However, it is not a valid search field when
searching for a Series.
*
*  You can specify multiple search text items for a single VideoID query handle, such as multiple
contributor names, or a work title and multiple character names. Create the necessary number of
search items, specifying in each the same VideoID query handle but differing search parameter
information.
* <p><b>Notes:</b></p>
*  Product title searches can be performed with either search type.<br>
*  Contributors, Products, Series, and Works title searches - use <code>gnsdk_video_search_type_default</code><br>
*  Suggestion searches and Product title searches - use <code>gnsdk_video_search_type_anchored</code>
*
* @ingroup Video_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_video_query_set_text(
	gnsdk_video_query_handle_t		video_query_handle,
	gnsdk_cstr_t					search_field,
	gnsdk_cstr_t					search_text,
	gnsdk_video_search_type_t		search_type
	);

/** @internal GNSDK_VIDEO_SEARCH_FIELD_CONTRIBUTOR_NAME @endinternal
*  Specifies text for a contributor name search field that is used with <code>gnsdk_video_query_set_text</code>
* @ingroup Video_SearchFields
*/
#define GNSDK_VIDEO_SEARCH_FIELD_CONTRIBUTOR_NAME		"gnsdk_video_search_field_contributor_name"

/** @internal GNSDK_VIDEO_SEARCH_FIELD_CHARACTER_NAME @endinternal
*  Specifies text for a character name search field that is used with <code>gnsdk_video_query_set_text</code>
* @ingroup Video_SearchFields
*/
#define GNSDK_VIDEO_SEARCH_FIELD_CHARACTER_NAME			"gnsdk_video_search_field_character_name"

/** @internal GNSDK_VIDEO_SEARCH_FIELD_WORK_FRANCHISE @endinternal
*  Specifies text for a work franchise search field that is used with <code>gnsdk_video_query_set_text</code>
* @ingroup Video_SearchFields
*/
#define GNSDK_VIDEO_SEARCH_FIELD_WORK_FRANCHISE			"gnsdk_video_search_field_work_franchise"

/** @internal GNSDK_VIDEO_SEARCH_FIELD_WORK_SERIES @endinternal
*  Specifies text for a work series search field that is used with <code>gnsdk_video_query_set_text</code>
* @ingroup Video_SearchFields
*/
#define GNSDK_VIDEO_SEARCH_FIELD_WORK_SERIES			"gnsdk_video_search_field_work_series"

/** @internal GNSDK_VIDEO_SEARCH_FIELD_WORK_TITLE @endinternal
*  Specifies text for a work title search field that is used with <code>gnsdk_video_query_set_text</code>
* @ingroup Video_SearchFields
*/
#define GNSDK_VIDEO_SEARCH_FIELD_WORK_TITLE				"gnsdk_video_search_field_work_title"

/** @internal GNSDK_VIDEO_SEARCH_FIELD_PRODUCT_TITLE @endinternal
*  Specifies text for a product title search field that is used with <code>gnsdk_video_query_set_text</code>
* @ingroup Video_SearchFields
*/
#define GNSDK_VIDEO_SEARCH_FIELD_PRODUCT_TITLE			"gnsdk_video_search_field_product_title"

/** @internal GNSDK_VIDEO_SEARCH_FIELD_SERIES_TITLE @endinternal
*  Specifies text for a series title search field that is used with <code>gnsdk_video_query_set_text</code>
* @ingroup Video_SearchFields
*/
#define GNSDK_VIDEO_SEARCH_FIELD_SERIES_TITLE			"gnsdk_video_search_field_series_title"

/** @internal GNSDK_VIDEO_SEARCH_FIELD_ALL @endinternal
*  Specifies text for a comprehensive search field that is used with <code>gnsdk_video_query_set_text</code>.
*  <p><b>Remarks:</b></p>
*  This video search field performs a search on all fields relevant to the search, and returns any
data found in any of these fields. However, this search field cannot be used when performing
suggestion search queries.
* @ingroup Video_SearchFields
*/
#define GNSDK_VIDEO_SEARCH_FIELD_ALL					"gnsdk_video_search_field_all"



/** @internal gnsdk_video_query_set_gdo @endinternal
*  Sets a GDO as input to a VideoID or Video Explore query handle.
*  @param video_query_handle [in] VideoID or Video Explore query handle this text applies to
*  @param query_gdo [in] GDO that identifies a video object (such as a DVD)
*  @return VIDERR_NotInited - <code>gnsdk_video_initialize</code> was not successfully initiated
*  @return VIDERR_InvalidArg - Given value for the <code>query_gdo</code> parameter is invalid
*  @return VIDERR_HandleObjectInvalid - Either the <code>video_query_handle</code> or <code>query_gdo</code> parameter is not a
valid handle
*  @return VIDERR_HandleObjectWrongType - <code>video_query_handle</code> parameter is not a valid VideoID or Video
Explore query handle, or <code>query_gdo parameter</code> is not a valid GDO handle
*  @return VIDERR_NoMemory - System is out of memory
*  @return VIDERR_NoError - GDO handle was successfully set
*  <p><b>Remarks:</b></p>
*  This function allows your application to perform a follow-up query on a GDO.
*
* Use this function
when you have a GDO from a previous GNSDK result that you want to use as input to a VideoID or Video
Explore query. The GDO may originate from a previous VideoID or Video Explore query, from a
deserialized GDO string, or from another Gracenote library.
*
* Note that the GDO's context has a bearing on the returned result.
*
*  The input GDO can be a full GDO that contains partial GDOs, such as a Work context GDO that
contains one or more partial Product GDOs. In this case, the specified <code>gnsdk_video_find_*</code> function
dictates the returned context response GDO. For example, when <code>gnsdk_video_query_set_gdo</code> is given a
Work GDO as input, a subsequent call to <code>gnsdk_video_find_products</code> returns a
GNSDK_GDO_TYPE_RESPONSE_VIDEO_PRODUCT GDO containing full Product GDOs for every partial product
that is contained within the input Work GDO, and in the specified range. If, instead, the subsequent
call is to <code>gnsdk_video_find_contributors</code>, the response is GNSDK_GDO_TYPE_RESPONSE_CONTRIBUTOR,
which contains the full Contributor GDOs for the partial contributors contained within the input
Work GDO, within the specified range.
*
* @ingroup Video_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_video_query_set_gdo(
	gnsdk_video_query_handle_t	video_query_handle,
	gnsdk_gdo_handle_t			query_gdo
	);


gnsdk_error_t GNSDK_API
gnsdk_video_query_set_locale(
	gnsdk_video_query_handle_t	video_query_handle,
	gnsdk_locale_handle_t		locale_handle
	);

/** @internal gnsdk_video_query_option_set @endinternal
*  Sets an option for a given VideoID or Video Explore query handle.
*  @param query_handle [in] VideoID or Video Explore query handle to set option for
*  @param option_key   [in] An option from the available query options 
*									defined here or in gnsdk_manager.h
*  @param option_value [in] A value that corresponds to the defined option key; may be an
alphabetical or numeric value, or one of the available video option values
*  @return VIDERR_NotInited - <code>gnsdk_video_initialize</code> was not successfully initiated
*  @return VIDERR_InvalidArg - Either the <code>option_key</code> or <code>option_value</code> parameter is empty or invalid
*  @return VIDERR_HandleObjectInvalid - Given VideoID or Video Explore <code>query_handle</code> is not a valid
handle
*  @return VIDERR_HandleObjectWrongType - Given VideoID or Video ExploreID <code>query_handle</code> is not a valid
VideoID or Video Explore query handle
*  @return GNSDKERR_LicenseDisallowed - The functionality is not allowed by the license
*  @return GNSDKERR_LicenseExpired - The license has expired for this functionality
*  @return GNSDKERR_LicenseTrialExpired - The trial period has expired for this functionality
*  @return VIDERR_NoError - Option was successfully set
* @ingroup Video_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_video_query_option_set(
	gnsdk_video_query_handle_t	query_handle,
	gnsdk_cstr_t				option_key,
	gnsdk_cstr_t				option_value
	);


/** @internal gnsdk_video_query_option_get @endinternal
*  Retrieves an option for a given VideoID or Video Explore query handle
*  @param query_handle [in] VideoID or Video Explore query handle to retrieve option from
*  @param option_key   [in] An option from the available query options 
*									defined here or in gnsdk_manager.h
*  @param p_option_value [out] Pointer to receive an option value
*  @return VIDERR_NotInited - <code>gnsdk_video_initialize</code> was not successfully initiated
*  @return VIDERR_InvalidArg - Either the <code>option_key</code> or <code>p_option_value</code> parameter is empty or invalid
*  @return VIDERR_HandleObjectInvalid - Given VideoID or Video Explore <code>query_handle</code> is not a valid
handle
*  @return VIDERR_HandleObjectWrongType - Given VideoID or Video Explore <code>query_handle</code> is not a valid
VideoID or Video Explore query handle
*  @return VIDERR_NoError - Option was successfully retrieved
* @ingroup Video_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_video_query_option_get(
	gnsdk_video_query_handle_t	query_handle,
	gnsdk_cstr_t				option_key,
	gnsdk_cstr_t*				p_option_value
	);


/**  Will be deprecated in a future release. 
* For content (like images, etc), use GNSDK_VIDEO_OPTION_ENABLE_CONTENT_DATA instead. 
* For external 3rd party IDs, use GNSDK_VIDEO_OPTION_ENABLE_EXTERNAL_IDS instead. */
#define GNSDK_VIDEO_OPTION_ENABLE_LINK_DATA				"gnsdk_video_option_enable_link"

/** @internal GNSDK_VIDEO_OPTION_ENABLE_EXTERNAL_IDS @endinternal
*  Indicates whether a response includes any external IDs (third-party IDs).
*  <p><b>Remarks:</b></p>
*  External IDs are third-party IDs associated with the results (such as an Amazon ID),
configured specifically for your application. Contact your Gracenote Professional Services
representative about enabling this option.
*
*  External IDs are supported for the following GDO types:
*  <ul>
*  <li>GNSDK_GDO_TYPE_CONTRIBUTOR</li>
*  <li>GNSDK_GDO_TYPE_VIDEOCLIP</li>
*  <li>GNSDK_GDO_TYPE_VIDEO_PRODUCT</li>
*  <li>GNSDK_GDO_TYPE_VIDEO_SEASON</li>
*  <li>GNSDK_GDO_TYPE_VIDEO_SERIES</li>
*  <li>GNSDK_GDO_TYPE_VIDEO_WORK</li>
*  </ul>
*  All the listed types support these child GDOs:
*  <ul>
*  <li>GNSDK_GDO_CHILD_EXTERNAL_ID</li>
*  </ul>
*
* @ingroup Video_Options
*/
#define GNSDK_VIDEO_OPTION_ENABLE_EXTERNAL_IDS			"gnsdk_video_option_enable_xids"

/** @internal GNSDK_VIDEO_OPTION_ENABLE_CONTENT_DATA @endinternal
*  Indicates whether a response will be used to fetch content like cover art, reviews, etc.
*  <p><b>Remarks:</b></p>
*  <p><b>Image Availability</b></p>
*  At the time of this guide's publication, only limited content is available for Video Explore
Seasons and Series image retrieval through Seasons, Series, and Works queries. Contact your
Gracenote Professional Services representative for updates on the latest supported images.
* @ingroup Video_Options
*/
#define GNSDK_VIDEO_OPTION_ENABLE_CONTENT_DATA				"gnsdk_video_option_enable_content"

/** @internal GNSDK_VIDEO_OPTION_ENABLE_MINIMAL_DATA @endinternal
*  Indicates whether a response will contain only a subset of the data.
*  <p><b>Remarks:</b></p>
*  <p><b>Image Availability</b></p>
*  At the time of this guide's publication, this is only supported for contributor queries and
* results in a reduced set of credits.
* @ingroup Video_Options
*/
#define GNSDK_VIDEO_OPTION_ENABLE_MINIMAL_DATA				"gnsdk_video_option_enable_minimal"

/** @internal GNSDK_VIDEO_OPTION_PREFERRED_LANG @endinternal
*  Specifies the preferred language of the returned results. This option applies only to TOC
Lookups.
* @ingroup Video_Options
*/
#define GNSDK_VIDEO_OPTION_PREFERRED_LANG				"gnsdk_video_preferred_lang"

/** @internal GNSDK_VIDEO_OPTION_RESULT_RANGE_START @endinternal
*  Specifies the initial value for a result range that is returned by a response. The initial value
can be an ordinal.
*  <p><b>Remarks:</b></p>
*  This option is useful for paging through results.
* <p><b>Note:</b></p>
*   Gracenote Service enforces that the range start value must be less than or equal to the total
number of results. If you specify a range start value that is greater than the total number of
results, no results are returned.
* @ingroup Video_Options
*/
#define GNSDK_VIDEO_OPTION_RESULT_RANGE_START			"gnsdk_video_result_range_start"

/** @internal GNSDK_VIDEO_OPTION_RESULT_RANGE_SIZE @endinternal
*  Specifies a maximum number of results that a response can return.
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
* @ingroup Video_Options
*/
#define GNSDK_VIDEO_OPTION_RESULT_RANGE_SIZE			"gnsdk_video_result_range_size"



/** @internal GNSDK_VIDEO_OPTION_QUERY_NOCACHE @endinternal
*  Indicates whether a response is not automatically stored in the cache.
*  <p><b>Remarks:</b></p>
*  Set this option to True to retrieve query data from a call to Gracenote Service; doing this
ensures retrieving the most recent available data.
*  Set this option to False to retrieve query data that already exists in the lookup cache. When no
data exists in the cache, VideoID
*  or Video Explore automatically calls Gracenote Service with the query request.
* @ingroup Video_Options
*/
#define GNSDK_VIDEO_OPTION_QUERY_NOCACHE				"gnsdk_video_option_query_nocache"


/** @internal GNSDK_VIDEO_OPTION_QUERY_ENABLE_COMMERCE_TYPE @endinternal
*  Specifies that a TOC lookup includes the disc's commerce type.
* @ingroup Video_Options
*/
#define GNSDK_VIDEO_OPTION_QUERY_ENABLE_COMMERCE_TYPE		"gnsdk_video_option_query_enable_commerce_type"



/** @internal gnsdk_video_query_find_products @endinternal
*  Performs a VideoID or Video Explore query for Products.
*  @param video_query_handle [in] VideoID or Video Explore query handle to perform query with
*  @param p_response_gdo [out] Pointer to receive the GDO handle with the Products' response
*  @return VIDERR_NotInited gnsdk_video_initialize was not successfully initiated
*  @return VIDERR_InvalidArg
*  @return VIDERR_InvalidData
*  @return VIDERR_Unsupported
*  @return VIDERR_HandleObjectInvalid
*  @return VIDERR_HandleObjectWrongType
*  @return VIDERR_NoMemory
*  @return VIDERR_NoError
*  <p><b>Remarks:</b></p>
*  A product is a specific version of a video presentation, either one television show episode
*  or a complete season, or a movie. Products are generally available on a DVD, Blu-ray disc, or a box set.
*  Use this API to find a video product by its TOC, external ID, or identifying text, or by a GDO.
* <p><b>Note:</b></p>
*   To query by TUI, you must first convert a TUI and its associated TUI Tag to a GDO using
<code>gnsdk_manager_gdo_create_from_id</code>.
*  The response GDO, if available, is of the GNSDK_GDO_TYPE_RESPONSE_VIDEO_PRODUCT context.
*
*  This API performs the following behavior when it successfully finds no results for the query with
no errors:
*  <ul>
*  <li>Displays a return code indicating processing success; generally, a <code>*IDERR_NoError</code> code.</li>
*  <li>Sets the match type to <code>None</code>.</li>
*  <li>Returns a GDO for the <code>None</code> match type response.</li>
*  </ul>
*
*  As the GDO returns only a <code>None</code> value, ensure that the GDO is released to conserve system
resources.
*
*  The following licensing requirements apply:
*  <ul>
*  <li>Querying by TOC requires VideoID licensing.</li>
*  <li>Querying by Text, external ID, and GDO requires VideoID or Video Explore licensing.</li>
*  </ul>
* @ingroup Video_QueryFunctions
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/
gnsdk_error_t GNSDK_API
gnsdk_video_query_find_products(
	gnsdk_video_query_handle_t	video_query_handle,
	gnsdk_gdo_handle_t*			p_response_gdo
	);


/** @internal gnsdk_video_query_find_videos @endinternal
*
*   Performs a VideoID or Video Explore query for Products.
*   Same as <code>gnsdk_video_query_find_products</code>.
*
* @ingroup Video_QueryFunctions
*/
#define gnsdk_video_query_find_videos		gnsdk_video_query_find_products


/** @internal gnsdk_video_query_find_works @endinternal
*  Performs a Video Explore query for Works.
*  @param video_query_handle [in] Video Explore query handle to perform query with
*  @param p_response_gdo [out] Pointer to receive the GDO handle with the Works' response
*  @return VIDERR_NotInited gnsdk_video_initialize was not successfully initiated
*  @return VIDERR_InvalidArg
*  @return VIDERR_InvalidData
*  @return VIDERR_Unsupported
*  @return VIDERR_HandleObjectInvalid
*  @return VIDERR_HandleObjectWrongType
*  @return VIDERR_NoMemory
*  @return VIDERR_NoError
*  <p><b>Remarks:</b></p>
*  The term 'work' has both generic and specific meanings. It can be used generically to indicate a
body of work, or, more specifically, to indicate a particular movie or television show.
*  Use this function to find a work by its external ID, identifying text, or by a GDO.
* <p><b>Notes:</b></p>
*   <ul>
*   <li>To query by TUI, you must first convert a TUI and its associated TUI Tag to a GDO using
<code>gnsdk_manager_gdo_create_from_id</code>.</li>
*  <li>The response GDO, if available, is of the GNSDK_GDO_TYPE_RESPONSE_VIDEO_WORK context.</li>
*  </ul>
*  This API performs the following behavior when it successfully finds no results for the query with
no errors:
*  <ul>
*  <li>Displays a return code indicating processing success; generally, a *IDERR_NoError code.</li>
*  <li>Sets the match type to <code>None</code>.</li>
*  <li>Returns a GDO for the <code>None</code> match type response.</li>
*  </ul>
* <p><b>Note:</b></p>
*   As the GDO returns only a <code>None</code> value, ensure that the GDO is released to conserve system
resources.
* <p><b>Note:</b></p>
*   Performing this query requires Video Explore licensing.
* @ingroup Video_QueryFunctions
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/
gnsdk_error_t GNSDK_API
gnsdk_video_query_find_works(
	gnsdk_video_query_handle_t	video_query_handle,
	gnsdk_gdo_handle_t*			p_response_gdo
	);


/** @internal gnsdk_video_query_find_programs @endinternal
*
* Performs a Video Explore query for Programs.
*
* @param video_query_handle [in] Video Explore query handle to perform query with
* @param p_response_gdo [out] Pointer to receive the GDO handle with the Programs' response
* @return VIDERR_NotInited
* @return VIDERR_Busy
* @return VIDERR_InvalidArg
* @return VIDERR_InvalidData
* @return VIDERR_InsufficientInputData
* @return VIDERR_Unsupported
* @return VIDERR_HandleObjectInvalid
* @return VIDERR_HandleObjectWrongType
* @return VIDERR_NoMemory
* @return VIDERR_NoError
* @ingroup Video_QueryFunctions
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/
gnsdk_error_t	gnsdk_video_query_find_programs(
	gnsdk_video_query_handle_t	video_query_handle,
	gnsdk_gdo_handle_t*			p_response_gdo
	);


/** @internal gnsdk_video_query_find_seasons @endinternal
*  Performs a Video Explore query for Seasons.
*  @param video_query_handle [in] Video Explore query handle to perform query with
*  @param p_response_gdo [out] Pointer to receive the GDO handle with the Seasons' response
*
*  @return VIDERR_NotInited
*  @return VIDERR_Busy
*  @return VIDERR_InvalidArg
*  @return VIDERR_InvalidData
*  @return VIDERR_InsufficientInputData
*  @return VIDERR_Unsupported
*  @return VIDERR_HandleObjectInvalid
*  @return VIDERR_HandleObjectWrongType
*  @return VIDERR_NoMemory
*  @return VIDERR_NoError
*  <p><b>Remarks:</b></p>
*  A Season is an ordered collection of Works.
*
* Examples: CSI: Las Vegas, Season One; CSI: Las Vegas, Season Two; and CSI: Las Vegas, Season Three.
*
* Use this API to find a Seasons object by an external ID or a GDO. A partial Seasons object can be contained in a full Contributor, Series, or
Work object.
*
*  Valid inputs for this query are the following:
*  <ul>
*  <li><code>gnsdk_video_query_set_gdo</code> with an allowed context, as shown in Valid Full and Partial GDO
Query Input.
*   <p><b>Note</b> To query by TUI, you must first convert a TUI and its associated TUI Tag to a GDO
using <code>gnsdk_manager_gdo_create_from_id</code>.</p></li>
*  <li><code>gnsdk_video_query_set_external_id</code> for implementation-specific (pass-through) ID types. For
more information about using this function with implementation-specific IDs, contact your Gracenote
Professional Services representative.</li>
*  </ul>
* The response GDO, if available, is of the GNSDK_GDO_TYPE_RESPONSE_VIDEO_SEASON context.
*
*  This API performs the following behavior when it successfully finds no results for the query with
no errors:
*  <ul>
*  <li>Displays a return code indicating processing success; generally, a *IDERR_NoError code.
*  <li>Sets the match type to <code>None</code>.
*  <li>Returns a GDO for the <code>None</code> match type response.
*  </ul>
*  As the GDO returns only a <code>None</code> value, ensure that the GDO is released to conserve system
resources.
*  Performing this query requires Video Explore licensing.
* @ingroup Video_QueryFunctions
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/
gnsdk_error_t GNSDK_API
gnsdk_video_query_find_seasons(
	gnsdk_video_query_handle_t	video_query_handle,
	gnsdk_gdo_handle_t*			p_response_gdo
	);


/** @internal gnsdk_video_query_find_series @endinternal
*  Performs a Video Explore query for Series.
*  @param video_query_handle [in] Video Explore query handle to perform query with
*  @param p_response_gdo [out] Pointer to receive the GDO handle with the Series' response
*
*  @return VIDERR_NotInited
*  @return VIDERR_Busy
*  @return VIDERR_InvalidArg
*  @return VIDERR_InvalidData
*  @return VIDERR_InsufficientInputData
*  @return VIDERR_Unsupported
*  @return VIDERR_HandleObjectInvalid
*  @return VIDERR_HandleObjectWrongType
*  @return VIDERR_NoMemory
*  @return VIDERR_NoError
*  <p><b>Remarks:</b></p>
*  A Series is a collection of related Works, typically in sequence, and for television programs,
often comprised of Seasons. Examples are the film series <em>The Matrix Trilogy</em> and the television
series <em>CSI: Las Vegas</em>. Use this API to find a Series object by identifying text, an external ID, or
a GDO. A partial Seasons object can be contained in a full Contributors, Series, or Works object.
*
*  Valid inputs for this query are the following:
*  <ul>
*  <li><code>gnsdk_video_query_set_text</code> with GNSDK_VIDEO_SEARCH_FIELD_SERIES_TITLE. When performing this
query type, you can perform a regular text search or indexed suggestion search. You cannot search
for a Series using <code>gnsdk_video_query_set_text</code> with GNSDK_VIDEO_SEARCH_FIELD_ALL.</li>
*  <li><code>gnsdk_video_query_set_gdo</code> with an allowed context, as shown in Valid Full and Partial GDO
Query Input.
* <p><b>Note:</b> To query by TUI, you must first convert a TUI and its associated TUI Tag to a GDO
using <code>gnsdk_manager_gdo_create_from_id</code>.</p></li>
*  <li><code>gnsdk_video_query_set_external_id</code> for implementation-specific (pass-through) ID types. For
more information about using this function with implementation-specific IDs, contact your Gracenote
Professional Services representative.</li>
*  </ul>
*  The response GDO, if available, is of the GNSDK_GDO_TYPE_RESPONSE_VIDEO_SERIES context.
*
*  This API performs the following behavior when it successfully finds no results for the query with
no errors:
*  <ul>
*  <li>Displays a return code indicating processing success; generally, a *IDERR_NoError code.</li>
*  <li>Sets the match type to <code>None</code>.</li>
*  <li>Returns a GDO for the <code>None</code> match type response.</li>
*  </ul>
*  As the GDO returns only a <code>None</code> value, ensure that the GDO is released to conserve system
resources.
*  Performing this query requires Video Explore licensing.
* @ingroup Video_QueryFunctions
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/
gnsdk_error_t GNSDK_API
gnsdk_video_query_find_series(
	gnsdk_video_query_handle_t	video_query_handle,
	gnsdk_gdo_handle_t*			p_response_gdo
	);


/** @internal gnsdk_video_query_find_contributors @endinternal
*  Performs a Video Explore query for Contributors.
*  @param video_query_handle [in] Video Explore query handle to perform query with
*  @param p_response_gdo [out] Pointer to receive the GDO handle with the Contributors' response
*  @return VIDERR_NotInited
*  @return VIDERR_InvalidArg
*  @return VIDERR_InvalidData
*  @return VIDERR_Unsupported
*  @return VIDERR_HandleObjectInvalid
*  @return  VIDERR_HandleObjectWrongType
*  @return  VIDERR_NoMemory
*  @return  VIDERR_NoError
*  <p><b>Remarks:</b></p>
*  A contributor is a person involved in the creation of a work (such as an actor or a director) or
an entity (such as a production company).
*
* Use this function to find a contributor by its external ID, identifying text, or by a GDO.
*
* <p><b>Note:</b> To query by TUI, you must first convert a TUI and its
associated TUI Tag to a GDO using <code>gnsdk_manager_gdo_create_from_id</code>.</p>
*
*  The response GDO, if available, is of the GNSDK_GDO_TYPE_RESPONSE_CONTRIBUTOR context.
*
* This API performs the following behavior when it successfully finds no results for the query with
no errors:
*  <ul>
*  <li>Displays a return code indicating processing success; generally, a *IDERR_NoError code.</li>
*  <li>Sets the match type to <code>None</code>.</li>
*  <li>Returns a GDO for the <code>None</code> match type response.</li>
*   </ul>
*
* <p><b>Note:</b></p>
*   As the GDO returns only a <code>None</code> value, ensure that the GDO is released to conserve system
resources.
* <p><b>Note:</b></p>
*   Performing this query requires Video Explore licensing.
* @ingroup Video_QueryFunctions
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/
gnsdk_error_t GNSDK_API
gnsdk_video_query_find_contributors(
	gnsdk_video_query_handle_t	video_query_handle,
	gnsdk_gdo_handle_t*			p_response_gdo
	);



/** @internal gnsdk_video_query_find_objects @endinternal
*  Performs a Video Explore query for any type of video object.
*  @param video_query_handle [in] Video Explore query handle to perform query with
*  @param p_response_gdo [out] Pointer to receive the GDO handle with the Objects' response
*
*  @return VIDERR_NotInited
*  @return VIDERR_InvalidArg
*  @return VIDERR_InvalidData
*  @return VIDERR_Unsupported
*  @return VIDERR_HandleObjectInvalid
*  @return VIDERR_HandleObjectWrongType
*  @return VIDERR_NoMemory
*  @return VIDERR_NoError
*  <p><b>Remarks:</b></p>
*  Use this function to retrieve a specific Video Explore object referenced by a GDO, or to retrieve
all the Video Explore objects (Contributors, Products, Seasons, Series, and Works) associated with a
particular external ID.
*
*  This query is useful when you are unsure of all the potential object types existing for a
particular GDO or external ID input.
*
*  Valid inputs for this query are the following:
*
*  <code>gnsdk_video_query_set_gdo</code> with any of the following GDO types:
*  <ul>
*  <li>GNSDK_GDO_TYPE_CONTRIBUTOR
*  <li>GNSDK_GDO_TYPE_VIDEO_PRODUCT
*  <li>GNSDK_GDO_TYPE_VIDEO_SEASON
*  <li>GNSDK_GDO_TYPE_VIDEO_SERIES
*  <li>GNSDK_GDO_TYPE_VIDEO_WORK
*  <li>GNSDK_GDO_TYPE_EXTENDED_DATA
*  </ul>
* <p><b>Note:</b></p>
*   To query by TUI, you must first convert a TUI and its associated TUI Tag to a GDO using
<code>gnsdk_manager_gdo_create_from_id</code>,
*  <code>gnsdk_video_query_set_external_id</code> for any external ID that Gracenote Service accepts (such as
UPC), and implementation-specific (pass-through) ID types.
*
*  For more information about using this function with implementation-specific IDs, contact your
Gracenote Professional Services representative.
*
*  The response GDO, if available, is of the GNSDK_GDO_TYPE_RESPONSE_VIDEO_OBJECT context.
*
*  This API performs the following behavior when it successfully finds no results for the query with
no errors:
*  <ul>
*  <li>Displays a return code indicating processing success; generally, a *IDERR_NoError code.</li>
*  <li>Sets the match type to <code>None</code>.</li>
*  <li>Returns a GDO for the <code>None</code> match type response.</li>
*  </ul>
*  As the GDO returns only a <code>None</code> value, ensure that the GDO is released to conserve system
resources.
*
*  Performing this query requires Video Explore licensing.
* @ingroup Video_QueryFunctions
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/
gnsdk_error_t GNSDK_API
gnsdk_video_query_find_objects(
	gnsdk_video_query_handle_t	video_query_handle,
	gnsdk_gdo_handle_t*			p_response_gdo
	);


/** @internal gnsdk_video_query_find_suggestions @endinternal
*  Performs a VideoID or Video Explore query for search suggestion text.
*  @param video_query_handle [in] VideoID or Video Explore query handle to perform query with
*  @param p_response_gdo [out] Pointer to receive the GDO handle with the video suggestions'
response
*
*  @return VIDERR_NotInited
*  @return VIDERR_InvalidArg
*  @return VIDERR_InvalidData
*  @return VIDERR_Unsupported
*  @return VIDERR_HandleObjectInvalid
*  @return VIDERR_HandleObjectWrongType
*  @return VIDERR_NoMemory
*  @return VIDERR_NoError
*  <p><b>Remarks:</b></p>
*  Use this function to suggest potential matching titles, names, and series as a user enters
*  text in a search query.
*
   Your license determines what suggestion searches your app can perform:
*  <ul>
*  <li>To query for Product titles requires VideoID or Video Explore licensing</li>
*  <li>To query for Works titles, Series titles, or Contributors names requires Video Explore licensing.</li>
*  </ul>
*  Use this function with a query handle set with a <code>GNSDK_VIDEO_SEARCH_FIELD_SERIES_TITLE</code> key to
*  use suggestion functionality in video series searches.
*
*  This function uses the anchored search type - <code>gnsdk_video_search_type_anchored</code>.
*  The response GDO, if available, is of the <code>GNSDK_GDO_TYPE_RESPONSE_SUGGESTIONS</code> context.<br>
*
*  This API performs the following behavior when it successfully finds no results for the query
*  with no errors:
*  <ul>
*  <li>Displays a return code indicating processing success; generally, a <code>*IDERR_NoError</code> code.</li>
*  </ul>
*  Suggestion searching has 2 limitations:
*  <ol>
*  <li>A suggestion search can be performed on only one search field at a time.</li>
*  <li>A suggestion search cannot be performed on a query handle defined with the
*  <code>GNSDK_VIDEO_SEARCH_FIELD_ALL</code> search field.</li>
*   </ol>
*	<p><b>Steps:</b></p>
*   <ol>
*	<li>Initialize GNSDK Manager</li>
*	<li>Get user handle</li>
*	<li>Initialize VideoID</li>
*	<li>Create video query</li>
*	<li>Set query text</li>
*	<li>Set query options</li>
*	<li>Perform "find_suggestions" query</li>
*	<li>Display results</li>
*   </ol>
*
*  <p><b>Code Sample:</b></p>
*  Note that no error handling is done here.
*  <pre>
*  ////
*  //// Set Query text to search for "spider" suggestions. Note the use of the "gnsdk_video_search_type_anchored"
*  //// search type.
*  ////
*  error = gnsdk_video_query_set_text(query_handle, GNSDK_VIDEO_SEARCH_FIELD_PRODUCT_TITLE,
*                                     "spider", gnsdk_video_search_type_anchored);
*  ////
*  //// Set the search options: range start (1) and range size (20)
*  ////
*  error = gnsdk_video_query_option_set(query_handle, GNSDK_VIDEO_OPTION_RESULT_RANGE_START, "1");
*  error = gnsdk_video_query_option_set(query_handle, GNSDK_VIDEO_OPTION_RESULT_RANGE_SIZE, "20");
*  ////
*  //// Perform the search
*  ////
*  error = gnsdk_video_query_find_suggestions(query_handle, &result_gdo);
*  </pre>
*
* For more information, see the Video Search Suggestions sample application.
*
* @ingroup Video_QueryFunctions
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/
gnsdk_error_t GNSDK_API
gnsdk_video_query_find_suggestions(
	gnsdk_video_query_handle_t	video_query_handle,
	gnsdk_gdo_handle_t*			p_response_gdo
	);


/** @internal gnsdk_video_query_release @endinternal
*  Invalidates and releases resources for a given VideoID or Video Explore query handle.
*  @param video_query_handle [in] VideoID or Video Explore query handle to release
*  @return VIDERR_NotInited - <code>gnsdk_video_initialize</code> was not successfully inititated
*  @return VIDERR_HandleObjectInvalid - Given VideoID or Video Explore query handle is not a valid
handle
*  @return VIDERR_HandleObjectWrongType - Given VideoID or Video Explore query handle is not a valid
VideoID query handle
*  @return VIDERR_NoError - VideoID or Video Explore query handle was successfully released
*  <p><b>Remarks:</b></p>
*  Use this function to release queries and GDOs. Queries and GDOs must be released; however, they
do not need to be released in the order in which they were called.
* @ingroup Video_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_video_query_release(
	gnsdk_video_query_handle_t	video_query_handle
	);



#ifdef __cplusplus
}
#endif

#endif /** @internal _GNSDK_VIDEO_H_ @endinternal
*  Primary interface for the VideoID SDK
*/


