//
//  PBResponses.h
//  pblib
//
//  Created by haxpor on 2/6/15.
//  Copyright (c) 2015 Maethee Chongchitnant. All rights reserved.
//

#ifndef pblib_PBResponses_h
#define pblib_PBResponses_h

#import <Foundation/Foundation.h>

///--------------------------------------
/// Type of Response
///--------------------------------------
typedef enum
{
    responseType_normal,
    responseType_auth,
    responseType_playerPublic,
    responseType_player,
    responseType_playerList,
    responseType_point
}pbResponseType;

///--------------------------------------
/// Auth
///--------------------------------------
@interface PBAuth_Response : NSObject

@property (strong, nonatomic) NSString *token;
@property (strong, nonatomic) NSDate *dateExpire;

/**
 Parse json-response data into NSDictionary.
 */
+(PBAuth_Response*)parseFromDictionary:(const NSDictionary*) jsonResponse;

@end
///--------------------------------------
/// Player Info - Public Data Only
///--------------------------------------
@interface PBPlayerPublic_Response : NSObject

@property (strong, nonatomic) NSString *image;
@property (strong, nonatomic) NSString *userName;
@property (nonatomic) NSUInteger exp;
@property (nonatomic) NSUInteger level;
@property (strong, nonatomic) NSString *firstName;
@property (strong, nonatomic) NSString *lastName;
@property (nonatomic) NSUInteger gender;
@property (strong, nonatomic) NSDate *registered;
@property (strong, nonatomic) NSDate *lastLogin;
@property (strong, nonatomic) NSDate *lastLogout;
@property (strong, nonatomic) NSString* clPlayerId;

/**
 Parse json-response data into NSDictionary.
 */
+(PBPlayerPublic_Response*)parseFromDictionary:(const NSDictionary*) jsonResponse;

@end

///--------------------------------------
/// Player Info - Included Private Data
///--------------------------------------
@interface PBPlayer_Response : NSObject

@property (strong, nonatomic) NSString *image;
@property (strong, nonatomic) NSString *email;
@property (strong, nonatomic) NSString *userName;
@property (nonatomic) NSUInteger exp;
@property (nonatomic) NSUInteger level;
@property (strong, nonatomic) NSString *phoneNumber;
@property (strong, nonatomic) NSString *firstName;
@property (strong, nonatomic) NSString *lastName;
@property (nonatomic) NSUInteger gender;
@property (strong, nonatomic) NSDate *registered;
@property (strong, nonatomic) NSDate *lastLogin;
@property (strong, nonatomic) NSDate *lastLogout;
@property (strong, nonatomic) NSString* clPlayerId;

/**
 Parse json-response data into NSDictionary.
 */
+(PBPlayer_Response*)parseFromDictionary:(const NSDictionary*) jsonResponse;

@end

///--------------------------------------
/// PlayerList
///--------------------------------------
@interface PBPlayerList_Response : NSObject

@property (strong, nonatomic) NSArray *players;

/**
 Parse json-response data into NSDictionary.
 */
+(PBPlayerList_Response*)parseFromDictionary:(const NSDictionary*) jsonResponse;

@end

///--------------------------------------
/// PlayerDetailPublic
///--------------------------------------
@interface PBPlayerDetailPublic_Response : NSObject

@property (strong, nonatomic) PBPlayerPublic_Response *playerPublic;
@property (nonatomic) float percentOfLevel;
@property (strong, nonatomic) NSString *levelTitle;
@property (strong, nonatomic) NSString *levelImage;

/**
 Parse json-response data into NSDictionary.
 */
+(PBPlayerDetailPublic_Response*)parseFromDictionary:(const NSDictionary*) jsonResponse;

@end

///--------------------------------------
/// Point - No Resposne
///--------------------------------------
@interface PBPoint : NSObject

@property (strong, nonatomic) NSString *rewardId;
@property (strong, nonatomic) NSString *rewardName;
@property (nonatomic) NSUInteger value;

@end

///--------------------------------------
/// Point
///--------------------------------------
@interface PBPoint_Response : NSObject

@property (strong, nonatomic) NSArray* points;

/**
 Parse json-response data into NSDictionary.
 */
+(PBPoint_Response*)parseFromDictionary:(const NSDictionary*) jsonResponse;

@end

#endif
