//
//  TABVoucher.h
//  TabSdk-ios
//
//  Created by Diego Lafuente Garcia on 30/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Model of a voucher.
 */
@interface TABVoucher : MTLModel<MTLJSONSerializing>

/**
 The code of the voucher
 */
@property (strong, nonatomic, readonly) NSString *code;

/**
 The customerId of the voucher
 */
@property (strong, nonatomic, readonly) NSString *customerId;

/**
 The TAB code for the language of the voucher
 */
@property (strong, nonatomic, readonly) NSString *language;

/**
 The url of the voucher
 */
@property (strong, nonatomic, readonly) NSString *url;

/**
 The mimeType of the voucher
 */
@property (strong, nonatomic, readonly) NSString *mimeType;

@end
