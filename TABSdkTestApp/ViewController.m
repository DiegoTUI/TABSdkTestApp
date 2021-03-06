//
//  ViewController.m
//  TABSdkTestApp
//
//  Created by Diego Lafuente Garcia on 01/04/15.
//  Copyright (c) 2015 Diego Lafuente Garcia. All rights reserved.
//

#import <Mantle/Mantle.h>
#import "ViewController.h"
//#import "TABConstants.h"
#import "TABSdk.h"
#import "TABActivitiesClient.h"

@interface ViewController ()

@property (strong, nonatomic) TABActivitiesClient *client;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // A simple booking cycle for the TABSDK
    
    // Init the client
    _client = [[TABActivitiesClient alloc] initWithAPIKey:@"180915-1" andAPISecret:@"180915-1"];
    // Set TEST environment
    [_client setEnvironment:TABEnvironmentTest];
    
    // Set the language for the client (defaults to en)
    _client.language = @"en";
    
    // set the dates
    NSDateComponents *offsetComponents = [[NSDateComponents alloc] init];
    NSDate *now = [NSDate date];
    [offsetComponents setDay:35];
    __block NSDate *from = [[NSCalendar currentCalendar] dateByAddingComponents:offsetComponents toDate:now options:0];
    [offsetComponents setDay:7];
    __block NSDate *to = [[NSCalendar currentCalendar] dateByAddingComponents:offsetComponents toDate:from options:0];
    // generate a random customerReference
    NSString *letters = @"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    NSMutableString *randomString = [NSMutableString stringWithCapacity:16];
    for (int i=0; i<16; i++) {
        [randomString appendFormat: @"%C", [letters characterAtIndex: arc4random_uniform((unsigned int)[letters length])]];
    }
    __block NSString *testCustomerReference = randomString;
    
    /*************************************************************************
     * Fetch activities for destination London.
     *************************************************************************/
    
    __block TABActivity *activity;
    [_client fetchActivitiesForDestination:@"LON" fromDate:from toDate:to pagination:nil completion:^(TABActivityListResponse *activityListResponse) {
        if (activityListResponse.errors.count) {
            // do something about it
            return;
        }
        NSLog(@"Operation id for activity list: %@", activityListResponse.operationId);
        self.view.backgroundColor = [UIColor greenColor];
        // get first activity
        activity = activityListResponse.activities[0];
        
        // Now fetch activity details
        // create paxes (just one adult)
        __block NSArray *paxes = @[[[TABPaxRequest alloc] initWithAge:@30]];
        
        /*************************************************************************
         * Get details for the selected activity
         *************************************************************************/
        
        __block TABOperationDate *operationDate;
        [_client fetchDetailsForActivityCode:activity.code inDestination:@"LON" fromDate:from toDate:to paxes:paxes completion:^(TABActivityDetailResponse *activityDetailResponse) {
            if (activityDetailResponse.errors.count) {
                // do something about it
                return;
            }
            NSLog(@"Operation id for activity detail: %@", activityDetailResponse.operationId);
            self.view.backgroundColor = [UIColor yellowColor];
            // the user selects one modality and then one operation date
            operationDate = [(TABModality *)activityDetailResponse.activity.modalities[0] operationDates][0];
            
            /*************************************************************************
             * Book it for the first operation date
             *************************************************************************/
            
            // create a holder of the booking
            __block TABHolder *holder = [[TABHolder alloc] initWithName:@"firstname" lastName:@"lastname"];
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
            [_client confirmBookingForServices:@[serviceRequest] holder:holder customerReference:testCustomerReference cardInformation:cardInformation completion:^(TABBookingConfirmResponse *bookingConfirmResponse) {
                if (bookingConfirmResponse.errors.count) {
                    // do something about it
                    return;
                }
                NSLog(@"Operation id for booking confirm: %@", bookingConfirmResponse.operationId);
                self.view.backgroundColor = [UIColor purpleColor];
                bookingDetail = bookingConfirmResponse.booking;
                
                /*************************************************************************
                 * Check booking details using TAB's reference
                 *************************************************************************/
                [_client fetchBookingDetailsForReference:bookingDetail.reference completion:^(TABBookingDetailResponse *bookingDetailResponse) {
                    if (bookingDetailResponse.errors.count) {
                        // do something about it
                        return;
                    }
                    NSLog(@"Operation id for booking detail: %@", bookingDetailResponse.operationId);
                    self.view.backgroundColor = [UIColor brownColor];
                    
                    /*************************************************************************
                     * Cancel the booking using TAB's reference
                     *************************************************************************/
                    [_client cancelBookingForReference:bookingDetail.reference completion:^(TABBookingCancelResponse *bookingCancelResponse) {
                        if (bookingCancelResponse.errors.count) {
                            // do something about it
                            return;
                        }
                        NSLog(@"Operation id for booking cancel: %@", bookingCancelResponse.operationId);
                        self.view.backgroundColor = [UIColor darkGrayColor];
                        
                        /*************************************************************************
                         * Get the booking details using the customerReference
                         *************************************************************************/
                        __block TABServiceDetail *serviceDetail = bookingDetail.services[0];
                        [_client fetchBookingDetailsForCustomerReference:testCustomerReference holder:holder fromDate:serviceDetail.from toDate:serviceDetail.to completion:^(TABBookingDetailResponse *bookingDetailCustomerReferenceResponse) {
                            if (bookingDetailCustomerReferenceResponse.errors.count) {
                                // do something about it
                                return;
                            }
                            NSLog(@"Operation id for ˇ: %@", bookingDetailCustomerReferenceResponse.operationId);
                            self.view.backgroundColor = [UIColor blackColor];
                        }];
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
