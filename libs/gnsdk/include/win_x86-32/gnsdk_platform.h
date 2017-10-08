/*
  *
  *  GRACENOTE, INC. PROPRIETARY INFORMATION
  *  This software is supplied under the terms of a license agreement or
  *  nondisclosure agreement with Gracenote, Inc. and may not be copied
  *  or disclosed except in accordance with the terms of that agreement.
  *  Copyright(c) 2000-2013. Gracenote, Inc. All Rights Reserved.
  *
 */

/*
 * gnsdk_platform.h - Contains platform-specific definitions.
 * USE THIS FILE TO OVERRIDE THE DEFINITIONS IN gnsdk_defines.h
 */

 #ifndef _GNSDK_DEFINES_H_
 #error gnsdk_platforms.h should not be included directly. Use #include "gnsdk_defines.h"
 #endif

/*
 * Windows Flavor
 */

#ifndef _GNSDK_PLATFORM_H_
#define _GNSDK_PLATFORM_H_


#define GNSDK_WINDOWS
#define GNSDK_WINDOWS_X86
#define GNSDK_WINDOWS_X86_32
#define GNSDK_PLATFORM_STR			"Windows (x86)"


#define GNSDK_EXPORTED_API			__declspec(dllexport)
#define GNSDK_IMPORTED_API			__declspec(dllimport)
#define	GNSDK_CALLBACK_API			__cdecl
#define GNSDK_API					__stdcall
#define GNSDK_DEPRECATED_API(func)	__declspec(deprecated) func


#include <crtdbg.h>
#define GNSDK_ASSERT(exp)	_ASSERT(exp)

#define GNSDK_INT64_T
typedef __int64 gnsdk_int64_t;

#define GNSDK_UINT64_T
typedef unsigned __int64 gnsdk_uint64_t;

#include <stddef.h>

/* byte swapping from native to LE/BE */
#define GNSDK_BSWAP32_TO_LE(x)				(x)
#define GNSDK_BSWAP16_TO_LE(x)				(x)
#define GNSDK_BSWAP32_TO_BE(x)				GNSDK_BSWAP_32(x)
#define GNSDK_BSWAP16_TO_BE(x)				GNSDK_BSWAP_16(x)

#define GNSDK_BSWAP32_FROM_LE(x)			(x)
#define GNSDK_BSWAP16_FROM_LE(x)			(x)
#define GNSDK_BSWAP32_FROM_BE(x)			GNSDK_BSWAP_32(x)
#define GNSDK_BSWAP16_FROM_BE(x)			GNSDK_BSWAP_16(x)


#endif /* _GNSDK_PLATFORM_H_ */

