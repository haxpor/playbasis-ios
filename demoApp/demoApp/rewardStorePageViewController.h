//
//  rewardStorePageViewController.h
//  demoApp
//
//  Created by haxpor on 2/16/15.
//  Copyright (c) 2015 Maethee Chongchitnant. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Playbasis.h"

@interface rewardStorePageViewController : UIPageViewController <UIPageViewControllerDataSource, UIPageViewControllerDelegate, UIAlertViewDelegate>

@property (strong, nonatomic) PBGoodsListInfo_Response *goodsListInfo;
@property (strong, nonatomic) NSMutableArray *goodsListInfoImages;
@end
