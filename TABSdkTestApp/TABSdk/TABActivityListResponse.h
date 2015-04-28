//
//  TABActivityListResponse.h
//  TabSdk-ios
//
//  Created by Diego Lafuente Garcia on 31/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import "TABServerResponse.h"
#import "TABPagination.h"

/**
 A model of a server response for the service fetchActivitiesForDestination:fromDate:toDate:pagination:completion:
 */
@interface TABActivityListResponse : TABServerResponse

/**
 The activities in the response. This is a list of TABActivity objects
 */
@property (strong, nonatomic, readonly) NSArray *activities;

/**
 Pagination of the request. If nil, then there is no pagination for this request.
 */
@property (strong, nonatomic, readonly) TABPagination *pagination;

@end
