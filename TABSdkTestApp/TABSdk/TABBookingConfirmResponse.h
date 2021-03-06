//
//  TABBookingConfirmResponse.h
//  TabSdk-ios
//
//  Created by Diego Lafuente Garcia on 31/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import "TABServerResponse.h"
#import "TABBookingDetail.h"

/**
 A model of a booking confirm response.
 */
@interface TABBookingConfirmResponse : TABServerResponse

/**
 The booking details in the response.
 */
@property (strong, nonatomic, readonly) TABBookingDetail *booking;

/**
 The url of the web payment gateway. ONLY VALID FOR OPTION 1. WILL BE REMOVED IN OPTION 2.
 */
@property (strong, nonatomic, readonly) NSURL *paymentUrl;

@end
