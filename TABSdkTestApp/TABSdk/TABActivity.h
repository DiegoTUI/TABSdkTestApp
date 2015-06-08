//
//  TABActivity.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 19/02/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

/**
 Model of a basic TAB Activity. This model only includes the basic info of an activity. 
 For an extended model of an activity, refer to TABValuedActivity
 */
@interface TABActivity : MTLModel<MTLJSONSerializing>

/**
 The code of the activity
 */
@property (strong, nonatomic, readonly) NSString *code;

/**
 The name of the activity
 */
@property (strong, nonatomic, readonly) NSString *name;

/**
 The type of the activity
 */
@property (nonatomic) TABActivityType type;

/**
 The short description of the activity
 */
@property (strong, nonatomic, readonly) NSString *shortDescription;

/**
 Price for an adult in the cheapest modality of the activity
 */
@property (strong, nonatomic, readonly) NSNumber *adultPrice;

/**
 Price for an adult in the cheapest modality of the activity at the box office
 */
@property (strong, nonatomic, readonly) NSNumber *adultBoxOfficePrice;

/**
 Price for a child in the cheapest modality of the activity
 */
@property (strong, nonatomic, readonly) NSNumber *childPrice;

/**
 Price for a child in the cheapest modality of the activity at the box office
 */
@property (strong, nonatomic, readonly) NSNumber *childBoxOfficePrice;

/**
 The main picture of the activity in all the available sizes. This is an array of TABImage objects
 */
@property (strong, nonatomic, readonly) NSArray *images;

/**
 The list of Foursquare ids (as described in https://developer.foursquare.com) related to this activity.
 */
@property (strong, nonatomic, readonly) NSArray *foursquareIds;

/**
 An identifier to retrieve the full content of te activity if needed.
 */
@property (strong, nonatomic, readonly) NSNumber *contentId;

/**
 A list of keywords defining the activity. This is a NSArray of NSString objects.
 */
@property (strong, nonatomic, readonly) NSArray *keywords;

/**
 An indicator of the relevance of the activity according to TAB's system (the higher, the less relevant).
 */
@property (strong, nonatomic, readonly) NSNumber *order;


@end
