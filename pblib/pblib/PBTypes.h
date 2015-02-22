//
//  PBTypes.h
//  pblib
//
//  Created by haxpor on 1/22/15.
//  Copyright (c) 2015 Maethee Chongchitnant. All rights reserved.
//

#ifndef pblib_PBTypes_h
#define pblib_PBTypes_h

#import "PBResponses.h"

///----------------
/// Notification string
///----------------
extern NSString *pbNetworkStatusChangedNotification;

///---------------------------------------------
/// @name Delegates and Block Response Handlers
///---------------------------------------------
///----------------
/// Normal
///----------------
@protocol PBResponseHandler <NSObject>
-(void)processResponse:(id)jsonResponse withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBResponseBlock)(id jsonResponse, NSURL* url, NSError *error);

///----------------
/// Async URL Response
///----------------
typedef void (^PBAsyncURLRequestResponseBlock)(PBManualSetResultStatus_Response* status, NSURL* url, NSError *error);

///----------------
/// Result Status Response
///----------------
@protocol PBResultStatus_ResponseHandler <NSObject>
-(void)processResponseWithResultStatus:(PBResultStatus_Response*)result withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBResultStatus_ResponseBlock)(PBResultStatus_Response* result, NSURL* url, NSError *error);

///----------------
/// Auth
///----------------
@protocol PBAuth_ResponseHandler <NSObject>
-(void)processResponseWithAuth:(PBAuth_Response*)auth withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBAuth_ResponseBlock)(PBAuth_Response* auth, NSURL* url, NSError *error);

///----------------
/// PlayerPublic
///----------------
@protocol PBPlayerPublic_ResponseHandler <NSObject>
-(void)processResponseWithPlayerPublic:(PBPlayerPublic_Response*)playerResponse withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBPlayerPublic_ResponseBlock)(PBPlayerPublic_Response *playerResponse, NSURL *url, NSError *error);

///----------------
/// Player
///----------------
@protocol PBPlayer_ResponseHandler <NSObject>
-(void)processResponseWithPlayer:(PBPlayer_Response*)playerResponse withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBPlayer_ResponseBlock)(PBPlayer_Response * player, NSURL *url, NSError *error);

///----------------
/// PlayerList
///----------------
@protocol PBPlayerList_ResponseHandler <NSObject>
-(void)processResponseWithPlayerList:(PBPlayerList_Response*)playerList withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBPlayerList_ResponseBlock)(PBPlayerList_Response * playerList, NSURL *url, NSError *error);

///----------------
/// Point
///----------------
@protocol PBPoint_ResponseHandler <NSObject>
-(void)processResponseWithPoint:(PBPoint_Response*)points withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBPoint_ResponseBlock)(PBPoint_Response * points, NSURL *url, NSError *error);

///----------------
/// Points
///----------------
@protocol PBPoints_ResponseHandler <NSObject>
-(void)processResponseWithPoints:(PBPoints_Response*)points withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBPoints_ResponseBlock)(PBPoints_Response * points, NSURL *url, NSError *error);

///----------------
/// Badge
///----------------
@protocol PBBadge_ResponseHandler <NSObject>
-(void)processResponseWithBadge:(PBBadge_Response*)badge withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBBadge_ResponseBlock)(PBBadge_Response * badge, NSURL *url, NSError *error);

///----------------
/// Badges
///----------------
@protocol PBBadges_ResponseHandler <NSObject>
-(void)processResponseWithBadges:(PBBadges_Response*)badges withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBBadges_ResponseBlock)(PBBadges_Response * badges, NSURL *url, NSError *error);

///----------------
/// PlayerBadge
///----------------
@protocol PBPlayerBadges_ResponseHandler <NSObject>
-(void)processResponseWithPlayerBadges:(PBPlayerBadges_Response*)badges withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBPlayerBadges_ResponseBlock)(PBPlayerBadges_Response * badges, NSURL *url, NSError *error);

///----------------
/// PlayerDetailedPublic
///----------------
@protocol PBPlayerDetailedPublic_ResponseHandler <NSObject>
-(void)processResponseWithPlayerDetailedPublic:(PBPlayerDetailedPublic_Response*)playerDetailedPublic withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBPlayerDetailedPublic_ResponseBlock)(PBPlayerDetailedPublic_Response * playerDetailedPublic, NSURL *url, NSError *error);

///----------------
/// PlayerDetailed
///----------------
@protocol PBPlayerDetailed_ResponseHandler <NSObject>
-(void)processResponseWithPlayerDetailed:(PBPlayerDetailed_Response*)playerDetailed withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBPlayerDetailed_ResponseBlock)(PBPlayerDetailed_Response * playerDetailed, NSURL *url, NSError *error);

///----------------
/// PlayerGoodsOwned
///----------------
@protocol PBPlayerGoodsOwned_ResponseHandler <NSObject>
-(void)processResponseWithPlayerGoodsOwned:(PBPlayerGoodsOwned_Response *)goodsOwneds withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBPlayerGoodsOwned_ResponseBlock)(PBPlayerGoodsOwned_Response * goodsOwneds, NSURL *url, NSError *error);

///----------------
/// PointHistory
///----------------
@protocol PBActionLastPerformedTime_ResponseHandler <NSObject>
-(void)processResponseWithActionLastPerformedTime:(PBActionLastPerformedTime_Response*)response withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBActionLastPerformedTime_ResponseBlock)(PBActionLastPerformedTime_Response * response, NSURL *url, NSError *error);

///----------------
/// PointHistory
///----------------
@protocol PBPointHistory_ResponseHandler <NSObject>
-(void)processResponseWithPointHistory:(PBPointHistory_Response*)pointHistory withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBPointHistory_ResponseBlock)(PBPointHistory_Response * pointHistory, NSURL *url, NSError *error);

///----------------
/// ActionTime
///----------------
@protocol PBActionTime_ResponseHandler <NSObject>
-(void)processResponseWithActionTime:(PBActionTime_Response*)actionTime withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBActionTime_ResponseBlock)(PBActionTime_Response * actionTime, NSURL *url, NSError *error);

///----------------
/// ActionConfig
///----------------
@protocol PBActionConfig_ResponseHandler <NSObject>
-(void)processResponseWithActionConfig:(PBActionConfig_Response*)actionConfigs withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBActionConfig_ResponseBlock)(PBActionConfig_Response * actionConfigs, NSURL *url, NSError *error);

///----------------
/// Rule
///----------------
@protocol PBRule_ResponseHandler <NSObject>
-(void)processResponseWithRule:(PBRule_Response*)response withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBRule_ResponseBlock)(PBRule_Response * response, NSURL *url, NSError *error);

///----------------
/// LastAction
///----------------
@protocol PBLastAction_ResponseHandler <NSObject>
-(void)processResponseWithLastAction:(PBLastAction_Response*)lastAction withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBLastAction_ResponseBlock)(PBLastAction_Response * lastAction, NSURL *url, NSError *error);

///----------------
/// ActionCount
///----------------
@protocol PBActionCount_ResponseHandler <NSObject>
-(void)processResponseWithActionCount:(PBActionCount_Response*)actionCount withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBActionCount_ResponseBlock)(PBActionCount_Response * actionCount, NSURL *url, NSError *error);

///----------------
/// Level
///----------------
@protocol PBLevel_ResponseHandler <NSObject>
-(void)processResponseWithLevel:(PBLevel_Response*)level withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBLevel_ResponseBlock)(PBLevel_Response * level, NSURL *url, NSError *error);

///----------------
/// Levels
///----------------
@protocol PBLevels_ResponseHandler <NSObject>
-(void)processResponseWithLevels:(PBLevels_Response*)levels withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBLevels_ResponseBlock)(PBLevels_Response * levels, NSURL *url, NSError *error);

///----------------
/// Rank
///----------------
@protocol PBRank_ResponseHandler <NSObject>
-(void)processResponseWithRank:(PBRank_Response*)rank withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBRank_ResponseBlock)(PBRank_Response * rank, NSURL *url, NSError *error);

///----------------
/// Ranks
///----------------
@protocol PBRanks_ResponseHandler <NSObject>
-(void)processResponseWithRanks:(PBRanks_Response*)ranks withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBRanks_ResponseBlock)(PBRanks_Response * ranks, NSURL *url, NSError *error);

///----------------
/// GoodsInfo
///----------------
@protocol PBGoodsInfo_ResponseHandler <NSObject>
-(void)processResponseWithGoodsInfo:(PBGoodsInfo_Response*)goodsInfo withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBGoodsInfo_ResponseBlock)(PBGoodsInfo_Response * goodsInfo, NSURL *url, NSError *error);

///----------------
/// GoodsList
///----------------
@protocol PBGoodsListInfo_ResponseHandler <NSObject>
-(void)processResponseWithGoodsListInfo:(PBGoodsListInfo_Response*)goodsListInfo withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBGoodsListInfo_ResponseBlock)(PBGoodsListInfo_Response * goodsListInfo, NSURL *url, NSError *error);

///----------------
/// Goods Group Available
///----------------
@protocol PBGoodsGroupAvailable_ResponseHandler <NSObject>
-(void)processResponseWithGoodsGroupAvailable:(PBGoodsGroupAvailable_Response*)goodsGroupAvailable withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBGoodsGroupAvailable_ResponseBlock)(PBGoodsGroupAvailable_Response * goodsGroupAvailable, NSURL *url, NSError *error);

///----------------
/// QuestOfPlayer
///----------------
@protocol PBQuestOfPlayer_ResponseHandler <NSObject>
-(void)processResponseWithQuestOfPlayer:(PBQuestOfPlayer_Response*)questList withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBQuestOfPlayer_ResponseBlock)(PBQuestOfPlayer_Response * questList, NSURL *url, NSError *error);

///----------------
/// QuestListOfPlayer
///----------------
@protocol PBQuestListOfPlayer_ResponseHandler <NSObject>
-(void)processResponseWithQuestListOfPlayer:(PBQuestListOfPlayer_Response*)quest withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBQuestListOfPlayer_ResponseBlock)(PBQuestListOfPlayer_Response * quest, NSURL *url, NSError *error);

///----------------
/// QuestRewardHistoryOfPlayer
///----------------
@protocol PBQuestRewardHistoryOfPlayer_ResponseHandler <NSObject>
-(void)processResponseWithQuestRewardHistoryOfPlayer:(PBQuestRewardHistoryOfPlayer_Response*)rewards withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBQuestRewardHistoryOfPlayer_ResponseBlock)(PBQuestRewardHistoryOfPlayer_Response * rewards, NSURL *url, NSError *error);

///----------------
/// QuestList
///----------------
@protocol PBQuestList_ResponseHandler <NSObject>
-(void)processResponseWithQuestList:(PBQuestList_Response*)questList withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBQuestList_ResponseBlock)(PBQuestList_Response * questList, NSURL *url, NSError *error);

///----------------
/// Quest Info
///----------------
@protocol PBQuestInfo_ResponseHandler <NSObject>
-(void)processResponseWithQuestInfo:(PBQuestInfo_Response*)questInfo withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBQuestInfo_ResponseBlock)(PBQuestInfo_Response * questInfo, NSURL *url, NSError *error);

///----------------
/// Recent point
///----------------
@protocol PBRecentPoint_ResponseHandler <NSObject>
-(void)processResponseWithRecentPoint:(PBRecentPointArray_Response*)recentPoints withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBRecentPoint_ResponseBlock)(PBRecentPointArray_Response * recentPoints, NSURL *url, NSError *error);

///----------------
/// Mission Info
///----------------
@protocol PBMissionInfo_ResponseHandler <NSObject>
-(void)processResponseWithMissionInfo:(PBMissionInfo_Response*)missionInfo withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBMissionInfo_ResponseBlock)(PBMissionInfo_Response * missionInfo, NSURL *url, NSError *error);

///--------------------------------------
/// QuestListAvailableForPlayer
///--------------------------------------
@protocol PBQuestListAvailableForPlayer_ResponseHandler <NSObject>
-(void)processResponseWithQuestListAvailableForPlayer:(PBQuestListAvailableForPlayer_Response*)list withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBQuestListAvailableForPlayer_ResponseBlock)(PBQuestListAvailableForPlayer_Response * list, NSURL *url, NSError *error);

///--------------------------------------
/// QuestAvailableForPlayer
///--------------------------------------
@protocol PBQuestAvailableForPlayer_ResponseHandler <NSObject>
-(void)processResponseWithQuestAvailableForPlayer:(PBQuestAvailableForPlayer_Response*)available withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBQuestAvailableForPlayer_ResponseBlock)(PBQuestAvailableForPlayer_Response * available, NSURL *url, NSError *error);

///--------------------------------------
/// ActiveQuizList
///--------------------------------------
@protocol PBActiveQuizList_ResponseHandler <NSObject>
-(void)processResponseWithActiveQuizList:(PBActiveQuizList_Response*)activeQuizList withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBActiveQuizList_ResponseBlock)(PBActiveQuizList_Response * activeQuizList, NSURL *url, NSError *error);

///--------------------------------------
/// QuizDetail
///--------------------------------------
@protocol PBQuizDetail_ResponseHandler <NSObject>
-(void)processResponseWithQuizDetail:(PBQuizDetail_Response*)quizDetail withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBQuizDetail_ResponseBlock)(PBQuizDetail_Response * quizDetail, NSURL *url, NSError *error);

///--------------------------------------
/// QuizRandom
///--------------------------------------
@protocol PBQuizRandom_ResponseHandler <NSObject>
-(void)processResponseWithQuizRandom:(PBQuizRandom_Response*)quizRandom withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBQuizRandom_ResponseBlock)(PBQuizRandom_Response * quizRandom, NSURL *url, NSError *error);

///--------------------------------------
/// QuizDoneList
///--------------------------------------
@protocol PBQuizDoneList_ResponseHandler <NSObject>
-(void)processResponseWithQuizDoneList:(PBQuizDoneList_Response*)quizDoneList withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBQuizDoneList_ResponseBlock)(PBQuizDoneList_Response * quizDoneList, NSURL *url, NSError *error);

///--------------------------------------
/// QuestionFromQuiz
///--------------------------------------
@protocol PBQuestion_ResponseHandler <NSObject>
-(void)processResponseWithQuestion:(PBQuestion_Response*)question withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBQuestion_ResponseBlock)(PBQuestion_Response * question, NSURL *url, NSError *error);

///--------------------------------------
/// QuestionAnswered
///--------------------------------------
@protocol PBQuestionAnswered_ResponseHandler <NSObject>
-(void)processResponseWithQuestionAnswered:(PBQuestionAnswered_Response*)questionAnswered withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBQuestionAnswered_ResponseBlock)(PBQuestionAnswered_Response * questionAnswered, NSURL *url, NSError *error);

///--------------------------------------
/// PlayersQuizRank
///--------------------------------------
@protocol PBPlayersQuizRank_ResponseHandler <NSObject>
-(void)processResponseWithPlayersQuizRank:(PBPlayersQuizRank_Response*)playersQuizRank withURL:(NSURL *)url error:(NSError*)error;
@end

typedef void (^PBPlayersQuizRank_ResponseBlock)(PBPlayersQuizRank_Response * playersQuizRank, NSURL *url, NSError *error);

#endif
