/*
  *
  *  GRACENOTE, INC. PROPRIETARY INFORMATION
  *  This software is supplied under the terms of a license agreement or
  *  nondisclosure agreement with Gracenote, Inc. and may not be copied
  *  or disclosed except in accordance with the terms of that agreement.
  *  Copyright(c) 2000-2013. Gracenote, Inc. All Rights Reserved.
  *
 */

/* gnsdk_storage_manager.h: Primary interface for the GNSDK Manager Storage.
*/

#ifndef _GNSDK_MANAGER_STORAGE_H_
#define _GNSDK_MANAGER_STORAGE_H_

#include "gnsdk_manager.h"

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
 * SDK Manager local storage management APIs
 ******************************************************************************/

/** @internal gnsdk_manager_storage_cleanup @endinternal
*  This function searches the existing local SDK cache and removes any records that are expired.
*
*  Operation
*
*  This API first decides if maintenance is required; this is determined by tracking when the next
*  record expiration is needed.
*
*  Maintenance is always run the first time this API is called; any subsequent calls only perform
*  maintenance if this is required. Consequently, calling this API multiple times does not result in
*  excessive maintenance.
*
*  Storage Names
*
*  Currently there are three storages managed by the SDK:
*  <ul>
*   <li>The content cache, which stores cover art and related information #GNSDK_MANAGER_STORAGE_CONTENTCACHE
*   <li>The query cache, which stores media identification requests #GNSDK_MANAGER_STORAGE_QUERYCACHE
*   <li>The list storage, which stores Gracenote's display lists #GNSDK_MANAGER_STORAGE_LISTS
*  </ul>
*  Use the appropriate name to perform this operation on the target storage. Each of these require a
*  separate call to this API, with the name of the storage to on which to perform the maintenance.
*
*  Performance
*
*  If <code>b_async</code> is true and if maintenance is necessary, this API spawns a thread to perform the cleanup.
*  This thread runs at the lowest priority to minimize the impact on other running queries or operations of the SDK.
*
*  This function can cause performance issues due to creating a large amount of disk I/O.
*
*  This operation can be performed on different storages at the same time, but note that performing
*  multiple simultaneous calls will potentially further degrade performance.
*
*  Expired Records
*
*  Expired records are those older than the maximum allowable, even if the record has been recently
*  read. Old but actively read records are removed because Gracenote Service may have an updated
*  matching record.
*
*  The maximum allowable age of a record varies by query type and is managed internally by
*  Gracenote. Applications can use #GNSDK_USER_OPTION_CACHE_EXPIRATION to adjust the age at which
*  records are expired.
*
*  @param storage_name [in] Local storage name
*  @param b_async [in] Boolean value to indicate whether to perform an asynchronous cleanup maintenance in the background
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_NoError Cleanup was successfully performed
*
* @ingroup StorageandCaching_General_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_storage_cleanup(
	gnsdk_cstr_t	storage_name,
	gnsdk_bool_t	b_async
	);


/** @internal gnsdk_manager_storage_compact @endinternal
*  Attempts to compact the named local storage to minimize the amount of space required.
*
*  When the b_async parameter is set to value that equals TRUE, then the function immediately
*  returns and the flush is performed in the background and on a separate thread.
*
*  Storage Names
*
*  Currently there are three storages managed by the SDK:
*  <ul>
*   <li>The content cache, which stores cover art and related information #GNSDK_MANAGER_STORAGE_CONTENTCACHE
*   <li>The query cache, which stores media identification requests #GNSDK_MANAGER_STORAGE_QUERYCACHE
*   <li>The list storage, which stores Gracenote display lists #GNSDK_MANAGER_STORAGE_LISTS
*  </ul>
*  Use the appropriate name to perform this operation on the target storage. Each of these require a
*  separate call to this API, with the name of the storage on which to perform the cleanup.
*
*  Performance
*
*  If <code>b_async</code> is true this API spawns a thread to perform the operation. This thread runs at the
*  lowest priority to minimize the impact on other running queries or operations of the SDK.
*
*  This function can cause performance issues due to creating a large amount of disk I/O.
*
*  This operation can be performed on different storages at the same time, but note that performing
*  multiple simultaneous calls will potentially further degrade performance.
*
*  @param storage_name [in] Local storage name
*  @param b_async [in] Boolean value to indicate whether to perform an asynchronous cache compact in the background, on a separate thread
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_NoError Compact was successfully performed
*
* @ingroup StorageandCaching_General_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_storage_compact(
	gnsdk_cstr_t	storage_name,
	gnsdk_bool_t	b_async
	);


/** @internal gnsdk_manager_storage_flush @endinternal
*  This function clears all records from the named local storage.
*
*  When the b_async parameter is set to value that equals TRUE, then the function immediately
*  returns and the flush is performed in the background and on a separate thread.
*
*  Storage Names
*
*  Currently there are three storages managed by the SDK:
*  <ul>
*   <li>The content cache, which stores cover art and related information #GNSDK_MANAGER_STORAGE_CONTENTCACHE
*   <li>The query cache, which stores media identification requests #GNSDK_MANAGER_STORAGE_QUERYCACHE
*   <li>The list storage, which stores Gracenote display lists #GNSDK_MANAGER_STORAGE_LISTS
*  </ul>
*  Use the appropriate name to perform this operation on the target storage. Each of these require a
*  separate call to this API, with the name of the storage on which to perform the flush.
*
*  Performance
*
*  If <code>b_async</code> is true this API spawns a thread to perform the operation. This thread runs at the
*  lowest priority to minimize the impact on other running queries or operations of the SDK.
*
*  This function can cause performance issues due to creating a large amount of disk I/O.
*
*  This operation can be performed on different storages at the same time, but note that performing
*  multiple simultaneous calls will potentially further degrade performance.
*
*  @param storage_name [in] Local storage name
*  @param b_async [in] Boolean value to indicate whether to perform an asynchronous cache flush in the background, on a separate thread
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_NoError Flush was successfully performed
*
* @ingroup StorageandCaching_General_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_storage_flush(
	gnsdk_cstr_t	storage_name,
	gnsdk_bool_t	b_async
	);


/** @internal gnsdk_manager_storage_location_set @endinternal
*  This function cas be used to specify the location of the named local storage.
*
*  If this option is not specified the option set for the initialized storage SDK will be used.
*  For example, if the SQLite Storage SDK has been initialized any path set using
*  #GNSDK_STORAGE_SQLITE_OPTION_STORAGE_FOLDER and <code>gnsdk_storage_sqlite_option_set()</code> will be used.
*
*  The storage location must be a valid relative or absolute path to an existing folder that
*  has the necessary write permissions.
*
*  <p><b>Important:</b></p>
*  For Windows CE an absolute path must be used.
*
*  Storage Names
*
*  Currently there are three storages managed by the SDK:
*  <ul>
*   <li>The content cache, which stores cover art and related information #GNSDK_MANAGER_STORAGE_CONTENTCACHE
*   <li>The query cache, which stores media identification requests #GNSDK_MANAGER_STORAGE_QUERYCACHE
*   <li>The list storage, which stores Gracenote display lists #GNSDK_MANAGER_STORAGE_LISTS
*  </ul>
*  Use the appropriate name to perform this operation on the target storage. Each of these require a
*  separate call to this API, with the name of the storage on which to specify the location for.
*
*  @param storage_name [in] Local storage name
*  @param storage_location [in] String value to indicate location of storage.
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_NoError Set location was successfully performed
*
* @ingroup StorageandCaching_General_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_storage_location_set(
	gnsdk_cstr_t	storage_name,
	gnsdk_cstr_t	storage_location
	);


/** @internal gnsdk_manager_storage_validate @endinternal
*  Performs validation on the named local storage.
*
*  Storage Names
*
*  Currently there are three storages managed by the SDK:
*  <ul>
*   <li>The content cache, which stores cover art and related information #GNSDK_MANAGER_STORAGE_CONTENTCACHE
*   <li>The query cache, which stores media identification requests #GNSDK_MANAGER_STORAGE_QUERYCACHE
*   <li>The list storage, which stores Gracenote display lists #GNSDK_MANAGER_STORAGE_LISTS
*  </ul>
*  Use the appropriate name to perform this operation on the target storage. Each of these require a
*  separate call to this API, with the name of the storage on which to perform the flush.
*
*  @param storage_name [in] Local storage name
*  @param p_valid [out] Pointer to error info struct to hold validation result.
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_NoError Validation was successfully performed
*
* @ingroup StorageandCaching_General_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_storage_validate(
	gnsdk_cstr_t			storage_name,
	gnsdk_error_info_t*		p_valid
	);


/** @internal GNSDK_MANAGER_STORAGE_QUERYCACHE @endinternal
*  Name of the cache the SDK creates to store queries.
*
*  The query cache stores media identification requests and the resultant metadata.
*
* @ingroup StorageandCaching_General_StorageIDs
*/
#define GNSDK_MANAGER_STORAGE_QUERYCACHE		"gnsdk_storage_querycache"
/** @internal GNSDK_MANAGER_STORAGE_CONTENTCACHE @endinternal
*  Name of the cache the SDK creates to store content.
*
*  The content cache stores cover art and other media-related information.
*
* @ingroup StorageandCaching_General_StorageIDs
*/
#define GNSDK_MANAGER_STORAGE_CONTENTCACHE		"gnsdk_storage_contentcache"
/** @internal GNSDK_MANAGER_STORAGE_LISTS @endinternal
*  Name of the storage the SDK uses to store Gracenote display lists.
*
* @ingroup StorageandCaching_General_StorageIDs
*/
#define GNSDK_MANAGER_STORAGE_LISTS				"gnsdk_storage_lists"
/** @internal GNSDK_MANAGER_STORAGE_LISTSCACHE @endinternal
*  @deprecated Will be removed in a future release. Use GNSDK_MANAGER_STORAGE_LISTS instead. *
*
* @ingroup StorageandCaching_General_StorageIDs
*/
#define GNSDK_MANAGER_STORAGE_LISTSCACHE		"gnsdk_storage_lists"

/** @internal GNSDK_MANAGER_STORAGE_TEMP @endinternal
*  Name of the storage the SDK uses to store Gracenote temp data.
*
* @ingroup StorageandCaching_General_StorageIDs
*/
#define GNSDK_MANAGER_STORAGE_TEMP				"gnsdk_storage_temp"


#ifdef __cplusplus
}
#endif

#endif /** @internal _GNSDK_MANAGER_STORAGE_H_ @endinternal
*  Primary interface for the GNSDK Manager Storage.
*/

