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
 * gnsdk_defines.h - The type definitions used by the gracenote SDKs
 * and the definition of macros.
 */

#ifndef	_GNSDK_DEFINES_H_
#define _GNSDK_DEFINES_H_

#ifdef __cplusplus
	/* C++ likes these better */
	#define GNSDK_NULL		(0)
	#define GNSDK_EXTERN_C	extern "C"
	extern "C" {
#else
	#define GNSDK_EXTERN_C
#endif

/* include platform dependent definitions first */
#include "gnsdk_platform.h"

/* Assert disable */
#ifdef GNSDK_NOASSERT
	#undef GNSDK_ASSERT
	#define GNSDK_ASSERT(exp)
#endif

/* Unused parameter/variable declaration */
#ifndef GNSDK_ENABLE_UNUSED_WARNING
	#define GNSDK_UNUSED(x)	(void)(x)
#else
	#define GNSDK_UNUSED(x)
#endif

/*
 * Constants.
 */
#ifndef GNSDK_FALSE
#define GNSDK_FALSE			((gnsdk_bool_t)(0))
#endif

#ifndef GNSDK_TRUE
#define GNSDK_TRUE			((gnsdk_bool_t)(1))
#endif

#ifndef GNSDK_NULL
#define GNSDK_NULL			((gnsdk_void_t*)0)
#endif

#ifndef GNSDK_VALUE_TRUE
#define	GNSDK_VALUE_TRUE	"1"
#endif

#ifndef GNSDK_VALUE_FALSE
#define GNSDK_VALUE_FALSE	"0"
#endif

#ifndef	GNSDK_MAX_PATH
#define	GNSDK_MAX_PATH		260
#endif

/* byte swapping helpers */
#ifndef GNSDK_BSWAP_32
#define GNSDK_BSWAP_32(x)		((((x) & 0xFF000000) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | (((x) & 0x000000FF) << 24) )
#endif
#ifndef GNSDK_BSWAP_16
#define GNSDK_BSWAP_16(x)		((((x) & 0xFF00) >> 8) | (((x) & 0x00FF) << 8))
#endif

/*
 * Typedef
 */

#ifndef GNSDK_VOID_T
#define GNSDK_VOID_T
typedef void gnsdk_void_t;
#endif /* GNSDK_VOID_T */

#ifndef GNSDK_CHAR_T
#define GNSDK_CHAR_T
typedef char gnsdk_char_t;
#endif /* GNSDK_CHAR_T */

#ifndef GNSDK_BYTE_T
#define GNSDK_BYTE_T
typedef unsigned char gnsdk_byte_t;
#endif /* GNSDK_BYTE_T */

#ifndef GNSDK_INT8_T
#define GNSDK_INT8_T
typedef signed char gnsdk_int8_t;
#endif /* GNSDK_INT8_T */

#ifndef GNSDK_INT16_T
#define GNSDK_INT16_T
typedef short gnsdk_int16_t;
#endif /* GNSDK_INT16_T */

#ifndef GNSDK_INT32_T
#define GNSDK_INT32_T
typedef int gnsdk_int32_t;
#endif /* GNSDK_INT32_T */

#ifndef GNSDK_INT64_T
#define GNSDK_INT64_T
typedef long long gnsdk_int64_t;
#endif /* GNSDK_INT64_T */

#ifndef GNSDK_UINT8_T
#define GNSDK_UINT8_T
typedef unsigned char gnsdk_uint8_t;
#endif /* GNSDK_UINT8_T */

#ifndef GNSDK_UINT16_T
#define GNSDK_UINT16_T
typedef unsigned short gnsdk_uint16_t;
#endif /* GNSDK_UINT16_T */

#ifndef GNSDK_UINT32_T
#define GNSDK_UINT32_T
typedef unsigned int gnsdk_uint32_t;
#endif /* GNSDK_UINT32_T */

#ifndef GNSDK_UINT64_T
#define GNSDK_UINT64_T
typedef unsigned long long gnsdk_uint64_t;
#endif /* GNSDK_UINT64_T */

#ifndef GNSDK_SIZE_T
#define GNSDK_SIZE_T
typedef size_t gnsdk_size_t;
#endif /* GNSDK_SIZE_T */

#ifndef GNSDK_UINTPTR_T
#define GNSDK_UINTPTR_T
typedef uintptr_t gnsdk_uintptr_t;
#endif /* GNSDK_UINTPTR_T */

#ifndef GNSDK_INTPTR_T
#define GNSDK_INTPTR_T
typedef intptr_t gnsdk_intptr_t;
#endif /* GNSDK_INTPTR_T */

#ifndef GNSDK_STR_T
#define GNSDK_STR_T
typedef gnsdk_char_t* gnsdk_str_t;
#endif /* GNSDK_STR_T */

#ifndef GNSDK_CSTR_T
#define GNSDK_CSTR_T
typedef const gnsdk_char_t*  gnsdk_cstr_t;
#endif /* GNSDK_CSTR_T */

#ifndef GNSDK_FLT32_T
#define GNSDK_FLT32_T
typedef float gnsdk_flt32_t;
#endif /* GNSDK_FLT32_T */

#ifndef GNSDK_FLT64_T
#define GNSDK_FLT64_T
typedef double gnsdk_flt64_t;
#endif /* GNSDK_FLT64_T */

#ifndef GNSDK_FLT128_T
#define GNSDK_FLT128_T
typedef long double gnsdk_flt128_t;
#endif /* GNSDK_FLT128_T */

#ifndef GNSDK_BOOL_T
#define GNSDK_BOOL_T
typedef char gnsdk_bool_t;
#endif /* GNSDK_BOOL_T */

#ifndef GNSDK_ERROR_T
#define GNSDK_ERROR_T
typedef gnsdk_uint32_t gnsdk_error_t;
#endif /* GNSDK_ERROR_T */

#ifndef GNSDK_TIME_US_T
#define GNSDK_TIME_US_T
typedef gnsdk_uint64_t gnsdk_time_us_t;
#endif /* GNSDK_TIME_US_T */

#ifndef GNSDK_HANDLE_T
#define GNSDK_HANDLE_T
	typedef gnsdk_void_t*        gnsdk_handle_t;
	#define GNSDK_DECLARE_HANDLE(handle)     struct handle##_s { gnsdk_uint32_t magic; }; typedef struct handle##_s* handle
#endif /* GNSDK_HANDLE_T */



#ifdef __cplusplus
}
#endif

#endif /* _GNSDK_DEFINES_H_ */
