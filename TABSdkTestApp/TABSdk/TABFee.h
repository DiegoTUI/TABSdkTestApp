//
//  TABFee.h
//  TabSdk-ios
//
//  Created by Diego Lafuente Garcia on 30/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Model of a fee included in a service
 */
@interface TABFee : MTLModel<MTLJSONSerializing>

/**
 The type of the fee
 */
@property (strong, nonatomic, readonly) NSString *type;

/**
 The price of the fee
 */
@property (strong, nonatomic, readonly) NSNumber *price;

@end
