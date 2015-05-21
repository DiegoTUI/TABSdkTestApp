//
//  TABCardInformation.h
//  TabSdk-ios
//
//  Created by Diego Lafuente Garcia on 22/04/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Model of a credit card to perform a payment. This object is passed as a parameter in the booking confirmation operation.
 */
@interface TABCardInformation : MTLModel<MTLJSONSerializing>

/**
 Name and surname of the card holder
 */
@property (strong, nonatomic, readonly) NSString *cardHolder;

/**
 E-mail of the card holder
 */
@property (strong, nonatomic, readonly) NSString *email;

/**
 Phone number of the card holder
 */
@property (strong, nonatomic, readonly) NSString *phone;

/**
 Credit card number
 */
@property (strong, nonatomic, readonly) NSString *cardNumber;

/**
 Credit card type
 */
@property (nonatomic) TABCreditCardType cardType;

/**
 CVC number
 */
@property (strong, nonatomic, readonly) NSString *cvc;

/**
 Expiration month. 1 is January, 12 is December.
 */
@property (strong, nonatomic, readonly) NSNumber *expirationMonth;

/**
 Expiration year using 2 digits (as in 17 for 1017).
 */
@property (strong, nonatomic, readonly) NSNumber *expirationYear;

/**
 @methodName initWithCardHolder:cardNumber:cardType:cvc:expirationMonth:expirationYear:
 @abstract Initializes a credit card.
 @discussion This method initializes a credit card with the needed info. It returns nil if the parameters are invalid.
 
 @param cardHolder [required] The card holder's name and surname.
 @param email [required] The card holder's email.
 @param phone [required] The card holder's phone number.
 @param cardNumber [required] The card number.
 @param cardType [required] The card type.
 @param cvc [required] The cvc number.
 @param expirationMonth [required] The expiration month. 1 is January, 12 is December.
 @param expirationYear [required] The expiration year using 4 digits (as in 2017).
 
 @return An instance of the initialized service request or nil if invalid parameters are provided.
 */
- (id)initWithCardHolder:(NSString *)cardHolder
                   email:(NSString *)email
                   phone:(NSString *)phone
              cardNumber:(NSString *)cardNumber
                cardType:(TABCreditCardType)cardType
                     cvc:(NSString *)cvc
         expirationMonth:(NSNumber *)expirationMonth
          expirationYear:(NSNumber *)expirationYear;

@end
