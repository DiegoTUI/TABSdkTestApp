//
//  TABQuestion.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 11/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Model of a generic question for an activity. Questions are returned at the activity level (see TABContractQuestion) and at the operation date level (see TABPaxQuestion). Answers to those questions are required in the requests of some services. Answers to both kinds of questions are given using the TABAnswer model.
 */
@interface TABQuestion : MTLModel<MTLJSONSerializing>

/**
 The text of the question
 */
@property (strong, nonatomic, readonly) NSString *text;

/**
 Boolean specifying if the question is required
 */
@property (strong, nonatomic, readonly) NSNumber *required;

@end
