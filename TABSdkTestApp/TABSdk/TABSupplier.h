//
//  TABSupplier.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 27/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Model of a supplier
 */
@interface TABSupplier : MTLModel<MTLJSONSerializing>

/**
 The name of the supplier
 */
@property (strong, nonatomic, readonly) NSString *name;

/**
 The VAT number of the supplier
 */
@property (strong, nonatomic, readonly) NSString *vatNumber;

@end
