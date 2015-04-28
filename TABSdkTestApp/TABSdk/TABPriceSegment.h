//
//  TABPriceSegment.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 20/02/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 A model of an age segment in a TABModality.
 */
@interface TABPriceSegment : MTLModel<MTLJSONSerializing>

/**
 The minimum age allowed for this segment
 */
@property (strong, nonatomic, readonly) NSNumber *from;

/**
 The maximum age allowed for this segment
 */
@property (strong, nonatomic, readonly) NSNumber *to;

/**
 The price for this age segment
 */
@property (strong, nonatomic, readonly) NSNumber *price;

/**
 The box office price for this age segment
 */
@property (strong, nonatomic, readonly) NSNumber *boxOfficePrice;

@end
