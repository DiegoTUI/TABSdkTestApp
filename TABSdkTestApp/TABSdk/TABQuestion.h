//
//  TABQuestion.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 11/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Model of a question for an activity. Questions are returned at the activity and operation dates level and answers to those questions are required in the requests of some services.
 */
@interface TABQuestion : MTLModel<MTLJSONSerializing>

/**
 The code of the contract question
 */
@property (strong, nonatomic, readonly) NSString *code;

/**
 The text of the contract question
 */
@property (strong, nonatomic, readonly) NSString *text;

/**
 Boolean specifying if the question is required
 */
@property (strong, nonatomic, readonly) NSNumber *required;

@end
