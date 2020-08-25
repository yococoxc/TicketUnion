//
//  ISearchPagerPresenter.h
//  TicketUnion
//
//  Created by muzico on 2020/8/22.
//  Copyright © 2020 muzico. All rights reserved.
//


#import <Foundation/Foundation.h>

@protocol ISearchPagerPresenter <NSObject>

/**
 搜索
 */
- (void) doSearch:(NSString *)keyword;

/**
 重新搜索
 */
- (void) research;

/**
 获取搜索历史内容
 */
- (void) getHistories;

/**
 删除搜索历史
 */
- (void) deleteHistories;

/**
 获取更多的搜索结果
 */
- (void) loaderMore;

/**
 获取推荐词
 */
- (void) getRecommendWords;

@end
