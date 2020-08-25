//
//  LQSControllerContainerFixController.h
//  LQSKit
//
//  Created by muzico on 2019/12/17.
//  Copyright © 2019 muzico. All rights reserved.
//

#import "LQSFixController.h"
#import "LQSMenuScrollPageView.h"
@class LQSFixController;
@class LQSControllerContainerFixController;


@interface LQSControllerContainerFixController : LQSFixController<LQSMenuScrollPageViewSource,LQSMenuScrollPageViewDelegate>

@property(nonatomic,strong) NSArray<UIViewController *> *viewControllers;

/**
 字典，key为 name，value 就是要显示的内容。
 字符串，直接显示的内容。
 */
@property(nonatomic,strong) NSArray *menuDataSource;

@property(nonatomic,assign) NSUInteger selectedIndex;

@property(nonatomic,readonly) UIViewController *currentViewController;


/**
 默认
 menuScrollPageView.menu.style 为 LQSMenuStyleFixedWidthDefault
 menuHeight 为 44
 */
@property(nonatomic,strong) LQSMenuScrollPageView* menuScrollPageView;


/**
 menuDataSource
 viewControllers
 数据变更，调用 reloadData 刷新数据。
 */
- (void) reloadData;

/**
 *  重写下面的方法。
 */
- (void) lqsControllerContainerFixController:(LQSControllerContainerFixController *)vcContainer lqsMenuScrollPageView:(LQSMenuScrollPageView *)view didSelectOrScrollToIndex:(NSInteger)index;

@end

