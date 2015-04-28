//
//  TABPagination.h
//  TabSdk-ios
//
//  Created by Diego Lafuente Garcia on 30/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Model of a pagination item
 */
@interface TABPagination : MTLModel<MTLJSONSerializing>

/**
 Items per page
 */
@property (strong, nonatomic, readonly) NSNumber *itemsPerPage;

/**
 Current page
 */
@property (strong, nonatomic, readonly) NSNumber *page;

/**
 Total number of items in all the pages
 */
@property (strong, nonatomic, readonly) NSNumber *totalItems;

/**
 @methodName initWithItemsPerPage:andCurrentPage:
 @abstract Initializes a pagination object with given itemsPerPage and currentPage.
 @discussion This method initializes a pagination object with given itemsPerPage and currentPage.
 Use this method to initialize a pagination object and pass it as a parameter to a request.
 
 @param itemsPerPage [required] The items per page of the pagination object
 @param currentPage [required] The current page of the pagination object
 @return An instance of the initialized pagination object.
 */
- (id)initWithItemsPerPage:(NSNumber *)itemsPerPage
            andCurrentPage:(NSNumber *)currentPage;

@end
