//
//  TABPax.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 11/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Model of a pax to be used for parsing paxes in TABBookingDetail responses.
 */
@interface TABPax : MTLModel<MTLJSONSerializing>

/**
 The age of this pax
 */
@property (strong, nonatomic, readonly) NSNumber *age;

/**
 The customer id of this pax. This parameter is returned within each TABServiceDetail object in TABBookingDetail. Set to nil by initWithAge:
 */
@property (strong, nonatomic, readonly) NSString *customerId;

/**
 The answers to the pax-specific questions. This parameter has to be assigned after initialization. Set to nil by initWithAge:
 */
@property (strong, nonatomic) NSArray *answers;

@end
