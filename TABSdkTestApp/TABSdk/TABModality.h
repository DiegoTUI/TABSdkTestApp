//
//  TABModality.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 20/02/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 A model of a modality in a TABValuedActivity
 */
@interface TABModality : MTLModel<MTLJSONSerializing>

/**
 The code of the modality
 */
@property (strong, nonatomic, readonly) NSString *code;

/**
 The name of the modality
 */
@property (strong, nonatomic, readonly) NSString *name;

/**
 The unit type of the modality
 */
@property (nonatomic) TABModalityUnitType unitType;

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
 An NSArray of TABOperationDate specifying the operation dates for this modality
 */
@property (strong, nonatomic, readonly) NSArray *operationDates;

/**
 The list of Foursquare ids (as described in https://developer.foursquare.com) related to this modality.
 */
@property (strong, nonatomic, readonly) NSArray *foursquareIds;

@end
