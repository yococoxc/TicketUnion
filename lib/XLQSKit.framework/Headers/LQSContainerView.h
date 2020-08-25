//
//  LQSContainerView.h
//  LQSKit
//
//  Created by muzico on 2019/1/2.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>

@class LQSContainerView;

typedef void(^LQSContainerViewBlock)(LQSContainerView *view);

@interface LQSContainerView : UIView

/**
 用法同 reloadLayout 方法。
 但优先级会比 reloadLayoutByLayoutSubviews 方法低。即会先调用 reloadLayoutByLayoutSubviews 方法，再调用该对象。
 实际上，reloadLayoutByLayoutSubviewsBlock 在 layoutSubviews 中执行。
 */
@property (nonatomic, copy) LQSContainerViewBlock reloadLayoutByLayoutSubviewsBlock;

/**
 用法同 reloadLayout 方法。
 但优先级会比 reloadLayout 方法低。即会先调用 reloadLayout 方法，再调用该对象。
 */
@property (nonatomic, copy) LQSContainerViewBlock reloadLayoutBlock;

/**
 当 View 的 frame、bounds 发生改变时，即需要重新布局时，则会调用该方法。
 */
- (void) reloadLayout;

/**
 用法同 reloadLayout 方法。
 与 reloadLayoutByLayoutSubviewsBlock 同一个处理动作。
 */
- (void) reloadLayoutByLayoutSubviews;


/**
 初始化类的时候会调用。
 */
- (void) setupWithInitialization;

/**
 加载内容视图，相当于 [self addSubview:view]，当然还包括内容视图管理，自动布局，与 self 同样大小。
 */
- (void) loadingContentView:(UIView *)view;

/**
 移除内容视图，相当于 [view removeFromSuperview]，当然还包括从内容视图管理中移除。
 */
- (void) removeContentView:(UIView *)view;

@end
