//
//  playbasis.h
//  playbasis
//
//  Created by Playbasis.
//  Copyright (c) 2556 Playbasisß. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "libs/Reachability/Reachability.h"
#import "JSONKit.h"
#import "PBTypes.h"
#import "PBRequest.h"
#import "NSMutableArray+QueueAndSerializationAdditions.h"
#import "PBResponses.h"

/**
 Playbasis
 Handle the API end-point calls from client side.
 */
@interface Playbasis : NSObject
{
    NSString *token;
    NSString *apiKeyParam;
    id<PBAuth_ResponseHandler> authDelegate;
    NSMutableArray *requestOptQueue;
}

@property (nonatomic, readonly) NSString* token;

/**
 Utility method to register device for push notification.
 Call this method inside
 */
+(void)registerDeviceForPushNotification;

/**
 Utility method to handle device token data, and convert it into
 a proper format ready to use later, then save it to NSUserDefaults
 for Playbasis SDK to retrieve it and register device for push
 notification later.
 
 @param deviceToken Device token sent in from native iOS platform.
 @param withKey Key string for Playbasis SDK to retrieve the value from later via NSUserDefaults.
 
 */
+(void)saveDeviceToken:(NSData *)deviceToken withKey:(NSString*)key;

/**
 Get the singleton instance of Playbasis.
 */
+(id)sharedPB;

-(id)initWithCoder:(NSCoder *)decoder;
-(void)encodeWithCoder:(NSCoder *)encoder;
-(id)init;
-(void)dealloc;

/**
 Get request-operational-queue.
 It holds all created http requests. Those requests are not dispatched or sent just yet. It's after dequeing, it will start sending those request one by one.
 */
-(const NSMutableArray *)getRequestOperationalQueue;

/**
 Authenticate and get access token.
 */
-(PBRequest *)auth:(NSString *)apiKey withApiSecret:(NSString *)apiSecret andDelegate:(id<PBAuth_ResponseHandler>)delegate;
-(PBRequest *)auth:(NSString *)apiKey withApiSecret:(NSString *)apiSecret andBlock:(PBAuth_ResponseBlock)block;
-(PBRequest *)authAsync:(NSString *)apiKey withApiSecret:(NSString *)apiSecret andDelegate:(id<PBAuth_ResponseHandler>)delegate;
-(PBRequest *)authAsync:(NSString *)apiKey withApiSecret:(NSString *)apiSecret andBlock:(PBAuth_ResponseBlock)block;

/**
 Request a new access token, and discard the current one.
 */
-(PBRequest *)renew:(NSString *)apiKey withApiSecret:(NSString *)apiSecret andDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)renew:(NSString *)apiKey withApiSecret:(NSString *)apiSecret andBlock:(PBResponseBlock)block;
-(PBRequest *)renewAsync:(NSString *)apiKey withApiSecret:(NSString *)apiSecret andDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)renewAsync:(NSString *)apiKey withApiSecret:(NSString *)apiSecret andBlock:(PBResponseBlock)block;

/** 
 Get player's public information.
 It will send request via GET method.
 */
-(PBRequest *)playerPublic:(NSString *)playerId withDelegate:(id<PBPlayerPublic_ResponseHandler>)delegate;
-(PBRequest *)playerPublic:(NSString *)playerId withBlock:(PBPlayerPublic_ResponseBlock)block;
-(PBRequest *)playerPublicAsync:(NSString *)playerId withDelegate:(id<PBPlayerPublic_ResponseHandler>)delegate;
-(PBRequest *)playerPublicAsync:(NSString *)playerId withBlock:(PBPlayerPublic_ResponseBlock)block;

/** 
 Get player's both private and public information.
 */
-(PBRequest *)player:(NSString *)playerId withDelegate:(id<PBPlayer_ResponseHandler>)delegate;
-(PBRequest *)player:(NSString *)playerId withBlock:(PBPlayer_ResponseBlock)block;
-(PBRequest *)playerAsync:(NSString *)playerId withDelegate:(id<PBPlayer_ResponseHandler>)delegate;
-(PBRequest *)playerAsync:(NSString *)playerId withBlock:(PBPlayer_ResponseBlock)block;

/**
 Get basic information of list of players.
 playerListId is in the format of id separated by "," ie. "1,2,3".
 */
-(PBRequest *)playerList:(NSString *)playerListId withDelegate:(id<PBPlayerList_ResponseHandler>)delegate;
-(PBRequest *)playerList:(NSString *)playerListId withBlock:(PBPlayerList_ResponseBlock)block;
-(PBRequest *)playerListAsync:(NSString *)playerListId withDelegate:(id<PBPlayerList_ResponseHandler>)delegate;
-(PBRequest *)playerListAsync:(NSString *)playerListId withBlock:(PBPlayerList_ResponseBlock)block;

/**
 Get player's detailed public information including points and badge.
 */
-(PBRequest *)playerDetailPublic:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)playerDetailPublic:(NSString *)playerId withBlock:(PBResponseBlock)block;
-(PBRequest *)playerDetailPublicAsync:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)playerDetailPublicAsync:(NSString *)playerId withBlock:(PBResponseBlock)block;

/**
 Get player's detailed information both private and public one including points and badges.
 */
-(PBRequest *)playerDetail:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)playerDetail:(NSString *)playerId withBlock:(PBResponseBlock)block;
-(PBRequest *)playerDetailAsync:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)playerDetailAsync:(NSString *)playerId withBlock:(PBResponseBlock)block;

/**
 Register from the client side as a Playbasis player.
 */
-(PBRequest *)registerUser:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate :(NSString *)username :(NSString *)email :(NSString *)imageUrl, ...;
-(PBRequest *)registerUser:(NSString *)playerId withBlock:(PBResponseBlock)block :(NSString *)username :(NSString *)email :(NSString *)imageUrl, ...;
-(PBRequest *)registerUserAsync:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate :(NSString *)username :(NSString *)email :(NSString *)imageUrl, ...;
-(PBRequest *)registerUserAsync:(NSString *)playerId withBlock:(PBResponseBlock)block :(NSString *)username :(NSString *)email :(NSString *)imageUrl, ...;

/**
 Update player information.
 */
-(PBRequest *)updateUser:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate :(NSString *)firstArg ,...;
-(PBRequest *)updateUser:(NSString *)playerId withBlock:(PBResponseBlock)block :(NSString *)firstArg ,...;
-(PBRequest *)updateUserAsync:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate :(NSString *)firstArg ,...;
-(PBRequest *)updateUserAsync:(NSString *)playerId withBlock:(PBResponseBlock)block :(NSString *)firstArg ,...;

/**
 Permanently delete user from Playbasis's database.
 */
-(PBRequest *)deleteUser:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)deleteUser:(NSString *)playerId withBlock:(PBResponseBlock)block;
-(PBRequest *)deleteUserAsync:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)deleteUserAsync:(NSString *)playerId withBlock:(PBResponseBlock)block;

/**
 Tell Playbasis system that player has logged in.
 It uses delegate callback.
 */
-(PBRequest *)login:(NSString *)playerId syncUrl:(BOOL)syncUrl withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)login:(NSString *)playerId syncUrl:(BOOL)syncUrl withBlock:(PBResponseBlock)block;

-(PBRequest *)login:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)login:(NSString *)playerId withBlock:(PBResponseBlock)block;
-(PBRequest *)loginAsync:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)loginAsync:(NSString *)playerId withBlock:(PBResponseBlock)block;

/**
 Tell Playbasis system that player has logged out.
 */
-(PBRequest *)logout:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)logout:(NSString *)playerId withBlock:(PBResponseBlock)block;
-(PBRequest *)logoutAsync:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)logoutAsync:(NSString *)playerId withBlock:(PBResponseBlock)block;

/**
 Returns information about all point-based rewards that a player currently have.
 */
-(PBRequest *)points:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)points:(NSString *)playerId withBlock:(PBResponseBlock)block;
-(PBRequest *)pointsAsync:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)pointsAsync:(NSString *)playerId withBlock:(PBResponseBlock)block;


/**
 Returns how much of specified the point-based reward a player currently have.
 */
-(PBRequest *)point:(NSString *)playerId forPoint:(NSString *)pointName withDelegate:(id<PBPoint_ResponseHandler>)delegate;
-(PBRequest *)point:(NSString *)playerId forPoint:(NSString *)pointName withBlock:(PBPoint_ResponseBlock)block;
-(PBRequest *)pointAsync:(NSString *)playerId forPoint:(NSString *)pointName withDelegate:(id<PBPoint_ResponseHandler>)delegate;
-(PBRequest *)pointAsync:(NSString *)playerId forPoint:(NSString *)pointName withBlock:(PBPoint_ResponseBlock)block;

/**
 Get history point of user.
 */
-(PBRequest *)pointHistory:(NSString *)playerId forPoint:(NSString *)pointName offset:(unsigned int)offset withLimit:(unsigned int)limit andDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)pointHistory:(NSString *)playerId forPoint:(NSString *)pointName offset:(unsigned int)offset withLimit:(unsigned int)limit andBlock:(PBResponseBlock)block;
-(PBRequest *)pointHistoryAsync:(NSString *)playerId forPoint:(NSString *)pointName offset:(unsigned int)offset withLimit:(unsigned int)limit andDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)pointHistoryAsync:(NSString *)playerId forPoint:(NSString *)pointName offset:(unsigned int)offset withLimit:(unsigned int)limit andBlock:(PBResponseBlock)block;

/**
 Get the latest time for the specified action that player has performed.
 */
-(PBRequest *)actionTime:(NSString *)playerId forAction:(NSString *)actionName withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)actionTime:(NSString *)playerId forAction:(NSString *)actionName withBlock:(PBResponseBlock)block;
-(PBRequest *)actionTimeAsync:(NSString *)playerId forAction:(NSString *)actionName withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)actionTimeAsync:(NSString *)playerId forAction:(NSString *)actionName withBlock:(PBResponseBlock)block;

/**
 Return the time and action that player has performed.
 */
-(PBRequest *)actionLastPerformed:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)actionLastPerformed:(NSString *)playerId withBlock:(PBResponseBlock)block;
-(PBRequest *)actionLastPerformedAsync:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)actionLastPerformedAsync:(NSString *)playerId withBlock:(PBResponseBlock)block;

/**
 Get the latest time of specified action that player has performed.
 */
-(PBRequest *)actionLastPerformedTime:(NSString *)playerId forAction:(NSString *)actionName withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)actionLastPerformedTime:(NSString *)playerId forAction:(NSString *)actionName withBlock:(PBResponseBlock)block;
-(PBRequest *)actionLastPerformedTimeAsync:(NSString *)playerId forAction:(NSString *)actionName withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)actionLastPerformedTimeAsync:(NSString *)playerId forAction:(NSString *)actionName withBlock:(PBResponseBlock)block;

/**
 Return the number of times that player has performed the specified action.
 */
-(PBRequest *)actionPerformedCount:(NSString *)playerId forAction:(NSString *)actionName withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)actionPerformedCount:(NSString *)playerId forAction:(NSString *)actionName withBlock:(PBResponseBlock)block;
-(PBRequest *)actionPerformedCountAsync:(NSString *)playerId forAction:(NSString *)actionName withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)actionPerformedCountAsync:(NSString *)playerId forAction:(NSString *)actionName withBlock:(PBResponseBlock)block;

/**
 Return information about all badges that player has earned.
 */
-(PBRequest *)badgeOwned:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)badgeOwned:(NSString *)playerId withBlock:(PBResponseBlock)block;
-(PBRequest *)badgeOwnedAsync:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)badgeOwnedAsync:(NSString *)playerId withBlock:(PBResponseBlock)block;

/**
 Returns list of players sorted by the specified point type.
 */
-(PBRequest *)rank:(NSString *)rankedBy withLimit:(unsigned int)limit andDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)rank:(NSString *)rankedBy withLimit:(unsigned int)limit andBlock:(PBResponseBlock)block;
-(PBRequest *)rankAsync:(NSString *)rankedBy withLimit:(unsigned int)limit andDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)rankAsync:(NSString *)rankedBy withLimit:(unsigned int)limit andBlock:(PBResponseBlock)block;

/**
 Return list of players sorted by each point type.
 */
-(PBRequest *)ranks:(unsigned int)limit withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)ranks:(unsigned int)limit withBlock:(PBResponseBlock)block;
-(PBRequest *)ranksAsync:(unsigned int)limit withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)ranksAsync:(unsigned int)limit withBlock:(PBResponseBlock)block;

/**
 Return detail of level.
 */
-(PBRequest *)level:(unsigned int)level withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)level:(unsigned int)level withBlock:(PBResponseBlock)block;
-(PBRequest *)levelAsync:(unsigned int)level withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)levelAsync:(unsigned int)level withBlock:(PBResponseBlock)block;

/**
 Return all detail of levels.
 */
-(PBRequest *)levelsWithDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)levelsWithBlock:(PBResponseBlock)block;
-(PBRequest *)levelsAsyncWithDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)levelsAsyncWithBlock:(PBResponseBlock)block;

/**
 Claim a badge that player has earned.
 */
-(PBRequest *)claimBadge:(NSString *)playerId withBadgeId:(NSString *)badgeId andDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)claimBadge:(NSString *)playerId withBadgeId:(NSString *)badgeId andBlock:(PBResponseBlock)block;
-(PBRequest *)claimBadgeAsync:(NSString *)playerId withBadgeId:(NSString *)badgeId andDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)claimBadgeAsync:(NSString *)playerId withBadgeId:(NSString *)badgeId andBlock:(PBResponseBlock)block;

/**
 Redeem a badge that player has claimed.
 */
-(PBRequest *)redeemBadge:(NSString *)playerId withBadgeId:(NSString *)badgeId andDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)redeemBadge:(NSString *)playerId withBadgeId:(NSString *)badgeId andBlock:(PBResponseBlock)block;
-(PBRequest *)redeemBadgeAsync:(NSString *)playerId withBadgeId:(NSString *)badgeId andDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)redeemBadgeAsync:(NSString *)playerId withBadgeId:(NSString *)badgeId andBlock:(PBResponseBlock)block;

/**
 Return information about all goods that player has redeemed.
 */
-(PBRequest *)goodsOwned:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)goodsOwned:(NSString *)playerId withBlock:(PBResponseBlock)block;
-(PBRequest *)goodsOwnedAsync:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)goodsOwnedAsync:(NSString *)playerId withBlock:(PBResponseBlock)block;

/**
 Return quest information that player has joined.
 */
-(PBRequest *)questOfPlayer:(NSString *)playerId questId:(NSString *)questId andDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)questOfPlayer:(NSString *)playerId questId:(NSString *)questId andBlock:(PBResponseBlock)block;
-(PBRequest *)questOfPlayerAsync:(NSString *)playerId questId:(NSString *)questId andDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)questOfPlayerAsync:(NSString *)playerId questId:(NSString *)questId andBlock:(PBResponseBlock)block;

/**
 Return list of quest that player has joined.
 */
-(PBRequest *)questListOfPlayer:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)questListOfPlayer:(NSString *)playerId withBlock:(PBResponseBlock)block;
-(PBRequest *)questListOfPlayerAsync:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)questListOfPlayerAsync:(NSString *)playerId withBlock:(PBResponseBlock)block;

/**
 Return information of specified badge.
 */
-(PBRequest *)badge:(NSString *)badgeId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)badge:(NSString *)badgeId withBlock:(PBResponseBlock)block;
-(PBRequest *)badgeAsync:(NSString *)badgeId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)badgeAsync:(NSString *)badgeId withBlock:(PBResponseBlock)block;

/**
 Return information about all badges of the current site.
 */
-(PBRequest *)badgesWithDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)badgesWithBlock:(PBResponseBlock)block;
-(PBRequest *)badgesAsyncWithDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)badgesAsyncWithBlock:(PBResponseBlock)block;

/**
 Return information about goods for the specified id.
 */
-(PBRequest *)goods:(NSString *)goodId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)goods:(NSString *)goodId withBlock:(PBResponseBlock)block;
-(PBRequest *)goodsAsync:(NSString *)goodId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)goodsAsync:(NSString *)goodId withBlock:(PBResponseBlock)block;

/**
 Return information about all available goods on the current site.
 */
-(PBRequest *)goodsListWithDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)goodsListWithBlock:(PBResponseBlock)block;
-(PBRequest *)goodsListAsyncWithDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)goodsListAsyncWithBlock:(PBResponseBlock)block;

/**
 Return the name of actions that can trigger game's rules within a client's website.
 */
-(PBRequest *)actionConfigWithDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)actionConfigWithBlock:(PBResponseBlock)block;
-(PBRequest *)actionConfigAsyncWithDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)actionConfigAsyncWithBlock:(PBResponseBlock)block;

/**
 Process an action through all the game's rules defined for client's website.
 */
-(PBRequest *)rule:(NSString *)playerId forAction:(NSString *)action withDelegate:(id<PBResponseHandler>)delegate, ...;
-(PBRequest *)rule:(NSString *)playerId forAction:(NSString *)action syncUrl:(BOOL)syncUrl withDelegate:(id<PBResponseHandler>)delegate, ...;

-(PBRequest *)rule:(NSString *)playerId forAction:(NSString *)action withBlock:(PBResponseBlock)block, ...;
-(PBRequest *)rule:(NSString *)playerId forAction:(NSString *)action syncUrl:(BOOL)syncUrl withBlock:(PBResponseBlock)block, ...;

-(PBRequest *)ruleAsync:(NSString *)playerId forAction:(NSString *)action withDelegate:(id<PBResponseHandler>)delegate, ...;
-(PBRequest *)ruleAsync:(NSString *)playerId forAction:(NSString *)action syncUrl:(BOOL)syncUrl withDelegate:(id<PBResponseHandler>)delegate, ...;

-(PBRequest *)ruleAsync:(NSString *)playerId forAction:(NSString *)action withBlock:(PBResponseBlock)block, ...;
-(PBRequest *)ruleAsync:(NSString *)playerId forAction:(NSString *)action syncUrl:(BOOL)syncUrl withBlock:(PBResponseBlock)block, ...;

/**
 Return information about all quests in current site.
 */
-(PBRequest *)questListWithDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)questListWithBlock:(PBResponseBlock)block;
-(PBRequest *)questListWithDelegateAsync:(id<PBResponseHandler>)delegate;
-(PBRequest *)questListWithBlockAsync:(PBResponseBlock)block;

/**
 Return information about quest with the specified id.
 */
-(PBRequest *)quest:(NSString *)questId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)quest:(NSString *)questId withBlock:(PBResponseBlock)block;
-(PBRequest *)questAsync:(NSString *)questId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)questAsync:(NSString *)questId withBlock:(PBResponseBlock)block;

/**
 Return information about mission with the specified id.
 */
-(PBRequest *)mission:(NSString *)questId mission:(NSString *)missionId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)mission:(NSString *)questId mission:(NSString *)missionId withBlock:(PBResponseBlock)block;
-(PBRequest *)missionAsync:(NSString *)questId mission:(NSString *)missionId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)missionAsync:(NSString *)questId mission:(NSString *)missionId withBlock:(PBResponseBlock)block;

-(PBRequest *)questAvailableForPlayer:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)questAvailableForPlayer:(NSString *)playerId withBlock:(PBResponseBlock)block;
-(PBRequest *)questAvailableForPlayerAsync:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)questAvailableForPlayerAsync:(NSString *)playerId withBlock:(PBResponseBlock)block;

/**
 Return information whether the quest is ready for the player.
 */
-(PBRequest *)questAvailable:(NSString *)questId forPlayer:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)questAvailable:(NSString *)questId forPlayer:(NSString *)playerId withBlock:(PBResponseBlock)block;
-(PBRequest *)questAvailableAsync:(NSString *)questId forPlayer:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)questAvailableAsync:(NSString *)questId forPlayer:(NSString *)playerId withBlock:(PBResponseBlock)block;

/**
 Return information about all of the quests available for the player.
 */
-(PBRequest *)questsAvailable:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)questsAvailable:(NSString *)playerId withBlock:(PBResponseBlock)block;
-(PBRequest *)questsAvailableAsync:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)questsAvailableAsync:(NSString *)playerId withBlock:(PBResponseBlock)block;

/**
 Player joins a quest.
 */
-(PBRequest *)joinQuest:(NSString *)questId player:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)joinQuest:(NSString *)questId player:(NSString *)playerId withBlock:(PBResponseBlock)block;
-(PBRequest *)joinQuestAsync:(NSString *)questId player:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)joinQuestAsync:(NSString *)questId player:(NSString *)playerId withBlock:(PBResponseBlock)block;

/**
 Player cancels a quest.
 */
-(PBRequest *)cancelQuest:(NSString *)questId player:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)cancelQuest:(NSString *)questId player:(NSString *)playerId withBlock:(PBResponseBlock)block;
-(PBRequest *)cancelQuestAsync:(NSString *)questId player:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)cancelQuestAsync:(NSString *)questId player:(NSString *)playerId withBlock:(PBResponseBlock)block;

/**
 Redeem goods for player.
 */
-(PBRequest *)redeemGoods:(NSString *)goodsId player:(NSString *)playerId amount:(unsigned int)amount withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)redeemGoods:(NSString *)goodsId player:(NSString *)playerId amount:(unsigned int)amount withBlock:(PBResponseBlock)block;
-(PBRequest *)redeemGoodsAsync:(NSString *)goodsId player:(NSString *)playerId amount:(unsigned int)amount withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)redeemGoodsAsync:(NSString *)goodsId player:(NSString *)playerId amount:(unsigned int)amount withBlock:(PBResponseBlock)block;

/**
 Return recent activity points of all players.
 */
-(PBRequest *)recentPoint:(unsigned int)offset limit:(unsigned int)limit withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)recentPoint:(unsigned int)offset limit:(unsigned int)limit withBlock:(PBResponseBlock)block;
-(PBRequest *)recentPointAsync:(unsigned int)offset limit:(unsigned int)limit withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)recentPointAsync:(unsigned int)offset limit:(unsigned int)limit withBlock:(PBResponseBlock)block;

/**
 Return recent activity points of point name of all players.
 */
-(PBRequest *)recentPointByName:(NSString *)pointName offset:(unsigned int)offset limit:(unsigned int)limit withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)recentPointByName:(NSString *)pointName offset:(unsigned int)offset limit:(unsigned int)limit withBlock:(PBResponseBlock)block;
-(PBRequest *)recentPointByNameAsync:(NSString *)pointName offset:(unsigned int)offset limit:(unsigned int)limit withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)recentPointByNameAsync:(NSString *)pointName offset:(unsigned int)offset limit:(unsigned int)limit withBlock:(PBResponseBlock)block;

/**
 Send Email to a player.
 */
-(PBRequest *)sendEmail:(NSString *)playerId subject:(NSString *)subject message:(NSString *)message withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)sendEmail:(NSString *)playerId subject:(NSString *)subject message:(NSString *)message withBlock:(PBResponseBlock)block;
-(PBRequest *)sendEmailAsync:(NSString *)playerId subject:(NSString *)subject message:(NSString *)message withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)sendEmailAsync:(NSString *)playerId subject:(NSString *)subject message:(NSString *)message withBlock:(PBResponseBlock)block;

/**
 Send Email to a player with template-id.
 */
-(PBRequest *)sendEmail:(NSString *)playerId subject:(NSString *)subject message:(NSString *)message template:(NSString *)templateId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)sendEmail:(NSString *)playerId subject:(NSString *)subject message:(NSString *)message template:(NSString *)templateId withBlock:(PBResponseBlock)block;
-(PBRequest *)sendEmailAsync:(NSString *)playerId subject:(NSString *)subject message:(NSString *)message template:(NSString *)templateId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)sendEmailAsync:(NSString *)playerId subject:(NSString *)subject message:(NSString *)message template:(NSString *)templateId withBlock:(PBResponseBlock)block;

/**
 Send Email Coupon to a player.
 */
-(PBRequest *)sendEmailCoupon:(NSString *)playerId ref:(NSString *)refId subject:(NSString *)subject message:(NSString *)message withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)sendEmailCoupon:(NSString *)playerId ref:(NSString *)refId subject:(NSString *)subject message:(NSString *)message withBlock:(PBResponseBlock)block;
-(PBRequest *)sendEmailCouponAsync:(NSString *)playerId ref:(NSString *)refId subject:(NSString *)subject message:(NSString *)message withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)sendEmailCouponAsync:(NSString *)playerId ref:(NSString *)refId subject:(NSString *)subject message:(NSString *)message withBlock:(PBResponseBlock)block;

/**
 Send Email Coupon to a player with template-id.
 */
-(PBRequest *)sendEmailCoupon:(NSString *)playerId ref:(NSString *)refId subject:(NSString *)subject message:(NSString *)message template:(NSString *)templateId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)sendEmailCoupon:(NSString *)playerId ref:(NSString *)refId subject:(NSString *)subject message:(NSString *)message template:(NSString *)templateId withBlock:(PBResponseBlock)block;
-(PBRequest *)sendEmailCouponAsync:(NSString *)playerId ref:(NSString *)refId subject:(NSString *)subject message:(NSString *)message template:(NSString *)templateId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)sendEmailCouponAsync:(NSString *)playerId ref:(NSString *)refId subject:(NSString *)subject message:(NSString *)message template:(NSString *)templateId withBlock:(PBResponseBlock)block;

/**
 Return a list of active quizzes.
 */
-(PBRequest *)quizList:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)quizList:(NSString *)playerId withBlock:(PBResponseBlock)block;
-(PBRequest *)quizListAsync:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)quizListAsync:(NSString *)playerId withBlock:(PBResponseBlock)block;

/**
 Get detail of a quiz.
 */
-(PBRequest *)quizDetail:(NSString *)quizId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)quizDetail:(NSString *)quizId withBlock:(PBResponseBlock)block;
-(PBRequest *)quizDetailAsync:(NSString *)quizId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)quizDetailAsync:(NSString *)quizId withBlock:(PBResponseBlock)block;

/**
 Get detail of a quiz by also specifying player-id.
 */
-(PBRequest *)quizDetail:(NSString *)quizId forPlayer:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)quizDetail:(NSString *)quizId forPlayer:(NSString *)playerId withBlock:(PBResponseBlock)block;
-(PBRequest *)quizDetailAsync:(NSString *)quizId forPlayer:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)quizDetailAsync:(NSString *)quizId forPlayer:(NSString *)playerId withBlock:(PBResponseBlock)block;

/**
 Get a random of quiz from available quizzes of player.
 */
-(PBRequest *)quizRandom:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)quizRandom:(NSString *)playerId withBlock:(PBResponseBlock)block;
-(PBRequest *)quizRandomAsync:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)quizRandomAsync:(NSString *)playerId withBlock:(PBResponseBlock)block;

/**
 Get recent quizzes done by player.
 */
-(PBRequest *)quizDone:(NSString *)playerId limit:(NSInteger)limit withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)quizDone:(NSString *)playerId limit:(NSInteger)limit withBlock:(PBResponseBlock)block;
-(PBRequest *)quizDoneAsync:(NSString *)playerId limit:(NSInteger)limit withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)quizDoneAsync:(NSString *)playerId limit:(NSInteger)limit withBlock:(PBResponseBlock)block;

/**
 Get pending quizzes by player.
 */
-(PBRequest *)quizPending:(NSString *)playerId limit:(NSInteger)limit withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)quizPending:(NSString *)playerId limit:(NSInteger)limit withBlock:(PBResponseBlock)block;
-(PBRequest *)quizPendingAsync:(NSString *)playerId limit:(NSInteger)limit withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)quizPendingAsync:(NSString *)playerId limit:(NSInteger)limit withBlock:(PBResponseBlock)block;

/**
 Get a question from a quiz for player.
 */
-(PBRequest *)quizQuestion:(NSString *)quizId forPlayer:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)quizQuestion:(NSString *)quizId forPlayer:(NSString *)playerId withBlock:(PBResponseBlock)block;
-(PBRequest *)quizQuestionAsync:(NSString *)quizId forPlayer:(NSString *)playerId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)quizQuestionAsync:(NSString *)quizId forPlayer:(NSString *)playerId withBlock:(PBResponseBlock)block;

/**
 Answer a question for a given quiz.
 */
-(PBRequest *)quizAnswer:(NSString *)quizId optionId:(NSString *)optionId forPlayer:(NSString *)playerId ofQuestionId:(NSString *)questionId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)quizAnswer:(NSString *)quizId optionId:(NSString *)optionId forPlayer:(NSString *)playerId ofQuestionId:(NSString *)questionId withBlock:(PBResponseBlock)block;
-(PBRequest *)quizAnswerAsync:(NSString *)quizId optionId:(NSString *)optionId forPlayer:(NSString *)playerId ofQuestionId:(NSString *)questionId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)quizAnswerAsync:(NSString *)quizId optionId:(NSString *)optionId forPlayer:(NSString *)playerId ofQuestionId:(NSString *)questionId withBlock:(PBResponseBlock)block;

/**
 Rank player by their score for a quiz.
 */
-(PBRequest *)quizScoreRank:(NSString *)quizId limit:(NSInteger)limit withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)quizScoreRank:(NSString *)quizId limit:(NSInteger)limit withBlock:(PBResponseBlock)block;
-(PBRequest *)quizScoreRankAsync:(NSString *)quizId limit:(NSInteger)limit withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)quizScoreRankAsync:(NSString *)quizId limit:(NSInteger)limit withBlock:(PBResponseBlock)block;

/**
 Send SMS to a player.
 */
-(PBRequest *)sms:(NSString *)playerId message:(NSString *)message withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)sms:(NSString *)playerId message:(NSString *)message withBlock:(PBResponseBlock)block;
-(PBRequest *)smsAsync:(NSString *)playerId message:(NSString *)message withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)smsAsync:(NSString *)playerId message:(NSString *)message withBlock:(PBResponseBlock)block;

/**
 Send SMS to a player with a template-id.
 */
-(PBRequest *)sms:(NSString *)playerId message:(NSString *)message template:(NSString *)templateId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)sms:(NSString *)playerId message:(NSString *)message tempalte:(NSString *)templateId withBlock:(PBResponseBlock)block;
-(PBRequest *)smsAsync:(NSString *)playerId message:(NSString *)message template:(NSString *)templateId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)smsAsync:(NSString *)playerId message:(NSString *)message tempalte:(NSString *)templateId withBlock:(PBResponseBlock)block;

/**
 Send SMS Coupon to a player via SMS.
 */
-(PBRequest *)smsCoupon:(NSString *)playerId ref:(NSString *)refId message:(NSString *)message withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)smsCoupon:(NSString *)playerId ref:(NSString *)refId message:(NSString *)message withBlock:(PBResponseBlock)block;
-(PBRequest *)smsCouponAsync:(NSString *)playerId ref:(NSString *)refId message:(NSString *)message withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)smsCouponAsync:(NSString *)playerId ref:(NSString *)refId message:(NSString *)message withBlock:(PBResponseBlock)block;

/**
 Send SMS Coupon to a player via SMS with a template-id.
 */
-(PBRequest *)smsCoupon:(NSString *)playerId ref:(NSString *)refId message:(NSString *)message template:(NSString *)templateId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)smsCoupon:(NSString *)playerId ref:(NSString *)refId message:(NSString *)message template:(NSString *)templateId withBlock:(PBResponseBlock)block;
-(PBRequest *)smsCouponAsync:(NSString *)playerId ref:(NSString *)refId message:(NSString *)message template:(NSString *)templateId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)smsCouponAsync:(NSString *)playerId ref:(NSString *)refId message:(NSString *)message template:(NSString *)templateId withBlock:(PBResponseBlock)block;

/**
 Push message.
 */
-(PBRequest *)push:(NSString *)playerId message:(NSString *)message withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)push:(NSString *)playerId message:(NSString *)message withBlock:(PBResponseBlock)block;
-(PBRequest *)pushAsync:(NSString *)playerId message:(NSString *)message withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)pushAsync:(NSString *)playerId message:(NSString *)message withBlock:(PBResponseBlock)block;

/**
 Push message with template id.
 */
-(PBRequest *)push:(NSString *)playerId message:(NSString *)message template:(NSString *)templateId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)push:(NSString *)playerId message:(NSString *)message template:(NSString *)templateId withBlock:(PBResponseBlock)block;
-(PBRequest *)pushAsync:(NSString *)playerId message:(NSString *)message template:(NSString *)templateId withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)pushAsync:(NSString *)playerId message:(NSString *)message template:(NSString *)templateId withBlock:(PBResponseBlock)block;

/**
 Register device for push notification.
 */
-(PBRequest *)registerForPushNotification:(id<PBResponseHandler>)delegate;

/**
 Track player with an action.
 */
-(PBRequest *)track:(NSString *)playerId forAction:(NSString *)action withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)track:(NSString *)playerId forAction:(NSString *)action withBlock:(PBResponseBlock)block;

/**
 Execute action for player.
 */
-(PBRequest *)do:(NSString *)playerId action:(NSString *)action withDelegate:(id<PBResponseHandler>)delegate;
-(PBRequest *)do:(NSString *)playerId action:(NSString *)action withBlock:(PBResponseBlock)block;

@end
