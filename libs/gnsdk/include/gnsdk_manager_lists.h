/*
  *
  *  GRACENOTE, INC. PROPRIETARY INFORMATION
  *  This software is supplied under the terms of a license agreement or
  *  nondisclosure agreement with Gracenote, Inc. and may not be copied
  *  or disclosed except in accordance with the terms of that agreement.
  *  Copyright(c) 2000-2013. Gracenote, Inc. All Rights Reserved.
  *
 */

/* gnsdk_manager_lists.h: Lists interface for the GNSDK Manager.
*/

#ifndef _GNSDK_MANAGER_LISTS_H_
#define _GNSDK_MANAGER_LISTS_H_

#include "gnsdk_status.h"
#include "gnsdk_manager.h"
#include "gnsdk_manager_gdo.h"

#ifdef __cplusplus
extern "C"{
#endif


/******************************************************************************
 * Typedefs
 ******************************************************************************/

/** @internal gnsdk_list_handle_t @endinternal
*  Handle to a List object. List objects are used to maintain certain Gracenote data fields that are too
complex or too dynamic to be included in the GDO. Examples of List objects are the Genre List,
Language List and Region List.
*  This handle must be released by gnsdk_manager_list_release.
* @ingroup ListsandLocales_List_TypesEnums
*/
GNSDK_DECLARE_HANDLE( gnsdk_list_handle_t );

/** @internal gnsdk_list_element_handle_t @endinternal
*  Handle to a List Element object. A List Element object stores a single value that is contained in
a List object. This handle does not have to be released.
* @ingroup ListsandLocales_List_TypesEnums
*/
GNSDK_DECLARE_HANDLE( gnsdk_list_element_handle_t );


/******************************************************************************
 * SDK Manager Lists APIs
 ******************************************************************************/

/** @internal gnsdk_manager_list_retrieve @endinternal
*  Retrieves a list handle for the specified list. A list not currently in memory is loaded from the Gracenote Service
*  or local storage according to the configuration of the user lookup option.
*  See #GNSDK_USER_OPTION_LOOKUP_MODE for more information.
*
*  <b>Note</b>: This function blocks the current thread until the download is complete;
*  set a status callback function to receive progress messages.
*  @param list_type [in] Type of list to retrieve. Specify from an available List Types value.
*  @param list_language [in_opt] Language of list to retrieve. Specify from an available Locale
Languages value.
*  @param list_region [in_opt] Region for list to retrieve. Specify from an available Locale Regions
value.
*  @param list_descriptor [in_opt] Descriptor of list to retrieve. Specify from an available Locale
Descriptors value.
*  @param user_handle [in] User handle for the user making the list retrieve request
*  @param callback [in_opt] Callback function for status and progress
*  @param callback_data [in_opt] Data that is passed back through calls to the callback function
*  @param p_list_handle [out] Pointer to receive the list object handle
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for a non-optional parameter is null or empty
*  @return SDKMGRERR_HandleObjectInvalid Given user handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given user handle is not a valid type
or user handle
*  @return SDKMGRERR_NoError List was successfully retrieved
*  <p><b>Remarks:</b></p>
*  Use this function to retrieve a list handle that matches the specified parameters.
*  When a list matching the given descriptor, language, or region is not available, a list of
default values in English is substituted. You should test any retrieved list to determine its actual
content using the appropriate gnsdk_manager_list_get_* function:
*  <ul>
*  <li>Descriptor: gnsdk_manager_list_get_descriptor
*  <li>Language: gnsdk_manager_list_get_language
*  <li>Region: gnsdk_manager_list_get_region
*  </ul>
*  To save the list locally and avoid downloading it again on the next list retrieval run, use
*  gnsdk_manager_list_serialize() to serialize and store the list. On the next run, use
*  gnsdk_manager_list_deserialize() to deserialize the list into a list handle. You must periodically
*  check for updates to a deserialized list through a call to gnsdk_manager_list_update().
*  For local applications, if a storage provider is initialized, then lists are cached locally
*  and there is no need to perform the serialize function. If a GNSDK storage provider is not being used,
*  you may wish to cache lists using the serialize functionality.
*  Call gnsdk_manager_list_release() to release the list handle returned by this API.
* @ingroup ListsandLocales_List_Functions
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_retrieve(
	gnsdk_cstr_t					list_type,
	gnsdk_cstr_t					list_language,
	gnsdk_cstr_t					list_region,
	gnsdk_cstr_t					list_descriptor,
	gnsdk_user_handle_t				user_handle,
	gnsdk_status_callback_fn		callback,
	gnsdk_void_t*					callback_data,
	gnsdk_list_handle_t*			p_list_handle
	);

/** @internal gnsdk_manager_list_update @endinternal
*  Tests an existing list for updates and downloads a new list, if available. The application must
*  ensure the List module can contact the Gracenote Service to test for a new list version, by
*  appropriately configuring the user lookup option.
*  See #GNSDK_USER_OPTION_LOOKUP_MODE for more information.
*
*  Note: This function blocks the current thread until the download is complete; set a status callback function to receive progress messages.
*  @param list_handle [in] List object handle to a pre-loaded list
*  @param user_handle [in] Client handle for the user making the list retrieve request
*  @param callback [in_opt] Callback function for status and progress
*  @param callback_data [in_opt] Data that is passed back to calls to the callback function
*  @param p_updated_list_handle [out] Pointer to the updated list object, if GNSDK_NULL no new version of this was
is available and no update occurred.
*  @return SDKMGRERR_NotInited
*  @return SDKMGRERR_InvalidArg
*  @return SDKMGRERR_HandleObjectInvalid
*  @return SDKMGRERR_HandleObjectWrongType
*  @return SDKMGRERR_NoError
*  <p><b>Remarks:</b></p>
*  Use this function to periodically check Gracenote Service for updates to an existing list handle.
* <p><b>Note:</b></p>
*   You must call this update function immediately after deserializing a list through
gnsdk_manager_list_deserialize(), to check for any list updates.
*  You should configure application(s) to automatically check for list updates to ensure use of the
most current data.
* @ingroup ListsandLocales_List_Functions
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_update(
	gnsdk_list_handle_t				list_handle,
	gnsdk_user_handle_t				user_handle,
	gnsdk_status_callback_fn		callback,
	gnsdk_void_t*					callback_data,
	gnsdk_list_handle_t*			p_updated_list_handle
	);

/** @internal gnsdk_manager_list_update_check @endinternal
*  Tests an existing list to determine if a newer revision is available. If available the new revision is not downloaded. To download
*  the new revision the application must call gnsdk_manager_list_update().
*  The application must ensure the List module can contact the Gracenote Service to test for a new list version, by
*  appropriately configuring the user lookup option.
*  See #GNSDK_USER_OPTION_LOOKUP_MODE for more information.
*
*  Note: This function blocks the current thread until the check is complete; set a status callback function to receive progress messages.
*  @param list_handle [in] List object handle to a pre-loaded list
*  @param user_handle [in] Client handle for the user making the list retrieve request
*  @param callback [in_opt] Callback function for status and progress
*  @param callback_data [in_opt] Data that is passed back to calls to the callback function
*  @param p_new_revision_available [out] Pointer to boolean variable, if GNSDK_TRUE a new revision is available, if GNSDK_FALSE
*  no new version is available.
*  @return SDKMGRERR_NotInited
*  @return SDKMGRERR_InvalidArg
*  @return SDKMGRERR_HandleObjectInvalid
*  @return SDKMGRERR_HandleObjectWrongType
*  @return SDKMGRERR_NoError
*  <p><b>Remarks:</b></p>
*  Use this function to periodically check Gracenote Service for updates to an existing list handle.
* <p><b>Note:</b></p>
*  You should configure application(s) to automatically check for list updates to ensure use of the
most current data.
* @ingroup ListsandLocales_List_Functions
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_update_check(
	gnsdk_list_handle_t				list_handle,
	gnsdk_user_handle_t				user_handle,
	gnsdk_status_callback_fn		callback,
	gnsdk_void_t*					callback_data,
	gnsdk_bool_t*					p_new_revision_available
	);

/** @internal gnsdk_list_update_callback_fn @endinternal
 * Update notify calback function type
 * @param callback_data	[in] Callback data
 * @param list_handle	[in] Handle of list detected as being out of date
 */
typedef gnsdk_void_t
(GNSDK_CALLBACK_API * gnsdk_list_update_callback_fn)(
	gnsdk_void_t*					callback_data,
	gnsdk_list_handle_t				list_handle
	);

/** @internal gnsdk_manager_list_update_notify @endinternal
 * Provides a callback function that is invoked when an out of date list is detected. The application
 * can invoke a list update procedure within the callback or defer it.
 * @param callback_fn	[in] Notification callback function
 * @param callback_data [in_opt] Data that is passed back to calls to the callback function
 */
gnsdk_error_t GNSDK_API
gnsdk_manager_list_update_notify(
	gnsdk_list_update_callback_fn	callback_fn,
	gnsdk_void_t*					callback_data
	);

/** @internal gnsdk_manager_list_release @endinternal
*  Unloads and frees all resources associated with a list.
*  @param list_handle [in] Handle to list object
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_HandleObjectInvalid Given list handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given list handle is not a valid list handle
*  @return SDKMGRERR_NoError List handle was successfully released
*  <p><b>Remarks:</b></p>
*  Passing a null handle causes GNSDK Manager to return SDKMGRERR_NoError.
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_release(
	gnsdk_list_handle_t				list_handle
	);

/** @internal gnsdk_manager_list_serialize @endinternal
*  Serializes a list into encrypted text, so the application can store it for later use.
*
*  Note: If the application is using a GNSDK local storage solution, lists are automatically stored
*  and retrieved from a local store according to the configuration of user option.
*  See #GNSDK_USER_OPTION_LOOKUP_MODE for more information.
*  Applications implementing their own local storage functionality can use gnsdk_manager_list_serialize()
*  to render a list into a format that can be stored persistently and restored at a later time using
*  gnsdk_manager_list_deserialize().
*  @param list_handle [in] List handle to serialize
*  @param p_serialized_list [out] Pointer to receive serialized list handle string
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully inititated
*  @return SDKMGRERR_InvalidArg Given value for either parameter is null
*  @return SDKMGRERR_HandleObjectInvalid Given list handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given list handle is not a valid list handle
*  @return SDKMGRERR_NoError List handle was successfully serialized
*  <p><b>Remarks:</b></p>
*  Use the corresponding API gnsdk_manager_string_free() to free the serialized string when the
*  application is finished using it.
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_serialize(
	gnsdk_list_handle_t				list_handle,
	gnsdk_str_t*					p_serialized_list
	);

/** @internal gnsdk_manager_list_deserialize @endinternal
*  Reconstitutes a list handle from given serialized list data.
*  @param serialized_list [in] String of serialized list handle data
*  @param p_list_handle [out] Pointer to receive list handle
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for the serialized list string is empty or invalid, or
given value for p_list_handle is null
*  @return SDKMGRERR_NoError List handle was successfully reconstituted
*  <p><b>Remarks:</b></p>
*  Use this function to reconstitute a previously serialized list handle.
*  Immediately after deserializing a list, applications must call gnsdk_manager_list_update with the
list handle to check for any list updates. After this initial verification, establish a schedule of
periodic checks for updates.
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_deserialize(
	gnsdk_cstr_t					serialized_list,
	gnsdk_list_handle_t*			p_list_handle
	);


/** @internal gnsdk_manager_list_render_to_xml @endinternal
*  Renders list data to XML. See @link ListsandLocales_List_RenderFlags List Render Flags @endlink for the possible render flag values.
*  @param list_handle [in] Handle to a list
*  @param levels [in] List level values to render
*  @param render_flags [in] List render flags
*  @param p_xml_render [out] Pointer to render list to XML
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for p_xml_render parameter is null, or given value of
levels is 0
*  @return SDKMGRERR_HandleObjectInvalid Given list handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given list handle is not a valid list handle
*  @return SDKMGRERR_NoError List was successfully rendered to XML
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_render_to_xml(
	gnsdk_list_handle_t				list_handle,
	gnsdk_uint32_t					levels,
	gnsdk_uint32_t					render_flags,
	gnsdk_str_t*					p_xml_render
	);


/** @internal GNSDK_LIST_RENDER_XML_MINIMAL @endinternal
*  Renders minimal list data into the XML for a list.
* @ingroup ListsandLocales_List_RenderFlags
*/
#define GNSDK_LIST_RENDER_XML_MINIMAL				0x0000
/** @internal GNSDK_LIST_RENDER_XML_SUBMIT @endinternal
*  Renders minimal and Submit-specific data into the XML for a list.
* @ingroup ListsandLocales_List_RenderFlags
*/
#define GNSDK_LIST_RENDER_XML_SUBMIT				0x0001

/** @internal gnsdk_manager_list_get_type @endinternal
*  Retrieves a list type for a given list handle object.
*  When this function succeeds, the p_type parameter points to one of the List Type values.
*  @param list_handle [in] Handle to list object
*  @param p_type [out] Pointer to receive list type value
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for either parameter is null
*  @return SDKMGRERR_HandleObjectInvalid Given list handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given list handle is not a valid list handle
*  @return SDKMGRERR_NoError List type was successfully retrieved
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_get_type(
	gnsdk_list_handle_t				list_handle,
	gnsdk_cstr_t*					p_type
	);

/** @internal gnsdk_manager_list_get_language @endinternal
*  Retrieves a list language for a given list handle object. See @link Manager_DisplayLanguages Display Languages @endlink for a list of supported languages.
*  When this function succeeds, the p_lang parameter points to a Locale Languages value.
*  @param list_handle [in] Handle to list object
*  @param p_lang [out] Pointer to receive list language value
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for either parameter is null
*  @return SDKMGRERR_HandleObjectInvalid Given list handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given list handle is not a valid list handle
*  @return SDKMGRERR_NoError List language was successfully retrieved
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_get_language(
	gnsdk_list_handle_t				list_handle,
	gnsdk_cstr_t*					p_lang
	);

/** @internal gnsdk_manager_list_get_region @endinternal
*  Retrieves a list region for a given list handle object.
*  @param list_handle [in] Handle to list object
*  @param p_region [out] Pointer to receive list region value
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for either parameter is null
*  @return SDKMGRERR_HandleObjectInvalid Given list handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given list handle is not a valid list handle
*  @return SDKMGRERR_NoError List region was successfully retrieved
*  <p><b>Remarks:</b></p>
*  When this function succeeds, the p_region parameter points to one of the Locale Region values.
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_get_region(
	gnsdk_list_handle_t				list_handle,
	gnsdk_cstr_t*					p_region
	);

/** @internal gnsdk_manager_list_get_descriptor @endinternal
*  Retrieves a list descriptor for a given list handle object.
*  @param list_handle [in] Handle to a list object
*  @param p_descriptor [out] Pointer to receive list descriptor value
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for either parameter is null
*  @return SDKMGRERR_HandleObjectInvalid Given list handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given list handle is not a valid list handle
*  @return SDKMGRERR_NoError List descriptor was successfully retrieved
*  <p><b>Remarks:</b></p>
*  When this function succeeds, the p_descriptor parameter points to one of the Locale Descriptors
values.
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_get_descriptor(
	gnsdk_list_handle_t				list_handle,
	gnsdk_cstr_t*					p_descriptor
	);

/** @internal gnsdk_manager_list_get_revision @endinternal
*  Retrieves a list revision for a given list handle object.
*  @param list_handle [in] Handle to a list object
*  @param p_revision [out] Pointer to receive list revision value
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for either parameter is null
*  @return SDKMGRERR_HandleObjectInvalid Given list handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given list handle is not a valid list handle
*  @return SDKMGRERR_NoError List revision was successfully retrieved
*  <p><b>Remarks:</b></p>
*  When this function succeeds, the p_revision parameter points to the list revision value.
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_get_revision(
	gnsdk_list_handle_t   list_handle,
	gnsdk_cstr_t*         p_revision
	);

/** @internal gnsdk_manager_list_get_level_count @endinternal
*  Retrieves a maximum number of levels in a hierarchy for a given list.
*  @param list_handle [in] Handle to list object
*  @param p_count [out] Pointer to receive level count
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for either parameter is null
*  @return SDKMGRERR_HandleObjectInvalid Given list handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given list handle is not a valid list handle
*  @return SDKMGRERR_NoError List level count was successfully retrieved
*  <p><b>Remarks:</b></p>
*  When this function succeeds, the p_count parameter contains the number of levels in the given
list's hierarchy. This level count value is needed when determining which level to access when
retrieving elements or data from a list.
*  Lists can be flat or hierarchical. A flat list has only one level. A hierarchical list has a
parent-child relationship, where the parent's value is broad enough to encompass its child values
(for example, a level 1 Rock genre is a parent to level 2 Country Rock and Punk Rock genres). You
can configure an application to use a single level or the entire hierarchy.
*  Level 1 indicates the top level of the list, which usually contains the more general data. The
highest level value for a list contains the most fine-grained data.
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_get_level_count(
	gnsdk_list_handle_t				list_handle,
	gnsdk_uint32_t*					p_count
	);

/** @internal gnsdk_manager_list_get_element_count @endinternal
*  Retrieves a number of list elements at a specified level for a given list.
*  @param list_handle [in] Handle to list object
*  @param level [in] Level of list to count
*  @param p_count [out] Pointer to receive element count
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for list_handle or p_count parameter is null
*  @return SDKMGRERR_HandleObjectInvalid Given list handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given list handle is not a valid list handle
*  @return SDKMGRERR_NoError List element count was successfully retrieved
*  <p><b>Remarks:</b></p>
*  When this function succeeds, the p_count parameter contains the number of elements in the given
*  list at the given level. The range of valid index values can be obtained via gnsdk_manager_list_get_element_count.
*  @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_get_element_count(
	gnsdk_list_handle_t				list_handle,
	gnsdk_uint32_t					level,
	gnsdk_uint32_t*					p_count
	);

/** @internal gnsdk_manager_list_get_element @endinternal
*  Retrieves a list element from a list using defined level and index values.
*  @param list_handle [in] Handle to list object
*  @param level [in] Level in list of element to retrieve
*  @param index [in] Index in level of element to retrieve
*  @param p_element_handle [out] Pointer that receives the list element handle
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for list_handle or p_element_handle parameter is null
*  @return SDKMGRERR_HandleObjectInvalid Given list handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given list handle is not a valid list handle
*  @return SDKMGRERR_NoError List element was successfully retrieved
*  <p><b>Remarks:</b></p>
*  When this function succeeds, the p_element_handle parameter contains the list element.
*  The application should only need to retrieve a list element when it must get an element's parent
*  or children to traverse a hierarchy, or when it must get a string other than the main display string,
*  through gnsdk_manager_list_element_get_value().
*  Use gnsdk_manager_list_get_element_count to determine
*  the range of valid values for the index parameter.
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_get_element(
	gnsdk_list_handle_t					list_handle,
	gnsdk_uint32_t						level,
	gnsdk_uint32_t						index,
	gnsdk_list_element_handle_t* 		p_element_handle
	);

/** @internal gnsdk_manager_list_get_element_by_id @endinternal
*  Retrieves a list element from a list using a specific list element ID.
*  @param list_handle [in] Handle to list object
*  @param item_id [in] List element item ID
*  @param p_element_handle [out] Pointer that receives the list element handle
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for list_handle or p_element_handle parameter is null,
or given value for item_id is 0
*  @return SDKMGRERR_HandleObjectInvalid Given list handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given list handle is not a valid list handle
*  @return SDKMGRERR_NoError List element was successfully retrieved
*  <p><b>Remarks:</b></p>
*  This function uses the ID retrieved by the gnsdk_manager_list_element_get_id(). When this function
succeeds, the p_element_handle parameter contains the list element.
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_get_element_by_id(
	gnsdk_list_handle_t					list_handle,
	gnsdk_uint32_t						item_id,
	gnsdk_list_element_handle_t* 		p_element_handle
	);

/** @internal gnsdk_manager_list_get_element_by_range @endinternal
  * Retrieves list element whose range includes the specified value
  *
  * @param list_handle      [in]  Handle to list object
  * @param value            [in]  Value for range comparison
  * @param p_element_handle [out] Pointer that receives the list element handle
  * @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
  * @return SDKMGRERR_InvalidArg Given value for list_handle or value or p_element_handle parameter is null
  * @return SDKMGRERR_HandleObjectInvalid Given list handle is not a valid handle
  * @return SDKMGRERR_HandleObjectWrongType Given list handle is not a valid list handle
  * @return SDKMGRERR_NoError List element was successfully retrieved
  *
  * @ingroup ListsandLocales_List_Functions
  */
gnsdk_error_t GNSDK_API
gnsdk_manager_list_get_element_by_range(
	gnsdk_list_handle_t                 list_handle,
	gnsdk_uint32_t                      value,
	gnsdk_list_element_handle_t* 		p_element_handle
	);

/** @internal gnsdk_manager_list_get_element_by_string @endinternal
  * Retrieves list element whose string matches the specified value.
  *
  * @param list_handle      [in]  Handle to list object
  * @param value            [in]  Value of string to look up
  * @param p_element_handle [out] Pointer that receives the list element handle
  * @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
  * @return SDKMGRERR_InvalidArg Given value for list_handle or string or p_element_handle parameter is null
  * @return SDKMGRERR_HandleObjectInvalid Given list handle is not a valid handle
  * @return SDKMGRERR_HandleObjectWrongType Given list handle is not a valid list handle
  * @return SDKMGRERR_NoError List element was successfully retrieved
  *
  * @ingroup ListsandLocales_List_Functions
  */
gnsdk_error_t GNSDK_API
gnsdk_manager_list_get_element_by_string(
	gnsdk_list_handle_t                 list_handle,
	gnsdk_cstr_t                      	value,
	gnsdk_list_element_handle_t* 		p_element_handle
	);

/** @internal gnsdk_manager_list_get_element_by_gdo @endinternal
*  Retrieves a list element that corresponds to a given GDO.
*  @param list_handle [in] Handle to list object
*  @param gdo_handle [in] Handle to GDO
*  @param ordinal [in] Ordinal of matching list element to retrieve, if multiple values exist (1-based).
*  @param level [in] Level of list element to retrieve
*  @param p_element_handle [out] Pointer that receives the list element handle
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for list_handle or p_element_handle parameter is null
*  @return SDKMGRERR_HandleObjectInvalid Given list handle or GDO handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given list handle is not a valid list handle, or given
GDO handle is not a valid GDO handle
*  @return SDKMGRERR_NoError List element was successfully retrieved
*  <p><b>Remarks:</b></p>
*  Use this function to simplify retrieving a specific list element for the given GDO. For example,
if the list_handle parameter is for a genre list, then this function returns the specific list
element that corresponds to the genre for the given GDO.
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_get_element_by_gdo(
	gnsdk_list_handle_t					list_handle,
	gnsdk_gdo_handle_t					gdo_handle,
	gnsdk_uint32_t						ordinal,
	gnsdk_uint32_t						level,
	gnsdk_list_element_handle_t* 		p_element_handle
	);

/** @internal gnsdk_manager_list_element_release @endinternal
*  Releases a list element previously retrieved via:
*  <ul>
*  <li>gnsdk_manager_list_get_element()</li>
*  <li>gnsdk_manager_list_get_element_by_id()</li>
*  <li>gnsdk_manager_list_get_element_by_range()</li>
*  </ul>
*  @param element_handle [in] Handle to list element object
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_HandleObjectInvalid Given list element handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given list element handle is not a valid list
*  element handle
*  @return SDKMGRERR_NoError List element was successfully released
*  <p><b>Remarks:</b></p>
*  The list element may be released from memory after all retrieved instances have been
*  released. When release from memory values extracted from the list element, such as a pointer
*  to a display string, will be come invalid.
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_element_release(
	gnsdk_list_element_handle_t			element_handle
	);

/** @internal gnsdk_manager_list_element_get_display_string @endinternal
*  Retrieves a display string for a given list element.
*  @param element_handle [in] Handle to list element object
*  @param p_string [out] Pointer to receive display string
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for element_handle or p_string parameter is null
*  @return SDKMGRERR_HandleObjectInvalid Given list element handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given list element handle is not a valid list element
handle
*  @return SDKMGRERR_NoError Display string was successfully retrieved
*  <p><b>Remarks:</b></p>
*  Use this function to directly retrieve the display string from a list element.
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_element_get_display_string(
	gnsdk_list_element_handle_t		element_handle,
	gnsdk_cstr_t*					p_string
	);

/** @internal gnsdk_manager_list_element_get_id @endinternal
*  Retrieves a specified list element ID for a given list element.
*  @param element_handle [in] Handle to list element object
*  @param p_item_id [out] Pointer to receive list element ID
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for element_handle or p_item_id parameter is null
*  @return SDKMGRERR_HandleObjectInvalid Given list element handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given list element handle is not a valid list element
handle
*  @return SDKMGRERR_NoError Element ID was successfully retrieved
*  <p><b>Remarks:</b></p>
*  Use this function to retrieve the ID of a list element. This ID is used by
gnsdk_manager_list_get_element_by_id.
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_element_get_id(
	gnsdk_list_element_handle_t		element_handle,
	gnsdk_uint32_t*					p_item_id
	);

/** @internal gnsdk_manager_list_element_get_id_for_submit @endinternal
*  Retrieves a list element ID for use in submitting parcels.
*  @param element_handle [in] Handle to list element object
*  @param p_item_submit_id [out] Pointer to receive list element ID for Submit
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for element_handle or p_item_submit_id parameter is null
*  @return SDKMGRERR_NoError List element ID for submit was successfully retrieved
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_element_get_id_for_submit(
	gnsdk_list_element_handle_t		element_handle,
	gnsdk_uint32_t*					p_item_submit_id
	);

/** @internal gnsdk_manager_list_element_get_value @endinternal
*  Retrieves a non-display string value for a given list element.
*  @param element_handle [in] Handle to list element object
*  @param list_value_key [in] List key indicating which value to retrieve
*  @param p_value [out] Pointer to receive list element value
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for element_handle or p_value parameter is null,
*  or list_value_key is empty
*  @return SDKMGRERR_HandleObjectInvalid Given list element handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given list element handle is not a valid list element
handle
*  @return SDKMGRERR_NotFound Requested value does not exist in the given element
*  @return SDKMGRERR_NoError Element value was successfully retrieved
*  <p><b>Remarks:</b></p>
*  Use this function to retrieve other potential values from a list element. For example, for a
movie ratings list, retrieve a rating type value that indicates which rating system the rating is
from, such as MPAA.
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_element_get_value(
	gnsdk_list_element_handle_t		element_handle,
	gnsdk_cstr_t					list_value_key,
	gnsdk_cstr_t*					p_value
	);

/*
 * List Value Keys
 */

/** @internal GNSDK_LIST_KEY_DESC @endinternal
*  The list element's description.
* @ingroup ListsandLocales_List_Keys
*/
#define			GNSDK_LIST_KEY_DESC				"gnsdk_list_key_desc"
/** @internal GNSDK_LIST_KEY_RATINGTYPE_ID @endinternal
*  The list element's Rating Type ID (available in content ratings list).
* @ingroup ListsandLocales_List_Keys
*/
#define			GNSDK_LIST_KEY_RATINGTYPE_ID	"gnsdk_list_key_ratingtype_id"

/** @internal gnsdk_manager_list_element_get_parent @endinternal
*  Retrieves the parent element of the given list element.
*  @param element_handle [in] Handle to list element object
*  @param p_element_handle [out] Pointer to receive parent list element handle
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for element_handle or p_element_handle parameter is null
*  @return SDKMGRERR_HandleObjectInvalid Given list element handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given list element handle is not a valid list element handle
*  @return SDKMGRERR_NotFound No parent element exists for this list element
*  @return SDKMGRERR_NoError Parent element was successfully retrieved
*  <p><b>Remarks:</b></p>
*  When GNSDK Manager returns SDKMGRERR_NotFound, then the given element is the top-most parent
element.
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_element_get_parent(
	gnsdk_list_element_handle_t			element_handle,
	gnsdk_list_element_handle_t* 		p_element_handle
	);

/** @internal gnsdk_manager_list_element_get_level @endinternal
*  Retrieves the hierarchy level for a given list element.
*  @param element_handle [in] Handle to list element object
*  @param p_level [out] Pointer to receive level value
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for element_handle or p_level parameter is null
*  @return SDKMGRERR_HandleObjectInvalid Given list element handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given list element handle is not a valid list element handle
*  @return SDKMGRERR_NoError Element level was successfully retrieved
*  <p><b>Remarks:</b></p>
*  Use this function to retrieve the hierarchy level of a list element. This level value can be used
*  by the following functions:
*  <ul><li>gnsdk_manager_list_get_element()</li>
*  <li>gnsdk_manager_list_get_element_by_gdo()</li>
*  <li>gnsdk_manager_list_get_element_by_range()</li>
*  </ul>
*
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_element_get_level(
	gnsdk_list_element_handle_t		element_handle,
	gnsdk_uint32_t*					p_level
	);

/** @internal gnsdk_manager_list_element_get_child_count @endinternal
*  Retrieves a specified number of child list elements for a given list element.
*  @param element_handle [in] Handle to list element object
*  @param p_count [out] Pointer to receive child element count
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for element_handle or p_count parameter is null
*  @return SDKMGRERR_NoError Element child count was successfully retrieved
*  <p><b>Remarks:</b></p>
*  As some lists are hierarchical, some list elements have children elements. Use this function to
*  retrieve the count of children elements to determine a valid index value for calls to
*  gnsdk_manager_list_element_get_child().
*  @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_element_get_child_count(
	gnsdk_list_element_handle_t		element_handle,
	gnsdk_uint32_t*					p_count
	);

/** @internal gnsdk_manager_list_element_get_child @endinternal
*  Retrieves the specified child list element from the given list element.
*  @param element_handle [in] Handle to list element object
*  @param index [in] Index of child of list element to retrieve (0-based)
*  @param p_child_element_handle [out] Pointer to receive child list element handle
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_InvalidArg Given value for element_handle or p_child_element_handle parameter
is null
*  @return SDKMGRERR_HandleObjectInvalid Given list element handle is not a valid handle
*  @return SDKMGRERR_HandleObjectWrongType Given list element handle is not a valid list element
handle
*  @return SDKMGRERR_NoError Child list element was successfully retrieved
*  <p><b>Remarks:</b></p>
*  Use gnsdk_manager_list_element_get_child_count() to determine the range of valid values for the index parameter.
* <p><b>Note:</b></p>
*   Only those list elements existing in a hierarchical and multi-level list structure have child list elements.
* @ingroup ListsandLocales_List_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_list_element_get_child(
	gnsdk_list_element_handle_t			element_handle,
	gnsdk_uint32_t						index,
	gnsdk_list_element_handle_t* 		p_child_element_handle
	);

/*
 * List Types
 */

/** @internal GNSDK_LIST_TYPE_LANGUAGES @endinternal
*  This list contains languages that are supported by Gracenote, and are typically used to indicate
the original language of an item.
*  The language of the list is determined by the language value given to
gnsdk_manager_list_retrieve(). If any list is not available in the requested language, the
functionality defaults to using the English language list.
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_LANGUAGES			"gnsdk_list_type_languages"

/** @internal GNSDK_LIST_TYPE_SCRIPTS @endinternal
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_SCRIPTS				"gnsdk_list_type_scripts"

/** @internal GNSDK_LIST_TYPE_GENRES @endinternal
*  The list of supported music genres.
*  <p><b>Remarks:</b></p>
*  The genre list contains a hierarchy of genres available from Gracenote strictly for music data.
*  The language of the list is determined by the locale language value given to
gnsdk_manager_list_retrieve().
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_GENRES				"gnsdk_list_type_genres"
/** @internal GNSDK_LIST_TYPE_ORIGINS @endinternal
*  The list of supported geographic origins for artists.
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_ORIGINS				"gnsdk_list_type_origins"
/** @internal GNSDK_LIST_TYPE_ERAS @endinternal
*  The list of supported music era categories.
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_ERAS				"gnsdk_list_type_eras"
/** @internal GNSDK_LIST_TYPE_ARTISTTYPES @endinternal
  *
  *   The list of supported artist type categories.
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_ARTISTTYPES			"gnsdk_list_type_artist_types"
/** @internal GNSDK_LIST_TYPE_ROLES @endinternal
*  This list contains role list elements supported Gracenote for album data, such as Vocalist and
Bass Guitar.
*  The language of the list is determined by the locale language value given to
gnsdk_manager_list_retrieve().
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_ROLES				"gnsdk_list_type_roles"
/** @internal GNSDK_LIST_TYPE_GENRES_VIDEO @endinternal
*  This list contains a hierarchy of genre list elements available from Gracenote, strictly for
video data.
*  The language of the list is determined by the language value given to
gnsdk_manager_list_retrieve(). If any list is not available in the requested language, the
functionality defaults to using the English language list.
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_GENRES_VIDEO		"gnsdk_list_type_genres_video"
/** @internal GNSDK_LIST_TYPE_RATINGS @endinternal
*  This list contains movie rating list elements supported by Gracenote.
*  The language of the list is determined by the language value given to
gnsdk_manager_list_retrieve(). If any list is not available in the requested language, the
functionality defaults to using
*  the English language list.
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_RATINGS				"gnsdk_list_type_ratings"
/** @internal GNSDK_LIST_TYPE_RATINGTYPES @endinternal
*  This list contains film content rating list elements supported by Gracenote.
*  The language of the list is determined by the language value given to
gnsdk_manager_list_retrieve(). If any list is not available in the requested language, the
functionality defaults to using the English language list.
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_RATINGTYPES			"gnsdk_list_type_ratingtypes"
/** @internal GNSDK_LIST_TYPE_CONTRIBUTORS @endinternal
*  This list contains contributor role list elements available from Gracenote, such as Actor or
Costume Design. These apply to video data.
*  The language of the list is determined by the language value given to
gnsdk_manager_list_retrieve(). If any list is not available in the requested language, the
functionality defaults to using the English language list.
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_CONTRIBUTORS		"gnsdk_list_type_contributors"
/** @internal GNSDK_LIST_TYPE_FEATURETYPES @endinternal
  *   The list of supported feature types for video data.
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_FEATURETYPES		"gnsdk_list_type_featuretypes"
/** @internal GNSDK_LIST_TYPE_VIDEOREGIONS @endinternal
*  The list of supported video regions.
*  The language of the list is determined by the language value given to
gnsdk_manager_list_retrieve(). If any list is not available in the requested language, the
functionality defaults to using the English language list.
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_VIDEOREGIONS		"gnsdk_list_type_videoregions"
/** @internal GNSDK_LIST_TYPE_VIDEOTYPES @endinternal
*  The list of supported video types, such as Documentary, Sporting Event, or Motion Picture.
*  Use this list type with the GNSDK_VIDEO_FILTER_KEY_PRODUCTION_TYPE_INCLUDE,
*  GNSDK_VIDEO_FILTER_KEY_PRODUCTION_TYPE_INCLUDE, and GNSDK_VIDEO_FILTER_KEY_PRODUCTION_TYPE_EXCLUDE filter keys.
*  The language of the list is determined by the language value given to
gnsdk_manager_list_retrieve(). If any list is not available in the requested language, the
functionality defaults to using the English language list.
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_VIDEOTYPES			"gnsdk_list_type_videotypes"
/** @internal GNSDK_LIST_TYPE_MEDIATYPES @endinternal
*  The list of supported media types for music and video, such as Audio CD, Blu-ray, DVD, or HD DVD.
*  The language of the list is determined by the language value given to
gnsdk_manager_list_retrieve(). If any list is not available in the requested language, the
functionality defaults to using the English language list.
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_MEDIATYPES			"gnsdk_list_type_mediatypes"

/** @internal GNSDK_LIST_TYPE_VIDEOSERIALTYPES @endinternal
*  The list of supported video serial types, such as Series or Episode.
*  The language of the list is determined by the language value given to
gnsdk_manager_list_retrieve(). If any list is not available in the requested language, the
functionality defaults to using the English language list.
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_VIDEOSERIALTYPES	"gnsdk_list_type_videoserialtypes"
/** @internal GNSDK_LIST_TYPE_WORKTYPES @endinternal
*  The list of supported work types for video data, such as Musical or Image.
*  The language of the list is determined by the language value given to
gnsdk_manager_list_retrieve(). If any list is not available in the requested language, the
functionality defaults to using the English language list.
* @ingroup ListsandLocales_List_Types
*/

#define			GNSDK_LIST_TYPE_WORKTYPES			"gnsdk_list_type_worktypes"
/** @internal GNSDK_LIST_TYPE_MEDIASPACES @endinternal
*  The list of supported media spaces for video data, such as Music, Film, or Stage.
*  The language of the list is determined by the language value given to
gnsdk_manager_list_retrieve(). If any list is not available in the requested language, the
functionality defaults to using the English language list.
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_MEDIASPACES			"gnsdk_list_type_mediaspaces"

/** @internal GNSDK_LIST_TYPE_MOODS @endinternal
*  The list of supported moods for music data. Moods are categorized into levels, from more general
*  (Level 1, such as Blue) to more specific (Level 2, such as Gritty/Earthy/Soulful).
*  The language of the list is determined by the locale language value given to gnsdk_manager_list_retrieve().
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_MOODS				"gnsdk_list_type_moods"
/** @internal GNSDK_LIST_TYPE_TEMPOS @endinternal
*  The list of supported tempos for music data; has three levels of granularity.
*  The tempos are categorized in levels in increasing order of granularity.
*  Level 1: The meta level, such as Fast Tempo.
*  Level 2: The sub tempo level, such as Very Fast.
*  Level 3: The micro level, which may be displayed as a numeric tempo range, such as 240-249, or a
*  descriptive phrase.
*  The language of the list is determined by the locale language value given to gnsdk_manager_list_retrieve().
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_TEMPOS				"gnsdk_list_type_tempos"

/** @internal GNSDK_LIST_TYPE_COMPOSITION_FORM @endinternal
*  The list of supported composition forms for classical music.
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_COMPOSITION_FORM	"gnsdk_list_type_compform"
/** @internal GNSDK_LIST_TYPE_INSTRUMENTATION @endinternal
*  The list of supported instrumentation for classical music.
* @ingroup ListsandLocales_List_Types
*/
#define			GNSDK_LIST_TYPE_INSTRUMENTATION		"gnsdk_list_type_instrumentation"
/** @internal GNSDK_LIST_TYPE_VIDEOSTORYTYPE @endinternal
*  The list of supported overall story types for video data, such as Love Story.
*  It includes general theme classifications such as such as Love Story, Family Saga, Road Trip,
*  and Rags to Riches.
*  The language of the list is determined by the language value given to
gnsdk_manager_list_retrieve(). If any list is not available in the requested language, the
functionality defaults to using the English language list.
* @ingroup ListsandLocales_List_Types
*/
#define 		GNSDK_LIST_TYPE_VIDEOSTORYTYPE 		"gnsdk_list_type_videostorytype"
/** @internal GNSDK_LIST_TYPE_VIDEOAUDIENCE @endinternal
*  The list of supported audience types for video data.
*  It includes general audience classifications by age, ethnicity, gender, and spiritual beliefs,
*  such as Kids & Family, African-American, Female, Gay & Lesbian, and Buddhist.
*  The language of the list is determined by the language value given to
gnsdk_manager_list_retrieve(). If any list is not available in the requested language, the
functionality defaults to using the English language list.
* @ingroup ListsandLocales_List_Types
*/
#define 		GNSDK_LIST_TYPE_VIDEOAUDIENCE 		"gnsdk_list_type_videoaudience"
/** @internal GNSDK_LIST_TYPE_VIDEOMOOD @endinternal
*  The list of supported moods for video data, such as Offbeat.
*  It includes general classifications such as such as Offbeat, Uplifting, Mystical, and Sarcastic.
*  The language of the list is determined by the language value given to
gnsdk_manager_list_retrieve(). If any list is not available in the requested language, the
functionality defaults to using the English language list.
* @ingroup ListsandLocales_List_Types
*/
#define 		GNSDK_LIST_TYPE_VIDEOMOOD 			"gnsdk_list_type_videomood"
/** @internal GNSDK_LIST_TYPE_VIDEOREPUTATION @endinternal
*  The list of supported film reputation types for video data, such as Classic.
*  It includes general classifications such as such as Classic, Chick Flick, and Cult.
*  The language of the list is determined by the language value given to
gnsdk_manager_list_retrieve(). If any list is not available in the requested language, the
functionality defaults to using the English language list.
* @ingroup ListsandLocales_List_Types
*/
#define 		GNSDK_LIST_TYPE_VIDEOREPUTATION 	"gnsdk_list_type_videoreputation"
/** @internal GNSDK_LIST_TYPE_VIDEOSCENARIO @endinternal
*  The list of supported scenarios for video data. It
includes general classifications such as such as Action, Comedy, and Drama.
*  The language of the list is determined by the language value given to
gnsdk_manager_list_retrieve(). If any list is not available in the requested language, the
functionality defaults to using the English language list.
* @ingroup ListsandLocales_List_Types
*/
#define 		GNSDK_LIST_TYPE_VIDEOSCENARIO 		"gnsdk_list_type_videoscenario"
/** @internal GNSDK_LIST_TYPE_VIDEOSETTINGENV @endinternal
*  The language of the list is determined by the language value given to
gnsdk_manager_list_retrieve(). If any list is not available in the requested language, the
functionality defaults to using the English language list.
* @ingroup ListsandLocales_List_Types
*/
#define 		GNSDK_LIST_TYPE_VIDEOSETTINGENV 	"gnsdk_list_type_videosettingenv"

/** @internal GNSDK_LIST_TYPE_VIDEOSETTINGPERIOD @endinternal
*  The list of supported historical time settings for video data, such as Elizabethan Era,
1558-1603, or Jazz Age, 1919-1929.
* @ingroup ListsandLocales_List_Types
*/
#define 		GNSDK_LIST_TYPE_VIDEOSETTINGPERIOD 	"gnsdk_list_type_videosettingperiod"

/** @internal GNSDK_LIST_TYPE_VIDEOSOURCE @endinternal
*  The list of supported story concept sources for video data, such as Fairy Tales & Nursery Rhymes.
*  It includes story source classifications such as Novel, Video Game, and True Story.
*  The language of the list is determined by the language value given to
gnsdk_manager_list_retrieve(). If any list is not available in the requested language, the
functionality defaults to using the English language list.
* @ingroup ListsandLocales_List_Types
*/
#define 		GNSDK_LIST_TYPE_VIDEOSOURCE 		"gnsdk_list_type_videosource"
/** @internal GNSDK_LIST_TYPE_VIDEOSTYLE @endinternal
*  The list of supported film style types for video data, such as Film Noir.It
* includes general style classifications such as such as Art House, Film Noir, and Silent.
*  The language of the list is determined by the language value given to
gnsdk_manager_list_retrieve(). If any list is not available in the requested language, the
functionality defaults to using the English language list.
* @ingroup ListsandLocales_List_Types
*/
#define 		GNSDK_LIST_TYPE_VIDEOSTYLE 			"gnsdk_list_type_videostyle"
/** @internal GNSDK_LIST_TYPE_VIDEOTOPIC @endinternal
*  The list of supported film topics for video data, such as Racing or Teen Angst. It includes a diverse
*  range of film topics, such as Politics, Floods, Mercenaries, Surfing, and Adventure. It also includes
*  some list elements that can be considered sub-topics of a broader topic. For example, the list element Aliens (the broad topic),
*  and Nice Aliens and Bad Aliens (the more defined topics).
*  The language of the list is determined by the language value given to
gnsdk_manager_list_retrieve(). If any list is not available in the requested language, the
functionality defaults to using the English language list.
* @ingroup ListsandLocales_List_Types
*/
#define 		GNSDK_LIST_TYPE_VIDEOTOPIC 			"gnsdk_list_type_videotopic"

/** @internal GNSDK_LIST_TYPE_EPGVIEWINGTYPES @endinternal
  *
* @ingroup ListsandLocales_List_Types
*/
#define 		GNSDK_LIST_TYPE_EPGVIEWINGTYPES	 	"gnsdk_list_type_epgviewingtypes"
/** @internal GNSDK_LIST_TYPE_EPGAUDIOTYPES @endinternal
  *
* @ingroup ListsandLocales_List_Types
*/
#define 		GNSDK_LIST_TYPE_EPGAUDIOTYPES	 	"gnsdk_list_type_epgaudiotypes"
/** @internal GNSDK_LIST_TYPE_EPGVIDEOTYPES @endinternal
  *
* @ingroup ListsandLocales_List_Types
*/
#define 		GNSDK_LIST_TYPE_EPGVIDEOTYPES	 	"gnsdk_list_type_epgvideotypes"
/** @internal GNSDK_LIST_TYPE_EPGCAPTIONTYPES @endinternal
  *
* @ingroup ListsandLocales_List_Types
*/
#define 		GNSDK_LIST_TYPE_EPGCAPTIONTYPES 	"gnsdk_list_type_epgcaptiontypes"
/** @internal GNSDK_LIST_TYPE_IPGCATEGORIES_L1 @endinternal
  *
* @ingroup ListsandLocales_List_Types
*/
#define 		GNSDK_LIST_TYPE_IPGCATEGORIES_L1 	"gnsdk_list_type_ipgcat_l1"
/** @internal GNSDK_LIST_TYPE_IPGCATEGORIES_L2 @endinternal
  *
* @ingroup ListsandLocales_List_Types
*/
#define 		GNSDK_LIST_TYPE_IPGCATEGORIES_L2 	"gnsdk_list_type_ipgcat_l2"
/** @internal GNSDK_LIST_TYPE_EPGPRODUCTIONTYPES @endinternal
  *
* @ingroup ListsandLocales_List_Types
*/
#define 		GNSDK_LIST_TYPE_EPGPRODUCTIONTYPES 	"gnsdk_list_type_epgproductionyypes"
/** @internal GNSDK_LIST_TYPE_EPGDEVICETYPES @endinternal
  *
* @ingroup ListsandLocales_List_Types
*/
#define 		GNSDK_LIST_TYPE_EPGDEVICETYPES	 	"gnsdk_list_type_epgdevicetypes"



#ifdef __cplusplus
}
#endif

#endif /** @internal _GNSDK_MANAGER_LISTS_H_ @endinternal
*  Lists interface for the GNSDK Manager.
*/

