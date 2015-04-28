//
//  ViewController.m
//  TABSdkTestApp
//
//  Created by Diego Lafuente Garcia on 01/04/15.
//  Copyright (c) 2015 Diego Lafuente Garcia. All rights reserved.
//

#import <Mantle/Mantle.h>
#import "ViewController.h"
#import "Constants.h"
#import "TABSdk.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // A simple booking cycle for the TABSDK
    
    // Init the client
    TABActivitiesClient *client = [[TABActivitiesClient alloc] initWithAPIKey:@"YOUR-API-KEY" andAPISecret:@"YOUR-API-SECRET"];
    
    // Set the language for the client (defaults to ENG)
    client.language = @"ENG";
    
    // fetch activities for destination London. The rest of the parameters are optional
    __block TABActivity *activity;
    NSLog(@"before fetchActivitiesForDestination");
    [client fetchActivitiesForDestination:@"LON" fromDate:nil toDate:nil pagination:nil completion:^(NSError *error, TABActivityListResponse *response) {
        if (error) {
            // do something about it
            return;
        }
        NSLog(@"Operation id for activity list: %@", response.operationId);
        // get first activity
        activity = response.activities[0];
    }];
    NSLog(@"after fetchActivitiesForDestination");
    
    // create paxes (just one adult)
    TABPax *pax = [[TABPax alloc] initWithAge:@30];
    
    // get details for selected activity
    __block TABOperationDate *operationDate;
    [client fetchDetailsForActivityCode:activity.code inDestination:@"LON" fromDate:nil toDate:nil paxes:@[pax] completion:^(NSError *error, TABActivityDetailResponse *response) {
        if (error) {
            // do something about it
            return;
        }
        NSLog(@"Operation id for activity detail: %@", response.operationId);
        // the user selects one modality and then one operation date
        operationDate = [(TABModality *)response.activity.modalities[0] operationDates][0];
    }];
    
    // create a holder of the booking
    TABHolder *holder = [[TABHolder alloc] initWithName:@"firstname" lastName:@"lastname" phone:@"phonenr" andEmail:@"email@test"];
    
    // create service request
    TABServiceRequest *serviceRequest = [[TABServiceRequest alloc] initWithPurchaseableServiceId:operationDate.purchaseableServiceId paxes:nil andAnswers:nil];
    
    // preconfirm the booking
    __block NSString *bookingConfirmId;
    __block TABBookingDetail *bookingDetail;
    [client preconfirmBookingForServices:@[serviceRequest] holder:holder customerReference:nil completion:^(NSError *error, TABBookingPreconfirmResponse *response) {
        if (error) {
            // do something about it
            return;
        }
        NSLog(@"Operation id for booking preconfirm: %@", response.operationId);
        
        bookingConfirmId = response.bookingConfirmId;
        bookingDetail = response.booking;
    }];
    
    // PERFORM PAYMENT!!!
    
    // confirm booking
    [client confirmBooking:bookingConfirmId completion:^(NSError *error, TABBookingConfirmResponse *response) {
        if (error) {
            // do something about it
            return;
        }
        NSLog(@"Operation id for booking confirm: %@", response.operationId);
        // Show voucher...
        // update booking detail
        bookingDetail = response.booking;
    }];
    
    // cancel booking
    [client cancelBookingForReference:bookingDetail.reference completion:^(NSError *error, TABBookingCancelResponse *response) {
        if (error) {
            // do something about it
            return;
        }
        NSLog(@"Operation id for booking cancel: %@", response.operationId);
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
