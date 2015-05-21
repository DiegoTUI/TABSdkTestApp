//
//  TABServiceDetail.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 11/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TABSupplier.h"
#import "TABPriceBreakdown.h"

/**
 The details of a service (an item included in a booking)
 */
@interface TABServiceDetail : MTLModel<MTLJSONSerializing>

/**
 The status of the service.
 */
@property (strong, nonatomic, readonly) NSString *status;

/**
 The supplier of the service.
 */
@property (strong, nonatomic, readonly) TABSupplier *supplier;

/**
 Contract comments for the service. An NSArray of TABComment objects
 */
@property (strong, nonatomic, readonly) NSArray *comments;

/**
 The activity code of the service.
 */
@property (strong, nonatomic, readonly) NSString *activityCode;

/**
 The activity name of the service.
 */
@property (strong, nonatomic, readonly) NSString *activityName;

/**
 The modality code of the service.
 */
@property (strong, nonatomic, readonly) NSString *modalityCode;

/**
 The modality name of the service.
 */
@property (strong, nonatomic, readonly) NSString *modalityName;

/**
 The id of the TAB factsheet for the activity included in this service.
 */
@property (strong, nonatomic, readonly) NSNumber *contentId;

/**
 The start date of the service.
 */
@property (strong, nonatomic, readonly) NSDate *from;

/**
 The end date of the service.
 */
@property (strong, nonatomic, readonly) NSDate *to;

/**
 The price of the service. In the case of a cancellation, it is the price of the service after the cancellation. If the price of a service is 60 and the cancellation costs at a certain date are 40, the price showed by this attribute after a cancellation will be 20.
 */
@property (strong, nonatomic, readonly) NSNumber *price;

/**
 An NSArray of TABPriceSegment objects specifying the prices for each age segment of the service.
 */
@property (strong, nonatomic, readonly) NSArray *paxPrices;

/**
 Breakdown of the price of the service
 */
@property (strong, nonatomic, readonly) TABPriceBreakdown *priceBreakdown;

/**
 An NSArray of TABAnswer objects specifying the questions and responses provided for this booking.
 */
@property (strong, nonatomic, readonly) NSArray *answers;

/**
 The cancellation fees that apply to this service. This is a list of TABCancellationFee objects.
 */
@property (strong, nonatomic, readonly) NSArray *cancellationFees;

/**
 The confirmation codes for each pax of this service. Note that in some services, all paxes share the same code (the "reference" in TABBookingDetail). This is a list of TABConfirmationCode objects
 */
@property (strong, nonatomic, readonly) NSArray *confirmationCodes;

/**
 The paxes of the service. This is a list of TABPax objects
 */
@property (strong, nonatomic, readonly) NSArray *paxes;

/**
 The vouchers of this service. This is a list of TABVoucher objects.
 */
@property (strong, nonatomic, readonly) NSArray *vouchers;

/**
 The vouchers of this service. This is a list of TABBarcode objects.
 */
@property (strong, nonatomic, readonly) NSArray *barcodes;

/**
 The assigned seats in this service. This is a list of TABSeat objects.
 */
@property (strong, nonatomic, readonly) NSArray *seats;

@end
