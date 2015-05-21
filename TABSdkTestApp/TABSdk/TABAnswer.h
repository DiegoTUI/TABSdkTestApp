//
//  TABAnswer.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 11/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TABQuestion.h"

/**
 Model of an answer for a question at the activity or operation date level. Answers are needed as parameters of some requests.
 */
@interface TABAnswer : MTLModel<MTLJSONSerializing>

/**
 The contract question to respond
 */
@property (strong, nonatomic, readonly) TABQuestion *question;

/**
 The text of the response to the question
 */
@property (strong, nonatomic, readonly) NSString *text;

/**
 @methodName initWithQuestion:andAnswer:
 @abstract Initializes a contract response.
 @discussion This method initializes a contract response with a given TABQuestion and an answer.
 Use this method to initialize a TABAnswer and pass it as a parameter to a request.
 
 @param question [required] The TABQuestion to respond.
 @param answer [required] The answer to the question.
 @return An instance of the initialized contract response.
 */
- (id)initWithQuestion:(TABQuestion *)question
             andAnswer:(NSString *)answer;

@end
