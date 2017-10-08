/*
  *
  *  GRACENOTE, INC. PROPRIETARY INFORMATION
  *  This software is supplied under the terms of a license agreement or
  *  nondisclosure agreement with Gracenote, Inc. and may not be copied
  *  or disclosed except in accordance with the terms of that agreement.
  *  Copyright(c) 2000-2013. Gracenote, Inc. All Rights Reserved.
  *
 */

#ifndef _GNSDK_LOOKUP_LOCAL_H_
/* gnsdk_lookup_local.h: Primary interface for the Lookup Local module.
 */
#define _GNSDK_LOOKUP_LOCAL_H_

#include "gnsdk_manager.h"
#include "gnsdk_manager_gdo.h"

#ifdef __cplusplus
extern "C"{
#endif


/******************************************************************************
 * Initialization APIs
 ******************************************************************************/

/** @internal gnsdk_lookup_local_initialize @endinternal
  * Initializes the Lookup Local module.
  * This function must be successfully called before any calls to other Lookup Local APIs will succeed.
  * @param sdkmgr_handle [in] Handle from a successful gnsdk_manager_initialize() call.
  *
  * @return GNSDK_SUCCESS Initialization succeeded
  * @return error Initialization failed
  *
  * @ingroup Setup_LookupLocal_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_lookup_local_initialize(
	gnsdk_manager_handle_t sdkmgr_handle
	);

/** @internal gnsdk_lookup_local_shutdown @endinternal
  * Shuts down and release resources for the Lookup Local module.
  * gnsdk_lookup_local_shutdown must be called to shutdown this module;
  * all Lookup Local APIs cease to function until the module is again initialized.
  * @return GNSDK_SUCCESS Shutdown succeeded
  * @return error Shutdown failed
  *
  * @ingroup Setup_LookupLocal_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_lookup_local_shutdown(void);

/** @internal gnsdk_lookup_local_get_version @endinternal
  * Retrieves the Lookup Local module version string.
  * This API can be called at any time, even before initialization and after shutdown.
  * @return  Returns the version string for this module
  *
  * @ingroup Setup_LookupLocal_Functions
*/
gnsdk_cstr_t GNSDK_API
gnsdk_lookup_local_get_version(void);

/** @internal gnsdk_lookup_local_get_build_date @endinternal
  * Retrieves the Lookup Local module's build date string.
  * This API can be called at any time, even before initialization and after shutdown.
  * @return Returns the build date string for this module
  *
  * @ingroup Setup_LookupLocal_Functions
*/
gnsdk_cstr_t GNSDK_API
gnsdk_lookup_local_get_build_date(void);

/******************************************************************************
 * Lookup local storage management APIs
 ******************************************************************************/

/** @internal gnsdk_lookup_local_storage_compact @endinternal
  * Performs compaction on named local storage.
  * See @link StorageandCaching_General_StorageIDs Storage IDs @endlink for possible storage names.
  * @param storage_name [in] Local storage name
  * @return GNSDK_SUCCESS
  * @return error
  * @ingroup Setup_LookupLocal_Functions
  * Long Running Potential: File system I/O, database size affects running time
*/
gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_compact(
	gnsdk_cstr_t	storage_name
	);

/** @internal gnsdk_lookup_local_storage_location_set @endinternal
  * Sets the location for named local storage.
  * See @link Setup_StorageIDs Storage IDs @endlink for possible storage names.
  * <p><b>Remarks:</b></p>
  *  The storage location path can be absolute or relative.
  *  However, Windows CE developers will need to set the full path, since relative path is not supported in Windows CE.
  * 
  * You can use gnsdk_storage_sqlite_option_set() to set all the storage locations at once.
  * @param storage_name [in] Local storage name
  * @param storage_location [in] String value of path to indicate location of storage
  * @return GNSDK_SUCCESS
  * @return error
  * @ingroup Setup_LookupLocal_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_location_set(
	gnsdk_cstr_t	storage_name,
	gnsdk_cstr_t	storage_location
	);

/** @internal gnsdk_lookup_local_storage_validate @endinternal
  * Performs validation on named local storage.
  * @param storage_name [in] Local storage name
  * @param p_valid [out] Pointer to error info struct to hold validation result.
  * @return GNSDK_SUCCESS
  * @return error
  * @ingroup Setup_LookupLocal_Functions
  * Long Running Potential: File system I/O, database size affects running time
*/
gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_validate(
	gnsdk_cstr_t			storage_name,
	gnsdk_error_info_t*		p_valid
	);

/** @internal gnsdk_lookup_local_storage_version_get @endinternal
  * <b>Deprecated.</b> Use gnsdk_lookup_local_storage_info_get() instead. 
  * @param storage_name [in] Local storage name
  * @param p_gdb_version [out] String value for format version.
  * @return GNSDK_SUCCESS
  * @return error
  * @ingroup Setup_LookupLocal_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_version_get(
	gnsdk_cstr_t	storage_name,
	gnsdk_cstr_t*	p_gdb_version
	);
	
/** @internal gnsdk_lookup_local_storage_info_count @endinternal
  * Get count of information available for named local storage and local storage key.
  * @param storage_name [in] Local storage name
  * @param storage_info_key [in] Local storage information key
  * @param p_info_count [out] Pointer to integer value for information count.
  * @return GNSDK_SUCCESS
  * @return error
  * @ingroup Setup_LookupLocal_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_info_count(
	gnsdk_cstr_t	storage_name,
	gnsdk_cstr_t	storage_info_key,
	gnsdk_uint32_t*	p_info_count
	);

/** @internal gnsdk_lookup_local_storage_info_get @endinternal
  * Get ordinal based information for named local storage and local storage key.
  * @param storage_name [in] Local storage name
  * @param storage_info_key [in] Local storage information key
  * @param ordinal [in] Integer ordinal input
  * @param p_storage_info [out] String value for information.
  * @return GNSDK_SUCCESS
  * @return error
  * @ingroup Setup_LookupLocal_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_info_get(
	gnsdk_cstr_t	storage_name,
	gnsdk_cstr_t	storage_info_key,
	gnsdk_uint32_t	ordinal,
	gnsdk_cstr_t*	p_storage_info
	);

/******************************************************************************
 * Lookup local storage management APIs (with Storage Identifier)
 ******************************************************************************/

/** @internal gnsdk_lookup_local_storage_handle_t @endinternal
 *  Handle to interaction with local storages.
 *  The application creates this handle to facilitate interaction with local storages.
 *  <p><b>Remarks:</b></p>
 *  An application may create as many of these handles as needed using 
 *  gnsdk_lookup_local_storage_create() or gnsdk_lookup_local_storage_open()
 * @ingroup LookupLocalStorage_TypesEnums
 */
GNSDK_DECLARE_HANDLE( gnsdk_lookup_local_storage_handle_t );

/** @internal gnsdk_lookup_local_storage_create @endinternal
  * Creates a local storage handle.
  *
  * You need to first set the location of the storage with gnsdk_lookup_local_storage_location_set2
  *		before calling this API.
  * @param storage_identifier [in] Local storage identifier
  * @param p_lookup_local_storage_handle [out] Local storage handle
  * @return GNSDK_SUCCESS
  * @return error
  * @ingroup Setup_LookupLocalStorage_Functions
  *
*/
gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_create(
	gnsdk_cstr_t							storage_identifier,
	gnsdk_lookup_local_storage_handle_t*	p_lookup_local_storage_handle
);

/** @internal gnsdk_lookup_local_storage_open @endinternal
  * Creates a local storage handle.
  *
  * You need to first set the location of the storage with gnsdk_lookup_local_storage_location_set2
  *		before calling this API.
  * @param storage_identifier [in] Local storage identifier
  * @param p_lookup_local_storage_handle [out] Local storage handle
  * @return GNSDK_SUCCESS
  * @return error
  * @ingroup Setup_LookupLocalStorage_Functions
  *
*/
gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_open(
	gnsdk_cstr_t							storage_identifier,
	gnsdk_lookup_local_storage_handle_t*	p_lookup_local_storage_handle
);

/** @internal gnsdk_lookup_local_storage_release @endinternal
  * Release a local storage handle.
  * @param p_lookup_local_storage_handle [in] Local storage handle
  * @return GNSDK_SUCCESS
  * @return error
  * @ingroup Setup_LookupLocalStorage_Functions
  *
*/
gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_release(
	gnsdk_lookup_local_storage_handle_t		lookup_local_storage_handle
);

/** @internal gnsdk_lookup_local_storage_add_record @endinternal
  * Adds a GDO handle to the local storage.
  * @param p_lookup_local_storage_handle [in] Local storage handle
  * @param gdo [in] GDO handle
  * @return GNSDK_SUCCESS
  * @return error
  * @ingroup Setup_LookupLocalStorage_Functions
  *
*/
gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_add_record(
	gnsdk_lookup_local_storage_handle_t		lookup_local_storage_handle,
	gnsdk_gdo_handle_t						gdo
);

/** @internal gnsdk_lookup_local_storage_add_image @endinternal
  * Adds a GDO handle to the local storage.
  * @param p_lookup_local_storage_handle [in] Local storage handle
  * @param buffer [in] buffer of image
  * @param buffer_size [in] buffer size
  * @param content_id [in] content identifier
  * @param image_type [in] image type use GNSDK_CONTENT_TYPE_IMAGE_* macros
  * @param image_size [in] imafe size use GNSDK_CONTENT_DATA_SIZE_VALUE_* macros
  * @param image_format [in] image format use GNSDK_CONTENT_DATA_TYPE_VALUE_* macros
  * @param flags [in] flags
  * @return GNSDK_SUCCESS
  * @return error
  * @ingroup Setup_LookupLocalStorage_Functions
  *
*/
gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_add_image(
	gnsdk_lookup_local_storage_handle_t		lookup_local_storage_handle,
	gnsdk_byte_t*							buffer, 
	gnsdk_size_t							buffer_size, 
	gnsdk_cstr_t							content_id,
	gnsdk_cstr_t							image_type,
	gnsdk_cstr_t							image_size,
	gnsdk_cstr_t							image_format,
	gnsdk_uint32_t							flags
	);
	
/** @internal gnsdk_lookup_local_storage_compact2 @endinternal
  * Performs compaction on named local storage.
  * See @link StorageandCaching_General_StorageIDs Storage IDs @endlink for possible storage names.
  * @param storage_identifier [in] Local storage identifier
  * @param storage_name [in] Local storage name
  * @return GNSDK_SUCCESS
  * @return error
  * @ingroup Setup_LookupLocalStorage_Functions
  * Long Running Potential: File system I/O, database size affects running time
*/
gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_compact2(
	gnsdk_cstr_t	storage_identifier,
	gnsdk_cstr_t	storage_name
	);

/** @internal gnsdk_lookup_local_storage_location_set2 @endinternal
  * Sets the location for named local storage.
  * See @link Setup_StorageIDs Storage IDs @endlink for possible storage names.
  * <p><b>Remarks:</b></p>
  *  The storage location path can be absolute or relative.
  *  However, Windows CE developers will need to set the full path, since relative path is not supported in Windows CE.
  * 
  * You must set the storage location with this API befre you can open/create storage handle.
  * @param storage_identifier [in] Local storage identifier
  * @param storage_name [in] Local storage name
  * @param storage_location [in] String value of path to indicate location of storage
  * @return GNSDK_SUCCESS
  * @return error
  * @ingroup Setup_LookupLocalStorage_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_location_set2(
	gnsdk_cstr_t	storage_identifier,
	gnsdk_cstr_t	storage_name,
	gnsdk_cstr_t	storage_location
	);

/** @internal gnsdk_lookup_local_storage_validate2 @endinternal
  * Performs validation on named local storage.
  * @param storage_identifier [in] Local storage identifier
  * @param storage_name [in] Local storage name
  * @param p_valid [out] Pointer to error info struct to hold validation result.
  * @return GNSDK_SUCCESS
  * @return error
  * @ingroup Setup_LookupLocalStorage_Functions
  * Long Running Potential: File system I/O, database size affects running time
*/
gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_validate2(
	gnsdk_cstr_t			storage_identifier,
	gnsdk_cstr_t			storage_name,
	gnsdk_error_info_t*		p_valid
	);

/** @internal gnsdk_lookup_local_storage_version_get2 @endinternal
  * <b>Deprecated.</b> Use gnsdk_lookup_local_storage_info_get() instead. 
  * @param storage_identifier [in] Local storage identifier
  * @param storage_name [in] Local storage name
  * @param p_gdb_version [out] String value for format version.
  * @return GNSDK_SUCCESS
  * @return error
  * @ingroup Setup_LookupLocalStorage_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_version_get2(
	gnsdk_cstr_t	storage_identifier,
	gnsdk_cstr_t	storage_name,
	gnsdk_cstr_t*	p_gdb_version
	);
	
/** @internal gnsdk_lookup_local_storage_info_count2 @endinternal
  * Get count of information available for named local storage and local storage key.
  * @param storage_identifier [in] Local storage identifier
  * @param storage_name [in] Local storage name
  * @param storage_info_key [in] Local storage information key
  * @param p_info_count [out] Pointer to integer value for information count.
  * @return GNSDK_SUCCESS
  * @return error
  * @ingroup Setup_LookupLocalStorage_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_info_count2(
	gnsdk_cstr_t	storage_identifier,
	gnsdk_cstr_t	storage_name,
	gnsdk_cstr_t	storage_info_key,
	gnsdk_uint32_t*	p_info_count
	);

/** @internal gnsdk_lookup_local_storage_info_get2 @endinternal
  * Get ordinal based information for named local storage and local storage key.
  * @param storage_identifier [in] Local storage identifier
  * @param storage_name [in] Local storage name
  * @param storage_info_key [in] Local storage information key
  * @param ordinal [in] Integer ordinal input
  * @param p_storage_info [out] String value for information.
  * @return GNSDK_SUCCESS
  * @return error
  * @ingroup Setup_LookupLocalStorage_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_lookup_local_storage_info_get2(
	gnsdk_cstr_t	storage_identifier,
	gnsdk_cstr_t	storage_name,
	gnsdk_cstr_t	storage_info_key,
	gnsdk_uint32_t	ordinal,
	gnsdk_cstr_t*	p_storage_info
	);

/** @internal GNSDK_LOOKUP_LOCAL_STORAGE_PRIMARY_IDENTIFIER @endinternal
  * Name of the local storage the SDK uses to identify the primary local storage.
  * @ingroup LookupLocalStorage_TypesEnums
*/
#define GNSDK_LOOKUP_LOCAL_STORAGE_PRIMARY_IDENTIFIER   "gnsdk_lookup_local_storage_primary_identifier"


/** @internal GNSDK_LOOKUP_LOCAL_STORAGE_CONTENT @endinternal
  * Name of the local storage the SDK uses to query Gracenote Content (gn_cds.gdb).
  * @ingroup Setup_StorageIDs
*/
#define GNSDK_LOOKUP_LOCAL_STORAGE_CONTENT			"gnsdk_lookup_local_gdbcds"

/** @internal GNSDK_LOOKUP_LOCAL_STORAGE_METADATA @endinternal
  * Name of the local storage the SDK uses to query Gracenote Metadata (gn_mdata.gdb).
  * @ingroup Setup_StorageIDs
*/
#define GNSDK_LOOKUP_LOCAL_STORAGE_METADATA			"gnsdk_lookup_local_gdbmdata"

/** @internal GNSDK_LOOKUP_LOCAL_STORAGE_TOCINDEX @endinternal
  * Name of the local storage the SDK uses for CD TOC searching (gn_itoc.gdb).
  * @ingroup Setup_StorageIDs
*/
#define GNSDK_LOOKUP_LOCAL_STORAGE_TOCINDEX			"gnsdk_lookup_local_gdbitoc"

/** @internal GNSDK_LOOKUP_LOCAL_STORAGE_TEXTINDEX @endinternal
  * Name of the local storage the SDK uses for text searching (gn_itxt.gdb).
  * @ingroup Setup_StorageIDs
*/
#define GNSDK_LOOKUP_LOCAL_STORAGE_TEXTINDEX		"gnsdk_lookup_local_gdbitxt"
	
/** @internal GNSDK_LOOKUP_LOCAL_STORAGE_ALL @endinternal
  * For referencing all the above storages that make up the local storage.
  * @ingroup Setup_StorageIDs
*/
#define GNSDK_LOOKUP_LOCAL_STORAGE_ALL				"gnsdk_lookup_local_gdball"


/** @internal GNSDK_LOOKUP_LOCAL_STORAGE_GDB_VERSION @endinternal
  * Key the local storage the SDK uses for version searching.
  * @ingroup Setup_StorageIDs
*/
#define GNSDK_LOOKUP_LOCAL_STORAGE_GDB_VERSION		"gnsdk_lookup_local_gdb_version"

/** @internal GNSDK_LOOKUP_LOCAL_STORAGE_IMAGE_SIZE @endinternal
  * Key the local storage the SDK uses for content image size searching.
  * @ingroup Setup_StorageIDs
*/
#define GNSDK_LOOKUP_LOCAL_STORAGE_IMAGE_SIZE		"gnsdk_lookup_local_image_size"


#ifdef __cplusplus
}
#endif

#endif /* _GNSDK_LOOKUP_LOCAL_H_ */

