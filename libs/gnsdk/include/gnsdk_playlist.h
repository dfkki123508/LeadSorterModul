/*
  *
  *  GRACENOTE, INC. PROPRIETARY INFORMATION
  *  This software is supplied under the terms of a license agreement or
  *  nondisclosure agreement with Gracenote, Inc. and may not be copied
  *  or disclosed except in accordance with the terms of that agreement.
  *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
  * 
 */

#ifndef _GNSDK_PLAYLIST_H_
/* @internal gnsdk_playlist.h @endinternal
 * Primary interface for the Playlist SDK.
* @ingroup Playlist_HeaderFile
*/
#define _GNSDK_PLAYLIST_H_

#include "gnsdk_manager_gdo.h"
#include "gnsdk_manager_lists.h"

#ifdef __cplusplus
extern "C"{
#endif


/** @internal gnsdk_playlist_collection_handle_t @endinternal
*  Handle to a Playlist collection summary.
*  The application must release this handle using gnsdk_playlist_collection_release().
*  <p><b>Remarks:</b></p>
*  Create a collection summary handle using one of these methods:
*  Create a new handle.
*  Load an existing collection summary from storage.
*  Deserialize an existing serialized collection summary.
* @ingroup Playlist_TypesEnums
*/
GNSDK_DECLARE_HANDLE( gnsdk_playlist_collection_handle_t );

/** @internal gnsdk_playlist_results_handle_t @endinternal
*  Handle to Playlist results.
*  The application must release this handle using gnsdk_playlist_results_release().
*  <p><b>Remarks:</b></p>
*  Playlist Result handles are returned by the gnsdk_playlist_generate_playlist() and
gnsdk_playlist_generate_morelikethis() APIs.
*  Each Playlist result consist solely of the unqiue identifier which was given to Playlist during
the population of the collection summary. The application must match this identifier to the physical
media to which it references.
*  The unique identifier given by the application can be any value that helps the application
identify the media it references. For example, a desktop application could use the full pathname of
a file as the identifier. An online application might use a URL or database ID as the identifier.
Playlist does not interpret the identifer, only returns it to the application in playlist results.
* @ingroup Playlist_TypesEnums
*/
GNSDK_DECLARE_HANDLE( gnsdk_playlist_results_handle_t );


/** @internal gnsdk_playlist_status_t @endinternal
*  Indicates the Playlist callback function synchronization status values.
* @ingroup Playlist_TypesEnums
*/
typedef enum
{
/** @internal gnsdk_playlist_status_unknown @endinternal
*   Indicates a Playlist status value of unknown, the default state.
* @ingroup Playlist_TypesEnums
*/
	gnsdk_playlist_status_unknown	= 0,

/** @internal gnsdk_playlist_status_new_ident @endinternal 
*   Indicates that a new media item has been added to the user's media 
*   collection, and needs to be added to the collection summary.
* @ingroup Playlist_TypesEnums
*/
	gnsdk_playlist_status_new_ident	= 10,

/** @internal gnsdk_playlist_status_old_ident @endinternal
*   Indicates that a media item has been deleted from the user's media 
*   collection, and needs to be deleted from the collection summary.
* @ingroup Playlist_TypesEnums
*/	gnsdk_playlist_status_old_ident	= 11


} gnsdk_playlist_status_t;

/** @internal gnsdk_playlist_update_callback_fn @endinternal
*  Receive Playlist processing status updates.
*  @param callback_data [in_opt] Data that is passed back through calls to the callback function
*  @param h_collection [in] Handle to a collection
*  @param ident [in] Media identifier
*  @param status [in] One of gnsdk_playlist_status_t values
*  @param pb_abort [out] Set dereferenced value to GNSDK_TRUE to abort the operation that calls the
callback
*
* @ingroup Playlist_Callbacks
*/
typedef gnsdk_void_t		(GNSDK_CALLBACK_API *gnsdk_playlist_update_callback_fn)(
	gnsdk_void_t*						callback_data,
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_cstr_t						ident,
	gnsdk_playlist_status_t				status,
	gnsdk_bool_t*						pb_abort
	);


/** @internal gnsdk_playlist_initialize @endinternal
*  Initializes the GNSDK Playlist library.
*  @param sdkmgr_handle [in] Handle from a successful gnsdk_manager_initialize() call
*  @return PLERR_InvalidArg Given sdkmgr_handle parameter is null
*  @return PLERR_HandleObjectInvalid Given sdkmgr_handle is not a valid GNSDK Manager handle
*  @return PLERR_InitFailed Initialization failed
*  @return PLERR_NoError Initialization succeeded
*  <p><b>Remarks:</b></p>
*  This function must be successfully called before any calls to other Playlist APIs will succeed.
This function can be called multiple times, however, all successful calls must be paired with a call
to gnsdk_playlist_shutdown(). If a call to gnsdk_playlist_initialize returns an error, then its
corresponding gnsdk_playlist_shutdown call must not be called.
* @ingroup Playlist_InitializationFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_initialize(gnsdk_manager_handle_t sdkmgr_handle);

/** @internal gnsdk_playlist_shutdown @endinternal
*  Shuts down and releases resources for the Playlist library.
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_NoError Shut down succeeded
*  <p><b>Remarks:</b></p>
*  All gnsdk_playlist_shutdown calls must be paired with an initial call to
gnsdk_playlist_initialize().
*  The final gnsdk_playlist_shutdown call results in the library being completely shut down; all
Playlist APIs cease to function until the library is again initialized.
* @ingroup Playlist_InitializationFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_shutdown(void);

/** @internal gnsdk_playlist_get_version @endinternal
*  Retrieves the Playlist library's version string.
*  This API can be called at any time, even before initialization and after shutdown. The returned
string is a constant. Do not attempt to modify or delete.
*  Example: 1.2.3.123 (Major.Minor.Improvement.Build)
*  Major: New functionality
*  Minor: New or changed features
*  Improvement: Improvements and fixes
*  Build: Internal build number
* @ingroup Playlist_InitializationFunctions
*/
gnsdk_cstr_t GNSDK_API
gnsdk_playlist_get_version(void);

/** @internal gnsdk_playlist_get_build_date @endinternal
*  Retrieves the Playlist library's build date string.
*  @return Note Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  This API can be called at any time, even before initialization and after shutdown. The returned
string is a constant. Do not attempt to modify or delete.
*  Example
*  Example build date string: 2008-02-12 00:41 UTC
* @ingroup Playlist_InitializationFunctions
*/
gnsdk_cstr_t GNSDK_API
gnsdk_playlist_get_build_date(void);


/** @internal gnsdk_playlist_attributes_count @endinternal
*  Retrieves the total number of registered attributes for use in the Playlist system.
*  @param p_count [out] Pointer to receive total number of registered Playlist attributes
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg p_count is equal to NULL
*  @return PLERR_NoError System-specific registered attributes were successfully counted
*  <p><b>Remarks:</b></p>
*  Playlist comes with several supported attributes. Collection summaries may have been created with
a different set or sub set of these attributes. Only attributes supported by both the system and a
collection summary can be used by a Playlist definition.
* @ingroup Playlist_Attributes_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_attributes_count(
	gnsdk_uint32_t* p_count
	);

/** @internal gnsdk_playlist_attributes_enum @endinternal
*  Retrieves a n'th registered Playlist attribute.
*  @param index [in] Index of Playlist attribute to retrieve
*  @param p_attribute_name [out] Pointer to receive attribute name string
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg Given p_attribute_name is NULL
*  @return PLERR_NoError System-specific n'th attribute was successfully retrieved
* @ingroup Playlist_Attributes_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_attributes_enum(
	gnsdk_uint32_t	index,
	gnsdk_cstr_t*	p_attribute_name
	);

/* Playlist default supported attribute names */

/** @internal GNSDK_PLAYLIST_ATTRIBUTE_NAME_ALBUM @endinternal
* Playlist album name attribute.
* @ingroup Playlist_Attributes_Types
*/
#define GNSDK_PLAYLIST_ATTRIBUTE_NAME_ALBUM		"GN_AlbumName"
/** @internal GNSDK_PLAYLIST_ATTRIBUTE_NAME_ARTIST @endinternal
* Playlist artist name attribute.
* @ingroup Playlist_Attributes_Types
*/
#define GNSDK_PLAYLIST_ATTRIBUTE_NAME_ARTIST	"GN_ArtistName"
/** @internal GNSDK_PLAYLIST_ATTRIBUTE_NAME_TRACK @endinternal
* Playlist track name attribute.
* @ingroup Playlist_Attributes_Types
*/
#define GNSDK_PLAYLIST_ATTRIBUTE_NAME_TRACK		"GN_TrackName"
/** @internal GNSDK_PLAYLIST_ATTRIBUTE_NAME_ARTTYPE @endinternal
* Playlist artist type attribute.
* @ingroup Playlist_Attributes_Types
*/
#define GNSDK_PLAYLIST_ATTRIBUTE_NAME_ARTTYPE	"GN_ArtistType"
/** @internal GNSDK_PLAYLIST_ATTRIBUTE_NAME_ERA @endinternal
* Playlist era attribute.
* @ingroup Playlist_Attributes_Types
*/
#define GNSDK_PLAYLIST_ATTRIBUTE_NAME_ERA		"GN_Era"
/** @internal GNSDK_PLAYLIST_ATTRIBUTE_NAME_GENRE @endinternal
* Playlist genre attribute.
* @ingroup Playlist_Attributes_Types
*/
#define GNSDK_PLAYLIST_ATTRIBUTE_NAME_GENRE		"GN_Genre"
/** @internal GNSDK_PLAYLIST_ATTRIBUTE_NAME_ORIGIN @endinternal
* Playlist origin attribute.
* @ingroup Playlist_Attributes_Types
*/
#define GNSDK_PLAYLIST_ATTRIBUTE_NAME_ORIGIN	"GN_Origin"
/** @internal GNSDK_PLAYLIST_ATTRIBUTE_NAME_MOOD @endinternal
* Playlist mood attribute.
* @ingroup Playlist_Attributes_Types
*/
#define GNSDK_PLAYLIST_ATTRIBUTE_NAME_MOOD		"GN_Mood"
/** @internal GNSDK_PLAYLIST_ATTRIBUTE_NAME_TEMPO @endinternal
* Playlist tempo attribute.
* @ingroup Playlist_Attributes_Types
*/
#define GNSDK_PLAYLIST_ATTRIBUTE_NAME_TEMPO		"GN_Tempo"


/** @internal gnsdk_playlist_collection_create @endinternal
* Creates a new, empty Playlist collection summary. Takes a collection summary name as input
* and returns a pointer to a collection handle.
* <b>Note:</b> Each new collection summary that is created must have a unique name. 
* Although it is possible to create more than one collection summary with the same name, 
* if these collection summaries are then saved to local storage, one collection will override 
* the other. To avoid this, ensure that collection summary names are unique.
* @param collection_name [in] String for a collection summary name as a valid UTF-8 text string
* @param ph_collection [out] Pointer to a collection handle
* @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
* @return PLERR_InvalidArg Given collection_name is empty, or or ph_collection parameter is null
* @return PLERR_NoError Collection summary was successfully retrieved
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_create(
	gnsdk_cstr_t						collection_name,
	gnsdk_playlist_collection_handle_t*	ph_collection
	);

/** @internal gnsdk_playlist_collection_get_name @endinternal
*  Retrieves a Playlist Collection Summary name.
*  @param h_collection [in] Handle to a collection summary
*  @param p_collection_name [out] Pointer to a collection summary name
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg Given h_collection is null or invalid
*  @return PLERR_NoError Collection summary name was successfully retrieved
*  <p><b>Remarks:</b></p>
*  In cases where collection summaries have the same name, a collection name collision occurs, and
the existing collection summary name is overwritten by the new collection summary name.
*  The application must ensure that collection names are unique to prevent a collection name
collision.
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_get_name(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_cstr_t*						p_collection_name
	);

/** @internal gnsdk_playlist_collection_update_name @endinternal
*  Changes a Playlist Collection Summary name.
*  @param h_collection [in] Handle to a collection
*  @param collection_name [in] Updated collection name
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg Given h_collection is NULL, or collection_name is empty or invalid
*  @return PLERR_NoError Collection name was successfully updated
*  <p><b>Remarks:</b></p>
*  Changes the name of a collection; for example: MyCollection to MyCollection2011.
*  When storing a collection using gnsdk_playlist_storage_store_collection(), the function stores the
collection with the new name, replacing the existing stored collection that uses the previous name.
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_update_name(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_cstr_t						collection_name
	);

/** @internal gnsdk_playlist_collection_release @endinternal
*  Invalidates and releases resources for a given Playlist Collection Summary.
*  @param h_collection [in] Handle to a collection
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_NoError Collection was successfully released, or collection was null or invalid
*  <p><b>Remarks:</b></p>
*  If the collection summary is not serialized or otherwise stored, the collection summary data will
be lost upon release.
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_release(
	gnsdk_playlist_collection_handle_t	h_collection
	);


/** @internal gnsdk_playlist_collection_add_ident @endinternal
*  Adds an identifier to a Collection Summary. This creates an empty entry in the Collection Summary
*  for this given identifier.
*  When adding media to a collection summary, an application provides an identifier that allows the 
*  application to identify the physical media being referenced. The identifier is not interpreted by 
* Playlist; it is only returned to the application in Playlist results.
*  An identifier is generally application-dependent. For example, a desktop application typically
* uses a full path to a file name for an identifier, while an online application typically uses a
* database key.
* Use this function to pre-populate a collection with all media identifiers, then perform matching later. 
* Once matching is done, the resultant GDOs can be added to the collection
* Additionally, for media not matched by Gracenote, an application can still track the existence of
* this media by putting the ident alone in the collection.
* Applications can add metadata to the same ident using the other gnsdk_playlist_collection_add_* APIs.
*  @param h_collection [in] Handle to a collection summary
*  @param ident [in] Valid UTF-8 string of media identifier data provided by the application; must
be unique within the collection summary
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg Given ident string is empty or invalid
*  @return PLERR_NoError Identifier was successfully added
*  <p><b>Important:</b></p>
*  Idents are essential to the Playlist generation process. The functionality cannot reference a
media item if its ident is missing or invalid.
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_add_ident(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_cstr_t						ident
	);

/** @internal gnsdk_playlist_collection_add_gdo @endinternal
*  Adds an identifier plus related metadata to a Collection Summary.
*  When adding media to a collection summary, an application provides an identifier and a GDO which
 contains the metadata for the identifier. The identifier is a value that allows the application to
 identify the physical media being referenced. The identifier is not interpreted by Playlist; it is
 only returned to the application in Playlist results.
*  An identifier is generally application-dependent. For example, a desktop application typically
 uses a full path to a file name for an identifier, while an online application typically uses a
 database key.
*  The media GDO should contain relevant metadata for the media referenced by the identifier. In
 most cases the
*  GDO comes from a recognition event for the respective media (such as from MusicID). Playlist will
 take whatever metadata is relevant for playlist generation from the given GDO.
*  For best results, we recommend giving Album Type GDOs to this function; Track Type GDOs
 also work well. Other GDOs are supported, but most other types lack information for decent
 Playlist generation.
*  @param h_collection [in] Handle to a collection summary
*  @param ident [in] Valid UTF-8 string of media identifier data provided by the application; must
be unique within the collection summary
*  @param media_gdo [in] Handle to a media GDO, such as an Album or Track GDO
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg Given ident string is empty or invalid
*  @return PLERR_NoError Identifier was successfully added
*  <p><b>Important:</b></p>
*  Idents are essential to the Playlist generation process. The functionality cannot reference a
media item if its ident is missing or invalid.
*  You must ensure the following in your implementation for proper performance:
*  The application integrates with GNSDK's MusicID or MusicID -File (or both) to recognize music
media and create GDOs with valid idents.
*  The application uses valid idents. An ident must be a valid UTF-8 string of unique media
identifier data.
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_add_gdo(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_cstr_t						ident,
	gnsdk_gdo_handle_t					media_gdo
	);

/* deprecated API name for above */
#define gnsdk_playlist_collection_ident_add gnsdk_playlist_collection_add_gdo


/** @internal gnsdk_playlist_collection_add_gdo @endinternal
*  Adds an identifier plus related list element data to a Collection Summary.
* @ingroup Playlist_CollectionSummaryFunctions
*  @param h_collection [in] Handle to a collection summary
*  @param ident [in] Valid UTF-8 string of media identifier data provided by the application; must
be unique within the collection summary
*  @param list_element [in] Handle to a list element,e.g. from the Genre, Origin, Era, Mood, ArtistType lists.
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg Given ident, h_collection or list_element are empty or invalid
*  @return PLERR_NoError Identifier was successfully added
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_add_list_element(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_cstr_t						ident,
	gnsdk_list_element_handle_t			list_element
	);


/** @internal gnsdk_playlist_collection_get_gdo @endinternal
*  Retrieves attribute data for the specified identifier.
*  Use this function to inspect the data attributes associated with a media identifier, such as
Genre, Mood, and Tempo.
*  @param h_collection [in] Handle to a Playlist collection summary
*  @param user_handle [in] Handle for the user requesting the GDO
*  @param ident [in] String of identifier data
*  @param ph_gdo_ident [out] Pointer to receive a GDO identifier handle
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg Given ident or attribute_name is empty, or given p_attribute_value is null
*  @return PLERR_NoError Attribute data successfully retrieved
*  <p><b>Remarks:</b></p>
*  The GDO returned will be of type GNSDK_GDO_TYPE_PLAYLIST_DATA.
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_get_gdo(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_user_handle_t					user_handle,
	gnsdk_cstr_t						ident,
	gnsdk_gdo_handle_t*					ph_gdo_ident
	);

/* deprecated API name */
#define gnsdk_playlist_collection_ident_get_gdo		gnsdk_playlist_collection_get_gdo

/** @internal gnsdk_playlist_collection_join @endinternal
*  Joins the collection represented by the second parameter into the collection
*  represented by the first parameter. After the join, the first collection will
*  contain a reference to the second collection. The collection handle for the first
*  collection can be used to represent the joined collection.
*  @param h_destination [in] Handle to a collection that is being joined into
*  @param h_join		[in] Handle to a collection that is being joined
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg h_collection has the same name as h_joined or has been joined already
*  @return PLERR_NoError collections were successfully joined.
*
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_join(
	gnsdk_playlist_collection_handle_t	h_destination,
	gnsdk_playlist_collection_handle_t	h_join
	);


/** @internal gnsdk_playlist_collection_join_count @endinternal
*  Gets a count of the number of collections joined into h_collection.
*  @param h_collection [in] Handle to a collection.
*  @param p_count		[out]  Pointer to receive the total number of joined collections.
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg h_collection has the same name as h_destination or has been merged already
*  @return PLERR_NoError collections were successfully merged.
*
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_join_count(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_uint32_t*                     p_count
	);


/** @internal gnsdk_playlist_collection_join_enum @endinternal
*  Gets the joined collection based on a 0 index.
*  @param h_collection          [in] Handle to a collection that has joined collections .
*  @param index                 [in] index position.
*  @param ph_joined_collection  [out]  Pointer to a collection to receive the joined collections
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg h_collection is invalid or the index is out of range
*  @return PLERR_NoError the joined collection was successfully assigned to  p_joined_collection
*
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_join_enum(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_uint32_t						index,
	gnsdk_playlist_collection_handle_t*	ph_joined_collection
	);


/** @internal gnsdk_playlist_collection_join_get @endinternal
*  Retrieves an individual collection from a join, using the name of the collection.
*  @param h_collection          [in] Handle to a collection that has joined collections
*  @param collection_name       [in] String that has a collection name, most likely from a result set
*  @param ph_joined_collection  [out]  Pointer to a collection to receive the individual collection
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg h_collection is invalid or the collection name is empty or a null pointer
*  @return PLERR_NotFound   no collection was found by that name.
*  @return PLERR_NoError  the joined collection was successfully assigned to  p_joined_collection
*
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_join_get(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_cstr_t						collection_name,
	gnsdk_playlist_collection_handle_t*	ph_joined_collection
	);

/* deprecated API name for above */
#define gnsdk_playlist_collection_join_get_by_name		gnsdk_playlist_collection_join_get


/** @internal gnsdk_playlist_collection_join_remove @endinternal
*  Remove an individual collection from a join, using the name of the collection.
*  @param h_collection          [in] Handle to a collection that has joined collections
*  @param collection_name       [in] String that has a collection name.
 * @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg h_collection is invalid or the collection name is empty or a null pointer
*  @return PLERR_NotFound   no collection was found by that name.
*  @return PLERR_NoError  the collection represented by the collection_name was successfully removed
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_join_remove(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_cstr_t						collection_name
	);

/** @internal gnsdk_playlist_collection_ident_find @endinternal
*  Retrieves an index value for the first instance matching the input after the start_index value.
*  An identifier must be unique and not duplicated in a single collection summary. It may however exist multiple 
*  times in a collection with other collections joined to it (unique in each collection summary). 
*  Use this function to determine if or where an identifier  exists in the collection summary or any of its 
*  Joined collection summaries. 
*  @param h_collection [in] Handle to a collection summary
*  @param media_ident [in] String of identifier data
*  @param start_index [in] Index to start the find from . 
*  @param p_found_index [out] Pointer to receive integer value indicating the position of the ident .
*  @param p_collection_name [out] Pointer to receive string value indicating the name of the collection/joined collection it belongs to .
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg Given ident is empty, or given p_found_index is NULL
*  @return PLERR_NoError Ident was successfully found .
*  @return PLERR_NotFound if the ident wasnt not found.  
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t  GNSDK_API
gnsdk_playlist_collection_ident_find(
	gnsdk_playlist_collection_handle_t	h_collection, 
	gnsdk_cstr_t						media_ident, 
	gnsdk_uint32_t						start_index, 
	gnsdk_uint32_t*						p_found_index, 
	gnsdk_cstr_t*						p_collection_name
	);


/** @internal gnsdk_playlist_collection_ident_count @endinternal
*  Retrieves the total number of identifiers associated with a Playlist Collection Summary and all of its Joined Collection Summaries.
*  @param h_collection [in] Handle to a collection summary
*  @param p_count [out] Pointer to receive the total number of identifiers
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg Given p_count is null
*  @return PLERR_NoError Collection summary identifiers were successfully counted
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_ident_count(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_uint32_t*						p_count
	);

/** @internal gnsdk_playlist_collection_ident_enum @endinternal
*  Retrieves a n'th identifier from a Playlist Collection Summary.
*  Use this function to iterate through the identifiers (0-n) contained in a collection summary and all of its joined summaries.
*  @param h_collection [in] Handle to a collection summary
*  @param index [in] Index of identifier to retrieve
*  @param p_ident [out] Pointer to receive a identifier
*  @param p_collection_name [out] Pointer to receive the collection name identifier
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_NoError n'th collection identifier was successfully retrieved
*  @return PLERR_OutOfRange if n'th collection identifier is equal greater than the count of identifiers.
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_ident_enum(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_uint32_t						index,
	gnsdk_cstr_t*						p_ident,
	gnsdk_cstr_t*						p_collection_name
	);


/** @internal GNSDK_GDO_TYPE_PLAYLIST_DATA @endinternal
  * Custom GDO type returned from Playlist. This GDO supports values of the same
  * name as attributes available for Playlist.
  * @ingroup Playlist_GDOType
*/
#define GNSDK_GDO_TYPE_PLAYLIST_DATA		"gnsdk_ctx_pldata"


/** @internal gnsdk_playlist_collection_ident_remove @endinternal
*  Removes an identifier from a Playlist Collection Summary.
*  @param h_collection [in] Handle to a Playlist collection summary
*  @param ident [in] String of identifier data
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg Given ident is empty
*  @return PLERR_NoError Media identifier was successfully removed
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_ident_remove(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_cstr_t						ident
	);


/** @internal gnsdk_playlist_collection_sync_ident_add @endinternal
*  Indicate an identifier is still physically present when setting up synchronization of a
Collection Summary.
*  Use this function to identify the differences between a user's media collection (such as MP3s on
a hard drive or a virtual collection hosted on a server) and an existing stored collection summary.
*  Synchronization of a collection summary to physical media involves two steps:
*  1. Adding all existing (current and new) identifiers using this function, which Playlist
collates.
*  2. Processing the current and new identifiers and using the callback to indicate which
identifiers should be removed from or added to the collection summary.
*  @param h_collection [in] Handle to a Playlist collection summary
*  @param ident [in] Identifier string
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg Attempting to update the collection summary with an unavailable,
invalid, or null identifier
*  @return PLERR_NoError Physical media and collection summary differences were successfully
identified
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_sync_ident_add(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_cstr_t						ident
	);

/** @internal gnsdk_playlist_collection_sync_process @endinternal
*  Synchronizes a Playlist Collection Summary with Gracenote Service data.
*  After preparing a collection summary for synchronization using
gnsdk_playlist_collection_sync_ident_add(), call gnsdk_playlist_collection_sync_process to reconcile
the collection summary's data with Gracenote Service.
*  During processing, gnsdk_playlist_update_callback_fn() alerts the application to idents that need
further action, such as adding new and deleting old identifiers.
*  @param h_collection [in] Handle to a collection summary
*  @param callback_fn [in] Callback function for information on identifiers to add or remove (not
optional)
*  @param callback_data [in_opt] Data that is passed back through calls to the callback function
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidCall Attempt to synchronize deleted or new identifier returned null
*  @return PLERR_NoError Collection summary synchronization was successfully processed
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_sync_process(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_playlist_update_callback_fn	callback_fn,
	gnsdk_void_t*						callback_data
	);


/** @internal gnsdk_playlist_collection_serialize_size @endinternal
*  Returns an estimated size of buffer required to hold a serialized representation of the
collection. The size is guaranteed to be large enough, but may be slightly larger than required.
*  @param h_collection [in] Handle to a collection
*  @param p_size [out] Pointer to receive collection buffer size
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_HandleObjectInvalid Collection is deserialized (size is 0)
*  @return PLERR_NoError Collection size was successfully serialized, or collection size is 0
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_serialize_size(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_size_t*						p_size
	);

/** @internal gnsdk_playlist_collection_serialize @endinternal
*  Outputs the Playlist Collection Summary to a buffer.
*  Serializes (encrypts) the collection handle so that the application can store it locally for
future use.
*  Applications can store the buffer using any convenient means. The Playlist library provides
collection storage using the Storage Administration APIs.
*  @param h_collection [in] Handle to a collection
*  @param p_collection_buf [in] Pointer to buffer to received serialized data
*  @param p_buf_size [in/out] Size of buffer pointed to by p_collection_buf, and number of bytes
written to p_collection_buf on successful serialization
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_HandleObjectInvalid Collection is invalid
*  @return PLERR_InvalidArg Collection is null
*  @return PLERR_Unsupported Collection is already serialized
*  @return PLERR_NoError Collection was successfully serialized
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_serialize(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_byte_t*						p_collection_buf,
	gnsdk_size_t*						p_buf_size
	);

/** @internal gnsdk_playlist_collection_deserialize @endinternal
*  Reconstitutes a Playlist Collection Summary from serialized collection summary data.
*  @param p_collection_buf [in] Pointer to the serialized collection summary data
*  @param buf_size [in] Size of serialized data buffer pointed to by p_collection_buf
*  @param ph_collection [out] Pointer to receive a collection summary handle
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg Collection summary is null
*  @return PLERR_InvalidInputObject Attempting to deserialize a valid collection summary with an
invalid size
*  @return PLERR_Unsupported Collection summary is already deserialized
*  @return PLERR_NoError Collection summary was successfully deserialized
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_deserialize(
	gnsdk_byte_t*						p_collection_buf,
	gnsdk_size_t						buf_size,
	gnsdk_playlist_collection_handle_t*	ph_collection
	);

/** @internal gnsdk_playlist_collection_attributes_count @endinternal
*  Retrieves the total number of attributes utilized by a collection summary.
*  Collection summary attributes may differ from the attributes registered in the Playlist system.
Only attributes supported by both the system and a collection summary can be used by a Playlist
definition.
*  @param h_collection [in] Handle to a collection summary
*  @param p_count [out] Pointer to receive total number of attributes for a collection summary
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg p_count is equal to NULL
*  @return PLERR_NoError Collection-specific attributes were successfully counted
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_attributes_count(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_uint32_t*						p_count
	);

/** @internal gnsdk_playlist_collection_attributes_enum @endinternal
*  Retrieves a n'th registered attribute specific to collection summary.
*  Collection summary attributes may differ from the attributes registered in the Playlist system.
Only attributes supported by both the system and a collection summary can be used by a Playlist
definition.
*  @param h_collection [in] Handle to a collection summary
*  @param index [in] Index of collection summary attribute to retrieve
*  @param p_attribute_name [out] Pointer to receive attribute name string
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg Given p_attribute_name is equal to NULL
*  @return PLERR_NoError Collection-specific attribute was successfully retrieved
* @ingroup Playlist_CollectionSummaryFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_collection_attributes_enum(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_uint32_t						index,
	gnsdk_cstr_t*						p_attribute_name
	);

/** @internal gnsdk_playlist_storage_store_collection @endinternal
*  Saves a Playlist Collection Summary to local storage.
*  @param h_collection [in] Handle to a collection summary
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_NoMemory SQLite library was not successfully initiated prior to this function's
call
*  @return PLERR_HandleObjectInvalid Collection is deserialized, invalid, or NULL
*  @return PLERR_LibraryNotLoaded Storage module was not successfully initialized
*  @return PLERR_NoError Collection summary was successfully stored
* <p><b>Note:</b></p>
*   Be sure to initialize the application's storage module prior to using this function.
* @ingroup Playlist_StorageFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_storage_store_collection(
	gnsdk_playlist_collection_handle_t	h_collection
	);

/** @internal gnsdk_playlist_storage_load_collection @endinternal
*  Loads a Playlist Collection Summary from local storage into memory for use.
*  Applications cannot access a collection summary directly from storage; it must first be loaded
into memory.
*  Use this function to load a collection summary from the application-specific storage solution or
(if implemented) the GNSDK SQLite library implementation.
*  @param collection_name [in] Collection summary to load into memory
*  @param ph_collection [out] Pointer to receive a collection summary handle
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_NotFound Given collection_name is unavailable
*  @return PLERR_InvalidArg Given collection_name is empty or NULL, or given ph_collection is NULL
*  @return PLERR_LibraryNotLoaded Storage module was not successfully initialized
*  @return PLERR_NoError Collection handle was successfully loaded
* <p><b>Note:</b></p>
*   Be sure to initialize the application's storage module prior to using this function.
* @ingroup Playlist_StorageFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_storage_load_collection(
	gnsdk_cstr_t						collection_name,
	gnsdk_playlist_collection_handle_t*	ph_collection
	);

/** @internal gnsdk_playlist_storage_count_collections @endinternal
*  Retrieves the total number of Playlist Collection Summaries available in storage.
*  @param p_collection_count [out] Pointer to receive count of stored collection summaries
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg Given p_collection_count is NULL
*  @return PLERR_LibraryNotLoaded Storage module was not successfully initialized
*  @return PLERR_NoError Number of collection summaries in storage was successfully counted
* <p><b>Note:</b></p>
*   Be sure to initialize the application's storage module prior to using this function.
* @ingroup Playlist_StorageFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_storage_count_collections(
	gnsdk_uint32_t*						p_collection_count
	);

/** @internal gnsdk_playlist_storage_enum_collections @endinternal
*  Retrieves the name of the n'th Playlist Collection Summary from storage.
*  @param index [in] Index to specific collection summary
*  @param collection_name_buf [in] Pointer to buffer to receive collection name
*  @param buf_size [in] Size of collection name to retrieve from buffer
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg Given collection_name_buf is null, or given buf_size is 0
*   PLERR_NotFound Given index is invalid
*  @return PLERR_LibraryNotLoaded Storage module was not successfully initialized
*  @return PLERR_NoError n'th collection summary in storage was successfully retrieved
* <p><b>Note:</b></p>
*   Be sure to initialize the application's storage module prior to using this function.
* @ingroup Playlist_StorageFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_storage_enum_collections(
	gnsdk_uint32_t						index,
	gnsdk_char_t*						collection_name_buf,
	gnsdk_size_t						buf_size
	);

/** @internal gnsdk_playlist_storage_remove_collection @endinternal
*  Permanently removes a Playlist collection summary from local storage.
*  Use this function to remove a collection summary name from storage.
*  This function only removes the named collection from storage. If the collection currently exists
as a handle, the handle and referenced collection will not be affected, and must still be released
when their use is complete. The application is free to store the same named collection again after
removing it.
*  @param collection_name [in] Collection summary to delete from storage
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_NotFound Given collection_name is invalid
*  @return PLERR_InvalidArg Given collection_name is empty
*  @return PLERR_LibraryNotLoaded Storage module was not successfully initialized
*  @return PLERR_NoError Collection summary was successfully removed from storage
* <p><b>Note:</b></p>
*   Be sure to initialize the application's storage module prior to using this function.
* @ingroup Playlist_StorageFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_storage_remove_collection(
	gnsdk_cstr_t						collection_name
	);

/** @internal gnsdk_playlist_statement_validate @endinternal
*  Validates a Playlist Definition Language (PDL) statement.
*  Use this function to determine:
*  If the PDL is invalid, such as using an attribute name that does not exist in the collection or
using an invalid keyword for an operator.
*  If the PDL requires a Seed to generate results.
*  As a best practice, we recommend calling this function to validate PDL statements especially
unknown statements before calling gnsdk_playlist_generate_playlist().
*  @param pdl_statement [in] PDL statement string
*  @param h_collection [in] Handle to a Playlist collection summary
*  @param pb_seed_required [out] Pointer to receive a boolean value indicating if a Playlist Seed is
required
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_StatementError PDL statement can't be validated, due to missing or incorrect
information. If PLERR_StatementError is returned, details on problems with the PDL statement can be
shown by calling gnsdk_manager_error_extended_info.
*  @return PLERR_InvalidArg Given pdl_statement is empty or invalid
*  @return PLERR_NoError PDL statement was successfully validated
* @ingroup Playlist_PlaylistGeneration_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_statement_validate(
	gnsdk_cstr_t						pdl_statement,
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_bool_t*						pb_seed_required
	);


/** @internal gnsdk_playlist_generate_playlist @endinternal
* *** Experimental ***
* Produces analyzation output of given PDL applied to given ident. The output is a formatted
* logical tree of the PDL statement and the outcome applied for each operation.
* This API is used for debugging and analyzation of playlist generation.
*  @param pdl_statement [in] PDL statement string
*  @param h_collection [in] Handle to a Playlist collection summary
*  @param ident [in] Identifier string
*  @param p_pdl_outcome [out] Pointer to receive a string value that contains the formatted tree. 
*	the user must free the string using gnsdk_manager_string_free.
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_StatementError PDL statement can't be executed, due to missing or incorrect
information. If PLERR_StatementError is returned, details on problems with the PDL statement can be
shown by calling gnsdk_manager_error_extended_info.
*  @return PLERR_InvalidArg Given input is empty or invalid.
*  @return PLERR_NoError PDL statement was successfully generated into a logical tree
*
* @ingroup Playlist_PlaylistGeneration_Functions
*/
gnsdk_error_t GNSDK_API 
gnsdk_playlist_statement_analyze_ident(
	gnsdk_cstr_t						pdl_statement,
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_cstr_t						ident,
	gnsdk_str_t*						p_pdl_outcome
	);

/** @internal gnsdk_playlist_generate_playlist @endinternal
*  Generates a Playlist.
*  Use this function to generate Playlist results.
*  As a best practice and for processing efficiency, we recommend calling
gnsdk_playlist_statement_validate() before generating results.
*  @param user_handle [in] Handle for the user requesting the playlist
*  @param pdl_statement [in] PDL statement string
*  @param h_collection [in] Handle to a Playlist collection summary
*  @param h_gdo_seed [in] Handle to a GDO Seed (if necessary)
*  @param ph_results [out] Pointer to receive generated Playlist
*  results handle
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg Given pdl_statement is empty, or given ph_results is null
*  @return PLERR_StatementError PDL statement can't be validated, due to missing or incorrect
information. If PLERR_StatementError is returned, details on problems with the PDL statement can be
shown by calling gnsdk_manager_error_extended_info.
*  @return PLERR_NoError Playlist was successfully generated
* <p><b>Note:</b></p>
* Streamline your Playlist implementation by using the
* gnsdk_playlist_generate_morelikethis() function, which uses the "More Like This" algorithm to generate
optimal playlist results and eliminates the need to create and validate Playlist Definition Language
statements.
*  <p><b>Important:</b></p>
*  Playlist generates playlists from a single collection summary at a time. It does not support the
derivation of playlists across multiple collection summaries. Applications that require deriving a
playlist from
*  multiple collection summaries must create a master collection summary that spans the required
collections.
* @ingroup Playlist_PlaylistGeneration_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_generate_playlist(
	gnsdk_user_handle_t					user_handle,
	gnsdk_cstr_t						pdl_statement,
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_gdo_handle_t					h_gdo_seed,
	gnsdk_playlist_results_handle_t*	ph_results
	);

/** @internal gnsdk_playlist_generate_morelikethis @endinternal
*  Generates a Playlist using the Gracenote "More Like This" algorithm and GDO Seed
*  input. The algorithm matches tracks primarily on Mood and Genre attributes.
*  @param user_handle [in] Handle for the user requesting the "More Like This" playlist
*  @param h_collection [in] Handle to a Playlist collection summary
*  @param h_gdo_seed [in] Handle to a GDO Seed (required)
*  @param ph_results [out] Pointer to receive generated Playlist
*  results handle
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg Given ph_results is null
*  @return PLERR_NoError Playlist was successfully generated
*  <p><b>Important:</b></p>
*  Playlist generates playlists from a single collection summary at a time. It does not support the
derivation of playlists across multiple collection summaries. Applications that require deriving a
playlist from
*  multiple collection summaries must create a master collection summary that spans the required
collections.
* @ingroup Playlist_PlaylistGeneration_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_generate_morelikethis(
	gnsdk_user_handle_t					user_handle,
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_gdo_handle_t					h_gdo_seed,
	gnsdk_playlist_results_handle_t*	ph_results
	);

/** @internal GNSDK_PLAYLIST_MORELIKETHIS_OPTION_MAX_TRACKS @endinternal
  * Option for querying/specifying the maximum number of results returned in a "More Like This" playlist.
  * The value for this key must evaluate to a number greater than 0.
  * @ingroup Playlist_PlaylistGeneration_Options
*/
#define	GNSDK_PLAYLIST_MORELIKETHIS_OPTION_MAX_TRACKS		"gnsdk_playlist_morelikethis_option_max_tracks"


/** @internal GNSDK_PLAYLIST_MORELIKETHIS_OPTION_MAX_PER_ARTIST @endinternal
  * Option for querying/specifying the maximum number of results per artist returned in a "More Like This" playlist.
  * The value for this key must evaluate to a number greater than 0.
  * @ingroup Playlist_PlaylistGeneration_Options
*/
#define	GNSDK_PLAYLIST_MORELIKETHIS_OPTION_MAX_PER_ARTIST	"gnsdk_playlist_morelikethis_option_max_per_artist"

/** @internal GNSDK_PLAYLIST_MORELIKETHIS_OPTION_MAX_PER_ALBUM @endinternal
  * Option for querying/specifying the maximum number of results per album returned in a "More Like This" playlist.
  * The value for this key must evaluate to a number greater than 0.
  * @ingroup Playlist_PlaylistGeneration_Options
*/
#define	GNSDK_PLAYLIST_MORELIKETHIS_OPTION_MAX_PER_ALBUM	"gnsdk_playlist_morelikethis_option_max_per_album"

/** @internal GNSDK_PLAYLIST_MORELIKETHIS_OPTION_RANDOMSEED @endinternal
  * Option for querying/specifying the seed value for the random number generator used in calculating a 
  * "More Like This" playlist. Using the same number for a seed will generate the same 'random' sequence, thus allowing
  * the same playlist ordering to be recreated. Choosing different numbers will create different playlists. Valid values
  * are from '1' to "4294967295" .
  * @ingroup Playlist_PlaylistGeneration_Options
*/
#define GNSDK_PLAYLIST_MORELIKETHIS_OPTION_RANDOMSEED	        "gnsdk_playlist_morelikethis_option_random"
#define GNSDK_PLAYLIST_MORELIKETHIS_OPTION_RANDOM	        	GNSDK_PLAYLIST_MORELIKETHIS_OPTION_RANDOMSEED

/** @internal gnsdk_playlist_morelikethis_option_get @endinternal
  *
  *   Retrieves an option for "More Like This" for a given collection.
  *   See @link Playlist_PlaylistGeneration_Options Playlist Generation Options @endlink for the list of available options.
  *   Please note that these options are not serialized or stored.
  *  @param  h_collection	  	[in] Collection handle
  *  @param  option_key			[in] An option for the "More Like This" playlist
  *  @param  p_option_value		[out] Pointer to hold the value for given option
  * @ingroup Playlist_PlaylistGeneration_Functions
  *
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_morelikethis_option_get(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_cstr_t						option_key,
	gnsdk_cstr_t*						p_option_value
	);


/** @internal gnsdk_playlist_morelikethis_option_set @endinternal
  *
  *   Sets a "More Like This" option on the collection.
  *   See @link Playlist_PlaylistGeneration_Options Playlist Generation Options @endlink for the list of available options.
  *   Please note that these options are not serialized or stored.
  *
  *  @param  h_collection	  	[in] Collection handle
  *  @param  option_key			[in] An option from the available "More Like This" list
  *  @param  option_value		[in] Value to set for given option
  * @ingroup Playlist_PlaylistGeneration_Functions
  *
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_morelikethis_option_set(
	gnsdk_playlist_collection_handle_t	h_collection,
	gnsdk_cstr_t					    option_key,
	gnsdk_cstr_t						option_value
	);


/** @internal gnsdk_playlist_results_count @endinternal
*  Retrieves the total number of results of a generated Playlist.
*  @param h_results [in] Handle to Playlist results
*  @param p_count [out] Pointer to receive the total number of generated results
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg Given p_count is null
*  @return PLERR_NoError Results were successfully counted
* @ingroup Playlist_PlaylistGeneration_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_results_count(
	gnsdk_playlist_results_handle_t		h_results,
	gnsdk_uint32_t*						p_count
	);

/** @internal gnsdk_playlist_results_enum @endinternal
*  Retrieves the n'th identifier of a result in a generated Playlist.
*  @param h_results [in] Handle to Playlist results
*  @param index [in] Index of result to retrieve
*  @param p_ident [out] Pointer to receive resulting identifier
*  @param p_collection_name [out] Pointer to receive collection name to which that ident belongs; Optional
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_InvalidArg Given p_ident is null
*  @return PLERR_NoError n'th result was successfully retrieved
* @ingroup Playlist_PlaylistGeneration_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_results_enum(
	gnsdk_playlist_results_handle_t		h_results,
	gnsdk_uint32_t						index,
	gnsdk_cstr_t*						p_ident,
	gnsdk_cstr_t*						p_collection_name
	);

/** @internal gnsdk_playlist_results_release @endinternal
*  Invalidates and releases resources for a given Playlist's results.
*  @param h_results [in] Handle to Playlist results
*  @return PLERR_NotInited gnsdk_playlist_initialize was not successfully initiated
*  @return PLERR_NoError Results were successfully released or null
* @ingroup Playlist_PlaylistGeneration_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_results_release(
	gnsdk_playlist_results_handle_t		h_results
	);

/******************************************************************************
 * Playlist storage management APIs
 ******************************************************************************/

/** @internal gnsdk_playlist_storage_compact @endinternal
*  Performs compaction on named local storage.
*  @return GNSDK_SUCCESS or error
* @ingroup Playlist_StorageFunctions
* Long Running Potential: File system I/O, database size affects running time
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_storage_compact(void);

/** @internal gnsdk_playlist_storage_location_set @endinternal
*  Set location on named local storage.
*  @param storage_location [in] String value to indicate location of storage.
*  @return GNSDK_SUCCESS or error
* @ingroup Playlist_StorageFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_storage_location_set(
	gnsdk_cstr_t	storage_location
	);

/** @internal gnsdk_playlist_storage_validate @endinternal
*  Performs validation on named local storage.
*  @param p_valid [out] Pointer to error info struct to hold validation result.
*  @return GNSDK_SUCCESS or error
* @ingroup Playlist_StorageFunctions
* Long Running Potential: File system I/O, database size affects running time
*/
gnsdk_error_t GNSDK_API
gnsdk_playlist_storage_validate(
	gnsdk_error_info_t*	p_valid
	);



#ifdef __cplusplus
}
#endif

#endif /* _GNSDK_PLAYLIST_H_ */

