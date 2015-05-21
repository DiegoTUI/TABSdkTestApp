//
//  ViewController.m
//  TABSdkTestApp
//
//  Created by Diego Lafuente Garcia on 01/04/15.
//  Copyright (c) 2015 Diego Lafuente Garcia. All rights reserved.
//

#import <Mantle/Mantle.h>
#import "ViewController.h"
#import "TABConstants.h"
#import "TABSdk.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // A simple booking cycle for the TABSDK
    
    // Init the client
    TABActivitiesClient *client = [[TABActivitiesClient alloc] initWithAPIKey:@"VISITLONDON1234" andAPISecret:@"VISITLONDON1234"];
    
    // Set the language for the client (defaults to en)
    client.language = @"en";
    
    // set the dates
    NSDateComponents *offsetComponents = [[NSDateComponents alloc] init];
    NSDate *now = [NSDate date];
    [offsetComponents setDay:35];
    __block NSDate *from = [[NSCalendar currentCalendar] dateByAddingComponents:offsetComponents toDate:now options:0];
    [offsetComponents setDay:7];
    __block NSDate *to = [[NSCalendar currentCalendar] dateByAddingComponents:offsetComponents toDate:from options:0];;
    
    /*************************************************************************
     * Fetch activities for destination London.
     *************************************************************************/
    
    __block TABActivity *activity;
    NSLog(@"before fetchActivitiesForDestination: %@", API_URL);
    [client fetchActivitiesForDestination:@"LON" fromDate:from toDate:to pagination:nil completion:^(TABActivityListResponse *activityListResponse) {
        if (activityListResponse.errors.count) {
            // do something about it
            return;
        }
        NSLog(@"Operation id for activity list: %@", activityListResponse.operationId);
        // get first activity
        activity = activityListResponse.activities[0];
        
        // Now fetch activity details
        // create paxes (just one adult)
        __block NSArray *paxes = @[[[TABPax alloc] initWithAge:@30]];
        
        /*************************************************************************
         * Get details for the selected activity
         *************************************************************************/
        
        __block TABOperationDate *operationDate;
        [client fetchDetailsForActivityCode:activity.code inDestination:@"LON" fromDate:from toDate:to paxes:paxes completion:^(TABActivityDetailResponse *activityDetailResponse) {
            if (activityDetailResponse.errors.count) {
                // do something about it
                return;
            }
            NSLog(@"Operation id for activity detail: %@", activityDetailResponse.operationId);
            // the user selects one modality and then one operation date
            operationDate = [(TABModality *)activityDetailResponse.activity.modalities[0] operationDates][0];
            
            /*************************************************************************
             * Book it for the first operation date
             *************************************************************************/
            
            // create a holder of the booking
            TABHolder *holder = [[TABHolder alloc] initWithName:@"firstname" lastName:@"lastname"];
            // create service request.
            // check for contract questions
            NSMutableArray *contractAnswers = [NSMutableArray array];
            for (TABContractQuestion *question in activityDetailResponse.activity.questions) {
                TABContractAnswer *answer = [[TABContractAnswer alloc] initWithQuestion:question andAnswer:@"you should place the correct answer here"];
                [contractAnswers addObject:answer];
            }
            // check for pax questions and answer the for each of your paxes
            NSMutableArray *paxesInformation = [NSMutableArray array];
            if ([operationDate.questions count] > 0) {
                for (TABPax *pax in paxes) {
                    NSMutableArray *paxAnswers = [NSMutableArray array];
                    for (TABPaxQuestion *question in operationDate.questions) {
                        TABPaxAnswer *answer = [[TABPaxAnswer alloc] initWithQuestion:question andAnswer:@"you should place the correct PAX answer here"];
                        [paxAnswers addObject:answer];
                    }
                    pax.answers = paxAnswers;
                    [paxesInformation addObject:pax];
                }
            }
            TABServiceRequest *serviceRequest = [[TABServiceRequest alloc] initWithPurchaseableServiceId:operationDate.purchaseableServiceId paxesInformation:paxesInformation andAnswers:contractAnswers];
            // create cardInformation (fake card in this case)
            NSDate *now = [NSDate date];
            NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
            [dateFormatter setDateFormat:@"MM"];
            NSNumber *expirationMonth = [NSNumber numberWithInteger:[[dateFormatter stringFromDate:now] integerValue]];
            [dateFormatter setDateFormat:@"yyyy"];
            NSNumber *expirationYear = [NSNumber numberWithInteger:[[dateFormatter stringFromDate:now] integerValue] + 1];
            TABCardInformation *cardInformation = [[TABCardInformation alloc] initWithCardHolder:@"AUTHORIZED" email:@"holycrap@holycrap.crap" phone:@"666333111" cardNumber:@"4444333322221111" cardType:TABCreditCardTypeVisa cvc:@"555" expirationMonth:expirationMonth expirationYear:expirationYear];
            // confirm the booking
            __block TABBookingDetail *bookingDetail;
            [client confirmBookingForServices:@[serviceRequest] holder:holder customerReference:@"dummyCustomerReference" cardInformation:cardInformation completion:^(TABBookingConfirmResponse *bookingConfirmResponse) {
                if (bookingConfirmResponse.errors.count) {
                    // do something about it
                    return;
                }
                NSLog(@"Operation id for booking confirm: %@", bookingConfirmResponse.operationId);
                bookingDetail = bookingConfirmResponse.booking;
                
                /*************************************************************************
                 * Check booking details using TAB's reference
                 *************************************************************************/
                [client fetchBookingDetailsForReference:bookingDetail.reference completion:^(TABBookingDetailResponse *bookingDetailResponse) {
                    if (bookingDetailResponse.errors.count) {
                        // do something about it
                        return;
                    }
                    NSLog(@"Operation id for booking detail: %@", bookingDetailResponse.operationId);
                    
                    /*************************************************************************
                     * Cancel the booking using TAB's reference
                     *************************************************************************/
                    [client cancelBookingForReference:bookingDetail.reference completion:^(TABBookingCancelResponse *bookingCancelResponse) {
                        if (bookingCancelResponse.errors.count) {
                            // do something about it
                            return;
                        }
                        NSLog(@"Operation id for booking cancel: %@", bookingCancelResponse.operationId);
                    }];
                }];
            }];
        }];
    }];
    NSLog(@"THIS IS ASYNC!!!!");
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
