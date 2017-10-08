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
 * gnsdk_errors.h - Definitions for error handling with GNSDK.
 */

#ifndef	_GNSDK_ERRORS_H_
#define _GNSDK_ERRORS_H_

/*
 * Background.
 */

/*
 * ERROR CODE FORMAT VERSION 1
 */
/*
 *  Gracenote SDK error codes (gnsdk_error_t) [version 1]
 *  are 32-bit values layed out as follows:
 *
 *   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
 *   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 *  +-+-----+-------+---------------+---------------+---------------+
 *  |s| ver | rsvd  |  package/lib  |          error code           |
 *  +-+-----+-----------------------+---------------+---------------+
 *
 *  where
 *
 *      s - severity
 *          0 - warning
 *          1 - failure
 *
 *      ver - version bits (value = 001).
 *
 *      rsvd - reserved portion of the error code.
 *
 *      package/lib - which library or package is the source of the error.
 *
 *      errror code - as defined in gnsdk_error_codes.h.
 */


/*
 * Dependencies.
 */

#ifdef __cplusplus
extern "C"{
#endif

/*
 * Constants.
 */
#define GNSDK_ERROR_VERSION             1

/* Generic value for success */
#define	GNSDK_SUCCESS                   0

/* Severity values */
#define GNSDK_SEVERITY_WARNING          0
#define GNSDK_SEVERITY_FAILURE          1

/* Offsets into error code */
#define	GNSDKERR_CODE_OFFSET            0
#define	GNSDKERR_PKG_OFFSET             16
#define	GNSDKERR_VER_OFFSET             28
#define	GNSDKERR_SEV_OFFSET             31

/* Masks for fields within error code */
#define	GNSDKERR_CODE_MASK              0x0000FFFF
#define	GNSDKERR_PKG_MASK               0x00FF0000
#define	GNSDKERR_VER_MASK               0x70000000
#define	GNSDKERR_SEV_MASK               0x80000000

/* Sizes (in bits) of fields within error code */
#define	GNSDKERR_CODE_SIZE              16
#define	GNSDKERR_PKG_SIZE               8
#define	GNSDKERR_VER_SIZE               3
#define	GNSDKERR_SEV_SIZE               1

#define GNSDKERR_CODE_RANGE             ((gnsdk_uint32_t)((1 << (GNSDKERR_CODE_SIZE + 1)) - 1))
#define GNSDKERR_PKG_RANGE              ((gnsdk_uint32_t)((1 << (GNSDKERR_PKG_SIZE + 1)) - 1))
#define GNSDKERR_VER_RANGE              ((gnsdk_uint32_t)((1 << (GNSDKERR_VER_SIZE + 1)) - 1))
#define GNSDKERR_SEV_RANGE              ((gnsdk_uint32_t)((1 << (GNSDKERR_SEV_SIZE + 1)) - 1))

/* Error descriptions */
#define	GNSDKERR_MAX_PACKAGE_STRING     32
#define	GNSDKERR_MAX_CODE_STRING        64
#define	GNSDKERR_MAX_MESSAGE_STRING     (GNSDKERR_MAX_PACKAGE_STRING + GNSDKERR_MAX_CODE_STRING + 64)


/*
 * Error assembly/disassembly
 */

/* Form error value from package id and error code */
#define	GNSDKERR_MAKE_ERROR(package_id,error_code)	\
\
	((gnsdk_error_t)(((gnsdk_uint32_t)(GNSDK_SEVERITY_FAILURE)               << (GNSDKERR_SEV_OFFSET)) | \
	                 ((gnsdk_uint32_t)(GNSDK_ERROR_VERSION)                  << (GNSDKERR_VER_OFFSET)) | \
	                 ((gnsdk_uint32_t)((package_id) & (GNSDKERR_PKG_RANGE))  << (GNSDKERR_PKG_OFFSET)) | \
	                 ((gnsdk_uint32_t)((error_code) & (GNSDKERR_CODE_RANGE)) << (GNSDKERR_CODE_OFFSET))))


	/* Form warning value from package id and error code */
#define	GNSDKERR_MAKE_WARNING(package_id,error_code)	\
\
	((gnsdk_error_t)(((gnsdk_uint32_t)(GNSDK_SEVERITY_WARNING)               << (GNSDKERR_SEV_OFFSET)) | \
	                 ((gnsdk_uint32_t)(GNSDK_ERROR_VERSION)                  << (GNSDKERR_VER_OFFSET)) | \
	                 ((gnsdk_uint32_t)((package_id) & (GNSDKERR_PKG_RANGE))  << (GNSDKERR_PKG_OFFSET)) | \
	                 ((gnsdk_uint32_t)((error_code) & (GNSDKERR_CODE_RANGE)) << (GNSDKERR_CODE_OFFSET))))


/* Extract error code */
#define	GNSDKERR_ERROR_CODE(error_code) \
\
	((gnsdk_uint16_t)((gnsdk_uint32_t)((error_code) & GNSDKERR_CODE_MASK) >> GNSDKERR_CODE_OFFSET))


/* Extract package id */
#define	GNSDKERR_PKG_ID(error_code) \
\
	((gnsdk_uint16_t)((gnsdk_uint32_t)((error_code) & GNSDKERR_PKG_MASK) >> GNSDKERR_PKG_OFFSET))


/* Extract severity code */
#define	GNSDKERR_SEVERE(error_code) \
\
	((gnsdk_uint16_t)((gnsdk_uint32_t)((error_code) & GNSDKERR_SEV_MASK) >> GNSDKERR_SEV_OFFSET))



#ifdef __cplusplus
}
#endif

#endif /* #ifndef _GNSDK_ERRORS_H_ */

