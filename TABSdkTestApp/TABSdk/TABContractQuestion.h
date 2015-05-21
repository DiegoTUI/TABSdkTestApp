//
//  TABContractQuestion.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 14/05/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TABQuestion.h"

/**
 Model of a contract question that comes at activity level. The code of the question is a "free flow" text string.
 */
@interface TABContractQuestion : TABQuestion

/**
 The code of the contract question
 */
@property (strong, nonatomic, readonly) NSString *code;

@end
