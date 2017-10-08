/*
  *
  *  GRACENOTE, INC. PROPRIETARY INFORMATION
  *  This software is supplied under the terms of a license agreement or
  *  nondisclosure agreement with Gracenote, Inc. and may not be copied
  *  or disclosed except in accordance with the terms of that agreement.
  *  Copyright(c) 2000-2013. Gracenote, Inc. All Rights Reserved.
  *
 */

#ifndef _GNSDK_STORAGE_SQLITE_H_
/* @internal gnsdk_storage_sqlite.h @endinternal
 * Primary interface for the SQLite SDK.
* @ingroup Storage_SQLITE_HeaderFile
*/
#define _GNSDK_STORAGE_SQLITE_H_

#include "gnsdk_manager.h"

#ifdef __cplusplus
extern "C"{
#endif

/** @internal gnsdk_storage_sqlite.h @endinternal
 * SQLite implementation of gnsdk_storage_provider_interface_t.
 *
 * @ingroup Storage_SQLITE_HeaderFile
*/

/******************************************************************************
 * Typdefs
 ******************************************************************************/

/******************************************************************************
 * GNSDK SQLite Initialization APIs
 ******************************************************************************/

/** @internal gnsdk_storage_sqlite_initialize @endinternal
*  Initializes the SQLite library.
*
*  After successful initialization, we recommended immediately setting a valid folder for local
*  storage - this must be set before this library will successfully begin operating.
*
*  It is possible to initialize this library at any time before or after other libraries have been
*  operating. However, to ensure that all queries are properly cached by this library, it should be
*  initialized immediately after the GNSDK Manager and before any other libraries.
*
*  <p><b>Important:</b></p>
*  You can specify the location of the SQLite database files by setting a valid storage folder path
*  using the #GNSDK_STORAGE_SQLITE_OPTION_STORAGE_FOLDER option with <code>gnsdk_storage_sqlite_option_set()</code>.
*
*  If this option is not specified the current working directory of the process will be used.
*
*  @param sdkmgr_handle [in] Handle from successful <code>gnsdk_manager_initialize</code> call
*  @return SQLITEERR_InvalidArg - Given <code>sdkmgr_handle</code> parameter is invalid
*  @return SQLITEERR_HandleObjectInvalid - Given <code>sdkmgr_handle</code> is not a valid GNSDK Manager handle
*  @return SQLITEERR_InitFailed - Initialization failed
*  @return SQLITEERR_NoError - Initialization succeeded
*
* @ingroup StorageandCaching_SQLITE_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_storage_sqlite_initialize(
	gnsdk_manager_handle_t	sdkmgr_handle
	);

/** @internal gnsdk_storage_sqlite_shutdown @endinternal
*  Shuts down and releases resources for the SQLite library.
*
*  All <code>gnsdk_storage_sqlite_shutdown()</code> calls must be paired with a previous call to
*  <code>gnsdk_storage_sqlite_initialize()</code>. The final <code>gnsdk_storage_sqlite_shutdown()</code>
*  call results in the library being shut down; all SQLite APIs cease to function until the library is
*  again initialized.
*
*  @return SQLITEERR_NotInited - <code>gnsdk_storage_sqlite_initialize</code> was not successfully initiated
*  @return SQLITEERR_NoError - Shut down succeeded
*
* @ingroup StorageandCaching_SQLITE_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_storage_sqlite_shutdown(void);

/** @internal gnsdk_storage_sqlite_get_version @endinternal
*  Retrieves the version string of the Storage SQLite library.
*
*  This API can be called at any time, even before initialization and after shutdown.
*
*  The returned string is a constant. Do not attempt to modify or delete.
*
*  Example: <code>1.2.3.123</code>
*
*  <code>Major.Minor.Improvement.Build</code><br>
*  Major: New functionality<br>
*  Minor: New or changed features<br>
*  Improvement: Improvements and fixes<br>
*  Build: Internal build number<br>
*
*  @return version string if successful
*  @return GNSDK_NULL if not successful
*
* @ingroup StorageandCaching_SQLITE_Functions
*/
gnsdk_cstr_t GNSDK_API
gnsdk_storage_sqlite_get_version(void);

/** @internal gnsdk_storage_sqlite_get_build_date @endinternal
*  Retrieves the build date string of the Storage SQLite library.
*
*  This API can be called at any time, even before initialization and after shutdown.
*
*  The returned string is a constant. Do not attempt to modify or delete.
*
*  Example build date string: <code>2008-02-12 00:41 UTC</code>
*
*  @return Build date string of the format: YYYY-MM-DD hh:mm UTC
*
* @ingroup StorageandCaching_SQLITE_Functions
*/
gnsdk_cstr_t GNSDK_API
gnsdk_storage_sqlite_get_build_date(void);

/** @internal gnsdk_storage_sqlite_get_sqlite_version @endinternal
*  Retrieves the version string of the SQLite database engine.
*
*  SQLite is a 3rd party database engine. Information on SQLite can be found at http://www.sqlite.org.
*
*  The SQLite library has its own version outside of the <code>gnsdk_storage_sqlite</code> module version. This
*  version is defined by the SQLite macro SQLITE_VERSION.
*
*  The returned string is a constant. Do not attempt to modify or delete.
*
*  @return GNSDK_NULL if not initialized
*  @return SQLite library version string
*
* @ingroup StorageandCaching_SQLITE_Functions
*/
gnsdk_cstr_t GNSDK_API
gnsdk_storage_sqlite_get_sqlite_version(void);

/** @internal gnsdk_storage_sqlite_option_set @endinternal
*  Sets an option specific to the Storage SQLite library. See @link StorageandCaching_SQLITE_OptionKeys 
*  SQLITE Option Keys@endlink for possible options.
*
*  @param option_name [in] One of the available SQLite option keys
*  @param option_value [in] Value to set for option name
*  @return SQLITEERR_NotInited - <code>gnsdk_storage_sqlite_initialize</code> was not successfully initiated
*  @return SQLITEERR_InvalidArg - Either the <code>option_name</code> or <code>option_value</code> parameter is empty or invalid
*  @return SQLITEERR_NoError - Option was successfully set
*
* @ingroup StorageandCaching_SQLITE_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_storage_sqlite_option_set(gnsdk_cstr_t option_name, gnsdk_cstr_t option_value);

/** @internal gnsdk_storage_sqlite_option_get @endinternal
*  Retrieves an option set to the Storage SQLite library. 
*
*  @param option_name [in] One of the available SQLite option keys
*  @param p_option_value [out] Pointer to receive the value set for option name
*  @return SQLITEERR_NotInited - <code>gnsdk_storage_sqlite_initialize()</code> was not successfully initiated
*  @return SQLITEERR_InvalidArg - Either the <code>option_name</code> or <code>p_option_value</code> parameter is empty or
invalid
*  @return SQLITEERR_NoError - Option was successfully retrieved
*
* @ingroup StorageandCaching_SQLITE_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_storage_sqlite_option_get(gnsdk_cstr_t option_name, gnsdk_cstr_t* p_option_value);

/** @internal GNSDK_STORAGE_SQLITE_OPTION_STORAGE_FOLDER @endinternal
*  Sets the folder path where storage file(s) can be created within or opened from.
*
*  If this option is not specified the current working directory of the process will be used.
*
*  The storage location must be a valid relative or absolute path to an existing folder that
*  has the necessary write permissions.
*
*  To set the path for an individual storage file, use gnsdk_lookup_local_storage_location_set().
*
* <p><b>Important:</b></p>
*  For Windows CE an absolute path must be used.
*
* @ingroup StorageandCaching_SQLITE_OptionKeys
*/
#define	GNSDK_STORAGE_SQLITE_OPTION_STORAGE_FOLDER		"gnsdk_storage_sqlite_storage_folder"

/** @internal GNSDK_STORAGE_SQLITE_OPTION_STORAGE_TEMPORARY_FOLDER @endinternal
*  Sets the folder path where temporary storage file(s) can be created within or opened from.
*
*  The temporary storage location must be a valid relative or absolute path to an existing 
*  folder that has the necessary write permissions. If this option is not specified, then the 
*  default directory for temporary files will be used. The default directory for temporary files 
*  depends on the OS.
*
* <p><b>Important:</b></p>
*  This option should only be set for platforms that do not have a default directory for 
*  temporary files. It is not safe to modify this option in more than one thread at a time.
*  It is intended that this option be set once after invoking gnsdk_storage_sqlite_initialize().
*
*  For Windows CE an absolute path must be used.
*  For Android this option must be set and an absolute path must be used.
*
* @ingroup StorageandCaching_SQLITE_OptionKeys
*/
#define	GNSDK_STORAGE_SQLITE_OPTION_STORAGE_TEMPORARY_FOLDER		"gnsdk_storage_sqlite_storage_temp_folder"

/** @internal GNSDK_STORAGE_SQLITE_OPTION_CACHE_FILESIZE @endinternal
*  Sets the maximum size the GNSDK cache can grow to; for example "100" for 100 Kb or "1024" for 1
*  MB. This limit applies to each cache that is created.
*
*  The value passed for this option is the maximum number of Kilobytes that the cache files can grow
*  to. For example, "100" sets the maximum to 100 KB, and "1024" sets the maximum to 1 MB.
*
*  If the cache files' current size already exceeds the maximum when this option is set, then the
*  set maximum is not applied.
*
*  When the maximum size is reached, new cache entries are not written to the database.
*  Additionally, a maintenance thread is run that attempts to clean up expired records from the
*  database and create space for new records.
*
*  If this option is not set the cache files default to having no maximum size.
*
*  For more information see the SQLite site definition of "PRAGMA page_size" and "PRAGMA max_page_count".
*  http://www.sqlite.org/pragma.html#pragma_page_size
*  http://www.sqlite.org/pragma.html#pragma_max_page_count
*
* @ingroup StorageandCaching_SQLITE_OptionKeys
*/
#define GNSDK_STORAGE_SQLITE_OPTION_CACHE_FILESIZE		"gnsdk_storage_sqlite_filesize"

/** @internal GNSDK_STORAGE_SQLITE_OPTION_CACHE_MEMSIZE @endinternal
*  Sets the maximum amount of memory SQLite can use to buffer cache data.
*
*  The value passed for this option is the maximum number of Kilobytes of memory that can be used.
*  For example, "100" sets the maximum to 100 KB, and "1024" sets the maximum to 1 MB.
*
*  Use this key as the <code>option_name</code> parameter with the <code>gnsdk_storage_sqlite_option_set()</code> or
*  <code>gnsdk_storage_sqlite_option_get()</code> functions.
*
*  For more information see the SQLite site definition of "PRAGMA cache_size".
*  http://www.sqlite.org/pragma.html#pragma_cache_size
*
* @ingroup StorageandCaching_SQLITE_OptionKeys
*/
#define	GNSDK_STORAGE_SQLITE_OPTION_CACHE_MEMSIZE		"gnsdk_storage_sqlite_memsize"

/** @internal GNSDK_STORAGE_SQLITE_OPTION_SYNCHRONOUS @endinternal
*  Sets the method that SQLite uses to write to the cache files.
*
*  This option is available for SQLite performance tuning. Valid values for this option are:
*  <ul>
*  <li>OFF (default setting): No synchronous writing; the quickest but least safe method.</li>
*  <li>NORMAL: Synchronous writing only at critical times; the generally quick and safe method.</li>
*  <li>FULL: Always synchronous writing; the slowest and safest method.</li>
*  </ul>
*
*  If the threat of losing a cache file due to hardware failure is high, then set this option in
*  your application to NORMAL or FULL.
*
*  For more information see the SQLite site definition of "PRAGMA synchronous".
*  http://www.sqlite.org/pragma.html#pragma_synchronous
*
* @ingroup StorageandCaching_SQLITE_OptionKeys
*/
#define	GNSDK_STORAGE_SQLITE_OPTION_SYNCHRONOUS			"gnsdk_storage_sqlite_synchronous"

/** @internal GNSDK_STORAGE_SQLITE_OPTION_JOURNAL_MODE @endinternal
*  Sets how the SQLite journal file is managed for database transactions.
*
*  This option is available for SQLite performance tuning. Valid values for this option are:
*  <ul>
*  <li>DELETE: Journal file is deleted after each transaction.</li>
*  <li>TRUNCATE: Journal file is truncated (but not deleted) after each transaction.</li>
*  <li>PERSIST: Journal file remains after each transaction.</li>
*  <li>MEMORY (default setting): Journal file is only stored in memory for each transaction.</li>
*  <li>OFF: No journaling is performed.</li>
*  </ul>
*
*  For more information see the SQLite site definition of "PRAGMA journal_mode".
*  http://www.sqlite.org/pragma.html#pragma_journal_mode
*
* @ingroup StorageandCaching_SQLITE_OptionKeys
*/
#define GNSDK_STORAGE_SQLITE_OPTION_JOURNAL_MODE		"gnsdk_storage_sqlite_journalmode"

/******************************************************************************
 * GNSDK SQLite Experimental APIs
 ******************************************************************************/

/** @internal gnsdk_storage_sqlite_use_external_library @endinternal
*  Indicates to sqlite that it should use the supplied SQLite3 shared library
*
*  <p><b>EXPERIMENTAL</b></p>
*
* If used, this must be called immediately before your call to <code>gnsdk_storage_sqlite_initialize</code>
*
*  <p><b>Important:</b></p>
*  Gracenote's instance of SQLite has been compiled with specific flags  to enable optional features of SQLite, 
*  if your version of SQLite is not built with these flags, it might not be usable with the GNSDK.
*       SQLITE_ENABLE_COLUMN_METADATA     
*       SQLITE_ENABLE_UNLOCK_NOTIFY        
*       SQLITE_OMIT_DEPRECATED            
*
*  @param sqlite3_filepath [in] path to SQLite3 shared library, or GNSDK_NULL
*  @return SQLITEERR_NoMemory	- Out of memory 
*  @return SQLITEERR_NoError	- External library was accepted
*
* @ingroup StorageandCaching_SQLITE_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_storage_sqlite_use_external_library(
	gnsdk_cstr_t			sqlite3_filepath
	);

/** @internal gnsdk_storage_sqlite_initialize_external_library @endinternal
*  Initializes the SQLite library, using the supplied SQLite3 shared library.
*
*  <p><b>EXPERIMENTAL</b></p>
*
*  After successful initialization, we recommended immediately setting a valid folder for local
*  storage - this must be set before this library will successfully begin operating.
*
*  It is possible to initialize this library at any time before or after other libraries have been
*  operating. However, to ensure that all queries are properly cached by this library, it should be
*  initialized immediately after the GNSDK Manager and before any other libraries.
*
*  <p><b>Important:</b></p>
*  You can specify the location of the SQLite database files by setting a valid storage folder path
*  using the #GNSDK_STORAGE_SQLITE_OPTION_STORAGE_FOLDER option with <code>gnsdk_storage_sqlite_option_set()</code>.
*
*  If this option is not specified the current working directory of the process will be used.
*
*  <p><b>Important:</b></p>
*  Gracenote's instance of SQLite has been compiled with specific flags  to enable optional features of SQLite, 
*  if your version of SQLite is not built with these flags, it might not be usable with the GNSDK.
*       SQLITE_ENABLE_COLUMN_METADATA     
*       SQLITE_ENABLE_UNLOCK_NOTIFY        
*       SQLITE_OMIT_DEPRECATED            
*
*  @param sdkmgr_handle [in] Handle from successful <code>gnsdk_manager_initialize</code> call
*  @param sqlite3_filepath [in] path to SQLite3 shared library
*  @return SQLITEERR_InvalidArg - Given <code>sdkmgr_handle</code> or <code>sqlite3_filepath</code> parameter is invalid
*  @return SQLITEERR_HandleObjectInvalid - Given <code>sdkmgr_handle</code> is not a valid GNSDK Manager handle
*  @return SQLITEERR_Unsupported - Given <code>sqlite3_filepath</code> is not a valid SQLite3 shared library
*  @return SQLITEERR_InitFailed - Initialization failed
*  @return SQLITEERR_NoError - Initialization succeeded
*
* @ingroup StorageandCaching_SQLITE_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_storage_sqlite_initialize_external_library(
	gnsdk_manager_handle_t	sdkmgr_handle,
	gnsdk_cstr_t			sqlite3_filepath
	);

#ifdef __cplusplus
}
#endif

#endif /* _GNSDK_STORAGE_SQLITE_H_ */

