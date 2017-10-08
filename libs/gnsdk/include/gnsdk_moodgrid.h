/*
  *
  *  GRACENOTE, INC. PROPRIETARY INFORMATION
  *  This software is supplied under the terms of a license agreement or
  *  nondisclosure agreement with Gracenote, Inc. and may not be copied
  *  or disclosed except in accordance with the terms of that agreement.
  *  Copyright(c) 2000-2013. Gracenote, Inc. All Rights Reserved.
  *
 */

#ifndef _GNSDK_MOODGRID_H_
/**
  *
  * Gracenote Mood Grid  provides easy to use spatially aware music organization features to manage
  * user's music collection against a set Gracenote attributes.
  * Built to provide a high level User experience for local / cloud based music collections and services that
  * are Gracenote enabled, Mood Grid allows for single point music categorization / playlist creation based on
  * Mood (Gracenote Tm) . Addittional filtering support is provided for GOET( Genre / Origin/ Era / Artist Type)
  * and Tempo music attributes.
  * <ul>
  * <li>Generate a set of tracks based on requested spatial mood index .
  * <li>filter tracks based on easy to use values based on GOET / Tempo values.
  * <li>can supports multiple local/online music providers.
  * </ul>
*/
#define _GNSDK_MOODGRID_H_

#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
 * Typedefs
 ******************************************************************************/

/** @internal gnsdk_moodgrid_presentation_type_t @endinternal
  *
  * @ingroup MoodGrid_TypesEnums
  */
typedef enum
{
	/** @internal gnsdk_moodgrid_presentation_type_5x5 @endinternal
	 *
	 * 5 by 5 Mood Grid presentation type.
	 * @ingroup MoodGrid_TypesEnums
	 */
	gnsdk_moodgrid_presentation_type_5x5 = 0x0505,


	/** @internal gnsdk_moodgrid_presentation_type_10x10 @endinternal
	 *
	 * 10 by 10 Mood Grid presentation type.
	 * @ingroup MoodGrid_TypesEnums
	 */
	gnsdk_moodgrid_presentation_type_10x10 = 0x0A0A

} gnsdk_moodgrid_presentation_type_t;



/** @internal gnsdk_moodgrid_provider_handle_t @endinternal
  *
  *   Handle to Mood Grid Provider.
  * @ingroup MoodGrid_TypesEnums
*/
GNSDK_DECLARE_HANDLE( gnsdk_moodgrid_provider_handle_t );

/** @internal gnsdk_moodgrid_presentation_handle_t @endinternal
  *
  *   Handle to Mood Grid Presentation. Created by gnsdk_moodgrid_presentation_create API, the
  *   application must create this handle to request any Mood Grid recommendations.
  * @ingroup MoodGrid_TypesEnums
*/
GNSDK_DECLARE_HANDLE( gnsdk_moodgrid_presentation_handle_t );


/** @internal gnsdk_moodgrid_result_handle_t @endinternal
  *
  *   Handle to Mood Grid Results. Created by gnsdk_moodgrid_presentation_find_recommendations API, the
  *   application calls this API to get results for any Presentation coordinate.
  * @ingroup MoodGrid_TypesEnums
*/
GNSDK_DECLARE_HANDLE( gnsdk_moodgrid_result_handle_t );

/** @internal gnsdk_moodgrid_initialize @endinternal
  *
  *   Initialize the Gracenote Mood Grid SDK.
  *
  *  @param	sdkmgr	Handle from successful gnsdk_sdkmanager_initialize call
  * @ingroup MoodGrid_InitializationFunctions
  *
*/
gnsdk_error_t GNSDK_API
gnsdk_moodgrid_initialize(
	gnsdk_manager_handle_t sdkmgr
	);

/** @internal gnsdk_moodgrid_shutdown @endinternal
  *
  *   Shut down the Mood Grid SDK.
  * @ingroup MoodGrid_InitializationFunctions
*/
gnsdk_error_t GNSDK_API
gnsdk_moodgrid_shutdown(void);

/** @internal gnsdk_moodgrid_get_version @endinternal
  *
  *   Retrieve the  Mood Grid SDK's version string.
  * @ingroup MoodGrid_InitializationFunctions
*/
gnsdk_cstr_t GNSDK_API
gnsdk_moodgrid_get_version(void);

/** @internal gnsdk_moodgrid_get_build_date @endinternal
  *
  *   Retrieve  Mood Grid SDK's build date string.
  * @ingroup MoodGrid_InitializationFunctions
*/
gnsdk_cstr_t GNSDK_API
gnsdk_moodgrid_get_build_date(void);

/* GNSDK_MOOD_GRID_PRESENTATION_TYPES
  * Summary:
  *   Sets host name for proxy to route GNSDK queries through.
*/

/************************************************************************************
 GNSDK MoodGrid Provider Management.
*************************************************************************************/

/** @internal gnsdk_moodgrid_provider_count @endinternal
 * Retrieves the number of Attribute Data Providers that are currently available.
 * @param  	p_count				[out] Pointer to recieve the count.
 * @ingroup MoodGrid_Providers_Functions
 */
gnsdk_error_t GNSDK_API
gnsdk_moodgrid_provider_count (
	gnsdk_uint32_t*							p_count
	);


/** @internal gnsdk_moodgrid_provider_enum @endinternal
 * Enumerate the Attribute Data Providers currently available.
 *
 * @param  	index				[in] index of location.
 * @param  	ph_provider			[out] Pointer to recieve the provider handle.
 * @ingroup MoodGrid_Providers_Functions
 */
gnsdk_error_t GNSDK_API
gnsdk_moodgrid_provider_enum (
	gnsdk_uint32_t							index,
	gnsdk_moodgrid_provider_handle_t*		ph_provider
	);

/** @internal GNSDK_MOODGRID_PROVIDER_NAME @endinternal
 *
 * @ingroup MoodGrid_Providers_Keys
 */
# define GNSDK_MOODGRID_PROVIDER_NAME			"gnsdk_moodgrid_provider_name"
/** @internal GNSDK_MOODGRID_PROVIDER_TYPE @endinternal
 *
 * @ingroup MoodGrid_Providers_Keys
 */
# define GNSDK_MOODGRID_PROVIDER_TYPE			"gnsdk_moodgrid_provider_type"
/** @internal GNSDK_MOODGRID_PROVIDER_NETWORK_USE @endinternal
 *
 * @ingroup MoodGrid_Providers_Keys
 */
# define GNSDK_MOODGRID_PROVIDER_NETWORK_USE	"gnsdk_moodgrid_provider_network_use"

/** @internal gnsdk_moodgrid_provider_get_data @endinternal
 * Retrieves the property associated with key for a specific provider.
 * @param  h_provider			[in] Handle to an attribute data provider.
 * @param  key					[in] Datasource key to get the value for.
 * @param  p_value 				[out] Pointer to value
 * @ingroup MoodGrid_Providers_Functions
 */
gnsdk_error_t GNSDK_API
gnsdk_moodgrid_provider_get_data (
	gnsdk_moodgrid_provider_handle_t 		h_provider,
	gnsdk_cstr_t							key,
	gnsdk_cstr_t*							p_value
	);




/** @internal gnsdk_moodgrid_provider_release @endinternal
 * Releases the resources associated with a provider handle. The handle is should not used after this call.
 * @param  	h_provider			[in] Handle to an attribute data provider.
 * @ingroup MoodGrid_Providers_Functions
 */
gnsdk_error_t GNSDK_API
gnsdk_moodgrid_provider_release(
	gnsdk_moodgrid_provider_handle_t	h_provider
	);

/******************************************************************************
 * Mood Grid Presentation Types
 ******************************************************************************/

/** @internal gnsdk_moodgrid_presentation_type_dimension @endinternal
 * Get the x and y dimension of a presentation type.
 * @param  	presentation_type		[in] presentation type identifier .
 * @param 	p_x_size 				[out] Pointer to presentation type x size
 * @param 	p_y_size 				[out] Pointer to presentation type y size
 * @ingroup MoodGrid_Presentations_TypeManagementFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_moodgrid_presentation_type_dimension(
		gnsdk_moodgrid_presentation_type_t  presentation_type,
		gnsdk_uint32_t*						p_x_size,
		gnsdk_uint32_t*						p_y_size
		);



/******************************************************************************
 * Mood Grid Presentation Handle Management.
 ******************************************************************************/

/** @internal moodgrid_presentation_create @endinternal
  *
  *   Create a Mood Grid presentation handle.
  *
  *   @param 	user_handle			[in] User handle for the user requesting the presentation
  *	  @param 	presentation_type	[in] Presentation type
  *   @param 	callback_fn		    [in]
  *   @param 	callback_data       [in]
  *   @param  	ph_presentation		[out] Pointer to receive the MoodGrid presentation handle
  * @ingroup MoodGrid_Presentations_HandleManagementFunctions
  *
*/

gnsdk_error_t GNSDK_API
gnsdk_moodgrid_presentation_create(
	gnsdk_user_handle_t						user_handle,
	gnsdk_moodgrid_presentation_type_t		presentation_type,
	gnsdk_status_callback_fn				callback_fn,
	gnsdk_void_t*							callback_data,
	gnsdk_moodgrid_presentation_handle_t*	ph_presentation
	);


/** @internal gnsdk_moodgrid_presentation_release @endinternal
  *
  *   Invalidate and release resources for a given MoodGrid presentation handle.
  *
  *  @param  h_presentation	  [in] MoodGrid presentation handle to release
  * @ingroup MoodGrid_Presentations_HandleManagementFunctions
  *
*/
gnsdk_error_t GNSDK_API
gnsdk_moodgrid_presentation_release(
	gnsdk_moodgrid_presentation_handle_t	h_presentation
	);

/* Under Review ..  gnsdk_moodgrid_presentation_provider_add
 * Add a mood grid data source  to the presentation .
 * @param  	h_presentation		[in] presentation handle to which the datasource is added.
 * @param  	h_provider		[in] the provider handle that represents the data source.
 */
/* Under Review ..
gnsdk_error_t GNSDK_API
gnsdk_moodgrid_presentation_provider_add(
	gnsdk_moodgrid_presentation_handle_t	h_presentation
	gnsdk_recommendation_provider_handle_t 	h_provider
	);
*/


/** @internal gnsdk_moodgrid_presentation_get_type @endinternal
 * Gets the presentation type for Presentation.
 * @param  	h_presentation		[in] presentation handle
 * @param  	p_presentation_type	[out]pointer to a constant presentation type.
 * @ingroup MoodGrid_Presentations_HandleManagementFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_moodgrid_presentation_get_type(
	gnsdk_moodgrid_presentation_handle_t	h_presentation,
	gnsdk_moodgrid_presentation_type_t*		p_presentation_type
	);
/** @internal gnsdk_moodgrid_presentation_get_mood_name @endinternal
 * Gets the name for the Mood from a cell in the presentation.
 * @param  	h_presentation		[in] presentation handle
 * @param  	x_ordinal			[in] x-axis ordinal of the mood requested ( 1to m depending on the presentation type )
 * @param  	y_ordinal			[in] y-axis ordinal of the mood requested ( 1 to n depending on the presentation type )
 * @param  	p_mood_name			[out] pointer to a constant string to retrieve the name.
 * @ingroup MoodGrid_Presentations_HandleManagementFunctions
 */

gnsdk_error_t GNSDK_API
gnsdk_moodgrid_presentation_get_mood_name(
	gnsdk_moodgrid_presentation_handle_t	h_presentation,
	gnsdk_uint32_t							x_ordinal,
	gnsdk_uint32_t							y_ordinal,
	gnsdk_cstr_t*							p_mood_name
	);



/** @internal gnsdk_moodgrid_presentation_get_mood_id @endinternal
 * Gets the Mood category id from a cell in a  presentation.
 * @param  	h_presentation		[in] presentation handle
 * @param  	x_ordinal			[in] x-axis ordinal of the mood requested ( 1-5 or 1-10 depending on the presentation)
 * @param  	y_ordinal			[in] y-axis ordinal of the mood requested ( 1-5 or 1-10 depending on the presentation)
 * @param  	p_mood_id			[out] pointer to a constant string to retrieve the Mood Category id.
 * @ingroup MoodGrid_Presentations_HandleManagementFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_moodgrid_presentation_get_mood_id(
	gnsdk_moodgrid_presentation_handle_t	h_presentation,
	gnsdk_uint32_t							x_ordinal,
	gnsdk_uint32_t							y_ordinal,
	gnsdk_cstr_t*							p_mood_id
	);

/** @internal gnsdk_moodgrid_presentation_find_recommendations @endinternal
 * Get data from a certain cell.
 * No changes to providers of filters will be handled untill this is called again.
 * @param  	h_presentation		[in] presentation handle
 * @param   h_provider          [in] provider handle
 * @param  	x_ordinal			[in] x-axis ordinal of the mood requested ( 1-5 or 1-10 depending on the presentation)
 * @param  	y_ordinal			[in] y-axis ordinal of the mood requested ( 1-5 or 1-10 depending on the presentation)
 * @param 	ph_result 			[out] pointer to a result handle to retrieve the result handle.
 * @ingroup MoodGrid_Presentations_HandleManagementFunctions
 */

gnsdk_error_t GNSDK_API
gnsdk_moodgrid_presentation_find_recommendations(
	gnsdk_moodgrid_presentation_handle_t	h_presentation,
	gnsdk_moodgrid_provider_handle_t	    h_provider,
	gnsdk_uint32_t							x_ordinal,
	gnsdk_uint32_t							y_ordinal,
	gnsdk_moodgrid_result_handle_t*			ph_result
	);

/** @internal gnsdk_moodgrid_presentation_find_recommendations_estimate @endinternal
 * Gets the count of the number of results there are in a mood. Use this call if the Provider caps the results to a maximum number.
   This value is strictly for information only.
 * @param  	h_presentation		[in] presentation handle
 * @param   h_provider          [in] provider handle
 * @param  	x_ordinal			[in] x-axis ordinal of the mood requested ( 1-5 or 1-10 depending on the presentation)
 * @param  	y_ordinal			[in] y-axis ordinal of the mood requested ( 1-5 or 1-10 depending on the presentation)
 * @param  	p_estimate			[out] pointer to a unsigned int to retrieve the estimate.
 * @ingroup MoodGrid_Presentations_HandleManagementFunctions
 */
 gnsdk_error_t GNSDK_API
gnsdk_moodgrid_presentation_find_recommendations_estimate(
	gnsdk_moodgrid_presentation_handle_t	h_presentation,
	gnsdk_moodgrid_provider_handle_t	    h_provider,
	gnsdk_uint32_t							x_ordinal,
	gnsdk_uint32_t							y_ordinal,
	gnsdk_uint32_t*							p_estimate
	);


/************************************************************************************
 Results Management
*************************************************************************************/


/** @internal gnsdk_moodgrid_results_count @endinternal
 * Retrieves the total number of results in a  generated recommendations list.
 * @param  	h_results			[in] Handle to a Mood Grid Presentation cell results.
 * @param  	p_count				[out] The pointer to a unsigned int to retrieve the count.
 * @ingroup MoodGrid_ResultsFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_moodgrid_results_count(
	gnsdk_moodgrid_result_handle_t			h_results,
	gnsdk_uint32_t*							p_count
	);


/** @internal gnsdk_moodgrid_results_enum @endinternal
 * Enumerates the results for unique identifiers as specified by the datasource.
 * @param  	h_results			[in] Handle to a Mood Grid Presentation cell results.
 * @param 	index 				[in] Index of identifier to retrieve
 * @param 	p_ident				[out] Pointer to receive a identifier
 * @param   p_group			    [out] optional : group name in which the ident belongs
 * @ingroup MoodGrid_ResultsFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_moodgrid_results_enum(
	gnsdk_moodgrid_result_handle_t			h_results,
	gnsdk_uint32_t 							index,
	gnsdk_cstr_t* 							p_ident,
	gnsdk_cstr_t* 							p_group
	);


/** @internal gnsdk_moodgrid_results_release @endinternal
 * Release the results handle.
 * @param  	h_results			[in] handle to a Mood Grid Presentation cell results.
 * @ingroup MoodGrid_ResultsFunctions
 */
gnsdk_error_t GNSDK_API
gnsdk_moodgrid_results_release(
	gnsdk_moodgrid_result_handle_t			h_results
	);

/************************************************************************************
 Filters Management
*************************************************************************************/
/*
	Any one List type ( GOET/Tempo) can only have includes or excludes not both.
	Include takes precedence over exclude.
*/

/************************************************************************************
 Filters Management	- List Types
*/
/** @internal GNSDK_MOODGRID_FILTER_LIST_TYPE_GENRE @endinternal
 *
 * @ingroup MoodGrid_Filters_List_Types
 */
#define GNSDK_MOODGRID_FILTER_LIST_TYPE_GENRE 	GNSDK_LIST_TYPE_GENRES

/** @internal GNSDK_MOODGRID_FILTER_LIST_TYPE_ORIGINS @endinternal
 *
 * @ingroup MoodGrid_Filters_List_Types
 */
#define GNSDK_MOODGRID_FILTER_LIST_TYPE_ORIGINS GNSDK_LIST_TYPE_ORIGINS

/** @internal GNSDK_MOODGRID_FILTER_LIST_TYPE_ORIGINS @endinternal
 *
 * @ingroup MoodGrid_Filters_List_Types
 */
#define GNSDK_MOODGRID_FILTER_LIST_TYPE_ERAS GNSDK_LIST_TYPE_ERAS


/************************************************************************************
 Filters Management	- Conditions
*/
/** @internal GNSDK_MOODGRID_FILTER_CONDITION_INCLUDE @endinternal
 *
 * @ingroup MoodGrid_Filters_Conditions
 */
#define GNSDK_MOODGRID_FILTER_CONDITION_INCLUDE 	"gnsdk_moodgrid_filter_condition_include"
/** @internal GNSDK_MOODGRID_FILTER_CONDITION_EXCLUDE @endinternal
 *
 * @ingroup MoodGrid_Filters_Conditions
 */
#define GNSDK_MOODGRID_FILTER_CONDITION_EXCLUDE 	"gnsdk_moodgrid_filter_condition_exclude"
/** @internal gnsdk_moodgrid_presentation_filter_set @endinternal
 * Sets a new filter for a presentation with the requisite values.
 * @param  	h_presentation		[in] presentation handle
 * @param  	ident				[in] unique non-empty value for the filter.
 * @param   list_type 			[in] list types that from those defined above.
 * @param   item_value_id 		[in] id values for the list types.
 * @param   condition_type		[in] The type for the condition . There are only 2 types supported:
 *											GNSDK_MOODGRID_FILTER_CONDITION_INCLUDE
 *											GNSDK_MOODGRID_FILTER_CONDITION_EXCLUDE
 * @ingroup MoodGrid_Filters_Functions
 */
gnsdk_error_t GNSDK_API
gnsdk_moodgrid_presentation_filter_set (
	gnsdk_moodgrid_presentation_handle_t	h_presentation,
	gnsdk_cstr_t							ident,
	gnsdk_cstr_t							list_type,
	gnsdk_cstr_t							item_value_id,
	gnsdk_cstr_t							condition_type
	);

/** @internal gnsdk_moodgrid_presentation_filter_remove @endinternal
 * Removes an existing filter from a presentation.
 * @param  	h_presentation			[in] presentation handle
 * @param  	ident					[in] unique non-empty value representing the filter.
 * @ingroup MoodGrid_Filters_Functions
 */
gnsdk_error_t GNSDK_API
gnsdk_moodgrid_presentation_filter_remove (
	gnsdk_moodgrid_presentation_handle_t	h_presentation,
	gnsdk_cstr_t							ident
	);

/** @internal gnsdk_moodgrid_presentation_filter_remove_all @endinternal
 * Removes all existing filters from a presentation.
 * @param  	h_presentation			[in] presentation handle
 * @ingroup MoodGrid_Filters_Functions
 */
gnsdk_error_t GNSDK_API
gnsdk_moodgrid_presentation_filter_remove_all (
	gnsdk_moodgrid_presentation_handle_t	h_presentation
	);

#ifdef __cplusplus
}
#endif

#endif /*_GNSDK_MOODGRID_H_*/
