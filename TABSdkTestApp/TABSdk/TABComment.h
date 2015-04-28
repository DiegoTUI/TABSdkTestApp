//
//  TABComment.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 26/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Model of a contract comment
 */
@interface TABComment : MTLModel<MTLJSONSerializing>

/**
 Type of the comment (general, tooltip, etc)
 */
@property (nonatomic) TABCommentType type;

/**
 Text of the comment
 */
@property (strong, nonatomic) NSString *text;

@end
