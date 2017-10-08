/*
  *
  *  GRACENOTE, INC. PROPRIETARY INFORMATION
  *  This software is supplied under the terms of a license agreement or
  *  nondisclosure agreement with Gracenote, Inc. and may not be copied
  *  or disclosed except in accordance with the terms of that agreement.
  *  Copyright(c) 2000-2013. Gracenote, Inc. All Rights Reserved.
  *
 */

#ifndef _GNSDK_LOOKUP_LOCALSTREAM_H_
#define _GNSDK_LOOKUP_LOCALSTREAM_H_

#include "gnsdk_manager.h"

#ifdef __cplusplus
extern "C"{
#endif


/******************************************************************************
 * Initialization APIs
 ******************************************************************************/
 
/** @internal gnsdk_lookup_localstream_initialize @endinternal
  * Initializes the Lookup Local Stream module.
  * This function must be successfully called before any calls to other Lookup Local Stream APIs will succeed.
  * @param sdkmgr_handle [in] Handle from a successful gnsdk_manager_initialize() call.
  *
  * @return GNSDK_SUCCESS Initialization succeeded
  * @return error Initialization failed
  *
  * @ingroup Music_LookupLocalStream_InitializationFunctions 
*/	
gnsdk_error_t GNSDK_API
gnsdk_lookup_localstream_initialize(
	gnsdk_manager_handle_t sdkmgr_handle
	);
	
/** @internal gnsdk_lookup_localstream_shutdown @endinternal
  * Shuts down and release resources for the Lookup Local Stream module.
  * gnsdk_lookup_localstream_shutdown must be called to shutdown this module;
  * all Lookup Local APIs cease to function until the module is again initialized.
  * @return GNSDK_SUCCESS Shutdown succeeded
  * @return error Shutdown failed
  *
  * @ingroup Music_LookupLocalStream_InitializationFunctions 
*/	
gnsdk_error_t GNSDK_API
gnsdk_lookup_localstream_shutdown(void);

/** @internal gnsdk_lookup_localstream_get_version @endinternal
  * Retrieves the Lookup Local Stream module version string.
  * This API can be called at any time, even before initialization and after shutdown.
  * @return  Returns the version string for this module
  *
  * @ingroup Music_LookupLocalStream_InitializationFunctions 
*/	
gnsdk_cstr_t GNSDK_API
gnsdk_lookup_localstream_get_version(void);

/** @internal gnsdk_lookup_localstream_get_build_date @endinternal
  * Retrieves the Lookup Local Stream module's build date string.
  * This API can be called at any time, even before initialization and after shutdown.
  * @return Returns the build date string for this module
  *
  * @ingroup Music_LookupLocalStream_InitializationFunctions 
*/	
gnsdk_cstr_t GNSDK_API
gnsdk_lookup_localstream_get_build_date(void);


/******************************************************************************
 * Lookup LocalStream Options
 ******************************************************************************/

/** @internal gnsdk_lookup_localstream_option_set @endinternal
  *  Sets an option for the initialized Lookup Local Stream Library.
  *  @param option_key   [in] An option from the available query options 
  *									defined here
  *  @param option_value [in] String value or one of Lookup Local Stream Option Values that corresponds to
									option key
  *  @return LSTRERR_NotInited gnsdk_lookup_localstream_initialize was not successfully initiated
  *  @return LSTRERR_InvalidArg Given value for option_key or option_value parameter is invalid
  *  @return LSTRERR_NoError Option was successfully set gnsdk_lookup_localstream_option_set
  * @ingroup Music_LookupLocalStream_OptionFunctions 
*/	
gnsdk_error_t GNSDK_API
gnsdk_lookup_localstream_option_set(gnsdk_cstr_t option_name, gnsdk_cstr_t option_value);

/** @internal gnsdk_lookup_localstream_option_get @endinternal
  *  Retrieves an option for the initialized Lookup Local Stream Library.
  *  @param option_key   [in] An option from the available query options 
  *									defined here
  *  @param p_option_value [out] Pointer to receive option value
  *  @return LSTRERR_InvalidArg Given value for option_key is invalid or given value for
  p_option_value parameter is null
  *  @return LSTRERR_NoError Option was successfully retrieved
  * @ingroup Music_LookupLocalStream_OptionFunctions 
*/	
gnsdk_error_t GNSDK_API
gnsdk_lookup_localstream_option_get(gnsdk_cstr_t option_name, gnsdk_cstr_t* p_option_value);

/********************************************************************************
 * GNSDK_LOOKUP_LOCALSTREAM_OPTION_* values
 ******************************************************************************/

/** @internal GNSDK_LOOKUP_LOCALSTREAM_OPTION_ENGINE_TYPE @endinternal
  *  Sets or Retrieves the Lookup Local Stream engine type value 
  * @ingroup Music_LookupLocalStream_OptionFunctions 
*/	
#define GNSDK_LOOKUP_LOCALSTREAM_OPTION_ENGINE_TYPE		"gnsdk_localstream_option_engine"

/********************************************************************************
 * GNSDK_LOOKUP_LOCALSTREAM_OPTION_* values
 ******************************************************************************/

/** @internal GNSDK_LOOKUP_LOCALSTREAM_ENGINE_MMAP @endinternal
  *  Sets Lookup Local Stream Library to operate in Memory-Mapped Mode.
  *  GNSDK_LOOKUP_LOCALSTREAM_ENGINE_MMAP
  * @ingroup Music_LookupLocalStream_OptionValues
*/
#define		GNSDK_LOOKUP_LOCALSTREAM_ENGINE_MMAP			"gnsdk_localstream_engine_mmap"

/** @internal GNSDK_LOOKUP_LOCALSTREAM_ENGINE_INMEMORY @endinternal
  *  Sets Lookup Local Stream Library to operate in In-Memory Mode.
  *  GNSDK_LOOKUP_LOCALSTREAM_ENGINE_INMEMORY
  * @ingroup Music_LookupLocalStream_OptionValues
*/
#define		GNSDK_LOOKUP_LOCALSTREAM_ENGINE_INMEMORY		"gnsdk_localstream_engine_inmem"


/******************************************************************************
 * Lookup fingerprint local storage management APIs
 ******************************************************************************/

/********************************************************************************
 * Typedefs
 ******************************************************************************/

/** @internal gnsdk_lookup_localstream_ingest_handle_t @endinternal
  *  Handle to Lookup Local Stream Ingest Handle for Lookup Local Stream. The application 
		creates this handle for each Lookup Local Stream Ingestion Process.
  *  <p><b>Remarks:</b></p>
  *  An application may create as many of these handles as needed using
		gnsdk_lookup_localstream_ingest_create()
* @ingroup Music_LookupLocalStream_TypesEnums
*/

GNSDK_DECLARE_HANDLE(gnsdk_lookup_localstream_ingest_handle_t);

/********************************************************************************
 * Callbacks
 *
 * The Lookup Local Stream SDK can use callbacks to report ingestion status.
 * Use of these callbacks is optional.
 ******************************************************************************/

/** @internal gnsdk_lookup_localstream_status @endinternal
*  Status codes passed to the gnsdk_lookup_localstream_status_fn() callback.
* @ingroup Music_LookupLocalStream_TypesEnums	
*/	
typedef enum
{	
	gnsdk_lookup_localstream_status_invalid = 0,
	
	/** @internal gnsdk_lookup_localstream_status_item_begin @endinternal
	  *
	  *   Lookup Local Stream ingest processing is beginning for a given bundle.
	  * @ingroup Music_LookupLocalStream_TypesEnums
	*/	
	gnsdk_lookup_localstream_status_item_begin,
	
	/** @internal gnsdk_lookup_localstream_status_item_add @endinternal
	  *
	  *   Lookup Local Stream ingest processing is adding a bundle item.
	  * @ingroup Music_LookupLocalStream_TypesEnums
	*/		
	gnsdk_lookup_localstream_status_item_add,
	
	/** @internal gnsdk_lookup_localstream_status_item_delete @endinternal
	  *
	  *   Lookup Local Stream ingest processing is deleting a bundle item.
	  * @ingroup Music_LookupLocalStream_TypesEnums
	*/	
	gnsdk_lookup_localstream_status_item_delete

} gnsdk_lookup_localstream_status_t;

/** @internal gnsdk_lookup_localstream_status_fn @endinternal
  *  Callback function declaration for Lookup Local Stream Ingest progress status.
  *  @param callback_data [in_opt] Value passed to the callback_data parameter of the function this callback was
passed to
  *  @param status [in] One of gnsdk_lookup_localstream_status_t values
  *  @param bundle_id [in] Current bundle id being processed
  *  @param p_abort [out] Set dereferenced value to GNSDK_TRUE to abort the operation that is calling
the callback

* @ingroup Music_LookupLocalStream_Callbacks	
*/	

typedef gnsdk_void_t (GNSDK_CALLBACK_API* gnsdk_lookup_localstream_status_fn)(
	gnsdk_void_t*						callback_data,
	gnsdk_lookup_localstream_status_t	status,
	gnsdk_cstr_t						bundle_id,
	gnsdk_bool_t*						p_abort
	);
	
/** @internal gnsdk_lookup_localstream_ingest_create @endinternal
  * Creates a local lookup stream ingest handle.
  *
  * You need to create local lookup stream ingest handle before using other
  *		ingestion related APIs.
  * @param callback [in_opt] Callback function for status
  * @param callback_data [in_opt] Data that is passed back through calls to the callback
  * @param ph_ingest_handle [out] Pointer to receive the Local Lookup Stream Ingest handle
  * @return GNSDK_SUCCESS
  * @return error
  * @ingroup Music_LookupLocalStream_IngestFunctions	
*/	
gnsdk_error_t GNSDK_API
gnsdk_lookup_localstream_ingest_create(
	gnsdk_lookup_localstream_status_fn				callback,
	gnsdk_void_t*									callback_data,
	gnsdk_lookup_localstream_ingest_handle_t*		ph_ingest_handle	
	);
	
/** @internal gnsdk_lookup_localstream_ingest_write @endinternal
  * Writes a buffer of data to Local Lookup Stream Ingestion handle for
  *		Ingestion.
  *
  * @param h_ingest_handle [in] Local Lookup Stream Ingest handle
  * @param p_ingest_data [in] Pointer to data that will be ingested through the Local Lookup Stream Ingestion Handle
  * @param data_size [in] Size of data to be ingested
  * @return GNSDK_SUCCESS
  * @return error
* @ingroup Music_LookupLocalStream_IngestFunctions	
*/	
gnsdk_error_t GNSDK_API
gnsdk_lookup_localstream_ingest_write(
	gnsdk_lookup_localstream_ingest_handle_t		h_ingest_handle,	
	gnsdk_void_t*									p_ingest_data,
	gnsdk_size_t									data_size
	);
	
/** @internal gnsdk_lookup_localstream_ingest_flush @endinternal
  * Flush all data yet to be written to the static storage in the Local Lookup Stream Ingestion handle to
  *		make sure all data are being ingested.
  *
  * @param h_ingest_handle [in] Local Lookup Stream Ingest handle
  *
  * @return GNSDK_SUCCESS
  * @return error
* @ingroup Music_LookupLocalStream_IngestFunctions	
*/	
gnsdk_error_t GNSDK_API
gnsdk_lookup_localstream_ingest_flush(
	gnsdk_lookup_localstream_ingest_handle_t		h_ingest_handle
	);
	
/** @internal gnsdk_lookup_localstream_ingest_release @endinternal
  * Invalidates and releases resources for a given Local Lookup Stream ingestion handle.
  *
  * @param h_ingest_handle [in] Local Lookup Stream Ingest handle
  *
  * @return GNSDK_SUCCESS
  * @return error
* @ingroup Music_LookupLocalStream_IngestFunctions	
*/	
gnsdk_error_t GNSDK_API
gnsdk_lookup_localstream_ingest_release(
	gnsdk_lookup_localstream_ingest_handle_t		h_ingest_handle
	);

/** @internal gnsdk_lookup_localstream_storage_location_set @endinternal
  * Sets the static storage location for the data being ingested.
  * <p><b>Remarks:</b></p>
  *  The storage location path can be absolute or relative.
  *  However, Windows CE developers will need to set the full path, since relative path is not supported in Windows CE.
  * 
  * @param storage_location [in] String value of path to indicate location of storage
  * @return GNSDK_SUCCESS
  * @return error
* @ingroup Music_LookupLocalStream_StorageFunctions	
*/	
gnsdk_error_t GNSDK_API
gnsdk_lookup_localstream_storage_location_set(
	gnsdk_cstr_t									storage_location
	);
	
/** @internal gnsdk_lookup_localstream_storage_clear @endinternal
  * Clears all ingested data in the set static storage location.
  * 
  * @return GNSDK_SUCCESS
  * @return error
* @ingroup Music_LookupLocalStream_StorageFunctions	
*/	
gnsdk_error_t GNSDK_API
gnsdk_lookup_localstream_storage_clear(				void
	);

/** @internal gnsdk_lookup_localstream_storage_remove @endinternal  
  * Removes a single item from the ingested data in the set static storage location.
  * 
  * @param bundle_id [in] String value of the bundle id to be removed.
  * @return GNSDK_SUCCESS
  * @return error
  * @ingroup Music_LookupLocalStream_StorageFunctions	
*/	
gnsdk_error_t GNSDK_API
gnsdk_lookup_localstream_storage_remove(
	gnsdk_cstr_t									bundle_id
	);


#ifdef __cplusplus
}
#endif

#endif /* _GNSDK_LOOKUP_LOCALSTREAM_H_ */

