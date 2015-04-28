//
//  TABServerResponse.h
//  TabSdk-ios
//
//  Created by Diego Lafuente Garcia on 30/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TABPagination.h"

/**
 A model of a server response.
 */
@interface TABServerResponse : MTLModel<MTLJSONSerializing>


/**
 The id of the operation
 */
@property (strong, nonatomic, readonly) NSString *operationId;


/**
 The errors returned by the server. If nil, then no errors occured. This is a list of TABServerError objects.
 */
@property (strong, nonatomic, readonly) NSArray *errors;

@end
