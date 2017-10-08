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
 * gnsdk.h - header to include all requisite GNSDK headers
 */

#ifndef _GNSDK_H_
#define _GNSDK_H_

/* GNSDK Types and Macros */
#include "gnsdk_defines.h"				/* REQUIRED */
#include "gnsdk_errors.h"				/* REQUIRED */
#include "gnsdk_error_codes.h"			/* REQUIRED */
#include "gnsdk_status.h"				/* STANDARD */
#include "gnsdk_version.h"				/* STANDARD */

/* GNSDK APIs */
#include "gnsdk_manager.h"				/* REQUIRED */
#include "gnsdk_manager_gdo.h"			/* STANDARD */
#include "gnsdk_manager_lists.h"		/* STANDARD */
#include "gnsdk_manager_list_values.h"	/* STANDARD */
#include "gnsdk_manager_locales.h"		/* STANDARD */
#include "gnsdk_manager_logging.h"		/* STANDARD */
#include "gnsdk_manager_storage.h"		/* STANDARD */

/* GNSDKs to be used: Enable defines for all SDKs to be used */
#if ((!defined GNSDK_MUSICID)        	&& \
	 (!defined GNSDK_MUSICID_FILE) 		&& \
	 (!defined GNSDK_MUSICID_STREAM)	&& \
	 (!defined GNSDK_VIDEO)          	&& \
	 (!defined GNSDK_LINK) 				&& \
	 (!defined GNSDK_DSP) 				&& \
	 (!defined GNSDK_PLAYLIST) 		 	&& \
	 (!defined GNSDK_MOODGRID) 			&& \
	 (!defined GNSDK_TASTE)             && \
	 (!defined GNSDK_LOOKUP_LOCAL)   	&& \
	 (!defined GNSDK_LOOKUP_LOCALSTREAM)    && \
	 (!defined GNSDK_STORAGE_SQLITE) )

	#define GNSDK_MUSICID            1
	#define GNSDK_MUSICID_FILE       1
	#define GNSDK_MUSICID_STREAM     1
	#define GNSDK_VIDEO              1
	#define GNSDK_LINK               1
	#define GNSDK_DSP                1
	#define GNSDK_PLAYLIST           1
	#define GNSDK_MOODGRID           1
	#define GNSDK_TASTE              1
	#define GNSDK_STORAGE_SQLITE     1
	#define GNSDK_LOOKUP_LOCAL       1
	#define GNSDK_LOOKUP_LOCALSTREAM 1
#endif


#if GNSDK_MUSICID
	#include "gnsdk_musicid.h"
#endif
#if GNSDK_MUSICID_FILE
	#include "gnsdk_musicid_file.h"
#endif
#if GNSDK_MUSICID_STREAM
	#include "gnsdk_musicid_stream.h"
#endif
#if GNSDK_VIDEO
	#include "gnsdk_video.h"
#endif
#if GNSDK_LINK
	#include "gnsdk_link.h"
#endif
#if GNSDK_STORAGE_SQLITE
	#include "gnsdk_storage_sqlite.h"
#endif
#if GNSDK_LOOKUP_LOCAL
	#include "gnsdk_lookup_local.h"
#endif
#if GNSDK_LOOKUP_LOCALSTREAM
	#include "gnsdk_lookup_localstream.h"
#endif
#if GNSDK_DSP
	#include "gnsdk_dsp.h"
#endif
#if GNSDK_PLAYLIST
	#include "gnsdk_playlist.h"
#endif
#if GNSDK_MOODGRID
	#include "gnsdk_moodgrid.h"
#endif


#endif /* _GNSDK_H_ */

