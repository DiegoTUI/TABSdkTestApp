//
//  TABPax.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 11/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Model of a pax to be used in requests.
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

/**
 @methodName initWithAge:
 @abstract Initializes a pax with a given age.
 @discussion This method initializes a pax with a given age.
 Use this method to initialize a pax and pass it as a parameter to a request.
 
 @param age [required] The age of the pax
 @return An instance of the initialized pax.
 */
- (id)initWithAge:(NSNumber *)age;

@end
