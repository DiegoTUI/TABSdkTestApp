//
//  TABPaxQuestion.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 14/05/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TABQuestion.h"

/**
 Model of a pax question that comes at operation date level. The code of the question is a TABPaxQuestionCode.
 */
@interface TABPaxQuestion : TABQuestion

/**
 The code of the contract question
 */
@property (nonatomic, readonly) TABPaxQuestionCode code;

@end
