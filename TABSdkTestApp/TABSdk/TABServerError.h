//
//  TABServerError.h
//  TabSdk-ios
//
//  Created by Diego Lafuente Garcia on 30/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Model of an error returned by the server
 */
@interface TABServerError : MTLModel<MTLJSONSerializing>

/**
 The error code
 */
@property (strong, nonatomic, readonly) NSString *code;

/**
 The description of the error
 */
@property (strong, nonatomic, readonly) NSString *description;

@end
