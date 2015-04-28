//
//  TABDescription.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 26/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 A model of a description in a TABActivity or a TABValuedActivity
 */
@interface TABDescription : MTLModel<MTLJSONSerializing>

/**
 Type of the description (general, tooltip, etc)
 */
@property (nonatomic) TABDescriptionType type;

/**
 Text of the description
 */
@property (strong, nonatomic) NSString *text;

@end
