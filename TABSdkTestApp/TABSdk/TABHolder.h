//
//  TABHolder.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 11/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Model of the holder of a booking.
 */
@interface TABHolder : MTLModel<MTLJSONSerializing>

/**
 First name of the person holding the booking
 */
@property (strong, nonatomic, readonly) NSString *name;

/**
 Last name of the person holding the booking
 */
@property (strong, nonatomic, readonly) NSString *lastName;


/**
 @methodName initWithName:phone:andEmail:
 @abstract Initializes a holder.
 @discussion This method initializes a holder with the given name, phone and email.
 
 @param name [required] The name of the holder
 @param lastName [required] The surname of the holder
 @return An instance of the initialized holder.
 */
- (id)initWithName:(NSString *)name
          lastName:(NSString *)lastName;

@end
