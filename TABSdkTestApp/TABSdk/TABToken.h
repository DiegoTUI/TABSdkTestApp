//
//  TABToken.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 08/05/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Model of a token coming from the auth service
 */
@interface TABToken : MTLModel<MTLJSONSerializing>

/**
 The access token.
 */
@property (strong, nonatomic, readonly) NSString *accessToken;

/**
 The refresh token.
 */
@property (strong, nonatomic, readonly) NSString *refreshToken;

/**
 The type of the token.
 */
@property (strong, nonatomic, readonly) NSString *tokenType;

/**
 The duration of the token from the moment of reception (in seconds).
 */
@property (strong, nonatomic, readonly) NSNumber *expiresIn;

/**
 The actual date of expiration for the token. Calculated from the expiresIn when the token is received.
 */
@property (strong, nonatomic, readonly) NSDate *expiration;

/**
 @methodName updateExpirationDate
 @abstract Updates the expiration date based on the current local time and the expiresIn property.
 @discussion This method updates the expiration date based on the current local time and the expiresIn property.
 */
- (void)updateExpirationDate;

@end
