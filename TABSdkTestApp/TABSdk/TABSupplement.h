//
//  TABSupplement.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 30/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Model of a supplement included in a service
 */
@interface TABSupplement : MTLModel<MTLJSONSerializing>

/**
 The number of supplements included in the service
 */
@property (strong, nonatomic, readonly) NSNumber *quantity;

/**
 The name of the supplement
 */
@property (strong, nonatomic, readonly) NSString *name;

/**
 The type of the supplement
 */
@property (strong, nonatomic, readonly) NSString *type;

/**
 The description of the supplement
 */
@property (strong, nonatomic, readonly) NSString *info;

/**
 The starting date where the supplement applies
 */
@property (strong, nonatomic, readonly) NSDate *from;

/**
 The end date where the supplement ceases to apply
 */
@property (strong, nonatomic, readonly) NSDate *to;

/**
 The price of this supplement
 */
@property (strong, nonatomic, readonly) NSNumber *price;

@end
