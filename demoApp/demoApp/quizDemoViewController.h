//
//  quizDemoViewController.h
//  demoApp
//
//  Created by haxpor on 1/27/15.
//  Copyright (c) 2015 Maethee Chongchitnant. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface quizDemoViewController : UIViewController
{
    NSDictionary *quizJsonResponse;
    UIImage *cachedQuizImage;
}

/**
 Testcases included here in this method.
 */
-(void)testcases;

/**
 Load a quiz.
 */
-(void)loadQuizAsync;

@end
