/*
  *
  *  GRACENOTE, INC. PROPRIETARY INFORMATION
  *  This software is supplied under the terms of a license agreement or
  *  nondisclosure agreement with Gracenote, Inc. and may not be copied
  *  or disclosed except in accordance with the terms of that agreement.
  *  Copyright(c) 2000-2013. Gracenote, Inc. All Rights Reserved.
  *
 */

#ifndef _GNSDK_DSP_H_
/* @internal gnsdk_dsp.h @endinternal
 * The primary interface for the DSP SDK
 * The GNSDK DSP library is an internal library that provides digital signal processing functionality
 * used by other GNSDK libraries. When implementing audio feature generation in the Submit library or digital
 * music recognition in the MusicID and MusicID-File libraries, the application must initialize GNSDK libraries
 * in the following order to ensure correct signal processing:
 * <ol>
 * <li>GNSDK Manager
 * <li>DSP
 * <li>The specific GNSDK library (or libraries)
 * </ol>
* @ingroup Music_Fingerprinting_HeaderFile
*/
#define _GNSDK_DSP_H_

#include "gnsdk_manager.h"

#ifdef __cplusplus
extern "C"{
#endif

/*
 * gnsdk_dsp.h:	Fingerprinting and other DSP implementations
 *
 */

/* GNSDK DSP Initialization APIs */
#ifndef SWIG
/** @internal gnsdk_dsp_initialize @endinternal
*  Initializes the DSP for GNSDK
*  @param sdkmgr_handle [in] Handle from a successful gnsdk_manager_initialize call
*  @return DSPERR_InvalidArg Given sdkmgr_handle parameter is null
*  @return DSPERR_HandleObjectInvalid Given sdkmgr_handle is not a valid GNSDK Manager handle
*  @return DSPERR_InitFailed Initialization failed
*  @return DSPERR_NoError Initialization succeeded
*  <p><b>Remarks:</b></p>
*  This function must be successfully called before any other DSP APIs will succeed.
*  This function can be called multiple times, however, all successful calls must be paired with a
call to gnsdk_dsp_shutdown.
*  If gnsdk_dsp_initialize returns an error, then gnsdk_dsp_shutdown must not be called.
* @ingroup Music_Fingerprinting_InitializationFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_dsp_initialize(
	gnsdk_manager_handle_t	sdkmgr_handle
	);

/** @internal gnsdk_dsp_shutdown @endinternal
*  Shut downs and releases resources for the DSP library.
*  @return DSPERR_NotInited gnsdk_dsp_initialize was not successfully initiated
*  @return DSPERR_NoError Shut down succeeded
*  <p><b>Remarks:</b></p>
*  All gnsdk_dsp_shutdown calls must be paired with an initial call to gnsdk_dsp_initialize.
*  The final gnsdk_dsp_shutdown call results in the library being completely shut down; all DSP APIs
cease to function until the library is again initialized.
* @ingroup Music_Fingerprinting_InitializationFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_dsp_shutdown(void);

/** @internal gnsdk_dsp_get_version @endinternal
*  Retrieves DSP's version string for GNSDK.
*  This API can be called at any time, even before initialization and after shutdown. The returned
string is a constant. Do not attempt to modify or delete.
*  Example: 1.2.3.123 (Major.Minor.Improvement.Build)
*  Major: New functionality
*  Minor: New or changed features
*  Improvement: Improvements and fixes
*  Build: Internal build number
* @ingroup Music_Fingerprinting_InitializationFunctions
*/
gnsdk_cstr_t GNSDK_API
gnsdk_dsp_get_version(void);

/** @internal gnsdk_dsp_get_build_date @endinternal
*  Retrieves the DSP 's build date string for GNSDK.
*  @return Note Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  This API can be called at any time, even before initialization and after shutdown. The returned
string is a constant. Do not attempt to modify or delete.
*  Example
*  Example build date string: 2008-02-12 00:41 UTC
* @ingroup Music_Fingerprinting_InitializationFunctions
*/
gnsdk_cstr_t GNSDK_API
gnsdk_dsp_get_build_date(void);
#endif
/* Direct DSP Feature Creation APIs */

/**  @internal gnsdk_dsp_feature_handle_t @endinternal
 * The handle for creating DSP Features. The term Feature is used
 * to encompass fingerprints and other DSP generated objects. 
* @ingroup Music_Fingerprinting_TypesEnums
*/
typedef gnsdk_handle_t		gnsdk_dsp_feature_handle_t;

/** @internal gnsdk_dsp_feature_qualities_t @endinternal
*  Value type to return specific qualities of certain DSP Features.
* @ingroup Music_Fingerprinting_TypesEnums
*/
typedef gnsdk_uint32_t		gnsdk_dsp_feature_qualities_t;

/** @internal GNSDK_DSP_FEATURE_QUALITY_DEFAULT @endinternal
  * Indicates the returned Feature is properly generated and no specific qualities.
  * @ingroup Music_Fingerprinting_FeatureQuality
*/
#define GNSDK_DSP_FEATURE_QUALITY_DEFAULT		0x0

/** @internal GNSDK_DSP_FEATURE_QUALITY_SHORT @endinternal
  * Indicates the source audio was shorter than optimal, and therefore the quality 
  * of the generated DSP feature could be degredaded.
  * @ingroup Music_Fingerprinting_FeatureQuality
*/
#define GNSDK_DSP_FEATURE_QUALITY_SHORT			0x1

/** @internal GNSDK_DSP_FEATURE_QUALITY_SILENT @endinternal
  * Indicates the source audio is silent, and therefore the generated Feature 
  * is based on silense.
  * @ingroup Music_Fingerprinting_FeatureQuality
*/
#define GNSDK_DSP_FEATURE_QUALITY_SILENT		0x2


#ifndef SWIG

/** @internal gnsdk_dsp_feature_audio_begin @endinternal
  * Create a DSP Feature handle to begin Feature generation. Applications can create
  * any number of handles to generate Features simultaneously.
  * @param user_handle  The user handle
  * @param feature_type The kind of DSP feature, for example a fingerprint.
  * @param audio_sample_rate The source audio sample rate.
  * @param audio_sample_size The source audio sample size.
  * @param audio_channels The source audio channels
  * @param p_feature_handle The handle of the generated DSP feature
* @ingroup Music_Fingerprinting_FeatureGenerationFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_dsp_feature_audio_begin(
	gnsdk_user_handle_t				user_handle,
	gnsdk_cstr_t					feature_type,
	gnsdk_uint32_t					audio_sample_rate,
	gnsdk_uint32_t					audio_sample_size,
	gnsdk_uint32_t					audio_channels,
	gnsdk_dsp_feature_handle_t*		p_feature_handle
	);

/** @internal gnsdk_dsp_feature_audio_write @endinternal
  * Write a buffer of audio to the Feature handle to be processed. 
  * Audio must be of the format specified in gnsdk_dsp_feature_audio_begin. 
  * Audio buffers must be contiguous from the source in order to generate an
  * accurate feature. 
  * @param feature_handle  Feature handle instance created by gnsdk_dsp_feature_audio_begin
  * @param audio_data  buffer of audio data provided by application
  * @param audio_data_bytes  size of audio buffer in bytes provided by audio_data parameter
  * @param pb_complete  point to gnsdk_bool_t to receive 'true' when Feature generation is complete
  * For some Features it is possible that the pb_complete parameter will not be set to true 
  * during any amount of writes. This case occurs when the generated Feature needs to utilize 
  * all provided audio and the application should provide audio until the source completes.
  * @ingroup Music_Fingerprinting_FeatureGenerationFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_dsp_feature_audio_write(
	gnsdk_dsp_feature_handle_t		feature_handle,
	const gnsdk_byte_t*				audio_data,
	gnsdk_size_t					audio_data_bytes,
	gnsdk_bool_t*					pb_complete
	);

/** @internal gnsdk_dsp_feature_end_of_write @endinternal
  * Indicate to Feature handle that the source audio has reached its end. This will finalize the
  * Feature and prepare it for retrieval. If the complete flag was set to true during the write
  * operations, it is not neccessary to call this function. However calling this API when the 
  * write complete flag was set to true is ok and will not have adverse affects.
  * @param feature_handle  Feature handle instance created by gnsdk_dsp_feature_audio_begin
  * @ingroup Music_Fingerprinting_FeatureGenerationFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_dsp_feature_end_of_write(
	gnsdk_dsp_feature_handle_t		feature_handle
	);

/** @internal gnsdk_dsp_feature_retrieve_data @endinternal
  * Get the DSP feature qualities and data. Note that if there were no
  * processing errors, but there wasn't enough non-silent audio to 
  * generate a fingerprint, the function will return 'success' but the
  * output data param may be set to GNSDK_NULL.
  * @param feature_handle  Feature handle instance created by gnsdk_dsp_feature_audio_begin
  * @param p_feature_qualities  Pointer to receive quality flags for Feature
  * @param p_feature_data  Pointer to receive Feature data in string form. 
  * The returned string in p_feature_data is managed by the feature_handle and is released when
  * feature_handle is released.
  * @ingroup Music_Fingerprinting_FeatureGenerationFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_dsp_feature_retrieve_data(
	gnsdk_dsp_feature_handle_t		feature_handle,
	gnsdk_dsp_feature_qualities_t*	p_feature_qualities,
	gnsdk_cstr_t*					p_feature_data
	);

/** @internal gnsdk_dsp_feature_release @endinternal
  * Release the DSP feature handle.
  * @param feature_handle  Feature handle instance created by gnsdk_dsp_feature_audio_begin
  * @ingroup Music_Fingerprinting_FeatureGenerationFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_dsp_feature_release(
	gnsdk_dsp_feature_handle_t		feature_handle
	);


#endif /* SWIG */

#ifdef __cplusplus
}
#endif

#endif /* _GNSDK_DSP_H_ */

