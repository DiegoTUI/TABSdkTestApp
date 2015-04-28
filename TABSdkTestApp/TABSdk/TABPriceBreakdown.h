//
//  TABPriceBreakdown.h
//  TabSdk-ios
//
//  Created by Diego Lafuente Garcia on 30/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Price breakdown in a service
 */
@interface TABPriceBreakdown : MTLModel<MTLJSONSerializing>

/**
 Supplements in the price breakdown. This is an array of TABSupplement objects.
 */
@property (strong, nonatomic, readonly) NSArray *supplements;

/**
 Fees in the price breakdown. This is an array of TABFee objects.
 */
@property (strong, nonatomic, readonly) NSArray *fees;

@end
