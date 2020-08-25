//
// Created by muzico on 2020/8/22.
// Copyright (c) 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IBaseViewCallback.h"

@protocol ISearchPageCallback <IBaseViewCallback>

/**
 搜索成功
 */
- (void) onSearchResultLoaded:(id)result;
/**
 加载更多内容
 */
- (void) onLoaderMote:(id)result;

/**
加载更多内容出错
*/
- (void) onLoaderMoreError;

/**
 没有更多内容
 */
- (void) onLoaderEmpty;

/**
搜索历史
*/
- (void) onHistoriesLoaded:(id)histories;
/**
推荐词获取结果
*/
- (void) onRecommenWordsLoaded:(id)recommendWord;
/**
推荐词获取结果出错
*/
- (void) onRecommendWordLoadError;

@end
