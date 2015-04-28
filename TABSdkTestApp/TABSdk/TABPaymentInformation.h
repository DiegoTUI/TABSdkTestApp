//
//  TABPaymentInformation.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 27/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TABInvoiceCompany.h"

/**
 A model of the payment information returned by a booking request.
 */
@interface TABPaymentInformation : MTLModel<MTLJSONSerializing>

/**
 The type of payment (VISA, Mastercard)
 */
@property (strong, nonatomic, readonly) NSString *type;

/**
 The invoicing data of the company emitting the invoice.
 */
@property (strong, nonatomic, readonly) TABInvoiceCompany *invoiceCompany;

/**
 Status of the payment
 */
@property (strong, nonatomic, readonly) NSString *status;

/**
 Extra information about the payment
 */
@property (strong, nonatomic, readonly) NSString *info;

@end
