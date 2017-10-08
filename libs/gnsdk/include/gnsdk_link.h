/*
  *
  *  GRACENOTE, INC. PROPRIETARY INFORMATION
  *  This software is supplied under the terms of a license agreement or
  *  nondisclosure agreement with Gracenote, Inc. and may not be copied
  *  or disclosed except in accordance with the terms of that agreement.
  *  Copyright(c) 2000-2013. Gracenote, Inc. All Rights Reserved.
  *
 */

#ifndef _GNSDK_LINK_H_
#define _GNSDK_LINK_H_

#ifdef __cplusplus
extern "C"{
#endif

#ifndef SWIG
/******************************************************************************
 * Typedefs
 ******************************************************************************/

/** @internal gnsdk_link_query_handle_t @endinternal
*  Handle to a Link query that is created by gnsdk_link_query_create().
*  The application must create this handle to perform any Link queries it needs to execute.
* @ingroup Link_TypesEnums
*/
GNSDK_DECLARE_HANDLE( gnsdk_link_query_handle_t );

#endif
/** @internal gnsdk_link_content_type_t @endinternal
*  Indicates available content types that can be retrieved for Albums, Lyrics, Tracks, Video
*  Products, Contributors, Works, Seasons, or Series (or some combination of these object types). Not
*  all content types are available for all objects.
* @ingroup Link_TypesEnums
*/
typedef enum
{
/** @internal gnsdk_link_content_unknown @endinternal
	*
	*   Indicates an invalid content type.
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_content_unknown = 0,

/** @internal gnsdk_link_content_cover_art @endinternal
	  *
	  *   Retrieves cover artwork; this is Album-level and Video Product-level
	  *   content.
	  *
	  *   Use with #GNSDK_GDO_TYPE_ALBUM and #GNSDK_GDO_TYPE_VIDEO_PRODUCT.
	  *
	  *   Do not use with #GNSDK_GDO_TYPE_VIDEO_WORK,
	  *   #GNSDK_GDO_TYPE_VIDEO_SERIES, #GNSDK_GDO_TYPE_VIDEO_SEASON, or
	  *   #GNSDK_GDO_TYPE_CONTRIBUTOR.
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_content_cover_art,

/** @internal gnsdk_link_content_genre_art @endinternal
	  *
	  *   Retrieves artwork for the object's primary genre; this is Album-level
	  *   and Track-level content.
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_content_genre_art,

/** @internal gnsdk_link_content_review @endinternal
	  *
	  *   Retrieves a review for the object; this is Album-level content.
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_content_review,

/** @internal gnsdk_link_content_biography @endinternal
	  *
	  *   Retrieves a biography for the object; this is Album-level content.
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_content_biography,

/** @internal gnsdk_link_content_artist_news @endinternal
	  *
	  *   Retrieves news for the artist; this is Album-level content.
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_content_artist_news,

/** @internal gnsdk_link_content_lyric_xml @endinternal
	  *
	  *   Retrieves lyrics in XML form; this is Lyric-level and Track-level
	  *   data.
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_content_lyric_xml,

/** @internal gnsdk_link_content_lyric_text @endinternal
	  *
	  *   Retrieves lyrics in plain text form; this is Lyric-level and
	  *   Track-level content.
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_content_lyric_text,

/** @internal gnsdk_link_content_dsp_data @endinternal
	  *
	  *   Retrieves DSP content; this is Track-level content.
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_content_dsp_data,

/** @internal gnsdk_link_content_comments_listener @endinternal
	  *
	  *   Retrieves listener comments; this is Album-level content.
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_content_comments_listener,

/** @internal gnsdk_link_content_comments_release @endinternal
	  *
	  *   Retrieves new release comments; this is Album-level content.
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_content_comments_release,

/** @internal gnsdk_link_content_news @endinternal
	  *
	  *   Retrieves news for the object; this is Album-level content.
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_content_news,

/** @internal gnsdk_link_content_image @endinternal
	  *
	  *   Retrieves an image for specific Video types.
	  *
	  *   Use with #GNSDK_GDO_TYPE_VIDEO_WORK, #GNSDK_GDO_TYPE_VIDEO_SERIES,
	  *   #GNSDK_GDO_TYPE_VIDEO_SEASON, and video #GNSDK_GDO_TYPE_CONTRIBUTOR.
	  *
	  *   Do not use with #GNSDK_GDO_TYPE_VIDEO_PRODUCT.
	  *
	  *   Note: At the time of this guide's publication, support for Video
	  *   Explore Seasons and Series image retrieval through Seasons, Series, and
	  *   Works queries is limited. Contact your Gracenote Professional Services
	  *   representative for updates on the latest supported images.
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_content_image,

/** @internal gnsdk_link_content_image_artist @endinternal
  * Retrieves an artist image for the object; this can be album-level or contributor-level content.
  * Use with #GNSDK_GDO_TYPE_ALBUM or #GNSDK_GDO_TYPE_CONTRIBUTOR.  
  * There are three ways to retrieve an artist image:
  * <ul><li>If the GDO is the result of an album match, you can retrieve the artist image from the album GDO.</li>
  * <li>If the GDO is the result of an album match, you can retrieve a contributor GDO from the album GDO, 
  * and then retrieve the artist image from the contributor GDO.</li>
  * <li>If the GDO is the result of a contributor match, which can only come from a local text query, 
  * you can use the GDO to retrieve the artist image from the local image database. 
  * However, you cannot retrieve the artist image from the online database using this GDO.</li></ul>
  *
  * The GDO used to retrieve an artist image can be the full object or a recently deserialized object.
	  *
	  *   Note: At the time of this guide's publication, the available Album
	  *   artist images are limited. Contact your Gracenote Professional Services
	  *   representative for updates on the latest supported images.
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_content_image_artist

} gnsdk_link_content_type_t;



/** @internal gnsdk_link_data_type_t @endinternal
*  Indicates possible data formats for the retrieved content.
* @ingroup Link_TypesEnums
*/
typedef enum
{
/** @internal gnsdk_link_data_unknown @endinternal
	*
	*   Indicates an invalid data type.
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_data_unknown		= 0,

/** @internal gnsdk_link_data_text_plain @endinternal
	*
	*   Indicates the content buffer contains plain text data (null terminated).
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_data_text_plain	= 1,

/** @internal gnsdk_link_data_text_xml @endinternal
	*
	*   Indicates the content buffer contains XML data (null terminated).
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_data_text_xml	= 2,

/** @internal gnsdk_link_data_number @endinternal
	*
	*   Indicates the content buffer contains a numerical value
	*   (gnsdk_uint32_t). Unused.
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_data_number		= 10,

/** @internal gnsdk_link_data_image_jpeg @endinternal
	*
	*   Indicates the content buffer contains jpeg image data.
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_data_image_jpeg	= 20,


/** @internal gnsdk_link_data_image_png @endinternal
	*
	*   Indicates the content buffer contains png image data.
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_data_image_png	= 30,


/** @internal gnsdk_link_data_binary @endinternal
	*
	*   Indicates the content buffer contains externally defined binary data.
	* @ingroup Link_TypesEnums
*/
	gnsdk_link_data_binary		= 100

} gnsdk_link_data_type_t;

#ifndef SWIG
/** @internal gnsdk_link_initialize @endinternal
*  Initializes the Link library.
*  This function must be successfully called before any calls to other Link APIs will succeed. This
*  function can be called multiple times, however, all successful calls must be paired with a call to
*  gnsdk_link_shutdown(). If a call to gnsdk_link_initialize returns an error, then its corresponding
*  gnsdk_link_shutdown() call must not be called.
*  @param sdkmgr_handle [in] Handle from successful gnsdk_manager_initialize call
*  @return LINKERR_InvalidArg - Given sdkmgr_handle parameter is null.
*  @return LINKERR_HandleObjectInvalid - Given sdkmgr_handle is not a valid GNSDK Manager handle
*  @return LINKERR_InitFailed - Initialization failed
*  @return LINKERR_NoError - Initialization succeeded
* @ingroup Link_InitializationFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_link_initialize(
	gnsdk_manager_handle_t sdkmgr_handle
	);


/** @internal gnsdk_link_shutdown @endinternal
*  Shuts down the Link library.
*  All gnsdk_link_shutdown calls must be paired with an initial call to gnsdk_link_initialize().
*  The final gnsdk_link_shutdown call results in the library being completely shut down; all Link
*  APIs cease to function until the library is again initialized.
*  @return LINKERR_NotInited gnsdk_link_initialize() was not successfully initiated
*  @return LINKERR_NoError Shut down succeeded
* @ingroup Link_InitializationFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_link_shutdown(void);


/** @internal gnsdk_link_get_version @endinternal
*  Retrieves the Link library version string.
*  This API can be called at any time, even before initialization and after shutdown. The returned
*  string is a constant. Do not attempt to modify or delete.
*
*  Example: <code>1.2.3.123</code> (Major.Minor.Improvement.Build)<br>
*  Major: New functionality<br>
*  Minor: New or changed features<br>
*  Improvement: Improvements and fixes<br>
*  Build: Internal build number<br>
*
* @ingroup Link_InitializationFunctions
*/
gnsdk_cstr_t GNSDK_API
gnsdk_link_get_version(void);


/** @internal gnsdk_link_get_build_date @endinternal
*  Retrieves Link library build date string.
*  @return Note Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  This API can be called at any time, even before initialization and after shutdown. The returned
*  string is a constant. Do not attempt to modify or delete.
*
*  Example build date string: 2008-02-12 00:41 UTC
* @ingroup Link_InitializationFunctions
*/
gnsdk_cstr_t GNSDK_API
gnsdk_link_get_build_date(void);


/******************************************************************************
 * Link Query Handle - for the life of the query
 ******************************************************************************/


/** @internal gnsdk_link_query_create @endinternal
*  Creates a Link query handle.
*  The application can create a single gnsdk_link_query_handle_t to query
*  for multiple content items.
*  You can create and operate multiple query handles that run simultaneously, however,
*  each query handle must be used only by the original thread that created it.
*  @param user_handle [in] User handle for the user requesting the query
*  @param callback_fn [in_opt] Callback function called by Link library to report status and progress
*  @param callback_data [in_opt] Data that is provided via calls to the callback function
*  @param p_link_query_handle [out] Pointer to receive the Link query handle
*  @return LINKERR_NotInited - gnsdk_link_initialize() was not successfully initiated
*  @return LINKERR_InvalidArg - Given user_handle or p_link_query_handle is null
*  @return LINKERR_HandleObjectInvalid - Given link query handle is not a valid handle
*  @return LINKERR_NoError - Link query handle was successfully created
* @ingroup Link_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_link_query_create(
	gnsdk_user_handle_t			user_handle,
	gnsdk_status_callback_fn	callback_fn,
	gnsdk_void_t*				callback_data,
	gnsdk_link_query_handle_t*	p_link_query_handle
	);


/** @internal gnsdk_link_query_release @endinternal
*  Invalidates and releases resources for a given Link query handle.
*  @param  link_query_handle [in] Link query handle to release
*  @return LINKERR_NotInited - gnsdk_link_initialize() was not successfully initiated
*  @return LINKERR_HandleObjectInvalid - Given link query handle is not a valid handle
*  @return LINKERR_HandleObjectWrongType - Given link query handle is not a valid link query handle
*  @return LINKERR_NoError - Link query handle was successfully released
* @ingroup Link_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_link_query_release(
	gnsdk_link_query_handle_t	link_query_handle
	);

/******************************************************************************
 * Link Query Input - each Link query needs one input - GDO.
 ******************************************************************************/


/** @internal gnsdk_link_query_set_gdo @endinternal
*  Sets a result GDO as input for a Link query.
*  @param link_query_handle [in] Link query handle this GDO applies to
*  @param input_gdo [in] Handle to GDO
*
*  @return LINKERR_NotInited
*  @return LINKERR_InvalidArg
*  @return LINKERR_HandleObjectInvalid
*  @return LINKERR_HandleObjectWrongType
*  @return LINKERR_NoError Link query GDO was successfully added
*  <p><b>Remarks:</b></p>
*  Use this function when you have a GDO from a previous GNSDK result that you need to use as input
to a Link query.
* <p><b>Note:</b></p>
*   The type of the GDO has a bearing on the returned result.
* @ingroup Link_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_link_query_set_gdo(
	gnsdk_link_query_handle_t	link_query_handle,
	gnsdk_gdo_handle_t			input_gdo
	);

/** @internal gnsdk_link_query_set_list_element @endinternal
*  Sets a list element as input for a Link query.
*  @param link_query_handle [in] Link query handle the element applies to
*  @param input_list_element [in] Handle to list element
*
*  @return LINKERR_NotInited
*  @return LINKERR_InvalidArg
*  @return LINKERR_HandleObjectInvalid
*  @return LINKERR_HandleObjectWrongType
*  @return LINKERR_NoError Link query GDO was successfully added
*  <p><b>Remarks:</b></p>
*  Use this function when you have a list element that you need to use as input
to a Link query.
* <p><b>Note:</b></p>
*   The type of the list element has a bearing on the returned result.
* @ingroup Link_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_link_query_set_list_element(
	gnsdk_link_query_handle_t	link_query_handle,
	gnsdk_list_element_handle_t	input_list_element
	);

/** @internal gnsdk_link_query_option_set @endinternal
*  Sets an option for a given Link query handle.
*  @param  link_query_handle [in] Link query handle this option applies to
*  @param option_key   [in] An option from the available query options 
*									defined here or in gnsdk_manager.h
*  @param option_value [in] Value to set for given option
*  @return LINKERR_NotInited - <code>gnsdk_link_initialize</code> was not successfully initiated
*  @return LINKERR_HandleObjectInvalid - Given link query handle is not a valid handle
*  @return LINKERR_HandleObjectWrongType - Given link query handle is not a valid link query handle
*  @return LINKERR_NoError - Option successfully set
*  <p><b>Remarks:</b></p>
*  Options are set per query handle.
* @ingroup Link_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_link_query_option_set(
	gnsdk_link_query_handle_t	link_query_handle,
	gnsdk_cstr_t				option_key,
	gnsdk_cstr_t				option_value
	);


/** @internal gnsdk_link_query_option_get @endinternal
*  Retrieves an option for a given Link query handle.
*  @param  link_query_handle [in] Link query handle to retrieve option from
*  @param option_key   [in] An option from the available query options 
*									defined here or in gnsdk_manager.h
*  @param p_option_value [out] Pointer to value set for given option
*  @return LINKERR_NotInited - <code>gnsdk_link_initialize</code> was not successfully initiated
*  @return LINKERR_HandleObjectInvalid - Given link query handle is not a valid handle
*  @return LINKERR_HandleObjectWrongType - Given link query handle is not a valid link query handle
*  @return LINKERR_NoError - Option successfully retrieved
*  <p><b>Remarks:</b></p>
*  Options are set per query handle.
* @ingroup Link_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_link_query_option_get(
	gnsdk_link_query_handle_t	link_query_handle,
	gnsdk_cstr_t				option_key,
	gnsdk_cstr_t*				p_option_value
	);


/** @internal gnsdk_link_query_options_clear @endinternal
*  Clears all options currently set for a given Link query handle.
*  @param  link_query_handle [in] Link query handle to clear options for
*  @return LINKERR_NotInited - <code>gnsdk_link_initialize</code> was not successfully initiated
*  @return LINKERR_HandleObjectInvalid - Given link query handle is not a valid handle
*  @return  LINKERR_HandleObjectWrongType - Given link query handle is not a valid link query handle
*  @return LINKERR_NoError - Options successfully cleared
*  <p><b>Remarks:</b></p>
*  As Link query handles can be used to retrieve multiple enhanced data items, it may be appropriate
to specify different options between data retrievals. You can use this function to clear all options
before setting new ones.
* @ingroup Link_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_link_query_options_clear(
	gnsdk_link_query_handle_t	link_query_handle
	);

#endif
/** @internal GNSDK_LINK_OPTION_LOOKUP_MODE @endinternal
  * Indicates whether the musicid query should be performed against local embedded databases or on-line.
  * Option values must be one of GNSDK_LOOKUP_MODE_* keys.
  *
  * @ingroup Link_OptionKeys
  */
#define GNSDK_LINK_OPTION_LOOKUP_MODE				GNSDK_QUERY_OPTION_LOOKUP_MODE

/** @internal GNSDK_LINK_OPTION_KEY_IMAGE_SIZE @endinternal
*  Indicates the image size being requested; use with a GNSDK_LINK_OPTION_VALUE_IMAGE_SIZE_* value.
* @ingroup Link_OptionKeys
*/
#define GNSDK_LINK_OPTION_KEY_IMAGE_SIZE			"gnsdk_link_imagesize"

/** @internal GNSDK_LINK_OPTION_KEY_TRACK_ORD @endinternal
*  Explicitly identifies the track of interest by its ordinal number. This option takes precedence
over any provided track indicator in the GDO.
* @ingroup Link_OptionKeys
*/
#define GNSDK_LINK_OPTION_KEY_TRACK_ORD				"gnsdk_link_trackord"

/** @internal GNSDK_LINK_OPTION_KEY_DATASOURCE @endinternal
*  Indicates the source provider of the content (for example, "Acme").
* @ingroup Link_OptionKeys
*/
#define GNSDK_LINK_OPTION_KEY_DATASOURCE				"gnsdk_link_datasource"

/** @internal GNSDK_LINK_OPTION_KEY_DATATYPE @endinternal
*  Indicates the type of the provider content (for example, "cover").
* @ingroup Link_OptionKeys
*/
#define GNSDK_LINK_OPTION_KEY_DATATYPE					"gnsdk_link_datatype"

/** @internal GNSDK_LINK_OPTION_VALUE_IMAGE_SIZE_75 @endinternal
*  Retrieves a 75 x 75 image. Use with the #GNSDK_LINK_OPTION_KEY_IMAGE_SIZE option key.
*
* @ingroup Link_OptionValues
*/
#define GNSDK_LINK_OPTION_VALUE_IMAGE_SIZE_75			  "gnsdk_link_sz_75"

/** @internal GNSDK_LINK_OPTION_VALUE_IMAGE_SIZE_170 @endinternal
*  Retrieves a 170 x 170 image. Use with the #GNSDK_LINK_OPTION_KEY_IMAGE_SIZE option key.
*
* @ingroup Link_OptionValues
*/
#define GNSDK_LINK_OPTION_VALUE_IMAGE_SIZE_170				"gnsdk_link_sz_170"

/** @internal GNSDK_LINK_OPTION_VALUE_IMAGE_SIZE_300 @endinternal
*  Retrieves a 300 x 300 image. Use with the #GNSDK_LINK_OPTION_KEY_IMAGE_SIZE option key.
*
* @ingroup Link_OptionValues
*/
#define GNSDK_LINK_OPTION_VALUE_IMAGE_SIZE_300				"gnsdk_link_sz_300"

/** @internal GNSDK_LINK_OPTION_VALUE_IMAGE_SIZE_450 @endinternal
*  Retrieves a 450 x 450 image. Use with the #GNSDK_LINK_OPTION_KEY_IMAGE_SIZE option key.
*
* @ingroup Link_OptionValues
*/
#define GNSDK_LINK_OPTION_VALUE_IMAGE_SIZE_450			  	"gnsdk_link_sz_450"

/** @internal GNSDK_LINK_OPTION_VALUE_IMAGE_SIZE_720 @endinternal
*  Retrieves a 720 x 720 image. Use with the #GNSDK_LINK_OPTION_KEY_IMAGE_SIZE option key.
*
* @ingroup Link_OptionValues
*/
#define GNSDK_LINK_OPTION_VALUE_IMAGE_SIZE_720			 	"gnsdk_link_sz_720"

/** @internal GNSDK_LINK_OPTION_VALUE_IMAGE_SIZE_1080 @endinternal
*  Retrieves a 1080 x 1080 image. Use with the #GNSDK_LINK_OPTION_KEY_IMAGE_SIZE option key.
*
* @ingroup Link_OptionValues
*/
#define GNSDK_LINK_OPTION_VALUE_IMAGE_SIZE_1080			 	"gnsdk_link_sz_1080"

/** @internal GNSDK_LINK_OPTION_VALUE_IMAGE_SIZE_110 @endinternal
*  Retrieves a 110 x 110 image. Use with the #GNSDK_LINK_OPTION_KEY_IMAGE_SIZE option key.
*
*  <b>Note:</b> This image size is valid for video-related images only.
* @ingroup Link_OptionValues
*/
#define GNSDK_LINK_OPTION_VALUE_IMAGE_SIZE_110				"gnsdk_link_sz_110"

/** @internal GNSDK_LINK_OPTION_VALUE_IMAGE_SIZE_220 @endinternal
*  Retrieves a 220 x 220 image. Use with the #GNSDK_LINK_OPTION_KEY_IMAGE_SIZE option key.
*
*  <b>Note:</b> This image size is valid for video-related images only.
* @ingroup Link_OptionValues
*/
#define GNSDK_LINK_OPTION_VALUE_IMAGE_SIZE_220				"gnsdk_link_sz_220"

#ifndef SWIG
/******************************************************************************
 * Link Data Retrieval
 ******************************************************************************/


/** @internal gnsdk_link_query_content_count @endinternal
*  Retrieves count for the specified content that is described by the Link query handle options and
content type flag.
*  @param  link_query_handle [in] Link query handle to retrieve content for
*  @param content_type [in] Type of content to count
*  @param p_count [out] Pointer to receive content count
*  @return LINKERR_NotInited - <code>gnsdk_link_initialize</code> was not successfully initiated
*  @return LINKERR_HandleObjectInvalid - Given link query handle is not a valid handle
*  @return LINKERR_HandleObjectWrongType - Given link query handle is not a valid link query handle
*  @return LINKERR_NotFound - Requested content is not available
*  @return LINKERR_NoError - Content count successfully retrieved
*  <p><b>Remarks:</b></p>
*  <code>gnsdk_link_query_content_count</code> can be called repeatedly on the same link query handle with
different content type requests to
*  retrieve the count for differing values of content type.
* @ingroup Link_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_link_query_content_count(
	gnsdk_link_query_handle_t	link_query_handle,
	gnsdk_link_content_type_t	content_type,
	gnsdk_uint32_t*				p_count
	);

/** @internal gnsdk_link_query_content_retrieve @endinternal
*  Retrieves content data that is described by the Link query handle options and data type flag.
*  @param  link_query_handle [in] Link query handle to retrieve content for
*  @param content_type [in] Type of content to request. Request cover art when retrieving album or video Products
artwork. Request an image when retrieving Contributors, Works, Seasons, or Series content.
*  @param ordinal [in] Nth item of <code>content_type</code> to retrieve
*  @param p_buffer_data_type [out] Pointer to receive the content data type
*  @param p_buffer [out] Pointer to receive the buffer that contains the requested content
*  @param p_buffer_size [out] Pointer to receive the memory size pointed to by <code>p_buffer</code>
*  @return LINKERR_NotInited - <code>gnsdk_link_initialize</code> was not successfully initiated
*  @return LINKERR_HandleObjectInvalid - Given link query handle is not a valid handle
*  @return LINKERR_HandleObjectWrongType - Given link query handle is not a valid link query handle
*  @return LINKERR_InsufficientInputData - Insufficient input data
*  @return LINKWARN_NotFound - Requested content is not available
*  @return  LINKERR_NoError - Content was successfully retrieved
*  <p><b>Remarks:</b></p>
*  Use this function to retrieve multiple pieces of content for a link query handle.
*
* This API can be called repeatedly on the same link query handle with
different content type requests.
* @ingroup Link_QueryFunctions
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/
gnsdk_error_t GNSDK_API
gnsdk_link_query_content_retrieve(
	gnsdk_link_query_handle_t	link_query_handle,
	gnsdk_link_content_type_t	content_type,
	gnsdk_uint32_t				ordinal,
	gnsdk_link_data_type_t*		p_buffer_data_type,
	gnsdk_byte_t**				p_buffer,
	gnsdk_size_t*				p_buffer_size
	);



/** @internal gnsdk_link_query_content_free @endinternal
*  Releases resources used for content data from <code>gnsdk_link_query_content_retrieve</code>.
*  @param buffer [in] Content buffer returned from <code>gnsdk_link_query_content_retrieve</code>
*  @return LINKERR_NotInited - <code>gnsdk_link_initialize</code> was not successfully initiated
*  @return LINKERR_NoError - Content data was successfully released
* @ingroup Link_QueryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_link_query_content_free(
	gnsdk_byte_t*				buffer
	);

#endif
#ifdef __cplusplus
}
#endif

#endif /* _GNSDK_LINK_H_ */
