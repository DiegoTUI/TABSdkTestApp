//
//  Constants.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 19/02/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#ifndef TabSdk_ios_Constants_h
#define TabSdk_ios_Constants_h

#import "Errors.h"

/**
 Image sizes.
 */
typedef NS_ENUM(NSInteger, TABImageSize) {
    /// Unknown size
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
    /// General description
    TABDescriptionTypeGeneral = 0,
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
    /// Pax type
    TABModalityUnitTypePax = 0,
    /// Service type
    TABModalityUnitTypeService
};

/**
 Modality types.
 */
typedef NS_ENUM(NSInteger, TABModalityType) {
    /// Ticket type
    TABModalityTypeTicket = 0
};

/**
 Comment types.
 */
typedef NS_ENUM(NSInteger, TABCommentType) {
    /// Contract remarks
    TABCommentTypeContractRemarks = 0
};

/**
 Status of a booking.
 */
typedef NS_ENUM(NSInteger, TABBookingStatus) {
    /// On hold. Confirmation pending.
    TABBookingStatusHold = 0,
    /// Confirmed.
    TABBookingStatusConfirmed,
    /// Cancelled
    TABBookingStatusCancelled
};

// default language for the client
#define DEFAULT_CLIENT_LANGUAGE @"ENG"
// default (INVALID) destination
#define INVALID_DESTINATION @"TAB_INVALID_DESTINATION"
// default number of days for the avail query
#define DEFAULT_NUMBER_OF_DAYS 7

// empty string
#define EMPTY_STRING @""

// base url
#if (DEBUG || TESTING)
#define API_URL @"http://54.154.213.111/api/testapikey/"
#else
#define API_URL @"http://www.guidego.com/api/testapikey/"
#endif

// Test user and password
#define TEST_SDK_USER @"GUIDEGOEUR139789"
#define TEST_SDK_PASSWORD @"GUIDEGOEUR139789"
#define TEST_SDK_DESTINATION @"BCN"

#endif
