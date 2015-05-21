//
//  TABOperationDate.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 23/02/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 A model of an operation date in a TABModality
 */
@interface TABOperationDate : MTLModel<MTLJSONSerializing>

/**
 The id needed to book the modality containing this object in the indicated date.
 */
@property (strong, nonatomic, readonly) NSString *purchaseableServiceId;

/**
 The date of the operation
 */
@property (strong, nonatomic, readonly) NSDate *date;

/**
 The minimum duration of the modality if booked at the given date (in days)
 */
@property (strong, nonatomic, readonly) NSNumber *minimum;

/**
 The maximum duration of the modality if booked at the given date (in days)
 */
@property (strong, nonatomic, readonly) NSNumber *maximum;

/**
 Total price for the given activity and modality, the operation date and the specified paxes.
 */
@property (strong, nonatomic, readonly) NSNumber *price;

/**
 Total box office price for the given activity and modality, the operation date and the specified paxes.
 */
@property (strong, nonatomic, readonly) NSNumber *boxOfficePrice;

/**
 An NSArray of TABPriceSegment objects specifying the prices for each age segment of the modality.
 */
@property (strong, nonatomic, readonly) NSArray *paxPrices;

/**
 An NSArray of TABQuestions objects needed to complete the booking for each pax.
 */
@property (strong, nonatomic, readonly) NSArray *questions;

/**
 Cancellation fees for this operationDate. This is an array of TABCancellationFee objects.
 */
@property (strong, nonatomic, readonly) NSArray *cancellationFees;

@end
