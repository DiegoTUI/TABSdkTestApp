//
//  TABInvoiceCompany.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 27/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 A model of a company with invoicing data.
 */
@interface TABInvoiceCompany : MTLModel<MTLJSONSerializing>

/**
 The code of the company
 */
@property (strong, nonatomic, readonly) NSString *code;

/**
 The name of the company
 */
@property (strong, nonatomic, readonly) NSString *name;

/**
 The registration number (i.e. VAT number) of the company
 */
@property (strong, nonatomic, readonly) NSString *registrationNumber;

@end
