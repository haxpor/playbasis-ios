//
//  PBRequest.h
//  pblib
//
//  Created by haxpor on 1/22/15.
//  Copyright (c) 2015 Maethee Chongchitnant. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PBTypes.h"
#import "PBResponses.h"
#import "JSONKit.h"

typedef enum
{
    ReadyToStart,
    Started,
    ResponseReceived,
    ReceivingData,
    FinishedWithError,
    Finished
}
PBRequestState;

@interface PBRequest : NSObject
{
    NSURLRequest *urlRequest;
    NSMutableData *receivedData;
    NSDictionary *jsonResponse;
    PBRequestState state;
    BOOL isBlockingCall;
    
    pbResponseType responseType;
    
    // either one or another
    id<PBResponseHandler> responseDelegate;
    PBResponseBlock responseBlock;
}

@property PBRequestState state;
@property (nonatomic, readonly) BOOL isBlockingCall;

-(id)initWithURLRequest:(NSURLRequest *)request blockingCall:(BOOL)blockingCall responseType:(pbResponseType)_responseType andDelegate:(id<PBResponseHandler>)delegate;
-(id)initWithURLRequest:(NSURLRequest *)request blockingCall:(BOOL)blockingCall responseType:(pbResponseType)_responseType andBlock:(PBResponseBlock)block;
-(id)initWithCoder:(NSCoder*)decoder;
-(void)encodeWithCoder:(NSCoder*)encoder;
-(void)dealloc;
-(PBRequestState)getRequestState;
-(NSDictionary *)getResponse;

/**
 Start its internal request. This sends request over network.
 */
-(void)start;
@end
