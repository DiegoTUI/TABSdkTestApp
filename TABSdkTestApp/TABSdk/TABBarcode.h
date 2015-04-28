//
//  TABBarcode.h
//  TabSdk-ios
//
//  Created by Diego Lafuente Garcia on 30/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Model of a barcode
 */
@interface TABBarcode : MTLModel<MTLJSONSerializing>

/**
 The customer id of the barcode
 */
@property (strong, nonatomic, readonly) NSString *customerId;

/**
 The url of the barcode
 */
@property (strong, nonatomic, readonly) NSString *url;

/**
 The mimeType of the barcode
 */
@property (strong, nonatomic, readonly) NSString *mimeType;

@end
