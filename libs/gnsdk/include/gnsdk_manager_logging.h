/*
  *
  *  GRACENOTE, INC. PROPRIETARY INFORMATION
  *  This software is supplied under the terms of a license agreement or
  *  nondisclosure agreement with Gracenote, Inc. and may not be copied
  *  or disclosed except in accordance with the terms of that agreement.
  *  Copyright(c) 2000-2013. Gracenote, Inc. All Rights Reserved.
  *
 */

/* gnsdk_manager_logging.h: Primary interface for the GNSDK Manager.
*/

#ifndef _GNSDK_MANAGER_LOGGING_H_
#define _GNSDK_MANAGER_LOGGING_H_

#include <stdarg.h> /* for va_list */
#include "gnsdk_manager.h"

#ifdef __cplusplus
extern "C"{
#endif


/******************************************************************************
 * SDK Manager Logging APIs
 ******************************************************************************/

/** @internal gnsdk_manager_logging_register_package @endinternal
*  Register a new Package ID to allow custom logging for your application.
*  @param package_id [in] Package ID to register.
*  @param package_name [in] Short name or description that appears in the log entries for this
package.
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_NoError Package ID was successfully registered for logging
*  <p><b>Remarks:</b></p>
*  This function allows an application to register one or more of its own package IDs into the GNSDK
logging system. The application can then enable, disable or filter its own logging messages based on
the registered package IDs. Applications can write their own log messages using
gnsdk_manager_logging_write or gnsdk_manager_logging_vwrite.
*  The package_id must be in the range GNSDKPKG_ID_APP_START to GNSDKPKG_ID_APP_MAX.
* @ingroup Setup_Logging_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_logging_register_package(
	gnsdk_uint16_t						package_id,
	gnsdk_cstr_t						package_name
	);

/** @internal gnsdk_manager_logging_enable @endinternal
*  Enables or changes logging settings of GNSDK messages for a specific log file.
*  @param log_file_path [in] Path and file name to log messages to
*  @param package_id [in] ID of package to filter log messages for this log
*  @param filter_mask [in] Filter mask for type of message to log
*  @param options_mask [in] Formatting options for this log
*  @param max_size [in] Maximum size of log before new log is created. Enter a value of zero (0) to
always create new log on open
*  @param b_archive [in] Specify GNSDK_TRUE for the archive to retain and rename old logs, or
GNSDK_FALSE to delete old logs
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_NoError Logging was successfully enabled for a given file
*  <p><b>Remarks:</b></p>
*  The GNSDK logging system allows multiple logs to be enabled simultaneously. Each call to
gnsdk_manager_logging_enable with a new log_file_path parameter will enable a new log. Filter
and option settings are set per Package ID. Multiple Package IDs can be enabled per log file
by calling this API multiple times with different Package IDs. The packages, filter and option
parameter will apply only to the log indicated by log_file_path.
*  If the log_file_path parameter matches an existing enabled log, then the package, filter and
option settings will be applied to the existing log file. These changes can be applied at run time.
* Windows CE developers: log_file_path parameter must be absolute path as relative paths are not supported
in Windows CE.
* @ingroup Setup_Logging_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_logging_enable(
	gnsdk_cstr_t						log_file_path,
	gnsdk_uint16_t						package_id,
	gnsdk_uint32_t						filter_mask,
	gnsdk_uint32_t						options_mask,
	gnsdk_uint64_t						max_size,
	gnsdk_bool_t						b_archive
	);

/** @internal gnsdk_manager_logging_callback_fn @endinternal
*  Manually manage Gracenote SDK logging messages.
*  @param callback_data [in] Pointer to data passed in to the gnsdk_manager_logging_enable_callback
function through the callback_data parameter. This pointer must be cast from the gnsdk_void_t
type to its original type to be accessed properly.
*  @param package_id [in] ID of package sending the log message
*  @param filter_mask [in] Filter mask of the type of log message
*  @param error_code [in] Error code (if any) relating to log message
*  @param message [in] The log message
*  <p><b>Remarks:</b></p>
*  This callback can be supplied to gnsdk_manager_logging_enable_callback.
* @ingroup Setup_Logging_Callback
*/
typedef gnsdk_void_t
(GNSDK_CALLBACK_API *gnsdk_manager_logging_callback_fn)(
	gnsdk_void_t*						callback_data,
	gnsdk_uint16_t						package_id,
	gnsdk_uint32_t						filter_mask,
	gnsdk_uint32_t						error_code,
	gnsdk_cstr_t						message
	);

/** @internal gnsdk_manager_logging_enable_callback @endinternal
*  Enables application callback that receives all logging messages.
*  @param callback [in] Callback function for logging message
*  @param callback_data [in_opt] Data that is passed back through calls to the callback function
*  @param package_id [in] ID of package to filter log messages for the callback
*  @param filter_mask [in] Filter mask for type of messages to send to callback
*  @param options_mask [in] Formatting options for the log message sent to callback
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_NoError Logging callback was successfully enabled
*  <p><b>Remarks:</b></p>
*  The GNSDK logging system allows logging message to be routed to a callback function. The logging
callback can be enabled along side or instead of file logging. Multiple Package IDs can be enabled
by calling this API multiple times with different Package IDs. The package and filter
will apply only to the logging message sent to the callback.
*  To disable the logging callback, call gnsdk_manager_logging_enable_callback with the callback
parameter set to GNSDK_NULL for each enabled PackageID.
* @ingroup Setup_Logging_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_logging_enable_callback(
	gnsdk_manager_logging_callback_fn	callback,
	gnsdk_void_t*						callback_data,
	gnsdk_uint16_t						package_id,
	gnsdk_uint32_t						filter_mask,
	gnsdk_uint32_t						options_mask
	);

/** @internal gnsdk_manager_logging_disable @endinternal
*  Disables logging of GNSDK messages.
*  @param log_file_path [in] Absolute path and file name of log to apply this disable
*  @param package_id [in] ID of package to to disable messages for
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_NoError Logging for a given file was successfully disabled
*  <p><b>Remarks:</b></p>
*  This disables logging to the given log file for the given package ID. The file handle for the log
file may not be closed until the GNSDK Manager is shut down.
* @ingroup Setup_Logging_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_logging_disable(
	gnsdk_cstr_t						log_file_path,
	gnsdk_uint16_t						package_id
	);

/** @internal gnsdk_manager_logging_write @endinternal
*  Enables an application to write to a log for its own messages.
*  @param line [in_opt] Source line number of this call
*  @param filename [in_opt] Source file name of this call
*  @param package_id [in] Package ID of application making call
*  @param filter_mask [in] Error mask for this logging message
*  @param format [in] Error message format (using printf style parameters for the format string)
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_NoError Logging function successfully called; however, message may not have
been written due to enabled filters
*  <p><b>Remarks:</b></p>
*  This function enables an application to write their own logging messages to the GNSDK logging
system. If a log or callback is enabled that is handling the given package ID and filter mask, then
these message are written to those logs. The package ID must be one registered by the application
with gnsdk_manager_logging_register_package().
* @ingroup Setup_Logging_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_logging_write(
	gnsdk_int32_t						line,
	gnsdk_cstr_t						filename,
	gnsdk_uint16_t						package_id,
	gnsdk_uint32_t						filter_mask,
	gnsdk_cstr_t						format,
	...
	);

/** @internal gnsdk_manager_logging_vwrite @endinternal
*  Enables an application to write to a log for its own messages. This API uses the var_args
parameter for variables in format string.
*  @param line [in_opt] Source line number of this call
*  @param filename [in_opt] Source file name of this call
*  @param package_id [in] Package ID of application making call
*  @param filter_mask [in] Error mask for this logging message
*  @param format [in] Error message format
*  @param argptr [in] Error message format arguments
*  @return SDKMGRERR_NotInited gnsdk_manager_initialize was not successfully initiated
*  @return SDKMGRERR_NoError Logging function successfully called; however, message may not have
been written due to enabled filters
*  <p><b>Remarks:</b></p>
*  This function enables an application to write their own logging messages to the GNSDK logging
system. If a log or callback is enabled that handles the given package ID and filter mask, then
these message are written to those log(s). The package ID must be one registered by the application
with gnsdk_manager_logging_register_package().
* @ingroup Setup_Logging_Functions
*/
gnsdk_error_t GNSDK_API
gnsdk_manager_logging_vwrite(
	gnsdk_int32_t						line,
	gnsdk_cstr_t						filename,
	gnsdk_uint16_t						package_id,
	gnsdk_uint32_t						filter_mask,
	gnsdk_cstr_t						format,
	va_list								argptr
	);


/*
 * Logging package IDs
 */

/** @internal GNSDK_LOG_PKG_ALL @endinternal
*  Indicates all package IDs.
* @ingroup Setup_Logging_FilterPackage
*/
#define		GNSDK_LOG_PKG_ALL				0xFF
/** @internal GNSDK_LOG_PKG_GCSL @endinternal
*  Indicates all low level Gracenote Client Standard Library (GCSL) package IDs.
* @ingroup Setup_Logging_FilterPackage
*/
#define		GNSDK_LOG_PKG_GCSL				0x7E
/** @internal GNSDK_LOG_PKG_GNSDK @endinternal
*  Indicates all GNSDK package IDs.
* @ingroup Setup_Logging_FilterPackage
*/
#define		GNSDK_LOG_PKG_GNSDK				0xFE

/*
 * Logging Filter masks
 */

/** @internal GNSDK_LOG_FILTER_ERROR @endinternal
*  Log errors
* @ingroup Setup_Logging_Filters
*/
#define GNSDK_LOG_FILTER_ERROR				0x00000001
/** @internal GNSDK_LOG_FILTER_WARNING @endinternal
*  Log warnings
* @ingroup Setup_Logging_Filters
*/
#define GNSDK_LOG_FILTER_WARNING			0x00000002
/** @internal GNSDK_LOG_FILTER_INFO @endinternal
*  Log information messages
* @ingroup Setup_Logging_Filters
*/
#define GNSDK_LOG_FILTER_INFO				0x00000004
/** @internal GNSDK_LOG_FILTER_DEBUG @endinternal
*  Log debug messages
* @ingroup Setup_Logging_Filters
*/
#define GNSDK_LOG_FILTER_DEBUG				0x00000008


/** @internal GNSDK_LOG_LEVEL_ERROR @endinternal
*  Error level logging
* @ingroup Setup_Logging_Filters
*/
#define		GNSDK_LOG_LEVEL_ERROR			(GNSDK_LOG_FILTER_ERROR)
/** @internal GNSDK_LOG_LEVEL_WARNING @endinternal
*  Log Warnings and Errors
* @ingroup Setup_Logging_Filters
*/
#define		GNSDK_LOG_LEVEL_WARNING			(GNSDK_LOG_FILTER_WARNING|GNSDK_LOG_FILTER_ERROR)
/** @internal GNSDK_LOG_LEVEL_INFO @endinternal
*  Log Information messages, warnings and errors
* @ingroup Setup_Logging_Filters
*/
#define		GNSDK_LOG_LEVEL_INFO			(GNSDK_LOG_FILTER_INFO|GNSDK_LOG_FILTER_WARNING|GNSDK_LOG_FILTER_ERROR)
/** @internal GNSDK_LOG_LEVEL_DEBUG @endinternal
*  Log Debug messages, information, warnings and errors
* @ingroup Setup_Logging_Filters
*/
#define		GNSDK_LOG_LEVEL_DEBUG			(GNSDK_LOG_FILTER_DEBUG|GNSDK_LOG_FILTER_INFO|GNSDK_LOG_FILTER_WARNING|GNSDK_LOG_FILTER_ERROR)
/** @internal GNSDK_LOG_LEVEL_ALL @endinternal
*  Log all messages
* @ingroup Setup_Logging_Filters
*/
#define		GNSDK_LOG_LEVEL_ALL				GNSDK_LOG_LEVEL_DEBUG

/*
 * Logging option masks
 */

/** @internal GNSDK_LOG_OPTION_TIMESTAMP @endinternal
*  Includes a log creation timestamp of the format: Wed Jan 30 18:56:37 2008
* @ingroup Setup_Logging_Options
*/
#define		GNSDK_LOG_OPTION_TIMESTAMP		0x01000000
/** @internal GNSDK_LOG_OPTION_CATEGORY @endinternal
*  Categorizes the log entries by headings such as ERROR, INFO, and so on.
* @ingroup Setup_Logging_Options
*/
#define		GNSDK_LOG_OPTION_CATEGORY		0x02000000
/** @internal GNSDK_LOG_OPTION_PACKAGE @endinternal
*  Includes the Package Name, or the Package ID if the name is unavailable.
* @ingroup Setup_Logging_Options
*/
#define		GNSDK_LOG_OPTION_PACKAGE		0x04000000
/** @internal GNSDK_LOG_OPTION_THREAD @endinternal
*  Includes the Thread ID.
* @ingroup Setup_Logging_Options
*/
#define		GNSDK_LOG_OPTION_THREAD			0x08000000
/** @internal GNSDK_LOG_OPTION_SOURCEINFO @endinternal
*  Includes the source information in the format
* @ingroup Setup_Logging_Options
*/
#define		GNSDK_LOG_OPTION_SOURCEINFO		0x10000000
/** @internal GNSDK_LOG_OPTION_NEWLINE @endinternal
*  Includes a trailing newline in the format: "\r\n"
* @ingroup Setup_Logging_Options
*/
#define		GNSDK_LOG_OPTION_NEWLINE		0x20000000
/** @internal GNSDK_LOG_OPTION_NONE @endinternal
*  Indicates to not include any extra information in the log.
* @ingroup Setup_Logging_Options
*/
#define		GNSDK_LOG_OPTION_NONE			0x00000000
/** @internal GNSDK_LOG_OPTION_ALL @endinternal
*  Includes all log formatting options.
* @ingroup Setup_Logging_Options
*/
#define		GNSDK_LOG_OPTION_ALL			0xFF000000

/** @internal GNSDK_LOG_OPTION_SYNCHRONOUS @endinternal
*  Write to the log synchronously (on the same thread). By default
*  logs are written to asynchronously. No internal logging thread
*  is created if all logs are opened for synchronous writing.
* @ingroup Setup_Logging_Options
*/
#define		GNSDK_LOG_OPTION_SYNCHRONOUS	0x00100000
/** @internal GNSDK_LOG_OPTION_ARCHIVEDAILY @endinternal
*  When b_archive parameter is TRUE on call to gnsdk_manager_logging_enable
*  having this option will cause the logs to archive (roll) at the start of 
*  each day (12:00 midnight). Archiving by the given size parameter will 
*  still occur normally as well.
* @ingroup Setup_Logging_Options
*/
#define		GNSDK_LOG_OPTION_ARCHIVEDAILY	0x00200000


#ifdef __cplusplus
}
#endif

#endif /** @internal _GNSDK_MANAGER_LOGGING_H_ @endinternal
*  Primary interface for the GNSDK Manager.
*/

