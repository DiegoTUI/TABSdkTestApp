//
//  TABConstants.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 19/02/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#ifndef TabSdk_ios_Constants_h
#define TabSdk_ios_Constants_h

#import "TABErrors.h"

/**
 Image sizes.
 */
typedef NS_ENUM(NSInteger, TABImageSize) {
    /// Unknown image size
    TABImageSizeUnknown = 0,
    /// Extra large
    TABImageSizeExtraLarge,
    /// Large
    TABImageSizeLarge,
    /// Medium
    TABImageSizeMedium,
    /// Small
    TABImageSizeSmall
};

/**
 Description types.
 */
typedef NS_ENUM(NSInteger, TABDescriptionType) {
    /// Unknown description type
    TABDescriptionTypeUnknown = 0,
    /// General description
    TABDescriptionTypeGeneral,
    /// Tooltip description
    TABDescriptionTypeTooltip,
    /// Short description
    TABDescriptionTypeShort,
    /// Short description
    TABDescriptionTypeLong
};

/**
 Modality unit types.
 */
typedef NS_ENUM(NSInteger, TABModalityUnitType) {
    /// Unknown modality unit type
    TABModalityUnitTypeUnknown = 0,
    /// Pax type
    TABModalityUnitTypePax,
    /// Service type
    TABModalityUnitTypeService
};

/**
 Modality types.
 */
typedef NS_ENUM(NSInteger, TABModalityType) {
    /// Unknown modality type
    TABModalityTypeUnknown = 0,
    /// Ticket type
    TABModalityTypeTicket
};

/**
 Comment types.
 */
typedef NS_ENUM(NSInteger, TABCommentType) {
    /// Unknown comment type
    TABCommentTypeUnknown = 0,
    /// Contract remarks
    TABCommentTypeContractRemarks
};

/**
 Status of a booking.
 */
typedef NS_ENUM(NSInteger, TABBookingStatus) {
    /// Unknown booking status
    TABBookingStatusUnknown = 0,
    /// On hold. Confirmation pending.
    TABBookingStatusHold,
    /// Confirmed.
    TABBookingStatusConfirmed,
    /// Cancelled
    TABBookingStatusCancelled
};

/**
 Credit card type.
 */
typedef NS_ENUM(NSInteger, TABCreditCardType) {
    /// Visa
    TABCreditCardTypeVisa = 0,
    /// Mastercard
    TABCreditCardTypeMastercard,
    /// American Express
    TABCreditCardTypeAmex
};

/**
 Pax question code.
 */
typedef NS_ENUM(NSInteger, TABPaxQuestionCode) {
    /// Unknown pax question code
    TABPaxQuestionCodeUnknown = 0,
    /// Code for a px question about weight
    TABPaxQuestionCodeWeight
};

// default language for the client
#define DEFAULT_CLIENT_LANGUAGE @"en"
// default (INVALID) destination
#define INVALID_DESTINATION @"TAB_INVALID_DESTINATION"
// default number of days for the avail query
#define DEFAULT_NUMBER_OF_DAYS 7

// empty string
#define EMPTY_STRING @""

// base url
#if (DEBUG || TESTING)
#define API_URL @"http://sa3dmt01.hotelbeds:23002/actdis-api/public/v1/"
#define OSC_URL @"http://wl3mpt01.hotelbeds:7009/actapi/"
#else
#define API_URL @"https://activitiesapi.activitiesbank.com/v1/"
#define OSC_URL @"https://osc.activitiesbank.com/v1/"
#endif

// Test API key and secret
#define TEST_SDK_API_KEY @"VISITLONDON1234"
#define TEST_SDK_API_SECRET @"VISITLONDON1234"
#define TEST_SDK_DESTINATION @"LON"

#endif
