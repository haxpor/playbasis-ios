//
//  rewardStoreLoadingPageViewController.m
//  demoApp
//
//  Created by haxpor on 2/25/15.
//  Copyright (c) 2015 Maethee Chongchitnant. All rights reserved.
//

#import "rewardStoreLoadingPageViewController.h"
#import "rewardStorePageViewController.h"

@interface rewardStoreLoadingPageViewController ()

-(void)loadGoodsListInfo;

@end

@implementation rewardStoreLoadingPageViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.goodsInfoListNotAvailableLabel.hidden = YES;
    self.errorLabel.hidden = YES;
    
    // begin loading goods-info list
    // simiulate touching on the button
    [self checkForGoodsInfoList:self];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    
}

#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
    if([[segue identifier] isEqualToString:@"showRewardStorePageViewController"])
    {
        // get reward-store
        rewardStorePageViewController *rewardStore = [segue destinationViewController];
        
        // set result of goodslist back to reward-store
        rewardStore.goodsList = _goodsListInfo;
    }
}


-(void)loadGoodsListInfo
{
    dispatch_async(dispatch_get_main_queue(), ^{
        // show hud
        [[Playbasis sharedPB] showHUDFromView:self.view withText:@"Loading"];
        
        // hide all texts
        self.goodsInfoListNotAvailableLabel.hidden = YES;
        self.errorLabel.hidden = YES;
    });
    
    // load goods-list in non-blocking way
    [[Playbasis sharedPB] goodsListAsyncWithBlock:^(PBGoodsListInfo_Response *goodsListInfo, NSURL *url, NSError *error) {
        if(!error)
        {
            NSLog(@"%@", goodsListInfo);
            
            // save response
            _goodsListInfo = goodsListInfo;
            
            // there's no available goods to list
            if(goodsListInfo.goodsList == nil ||
               [goodsListInfo.goodsList count] <= 0)
            {
                dispatch_async(dispatch_get_main_queue(), ^{
                    // hide hud
                    [[Playbasis sharedPB] hideHUDFromView:self.view];
                    // show goods info not available text
                    self.goodsInfoListNotAvailableLabel.hidden = NO;
                });
            }
            else
            {
                dispatch_async(dispatch_get_main_queue(), ^{
                    // hide hud
                    [[Playbasis sharedPB] hideHUDFromView:self.view];
                });
                
                // transition to reward store page via segue
                [self performSegueWithIdentifier:@"showRewardStorePageViewController" sender:self];
            }
        }
        else
        {
            NSLog(@"%@", error);
            
            dispatch_async(dispatch_get_main_queue(), ^{
                // hide hud
                [[Playbasis sharedPB] hideHUDFromView:self.view];
                // show error text
                self.errorLabel.hidden = NO;
            });
        }
    }];
}

- (IBAction)checkForGoodsInfoList:(id)sender {
    [self loadGoodsListInfo];
}
@end
