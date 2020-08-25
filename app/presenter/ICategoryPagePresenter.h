//
//  ICategoryPagePresenter.h
//  TicketUnion
//
//  Created by muzico on 2020/8/21.
//  Copyright © 2020 muzico. All rights reserved.
//


#import <Foundation/Foundation.h>
@protocol ICategoryPagePresenter <NSObject>

/**
 下拉刷新更多
 */
- (void) getCategoryContentById:(NSString *)categoryId;

/**
 加载更多内容
 */
- (void) loaderMore:(NSString *)categoryId;

/**
 加载更多内容
 */
- (void) reload:(NSString *)categoryId;



@end
