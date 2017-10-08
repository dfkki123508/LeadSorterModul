/*
  *
  *  GRACENOTE, INC. PROPRIETARY INFORMATION
  *  This software is supplied under the terms of a license agreement or
  *  nondisclosure agreement with Gracenote, Inc. and may not be copied
  *  or disclosed except in accordance with the terms of that agreement.
  *  Copyright(c) 2000-2013. Gracenote, Inc. All Rights Reserved.
  *
 */

/* gnsdk_manager_gdo_values.h: GDO keys and related macros.
*/

#ifndef _GNSDK_MANAGER_GDO_VALUES_H_
#define _GNSDK_MANAGER_GDO_VALUES_H_

#include "gnsdk_manager_locales.h"

#ifdef __cplusplus
extern "C"{
#endif


/*****************************************************************************
** GDO Keys common to multiple responses
*/

/** @internal GNSDK_GDO_TYPE_EXTERNAL_ID @endinternal
*  GDO is of external ID type.
* @ingroup GDO_Types_ExternalId
*/
#define GNSDK_GDO_TYPE_EXTERNAL_ID				"gnsdk_ctx_xid"

/** @internal GNSDK_GDO_CHILD_EXTERNAL_ID @endinternal
*  Retrieves an extended ID type (retrievable from most GDOs). This child GDO supports Link data.
*  GNSDK_GDO_CHILD_EXTERNAL_ID
*  GNSDK_GDO_TYPE_ALBUM GNSDK_GDO_TYPE_CONTRIBUTOR GNSDK_GDO_TYPE_TRACK
GNSDK_GDO_TYPE_VIDEOCLIP GNSDK_GDO_TYPE_VIDEO_PRODUCT GNSDK_GDO_TYPE_VIDEO_SEASON
GNSDK_GDO_TYPE_VIDEO_SERIES GNSDK_GDO_TYPE_VIDEO_WORK
* @ingroup GDO_ChildKeys_ExternalId
*/
#define GNSDK_GDO_CHILD_EXTERNAL_ID					GNSDK_GDO_TYPE_EXTERNAL_ID"!"

#define GNSDK_GDO_TYPE_CONTENT						"gnsdk_ctx_content"
#define GNSDK_GDO_VALUE_CONTENT_VALUE				"gnsdk_val_content"
#define GNSDK_GDO_VALUE_CONTENT_TYPE				"gnsdk_val_content_type"
#define GNSDK_GDO_VALUE_CONTENT_MIMETYPE			"gnsdk_val_content_mimetype"

#define GNSDK_GDO_CHILD_CONTENT						GNSDK_GDO_TYPE_CONTENT"!"
#define GNSDK_GDO_CHILD_CONTENT_IMAGECOVER			GNSDK_GDO_TYPE_CONTENT"!coverart"
#define GNSDK_GDO_CHILD_CONTENT_IMAGEARTIST			GNSDK_GDO_TYPE_CONTENT"!imgartist"
#define GNSDK_GDO_CHILD_CONTENT_IMAGEVIDEO			GNSDK_GDO_TYPE_CONTENT"!imgvideo"
#define GNSDK_GDO_CHILD_CONTENT_BIOGRAPHY			GNSDK_GDO_TYPE_CONTENT"!bio"
#define GNSDK_GDO_CHILD_CONTENT_REVIEW				GNSDK_GDO_TYPE_CONTENT"!review"

/* from GNSDK_GDO_VALUE_CONTENT_TYPE */
#define GNSDK_CONTENT_TYPE_IMAGE_COVER				"gnsdk_content_image_cover"
#define GNSDK_CONTENT_TYPE_IMAGE_GENRE				"gnsdk_content_image_genre"
#define GNSDK_CONTENT_TYPE_IMAGE_VIDEO				"gnsdk_content_image_video"
#define GNSDK_CONTENT_TYPE_IMAGE_ARTIST				"gnsdk_content_image_artist"
#define GNSDK_CONTENT_TYPE_TEXT_REVIEW				"gnsdk_content_text_review"
#define GNSDK_CONTENT_TYPE_TEXT_BIOGRAPHY			"gnsdk_content_text_bio"
#define GNSDK_CONTENT_TYPE_TEXT_NEWS				"gnsdk_content_text_news"
#define GNSDK_CONTENT_TYPE_TEXT_ARTISTNEWS			"gnsdk_content_text_artnews"
#define GNSDK_CONTENT_TYPE_TEXT_LISTENERCOMMENTS	"gnsdk_content_text_liscomm"
#define GNSDK_CONTENT_TYPE_TEXT_RELEASECOMMENTS		"gnsdk_content_text_relcomm"

#define GNSDK_GDO_TYPE_ASSET						"gnsdk_ctx_asset"
#define GNSDK_GDO_CHILD_ASSET						GNSDK_GDO_TYPE_ASSET"!"
#define GNSDK_GDO_CHILD_ASSET_SIZE_THUMB			GNSDK_GDO_TYPE_ASSET"!thumb"
#define GNSDK_GDO_CHILD_ASSET_SIZE_SMALL			GNSDK_GDO_TYPE_ASSET"!small"
#define GNSDK_GDO_CHILD_ASSET_SIZE_300				GNSDK_GDO_TYPE_ASSET"!300"
#define GNSDK_GDO_CHILD_ASSET_SIZE_MEDIUM			GNSDK_GDO_TYPE_ASSET"!medium"
#define GNSDK_GDO_CHILD_ASSET_SIZE_LARGE			GNSDK_GDO_TYPE_ASSET"!large"
#define GNSDK_GDO_CHILD_ASSET_SIZE_XLARGE			GNSDK_GDO_TYPE_ASSET"!xlarge"

#define GNSDK_GDO_VALUE_ASSET_URL					"gnsdk_val_asset_url"
#define GNSDK_GDO_VALUE_ASSET_DIMENSION				"gnsdk_val_asset_dimension"
#define GNSDK_GDO_VALUE_ASSET_BYTES					"gnsdk_val_asset_bytes"
#define GNSDK_GDO_VALUE_ASSET_SIZE					"gnsdk_val_asset_size"

/* from GNSDK_GDO_VALUE_ASSET_SIZE */
#define GNSDK_CONTENT_DATA_SIZE_VALUE_75			"gnsdk_content_sz_75"
#define GNSDK_CONTENT_DATA_SIZE_VALUE_170			"gnsdk_content_sz_170"
#define GNSDK_CONTENT_DATA_SIZE_VALUE_300			"gnsdk_content_sz_300"
#define GNSDK_CONTENT_DATA_SIZE_VALUE_450			"gnsdk_content_sz_450"
#define GNSDK_CONTENT_DATA_SIZE_VALUE_720			"gnsdk_content_sz_720"
#define GNSDK_CONTENT_DATA_SIZE_VALUE_1080			"gnsdk_content_sz_1080"

/* legacy */
#define GNSDK_CONTENT_DATA_SIZE_VALUE_THUMBNAIL		"thumbnail"	/* legacy: use GNSDK_CONTENT_DATA_SIZE_VALUE_75 */
#define GNSDK_CONTENT_DATA_SIZE_VALUE_SMALL			"small"		/* legacy: use GNSDK_CONTENT_DATA_SIZE_VALUE_170 */
#define GNSDK_CONTENT_DATA_SIZE_VALUE_300X300		"300x300"	/* legacy: use GNSDK_CONTENT_DATA_SIZE_VALUE_300 */
#define GNSDK_CONTENT_DATA_SIZE_VALUE_MEDIUM		"medium"	/* legacy: use GNSDK_CONTENT_DATA_SIZE_VALUE_450 */
#define GNSDK_CONTENT_DATA_SIZE_VALUE_LARGE			"large"		/* legacy: use GNSDK_CONTENT_DATA_SIZE_VALUE_720 */
#define GNSDK_CONTENT_DATA_SIZE_VALUE_XLARGE		"xLarge"	/* legacy: use GNSDK_CONTENT_DATA_SIZE_VALUE_1080 */

#define GNSDK_CONTENT_DATA_TYPE_VALUE_JPEG			"gsndk_content_jpeg"

#define GNSDK_GDO_VALUE_GDO_SERIALIZED				"gnsdk_val_serialized"

/** @internal GNSDK_GDO_VALUE_DISCOVER_SEED @endinternal
*  Retrieves a Discover Seed value from GDO.
*  <p><b>Remarks:</b></p>
*  Available for album and track types, this retrieves a Discover Seed which can be used as input
to Gracenote Discover SDK to retrieve recommendations based on the originating album or track.
*  As this is a unique value, the ordinal parameter for gnsdk_manager_gdo_value_get must be set to 1
to retrieve the first (or only) value instance.
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_DISCOVER_SEED				"gnsdk_val_discoverseed"
/** @internal GNSDK_GDO_VALUE_PRODUCTID @endinternal
*  Retrieves a product ID for the current product from a GDO.
*  <p><b>Remarks:</b></p>
*  Available for most types, this retrieves a value which can be stored or transmitted. This
value can be used as a static identifier for the current content as it will not change over time.
*  As this is a unique value, the ordinal parameter for gnsdk_manager_gdo_value_get must be set to 1
to retrieve the first (or only) value instance.
* @ingroup GDO_ValueKeys_GracenoteIDs
*/
#define GNSDK_GDO_VALUE_PRODUCTID					"gnsdk_val_productid"
/** @internal GNSDK_GDO_VALUE_TAGID @endinternal
*  Retrieves a TAGID value for a product from a GDO (Tag ID is a synonym for Product ID).
*  <p><b>Remarks:</b></p>
*  This value key exists primarily to support legacy implementations. We recommend using
GNSDK_GDO_VALUE_PRODUCTID to retrieve product identifiers from a GDO type.
* @ingroup GDO_ValueKeys_GracenoteIDs
*/
#define GNSDK_GDO_VALUE_TAGID						GNSDK_GDO_VALUE_PRODUCTID
/** @internal GNSDK_GDO_VALUE_GNID @endinternal
  *
  *   Retrieves a GNID value for a product from a GDO.
  * @ingroup GDO_ValueKeys_GracenoteIDs
*/
#define GNSDK_GDO_VALUE_GNID						"gnsdk_val_gnid"

/** @internal GNSDK_GDO_VALUE_GNUID @endinternal
  *
  *   Retrieves a GNUID value for a product from a GDO.
  * @ingroup GDO_ValueKeys_GracenoteIDs
*/
#define GNSDK_GDO_VALUE_GNUID						"gnsdk_val_gnuid"

/** @internal GNSDK_GDO_VALUE_TUI @endinternal
*  Retrieves a TUI value from a GDO.
* @ingroup GDO_ValueKeys_GracenoteIDs
*/
#define GNSDK_GDO_VALUE_TUI							"gnsdk_val_tui"
/** @internal GNSDK_GDO_VALUE_TUI_MATCH_PRODUCT @endinternal
*  Retrieves a second TUI from a Works GDO, if that GDO can be accessed by two IDs. This TUI is used
for matching partial Products objects to full Works objects.
*  Use this value to ensure correct TUI value matching for cases when a video Product GDO contains
multiple partial Work GDOs. Each partial Work GDO corresponds
*  to a full Works object, and each full Works object contains the GNSDK_GDO_VALUE_TUI value,
incremented by one digit to maintain data integrity with Gracenote Service.
*  The GNSDK_GDO_VALUE_TUI_MATCH_PRODUCT maps the partial Works object TUI value to the full Works
object.
* @ingroup GDO_ValueKeys_GracenoteIDs
*/
#define GNSDK_GDO_VALUE_TUI_MATCH_PRODUCT			"gnsdk_val_tui_match_product"
/** @internal GNSDK_GDO_VALUE_TUI_TAG @endinternal
*  Retrieves a TUI Tag value from a GDO.
* @ingroup GDO_ValueKeys_GracenoteIDs
*/
#define GNSDK_GDO_VALUE_TUI_TAG						"gnsdk_val_tui_tag"

/** @internal GNSDK_GDO_VALUE_GLOBALID @endinternal
  *
  *   Retrieves a global id value from a GDO.
* @ingroup GDO_ValueKeys_GracenoteIDs
*/
#define GNSDK_GDO_VALUE_GLOBALID					"gnsdk_val_globalid"

/** @internal GNSDK_GDO_VALUE_RESULT_SOURCE		 @endinternal
  *
  *   If exists, retrieves the source identifier value from a GDO.
  *		For supplemental storages, this is the custom ID. 
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_RESULT_SOURCE				"gnsdk_val_result_source"

#define GNSDK_RESULT_SOURCE_ONLINE					"gnsdk_result_source_online"
#define GNSDK_RESULT_SOURCE_LOCAL_PRIMARY			"gnsdk_result_source_local_primary"
#define GNSDK_RESULT_SOURCE_LOCAL_BUNDLE			"gnsdk_result_source_local_bundle"
#define GNSDK_RESULT_SOURCE_RENDERED				"gnsdk_result_source_rendered"

/** @internal GNSDK_GDO_VALUE_RESPONSE_RESULT_COUNT @endinternal
  *
  *   Retrieves number of results in a RESPONSE GDO
* @ingroup GDO_ValueKeys_GracenoteIDs
*/
#define GNSDK_GDO_VALUE_RESPONSE_RESULT_COUNT		"gnsdk_val_resultcount"

/** @internal GNSDK_GDO_VALUE_RESPONSE_RANGE_START @endinternal
*  Retrieves the ordinal of the first result in the returned range.
*  <p><b>Remarks:</b></p>
*  If you do not set a starting value, the default behavior is to return the first set of results.
*  Range values are available to aid in paging results. Gracenote Service limits the number of
responses returned in any one request, so the range values are available to indicate the total
number of results, and where the current results fit in within that total.
*
*  Range values are available from all response types.
*  As this is a unique value, the ordinal parameter for gnsdk_manager_gdo_value_get must be set to 1
to retrieve the first (or only) value instance.
*  <p><b>Important:</b></p>
*  The number of results actually returned for a query may not equal the number of results initially
requested. To accurately iterate through results, always check the range start, end, and total
values and the responses returned by Gracenote Service for the query (or queries). Ensure that you
are incrementing by using the actual last range end value plus one (range_end+1), and not by simply
using the initial requested value.
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_RESPONSE_RANGE_START		"gnsdk_val_rangestart"
/** @internal GNSDK_GDO_VALUE_RESPONSE_RANGE_END @endinternal
*  Retrieves the ordinal of the last result in the returned range.
*  <p><b>Remarks:</b></p>
*  Range values are available to aid in paging results. Gracenote Service limits the number of
responses returned in any one request, so the range values are available to indicate the total
number of results, and where the current results fit in within that total.
*  Range values are available from all response types.
*  As this is a unique value, the ordinal parameter for gnsdk_manager_gdo_value_get must be set to 1
to retrieve the first (or only) value instance.
*  <p><b>Important:</b></p>
*  The number of results actually returned for a query may not equal the number of results initially
requested. To accurately iterate through results, always check the range start, end, and total
values and the responses returned by Gracenote Service for the query (or queries). Ensure that you
are incrementing by using the actual last range end value plus one (range_end+1), and not by simply
using the initial requested value.
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_RESPONSE_RANGE_END					"gnsdk_val_rangeend"
/** @internal GNSDK_GDO_VALUE_RESPONSE_RANGE_TOTAL @endinternal
*  Retrieves the estimated total number of results possible.
*  <p><b>Remarks:</b></p>
*  Range values are available to aid in paging results. Gracenote Service limits the number of
responses returned in any one request, so the range values are available to indicate the total
number of results, and where the current results fit in within that total.
*  The total value may be estimated.
*  Range values are available from all response types.
*  As this is a unique value, the ordinal parameter for gnsdk_manager_gdo_value_get must be set to 1
to retrieve the first (or only) value instance.
*  <p><b>Important:</b></p>
*  The number of results actually returned for a query may not equal the number of results initially
requested. To accurately iterate through results, always check the range start, end, and total
values and the responses returned by Gracenote Service for the query (or queries). Ensure that you
are incrementing by using the actual last range end value plus one (range_end+1), and not by simply
using the initial requested value.
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_RESPONSE_RANGE_TOTAL				"gnsdk_val_rangecount"

/** @internal GNSDK_GDO_VALUE_RESPONSE_NEEDS_DECISION @endinternal
*  Retrieves a boolean value indicating whether the match(es) need a decision to be made by a user.
*
*  When your application makes an identification query, Gracenote returns a response GDO with one of the following:
*  <ul>
    *  <li>No GDO match</li>
    *  <li>Single GDO match</li>
    *  <li>Multiple GDO matches</li>
*  </ul>
*  In all cases, Gracenote returns high-confidence results based on the identification criteria. However, even high-confidence results could require additional decisions from a user. 
*  In such cases, GNSDK sets NEEDS_DECISION to true, indicating that the end user should select the the final result. The application should present users with the returned match(es) and allow them to select (or reject) the match.
*  In general, GDO responses that need a decision by a user are:
*  <ul>
*  <li><b>Any multiple match response</b></li>
*  <li><b>Any single match response</b> that Gracenote determines needs a decision by a user. Even though a single match might be good match candidate, Gracenote might determine that it is not quite perfect, based on the quality of the match and/or the criteria used to identify the match.</li>
*  </ul>
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_RESPONSE_NEEDS_DECISION				"gnsdk_val_decision"

/** @internal GNSDK_GDO_VALUE_EXTERNALID_VALUE @endinternal
*  Retrieves an external ID value from a GDO.
*  <p><b>Remarks:</b></p>
*  This value supports Link data.
*  GNSDK_GDO_TYPE_EXTERNAL_ID
* @ingroup GDO_ValueKeys_ExternalId
*/
#define GNSDK_GDO_VALUE_EXTERNALID_VALUE					"gnsdk_val_xid_val"
/** @internal GNSDK_GDO_VALUE_EXTERNALID_SOURCE @endinternal
*  Retrieves an external ID source value from a GDO.
*  <p><b>Remarks:</b></p>
*  This value supports Link data.
*  GNSDK_GDO_TYPE_EXTERNAL_ID
* @ingroup GDO_ValueKeys_ExternalId
*/
#define GNSDK_GDO_VALUE_EXTERNALID_SOURCE					"gnsdk_val_xid_source"
/** @internal GNSDK_GDO_VALUE_EXTERNALID_TYPE @endinternal
*  Retrieves an external ID type value from a GDO.
*  <p><b>Remarks:</b></p>
*  This value supports Link data.
*  GNSDK_GDO_TYPE_EXTERNAL_ID
* @ingroup GDO_ValueKeys_ExternalId
*/
#define GNSDK_GDO_VALUE_EXTERNALID_TYPE				"gnsdk_val_xid_type"
/** @internal GNSDK_GDO_VALUE_EXTERNALID_DATA @endinternal
*  Retrieves an external ID 3rd party data value from a GDO.
*  <p><b>Remarks:</b></p>
*  This value supports Link data.
*  GNSDK_GDO_TYPE_EXTERNAL_ID
* @ingroup GDO_ValueKeys_ExternalId
*/
#define GNSDK_GDO_VALUE_EXTERNALID_DATA				"gnsdk_val_xid_data"

/** @internal GNSDK_GDO_VALUE_FAMILY @endinternal
  *
  *   Retrieves a family (or last) name value of a person from a GDO.
  * @ingroup GDO_ValueKeys_Name
*/
#define GNSDK_GDO_VALUE_FAMILY						"gnsdk_val_family"

/** @internal GNSDK_GDO_VALUE_SORTABLE @endinternal
  *
  *   Retrieves sortable text for a GDO, e.g. a name or a title.
  *	  This key should only be used for sorting use case only
  * @ingroup GDO_ValueKeys_Name
*/
#define GNSDK_GDO_VALUE_SORTABLE					"gnsdk_val_name_sortable"

/** @internal GNSDK_GDO_VALUE_SORTABLE_SCHEME @endinternal
  *
  *   Retrieves the 'scheme' value for a returned
  *   GNSDK_GDO_VALUE_SORTABLE object, which indicates the method used to generated the sortable version of the string.
  * @ingroup GDO_ValueKeys_Sortable
*/
#define GNSDK_GDO_VALUE_SORTABLE_SCHEME				"gnsdk_val_name_sortable_scheme"

/** @internal GNSDK_VALUE_SORTABLE_SCHEME_PINYIN @endinternal
  *
  *   Indicates the 'pinyin scheme' value for a returned
  *   GNSDK_GDO_VALUE_SORTABLE_SCHEME object.
  * @ingroup GDO_ValueKeys_Sortable
*/
#define GNSDK_VALUE_SORTABLE_SCHEME_PINYIN			"gnsdk_sortscheme_pinyin"
/** @internal GNSDK_VALUE_SORTABLE_SCHEME_YOMI @endinternal
  *
  *   Indicates the 'yomi scheme' value for a returned
  *   GNSDK_GDO_VALUE_SORTABLE_SCHEME object.
  * @ingroup GDO_ValueKeys_Sortable
*/
#define GNSDK_VALUE_SORTABLE_SCHEME_YOMI			"gnsdk_sortscheme_yomi"
/** @internal GNSDK_VALUE_SORTABLE_SCHEME_UNKNOWN @endinternal
  *
  *   Indicates unknown scheme value for a returned
  *   GNSDK_GDO_VALUE_SORTABLE_SCHEME object.
  * @ingroup GDO_ValueKeys_Sortable
*/
#define GNSDK_VALUE_SORTABLE_SCHEME_UNKNOWN			"gnsdk_sortscheme_unknown"
/** @internal GNSDK_GDO_VALUE_BIOGRAPHY @endinternal
*  Retrieves an available biography value from a GDO.
* @ingroup GDO_ValueKeys_Contributor
*/
#define GNSDK_GDO_VALUE_BIOGRAPHY					"gnsdk_val_biography"
/** @internal GNSDK_GDO_VALUE_BIOGRAPHY_LANGUAGE @endinternal
*  Retrieves the available language value for a returned GNSDK_GDO_VALUE_BIOGRAPHY object.
*  <p><b>Remarks:</b></p>
*  Use this value to retrieve the actual language value of a returned object.
*  The language value of a returned object depends on availability. Information in the language set
for the locale may not be available, and the object's information may be available only in its
default official language. For example, if a locale's set language is Spanish, but the object's
information is available only in English, this value returns as English.
* @ingroup GDO_ValueKeys_Contributor
*/
#define GNSDK_GDO_VALUE_BIOGRAPHY_LANGUAGE			"gnsdk_val_biography_language"
/** @internal GNSDK_GDO_VALUE_BIRTH_DATE @endinternal
*  Retrieves a birth date value from a GDO.
* @ingroup GDO_ValueKeys_Contributor
*/
#define GNSDK_GDO_VALUE_BIRTH_DATE					"gnsdk_val_birth_date"
/** @internal GNSDK_GDO_VALUE_BIRTH_PLACE @endinternal
*  Retrieves a birth place value from a GDO.
* @ingroup GDO_ValueKeys_Contributor
*/
#define GNSDK_GDO_VALUE_BIRTH_PLACE					"gnsdk_val_birth_place"
/** @internal GNSDK_GDO_VALUE_BIRTH_PLACE_LANGUAGE @endinternal
*  Retrieves the available language value for a returned GNSDK_GDO_VALUE_BIRTH_PLACE object.
*  <p><b>Remarks:</b></p>
*  Use this value to retrieve the actual language value of a returned object.
*  The language value of a returned object depends on availability. Information in the language set
for the locale may not be available, and the object's information may be available only in its
default official language. For example, if a locale's set language is Spanish, but the object's
information is available only in English, this value returns as English.
* @ingroup GDO_ValueKeys_Contributor
*/
#define GNSDK_GDO_VALUE_BIRTH_PLACE_LANGUAGE		"gnsdk_val_birth_place_language"
/** @internal GNSDK_GDO_VALUE_DEATH_DATE @endinternal
*  Retrieves a death date value from a GDO.
*  GNSDK_GDO_VALUE_DEATH_DATE
* @ingroup GDO_ValueKeys_Contributor
*/
#define GNSDK_GDO_VALUE_DEATH_DATE					"gnsdk_val_death_date"
/** @internal GNSDK_GDO_VALUE_DEATH_PLACE @endinternal
*  Retrieves a death place value from a GDO.
* @ingroup GDO_ValueKeys_Contributor
*/
#define GNSDK_GDO_VALUE_DEATH_PLACE					"gnsdk_val_death_place"
/** @internal GNSDK_GDO_VALUE_BIRTH_DEATH_LANGUAGE @endinternal
*  Retrieves the available language value for a returned GNSDK_GDO_VALUE_BIRTH_DEATH object.
*  <p><b>Remarks:</b></p>
*  Use this value to retrieve the actual language value of a returned object.
*  The language value of a returned object depends on availability. Information in the language set
for the locale may not be available, and the object's information may be available only in its
default official language. For example, if a locale's set language is Spanish, but the object's
information is available only in English, this value returns as English.
* @ingroup GDO_ValueKeys_Contributor
*/
#define GNSDK_GDO_VALUE_DEATH_PLACE_LANGUAGE		"gnsdk_val_death_place_language"

/** @internal GNSDK_GDO_VALUE_URL_GENRE_IMAGE @endinternal
*  Retrieves the (temporary) URL for the music genre art image.
*/
#define GNSDK_GDO_VALUE_URL_GENRE_IMAGE_75				"gnsdk_val_url_genre_75"
#define GNSDK_GDO_VALUE_URL_GENRE_IMAGE_170				"gnsdk_val_url_genre_170"
#define GNSDK_GDO_VALUE_URL_GENRE_IMAGE_300				"gnsdk_val_url_genre_300"
#define GNSDK_GDO_VALUE_URL_GENRE_IMAGE_450				"gnsdk_val_url_genre_450"
#define GNSDK_GDO_VALUE_URL_GENRE_IMAGE_720				"gnsdk_val_url_genre_720"
#define GNSDK_GDO_VALUE_URL_GENRE_IMAGE_1080			"gnsdk_val_url_genre_1080"

/** @internal GNSDK_GDO_VALUE_URL_IMAGE @endinternal
*  Retrieves the (temporary) URL for the image.
*/
#define GNSDK_GDO_VALUE_URL_IMAGE_75				"gnsdk_val_url_image_75"
#define GNSDK_GDO_VALUE_URL_IMAGE_75_OR_LARGER		GNSDK_GDO_VALUE_URL_IMAGE_75"_or_lg"
#define GNSDK_GDO_VALUE_URL_IMAGE_170				"gnsdk_val_url_image_170"
#define GNSDK_GDO_VALUE_URL_IMAGE_170_OR_SMALLER	GNSDK_GDO_VALUE_URL_IMAGE_170"_or_sm"
#define GNSDK_GDO_VALUE_URL_IMAGE_170_OR_LARGER		GNSDK_GDO_VALUE_URL_IMAGE_170"_or_lg"
#define GNSDK_GDO_VALUE_URL_IMAGE_300				"gnsdk_val_url_image_300"
#define GNSDK_GDO_VALUE_URL_IMAGE_300_OR_SMALLER	GNSDK_GDO_VALUE_URL_IMAGE_300"_or_sm"
#define GNSDK_GDO_VALUE_URL_IMAGE_300_OR_LARGER		GNSDK_GDO_VALUE_URL_IMAGE_300"_or_lg"
#define GNSDK_GDO_VALUE_URL_IMAGE_450				"gnsdk_val_url_image_450"
#define GNSDK_GDO_VALUE_URL_IMAGE_450_OR_SMALLER	GNSDK_GDO_VALUE_URL_IMAGE_450"_or_sm"
#define GNSDK_GDO_VALUE_URL_IMAGE_450_OR_LARGER		GNSDK_GDO_VALUE_URL_IMAGE_450"_or_lg"
#define GNSDK_GDO_VALUE_URL_IMAGE_720				"gnsdk_val_url_image_720"
#define GNSDK_GDO_VALUE_URL_IMAGE_720_OR_SMALLER	GNSDK_GDO_VALUE_URL_IMAGE_720"_or_sm"
#define GNSDK_GDO_VALUE_URL_IMAGE_720_OR_LARGER		GNSDK_GDO_VALUE_URL_IMAGE_720"_or_lg"
#define GNSDK_GDO_VALUE_URL_IMAGE_1080				"gnsdk_val_url_image_1080"
#define GNSDK_GDO_VALUE_URL_IMAGE_1080_OR_SMALLER	GNSDK_GDO_VALUE_URL_IMAGE_1080"_or_sm"

/** @internal GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE @endinternal
*  Retrieves the (temporary) URL for the video contributor image.
*/
#define GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_75				"gnsdk_val_url_vid_contrib_75"
#define GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_75_OR_LARGER	GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_75"_or_lg"
#define GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_170				"gnsdk_val_url_vid_contrib_170"
#define GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_170_OR_SMALLER	GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_170"_or_sm"
#define GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_170_OR_LARGER	GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_170"_or_lg"
#define GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_300				"gnsdk_val_url_vid_contrib_300"
#define GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_300_OR_SMALLER	GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_300"_or_sm"
#define GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_300_OR_LARGER	GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_300"_or_lg"
#define GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_450				"gnsdk_val_url_vid_contrib_450"
#define GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_450_OR_SMALLER	GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_450"_or_sm"
#define GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_450_OR_LARGER	GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_450"_or_lg"
#define GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_720				"gnsdk_val_url_vid_contrib_720"
#define GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_720_OR_SMALLER	GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_720"_or_sm"
#define GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_720_OR_LARGER	GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_720"_or_lg"
#define GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_1080			"gnsdk_val_url_vid_contrib_1080"
#define GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_1080_OR_SMALLER	GNSDK_GDO_VALUE_URL_VIDEO_CONTRIBUTOR_IMAGE_1080"_or_sm"

/** @internal GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE @endinternal
*  Retrieves the (temporary) URL for the music contributor image.
*/
#define GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_75				"gnsdk_val_url_music_contrib_75"
#define GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_75_OR_LARGER	GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_75"_or_lg"
#define GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_170				"gnsdk_val_url_music_contrib_170"
#define GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_170_OR_SMALLER	GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_170"_or_sm"
#define GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_170_OR_LARGER	GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_170"_or_lg"
#define GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_300				"gnsdk_val_url_music_contrib_300"
#define GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_300_OR_SMALLER	GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_300"_or_sm"
#define GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_300_OR_LARGER	GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_300"_or_lg"
#define GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_450				"gnsdk_val_url_music_contrib_450"
#define GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_450_OR_SMALLER	GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_450"_or_sm"
#define GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_450_OR_LARGER	GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_450"_or_lg"
#define GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_720				"gnsdk_val_url_music_contrib_720"
#define GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_720_OR_SMALLER	GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_720"_or_sm"
#define GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_720_OR_LARGER	GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_720"_or_lg"
#define GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_1080			"gnsdk_val_url_music_contrib_1080"
#define GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_1080_OR_SMALLER	GNSDK_GDO_VALUE_URL_MUSIC_CONTRIBUTOR_IMAGE_1080"_or_sm"

/** @internal GNSDK_GDO_VALUE_URL_TVCHANNEL_IMAGE @endinternal
*  Retrieves the (temporary) URL for the contributor image.
*/
#define GNSDK_GDO_VALUE_URL_TVCHANNEL_IMAGE_110					"gnsdk_val_url_ch_110"
#define GNSDK_GDO_VALUE_URL_TVCHANNEL_IMAGE_110_OR_LARGER		GNSDK_GDO_VALUE_URL_TVCHANNEL_IMAGE_110"_or_sm"
#define GNSDK_GDO_VALUE_URL_TVCHANNEL_IMAGE_220					"gnsdk_val_url_ch_220"
#define GNSDK_GDO_VALUE_URL_TVCHANNEL_IMAGE_220_OR_SMALLER		GNSDK_GDO_VALUE_URL_TVCHANNEL_IMAGE_220"_or_sm"


/*****************************************************************************
** GDO Keys specific to ALBUM responses
*/

/*
 * GDO Types
 * One of these types will be the string returned by
 * gnsdk_manager_gdo_get_type() for any returned GDO
 */

/** @internal GNSDK_GDO_TYPE_RESPONSE_MATCH @endinternal
* The type for GDOs returned from calls to gnsdk_musicid_query_find_matches().
* Indicates that the GDO is a response object containing 0-n "match" children, which can be of various types.
* @ingroup GDO_Types_Music
*/
#define GNSDK_GDO_TYPE_RESPONSE_MATCH			"gnsdk_ctx_response_match"

/** @internal GNSDK_GDO_CHILD_MATCH @endinternal
* This key allows you to iterate over the "matches" returned by gnsdk_musicid_query_find_matches().
* For each match that is returned, you can inspect its type to see what kind of a GDO you have.
* @ingroup GDO_Types_Music
*/
#define GNSDK_GDO_CHILD_MATCH						GNSDK_GDO_TYPE_RESPONSE_MATCH"!"

/** @internal GNSDK_GDO_TYPE_RESPONSE_ALBUM @endinternal
*  GDO is of album response type.
*  <p><b>Remarks:</b></p>
*  Value is used as return value for <code>gnsdk_manager_gdo_get_type</code>.
*  Album response types are returned from query APIs of GNSDKs that return album content. An
album response type contains one or more GNSDK_GDO_TYPE_ALBUM child types.
* @ingroup GDO_Types_Music
*/
#define GNSDK_GDO_TYPE_RESPONSE_ALBUM			"gnsdk_ctx_response_album"
/** @internal GNSDK_GDO_TYPE_RESPONSE_TRACK @endinternal
*  GDO is of track response type.
* @ingroup GDO_Types_Music
*/
#define GNSDK_GDO_TYPE_RESPONSE_TRACK			"gnsdk_ctx_response_track"
/** @internal GNSDK_GDO_TYPE_ALBUM @endinternal
*  GDO is of album type.
*  <p><b>Remarks:</b></p>
*  Value is used as return value for <code>gnsdk_manager_gdo_get_type</code>.
*   Album types are retrieved from GNSDK_GDO_TYPE_RESPONSE_ALBUM types through
<code>gnsdk_manager_gdo_child_get</code> with the GNSDK_GDO_CHILD_ALBUM key.
*  This type supports Link data.
* @ingroup GDO_Types_Music
*/
#define GNSDK_GDO_TYPE_ALBUM						"gnsdk_ctx_album"
/** @internal GNSDK_GDO_TYPE_TRACK @endinternal
*  GDO is of track type.
*  <p><b>Remarks:</b></p>
*  Value is used as return value for <code>gnsdk_manager_gdo_get_type</code>.
*  Track types are retrieved from GNSDK_GDO_TYPE_ALBUM types through
<code>gnsdk_manager_gdo_child_get</code> with one of the GNSDK_GDO_CHILD_TRACK keys.
*  This type supports Link data.
* @ingroup GDO_Types_Music
*/
#define GNSDK_GDO_TYPE_TRACK						"gnsdk_ctx_track"
/** @internal GNSDK_GDO_TYPE_NAME @endinternal
  *
  *   GDO is of a Name type.
* @ingroup GDO_Types_Name
*/
#define GNSDK_GDO_TYPE_NAME						"gnsdk_ctx_name"
/** @internal GNSDK_GDO_TYPE_TITLE @endinternal
  *
  *   GDO is of a Title type.
* @ingroup GDO_Types_Title
*/
#define GNSDK_GDO_TYPE_TITLE						"gnsdk_ctx_title"
/** @internal GNSDK_GDO_TYPE_CREDIT @endinternal
  *
  *   GDO is of a Credit type.
* @ingroup GDO_Types_Credit
*/
#define GNSDK_GDO_TYPE_CREDIT					"gnsdk_ctx_credit"
/** @internal GNSDK_GDO_TYPE_ARTIST @endinternal
  *
  *   GDO is of an Artist type.
* @ingroup GDO_Types_Artist
*/
#define GNSDK_GDO_TYPE_ARTIST					"gnsdk_ctx_artist"
/** @internal GNSDK_GDO_TYPE_AUDIO_WORK @endinternal
*  GDO is of an audio work type.
* @ingroup GDO_Types_Music
*/
#define GNSDK_GDO_TYPE_AUDIO_WORK				"gnsdk_ctx_audio_work"

/*
 * GDO Type Keys
 * For retrieving specific types from a GDO.
 * Actual type returned will be one of the defined types above.
 */

/** @internal GNSDK_GDO_CHILD_ALBUM @endinternal
*  Retrieves a child album type.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for <code>gnsdk_manager_gdo_child_get</code> to retrieve child
GNSDK_GDO_TYPE_ALBUM GDOs.
*  The ordinal parameter for <code>gnsdk_manager_gdo_child_get</code> with this key indicates the n'th child
album to retrieve.
*  Album types are generally available from GNSDK_GDO_TYPE_RESPONSE_ALBUM GDOs.
* @ingroup GDO_ChildKeys_Music
*/
#define GNSDK_GDO_CHILD_ALBUM						GNSDK_GDO_TYPE_ALBUM"!"
/** @internal GNSDK_GDO_CHILD_TRACK @endinternal
*  Retrieves a child track type.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for <code>gnsdk_manager_gdo_child_get</code> to retrieve child
*  GNSDK_GDO_TYPE_TRACK GDOs.
*  The ordinal parameter for <code>gnsdk_manager_gdo_child_get</code> with this key indicates the n'th child
track to retrieve.
*  Track types are generally available from GNSDK_GDO_TYPE_ALBUM
*  GDOs.
* @ingroup GDO_ChildKeys_Music
*/
#define GNSDK_GDO_CHILD_TRACK						GNSDK_GDO_TYPE_TRACK"!"
/** @internal GNSDK_GDO_CHILD_TRACK_BY_NUMBER @endinternal
*  Retrieves a child track type matching the given track number.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for <code>gnsdk_manager_gdo_child_get</code> to retrieve child
*  GNSDK_GDO_TYPE_TRACK GDOs.
*  The ordinal parameter for <code>gnsdk_manager_gdo_child_get</code> with this key indicates the track number of
the child track to retrieve.
*
*  Track types are generally available from GNSDK_GDO_TYPE_ALBUM GDOs.
* @ingroup GDO_ChildKeys_Music
*/
#define GNSDK_GDO_CHILD_TRACK_BY_NUMBER				GNSDK_GDO_TYPE_TRACK"!number"
/** @internal GNSDK_GDO_CHILD_TRACK_MATCHED @endinternal
*  Retrieves a child track type that was matched.
*  GNSDK_GDO_CHILD_TRACK_MATCHED
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for gnsdk_manager_gdo_child_get to retrieve child
*  GNSDK_GDO_TYPE_TRACK GDOs.
*  A child track is marked as matching for some queries that can match to a
specific track. It is not always the case that there will be child track types marked as matching.
*  Track types are generally available from GNSDK_GDO_TYPE_ALBUM GDOs.
* @ingroup GDO_ChildKeys_Music
*/
#define GNSDK_GDO_CHILD_TRACK_MATCHED				GNSDK_GDO_TYPE_TRACK"!matching"

/** @internal GNSDK_GDO_VALUE_INPUT_TOC_ALBUM @endinternal
*  Retrieves the TOC used to look up the album. Only present in albums retrieved by TOC lookups.
* @ingroup GDO_ChildKeys_Music
*/
#define GNSDK_GDO_VALUE_INPUT_TOC_ALBUM						"gnsdk_val_input_toc_alb"

/** @internal GNSDK_GDO_VALUE_USER_DATA @endinternal
*  For albums coming out of a Supplemental Storage, this is the user data associated with
*  the album when it was added to the store.
* @ingroup GDO_ChildKeys_Music
*/
#define GNSDK_GDO_VALUE_USER_DATA						"gnsdk_val_userdata"

/** @internal GNSDK_GDO_CHILD_NAME_OFFICIAL @endinternal
  *
  *   Retrieves the official child name GDO.
* @ingroup GDO_ChildKeys_Name
*/
#define GNSDK_GDO_CHILD_NAME_OFFICIAL					GNSDK_GDO_TYPE_NAME"!off"
/** @internal GNSDK_GDO_CHILD_NAME_REGIONAL @endinternal
  *
  *   Retrieves a regional child name GDO.
* @ingroup GDO_ChildKeys_Name
*/
#define GNSDK_GDO_CHILD_NAME_REGIONAL					GNSDK_GDO_TYPE_NAME"!reg"
/** @internal GNSDK_GDO_CHILD_NAME_REGIONAL_LOCALE @endinternal
  *
  *   Retrieves a regional child name GDO that matches current locale.
* @ingroup GDO_ChildKeys_Name
*/
#define GNSDK_GDO_CHILD_NAME_REGIONAL_LOCALE			GNSDK_GDO_TYPE_NAME"!loc"
/** @internal GNSDK_GDO_CHILD_NAME_BRAND @endinternal
  *
  *   Retrieves an child brand name GDO. Supported by Video Advert objects.
* @ingroup GDO_ChildKeys_Name
*/
#define GNSDK_GDO_CHILD_NAME_BRAND						GNSDK_GDO_TYPE_NAME"!brand"
/** @internal GNSDK_GDO_CHILD_TITLE_OFFICIAL @endinternal
  *
  *   Retrieves the official child title GDO.
* @ingroup GDO_ChildKeys_Title
*/
#define GNSDK_GDO_CHILD_TITLE_OFFICIAL					GNSDK_GDO_TYPE_TITLE"!off"
/** @internal GNSDK_GDO_CHILD_TITLE_REGIONAL @endinternal
  *
  *   Retrieves a regional child title GDO.
* @ingroup GDO_ChildKeys_Title
*/
#define GNSDK_GDO_CHILD_TITLE_REGIONAL					GNSDK_GDO_TYPE_TITLE"!orv"
/** @internal GNSDK_GDO_CHILD_TITLE_REGIONAL_LOCALE @endinternal
  *
  *   Retrieves a regional child title GDO that matches current locale.
* @ingroup GDO_ChildKeys_Title
*/
#define GNSDK_GDO_CHILD_TITLE_REGIONAL_LOCALE			GNSDK_GDO_TYPE_TITLE"!loc"
/** @internal GNSDK_GDO_CHILD_TITLE_TLS @endinternal
  *
  *   Retrieves the TLS child title GDO.
* @ingroup GDO_ChildKeys_Title
*/
#define GNSDK_GDO_CHILD_TITLE_TLS						GNSDK_GDO_TYPE_TITLE"!tls"

/** @internal GNSDK_GDO_CHILD_AUDIO_WORK @endinternal
*  Retrieves a child audio work type.
* @ingroup GDO_ChildKeys_Music
*/
#define GNSDK_GDO_CHILD_AUDIO_WORK					GNSDK_GDO_TYPE_AUDIO_WORK"!"
/** @internal GNSDK_GDO_CHILD_CREDIT @endinternal
  *
  *   Retrieves a child credit type. For music types, this includes
  *   all credits except the artist credit.
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT						GNSDK_GDO_TYPE_CREDIT"!"

/** @internal GNSDK_GDO_CHILD_CREDIT_SERIES @endinternal
  *
  *   Retrieve a child credit of a Series type.
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_SERIES				GNSDK_GDO_TYPE_CREDIT"!series"
/** @internal GNSDK_GDO_CHILD_CREDIT_SEASON @endinternal
  *
  *   Retrieve a child credit of a Season type.
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_SEASON				GNSDK_GDO_TYPE_CREDIT"!season"
/** @internal GNSDK_GDO_CHILD_CREDIT_WORK_NONSERIES @endinternal
  *
  *   Retrieve a child credit of a Works non-Series type.
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_WORK_NONSERIES		GNSDK_GDO_TYPE_CREDIT"!worknonseries"

/** @internal GNSDK_GDO_CHILD_ARTIST @endinternal
  *
  * Artist credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_ARTIST				GNSDK_GDO_TYPE_ARTIST"!"

/** @internal GNSDK_GDO_CHILD_CREDIT_AUTHOR @endinternal
* @ingroup GDO_ChildKeys_Credit
 */
#define GNSDK_GDO_CHILD_CREDIT_AUTHOR				GNSDK_GDO_TYPE_CREDIT"!author"

/** @internal GNSDK_GDO_CHILD_CREDIT_ACTOR @endinternal
  *
   * Actor credit
   * @ingroup GDO_ChildKeys_Credit
 */
#define GNSDK_GDO_CHILD_CREDIT_ACTOR				GNSDK_GDO_TYPE_CREDIT"!actor"

/** @internal GNSDK_GDO_CHILD_CREDIT_DIRECTOR @endinternal
  *
  * Director credit
  * @ingroup GDO_ChildKeys_Credit
 */
#define GNSDK_GDO_CHILD_CREDIT_DIRECTOR				GNSDK_GDO_TYPE_CREDIT"!director"

/** @internal GNSDK_GDO_CHILD_CREDIT_EXECUTIVE_PRODUCER @endinternal
  *
  * Executive producer credit
  * @ingroup GDO_ChildKeys_Credit
 */
#define GNSDK_GDO_CHILD_CREDIT_EXECUTIVE_PRODUCER	GNSDK_GDO_TYPE_CREDIT"!executiveproduder"

/** @internal GNSDK_GDO_CHILD_CREDIT_PRODUCER @endinternal
  *
  * Producer credit
  * @ingroup GDO_ChildKeys_Credit
 */
#define GNSDK_GDO_CHILD_CREDIT_PRODUCER				GNSDK_GDO_TYPE_CREDIT"!producer"

/** @internal GNSDK_GDO_CHILD_CREDIT_NARRATOR @endinternal
  *
  * Narrator voice credit
  * @ingroup GDO_ChildKeys_Credit
 */
#define GNSDK_GDO_CHILD_CREDIT_NARRATOR				GNSDK_GDO_TYPE_CREDIT"!narrator"

/*
 * <p><b>GDO Value Keys</b></p>
 * For retrieving values from GDO. Values may or may not exist, or have
 * different values depending on the type of the GDO.
 */

/** @internal GNSDK_GDO_VALUE_PACKAGE_LANGUAGE @endinternal
*  Retrieves a language value from a GDO as the ISO code (for example, "eng").
*  <p><b>Remarks:</b></p>
*  GNSDK supports a subset of the ISO 639-2 Language Code List. For more information, refer to ISO
639-2 Language Code List: Codes for the representation of names of languages.
*  Specify a locale language's lower-case three-letter code, which is shown in the macro's C/C++
syntax section.
* <p><b>Note:</b></p>
*   The following languages use Gracenote-specific three-letter codes:
*  <ul>
*  <li>qtb (Simplified Chinese)*
*  <li>qtd (Traditional Chinese)*
*  </ul>
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_PACKAGE_LANGUAGE				"gnsdk_val_pkglang"
/** @internal GNSDK_GDO_VALUE_PACKAGE_LANGUAGE_DISPLAY @endinternal
*  Retrieves the package language as text (for example, "English").
*  <p><b>Remarks:</b></p>
*  Use this value to retrieve the actual language value of a returned object.
*  The language value of a returned object depends on availability. Information in the language set
for the locale may not be available, and the object's information may be available only in its
default official language. For example, if a locale's set language is Spanish, but the object's
information is available only in English, this value returns as English.
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_PACKAGE_LANGUAGE_DISPLAY		"gnsdk_val_pkglang_display"

/** @internal GNSDK_GDO_VALUE_SORTABLE_LANGUAGE @endinternal
*  Retrieves the available language value for a returned GNSDK_GDO_VALUE_TITLE_SORTABLE object.
*  <p><b>Remarks:</b></p>
*  Use this value to retrieve the actual language for the associated sortable display value.
*  The language value of a returned object depends on availability. Information in the language set
for the locale may not be available, and the object's information may be available only in its
default official language. For example, if a locale's set language is Spanish, but the object's
information is available only in English, this value returns as English.
* @ingroup GDO_ValueKeys_Title
*/
#define GNSDK_GDO_VALUE_SORTABLE_LANGUAGE			"gnsdk_val_title_sortable_language"

/** @internal GNSDK_GDO_VALUE_LYRICIST @endinternal
*  Retrieves a lyricist value from a GDO.
* @ingroup GDO_ValueKeys_Lyric
*/
#define GNSDK_GDO_VALUE_LYRICIST					"gnsdk_val_lyricist"
/** @internal GNSDK_GDO_VALUE_PUBLISHER @endinternal
*  Retrieves a publisher value from a GDO.
* @ingroup GDO_ValueKeys_Lyric
*/
#define GNSDK_GDO_VALUE_PUBLISHER					"gnsdk_val_publisher"
/** @internal GNSDK_GDO_VALUE_YEAR @endinternal
*  Retrieves a year value from a GDO.
*  <p><b>Remarks:</b></p>
*  For album types, this retrieves the album year. For track types, this retrieves the
track year. Album and track date values are not always available.
*  As this is a unique value, the ordinal parameter for gnsdk_manager_gdo_value_get must be set to 1
to retrieve the first (or only) value instance.
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_YEAR						"gnsdk_val_year"
/** @internal GNSDK_GDO_VALUE_DATE_RELEASE @endinternal
*  Retrieves a release date value from a GDO.
*  <p><b>Remarks:</b></p>
*  For video Features or video Products, this retrieves the respective video item release date.
Release date values are not always available.
*  As this is a unique value, the ordinal parameter for gnsdk_manager_gdo_value_get must be set to 1
to retrieve the first (or only) value instance.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_DATE_RELEASE				"gnsdk_val_daterel"
/** @internal GNSDK_GDO_VALUE_ALBUM_LABEL @endinternal
*  Retrieves an album label value from a GDO.
*  <p><b>Remarks:</b></p>
*  For album types, this retrieves the name of the record company that released the album.
*  Album label values are not always available.
*  As this is a unique value, the ordinal parameter for gnsdk_manager_gdo_value_get must be set to 1
to retrieve the first (or only) value instance.
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_ALBUM_LABEL					"gnsdk_val_albumlabel"
/** @internal GNSDK_GDO_VALUE_ALBUM_TRACK_COUNT @endinternal
*  Retrieves the total number of tracks on an album.
*  <p><b>Remarks:</b></p>
*  For album types, this retrieves the total number of tracks on the album.
*  As this is a unique value, the ordinal parameter for gnsdk_manager_gdo_value_get must be set to 1
to retrieve the first (or only) value instance.
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_ALBUM_TRACK_COUNT			"gnsdk_val_albumtrackcnt"
/** @internal GNSDK_GDO_VALUE_ALBUM_TOTAL_IN_SET @endinternal
*  Retrieves the total discs in set value from a GDO.
*  <p><b>Remarks:</b></p>
*  For album types, this retrieves the total number of volumes in a multi-volume set; note that
this value is not always available.
*  As this is a unique value, the ordinal parameter for gnsdk_manager_gdo_value_get must be set to 1
to retrieve the first (or only) value instance.
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_ALBUM_TOTAL_IN_SET			"gnsdk_val_albumtotalset"
/** @internal GNSDK_GDO_VALUE_ALBUM_DISC_IN_SET @endinternal
*  Retrieves a disc number value from a GDO.
*  <p><b>Remarks:</b></p>
*  For album types, this retrieves the volume number of this album in a multi-volume set; note
that this value is not always available.
*  As this is a unique value, the ordinal parameter for gnsdk_manager_gdo_value_get must be set to 1
to retrieve the first (or only) value instance.
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_ALBUM_DISC_IN_SET			"gnsdk_val_albumdiscset"
/** @internal GNSDK_GDO_VALUE_ALBUM_COMPILATION @endinternal
*  Retrieves an album compilation value from a GDO.
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_ALBUM_COMPILATION			"gnsdk_val_albumcompflag"
/** @internal GNSDK_GDO_VALUE_TRACK_NUMBER @endinternal
*  Retrieves a track number value from a GDO.
*  <p><b>Remarks:</b></p>
*  For track types, this retrieves the number for the track as assigned by its order on the
album.
*  As this is a unique value, the ordinal parameter for gnsdk_manager_gdo_value_get must be set to 1
to retrieve the first (or only) value instance.
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_TRACK_NUMBER				"gnsdk_val_tracknumber"
/** @internal GNSDK_GDO_VALUE_TRACK_MATCHED_NUM @endinternal
*  Retrieves a numeric value indicating the track number of the matching track (if applicable) for
the source query
*  <p><b>Remarks:</b></p>
*  Only valid for album_gdos, and is set if a matched track is found. This value is only available in file based queries when a track is matched. 
This will be the case for audio fingerprint queries and sometimes for text based queries.
*  This value is unique, so the ordinal parameter for gnsdk_manager_gdo_value_get should be set to
1.
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_TRACK_MATCHED_NUM			"gnsdk_val_track_matched"
/** @internal GNSDK_GDO_VALUE_TRACK_MATCHED_POSITION @endinternal
*
* @deprecated NB: This key has been marked as deprecated and will be removed from the next major release.
*	Please use GNSDK_GDO_VALUE_MATCH_POSITION_MS instead.
*
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_TRACK_MATCHED_POSITION		GNSDK_GDO_VALUE_MATCH_POSITION_MS

#define GNSDK_GDO_VALUE_TRACK_MATCHED_IDENT			"gnsdk_val_track_matched_ident"
#define GNSDK_GDO_VALUE_ALBUMID_MATCH_SCORE			"gnsdk_val_albumid_match_score"
#define GNSDK_GDO_VALUE_TRACK_MATCH_TYPE			"gnsdk_val_track_match_type"

/** @internal GNSDK_GDO_VALUE_TEXT_MATCH_SCORE @endinternal
*  Retrieve a match score value for the result.
*  <p><b>Remarks:</b></p>
*  Based on text input, GNSDK Manager generates a match confidence score for results of a top-level
object, for Album, Lyric, and Track text results. The returned results are of the type GNSDK_GDO_TYPE_RESPONSE_*,
specifically:
*  <ul>
*  <li>GNSDK_GDO_TYPE_RESPONSE_ALBUM
*  <li>GNSDK_GDO_TYPE_RESPONSE_LYRIC
*  <li>GNSDK_GDO_TYPE_RESPONSE_TRACK
*  </ul>
*  To get the match score:
*  <ol>
*  <li>Use gnsdk_manager_gdo_child_get to retrieve the appropriate child GDO from the response.
*  <li>Use gnsdk_manager_gdo_value_get with GNSDK_GDO_VALUE_TEXT_MATCH_SCORE to retrieve the score
of the match to the given Album, Lyric, or Track result. The score ranges from 0-100. 
* Note the following:
*  <ul>
*  <li>The match score is only useful in comparison to other match scores. By itself, it does not
indicate a strong or poor match. For example, the result text could be substantially different from the input text because the input text contained a lot of incorrect information. Such a response indicates that the results have an amount of ambiguity that the application must resolve.
*  <li>Only text input is valid. Any other input type (such as TOC) is invalid.
*  </ul>
*  </ol>
*
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_TEXT_MATCH_SCORE			"gnsdk_val_txtmatchscore"

/** @internal GNSDK_GDO_VALUE_FULL_RESULT @endinternal
*  Retrieves a value indicating if a GDO type response result is full (not partial). Returns 1 if
full, 0 if partial.
*  <p><b>Remarks:</b></p>
*  Available for the following music and video types:
*  <ul>
*  <li>GNSDK_GDO_TYPE_ALBUM
*  <li>GNSDK_GDO_TYPE_CONTRIBUTOR
*  <li>GNSDK_GDO_TYPE_LYRIC
*  <li>GNSDK_GDO_TYPE_TRACK
*  <li>GNSDK_GDO_TYPE_VIDEO_PRODUCT
*  <li>GNSDK_GDO_TYPE_VIDEO_SEASON
*  <li>GNSDK_GDO_TYPE_VIDEO_SERIES
*  <li>GNSDK_GDO_TYPE_VIDEO_WORK
*  </ul>
* <p><b>Note:</b></p>
*   What constitutes a full result varies among the individual response types and results, and also
depends on data availability.
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_FULL_RESULT							"gnsdk_val_full_result"

/** @internal GNSDK_GDO_VALUE_COLLABORATOR_RESULT @endinternal
* Retrieves a value indicating whether a contributor response GDO matched on the primary collaborator 
* for an input collaboration string, rather than on the collaboration. If your input text represents 
* a collaboration, but that collaboration is not found, Gracenote attempts to find the primary collaborator 
* instead. If it is able to find the primary collaborator, it returns results for that collaborator, 
* and the GNSDK_GDO_VALUE_COLLABORATOR_RESULT key is set to TRUE. This indicates that your input is 
* a collaboration, but you only matched the primary collaborator. This allows you to distinguish this case 
* from a situation in which the input was a single artist, and a single artist was identified.
*
* If the key is FALSE, the result is a single artist that matched your input text (for example, "Santana").
*
* If the key is TRUE, your input is a collaboration (for example, "Santana featuring Unknown Artist"), but 
* you only matched the primary collaborator, so the single artist object is returned (for example, "Santana").
*
*  <p><b>Remarks:</b></p>
*  Available for the following music types:
*  <ul>
*  <li>GNSDK_GDO_TYPE_CONTRIBUTOR
*  </ul>
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_COLLABORATOR_RESULT					"gnsdk_val_collab_result"

/** @internal GNSDK_GDO_VALUE_MATCH_POSITION_MS @endinternal
* For streaming matches, this indicates the position (in milliseconds)
* in the matched object where the fingerprint match occurred. 
*
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_MATCH_POSITION_MS					"gnsdk_val_match_pos_ms"

/** @internal GNSDK_GDO_VALUE_CURRENT_POSITION_MS @endinternal
* For streaming matches, this indicates the current position (in milliseconds)
* in the matched object. This is the GNSDK_GDO_VALUE_MATCH_POSITION_MS plus
* the amount of time that it took the query to complete.
*
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_CURRENT_POSITION_MS					"gnsdk_val_current_pos_ms"

/** @internal GNSDK_GDO_VALUE_ADJUSTED_MATCH_POSITION_MS @endinternal
*
* @deprecated NB: This key has been marked as deprecated and will be removed from the next major release.
*	Use GNSDK_GDO_VALUE_CURRENT_POSITION_MS instead.
*
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_ADJUSTED_MATCH_POSITION_MS			GNSDK_GDO_VALUE_CURRENT_POSITION_MS

/** @internal GNSDK_GDO_VALUE_MATCH_DURATION_MS @endinternal
* For MusicID-Stream fingerprint matches, this indicates the length of the audio that was used to match (i.e. the length of the matched query fingerprint).
*
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_MATCH_DURATION_MS						"gnsdk_val_match_duration_ms"

/** @internal GNSDK_GDO_VALUE_FP_DURATION_MS @endinternal
* For fingerprint matches, this indicates the total length of the reference audio (fingerprint)
* for the matched object. 
*
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_FP_DURATION_MS							"gnsdk_val_fp_duration_ms"

/** @internal GNSDK_GDO_VALUE_GENRE_LEVEL1 @endinternal
*  Retrieves a genre value from a GDO; applicable for music or video data.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to <code>gnsdk_manager_locale_load</code>.
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
*
*  When retrieving classical music data, genre data may be enhanced at the Track level.
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_GENRE_LEVEL1						"gnsdk_val_list_l1genre"
/** @internal GNSDK_GDO_VALUE_GENRE_LEVEL2 @endinternal
*  Retrieves a genre meta group value from a GDO; applicable for music or video data.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to <code>gnsdk_manager_locale_load</code>.
*
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_GENRE_LEVEL2						"gnsdk_val_list_l2genre"
/** @internal GNSDK_GDO_VALUE_GENRE_LEVEL3 @endinternal
*  Retrieves a genre micro group value from a GDO; applicable for music or video data.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to <code>gnsdk_manager_locale_load</code>.
*
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_GENRE_LEVEL3						"gnsdk_val_list_l3genre"

/** @internal GNSDK_GDO_VALUE_ARTISTTYPE_LEVEL1 @endinternal
  * Retrieves a level-1 artist type value from a GDO.
  * @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_ARTISTTYPE_LEVEL1					"gnsdk_val_list_l1arttype"
/** @internal GNSDK_GDO_VALUE_ARTISTTYPE_LEVEL2 @endinternal
  * Retrieves a level-2 artist type value from a GDO.
  * @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_ARTISTTYPE_LEVEL2					"gnsdk_val_list_l2arttype"

/** @internal GNSDK_GDO_VALUE_ROLE_CATEGORY @endinternal
*  Retrieves a role category credit value from a GDO.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to <code>gnsdk_manager_locale_load</code>.
*  To render locale-dependent information for list-based values, the application must call
gnsdk_manager_locale_load and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Role
*/

#define GNSDK_GDO_VALUE_ROLE_CATEGORY						"gnsdk_val_role_cat"
/** @internal GNSDK_GDO_VALUE_ROLE @endinternal
*  Retrieves a role value from a GDO.
*  <p><b>Remarks:</b></p>
*  This value shows the role that a person played in a music or video production; for example,
singing, playing an instrument, acting, directing, and so on.
* <p><b>Note:</b></p>
*  For music credits, the absence of a role for a person indicates that person is the primary
artist, who may have performed multiple roles.
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to <code>gnsdk_manager_locale_load</code>.
*
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Role
*/
#define GNSDK_GDO_VALUE_ROLE						"gnsdk_val_role"
/** @internal GNSDK_GDO_VALUE_ROLE_BILLING @endinternal
*  Retrieves a role billing value from a GDO.
* @ingroup GDO_ValueKeys_Role
*/
#define GNSDK_GDO_VALUE_ROLE_BILLING				"gnsdk_val_role_billing"
/** @internal GNSDK_GDO_VALUE_ORIGIN_LEVEL1 @endinternal
* Retrieves a level-1 origin value from a GDO.
* <p><b>Remarks:</b></p>
* This is a list-based value requiring that the list be loaded into memory through a 
* successful call to gnsdk_manager_locale_load().
* To render locale-dependent information for list-based values, the application must call
* gnsdk_manager_locale_load() and possibly also gnsdk_manager_gdo_set_locale(). The 
* application returns a <code>LocaleNotLoaded</code> message when locale information is 
* not set prior to a request for list-based value information.
*
* When retrieving classical music data, origin data may be available at the Album, Track, 
* and Composer credit level.
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_ORIGIN_LEVEL1				"gnsdk_val_list_l1origin"
/** @internal GNSDK_GDO_VALUE_ORIGIN_LEVEL2 @endinternal
*  Retrieves a level-2 origin value from a GDO.
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_ORIGIN_LEVEL2				"gnsdk_val_list_l2origin"
/** @internal GNSDK_GDO_VALUE_ORIGIN_LEVEL3 @endinternal
*  Retrieves a level-3 origin value from a GDO.
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_ORIGIN_LEVEL3				"gnsdk_val_list_l3origin"
/** @internal GNSDK_GDO_VALUE_ORIGIN_LEVEL4 @endinternal
*  Retrieves a level-4 origin value from a GDO.
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_ORIGIN_LEVEL4				"gnsdk_val_list_l4origin"

/** @internal GNSDK_GDO_VALUE_ERA_LEVEL1 @endinternal
*  Retrieves a level-1 classical musical era value from a GDO.
*  <p><b>Remarks:</b></p>
*  When retrieving classical music data, era data may be available at the Album, Track, and Composer
credit level.
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_ERA_LEVEL1					"gnsdk_val_desc_l1era"
/** @internal GNSDK_GDO_VALUE_ERA_LEVEL2 @endinternal
*  Retrieves a level-2 classical musical era value from a GDO.
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_ERA_LEVEL2					"gnsdk_val_desc_l2era"
/** @internal GNSDK_GDO_VALUE_ERA_LEVEL3 @endinternal
*  Retrieves a level-3 classical musical era value from a GDO.
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_ERA_LEVEL3					"gnsdk_val_desc_l3era"

/** @internal GNSDK_GDO_VALUE_COMPOSITION_FORM @endinternal
*  Retrieves a classical music composition form value (for example, Symphony) from a GDO.
*  <p><b>Remarks:</b></p>
*  Use this value to retrieve the compositional form of a musical work, such as Chamber Music or
Symphony, at the Track level.
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_COMPOSITION_FORM			"gnsdk_val_desc_compform"
/** @internal GNSDK_GDO_VALUE_CLASSICAL_DATA @endinternal
*  Retrieves a boolean value (Y/N) that indicates whether enhanced classical music data exists in
the GDO.
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_CLASSICAL_DATA				"gnsdk_val_classical_data"


/*****************************************************************************
** GDO Keys specific to LYRIC responses
*/

/** @internal GNSDK_GDO_TYPE_RESPONSE_LYRIC @endinternal
*  GDO is of lyric response type.
*  <p><b>Remarks:</b></p>
*  Value is used as return value for <code>gnsdk_manager_gdo_get_type</code>.
*  Lyric response types are returned from query APIs of GNSDKs that return lyric content. A lyric
response type contains one or more GNSDK_GDO_TYPE_LYRIC child types.
* @ingroup GDO_Types_Lyric
*/
#define GNSDK_GDO_TYPE_RESPONSE_LYRIC			"gnsdk_ctx_response_lyric"
/** @internal GNSDK_GDO_TYPE_LYRIC @endinternal
*  GDO is of lyric type.
*  <p><b>Remarks:</b></p>
*  Value is used as return value for <code>gnsdk_manager_gdo_get_type</code>.
*  Lyric types are retrieved from GNSDK_GDO_TYPE_RESPONSE_LYRIC types through
gnsdk_manager_gdo_child_get with the GNSDK_GDO_CHILD_LYRIC key.
* @ingroup GDO_Types_Lyric
*/
#define GNSDK_GDO_TYPE_LYRIC						"gnsdk_ctx_lyric"
/** @internal GNSDK_GDO_TYPE_LYRIC_SAMPLE @endinternal
*  GDO is of lyric sample type.
*  <p><b>Remarks:</b></p>
*  Value is used as return value for <code>gnsdk_manager_gdo_get_type</code>.
*  Lyric sample types are retrieved from GNSDK_GDO_TYPE_LYRIC types through
gnsdk_manager_gdo_child_get with the GNSDK_GDO_CHILD_LYRIC_SAMPLE key.
* @ingroup GDO_Types_Lyric
*/
#define GNSDK_GDO_TYPE_LYRIC_SAMPLE				"gnsdk_ctx_lyricsample"

/*
 * GDO Type Keys
 * For retrieving specific types from a GDO.
 * Actual type returned will be one of the defined types above.
 */

/** @internal GNSDK_GDO_CHILD_LYRIC @endinternal
*  Retrieves a child lyric type.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for gnsdk_manager_gdo_child_get to retrieve child
*  GNSDK_GDO_TYPE_LYRIC GDOs.
*  The ordinal parameter for <code>gnsdk_manager_gdo_child_get</code> with this key indicates the n'th child
lyric to retrieve.
*  Lyric types are generally available from GNSDK_GDO_TYPE_RESPONSE_LYRIC GDOs.
* @ingroup GDO_ChildKeys_Lyric
*/
#define GNSDK_GDO_CHILD_LYRIC						GNSDK_GDO_TYPE_LYRIC"!"
/** @internal GNSDK_GDO_CHILD_LYRIC_SAMPLE @endinternal
*  Retrieves a lyric sample type (from lyric response GDO).
*  <ul>
*  <li>GNSDK_GDO_CHILD_LYRIC_SAMPLE</li>
*  <li>GNSDK_GDO_TYPE_RESPONSE_LYRIC</li>
*  </ul>
* @ingroup GDO_ChildKeys_Lyric
*/
#define GNSDK_GDO_CHILD_LYRIC_SAMPLE				GNSDK_GDO_TYPE_LYRIC_SAMPLE"!"
/** @internal GNSDK_GDO_VALUE_LYRIC_LINE @endinternal
*  Retrieves a line of a lyric from a lyric sample GDO.
*  <p><b>Remarks:</b></p>
*  For lyric sample types, this retrieves a lyric line.
*  There can be multiples of this value, so the ordinal parameter for <code>gnsdk_manager_gdo_value_get</code>
should start at 1 and increment to retrieve each separate value.
* @ingroup GDO_ValueKeys_Lyric
*/
#define GNSDK_GDO_VALUE_LYRIC_LINE					"gnsdk_val_lyricline"


/*****************************************************************************
** GDO Keys specific to VIDEO responses
*/

/** @internal GNSDK_GDO_TYPE_RESPONSE_VIDEO_PRODUCT @endinternal
*  GDO is of video response type.
*  <p><b>Supported GDO Child Keys</b></p>
*  <ul>
*   <li>GNSDK_GDO_CHILD_VIDEO_PRODUCT</li>
*  </ul>
*  <p><b>Supported GDO Value Keys</b></p>
*
*   <ul>
*   <li>GNSDK_GDO_VALUE_RESPONSE_RANGE_START</li>
*   <li>GNSDK_GDO_VALUE_RESPONSE_RANGE_END</li>
*   <li>GNSDK_GDO_VALUE_RESPONSE_RANGE_TOTAL</li>
*   </ul>
* @ingroup GDO_Types_Video
*/
#define GNSDK_GDO_TYPE_RESPONSE_VIDEO_PRODUCT			"gnsdk_ctx_response_video_product"


/** @internal GNSDK_GDO_TYPE_RESPONSE_VIDEO @endinternal
*  GDO is of video product response type.
*  <p><b>Remarks:</b></p>
*  Value is used as return value for <code>gnsdk_manager_gdo_get_type</code>.
*
*  Video response types are returned from query APIs of GNSDKs that return video content. A video
response type contains one or more GNSDK_GDO_TYPE_VIDEO_PRODUCT child types.
* @ingroup GDO_Types_Video
*/
#define GNSDK_GDO_TYPE_RESPONSE_VIDEO					GNSDK_GDO_TYPE_RESPONSE_VIDEO_PRODUCT

/** @internal GNSDK_GDO_TYPE_VIDEO_PRODUCT @endinternal
*  GDO is of video product type.
*  <p><b>Remarks:</b></p>
*  Value is used as return value for <code>gnsdk_manager_gdo_get_type</code>.
*  Video product types are retrieved from GNSDK_GDO_TYPE_RESPONSE_VIDEO types through
<code>gnsdk_manager_gdo_child_get</code> with the GNSDK_GDO_CHILD_VIDEO_PRODUCT key.
*
*  This type supports Link data.
* @ingroup GDO_Types_Video
*/
#define GNSDK_GDO_TYPE_VIDEO_PRODUCT						"gnsdk_ctx_video_product"
/** @internal GNSDK_GDO_TYPE_VIDEO_DISC @endinternal
*  GDO is of video disc type.
*  <p><b>Remarks:</b></p>
*  Value is used as return value for <code>gnsdk_manager_gdo_get_type</code>.<br>
*  Video disc types are retrieved from GNSDK_GDO_TYPE_VIDEO_PRODUCT types
*  through <code>gnsdk_manager_gdo_child_get</code> with the GNSDK_GDO_CHILD_VIDEO_DISC key.
*
* @ingroup GDO_Types_Video
*/
#define GNSDK_GDO_TYPE_VIDEO_DISC						"gnsdk_ctx_video_disc"
/** @internal GNSDK_GDO_TYPE_VIDEO_SIDE @endinternal
*  GDO is of video disc side type.
*  <p><b>Remarks:</b></p>
*  Value is used as return value for <code>gnsdk_manager_gdo_get_type</code>.
*  Video side types are retrieved from GNSDK_GDO_TYPE_VIDEO_DISC types through
<code>gnsdk_manager_gdo_child_get</code> with the GNSDK_GDO_CHILD_VIDEO_SIDE key.
* @ingroup GDO_Types_Video
*/
#define GNSDK_GDO_TYPE_VIDEO_SIDE						"gnsdk_ctx_video_side"
/** @internal GNSDK_GDO_TYPE_VIDEO_LAYER @endinternal
*  GDO is of video disc layer type.
*  <p><b>Remarks:</b></p>
*  Value is used as return value for <code>gnsdk_manager_gdo_get_type</code>.
*  Video layer types are retrieved from GNSDK_GDO_TYPE_VIDEO_SIDE types through
<code>gnsdk_manager_gdo_child_get</code> with the GNSDK_GDO_CHILD_VIDEO_LAYER key.
* @ingroup GDO_Types_Video
*/
#define GNSDK_GDO_TYPE_VIDEO_LAYER						"gnsdk_ctx_video_layer"
/** @internal GNSDK_GDO_TYPE_VIDEO_FEATURE @endinternal
*  GDO is of video feature type.
*  <p><b>Remarks:</b></p>
*  Value is used as return value for <code>gnsdk_manager_gdo_get_type</code>.
*  Video feature types are retrieved from GNSDK_GDO_TYPE_VIDEO_LAYER types through
<code>gnsdk_manager_gdo_child_get</code> with one of the GNSDK_GDO_CHILD_VIDEO_FEATURE keys.
* @ingroup GDO_Types_Video
*/
#define GNSDK_GDO_TYPE_VIDEO_FEATURE						"gnsdk_ctx_video_feature"
/** @internal GNSDK_GDO_TYPE_VIDEO_CHAPTER @endinternal
*  GDO is of video feature chapter type.
*  <p><b>Remarks:</b></p>
*  Value is used as return value for <code>gnsdk_manager_gdo_get_type</code>.
*  Video chapter types are retrieved from GNSDK_GDO_TYPE_VIDEO_FEATURE types through
<code>gnsdk_manager_gdo_child_get</code> with the GNSDK_GDO_CHILD_VIDEO_CHAPTER key.
* @ingroup GDO_Types_Video
*/
#define GNSDK_GDO_TYPE_VIDEO_CHAPTER						"gnsdk_ctx_video_chapter"

/** @internal GNSDK_GDO_CHILD_VIDEO_PRODUCT @endinternal
*  Retrieves a child video product type.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for <code>gnsdk_manager_gdo_child_get</code> to retrieve child
*  GNSDK_GDO_TYPE_VIDEO_PRODUCT GDOs.
*  The ordinal parameter for <code>gnsdk_manager_gdo_child_get</code> with this key indicates the n'th child
video product to retrieve.
*  Video product types are generally available from
*  GNSDK_GDO_TYPE_RESPONSE_VIDEO GDOs.
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_VIDEO_PRODUCT						GNSDK_GDO_TYPE_VIDEO_PRODUCT"!"
/** @internal GNSDK_GDO_CHILD_VIDEO_DISC @endinternal
*  Retrieves a child video disc type.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for <code>gnsdk_manager_gdo_child_get</code> to retrieve child
*  GNSDK_GDO_TYPE_VIDEO_DISC GDOs.
*  The ordinal parameter for <code>gnsdk_manager_gdo_child_get</code> with this key indicates the n'th child
video disc to retrieve.
*
*  Video disc types are generally available from
*  GNSDK_GDO_TYPE_VIDEO_PRODUCT GDOs.
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_VIDEO_DISC							GNSDK_GDO_TYPE_VIDEO_DISC"!"
/** @internal GNSDK_GDO_CHILD_VIDEO_SIDE @endinternal
*  Retrieves a child video Side type.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for <code>gnsdk_manager_gdo_child_get</code> to retrieve child
*  GNSDK_GDO_TYPE_VIDEO_SIDE GDOs.
*  The ordinal parameter for <code>gnsdk_manager_gdo_child_get</code> with this key indicates the n'th child
video Side to retrieve.
*  Video Side types are generally available from GNSDK_GDO_TYPE_VIDEO_DISC GDOs.
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_VIDEO_SIDE							GNSDK_GDO_TYPE_VIDEO_SIDE"!"
/** @internal GNSDK_GDO_CHILD_VIDEO_LAYER @endinternal
*  Retrieves a child video layer type.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for <code>gnsdk_manager_gdo_child_get</code> to retrieve child
*  GNSDK_GDO_TYPE_VIDEO_LAYER GDOs.
*  The ordinal parameter for <code>gnsdk_manager_gdo_child_get</code> with this key indicates the n'th child
video layer to retrieve.
*  Video layer types are generally available from GNSDK_GDO_TYPE_VIDEO_DISC GDOs.
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_VIDEO_LAYER							GNSDK_GDO_TYPE_VIDEO_LAYER"!"
/** @internal GNSDK_GDO_CHILD_VIDEO_FEATURE @endinternal
*  Retrieves a child video feature type.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for <code>gnsdk_manager_gdo_child_get</code> to retrieve child
*  GNSDK_GDO_TYPE_VIDEO_FEATURE GDOs.
*  The ordinal parameter for <code>gnsdk_manager_gdo_child_get</code> with this key indicates the n'th child
video feature to retrieve.
*  Video feature types are generally available from GNSDK_GDO_TYPE_VIDEO_LAYER GDOs.
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_VIDEO_FEATURE						GNSDK_GDO_TYPE_VIDEO_FEATURE"!"
/** @internal GNSDK_GDO_CHILD_VIDEO_CHAPTER @endinternal
*  Retrieves a child video chapter type.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for <code>gnsdk_manager_gdo_child_get</code> to retrieve child
*  GNSDK_GDO_TYPE_VIDEO_CHAPTER GDOs.
*  The ordinal parameter for <code>gnsdk_manager_gdo_child_get</code> with this key indicates the n'th child
video chapter to retrieve.
*  Video chapter types are generally available from
*  GNSDK_GDO_TYPE_VIDEO_FEATURE GDOs.
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_VIDEO_CHAPTER						GNSDK_GDO_TYPE_VIDEO_CHAPTER"!"

/** @internal GNSDK_GDO_CHILD_VIDEO_FEATURE_MAIN @endinternal
*  Retrieves a child video feature type with a feature type of main.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for <code>gnsdk_manager_gdo_child_get</code> to retrieve child
GNSDK_GDO_TYPE_VIDEO_FEATURE GDOs where the feature type is set to 'main'.
*  The ordinal parameter for <code>gnsdk_manager_gdo_child_get</code> with this key indicates the n'th child
'main' video feature to retrieve.
*  Video feature types are generally available from GNSDK_GDO_TYPE_VIDEO_LAYER GDOs.
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_VIDEO_FEATURE_MAIN					GNSDK_GDO_TYPE_VIDEO_FEATURE"!main"
/** @internal GNSDK_GDO_CHILD_VIDEO_FEATURE_EPISODE @endinternal
*  Retrieves a child video feature type with a feature type of episode.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for <code>gnsdk_manager_gdo_child_get</code> to retrieve child
GNSDK_GDO_TYPE_VIDEO_FEATURE GDOs where the feature type is set to 'episode'.
*  The ordinal parameter for gnsdk_manager_gdo_child_get with this key indicates the n'th child
'episode' video feature to retrieve.
*  Video feature types are generally available from GNSDK_GDO_TYPE_VIDEO_LAYER GDOs.
*
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_VIDEO_FEATURE_EPISODE				GNSDK_GDO_TYPE_VIDEO_FEATURE"!episode"
/** @internal GNSDK_GDO_CHILD_VIDEO_FEATURE_EXTRA @endinternal
*  Retrieves a child video feature type with a feature type of extra.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for <code>gnsdk_manager_gdo_child_get</code> to retrieve child
GNSDK_GDO_TYPE_VIDEO_FEATURE GDOs where the feature type is set to 'extra'.
*  The ordinal parameter for <code>gnsdk_manager_gdo_child_get</code> with this key indicates
*  the n'th child 'extra' video feature to retrieve.
*  Video feature types are generally available from GNSDK_GDO_TYPE_VIDEO_LAYER GDOs.
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_VIDEO_FEATURE_EXTRA					GNSDK_GDO_TYPE_VIDEO_FEATURE"!extra"
/** @internal GNSDK_GDO_CHILD_VIDEO_FEATURE_RESERVED @endinternal
*  Retrieves a child video feature type with a feature type of reserved.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for <code>gnsdk_manager_gdo_child_get</code> to retrieve child
GNSDK_GDO_TYPE_VIDEO_FEATURE GDOs where the feature type is set to 'reserved'.
*  The ordinal parameter for <code>gnsdk_manager_gdo_child_get</code> with this key indicates the n'th child
'reserverd' video feature to retrieve.
*  Video feature types are generally available from GNSDK_GDO_TYPE_VIDEO_LAYER GDOs.
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_VIDEO_FEATURE_RESERVED				GNSDK_GDO_TYPE_VIDEO_FEATURE"!reserved"

/** @internal GNSDK_GDO_CHILD_VIDEO_MATCHED_DISC @endinternal
*  Retrieves a child video disc type that matches the input criteria.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for <code>gnsdk_manager_gdo_child_get</code> to retrieve child
*  GNSDK_GDO_TYPE_VIDEO_DISC GDOs.
*  The ordinal parameter for <code>gnsdk_manager_gdo_child_get</code> with this key indicates the n'th matching
child video disc to retrieve. A child video disc is marked matching for some queries that match to a
specific video disc. It is not always the case that there will be child video disc types marked
as matching available.
*  Video disc types are generally available from
*  GNSDK_GDO_TYPE_VIDEO_PRODUCT GDOs.
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_VIDEO_MATCHED_DISC					GNSDK_GDO_TYPE_VIDEO_DISC"!matched"
/** @internal GNSDK_GDO_CHILD_VIDEO_MATCHED_SIDE @endinternal
*  Retrieves a child video side type that matches the input criteria.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for <code>gnsdk_manager_gdo_child_get</code> to retrieve child
*  GNSDK_GDO_TYPE_VIDEO_SIDE GDOs.
*  The ordinal parameter for <code>gnsdk_manager_gdo_child_get</code> with this key indicates the n'th matching
child video side to retrieve. A child video side is marked matching for some queries that match to a
specific video side. It is not always the case that there will be child video side types marked
as matching available.
*  Video side types are generally available from GNSDK_GDO_TYPE_VIDEO_DISC GDOs.
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_VIDEO_MATCHED_SIDE					GNSDK_GDO_TYPE_VIDEO_SIDE"!matched"
/** @internal GNSDK_GDO_CHILD_VIDEO_MATCHED_LAYER @endinternal
*  Retrieves a child video layer type that matches the input criteria.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for <code>gnsdk_manager_gdo_child_get</code> to retrieve child
*  GNSDK_GDO_TYPE_VIDEO_LAYER GDOs.
*  The ordinal parameter for <code>gnsdk_manager_gdo_child_get</code> with this key indicates the n'th matching
child video layer to retrieve. A child video layer is marked matching for some queries that match to
a specific video layer. It is not always the case that there will be child video layer types
marked as matching available.
*  Video layer types are generally available from GNSDK_GDO_TYPE_VIDEO_SIDE GDOs.
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_VIDEO_MATCHED_LAYER					GNSDK_GDO_TYPE_VIDEO_LAYER"!matched"

/** @internal GNSDK_GDO_CHILD_CREDIT_CAST @endinternal
  *
  * Cast credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_CAST							GNSDK_GDO_TYPE_CREDIT"!15941"
/** @internal GNSDK_GDO_CHILD_CREDIT_DANCER @endinternal
  *
  * Dancer credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_DANCER						GNSDK_GDO_TYPE_CREDIT"!15943"
/** @internal GNSDK_GDO_CHILD_CREDIT_GUEST @endinternal
  *
  * Guest credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_GUEST						GNSDK_GDO_TYPE_CREDIT"!15944"
/** @internal GNSDK_GDO_CHILD_CREDIT_HOST @endinternal
  *
  * Host credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_HOST							GNSDK_GDO_TYPE_CREDIT"!15945"
/** @internal GNSDK_GDO_CHILD_CREDIT_PUPPETEER @endinternal
  *
  * Puppeteer credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_PUPPETEER					GNSDK_GDO_TYPE_CREDIT"!15947"
/** @internal GNSDK_GDO_CHILD_CREDIT_VOICE_OF @endinternal
  *
  * Voice of credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_VOICE_OF						GNSDK_GDO_TYPE_CREDIT"!15948"
/** @internal GNSDK_GDO_CHILD_CREDIT_CREW @endinternal
  *
  * Crew credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_CREW							GNSDK_GDO_TYPE_CREDIT"!15949"
/** @internal GNSDK_GDO_CHILD_CREDIT_CAMERA_PERSON @endinternal
  *
  * Camera person credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_CAMERA_PERSON				GNSDK_GDO_TYPE_CREDIT"!15950"
/** @internal GNSDK_GDO_CHILD_CREDIT_GOPHER @endinternal
  *
  * Gopher credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_GOPHER						GNSDK_GDO_TYPE_CREDIT"!15951"
/** @internal GNSDK_GDO_CHILD_CREDIT_STUNT_PERSON @endinternal
  *
  * Stunt person credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_STUNT_PERSON					GNSDK_GDO_TYPE_CREDIT"!15952"
/** @internal GNSDK_GDO_CHILD_CREDIT_MUSIC @endinternal
  *
  * Music credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_MUSIC						GNSDK_GDO_TYPE_CREDIT"!15953"
/** @internal GNSDK_GDO_CHILD_CREDIT_MUSIC_DIRECTOR @endinternal
  *
  * Music director credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_MUSIC_DIRECTOR				GNSDK_GDO_TYPE_CREDIT"!15954"
/** @internal GNSDK_GDO_CHILD_CREDIT_ORIGINAL_SCORE @endinternal
  *
  * Original score credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_ORIGINAL_SCORE				GNSDK_GDO_TYPE_CREDIT"!15955"
/** @internal GNSDK_GDO_CHILD_CREDIT_PRODUCTION @endinternal
  *
  * Production credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_PRODUCTION					GNSDK_GDO_TYPE_CREDIT"!15956"
/** @internal GNSDK_GDO_CHILD_CREDIT_ASSOCIATE_PRODUCER @endinternal
  *
  * Associate producer credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_ASSOCIATE_PRODUCER			GNSDK_GDO_TYPE_CREDIT"!15959"
/** @internal GNSDK_GDO_CHILD_CREDIT_SCREENWRITER @endinternal
  *
  * Screenwriter credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_SCREENWRITER					GNSDK_GDO_TYPE_CREDIT"!15961"
/** @internal GNSDK_GDO_CHILD_CREDIT_ART @endinternal
  *
  * Art credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_ART							GNSDK_GDO_TYPE_CREDIT"!15963"
/** @internal GNSDK_GDO_CHILD_CREDIT_ART_DIRECTION @endinternal
  *
  * Art direction credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_ART_DIRECTION				GNSDK_GDO_TYPE_CREDIT"!15964"
/** @internal GNSDK_GDO_CHILD_CREDIT_CASTING @endinternal
  *
  * Casting credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_CASTING						GNSDK_GDO_TYPE_CREDIT"!15965"
/** @internal GNSDK_GDO_CHILD_CREDIT_CINEMATOGRAPHY @endinternal
  *
  * Cinematography credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_CINEMATOGRAPHY				GNSDK_GDO_TYPE_CREDIT"!15966"
/** @internal GNSDK_GDO_CHILD_CREDIT_COSTUME_DESIGN @endinternal
  *
  * Costume design credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_COSTUME_DESIGN				GNSDK_GDO_TYPE_CREDIT"!15967"
/** @internal GNSDK_GDO_CHILD_CREDIT_EDITOR @endinternal
  *
  * Editor credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_EDITOR						GNSDK_GDO_TYPE_CREDIT"!15968"
/** @internal GNSDK_GDO_CHILD_CREDIT_MAKEUP @endinternal
  *
  * Makeup credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_MAKEUP						GNSDK_GDO_TYPE_CREDIT"!15969"
/** @internal GNSDK_GDO_CHILD_CREDIT_PRODUCTION_DESIGN @endinternal
  *
  * Production design credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_PRODUCTION_DESIGN			GNSDK_GDO_TYPE_CREDIT"!15970"
/** @internal GNSDK_GDO_CHILD_CREDIT_PRODUCTION_MANAGEMENT @endinternal
  *
  * Production management credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_PRODUCTION_MANAGEMENT		GNSDK_GDO_TYPE_CREDIT"!15971"
/** @internal GNSDK_GDO_CHILD_CREDIT_SPECIAL_EFFECTS @endinternal
  *
  * Special effects credit
  * @ingroup GDO_ChildKeys_Credit
*/
#define GNSDK_GDO_CHILD_CREDIT_SPECIAL_EFFECTS				GNSDK_GDO_TYPE_CREDIT"!15972"

/** @internal GNSDK_GDO_VALUE_MATCHED @endinternal
*  Retrieves the matched boolean value for the current type; this indicates whether this type
is the one that matched the input criteria. Available from many video types.
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_MATCHED							"gnsdk_val_matched"
/** @internal GNSDK_GDO_VALUE_ORDINAL @endinternal
*  Retrieves an ordinal of the current type.
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_ORDINAL							"gnsdk_val_ordinal"
/** @internal GNSDK_GDO_VALUE_DURATION @endinternal
*  Retrieves a duration value in seconds from the current type, such as "3600" for a 60-minute
program. Available for video Chapters, Features, Products, Seasons, Series, and Works.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_DURATION						"gnsdk_val_duration"
/** @internal GNSDK_GDO_VALUE_DURATION_UNITS @endinternal
*  Retrieves a duration units value (seconds, "SEC") from the current type. Available for video
Chapters, Features, Products, Seasons, Series, and Works.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_DURATION_UNITS					"gnsdk_val_duration_units"

/** @internal GNSDK_GDO_VALUE_PLOT_SYNOPSIS @endinternal
*  Retrieves a plot synopsis for the current type. Available from many video types.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_PLOT_SYNOPSIS					"gnsdk_val_plot_synopsis"
/** @internal GNSDK_GDO_VALUE_PLOT_SYNOPSIS_LANGUAGE @endinternal
*  Retrieves the available language value for a returned GNSDK_GDO_VALUE_PLOT_SYNOPSIS object.
*  <p><b>Remarks:</b></p>
*  Use this value to retrieve the actual language value of a returned object.
*  The language value of a returned object depends on availability. Information in the language set
for the locale may not be available, and the object's information may be available only in its
default official language. For example, if a locale's set language is Spanish, but the object's
information is available only in English, this value returns as English.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_PLOT_SYNOPSIS_LANGUAGE			"gnsdk_val_plot_synopsis_language"

/** @internal GNSDK_GDO_VALUE_PLOT_SUMMARY @endinternal
*  Retrieves a plot summary value from a GDO.
*  GNSDK_GDO_VALUE_PLOT_SUMMARY
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_PLOT_SUMMARY					"gnsdk_val_plot_summary"
/** @internal GNSDK_GDO_VALUE_PLOT_TAGLINE @endinternal
*  Retrieves a plot tagline value from a GDO.
*  GNSDK_GDO_VALUE_PLOT_TAGLINE
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_PLOT_TAGLINE					"gnsdk_val_plot_tagline"
/** @internal GNSDK_GDO_CHILD_TITLE_FRANCHISE @endinternal
*  Retrieves a Franchise title child from a GDO.
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_TITLE_FRANCHISE					GNSDK_GDO_TYPE_TITLE"!franchise"
/** @internal GNSDK_GDO_VALUE_FRANCHISE_NUM @endinternal
*  Retrieves a Franchise number value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_FRANCHISE_NUM					"gnsdk_val_franchise_num"
/** @internal GNSDK_GDO_VALUE_FRANCHISE_COUNT @endinternal
*  Retrieves a Franchise count value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_FRANCHISE_COUNT					"gnsdk_val_franchise_count"

/** @internal GNSDK_GDO_CHILD_TITLE_SERIES @endinternal
*  Retrieves a series title child from a GDO.
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_TITLE_SERIES					GNSDK_GDO_TYPE_TITLE"!series"
/** @internal GNSDK_GDO_VALUE_SERIES_EPISODE @endinternal
*  Retrieves a series episode value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_SERIES_EPISODE					"gnsdk_val_series_episode"
/** @internal GNSDK_GDO_VALUE_SERIES_EPISODE_COUNT @endinternal
*  Retrieves a series episode count value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_SERIES_EPISODE_COUNT			"gnsdk_val_series_episode_count"
/** @internal GNSDK_GDO_VALUE_SEASON_EPISODE @endinternal
*  Retrieves a Season episode value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_SEASON_EPISODE					"gnsdk_val_season_episode"
/** @internal GNSDK_GDO_VALUE_SEASON_EPISODE_COUNT @endinternal
*  Retrieves an episode count value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_SEASON_EPISODE_COUNT			"gnsdk_val_season_episode_count"
/** @internal GNSDK_GDO_VALUE_SEASON_NUMBER @endinternal
*  Retrieves a Season number value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_SEASON_NUMBER					"gnsdk_val_season_number"
/** @internal GNSDK_GDO_VALUE_SEASON_COUNT @endinternal
*  Retrieves a Season count value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_SEASON_COUNT					"gnsdk_val_season_count"

/** @internal GNSDK_GDO_VALUE_RATING @endinternal
*  Retrieves a rating value from a GDO.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to gnsdk_manager_locale_load.
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING							"gnsdk_val_list_rating"
/** @internal GNSDK_GDO_VALUE_RATING_DESC @endinternal
*  Retrieves a rating description value from a GDO.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to gnsdk_manager_locale_load.
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_DESC						"gnsdk_val_list_rating_desc"
/** @internal GNSDK_GDO_VALUE_RATING_TYPE @endinternal
*  Retrieves a rating type value from a GDO.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to gnsdk_manager_locale_load.
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_TYPE						"gnsdk_val_list_rating_type"

/** @internal GNSDK_GDO_VALUE_RATING_TYPE_ID @endinternal
*  Retrieves a rating type value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_TYPE_ID					"gnsdk_val_list_rating_type_id"

/** @internal GNSDK_GDO_VALUE_RATING_REASON @endinternal
*  Retrieves a rating reason value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_REASON					"gnsdk_val_list_rating_reason"

/** @internal GNSDK_GDO_VALUE_RATING_MPAA @endinternal
*  Retrieves a MPAA rating type value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_MPAA						"gnsdk_val_list_rating_typed_mpaa"
/** @internal GNSDK_GDO_VALUE_RATING_MPAA_TV @endinternal
*  Retrieves a MPAA TV rating type value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_MPAA_TV					"gnsdk_val_list_rating_typed_mpaa_tv"
/** @internal GNSDK_GDO_VALUE_RATING_FAB @endinternal
*  Retrieves a FAB rating type value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_FAB						"gnsdk_val_list_rating_typed_fab"
/** @internal GNSDK_GDO_VALUE_RATING_CHVRS @endinternal
*  Retrieves a CHVRS rating type value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_CHVRS					"gnsdk_val_list_rating_typed_chvrs"
/** @internal GNSDK_GDO_VALUE_RATING_CANADIAN_TV @endinternal
*  Retrieves a Canadian TV rating type value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_CANADIAN_TV				"gnsdk_val_list_rating_typed_canadian_tv"
/** @internal GNSDK_GDO_VALUE_RATING_BBFC @endinternal
*  Retrieves a BBFC rating type value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_BBFC						"gnsdk_val_list_rating_typed_bbfc"
/** @internal GNSDK_GDO_VALUE_RATING_CBFC @endinternal
*  Retrieves a CBFC rating type value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_CBFC						"gnsdk_val_list_rating_typed_cbfc"
/** @internal GNSDK_GDO_VALUE_RATING_OFLC @endinternal
*  Retrieves a OFLC TV rating type value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_OFLC						"gnsdk_val_list_rating_typed_oflc"
/** @internal GNSDK_GDO_VALUE_RATING_HONG_KONG @endinternal
*  Retrieves a Hong Kong rating type value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_HONG_KONG				"gnsdk_val_list_rating_typed_hong_kong"
/** @internal GNSDK_GDO_VALUE_RATING_FINNISH @endinternal
*  Retrieves a Finnish rating type value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_FINNISH					"gnsdk_val_list_rating_typed_finnish"
/** @internal GNSDK_GDO_VALUE_RATING_KMRB @endinternal
*  Retrieves a KMRB rating type value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_KMRB						"gnsdk_val_list_rating_typed_kmrb"
/** @internal GNSDK_GDO_VALUE_RATING_DVD_PARENTAL @endinternal
*  Retrieves a DVD Parental rating type value from a GDO.
*  GNSDK_GDO_VALUE_RATING_DVD_PARENTAL
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_DVD_PARENTAL				"gnsdk_val_list_rating_typed_dvd_parental"
/** @internal GNSDK_GDO_VALUE_RATING_EIRIN @endinternal
*  Retrieves a EIRIN rating type value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_EIRIN					"gnsdk_val_list_rating_typed_eirin"
/** @internal GNSDK_GDO_VALUE_RATING_INCAA @endinternal
*  Retrieves a INCAA rating type value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_INCAA					"gnsdk_val_list_rating_typed_incaa"
/** @internal GNSDK_GDO_VALUE_RATING_DJTCQ @endinternal
*  Retrieves a DJTCQ rating type value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_DJTCQ					"gnsdk_val_list_rating_typed_djtcq"
/** @internal GNSDK_GDO_VALUE_RATING_QUEBEC @endinternal
*  Retrieves a Quebecois rating type value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_QUEBEC					"gnsdk_val_list_rating_typed_quebec"
/** @internal GNSDK_GDO_VALUE_RATING_FRANCE @endinternal
*  Retrieves a French rating type value from a GDO.
*  GNSDK_GDO_VALUE_RATING_FRANCE
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_FRANCE					"gnsdk_val_list_rating_typed_france"
/** @internal GNSDK_GDO_VALUE_RATING_FSK @endinternal
*  Retrieves a FSK rating type value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_FSK						"gnsdk_val_list_rating_typed_fsk"
/** @internal GNSDK_GDO_VALUE_RATING_ITALY @endinternal
*  Retrieves a Italian rating type value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_ITALY					"gnsdk_val_list_rating_typed_italy"
/** @internal GNSDK_GDO_VALUE_RATING_SPAIN @endinternal
*  Retrieves a Spanish rating type value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_RATING_SPAIN					"gnsdk_val_list_rating_typed_spain"

/** @internal GNSDK_GDO_VALUE_VIDEO_PRODUCTION_TYPE @endinternal
*  Retrieves a video production type value from a GDO.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to gnsdk_manager_locale_load.
*
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_VIDEO_PRODUCTION_TYPE			"gnsdk_val_list_video_prodtype"


/** @internal GNSDK_GDO_VALUE_VIDEO_PRODUCTION_TYPE_ID @endinternal
*  Retrieves a video production type value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_VIDEO_PRODUCTION_TYPE_ID		"gnsdk_val_list_video_prodtype_id"


/** @internal GNSDK_GDO_VALUE_VIDEO_FEATURE_TYPE @endinternal
*  Retrieves a video feature type value from a GDO.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to <code>gnsdk_manager_locale_load</code>.
*
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_VIDEO_FEATURE_TYPE				"gnsdk_val_list_video_feattype"
/** @internal GNSDK_GDO_VALUE_SERIAL_TYPE @endinternal
*  Retrieves a serial type value from a GDO.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to gnsdk_manager_locale_load.
*
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_SERIAL_TYPE						"gnsdk_val_list_vidserial_type"

/** @internal GNSDK_GDO_VALUE_WORK_TYPE @endinternal
*  Retrieves a work type value from a GDO.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to gnsdk_manager_locale_load.
*
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_WORK_TYPE						"gnsdk_val_list_work_type"
/** @internal GNSDK_GDO_VALUE_STORY_TYPE @endinternal
*  Retrieves a story type value from a video Work GDO.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to <code>gnsdk_manager_locale_load</code>.
*
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_STORY_TYPE						"gnsdk_val_list_story_type"

/** @internal GNSDK_GDO_VALUE_AUDIENCE @endinternal
*  Retrieves an audience value from a video Work GDO.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to <code>gnsdk_manager_locale_load</code>.
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_AUDIENCE						"gnsdk_val_list_audience"
/** @internal GNSDK_GDO_VALUE_VIDEO_MOOD @endinternal
*  Retrieves a mood group value from a GDO.
*  <p><b>Remarks:</b></p>
*  This value retrieves mood information for music and video, depending on the respective calling
type.
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_VIDEO_MOOD						"gnsdk_val_list_vidmood"
/** @internal GNSDK_GDO_VALUE_REPUTATION @endinternal
*  Retrieves a reputation value from a video Work GDO.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to gnsdk_manager_locale_load.
*
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_REPUTATION						"gnsdk_val_list_reputation"
/** @internal GNSDK_GDO_VALUE_SCENARIO @endinternal
*  Retrieves a scenario value from a video Work GDO.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to gnsdk_manager_locale_load.
*
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_SCENARIO						"gnsdk_val_list_scenario"
/** @internal GNSDK_GDO_VALUE_SETTING_ENVIRONMENT @endinternal
*  Retrieves a setting environment value from a video Work GDO.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to <code>gnsdk_manager_locale_load</code>.
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_SETTING_ENVIRONMENT				"gnsdk_val_list_settingenv"

/** @internal GNSDK_GDO_VALUE_SETTING_TIME_PERIOD @endinternal
*  Retrieves a historical time period value, such as Elizabethan Era, 1558-1603.
*  GNSDK_GDO_TYPE_VIDEO_WORK GNSDK_GDO_TYPE_VIDEO_SEASON GNSDK_GDO_TYPE_VIDEO_SERIES
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_SETTING_TIME_PERIOD				"gnsdk_val_list_settingtimeperiod"

/** @internal GNSDK_GDO_VALUE_SOURCE @endinternal
*  Retrieves a source value from a video Work GDO.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to <code>gnsdk_manager_locale_load</code>.
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_SOURCE							"gnsdk_val_list_source"
/** @internal GNSDK_GDO_VALUE_STYLE @endinternal
*  Retrieves a style value from a video Work GDO.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to <code>gnsdk_manager_locale_load</code>.
*
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_STYLE							"gnsdk_val_list_style"
/** @internal GNSDK_GDO_VALUE_TOPIC @endinternal
*  Retrieves a topic value from a video Work GDO.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to <code>gnsdk_manager_locale_load</code>.
*
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_TOPIC							"gnsdk_val_list_topic"



/** @internal GNSDK_GDO_VALUE_MEDIA_SPACE @endinternal
*  Retrieves a media space value from a GDO.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to <code>gnsdk_manager_locale_load</code>.
*
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_MEDIA_SPACE						"gnsdk_val_list_media_space"

/** @internal GNSDK_GDO_VALUE_DATE_ORIGINAL_RELEASE @endinternal
*  Retrieves a release date from the current type. Available for video Products, Features, and
*  Works.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_DATE_ORIGINAL_RELEASE			"gnsdk_val_date_original_release"
/** @internal GNSDK_GDO_VALUE_NOTES @endinternal
*  Retrieves the notes for the current type. Available from most video types.
*  GNSDK_GDO_VALUE_NOTES
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_NOTES							"gnsdk_val_notes"
/** @internal GNSDK_GDO_VALUE_ASPECT_RATIO @endinternal
*  Retrieves the aspect ratio for the current type. Available from many video types.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_ASPECT_RATIO					"gnsdk_val_aspect"
/** @internal GNSDK_GDO_VALUE_ASPECT_RATIO_TYPE @endinternal
*  Retrieves the aspect ratio for the current type. Available from many video types.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_ASPECT_RATIO_TYPE				"gnsdk_val_aspect_type"

/** @internal GNSDK_GDO_VALUE_TV_SYSTEM @endinternal
*  Retrieves a TV system value (like NTSC) from the current type. Available from many video
types.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_TV_SYSTEM						"gnsdk_val_tv_system"
/** @internal GNSDK_GDO_VALUE_REGION_CODE @endinternal
*  Retrieves a region code (for example, FE) for the current type. Available from many video
types.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_REGION_CODE						"gnsdk_val_region_code"
/** @internal GNSDK_GDO_VALUE_VIDEO_REGION @endinternal
*  Retrieves a video product region value from the current type. Available from many video
types.
*  Example: 1
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to <code>gnsdk_manager_locale_load</code>.
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_VIDEO_REGION					"gnsdk_val_list_vidregion"
/** @internal GNSDK_GDO_VALUE_VIDEO_REGION_DESC @endinternal
*  Retrieves a video product region description for the current type. Available from many video
types.
*  Example
*  USA, Canada, US Territories, Bermuda, and Cayman Islands
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to <code>gnsdk_manager_locale_load</code>.
*
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_VIDEO_REGION_DESC				"gnsdk_val_list_vidregion_desc"
/** @internal GNSDK_GDO_VALUE_MEDIA_TYPE @endinternal
*  Retrieves a media type value from a GDO.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to gnsdk_manager_locale_load.
*
*  To render locale-dependent information for list-based values, the application must call
<code>gnsdk_manager_locale_load</code> and possibly also <code>gnsdk_sdkmanager_gdo_set_locale</code>. The application returns
a <code>LocaleNotLoaded</code> message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_MEDIA_TYPE						"gnsdk_val_list_mediatype"

/** @internal GNSDK_GDO_VALUE_COMMERCE_TYPE @endinternal
*  Retrieves a numerical value indicating if commerce type data exists for a video disc.
*  <p><b>Remarks:</b></p>
*  For information on the specific values this key retrieves, contact your Gracenote Professional
Services representative.
*
*  <p><b>Related Topics</b></p>
*  <ul>
*  <li><code>gnsdk_videoid_query_set_toc_string</code></li>
*   <li>GNSDK_VIDEOID_OPTION_QUERY_ENABLE_COMMERCE_TYPE</li>
*   <li>GNSDK_GDO_TYPE_VIDEO_PRODUCT</li>
*   </ul>
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_COMMERCE_TYPE					"gnsdk_val_commerce_type"

/** @internal GNSDK_GDO_VALUE_MAIN_TITLE @endinternal
*  Retrieves a video product or disc main title value from a title GDO.
*  <p><b>Remarks:</b></p>
*  For video product types, this retrieves the main video product title.
*  For video disc types, this retrieves the main video disc title.
*  This value is unique, so the ordinal parameter for <code>gnsdk_manager_gdo_value_get</code> should be set to
1.
* @ingroup GDO_ValueKeys_Title
*/
#define GNSDK_GDO_VALUE_MAIN_TITLE						"gnsdk_val_maintitle"
/** @internal GNSDK_GDO_VALUE_EDITION @endinternal
*  Retrieves an edition title for the current title GDO. Available from many video types.
* @ingroup GDO_ValueKeys_Title
*/
#define GNSDK_GDO_VALUE_EDITION							"gnsdk_val_edition"

/** @internal GNSDK_GDO_VALUE_RANK @endinternal
*  Retrieves a rank (ordinal) for the current credit type.
* @ingroup GDO_ValueKeys_Misc
*/
#define GNSDK_GDO_VALUE_RANK							"gnsdk_val_rank"
/** @internal GNSDK_GDO_VALUE_CHARACTER_NAME @endinternal
*  Retrieves a character name value from a GDO.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_CHARACTER_NAME					"gnsdk_val_character_name"


/** @internal GNSDK_GDO_VALUE_ROLE_ID @endinternal
*  Returns a Role ID for a credit.
* @ingroup GDO_ValueKeys_Role
*/
#define GNSDK_GDO_VALUE_ROLE_ID							"gnsdk_val_list_role_id"


/** @internal GNSDK_GDO_TYPE_RESPONSE_VIDEO_WORK @endinternal
*  GDO value keys specific to VIDEO_WORK responses.
*
*  <p><b>Supported GDO Child Keys</b></p>
*  <ul>
*  <li>GNSDK_GDO_CHILD_VIDEO_WORK</li>
*  </ul>
*
*  <p><b>Supported GDO Value Keys</b></p>
*  <ul>
*  <li>GNSDK_GDO_VALUE_RESPONSE_RANGE_START</li>
*  <li>GNSDK_GDO_VALUE_RESPONSE_RANGE_END</li>
*  <li>GNSDK_GDO_VALUE_RESPONSE_RANGE_TOTAL</li>
*  </ul>
*
* @ingroup GDO_Types_Video
*/
#define GNSDK_GDO_TYPE_RESPONSE_VIDEO_WORK				"gnsdk_ctx_response_video_work"
/** @internal GNSDK_GDO_TYPE_VIDEO_WORK @endinternal
*  GDO is of a video Work type.
*  <p><b>Remarks:</b></p>val_list_type
*  This type supports Link data.
* @ingroup GDO_Types_Video
*/
#define GNSDK_GDO_TYPE_VIDEO_WORK						"gnsdk_ctx_video_work"
/** @internal GNSDK_GDO_CHILD_VIDEO_WORK @endinternal
*  Retrieves a child Video Work type.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for gnsdk_manager_gdo_child_get to retrieve child
*  GNSDK_GDO_TYPE_VIDEO_WORK GDOs.
*  The ordinal parameter for gnsdk_manager_gdo_child_get with this key indicates the n'th child
video Work to retrieve.
*  Video Work types are generally available from GNSDK_GDO_TYPE_RESPONSE_VIDEO_WORK GDOs.
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_VIDEO_WORK							GNSDK_GDO_TYPE_VIDEO_WORK"!"

/** @internal GNSDK_GDO_TYPE_VIDEO_ADVERT @endinternal
*  GDO is of a video advertisement type.
*  <p><b>Remarks:</b></p>val_list_type
*  This type supports Link data.
* @ingroup GDO_Types_Video
*/
#define GNSDK_GDO_TYPE_VIDEO_ADVERT						"gnsdk_ctx_video_advert"
/** @internal GNSDK_GDO_CHILD_VIDEO_ADVERT @endinternal
*  Retrieves a child Video advertisement type.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for gnsdk_manager_gdo_child_get to retrieve child
*  GNSDK_GDO_TYPE_VIDEO_ADVERT GDOs.
*  The ordinal parameter for gnsdk_manager_gdo_child_get with this key indicates the n'th child
video advert to retrieve.
*  Video Advert types are generally available from GNSDK_GDO_TYPE_RESPONSE_ACR GDOs.
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_VIDEO_ADVERT							GNSDK_GDO_TYPE_VIDEO_ADVERT"!"

/** @internal GNSDK_GDO_TYPE_RESPONSE_TVPROGRAM @endinternal
  *
  *   GDO is of a TVPROGRAM response type.
  * @ingroup GDO_Types_Response
*/
#define GNSDK_GDO_TYPE_RESPONSE_TVPROGRAM				"gnsdk_ctx_response_tvprogram"
/** @internal GNSDK_GDO_TYPE_TVPROGRAM @endinternal
  *
  *   GDO is of a TVPROGRAM type.
  * @ingroup GDO_Types_Epg
*/
#define GNSDK_GDO_TYPE_TVPROGRAM							"gnsdk_ctx_tvprogram"

/** @internal GNSDK_GDO_CHILD_TVPROGRAM @endinternal
  *
  *   Retrieves a child TVPROGRAM type.
* @ingroup GDO_ChildKeys_Epg
*/
#define GNSDK_GDO_CHILD_TVPROGRAM							GNSDK_GDO_TYPE_TVPROGRAM"!"



/** @internal GNSDK_GDO_TYPE_RESPONSE_TVAIRING @endinternal
  *
* @ingroup GDO_Types_Response
*/
#define GNSDK_GDO_TYPE_RESPONSE_TVAIRING					"gnsdk_ctx_response_tvairing"
/** @internal GNSDK_GDO_TYPE_TVAIRING @endinternal
  *
* @ingroup GDO_Types_Epg
*/
#define GNSDK_GDO_TYPE_TVAIRING							"gnsdk_ctx_tvairing"
/** @internal GNSDK_GDO_CHILD_TVAIRING @endinternal
  *
* @ingroup GDO_ChildKeys_Epg
*/
#define GNSDK_GDO_CHILD_TVAIRING							GNSDK_GDO_TYPE_TVAIRING"!"
/** @internal GNSDK_GDO_TYPE_RESPONSE_TVPROVIDER @endinternal
  *
* @ingroup GDO_Types_Response
*/
#define GNSDK_GDO_TYPE_RESPONSE_TVPROVIDER				"gnsdk_ctx_response_tvprovider"
/** @internal GNSDK_GDO_TYPE_TVPROVIDER @endinternal
  *
* @ingroup GDO_Types_Epg
*/
#define GNSDK_GDO_TYPE_TVPROVIDER						"gnsdk_ctx_tvprovider"
/** @internal GNSDK_GDO_CHILD_TVPROVIDER @endinternal
  *
* @ingroup GDO_ChildKeys_Epg
*/
#define GNSDK_GDO_CHILD_TVPROVIDER							GNSDK_GDO_TYPE_TVPROVIDER"!"

/** @internal GNSDK_GDO_TYPE_RESPONSE_TVCHANNEL @endinternal
  *
* @ingroup GDO_Types_Response
*/
#define GNSDK_GDO_TYPE_RESPONSE_TVCHANNEL				"gnsdk_ctx_response_tvchannel"
/** @internal GNSDK_GDO_TYPE_TVCHANNEL @endinternal
  *
* @ingroup GDO_Types_Epg
*/
#define GNSDK_GDO_TYPE_TVCHANNEL							"gnsdk_ctx_tvchannel"
/** @internal GNSDK_GDO_CHILD_TVCHANNEL @endinternal
  *
* @ingroup GDO_ChildKeys_Epg
*/
#define GNSDK_GDO_CHILD_TVCHANNEL							GNSDK_GDO_TYPE_TVCHANNEL"!"




/** @internal GNSDK_GDO_TYPE_RESPONSE_ACR @endinternal
  *
  *   ACR type response.
* @ingroup GDO_Types_Response
*/
#define GNSDK_GDO_TYPE_RESPONSE_ACR						"ctx_response_acr"


/** @internal GNSDK_GDO_TYPE_MATCH_ACR @endinternal
  *
  *   ACR match type.
* @ingroup GDO_Types_Acr
*/
#define GNSDK_GDO_TYPE_MATCH_ACR							"ctx_match_acr"


/** @internal GNSDK_GDO_CHILD_MATCH_ACR @endinternal
  *
  *   Retrieves a child MATCH_ACR type.
* @ingroup GDO_ChildKeys_Acr
*/
#define GNSDK_GDO_CHILD_MATCH_ACR							GNSDK_GDO_TYPE_MATCH_ACR"!"


/** @internal GNSDK_GDO_VALUE_CHANNEL_GNID @endinternal
  *
  *   ACR type response.
* @ingroup GDO_ValueKeys_Channel
*/
#define GNSDK_GDO_VALUE_CHANNEL_GNID						"gnsdk_val_channel_gnid"

/** @internal GNSDK_GDO_VALUE_CHANNEL_NUM @endinternal
  *
  *   ACR type response.
* @ingroup GDO_ValueKeys_Channel
*/
#define GNSDK_GDO_VALUE_CHANNEL_NUM							"gnsdk_val_channel_num"

/** @internal GNSDK_GDO_VALUE_CHANNEL_NAME @endinternal
  *
  *   ACR type response.
* @ingroup GDO_ValueKeys_Channel
*/
#define GNSDK_GDO_VALUE_CHANNEL_NAME						"gnsdk_val_channel_name"

/** @internal GNSDK_GDO_VALUE_ONID @endinternal
  *
* @ingroup GDO_ValueKeys_Epg
*/
#define GNSDK_GDO_VALUE_ONID								"gnsdk_val_onid"
/** @internal GNSDK_GDO_VALUE_TSID @endinternal
  *
* @ingroup GDO_ValueKeys_Epg
*/
#define GNSDK_GDO_VALUE_TSID								"gnsdk_val_tsid"
/** @internal GNSDK_GDO_VALUE_SID @endinternal
  *
* @ingroup GDO_ValueKeys_Epg
*/
#define GNSDK_GDO_VALUE_SID									"gnsdk_val_sid"

/** @internal GNSDK_GDO_VALUE_PLACE @endinternal
  *
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_PLACE								"gnsdk_val_place"
/** @internal GNSDK_GDO_VALUE_IDENT @endinternal
  *
* @ingroup GDO_ValueKeys_Ident
*/
#define GNSDK_GDO_VALUE_IDENT								"gnsdk_val_ident"

/** @internal GNSDK_GDO_VALUE_CHANNEL_CALLSIGN @endinternal
 *
* @ingroup GDO_ValueKeys_Channel
*/
#define GNSDK_GDO_VALUE_CHANNEL_CALLSIGN					"gnsdk_val_channel_callsign"

/** @internal GNSDK_GDO_VALUE_ACR_MATCH_POSITION_ACTUAL @endinternal
*
* @deprecated NB: This key has been marked as deprecated and will be removed from the next major release.
*	Use GNSDK_GDO_VALUE_MATCH_POSITION_MS instead.
*
* @ingroup GDO_ValueKeys_Acr
*/
#define GNSDK_GDO_VALUE_ACR_MATCH_POSITION_ACTUAL			GNSDK_GDO_VALUE_MATCH_POSITION_MS

/** @internal GNSDK_GDO_VALUE_ACR_MATCH_POSITION_ADJUSTED @endinternal
*
* @deprecated NB: This key has been marked as deprecated and will be removed from the next major release.
*	Use GNSDK_GDO_VALUE_CURRENT_POSITION_MS instead.
*
* @ingroup GDO_ValueKeys_Acr
*/
#define GNSDK_GDO_VALUE_ACR_MATCH_POSITION_ADJUSTED			GNSDK_GDO_VALUE_CURRENT_POSITION_MS

/** @internal GNSDK_GDO_VALUE_ACR_MATCH_POSITION @endinternal
*
* @deprecated NB: This key has been marked as deprecated and will be removed from the next major release.
*	Use GNSDK_GDO_VALUE_MATCH_POSITION_MS instead.
*
* @ingroup GDO_ValueKeys_Acr
*/
#define GNSDK_GDO_VALUE_ACR_MATCH_POSITION					GNSDK_GDO_VALUE_MATCH_POSITION_MS


/** @internal GNSDK_GDO_VALUE_FP_CREATION_DATE @endinternal
  *
  *   The date the fingerprint was created.
* @ingroup GDO_ValueKeys_Fingerprint
*/
#define GNSDK_GDO_VALUE_FP_CREATION_DATE					"gnsdk_val_fp_creation_date"

/** @internal GNSDK_GDO_CHILD_TITLE_SUBTITLE @endinternal
*  Retrieves a subtitle child for TVPROGRAM or ACR_MATCH
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_TITLE_SUBTITLE					GNSDK_GDO_TYPE_TITLE"!subtitle"

/** @internal GNSDK_GDO_VALUE_LISTING @endinternal
  *
* @ingroup GDO_ValueKeys_Listing
*/
#define GNSDK_GDO_VALUE_LISTING								"gnsdk_val_listing"

/** @internal GNSDK_GDO_VALUE_DATE_START @endinternal
  *
* @ingroup GDO_ValueKeys_Date
*/
#define GNSDK_GDO_VALUE_DATE_START							"gnsdk_val_date_start"
/** @internal GNSDK_GDO_VALUE_DATE_END @endinternal
  *
* @ingroup GDO_ValueKeys_Date
*/
#define GNSDK_GDO_VALUE_DATE_END							"gnsdk_val_date_end"

/** @internal GNSDK_GDO_VALUE_EPGVIEWINGTYPE @endinternal
  *
* @ingroup GDO_ValueKeys_Epg
*/
#define GNSDK_GDO_VALUE_EPGVIEWINGTYPE						"gnsdk_val_epgviewingtype"
/** @internal GNSDK_GDO_VALUE_EPGAUDIOTYPE @endinternal
  *
* @ingroup GDO_ValueKeys_Epg
*/
#define GNSDK_GDO_VALUE_EPGAUDIOTYPE						"gnsdk_val_epgaudiotype"
/** @internal GNSDK_GDO_VALUE_EPGVIDEOTYPE @endinternal
  *
* @ingroup GDO_ValueKeys_Epg
*/
#define GNSDK_GDO_VALUE_EPGVIDEOTYPE						"gnsdk_val_epgvideotype"
/** @internal GNSDK_GDO_VALUE_EPGCAPTIONTYPE @endinternal
  *
* @ingroup GDO_ValueKeys_Epg
*/
#define GNSDK_GDO_VALUE_EPGCAPTIONTYPE						"gnsdk_val_epgcaptiontype"
/** @internal GNSDK_GDO_VALUE_EPGCATEGORY_L1 @endinternal
  *
* @ingroup GDO_ValueKeys_Epg
*/
#define GNSDK_GDO_VALUE_EPGCATEGORY_L1						"gnsdk_val_epgcatl1"
/** @internal GNSDK_GDO_VALUE_EPGCATEGORY_L2 @endinternal
  *
* @ingroup GDO_ValueKeys_Epg
*/
#define GNSDK_GDO_VALUE_EPGCATEGORY_L2						"gnsdk_val_epgcatl2"
/** @internal GNSDK_GDO_VALUE_EPGPRODUCTIONTYPE @endinternal
  *
* @ingroup GDO_ValueKeys_Epg
*/
#define GNSDK_GDO_VALUE_EPGPRODUCTIONTYPE					"gnsdk_val_epgproductiontype"



/** @internal GNSDK_GDO_VALUE_ACR_TMS_ID @endinternal
  *
  *   <p><b>TMS ID for ACR.</b></p>
  *
  * NOTE that this is a temporary key. It will soon go away and fetching the
  * TMS ID from an ACR response will be done though the link API, the same
  * way other IDs are fetched.
* @ingroup GDO_ValueKeys_Acr
*/
#define GNSDK_GDO_VALUE_ACR_TMS_ID							"gnsdk_val_acr_tms_id"

/** @internal GNSDK_GDO_CHILD_VIDEO_WORK_NONSEASON @endinternal
*  Retrieves a child Video Work type that is not associated with a Season.
*  <ul>
*  <li>GNSDK_GDO_CHILD_VIDEO_WORK_NONSEASON</li>
*  </ul>
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_VIDEO_WORK_NONSEASON				GNSDK_GDO_TYPE_VIDEO_WORK"!nonseason"

/** @internal GNSDK_GDO_TYPE_RESPONSE_VIDEO_SEASON @endinternal
*  GDO is of a video Seasons response type.
*  <ul>
*  <li>GNSDK_GDO_TYPE_RESPONSE_VIDEO_SEASON</li>
*  </ul>
*
*  <p><b>Supported GDO Child Keys</b></p>
*  <ul>
*   <li>GNSDK_GDO_CHILD_VIDEO_SEASON</li>
*  </ul>
*
*  <p><b>Supported GDO Value Keys</b></p>
*  <ul>
*  <li>GNSDK_GDO_VALUE_RESPONSE_RANGE_END</li>
*  <li>GNSDK_GDO_VALUE_RESPONSE_RANGE_START</li>
*  <li>GNSDK_GDO_VALUE_RESPONSE_RANGE_TOTAL</li>
*  </ul>
*
* @ingroup GDO_Types_Video
*/
#define GNSDK_GDO_TYPE_RESPONSE_VIDEO_SEASON				"gnsdk_ctx_response_video_season"
/** @internal GNSDK_GDO_TYPE_VIDEO_SEASON @endinternal
*  GDO is of a video Season type.
*  <p><b>Remarks:</b></p>
*  This type supports Link data.
* @ingroup GDO_Types_Video
*/
#define GNSDK_GDO_TYPE_VIDEO_SEASON						"gnsdk_ctx_video_season"
/** @internal GNSDK_GDO_CHILD_VIDEO_SEASON @endinternal
*  Retrieve a child Season type.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for gnsdk_manager_gdo_child_get to retrieve child
*  GNSDK_GDO_TYPE_VIDEO_SEASON GDOs.
*
*  The ordinal parameter for <code>gnsdk_manager_gdo_child_get</code> with this key indicates the n'th child
video Season to retrieve.
*  Video product types are generally available from GNSDK_GDO_TYPE_RESPONSE_VIDEO_SEASON GDOs.
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_VIDEO_SEASON						GNSDK_GDO_TYPE_VIDEO_SEASON"!"
/** @internal GNSDK_GDO_TYPE_RESPONSE_VIDEO_SERIES @endinternal
*  GDO is of a video Series response type.
*
*  <p><b>Supported GDO Child Keys</b></p>
*  <ul>
*  <li>GNSDK_GDO_CHILD_VIDEO_SERIES</li>
*  </ul>
*
*  <p><b>Supported GDO Value Keys</b></p>
*  <ul>
*  <li>GNSDK_GDO_VALUE_RESPONSE_RANGE_END</li>
*  <li>GNSDK_GDO_VALUE_RESPONSE_RANGE_START</li>
*  <li>GNSDK_GDO_VALUE_RESPONSE_RANGE_TOTAL</li>
*   </ul>
*
* @ingroup GDO_Types_Video
*/
#define GNSDK_GDO_TYPE_RESPONSE_VIDEO_SERIES				"gnsdk_ctx_response_video_series"
/** @internal GNSDK_GDO_TYPE_VIDEO_SERIES @endinternal
*  GDO is of a video Series type.
* @ingroup GDO_Types_Video
*/
#define GNSDK_GDO_TYPE_VIDEO_SERIES							"gnsdk_ctx_video_series"
/** @internal GNSDK_GDO_CHILD_VIDEO_SERIES @endinternal
*  Retrieve a child Series type.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for gnsdk_manager_gdo_child_get to retrieve child
GNSDK_GDO_TYPE_VIDEO_SERIES GDOs.
*  The ordinal parameter for <code>gnsdk_manager_gdo_child_get</code> with this key indicates the n'th child
video Series to retrieve.
*  Video Series types are generally available from GNSDK_GDO_TYPE_RESPONSE_VIDEO_SERIES GDOs.
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_VIDEO_SERIES						GNSDK_GDO_TYPE_VIDEO_SERIES"!"

/** @internal GNSDK_GDO_TYPE_RESPONSE_CONTRIBUTOR @endinternal
*  GDO value keys specific to CONTRIBUTOR responses.
*  <p><b>Supported GDO Child Keys:</b></p>
*  <ul>
*    <li>GNSDK_GDO_CHILD_CONTRIBUTOR</li>
*  </ul>
*  <p><b>Supported GDO Value Keys:</b></p>
*  <ul>
*   <li>GNSDK_GDO_VALUE_RESPONSE_RANGE_START</li>
*   <li>GNSDK_GDO_VALUE_RESPONSE_RANGE_END</li>
*   <li>GNSDK_GDO_VALUE_RESPONSE_RANGE_TOTAL</li>
*  </ul>
* @ingroup GDO_Types_Contributor
*/

#define GNSDK_GDO_TYPE_RESPONSE_CONTRIBUTOR					"gnsdk_ctx_response_contributor"

/** @internal GNSDK_GDO_TYPE_CONTRIBUTOR @endinternal
  *
  *   GDO is of a Contributor type.
* @ingroup GDO_Types_Contributor
*/
#define GNSDK_GDO_TYPE_CONTRIBUTOR							"gnsdk_ctx_contributor"

/** @internal GNSDK_GDO_CHILD_CONTRIBUTOR @endinternal
*  Retrieves a child contributor type.
* @ingroup GDO_ChildKeys_Contributor
*/
#define GNSDK_GDO_CHILD_CONTRIBUTOR							GNSDK_GDO_TYPE_CONTRIBUTOR"!"

/** @internal GNSDK_GDO_TYPE_RESPONSE_VIDEO_OBJECT @endinternal
*  GDO contains keys specific to video Object responses.
*  <p><b>Remarks:</b></p>
*  This type can contain 0-n Video Explore Object responses of any type (Contributors, Products,
Seasons, Series, and Works, depending on
*  the input). Object responses are returned in the order they are received from Gracenote Service.
* @ingroup GDO_Types_Video
*/
#define GNSDK_GDO_TYPE_RESPONSE_VIDEO_OBJECT				"gnsdk_ctx_response_video_object"


/*****************************************************************************
** GDO Keys specific to Suggestion responses
*/

/** @internal GNSDK_GDO_TYPE_RESPONSE_SUGGESTIONS @endinternal
*  GDO is of search suggestion response type.
*  <p><b>Remarks:</b></p>
*  Value is used as return value for <code>gnsdk_manager_gdo_get_type</code>. Suggestion response types are
returned from query APIs of GNSDKs that return search suggestion content.
* @ingroup GDO_Types_Video
*/
#define GNSDK_GDO_TYPE_RESPONSE_SUGGESTIONS					"gnsdk_ctx_response_suggestions"

/** @internal GNSDK_GDO_VALUE_SUGGESTION_TITLE @endinternal
*  Retrieves the title for the current search suggestion type.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_SUGGESTION_TITLE					"gnsdk_val_suggestion_title"
/** @internal GNSDK_GDO_VALUE_SUGGESTION_TYPE @endinternal
*  Retrieves the type for the current search suggestion type; this value is only available for a
video product title search.
* @ingroup GDO_ValueKeys_Video
*/

#define GNSDK_GDO_VALUE_SUGGESTION_TYPE						"gnsdk_val_suggestion_type"


/** @internal GNSDK_GDO_VALUE_SUGGESTION_TEXT @endinternal
*  Retrieves the text for the current search suggestion type.
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_SUGGESTION_TEXT						"gnsdk_val_suggestion_text"

/** @internal GNSDK_GDO_TYPE_RESPONSE_VIDEOCLIP @endinternal
*  GDO Keys for video clip response objects.
*  <p><b>Supported GDO Child Keys</b></p>
*  <ul>
*  <li>GNSDK_GDO_CHILD_VIDEOCLIP</li>
*  </ul>
* @ingroup GDO_Types_Video
*/
#define GNSDK_GDO_TYPE_RESPONSE_VIDEOCLIP				"gnsdk_ctx_response_videoclip"
/** @internal GNSDK_GDO_TYPE_VIDEOCLIP @endinternal
*  GDO is of video clip type.
*  <p><b>Remarks:</b></p>
*  This type supports Link data.
* @ingroup GDO_Types_Video
*/
#define GNSDK_GDO_TYPE_VIDEOCLIP						"gnsdk_ctx_videoclip"

/** @internal GNSDK_GDO_CHILD_VIDEOCLIP @endinternal
*  Retrieves a child Video Clip type.
*  <p><b>Remarks:</b></p>
*  Key is used as parameter for <code>gnsdk_manager_gdo_child_get</code> to retrieve child
*  GNSDK_GDO_TYPE_VIDEOCLIP GDOs.
*  The ordinal parameter for <code>gnsdk_manager_gdo_child_get</code> with this key indicates the n'th child
Video Clip to retrieve.
*  Video Clip types are generally available from
*  GNSDK_GDO_TYPE_RESPONSE_VIDEOCLIP GDOs.
* @ingroup GDO_ChildKeys_Video
*/
#define GNSDK_GDO_CHILD_VIDEOCLIP						GNSDK_GDO_TYPE_VIDEOCLIP"!"

/** @internal GNSDK_GDO_VALUE_DISPLAY @endinternal
*  Retrieves the display value.
* @ingroup GDO_ValueKeys_Name
*/
#define GNSDK_GDO_VALUE_DISPLAY							"gnsdk_val_display"

/** @internal GNSDK_GDO_VALUE_DISPLAY_LANGUAGE @endinternal
*  Retrieves the language of the display value as ISO code.
*
* <b>Note: Display language IDs are not available for track titles.</b>
* @ingroup GDO_ValueKeys_Name
*/
#define GNSDK_GDO_VALUE_DISPLAY_LANGUAGE				"gnsdk_val_displaylang"

/** @internal GNSDK_GDO_VALUE_DISPLAY_LANGUAGE_DISPLAY @endinternal
  *
  *   Retrieves the display language as text (for example, "English").
  * @ingroup GDO_ValueKeys_Name
*/
#define GNSDK_GDO_VALUE_DISPLAY_LANGUAGE_DISPLAY		"gnsdk_val_langdisplay"

/** @internal GNSDK_GDO_VALUE_DISPLAY_SCRIPT @endinternal
*  Retrieves the script used by the display values as ISO 15924 code
* @ingroup GDO_ValueKeys_Name
*/
#define GNSDK_GDO_VALUE_DISPLAY_SCRIPT					"gnsdk_val_displayscript"

/** @internal GNSDK_GDO_VALUE_GIVEN @endinternal
  *
  *   Retrieves the given name for the display value.
  *
  * @ingroup GDO_ValueKeys_Name
*/
#define GNSDK_GDO_VALUE_GIVEN							"gnsdk_val_given"

/** @internal GNSDK_GDO_VALUE_PREFIX @endinternal
  *
  *   Retrieves the prefix of the display value.
  * @ingroup GDO_ValueKeys_Name
*/
#define GNSDK_GDO_VALUE_PREFIX							"gnsdk_val_prefix"

/** @internal GNSDK_GDO_VALUE_TEMPO_LEVEL1 @endinternal
*  Retrieves a tempo meta group value from a GDO. Use this key with sonic attribute data.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to gnsdk_manager_locale_load.
*  To render locale-dependent information for list-based values, the application must call
gnsdk_manager_locale_load and possibly also gnsdk_sdkmanager_gdo_set_locale. The application returns
a LocaleNotLoaded message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_TEMPO_LEVEL1					"gnsdk_val_l1tempo"
/** @internal GNSDK_GDO_VALUE_TEMPO_LEVEL2 @endinternal
*  Retrieves a sub tempo value from a GDO. Use this key with sonic attribute data.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to gnsdk_manager_locale_load.
*  To render locale-dependent information for list-based values, the application must call
gnsdk_manager_locale_load and possibly also gnsdk_sdkmanager_gdo_set_locale. The application returns
a LocaleNotLoaded message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_TEMPO_LEVEL2					"gnsdk_val_l2tempo"
/** @internal GNSDK_GDO_VALUE_TEMPO_LEVEL3 @endinternal
*  Retrieves a tempo micro group value from a GDO. Use this key with sonic attribute data.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to gnsdk_manager_locale_load.
*  To render locale-dependent information for list-based values, the application must call
gnsdk_manager_locale_load and possibly also gnsdk_sdkmanager_gdo_set_locale. The application returns
a LocaleNotLoaded message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_TEMPO_LEVEL3					"gnsdk_val_l3tempo"

/** @internal GNSDK_GDO_VALUE_MOOD_LEVEL1 @endinternal
*  Retrieves a sub mood value from a GDO.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to gnsdk_manager_locale_load.
*  To render locale-dependent information for list-based values, the application must call
gnsdk_manager_locale_load and possibly also gnsdk_sdkmanager_gdo_set_locale. The application returns
a LocaleNotLoaded message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_MOOD_LEVEL1						"gnsdk_val_l1mood"
/** @internal GNSDK_GDO_VALUE_MOOD_LEVEL2 @endinternal
*  Retrieves a mood meta group value from a GDO.
*  <p><b>Remarks:</b></p>
*  This is a list-based value requiring that the list be loaded into memory through a successful
call to gnsdk_manager_locale_load.
*  To render locale-dependent information for list-based values, the application must call
gnsdk_manager_locale_load and possibly also gnsdk_sdkmanager_gdo_set_locale. The application returns
a LocaleNotLoaded message when locale information is not set prior to a request for list-based value
information.
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_MOOD_LEVEL2						"gnsdk_val_l2mood"


/** @internal GNSDK_GDO_VALUE_COMMERCE_TYPE_RETAIL @endinternal
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_COMMERCE_TYPE_RETAIL			"1"

/** @internal GNSDK_GDO_VALUE_COMMERCE_TYPE_RENTAL @endinternal
* @ingroup GDO_ValueKeys_Video
*/
#define GNSDK_GDO_VALUE_COMMERCE_TYPE_RENTAL			"2"


/*****************************************************************************
** GDO Keys specific to MATCH_INFO responses
************************************************************/

/** @internal GNSDK_GDO_VALUE_MATCH_INFO_TYPE @endinternal
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_MATCH_INFO_TYPE					"gnsdk_val_match_info_type"
/** @internal GNSDK_GDO_TYPE_RESPONSE_MATCH_INFO @endinternal
* @ingroup GDO_Types_Music
*/
#define GNSDK_GDO_TYPE_RESPONSE_MATCH_INFO				"gnsdk_ctx_response_matchinfo"
/** @internal GNSDK_GDO_TYPE_MATCH_INFO @endinternal
* @ingroup GDO_Types_Music
*/
#define GNSDK_GDO_TYPE_MATCH_INFO						"gnsdk_ctx_matchinfo"

/** @internal GNSDK_GDO_CHILD_MATCH_INFO @endinternal
* @ingroup GDO_ChildKeys_Music
*/
#define GNSDK_GDO_CHILD_MATCH_INFO						GNSDK_GDO_TYPE_MATCH_INFO"!"

/** @internal GNSDK_GDO_VALUE_MATCH_INFO_TYPE_EXACT @endinternal
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_MATCH_INFO_TYPE_EXACT			"gnsdk_val_match_info_typed_exact"
/** @internal GNSDK_GDO_VALUE_MATCH_INFO_TYPE_NO_MATCH @endinternal
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_MATCH_INFO_TYPE_NO_MATCH		"gnsdk_val_match_info_typed_no_match"
/** @internal GNSDK_GDO_VALUE_MATCH_INFO_TYPE_FP_NONEXIST @endinternal
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_MATCH_INFO_TYPE_FP_NONEXIST		"gnsdk_val_match_info_typed__fingerprint_nonexist"
/** @internal GNSDK_GDO_VALUE_MATCH_INFO_TYPE_UNDEFINED @endinternal
* @ingroup GDO_ValueKeys_Music
*/
#define GNSDK_GDO_VALUE_MATCH_INFO_TYPE_UNDEFINED		"gnsdk_val_match_info_typed_undefined"

/* */
#define GNSDK_GDO_TYPE_FPLOCAL_CUSTOM_DATA            "gnsdk_ctx_fplocal_custom_data"

/* */
#define GNSDK_GDO_CHILD_FPLOCAL_CUSTOM_DATA           GNSDK_GDO_TYPE_FPLOCAL_CUSTOM_DATA"!"

/* */
#define GNSDK_GDO_VALUE_FPLOCAL_CUSTOM_DATA_ID   "custom_data_id"

/* */
#define GNSDK_GDO_VALUE_FPLOCAL_CUSTOM_DATA      "custom_data"

/* */
#define GNSDK_GDO_VALUE_CUSTOM_ID						"custom_id"

/* */
#define GNSDK_GDO_VALUE_CUSTOM_DATA						"custom_data"	

#ifdef __cplusplus
}
#endif

#endif /** @internal _GNSDK_MANAGER_GDO_H_ @endinternal
*  GDO interface for the GNSDK Manager.
*/
