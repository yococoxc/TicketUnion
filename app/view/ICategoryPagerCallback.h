//
// Created by muzico on 2020/8/22.
// Copyright (c) 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IBaseViewCallback.h"

@protocol ICategoryPagerCallback <IBaseViewCallback>


@required
/**
 * 数据加载加回来
 */
- (void) onContentLoaded:(NSArray *)contents;

- (NSString *) getCategoryId;

/**
加更多时网络错误
 */
- (void) onLoaderMoreError;

/**
没有更多内容
 */
- (void) onLoaderMoreEmpty;

/**
加到了更多内容
 */
- (void) onLoaderMoreLoaded:(NSArray *)contents;

/**
轮播图内容加载到了
 */
- (void) onLooperListLoaded:(NSArray *)contents;

@end
