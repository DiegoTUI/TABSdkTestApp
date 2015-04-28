//
//  TABImage.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 19/02/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 A model of an image in a TABActivity or a TABValuedActivity
 */
@interface TABImage : MTLModel<MTLJSONSerializing>

/**
 Size of the image
 */
@property (nonatomic) TABImageSize size;

/**
 URL of the image
 */
@property (strong, nonatomic) NSURL *url;

@end
