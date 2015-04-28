//
//  TABConfirmationCode.h
//  TabSdk-ios
//
//  Created by Diego Lafuente Garcia on 30/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Confirmation code for an activity and a particular pax
 */
@interface TABConfirmationCode : MTLModel<MTLJSONSerializing>

/**
 The customer id, as returned in the TABPax object
 */
@property (strong, nonatomic, readonly) NSString *customerId;

/**
 The confirmation code for the given customerId
 */
@property (strong, nonatomic, readonly) NSString *code;

@end
