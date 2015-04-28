//
//  TABCancellationFee.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 10/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Model of a cancellation fee for a booked activity.
 */
@interface TABCancellationFee : MTLModel<MTLJSONSerializing>

/**
 The start date where the cancellation fee applies. Take into account hours and minutes in the date. The date and time is referred to Z-time.
 */
@property (strong, nonatomic, readonly) NSDate *from;

/**
 The start date where the cancellation fee applies. Take into account hours and minutes in the date. The date and time is referred to Z-time.
 */
@property (strong, nonatomic, readonly) NSDate *to;

/**
 The amount of the fee
 */
@property (strong, nonatomic, readonly) NSNumber *amount;

@end
