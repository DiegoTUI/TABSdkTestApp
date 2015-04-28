//
//  TabSdk_ios.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 18/02/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TABActivityListResponse.h"
#import "TABActivityDetailResponse.h"
#import "TABBookingPreconfirmResponse.h"
#import "TABBookingConfirmResponse.h"
#import "TABBookingDetailResponse.h"
#import "TABBookingCancelResponse.h"
#import "TABHolder.h"
#import "TABPagination.h"


/**
 The client for the TAB SDK
 */
@interface TABActivitiesClient : NSObject


/**
 Language for all requests: defaults to ENG
 */
@property (strong, nonatomic) NSString* language;

/**
 @methodName initWithAPIKey:andAPISecret
 @abstract Initializes the client with the given credentials
 @discussion This method initializes the client with the given credentials. Don't forget to set the language of the client if you want it to be different from the default.
 
 @param apiKey [required] The API key
 @param apiSecret [required] The API secret
 @return An instance of the initialized client.
 */
- (id)initWithAPIKey:(NSString *)apiKey
        andAPISecret:(NSString *)apiSecret;


/**
 @methodName fetchActivitiesForDestination:fromDate:toDate:pagination:completion:
 @abstract Fetches a list of available activities for the given parameters
 @discussion This method fetches a list of available activities (TABActivity objects embedded in a TABActivityListResponse) for the given parameters and returns it in the completion block.
 It uses the language property set in TABACtivitiesClient.
 
 @param destination [required] An NSString with the ATLAS code of a destination. The service will return an error if ommitted or empty.
 @param fromDate [optional] An NSDate object containing the start date for query. Only the year, month and day of the date will be used. Defaults to today.
 @param toDate [optional] An NSDate object containing the end date for query. Only the year, month and day of the date will be used. Defaults seven days from today.
 @param pagination [optional] A TABPagination object indicating the desired pagination for the response. If omitted, default pagination applies.
 @param completion [required] A block to be executed when the operation finishes. Returns an NSArray of TABValuedActivity embedded in a TABActivityListResponse object or an NSError. The TABActivityListResponse object may contain a TABPagination object indicating that there are more pages of activities.
 */
- (void)fetchActivitiesForDestination:(NSString *)destination
                             fromDate:(NSDate *)fromDate
                               toDate:(NSDate *)toDate
                           pagination:(TABPagination *)pagination
                           completion:(void (^)(NSError *error, TABActivityListResponse *response))completion;

/**
 @methodName fetchDetailsForActivityCode:inDestination:fromDate:toDate:paxes:completion:
 @abstract Fetches the details of an activity
 @discussion This method fetches the details (including valuation details) of an activity for certain dates and paxes. It returns a TABValuedActivity embedded in a TABActivityDetailResponse through the completion block ready to be booked. It uses the language property set in TABACtivitiesClient.
 
 @param activityCode [required] An NSString with the ATLAS code of the activity. The service will return an error if ommitted.
 @param destination [required] An NSString with the ATLAS code of a destination. The service will return an error if ommitted.
 @param fromDate [optional] An NSDate object containing the start date for query. Only the year, month and day of the date will be used. Defaults to today.
 @param toDate [optional] An NSDate object containing the end date for query. Only the year, month and day of the date will be used. Defaults to today.
 @param paxes [required] An array of TABPax objects to define the paxes of the activity. The service will return an error if ommitted.
 @param completion [required] A block to be executed when the operation finishes. Returns a TABValuedActivity embedded in a TABActivityDetailResponse object or an NSError.
 */
- (void)fetchDetailsForActivityCode:(NSString *)activityCode
                      inDestination:(NSString *)destination
                           fromDate:(NSDate *)fromDate
                             toDate:(NSDate *)toDate
                              paxes:(NSArray *)paxes
                         completion:(void (^)(NSError *error, TABActivityDetailResponse *response))completion;

/**
 @methodName preconfirmBookingForServices:holder:customerReference:completion:
 @abstract Sends a booking preconfirmation request.
 @discussion This method send a preconfirmation request for the specified services and holder. It returns (through the completion folder) a TABBookingDetail object embedded in a TABBookingPreconfirmResponse with the details of the preconfirmed booking. The TABBookingPreconfirmResponse object contains a bookingConfirmId attribute needed to confirm the booking. An optional customerReference parameter may be included in case the customer wants to use his own booking references. The status of this TABBookingDetail object is expected to be TABBookingStatusHold. The booking is on hold (and therefore not confirmed) until the confirmBooking:completion: method is invoked.
 
 @param services [required] An NSArray of TABServiceRequest objects containing the services to be preconfirmed. The service will return an error if omitted, nil, empty of invalid.
 @param holder [required] A TABHolder object containing the information of the holder of the booking. The service will return an error if ommitted.
 @param customerReference [optional] A reference number provided by the customer in prder to keep track of the booking in their system. If provided, this customerReference will be returned in the booking confirm, booking detail and booking cancel operations
 @param completion [required] A block to be executed when the operation finishes. Returns a TABBookingDetail embedded in a TABBookingPreconfirmResponse object or an NSError. Use the bookingConfirmId attribute in the TABBookingPreconfirmResponse to confirm the booking.
 */
- (void)preconfirmBookingForServices:(NSArray *)services
                              holder:(TABHolder *)holder
                   customerReference:(NSString *)customerReference
                          completion:(void (^)(NSError *error, TABBookingPreconfirmResponse *response))completion;

/**
 @methodName confirmBooking:completion:
 @abstract Sends a booking confirmation request.
 @discussion This method send a confirmation request for the bookingConfirmId returned by the preconfirmBookingForServices:holder:customerReference:completion: operation in the TABBookingPreconfirmResponse object. It returns (through the completion folder) a TABBookingDetail object embedded in a TABBookingConfirmResponse object with the details of the confirmed booking. The status of this TABBookingDetail object is expected to be TABBookingStatusConfirmed.
 
 @param bookingConfirmId [required] A valid bookingConfirmId as returned by  TABBookingPreconfirmResponse in preconfirmBookingForServices:holder:customerReference:completion:.
 @param completion [required] A block to be executed when the operation finishes. Returns a TABBookingDetail object embedded in a TABBookingConfirmResponse object or an NSError.
 */
- (void)confirmBooking:(NSString *)bookingConfirmId
            completion:(void (^)(NSError *error, TABBookingConfirmResponse *response))completion;

/**
 @methodName fetchBookingDetailsForReference:completion:
 @abstract Retrieves booking details for the given TAB booking reference.
 @discussion This method retrieves the booking details for the given TAB booking reference, as returned by either preconfirmBookingForServices:holder:customerReference:completion: or confirmBooking:completion: in the "reference" attribute of the TABBookingDetail object. If you want to use your own booking reference, use fetchBookingDetailsForCustomerReference:holder:fromDate:toDate:completion: instead. It returns (through the completion folder) a TABBookingDetail object embedded in a TABBookingDetailResponse object with the details of the requested booking.
 
 @param reference [required] The TAB booking reference found in the "reference" attribute of the TABBookingDetail object returned by either the preconfirmBookingForServices:holder:customerReference:completion: or the confirmBooking:completion: operations. This service will return an error if the reference is not provided.
 @param completion [required] A block to be executed when the operation finishes. Returns a TABBookingDetail object embedded in a TABBookingConfirmResponse object or an NSError.
 */
- (void)fetchBookingDetailsForReference:(NSString *)reference
                             completion:(void (^)(NSError *error, TABBookingDetailResponse *response))completion;

/**
 @methodName fetchBookingDetailsForCustomerReference:holder:fromDate:toDate:completion:
 @abstract Retrieves booking details for the given customer reference, holder and dates.
 @discussion This method retrieves the booking details for the given customer reference, holder and dates. You HAVE to provide a customer reference to the preconfirmBookingForServices:holder:customerReference:completion: if you want to use this method to retrieve the booking details. Holder, fromDate and toDate parameters are requires for security issues. It returns (through the completion folder) a TABBookingDetail object embedded in a TABBookingDetailResponse object with the details of the requested booking.
 
 @param customerReference [required] The customer reference provided to the preconfirmBookingForServices:holder:customerReference:completion: operation.
 @param holder [required] The holder of the booking
 @param from [required] The start date of the booking
 @param to [required] The end date of the booking
 @param completion [required] A block to be executed when the operation finishes. Returns a TABBookingDetail object embedded in a TABBookingDetailResponse object or an NSError.
 */
- (void)fetchBookingDetailsForCustomerReference:(NSString *)customerReference
                                         holder:(TABHolder *)holder
                                       fromDate:(NSDate *)from
                                         toDate:(NSDate *)to
                                     completion:(void (^)(NSError *error, TABBookingDetailResponse *response))completion;

/**
 @methodName cancelBookingForReference:completion:
 @abstract Cancels a booking based on the given TAB booking reference.
 @discussion This method attempts to cancel a booking given by its TAB booking reference, as returned by either preconfirmBookingForServices:holder:customerReference:completion: or confirmBooking:completion: in the "reference" attribute of the TABBookingDetail object. It returns (through the completion folder) a TABCancellation object embedded in a TABBookingCancelResponse object with the results of the cancellation request.
 
 @param reference [required] The booking reference found in the TABBookingDetail object returned by the preconfirmBookingForServices:holder:completion: and confirmBooking:completion: services. If you want to use your own booking reference, use cancelBookingForCustomerReference:holder:fromDate:toDate:completion: instead. This service will return an error if the reference is not provided.
 @param completion [required] A block to be executed when the operation finishes. Returns a TABCancellation object embedded in a TABBookingCancelResponse object or an NSError.
 */
- (void)cancelBookingForReference:(NSString *)reference
                       completion:(void (^)(NSError *error, TABBookingCancelResponse *response))completion;

/**
 @methodName cancelBookingForCustomerReference:holder:fromDate:toDate:completion:
 @abstract Cancels a booking defined by its customer reference, holder and dates.
 @discussion This method cancels a booking defined by its customer reference, holder and dates. You HAVE to provide a customer reference to the preconfirmBookingForServices:holder:customerReference:completion: if you want to use this method to cancel the booking. Holder, fromDate and toDate parameters are requires for security issues. It returns (through the completion folder) a TABCancellation object embedded in a TABBookingCancelResponse object with the results of the cancellation request..
 
 @param customerReference [required] The customer reference provided to the preconfirmBookingForServices:holder:customerReference:completion: operation.
 @param holder [required] The holder of the booking
 @param from [required] The start date of the booking
 @param to [required] The end date of the booking
 @param completion [required] A block to be executed when the operation finishes. Returns a TABCancellation object embedded in a TABBookingCancelResponse object or an NSError.
 */
- (void)cancelBookingForCustomerReference:(NSString *)customerReference
                                   holder:(TABHolder *)holder
                                 fromDate:(NSDate *)from
                                   toDate:(NSDate *)to
                               completion:(void (^)(NSError *error, TABBookingCancelResponse *response))completion;

@end
