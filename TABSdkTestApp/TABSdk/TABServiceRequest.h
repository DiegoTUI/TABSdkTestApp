//
//  TABServiceRequest.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 11/03/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Model of a service request used as a parameter to preconfirm a booking.
 It specifies all the details of a service to be booked.
 */
@interface TABServiceRequest : MTLModel<MTLJSONSerializing>

/**
 The purchaseableServiceId from the selected TABOperationDate in the desired TABModality.
 */
@property (strong, nonatomic, readonly) NSString *purchaseableServiceId;

/**
 The paxes to be booked. This is an array of TABPax objects. Only needed if the TABValuedActivity object returned by the activity detail operation returned pax questions in the selected operation date.
 */
@property (strong, nonatomic, readonly) NSArray *paxesInformation;

/**
 The answers to the contract questions for this booking. This is an array of TABAnswer objects.
 */
@property (strong, nonatomic, readonly) NSArray *answers;


/**
 @methodName initWithValuedActivity:modalityCode:date:paxes:andContractResponses:
 @abstract Initializes a service request.
 @discussion This method initializes a service request with the needed info. It returns nil if the parameters are invalid.
 
 @param purchaseableServiceId [required] A valid purchaseableServiceId extracted from a TABOperationDate in the selected TABModality.
 @param paxesInformation [optional] An array of TABPax objects specifying the paxes to be booked. Only needed if the TABValuedActivity object returned by the activity detail operation returned pax questions in the selected operation date.
 @param answers [optional] An array of TABAnswer objects. Could be empty or nil.
 @return An instance of the initialized service request or nil if invalid parameters are provided.
 */
- (id)initWithPurchaseableServiceId:(NSString *)purchaseableServiceId
                   paxesInformation:(NSArray *)paxesInformation
                         andAnswers:(NSArray *)answers;

@end
