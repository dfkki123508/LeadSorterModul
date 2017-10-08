/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2014. Gracenote, Inc. All Rights Reserved.
 *
 */

/*
 * gnsdk_status.h - Definitions used by the Gracenote SDKs for status callbacks.
 */

#ifndef _GNSDK_STATUS_H_
#define _GNSDK_STATUS_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @internal gnsdk_status_t @endinternal
 *  Indicates messages that can be received in status callbacks.
 * @ingroup StatusCallbacks_TypesEnums
 */
typedef enum
{
/** @internal gnsdk_status_unknown @endinternal
 * Status unknown.
 * @ingroup StatusCallbacks_TypesEnums
 */
	gnsdk_status_unknown = 0,

	/* Basic messages */

/** @internal gnsdk_status_begin @endinternal
 * Issued once per application function call, at the beginning of the call; percent_complete = 0.
 * @ingroup StatusCallbacks_TypesEnums
 */
	gnsdk_status_begin,

/** @internal gnsdk_status_progress @endinternal
 * Issued roughly 10 times per application function call; percent_complete values between 1-100.
 * @ingroup StatusCallbacks_TypesEnums
 */
	gnsdk_status_progress,

/** @internal gnsdk_status_complete @endinternal
 * Issued once per application function call, at the end of the call; percent_complete = 100.
 * @ingroup StatusCallbacks_TypesEnums
 */
	gnsdk_status_complete,

/** @internal gnsdk_status_error_info @endinternal
 * Issued when an error is encountered. If sent, call #gnsdk_manager_error_info().
 * @ingroup StatusCallbacks_TypesEnums
 */
	gnsdk_status_error_info,

	/* Advanced messages */

/** @internal gnsdk_status_connecting @endinternal
 * Issued when connecting to network.
 * @ingroup StatusCallbacks_TypesEnums
 */
	gnsdk_status_connecting,

/** @internal gnsdk_status_sending @endinternal
 * Issued when uploading.
 * @ingroup StatusCallbacks_TypesEnums
 */
	gnsdk_status_sending,

/** @internal gnsdk_status_receiving @endinternal
 * Issued when downloading.
 * @ingroup StatusCallbacks_TypesEnums
 */
	gnsdk_status_receiving,

/** @internal gnsdk_status_disconnected @endinternal
 * Issued when disconnected from network.
 * @ingroup StatusCallbacks_TypesEnums
 */
	gnsdk_status_disconnected,

/** @internal gnsdk_status_reading @endinternal
 * Issued when reading from storage.
 * @ingroup StatusCallbacks_TypesEnums
 */
	gnsdk_status_reading,

/** @internal gnsdk_status_writing @endinternal
 * Issued when writing to storage.
 * @ingroup StatusCallbacks_TypesEnums
 */
	gnsdk_status_writing,            /* issued whenever writing to storage. */

/** @internal gnsdk_status_cancelled @endinternal
 * Issued when transaction/query is cancelled
 * @ingroup StatusCallbacks_TypesEnums
 */
	gnsdk_status_cancelled            

} gnsdk_status_t;

/** @internal gnsdk_status_callback_fn @endinternal
 * Status callback function to receive status updates as operations are performed.
 * @param callback_data [in] Optional, application-provided user data
 * @param status [in] Status message
 * @param percent_complete [in] Percentage of operation complete
 * @param bytes_total_sent [in] Total bytes sent
 * @param bytes_total_received [in] Total bytes received
 * @param p_abort [in] Allows applications to abort processing and return from the function
 * @ingroup StatusCallbacks_Callbacks
 */
typedef gnsdk_void_t
(GNSDK_CALLBACK_API * gnsdk_status_callback_fn)(
	gnsdk_void_t*  callback_data,
	gnsdk_status_t status,
	gnsdk_uint32_t percent_complete,
	gnsdk_size_t   bytes_total_sent,
	gnsdk_size_t   bytes_total_received,
	gnsdk_bool_t*  p_abort
	);

#ifdef __cplusplus
}
#endif
#endif /* _GNSDK_STATUS_H_ */
