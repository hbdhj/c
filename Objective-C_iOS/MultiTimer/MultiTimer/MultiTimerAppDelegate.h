//
//  MultiTimerAppDelegate.h
//  MultiTimer
//
//  Created by denghaijun on 11-10-8.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@class MultiTimerViewController;

@interface MultiTimerAppDelegate : NSObject <UIApplicationDelegate>

@property (nonatomic, retain) IBOutlet UIWindow *window;

@property (nonatomic, retain) IBOutlet MultiTimerViewController *viewController;

@end
