//
//  TABNetworkClient.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 26/02/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TABServerError.h"

/**
 The client for the network connections.
 */
@interface TABNetworkClient : NSObject

/**
 @methodName sharedInstance
 @abstract Returns the unique instance of the TABNetwork object
 @discussion Creates and returns a unique instance of the TABNetwork object.
 
 @return The unique instance of TABNetwork
 */
+ (TABNetworkClient *)sharedInstance;

/**
 @methodName setAPIKey:
 @abstract Sets the API key for all the requests.
 @discussion This method sets the API key for all the requests where it is needed.
 
 @param apiKey [required] The API key to set
 */
- (void)setAPIKey:(NSString *)apiKey;

/**
 @methodName setAPISecret:
 @abstract Sets the API secret for all the requests.
 @discussion This method sets the API secret for all the requests where it is needed.
 
 @param apiSecret [required] The API secret to set
 */
- (void)setAPISecret:(NSString *)apiSecret;

/**
 @methodName cancelAllRequests
 @abstract Cancels all the ongoing requests
 @discussion This method cancels all the ongoing requests.
 */
- (void)cancelAllRequests;

/**
 @methodName GETRequestWithURL:parameters:completion:
 @abstract Performs a GET request to the given URL and parameters and returns result in completion block.
 @discussion This method performs a GET request to the given URL and parameters and returns result in completion block.
 If successful, the result could be either a NSDictionary or an NSArray. Timeout is set to AFNetworking's default (2 minutes).
 
 @param url [required] The URL to call
 @param parameters [optional] Parameters to be included in the body
 @param completion [required] The completion block to receive the result
 */
- (void)GETRequestWithURL:(NSURL *)url
               parameters:(NSDictionary *)parameters
               completion:(void (^)(TABServerError *error, id result))completion;

/**
 @methodName POSTRequestWithURL:parameters:completion:
 @abstract Performs a POST request to the given URL and parameters and returns result in completion block.
 @discussion This method performs a POST request to the given URL and parameters (that will be sent in the body of the request) and returns result in completion block.
 If successful, the result could be either a NSDictionary or an NSArray. Timeout is set to AFNetworking's default (2 minutes).
 
 @param url [required] The URL to call
 @param parameters [optional] Parameters to be included in the body
 @param completion [required] The completion block to receive the result
 */
- (void)POSTRequestWithURL:(NSURL *)url
                parameters:(NSDictionary *)parameters
                completion:(void (^)(TABServerError *error, id result))completion;

/**
 @methodName fetchTokenWithCompletion:
 @abstract Performs a request for the token and returns result in completion block.
 @discussion This method performs a request for the token using the credentials stored in TABNetworkClient and returns result in completion block.
 If successful, the result could be either a NSDictionary or an NSArray. Timeout is set to AFNetworking's default (2 minutes).
 
 @param completion [required] The completion block to receive the result
 */
- (void)fetchTokenWithCompletion:(void (^)(TABServerError *error, id result))completion;

@end
