//
//  TABBookingDetailResponse.h
//  TabSdk-ios
//
//  Created by Diego Lafuente Garcia on 31/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import "TABServerResponse.h"
#import "TABBookingDetail.h"

/**
 A model of a booking detail response.
 */
@interface TABBookingDetailResponse : TABServerResponse

/**
 The booking details in the response.
 */
@property (strong, nonatomic, readonly) TABBookingDetail *booking;

@end
