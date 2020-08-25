//
//  LQSShrinkMenuScrollPageView.h
//  XLQSKit
//
//  Created by muzico on 2020/8/24.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LQSShrinkView.h"
#import "LQSMenu.h"
#import "LQSScrollPageView.h"

@class LQSShrinkMenuScrollPageView;

@protocol LQSShrinkMenuScrollPageViewDelegate <NSObject>

@optional
/**
 请通过这个方法获取 scrollPage 上的 scrollView 对象，将其绑定到 shrinkMenuScrollPageView.scrollView。
 */
- (void) lqsShrinkMenuScrollPageView:(LQSShrinkMenuScrollPageView *)shrinkMenuScrollPageView scrollWithIndex:(NSUInteger)index withScrollPage:(id)scrollPage;

@end



@interface LQSShrinkMenuScrollPageView : LQSShrinkView<LQSMenuDataSource,LQSMenuDelegate,LQSScrollPageViewDataSource,LQSScrollPageViewDelegate>

@property(nonatomic,strong) LQSMenu *menu;

@property(nonatomic,strong) LQSScrollPageView *scrollPageView;


@property(nonatomic,weak) id<LQSShrinkMenuScrollPageViewDelegate> delegate;



@property(nonatomic,strong) NSArray *menuDataSource;

@property(nonatomic,strong) NSArray *scrollPageDataSource;


/**
 如果 menuDataSource 的内容是字典的话，可以通过该属性指定key 来获取内容。
 默认值为 name
 */
@property(nonatomic,strong) NSString *menuDataSourceKey;

- (void) reloadData;

@end

