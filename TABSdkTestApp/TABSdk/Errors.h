//
//  Errors.h
//  TabSdk-ios
//
//  Created by Diego Lafuente on 24/02/15.
//  Copyright (c) 2015 Transfers and Activities Bank. All rights reserved.
//

#ifndef TabSdk_ios_Errors_h
#define TabSdk_ios_Errors_h

// API error codes
// Generic
#define TAB_SKD_ERROR_CODE_GENERIC                                  1001
#define TAB_SDK_ERROR_CODE_CONNECTION_TIMED_OUT                     1002
#define TAB_SDK_ERROR_CODE_NO_CONNECTION                            1003
// Services
#define TAB_SKD_ERROR_CODE_SERVICE_GENERIC                          2001
#define TAB_SKD_ERROR_CODE_INVALID_SERVICE                          2002
#define TAB_SKD_ERROR_CODE_INVALID_DESTINATION                      2003
#define TAB_SKD_ERROR_CODE_INVALID_PARAMETER                        2004
#define TAB_SDK_ERROR_CODE_INVALID_ACTIVITY_CODE                    2005
#define TAB_SDK_ERROR_CODE_INVALID_CREDENTIALS                      2006
#define TAB_SDK_ERROR_CODE_BOOKING_NOT_FOUND                        2007
#define TAB_SDK_ERROR_CODE_INVALID_FILE_NUMBER                      2008
#define TAB_SDK_ERROR_CODE_INVALID_API_KEY                          2009
#define TAB_SDK_ERROR_CODE_EXPIRED_AVAIL_TOKEN                      2010
#define TAB_SDK_ERROR_CODE_INVALID_TOKEN                            2011
// Server
#define TAB_SDK_ERROR_CODE_SERVER_GENERIC                           3001
#define TAB_SDK_ERROR_CODE_DATABASE                                 3002
#define TAB_SDK_ERROR_CODE_AJAX                                     3003
#define TAB_SDK_ERROR_CODE_FTP                                      3004
#define TAB_SDK_ERROR_CODE_XML                                      3005
#define TAB_SDK_ERROR_CODE_FILE                                     3006
#define TAB_SDK_ERROR_CODE_ATLAS                                    3007
#define TAB_SDK_ERROR_CODE_ATLAS_TIMED_OUT                          3008

// API error domains
#define TAB_SDK_ERROR_DOMAIN_GENERIC                @"TAB_GENERIC_ERROR_DOMAIN"

// API error map
#define TAB_API_ERROR_MAP @{ \
    @"ERR-000" : @(TAB_SKD_ERROR_CODE_GENERIC), \
    @"ERR-001" : @(TAB_SKD_ERROR_CODE_INVALID_DESTINATION), \
    @"ERR-002" : @(TAB_SKD_ERROR_CODE_INVALID_PARAMETER), \
    @"ERR-003" : @(TAB_SDK_ERROR_CODE_DATABASE), \
    @"ERR-004" : @(TAB_SDK_ERROR_CODE_DATABASE), \
    @"ERR-005" : @(TAB_SDK_ERROR_CODE_DATABASE), \
    @"ERR-006" : @(TAB_SDK_ERROR_CODE_DATABASE), \
    @"ERR-007" : @(TAB_SDK_ERROR_CODE_DATABASE), \
    @"ERR-008" : @(TAB_SDK_ERROR_CODE_DATABASE), \
    @"ERR-009" : @(TAB_SDK_ERROR_CODE_INVALID_ACTIVITY_CODE), \
    @"ERR-010" : @(TAB_SDK_ERROR_CODE_AJAX), \
    @"ERR-011" : @(TAB_SDK_ERROR_CODE_AJAX), \
    @"ERR-012" : @(TAB_SDK_ERROR_CODE_AJAX), \
    @"ERR-013" : @(TAB_SDK_ERROR_CODE_FTP), \
    @"ERR-014" : @(TAB_SDK_ERROR_CODE_FTP), \
    @"ERR-015" : @(TAB_SDK_ERROR_CODE_FTP), \
    @"ERR-016" : @(TAB_SDK_ERROR_CODE_XML), \
    @"ERR-017" : @(TAB_SDK_ERROR_CODE_XML), \
    @"ERR-018" : @(TAB_SDK_ERROR_CODE_FILE), \
    @"ERR-019" : @(TAB_SDK_ERROR_CODE_ATLAS), \
    @"ERR-020" : @(TAB_SKD_ERROR_CODE_SERVICE_GENERIC), \
    @"ERR-021" : @(TAB_SKD_ERROR_CODE_SERVICE_GENERIC), \
    @"ERR-022" : @(TAB_SKD_ERROR_CODE_SERVICE_GENERIC), \
    @"ERR-023" : @(TAB_SDK_ERROR_CODE_DATABASE), \
    @"ERR-024" : @(TAB_SDK_ERROR_CODE_INVALID_CREDENTIALS), \
    @"ERR-025" : @(TAB_SDK_ERROR_CODE_BOOKING_NOT_FOUND), \
    @"ERR-026" : @(TAB_SDK_ERROR_CODE_INVALID_FILE_NUMBER), \
    @"ERR-027" : @(TAB_SKD_ERROR_CODE_SERVICE_GENERIC), \
    @"ERR-028" : @(TAB_SDK_ERROR_CODE_INVALID_API_KEY), \
    @"ERR-029" : @(TAB_SKD_ERROR_CODE_INVALID_SERVICE), \
    @"ERR-030" : @(TAB_SDK_ERROR_CODE_ATLAS_TIMED_OUT), \
    @"ERR-031" : @(TAB_SKD_ERROR_CODE_SERVICE_GENERIC), \
    @"ERR-032" : @(TAB_SDK_ERROR_CODE_EXPIRED_AVAIL_TOKEN), \
    @"ERR-033" : @(TAB_SKD_ERROR_CODE_SERVICE_GENERIC), \
    @"ERR-034" : @(TAB_SKD_ERROR_CODE_SERVICE_GENERIC), \
    @"ERR-035" : @(TAB_SKD_ERROR_CODE_SERVICE_GENERIC), \
    @"ERR-036" : @(TAB_SDK_ERROR_CODE_INVALID_TOKEN), \
}

#endif
