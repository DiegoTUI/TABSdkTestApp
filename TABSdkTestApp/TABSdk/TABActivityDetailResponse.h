//
//  TABActivityDetailResponse.h
//  TabSdk-ios
//
//  Created by Diego Lafuente Garcia on 31/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import "TABServerResponse.h"
#import "TABValuedActivity.h"

/**
 A model of an activity detail response.
 */
@interface TABActivityDetailResponse : TABServerResponse

/**
 The activity details in the response.
 */
@property (strong, nonatomic, readonly) TABValuedActivity *activity;

/**
 The time (in seconds) until the purchaseableActivityId(s) returned in the response expire.
 */
@property (strong, nonatomic, readonly) NSNumber *timeToExpiration;

@end
