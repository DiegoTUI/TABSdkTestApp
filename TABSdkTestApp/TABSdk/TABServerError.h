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
@property (strong, nonatomic, readonly) NSString *text;

/**
 @methodName initWithGenericError
 @abstract Creates a generic TABServerError.
 @discussion This method creates a generic TABServerError.
 
 @return An instance of the initialized server error.
 */
- (id)initWithGenericError;

/**
 @methodName initWithTimeoutError
 @abstract Creates a timeout TABServerError.
 @discussion This method creates a timeout TABServerError.
 
 @return An instance of the initialized server error.
 */
- (id)initWithTimeoutError;

/**
 @methodName initWithNoConnectionError
 @abstract Creates a no connection TABServerError.
 @discussion This method creates a no connection TABServerError.
 
 @return An instance of the initialized server error.
 */
- (id)initWithNoConnectionError;

/**
 @methodName initWithInvalidParameter:
 @abstract Creates a TABServerError with an invalid parameter code and description.
 @discussion This method creates a TABServerError with an invalid parameter code and description.
 
 @param parameter [required] The name of the invalid parameter
 @return An instance of the initialized server error.
 */
- (id)initWithInvalidParameter:(NSString *)parameter;

/**
 @methodName initWithJsonParsingError
 @abstract Creates a JSON parsing TABServerError.
 @discussion This method creates a JSON parsing TABServerError.
 
 @return An instance of the initialized server error.
 */
- (id)initWithJsonParsingError;

@end
