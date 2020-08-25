//
//  LQSAppManager.h
//  LQSKit
//
//  Created by muzico on 2019/12/17.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface LQSAppManager : NSObject

+ (instancetype) shared;

@property(nonatomic,readonly) UIWindow *window;
@property(nonatomic,readonly) UIViewController *rootViewController;

- (void) presentViewController:(UIViewController *)viewController;

- (void) pushViewController:(UIViewController *)viewController;

- (void) popViewController;
- (void) popToRootViewController;

@end

