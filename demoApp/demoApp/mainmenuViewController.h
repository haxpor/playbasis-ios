//
//  mainmenuViewController.h
//  demoApp
//
//  Created by haxpor on 1/27/15.
//  Copyright (c) 2015 Maethee Chongchitnant. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Playbasis.h"

@interface mainmenuViewController : UIViewController<PBNetworkStatusChangedDelegate>
{
    // cache the result from goodsList
    PBGoodsListInfo_Response *goodsListInfo_;
}

@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;

@end
