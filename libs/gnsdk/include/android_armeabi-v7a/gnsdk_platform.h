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
 * Android ARM 32-bit Flavor
 */

#ifndef _GNSDK_PLATFORM_H_
#define _GNSDK_PLATFORM_H_


#define GNSDK_ANDROID
#define GNSDK_ANDROID_ARM
#define GNSDK_PLATFORM_STR		"Android (armeabi-v7a)"

#define GNSDK_EXPORTED_API
#define GNSDK_IMPORTED_API
#define	GNSDK_CALLBACK_API
#define GNSDK_API
#ifdef __GNUC__
	#define GNSDK_DEPRECATED_API(func)	func __attribute__ ((deprecated))
#else
	#pragma message("WARNING: You need to implement DEPRECATED for this compiler")
	#define GNSDK_DEPRECATED_API(func) func
#endif

#include <assert.h>
#ifdef _DEBUG
#include <android/log.h>
#include <stdio.h>
#define GNSDK_ASSERT(exp)																										\
{																																\
	if ( !(exp) )																												\
	{																															\
		char comm_assert_msg_buffer[1024];																						\
		snprintf(comm_assert_msg_buffer,sizeof(comm_assert_msg_buffer),"ASSERT FAILED %s  [%s:%d]\n",#exp,__FILE__,__LINE__);	\
		__android_log_write(ANDROID_LOG_ERROR, "GNSDK", comm_assert_msg_buffer);												\
	}																															\
}
#else
#define GNSDK_ASSERT(exp)	assert(exp);
#endif

#include <stddef.h> /* for size_t */

#define GNSDK_INTPTR_T
typedef long int 							gnsdk_intptr_t;

#define GNSDK_UINTPTR_T
typedef unsigned long int 					gnsdk_uintptr_t;

#define GNSDK_SIZE_T
typedef unsigned long						gnsdk_size_t;


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
