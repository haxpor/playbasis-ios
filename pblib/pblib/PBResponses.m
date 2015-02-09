//
//  PBResponses.m
//  pblib
//
//  Created by haxpor on 2/6/15.
//  Copyright (c) 2015 Maethee Chongchitnant. All rights reserved.
//

#import "PBResponses.h"
#import "JSONKit.h"

///--------------------------------------
/// Base - Response
/// Additional interface for private methods
///--------------------------------------
@interface PBBase_Response ()

/**
 Do not use this property.
 It's used internally for convenience in parsing json-response.
 */
@property (strong, nonatomic) NSDictionary *parseLevelJsonResponse;

@end

@implementation PBBase_Response

@synthesize parseLevelJsonResponse;

@end

///--------------------------------------
/// Auth
///--------------------------------------
@implementation PBAuth_Response

@synthesize token;
@synthesize dateExpire;

-(NSString *)description
{
    NSString *descriptionString = [NSString stringWithFormat:@"Auth : {\r\ttoken : %@\r\tdate_expire : %@\r\t}", self.token, self.dateExpire];
    return descriptionString;
}

+(PBAuth_Response*)parseFromDictionary:(const NSDictionary *)jsonResponse startFromFinalLevel:(BOOL)startFromFinalLevel
{
    if(jsonResponse == nil)
        return nil;
    
    // create a result response
    PBAuth_Response *c = [[PBAuth_Response alloc] init];
    
    if(startFromFinalLevel)
    {
        c.parseLevelJsonResponse = [jsonResponse copy];
    }
    else
    {
        // get 'response'
        NSDictionary *response = [jsonResponse objectForKey:@"response"];
        NSAssert(response != nil, @"response must not be nil");
        
        c.parseLevelJsonResponse = response;
    }

    // set token
    c.token = [c.parseLevelJsonResponse objectForKey:@"token"];
    
    // create a date formatter to parse date-timestamp
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setTimeZone:[NSTimeZone timeZoneWithName:@"GMT"]];
    [dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ssZZZ"];
    
    c.dateExpire = [dateFormatter dateFromString:[c.parseLevelJsonResponse objectForKey:@"date_expire"]];
    
    return c;
}

@end

///--------------------------------------
/// PlayerPublic
///--------------------------------------
@implementation PBPlayerPublic_Response

@synthesize image;
@synthesize userName;
@synthesize exp;
@synthesize level;
@synthesize firstName;
@synthesize lastName;
@synthesize gender;
@synthesize registered;
@synthesize lastLogin;
@synthesize lastLogout;
@synthesize clPlayerId;

-(NSString *)description
{
    NSString *descriptionString = [NSString stringWithFormat:@"Player's Public Information : {\r\timage : %@\r\tuserName : %@\r\texp : %lu\r\tlevel : %lu\r\tfirst_name : %@\r\tlast_name : %@\r\tgender : %lu\r\tregistered : %@\r\tlast_login : %@\r\tlast_logout : %@\r\tcl_player_id : %@\r\t}", self.image, self.userName, (unsigned long)self.exp, (unsigned long)self.level, self.firstName, self.lastName, (unsigned long)self.gender, self.registered, self.lastLogin, self.lastLogout, self.clPlayerId];
    return descriptionString;
}

+(PBPlayerPublic_Response*)parseFromDictionary:(const NSDictionary *)jsonResponse startFromFinalLevel:(BOOL)startFromFinalLevel
{
    if(jsonResponse == nil)
        return nil;
    
    // create a result response
    PBPlayerPublic_Response *c = [[PBPlayerPublic_Response alloc] init];
    
    if(startFromFinalLevel)
    {
        c.parseLevelJsonResponse = [jsonResponse copy];
    }
    else
    {
        // get 'response'
        NSDictionary *response = [jsonResponse objectForKey:@"response"];
        NSAssert(response != nil, @"response must not be nil");
        
        // get 'player'
        NSDictionary *player = [response objectForKey:@"player"];
        NSAssert(response != nil, @"player must not be nil");
        
        c.parseLevelJsonResponse = player;
    }
    
    c.image = [c.parseLevelJsonResponse objectForKey:@"image"];
    c.userName = [c.parseLevelJsonResponse objectForKey:@"username"];
    c.exp = [[c.parseLevelJsonResponse objectForKey:@"exp"] unsignedIntegerValue];
    c.level = [[c.parseLevelJsonResponse objectForKey:@"level"] unsignedIntegerValue];
    c.firstName = [c.parseLevelJsonResponse objectForKey:@"first_name"];
    c.lastName = [c.parseLevelJsonResponse objectForKey:@"last_name"];
    c.gender = [[c.parseLevelJsonResponse objectForKey:@"gender"] unsignedIntegerValue];
    
    // create a date formatter to parse date-timestamp
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setTimeZone:[NSTimeZone timeZoneWithName:@"GMT"]];
    [dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ssZZZ"];
    
    c.registered = [dateFormatter dateFromString:[c.parseLevelJsonResponse objectForKey:@"registered"]];
    c.lastLogin = [dateFormatter dateFromString:[c.parseLevelJsonResponse objectForKey:@"last_login"]];
    c.lastLogout = [dateFormatter dateFromString:[c.parseLevelJsonResponse objectForKey:@"last_logout"]];
    
    c.clPlayerId = [c.parseLevelJsonResponse objectForKey:@"cl_player_id"];
    
    return c;
}

@end

///--------------------------------------
/// Player
///--------------------------------------
@implementation PBPlayer_Response

@synthesize playerPublic;
@synthesize email;
@synthesize phoneNumber;

-(NSString *)description
{
    NSString *descriptionString = [NSString stringWithFormat:@"Player Information : {\r\timage : %@\r\temail : %@\r\tuserName : %@\r\texp : %u\r\tlevel : %u\r\tphone_number : %@\r\tfirst_name : %@\r\tlast_name : %@\r\tgender : %u\r\tregistered : %@\r\tlast_login : %@\r\tlast_logout : %@\r\tcl_player_id : %@\r\t}", self.playerPublic.image, self.email, self.playerPublic.userName, (unsigned int)self.playerPublic.exp, (unsigned int)self.playerPublic.level, self.phoneNumber, self.playerPublic.firstName, self.playerPublic.lastName, (unsigned int)self.playerPublic.gender, self.playerPublic.registered, self.playerPublic.lastLogin, self.playerPublic.lastLogout, self.playerPublic.clPlayerId];
    return descriptionString;
}

+(PBPlayer_Response*)parseFromDictionary:(const NSDictionary *)jsonResponse startFromFinalLevel:(BOOL)startFromFinalLevel
{
    if(jsonResponse == nil)
        return nil;
    
    // create a result response
    PBPlayer_Response *c = [[PBPlayer_Response alloc] init];
    
    // if it starts from the final level, then copy the json-response right away
    if(startFromFinalLevel)
    {
        // set the parsing level
        c.parseLevelJsonResponse = [jsonResponse copy];
    }
    else
    {
        // get 'response'
        NSDictionary *response = [jsonResponse objectForKey:@"response"];
        NSAssert(response != nil, @"response must not be nil");
        
        // get 'player'
        NSDictionary *player = [response objectForKey:@"player"];
        NSAssert(response != nil, @"player must not be nil");
        
        // set the parsing level
        c.parseLevelJsonResponse = player;
    }
    
    c.email = [c.parseLevelJsonResponse objectForKey:@"email"];
    c.phoneNumber = [c.parseLevelJsonResponse objectForKey:@"phone_number"];
    
    // parse player's public info
    PBPlayerPublic_Response *playerPublic = [PBPlayerPublic_Response parseFromDictionary:c.parseLevelJsonResponse startFromFinalLevel:YES];
    // set player's public info to this response
    c.playerPublic = playerPublic;
    
    return c;
}

@end

///--------------------------------------
/// PlayerList
///--------------------------------------
@implementation PBPlayerList_Response

@synthesize players;

-(NSString *)description
{
    // create string to hold all players line-by-line
    NSMutableString *lines = [NSMutableString stringWithString:@"PlayerList : {"];
    
    for(PBPlayer_Response *player in self.players)
    {
        // get description line from each player
        NSString *playerLine = [player description];
        // append \r
        NSString *playerLineWithCR = [NSString stringWithFormat:@"\r\t%@\r", playerLine];
        
        // append to result 'lines'
        [lines appendString:playerLineWithCR];
    }
    
    // end with brace
    [lines appendString:@"}"];
    
    return [NSString stringWithString:lines];
}

+(PBPlayerList_Response*)parseFromDictionary:(const NSDictionary *)jsonResponse startFromFinalLevel:(BOOL)startFromFinalLevel
{
    if(jsonResponse == nil)
        return nil;
    
    // create a result playerList object
    PBPlayerList_Response *playerList = [[PBPlayerList_Response alloc] init];
    
    if(startFromFinalLevel)
    {
        playerList.parseLevelJsonResponse = [jsonResponse copy];
    }
    else
    {
        // get 'response'
        NSDictionary *response = [jsonResponse objectForKey:@"response"];
        NSAssert(response != nil, @"response must not be nil");
        
        // get array of 'player'
        NSDictionary *players = [response objectForKey:@"player"];
        NSAssert(response != nil, @"player must not be nil");
        
        playerList.parseLevelJsonResponse = players;
    }
    
    // convert the final level into array
    NSArray *players = (NSArray*)playerList.parseLevelJsonResponse;
    
    // create an empty array to add each player into it
    NSMutableArray *playerArray = [NSMutableArray array];
    
    // iterate through all the players, add add into result array
    for(NSDictionary *player in players)
    {
        // create a player object
        PBPlayer_Response *c = [PBPlayer_Response parseFromDictionary:player startFromFinalLevel:YES];
        
        // add to temporary array
        [playerArray addObject:c];
    }

    // add a player into an array
    playerList.players = [NSArray arrayWithArray:playerArray];
    
    return playerList;
}

@end

///--------------------------------------
/// Point - No Resposne
///--------------------------------------
@implementation PBPoint

@synthesize rewardId;
@synthesize rewardName;
@synthesize value;

-(NSString *)description
{
    NSString *descriptionString = [NSString stringWithFormat:@"Point : {\r\treward_id : %@\r\treward_name : %@\r\tvalue : %lu\r\t}", self.rewardId, self.rewardName, (unsigned long)self.value];
    
    return descriptionString;
}

+(PBPoint*)parseFromDictionary:(const NSDictionary *)jsonResponse startFromFinalLevel:(BOOL)startFromFinalLevel
{
    if(jsonResponse == nil)
        return nil;
    
    // create a result object
    PBPoint *c = [[PBPoint alloc] init];
    
    // ignore the 'startFromFinalLevel' flag
    // its appearance won't appear anywhere as a single entity to parse
    c.parseLevelJsonResponse = [jsonResponse copy];
    
    c.rewardId = [c.parseLevelJsonResponse objectForKey:@"reward_id"];
    c.value = [[c.parseLevelJsonResponse objectForKey:@"value"] unsignedIntegerValue];
    c.rewardName = [c.parseLevelJsonResponse objectForKey:@"reward_name"];
    
    return c;
}

@end

///--------------------------------------
/// Point
///--------------------------------------
@implementation PBPoint_Response

@synthesize point;

-(NSString *)description
{
    // create string to hold all players line-by-line
    NSMutableString *lines = [NSMutableString stringWithString:@"Point : {"];
    
    for(PBPoint *p in self.point)
    {
        // get description line from each point
        NSString *pointLine = [p description];
        // append \r
        NSString *pointLineWithCR = [NSString stringWithFormat:@"\r\t%@\r", pointLine];
        
        // append to result 'lines'
        [lines appendString:pointLineWithCR];
    }
    
    // end with brace
    [lines appendString:@"}"];
    
    return [NSString stringWithString:lines];
}

+(PBPoint_Response*)parseFromDictionary:(const NSDictionary *)jsonResponse startFromFinalLevel:(BOOL)startFromFinalLevel
{
    if(jsonResponse == nil)
        return nil;
    
    // create a result response
    PBPoint_Response *c = [[PBPoint_Response alloc] init];
    
    if(startFromFinalLevel)
    {
        c.parseLevelJsonResponse = [jsonResponse copy];
    }
    else
    {
        // get 'response'
        NSDictionary *response = [jsonResponse objectForKey:@"response"];
        NSAssert(response != nil, @"response must not be nil");
        
        // get 'point'
        NSDictionary *point = [response objectForKey:@"point"];
        NSAssert(point != nil, @"point must not be nil");
        
        c.parseLevelJsonResponse = point;
    }
    
    // crate a temporary array to hold all points
    NSMutableArray *tempPoints = [NSMutableArray array];
    
    // convert 'point' json to array
    NSArray *points = (NSArray*)c.parseLevelJsonResponse;
    for(NSDictionary *point in points)
    {
        // create a point object
        PBPoint *pObj = [PBPoint parseFromDictionary:point startFromFinalLevel:YES];
        
        // add it into temp array
        [tempPoints addObject:pObj];
    }
    
    // set to NSArray
    c.point = [NSArray arrayWithArray:tempPoints];
    
    return c;
}

@end

///--------------------------------------
/// Points
///--------------------------------------
@implementation PBPoints_Response

@synthesize points;

-(NSString *)description
{
    // create string to hold all players line-by-line
    NSMutableString *lines = [NSMutableString stringWithString:@"Points : {"];
    
    for(PBPoint *point in self.points)
    {
        // get description line from each point
        NSString *pointLine = [point description];
        // append \r
        NSString *pointLineWithCR = [NSString stringWithFormat:@"\r\t%@\r", pointLine];
        
        // append to result 'lines'
        [lines appendString:pointLineWithCR];
    }
    
    // end with brace
    [lines appendString:@"}"];
    
    return [NSString stringWithString:lines];
}

+(PBPoints_Response*)parseFromDictionary:(const NSDictionary *)jsonResponse startFromFinalLevel:(BOOL)startFromFinalLevel
{
    if(jsonResponse == nil)
        return nil;
    
    // create a result response
    PBPoints_Response *c = [[PBPoints_Response alloc] init];
    
    if(startFromFinalLevel)
    {
        c.parseLevelJsonResponse = [jsonResponse copy];
    }
    else
    {
        // get 'response'
        NSDictionary *response = [jsonResponse objectForKey:@"response"];
        NSAssert(response != nil, @"response must not be nil");
        
        // get 'points'
        NSDictionary *points = [response objectForKey:@"points"];
        NSAssert(points != nil, @"points must not be nil");
        
        c.parseLevelJsonResponse = points;
    }
    
    // crate a temporary array to hold all points
    NSMutableArray *tempPoints = [NSMutableArray array];
    
    // convert 'points' to array
    NSArray *points = (NSArray*)c.parseLevelJsonResponse;
    for(NSDictionary *point in points)
    {
        // create a point object
        PBPoint *pObj = [PBPoint parseFromDictionary:point startFromFinalLevel:YES];
        
        // add it into temp array
        [tempPoints addObject:pObj];
    }
    
    // set to NSArray
    c.points = [NSArray arrayWithArray:tempPoints];
    
    return c;
}

@end

///--------------------------------------
/// Badge
///--------------------------------------
@implementation PBBadge_Response

@synthesize badgeId;
@synthesize image;
@synthesize sortOrder;
@synthesize name;
@synthesize description_;
@synthesize hint;
@synthesize sponsor;
@synthesize claim;
@synthesize redeem;

-(NSString *)description
{
    NSString *descriptionString = [NSString stringWithFormat:@"Badge : {\r\tbadge_id : %@\r\timage : %@\r\tsort_order : %lu\r\tname : %@\r\tdescription : %@\r\thint : %@\r\tsponsor : %@\r\tclaim : %@\r\tredeem : %@\r\t}", self.badgeId, self.image, self.sortOrder, self.name, self.description_, self.hint, self.sponsor ? @"YES" : @"NO", self.claim ? @"YES" : @"NO", self.redeem ? @"YES" : @"NO"];
    
    return descriptionString;
}

+(PBBadge_Response *)parseFromDictionary:(const NSDictionary *)jsonResponse startFromFinalLevel:(BOOL)startFromFinalLevel
{
    if(jsonResponse == nil)
        return nil;
    
    // create a result response
    PBBadge_Response *c = [[PBBadge_Response alloc] init];
    
    if(startFromFinalLevel)
    {
        c.parseLevelJsonResponse = [jsonResponse copy];
    }
    else
    {
        // get 'response'
        NSDictionary *response = [jsonResponse objectForKey:@"response"];
        NSAssert(response != nil, @"response must not be nil");
        
        // get 'badge'
        NSDictionary *badge = [response objectForKey:@"badge"];
        NSAssert(badge != nil, @"badge must not be nil");
        
        c.parseLevelJsonResponse = badge;
    }
    
    c.badgeId = [c.parseLevelJsonResponse objectForKey:@"badge_id"];
    c.image = [c.parseLevelJsonResponse objectForKey:@"image"];
    c.sortOrder = [[c.parseLevelJsonResponse objectForKey:@"sort_order"] unsignedIntegerValue];
    c.name = [c.parseLevelJsonResponse objectForKey:@"name"];
    c.description_ = [c.parseLevelJsonResponse objectForKey:@"description"];
    c.hint = [c.parseLevelJsonResponse objectForKey:@"hint"];
    c.sponsor = [[c.parseLevelJsonResponse objectForKey:@"sponsor"] boolValue];
    c.claim = [[c.parseLevelJsonResponse objectForKey:@"claim"] boolValue];
    c.redeem = [[c.parseLevelJsonResponse objectForKey:@"redeem"] boolValue];
    
    return c;
}

@end

///--------------------------------------
/// Badges
///--------------------------------------
@implementation PBBadges_Response

@synthesize badges;

-(NSString *)description
{
    // create string to hold all badges line-by-line
    NSMutableString *lines = [NSMutableString stringWithString:@"Badges : {"];
    
    for(PBBadge_Response *badge in self.badges)
    {
        // get description line from each player-badge
        NSString *badgeLine = [badge description];
        // append \r
        NSString *badgeLineWithCR = [NSString stringWithFormat:@"\r\t%@\r", badgeLine];
        
        // append to result 'lines'
        [lines appendString:badgeLineWithCR];
    }
    
    // end with brace
    [lines appendString:@"}"];
    
    return [NSString stringWithString:lines];
}

+(PBBadges_Response *)parseFromDictionary:(const NSDictionary *)jsonResponse startFromFinalLevel:(BOOL)startFromFinalLevel
{
    if(jsonResponse == nil)
        return nil;
    
    // create result response
    PBBadges_Response *c = [[PBBadges_Response alloc] init];
    
    if(startFromFinalLevel)
    {
        c.parseLevelJsonResponse = [jsonResponse copy];
    }
    else
    {
        // get 'response'
        NSDictionary *response = [jsonResponse objectForKey:@"response"];
        NSAssert(response != nil, @"response must not be nil");
        
        // get 'badges'
        NSDictionary *badges = [response objectForKey:@"badges"];
        NSAssert(badges != nil, @"badges must not be nil");
        
        c.parseLevelJsonResponse = badges;
    }
    
    // convert 'badges' into array
    NSArray *badgeArray = (NSArray*)c.parseLevelJsonResponse;
    
    // temporary array to hold badges
    NSMutableArray *tempBadges = [NSMutableArray array];
    
    for(NSDictionary *badge in badgeArray)
    {
        // get badge
        PBBadge_Response *b = [PBBadge_Response parseFromDictionary:badge startFromFinalLevel:YES];
        
        // add to temp array
        [tempBadges addObject:b];
    }
    
    // set back to itself
    c.badges = [NSArray arrayWithArray:tempBadges];
    
    return c;
}

@end

///--------------------------------------
/// PBPlayerBadge - No Response
///--------------------------------------
@implementation PBPlayerBadge

@synthesize badgeId;
@synthesize redeemed;
@synthesize claimed;
@synthesize image;
@synthesize name;
@synthesize description;
@synthesize amount;
@synthesize hint;

-(NSString *)description
{
    NSString *descriptionString = [NSString stringWithFormat:@"Player Badge : {\r\tbadge_id : %@\r\tredeemed : %@\r\tclaimed : %@\r\timage : %@\r\tname : %@\r\tdescription : %@\r\tamount : %lu\r\thint : %@\r\t}", self.badgeId, self.redeemed ? @"YES" : @"NO", self.claimed ? @"YES" : @"NO", self.image, self.name, self.description_, (unsigned long)self.amount, self.hint];
    
    return descriptionString;
}

+(PBPlayerBadge *)parseFromDictionary:(const NSDictionary *)jsonResponse startFromFinalLevel:(BOOL)startFromFinalLevel
{
    if(jsonResponse == nil)
        return nil;
    
    // create a result object
    PBPlayerBadge *c = [[PBPlayerBadge alloc] init];
    
    // ignore parsing level flag as it won't be appeared anywhere singlely
    c.parseLevelJsonResponse = [jsonResponse copy];
    
    c.badgeId = [c.parseLevelJsonResponse objectForKey:@"badge_id"];
    c.redeemed = [[c.parseLevelJsonResponse objectForKey:@"redeemed"] boolValue];
    c.claimed = [[c.parseLevelJsonResponse objectForKey:@"claimed"] boolValue];
    c.image = [c.parseLevelJsonResponse objectForKey:@"image"];
    c.name = [c.parseLevelJsonResponse objectForKey:@"name"];
    c.description_ = [c.parseLevelJsonResponse objectForKey:@"description"];
    c.amount = [[c.parseLevelJsonResponse objectForKey:@"amount"] unsignedIntegerValue];
    c.hint = [c.parseLevelJsonResponse objectForKey:@"hint"];
    
    return c;
}

@end

///--------------------------------------
/// PlayerBadge
///--------------------------------------
@implementation PBPlayerBadges_Response

@synthesize playerBadges;

-(NSString *)description
{
    // create string to hold all players line-by-line
    NSMutableString *lines = [NSMutableString stringWithString:@"Player Badges : {"];
    
    for(PBPlayerBadge *badge in self.playerBadges)
    {
        // get description line from each player-badge
        NSString *pbadgeLine = [badge description];
        // append \r
        NSString *pbadgeLineWithCR = [NSString stringWithFormat:@"\r\t%@\r", pbadgeLine];
        
        // append to result 'lines'
        [lines appendString:pbadgeLineWithCR];
    }
    
    // end with brace
    [lines appendString:@"}"];
    
    return [NSString stringWithString:lines];
}

+(PBPlayerBadges_Response *)parseFromDictionary:(const NSDictionary *)jsonResponse startFromFinalLevel:(BOOL)startFromFinalLevel
{
    if(jsonResponse == nil)
        return nil;
    
    // create a result
    PBPlayerBadges_Response *c = [[PBPlayerBadges_Response alloc] init];
    
    if(startFromFinalLevel)
    {
        c.parseLevelJsonResponse = [jsonResponse copy];
    }
    else
    {
        // get 'response'
        NSDictionary *response = [jsonResponse objectForKey:@"response"];
        NSAssert(response != nil, @"response must not be nil");
        
        c.parseLevelJsonResponse = response;
    }
    
    // convert response to NSArray*
    NSArray *badges = (NSArray*)c.parseLevelJsonResponse;
    // create a temp array to hold all badges
    NSMutableArray *tempBadges = [NSMutableArray array];
    
    for(NSDictionary *badge in badges)
    {
        // get badge
        PBPlayerBadge *pb = [PBPlayerBadge parseFromDictionary:badge startFromFinalLevel:YES];
        
        // add into temp array
        [tempBadges addObject:pb];
    }
    
    // set back player-badges
    c.playerBadges = [NSArray arrayWithArray:tempBadges];
    
    return c;
}

@end

///--------------------------------------
/// PlayerDetailedPublic
///--------------------------------------
@implementation PBPlayerDetailedPublic_Response

@synthesize playerPublic;
@synthesize percentOfLevel;
@synthesize levelTitle;
@synthesize levelImage;
@synthesize badges;
@synthesize points;

-(NSString *)description
{
    NSString *descriptionString = [NSString stringWithFormat:@"Player Detailed Public : {\r\t%@\r\tpercent_of_level : %.2f\r\tlevel_title : %@\r\tlevel_image : %@\r\t%@\r\t%@\r\t}", self.playerPublic, self.percentOfLevel, self.levelTitle, self.levelImage, self.badges, self.points];
    
    return descriptionString;
}

+(PBPlayerDetailedPublic_Response*)parseFromDictionary:(const NSDictionary *)jsonResponse startFromFinalLevel:(BOOL)startFromFinalLevel
{
    if(jsonResponse == nil)
        return nil;
    
    // create result response
    PBPlayerDetailedPublic_Response *c = [[PBPlayerDetailedPublic_Response alloc] init];
    
    if(startFromFinalLevel)
    {
        c.parseLevelJsonResponse = [jsonResponse copy];
    }
    else
    {
        // get 'response'
        NSDictionary *response = [jsonResponse objectForKey:@"response"];
        NSAssert(response != nil, @"response must not be nil");
        
        // get 'player'
        NSDictionary *player = [response objectForKey:@"player"];
        NSAssert(player != nil, @"player must not be nil");
        
        c.parseLevelJsonResponse = player;
    }
    
    // get player's public information
    c.playerPublic = [PBPlayerPublic_Response parseFromDictionary:c.parseLevelJsonResponse startFromFinalLevel:YES];
    
    // get other fields of data
    c.percentOfLevel = [[c.parseLevelJsonResponse objectForKey:@"percent_of_level"] floatValue];
    c.levelTitle = [c.parseLevelJsonResponse objectForKey:@"level_title"];
    c.levelImage = [c.parseLevelJsonResponse objectForKey:@"level_image"];
    
    // get 'badges'
    NSDictionary *badgesJson = [c.parseLevelJsonResponse objectForKey:@"badges"];
    // get badges
    c.badges = [PBPlayerBadges_Response parseFromDictionary:badgesJson startFromFinalLevel:YES];
    
    // get 'points'
    NSDictionary *pointsJson = [c.parseLevelJsonResponse objectForKey:@"points"];
    // get points
    c.points = [PBPoints_Response parseFromDictionary:pointsJson startFromFinalLevel:YES];
    
    return c;
}

@end

///--------------------------------------
/// PlayerDetailed
///--------------------------------------
@implementation PBPlayerDetailed_Response

@synthesize player;
@synthesize percentOfLevel;
@synthesize levelTitle;
@synthesize levelImage;
@synthesize badges;
@synthesize points;

-(NSString *)description
{
    NSString *descriptionString = [NSString stringWithFormat:@"Player Detailed : {\r\t%@\r\tpercent_of_level : %.2f\r\tlevel_title : %@\r\tlevel_image : %@\r\t%@\r\t%@\r\t}", self.player, self.percentOfLevel, self.levelTitle, self.levelImage, self.badges, self.points];
    
    return descriptionString;
}

+(PBPlayerDetailed_Response*)parseFromDictionary:(const NSDictionary *)jsonResponse startFromFinalLevel:(BOOL)startFromFinalLevel
{
    if(jsonResponse == nil)
        return nil;
    
    // create result response
    PBPlayerDetailed_Response *c = [[PBPlayerDetailed_Response alloc] init];
    
    if(startFromFinalLevel)
    {
        c.parseLevelJsonResponse = [jsonResponse copy];
    }
    else
    {
        // get 'response'
        NSDictionary *response = [jsonResponse objectForKey:@"response"];
        NSAssert(response != nil, @"response must not be nil");
        
        // get 'player'
        NSDictionary *player = [response objectForKey:@"player"];
        NSAssert(player != nil, @"player must not be nil");
        
        c.parseLevelJsonResponse = player;
    }
    
    // get player's information
    c.player = [PBPlayer_Response parseFromDictionary:c.parseLevelJsonResponse startFromFinalLevel:YES];
    
    // get other fields of data
    c.percentOfLevel = [[c.parseLevelJsonResponse objectForKey:@"percent_of_level"] floatValue];
    c.levelTitle = [c.parseLevelJsonResponse objectForKey:@"level_title"];
    c.levelImage = [c.parseLevelJsonResponse objectForKey:@"level_image"];
    
    // get 'badges'
    NSDictionary *badgesJson = [c.parseLevelJsonResponse objectForKey:@"badges"];
    // get badges
    c.badges = [PBPlayerBadges_Response parseFromDictionary:badgesJson startFromFinalLevel:YES];
    
    // get 'points'
    NSDictionary *pointsJson = [c.parseLevelJsonResponse objectForKey:@"points"];
    // get points
    c.points = [PBPoints_Response parseFromDictionary:pointsJson startFromFinalLevel:YES];
    
    return c;
}

@end

///--------------------------------------
/// PointHistory - No Response
///--------------------------------------
@implementation PBPointHistory

@synthesize message;
@synthesize rewardId;
@synthesize rewardName;
@synthesize value;
@synthesize dateAdded;
@synthesize actionName;
@synthesize stringFilter;
@synthesize actionIcon;

-(NSString *)description
{
    NSString *descriptionString = [NSString stringWithFormat:@"PointHistory (single) : {\r\tmessage : %@\r\treward_id : %@\r\treward_name : %@\r\tvalue : %lu\r\tdate_added : %@\r\taction_name : %@\r\tstring_filter : %@\r\taction_icon : %@\r\t}", self.message, self.rewardId, self.rewardName, (unsigned long)self.value, self.dateAdded, self.actionName, self.stringFilter, self.actionIcon];
    
    return descriptionString;
}

+(PBPointHistory *)parseFromDictionary:(const NSDictionary *)jsonResponse startFromFinalLevel:(BOOL)startFromFinalLevel
{
    if(jsonResponse == nil)
        return nil;
    
    // create result response
    PBPointHistory *c = [[PBPointHistory alloc] init];
    
    // ignore json level flag, because it doesn't appear anywhere singlely
    c.parseLevelJsonResponse = [jsonResponse copy];
    
    c.message = [c.parseLevelJsonResponse objectForKey:@"message"];
    c.rewardId = [c.parseLevelJsonResponse objectForKey:@"reward_id"];
    c.rewardName = [c.parseLevelJsonResponse objectForKey:@"reward_name"];
    c.value = [[c.parseLevelJsonResponse objectForKey:@"value"] unsignedIntegerValue];
    
    // create a date formatter to parse date-timestamp
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setTimeZone:[NSTimeZone timeZoneWithName:@"GMT"]];
    [dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ssZZZ"];
    
    c.dateAdded = [dateFormatter dateFromString:[c.parseLevelJsonResponse objectForKey:@"date_added"]];
    
    c.actionName = [c.parseLevelJsonResponse objectForKey:@"action_name"];
    c.stringFilter = [c.parseLevelJsonResponse objectForKey:@"string_filter"];
    c.actionIcon = [c.parseLevelJsonResponse objectForKey:@"action_icon"];
    
    return c;
}

@end

///--------------------------------------
/// PointHistory
///--------------------------------------
@implementation PBPointHistory_Response

@synthesize pointHistory;

-(NSString *)description
{
    // create string to hold all point-history line-by-line
    NSMutableString *lines = [NSMutableString stringWithString:@"Point History : {"];
    
    for(PBPointHistory *ph in self.pointHistory)
    {
        // get description line from each player-badge
        NSString *pointHistoryLine = [ph description];
        // append \r
        NSString *pointHistoryLineWithCR = [NSString stringWithFormat:@"\r\t%@\r", pointHistoryLine];
        
        // append to result 'lines'
        [lines appendString:pointHistoryLineWithCR];
    }
    
    // end with brace
    [lines appendString:@"}"];
    
    return [NSString stringWithString:lines];
}

+(PBPointHistory_Response *)parseFromDictionary:(const NSDictionary *)jsonResponse startFromFinalLevel:(BOOL)startFromFinalLevel
{
    if(jsonResponse == nil)
        return nil;
    
    // create result response
    PBPointHistory_Response *c = [[PBPointHistory_Response alloc] init];
    
    if(startFromFinalLevel)
    {
        c.parseLevelJsonResponse = [jsonResponse copy];
    }
    else
    {
        // get 'response'
        NSDictionary *response = [jsonResponse objectForKey:@"response"];
        NSAssert(response != nil, @"response must not be nil");
        
        // get 'points'
        NSDictionary *points = [response objectForKey:@"points"];
        NSAssert(points != nil, @"points must not be nil");
        
        c.parseLevelJsonResponse = points;
    }
    
    // convert points into array
    NSArray *phArray = (NSArray*)c.parseLevelJsonResponse;
    
    // temp array to hold all of point history elements
    NSMutableArray *tempPhArray = [NSMutableArray array];
    
    for(NSDictionary *ph in phArray)
    {
        // get point history
        PBPointHistory *pointHistory = [PBPointHistory parseFromDictionary:ph startFromFinalLevel:YES];
        
        // add to temp array
        [tempPhArray addObject:pointHistory];
    }
    
    // set back to result response
    c.pointHistory = [NSArray arrayWithArray:tempPhArray];
    
    return c;
}

@end

///--------------------------------------
/// ActionTime
///--------------------------------------
@implementation PBActionTime_Response

@synthesize actionId;
@synthesize actionName;
@synthesize time;

-(NSString *)description
{
    NSString *descriptionString = [NSString stringWithFormat:@"ActionTime : {\r\taction_id : %@\r\taction_name : %@\r\ttime : %@\r\t}", self.actionId, self.actionName, self.time];
    
    return descriptionString;
}

+(PBActionTime_Response *)parseFromDictionary:(const NSDictionary *)jsonResponse startFromFinalLevel:(BOOL)startFromFinalLevel
{
    if(jsonResponse == nil)
        return nil;
    
    // create a result response
    PBActionTime_Response *c = [[PBActionTime_Response alloc] init];
    
    if(startFromFinalLevel)
    {
        c.parseLevelJsonResponse = [jsonResponse copy];
    }
    else
    {
        // get 'response'
        NSDictionary *response = [jsonResponse objectForKey:@"response"];
        NSAssert(response != nil, @"response must not be nil");
        
        // get 'action'
        NSDictionary *action = [response objectForKey:@"action"];
        NSAssert(action != nil, @"action must not be nil");
        
        c.parseLevelJsonResponse = action;
    }
    
    // parse
    c.actionId = [c.parseLevelJsonResponse objectForKey:@"action_id"];
    c.actionName = [c.parseLevelJsonResponse objectForKey:@"action_name"];
    
    // create a date formatter to parse date-timestamp
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setTimeZone:[NSTimeZone timeZoneWithName:@"GMT"]];
    [dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ssZZZ"];
    
    c.time = [dateFormatter dateFromString:[c.parseLevelJsonResponse objectForKey:@"time"]];
    
    return c;
}

@end

///--------------------------------------
/// LastAction
///--------------------------------------
@implementation PBLastAction_Response

@synthesize actionId;
@synthesize actionName;
@synthesize time;

-(NSString *)description
{
    NSString *descriptionString = [NSString stringWithFormat:@"Last Action : {\r\taction_id : %@\r\taction_name : %@\r\ttime : %@\r\t}", self.actionId, self.actionName, self.time];
    
    return descriptionString;
}

+(PBLastAction_Response *)parseFromDictionary:(const NSDictionary *)jsonResponse startFromFinalLevel:(BOOL)startFromFinalLevel
{
    if(jsonResponse == nil)
        return nil;
    
    // create a result response
    PBLastAction_Response *c = [[PBLastAction_Response alloc] init];
    
    if(startFromFinalLevel)
    {
        c.parseLevelJsonResponse = [jsonResponse copy];
    }
    else
    {
        // get 'response'
        NSDictionary *response = [jsonResponse objectForKey:@"response"];
        NSAssert(response != nil, @"response must not be nil");
        
        // get 'action'
        NSDictionary *action = [response objectForKey:@"action"];
        NSAssert(action != nil, @"action must not be nil");
        
        c.parseLevelJsonResponse = action;
    }
    
    // parse
    c.actionId = [c.parseLevelJsonResponse objectForKey:@"action_id"];
    c.actionName = [c.parseLevelJsonResponse objectForKey:@"action_name"];
    
    // create a date formatter to parse date-timestamp
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setTimeZone:[NSTimeZone timeZoneWithName:@"GMT"]];
    [dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ssZZZ"];
    
    c.time = [dateFormatter dateFromString:[c.parseLevelJsonResponse objectForKey:@"time"]];
    
    return c;
}

@end

///--------------------------------------
/// ActionCount
///--------------------------------------
@implementation PBActionCount_Response

@synthesize actionId;
@synthesize actionName;
@synthesize count;

-(NSString *)description
{
    NSString *descriptionString = [NSString stringWithFormat:@"Action Count : {\r\taction_id : %@\r\taction_name : %@\r\tcount : %lu\r\t}", self.actionId, self.actionName, self.count];
    
    return descriptionString;
}

+(PBActionCount_Response *)parseFromDictionary:(const NSDictionary *)jsonResponse startFromFinalLevel:(BOOL)startFromFinalLevel
{
    if(jsonResponse == nil)
        return nil;
    
    // create a result response
    PBActionCount_Response *c = [[PBActionCount_Response alloc] init];
    
    if(startFromFinalLevel)
    {
        c.parseLevelJsonResponse = [jsonResponse copy];
    }
    else
    {
        // get 'response'
        NSDictionary *response = [jsonResponse objectForKey:@"response"];
        NSAssert(response != nil, @"response must not be nil");
        
        // get 'action'
        NSDictionary *action = [response objectForKey:@"action"];
        NSAssert(action != nil, @"action must not be nil");
        
        c.parseLevelJsonResponse = action;
    }
    
    // parse
    c.actionId = [c.parseLevelJsonResponse objectForKey:@"action_id"];
    c.actionName = [c.parseLevelJsonResponse objectForKey:@"action_name"];
    c.count = [[c.parseLevelJsonResponse objectForKey:@"count"] unsignedIntegerValue];
    
    return c;
}

@end

///--------------------------------------
/// Level
///--------------------------------------
@implementation PBLevel_Response

@synthesize levelTitle;
@synthesize level;
@synthesize minExp;
@synthesize maxExp;
@synthesize levelImage;

-(NSString *)description
{
    NSString *descriptionString = [NSString stringWithFormat:@"Level : {\r\tlevel_title : %@\r\tlevel = %lu\r\tmin_exp : %lu\r\tmax_exp : %lu\r\tlevel_image : %@\r\t}", self.levelTitle, (unsigned long)self.level, (unsigned long)self.minExp, (unsigned long)self.maxExp, self.levelImage];
    
    return descriptionString;
}

+(PBLevel_Response *)parseFromDictionary:(const NSDictionary *)jsonResponse startFromFinalLevel:(BOOL)startFromFinalLevel
{
    if(jsonResponse == nil)
        return nil;
    
    // create a result response
    PBLevel_Response *c = [[PBLevel_Response alloc] init];
    
    if(startFromFinalLevel)
    {
        c.parseLevelJsonResponse = [jsonResponse copy];
    }
    else
    {
        // get 'response'
        NSDictionary *response = [jsonResponse objectForKey:@"response"];
        NSAssert(response != nil, @"response must not be nil");
        
        c.parseLevelJsonResponse = response;
    }
    
    // parse
    c.levelTitle = [c.parseLevelJsonResponse objectForKey:@"level_title"];
    c.level = [[c.parseLevelJsonResponse objectForKey:@"level"] unsignedIntegerValue];
    c.minExp = [[c.parseLevelJsonResponse objectForKey:@"min_exp"] unsignedIntegerValue];
    c.maxExp = [[c.parseLevelJsonResponse objectForKey:@"max_exp"] unsignedIntegerValue];
    c.levelImage = [c.parseLevelJsonResponse objectForKey:@"level_image"];
    
    return c;
}

@end
