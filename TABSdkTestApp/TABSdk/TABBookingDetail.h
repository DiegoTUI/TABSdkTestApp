//
//  TABBookingDetail.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 11/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TABHolder.h"
#import "TABPaymentInformation.h"

/**
 The details of a booking
 */
@interface TABBookingDetail : MTLModel<MTLJSONSerializing>

/**
 The provider's own booking reference for the final customer. This is only returned if the provider has indicated its own booking reference.
 */
@property (strong, nonatomic, readonly) NSString *customerReference;

/**
 The TAB booking reference for the final customer. This is the proof of purchase.
 */
@property (strong, nonatomic, readonly) NSString *reference;

/**
 Status of the booking.
 */
@property (nonatomic, readonly) TABBookingStatus status;

/**
 Holder of the booking
 */
@property (strong, nonatomic, readonly) TABHolder *holder;

/**
 The currency for the prices in this booking.
 */
@property (strong, nonatomic, readonly) NSString *currency;

/**
 Total price of the booking. In the case of a cancellation, it is the price of the booking after the cancellation. If the price of a booking (with one ore more services) is 140 and the cancellation costs at a certain date for all the services in the booking are 30, the price showed by this attribute after a cancellation will be 110.
 */
@property (strong, nonatomic, readonly) NSNumber *price;

/**
 Net price of the booking.
 */
@property (strong, nonatomic, readonly) NSNumber *netPrice;

/**
 Pending amount for this booking.
 */
@property (strong, nonatomic, readonly) NSNumber *pendingAmount;

/**
 Payment information for this booking
 */
@property (strong, nonatomic, readonly) TABPaymentInformation *paymentInformation;

/**
 Services included in the booking. This is a list of TABServiceDetail objects
 */
@property (strong, nonatomic, readonly) NSArray *services;

@end
