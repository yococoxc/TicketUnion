//
//  LQSCustomRootController.h
//  XLQSKit
//
//  Created by muzico on 2020/7/15.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface LQSCustomRootController : NSObject

+ (UIViewController *) rootViewControllerClass:(Class)viewControllerClass scene:(id/*UIScene **/)scene toWindow:(UIWindow *)window;

/**
 默认 navigationBarHidden 为 YES。
 
 */
+ (UINavigationController *) navgationControllerWithRootViewControllerClass:(Class)viewControllerClass scene:(id/*UIScene **/)scene toWindow:(UIWindow *)window;


+ (UINavigationController *) navgationControllerClass:(Class)navgationControllerClass withRootViewControllerClass:(Class)viewControllerClass scene:(id/*UIScene **/)scene toWindow:(UIWindow *)window;





/**
 这个不会考虑 scene 的问题，适合于 scene 早期的项目。
 */
+ (UINavigationController *) navgationControllerClass:(Class)navgationControllerClass withRootViewControllerClass:(Class)viewControllerClass toWindow:(UIWindow *)window;

@end
