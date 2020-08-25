//
//  UIViewController+LQS.h
//  LQSKit
//
//  Created by muzico on 2018/7/20.
//  Copyright © 2018年 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LQSPredefined.h"

@interface UIViewController (LQS)

@property(nonatomic,assign) BOOL lqs_hasBoxController;

/**
 获取最后一个弹出控制器
 2020-07-11
 */
@property(nonatomic,readonly) UIViewController *lqs_lastPresentedViewController;



@property(nonatomic,copy) LQSCallbackEmptyBlock lqs_dismissedBlock;


- (void) lqs_setupWithViewController:(void(^)(UIViewController* viewController))aBlock;


- (instancetype) lqs_initWithNib;
- (instancetype) lqs_initWithNibName:(NSString *)nibNameOrNil;

+ (instancetype) lqs_controllerWithNib;
+ (instancetype) lqs_controllerWithNibName:(NSString*)nibNameOrNil;

/**
 仅仅适用于 LQSBoxController 所持有的对象。
 */
- (void) lqs_boxControllerWithBoxViewReloadLayout;

- (void) lqs_boxControllerWithFillView:(UIView *)view;

- (UIViewController *) lqs_lastPresentedViewController;


+ (instancetype) lqs_createWithTabBarItemBlock:(void(^)(UITabBarItem *item))aBlock;

@end


@interface UIViewController (LQS_iPad_Popover)

/**
 箭头颜色，实际上就是 UIPopoverPresentationController 的 backgroundColor值。
 */

- (void) lqs_presentationPopoverWithSize:(CGSize)size sourceView:(UIView *)sourceView arrowDirections:(UIPopoverArrowDirection)arrowDirections;
- (void) lqs_presentationPopoverWithSize:(CGSize)size sourceView:(UIView *)sourceView sourceRect:(CGRect)sourceRect arrowDirections:(UIPopoverArrowDirection)arrowDirections;
- (void) lqs_presentationPopoverWithSize:(CGSize)size sourceView:(UIView *)sourceView arrowDirections:(UIPopoverArrowDirection)arrowDirections arrowColor:(UIColor *)arrowColor;
- (void) lqs_presentationPopoverWithSize:(CGSize)size sourceView:(UIView *)sourceView sourceRect:(CGRect)sourceRect arrowDirections:(UIPopoverArrowDirection)arrowDirections arrowColor:(UIColor *)arrowColor;
- (void) lqs_presentationPopover:(void(^)(UIPopoverPresentationController *presentationController))aBlock withSize:(CGSize)size;

@end
