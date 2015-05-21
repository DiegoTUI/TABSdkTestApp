//
//  TABSeat.h
//  TabSdk-ios
//
//  Created by Diego Lafuente Garcia on 21/04/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Model of a seat in an activity (typicallly for sport events, theaters and the like). Returned by TABBookingDetail when relevant.
 */
@interface TABSeat : MTLModel<MTLJSONSerializing>

/**
 The customer id for the person sitting here
 */
@property (strong, nonatomic, readonly) NSString *customerId;

/**
 The entrance door for this seat. Tipically, the outside gate in a Stadium.
 */
@property (strong, nonatomic, readonly) NSString *entranceDoor;

/**
 The entrance gate for this seat. Tipically, the inside gate in a Stadium.
 */
@property (strong, nonatomic, readonly) NSString *gate;

/**
 The row for this seat.
 */
@property (strong, nonatomic, readonly) NSString *row;

/**
 The seat number for this seat.
 */
@property (strong, nonatomic, readonly) NSString *number;

@end
