//
//  TABValuedActivity.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 05/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import "TABActivity.h"
#import <CoreLocation/CoreLocation.h>

/**
 Model of an extended TAB Activity. Includes all the info of the activity.
 */
@interface TABValuedActivity : TABActivity

/**
 The full set of descriptions of the activity, including the inherited short description shortDescription. An NSArray of TABDescription objects.
 */
@property (strong, nonatomic, readonly) NSArray *descriptions;

/**
 Contract comments for the activity. An NSArray of TABComment objects
 */
@property (strong, nonatomic, readonly) NSArray *comments;

/**
 An NSArray of NSStrings with the items included in the activity
 */
@property (strong, nonatomic, readonly) NSArray *included;

/**
 An NSArray of NSStrings with the items excluded from the activity
 */
@property (strong, nonatomic, readonly) NSArray *excluded;

/**
 Geolocation of the activity
 */
@property (nonatomic, readonly) CLLocationCoordinate2D coordinates;

/**
 Address of the activity
 */
@property (strong, nonatomic, readonly) NSString *address;

/**
 Modalities available for the activity. This is an array of TABModality objects.
 */
@property (strong, nonatomic, readonly) NSArray *modalities;

/**
 Contract questions for this activity. This is an array of TABContractQuestion objects.
 */
@property (strong, nonatomic, readonly) NSArray *questions;



@end
