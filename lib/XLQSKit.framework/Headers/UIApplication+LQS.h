//
//  UIApplication+LQS.h
//  LQSKit
//
//  Created by muzico on 2019/10/10.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 用法：（一般都应该懂吧）
 [UIApplication sharedApplication]
 然后获取属性、方法。
 */

@interface UIApplication (LQS)

@property(readonly) UIWindow *lqs_keyWindow;

@property(readonly) UIViewController *lqs_rootViewController;

@property(readonly) UIViewController *lqs_lastPresentedViewController;


/**
状态栏管理器：位置大小、是否隐藏、风格
iOS 13开始使用。
*/
@property(readonly) id /* UIStatusBarManager * */lqs_keyWindowSceneStatusBarManager;

/**
 状态栏位置大小
 iOS 13
 lqs_keyWindowSceneStatusBarManager.statusBarFrame
 iOS 13以下：
 [self statusBarFrame]
 */
@property(readonly) CGRect lqs_statusBarFrame;
/**
 状态栏是否隐藏
 iOS 13：
 lqs_keyWindowSceneStatusBarManager.isStatusBarHidden
 iOS 13以下：
 [self isStatusBarHidden]
*/
@property(readonly) BOOL lqs_isStatusBarHidden;
/**
 状态栏风格
 iOS 13：
 lqs_keyWindowSceneStatusBarManager.statusBarStyle
 iOS 13以下：
 [self statusBarStyle]
*/
@property(readonly) UIStatusBarStyle lqs_statusBarStyle;


/**
 获取当前设备方向。
 by2020-07-17
 */
@property(readonly) UIInterfaceOrientation lqs_interfaceOrientation;
/**
判断设备方向是否为 Landscape。
by2020-07-17
*/
@property(readonly) BOOL lqs_interfaceOrientationIsLandscape;

@end

