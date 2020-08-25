//
// Created by muzico on 2020/8/22.
// Copyright (c) 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IBaseViewCallback.h"

@protocol IOnSellPageCallback <IBaseViewCallback>

- (void) onSellContentLoaded:(id)result;

/**
 加载更多的结果
 */
- (void) onLoaderMoreResult:(id)result;

/**
 加载更多失败，提示用户稍后充实，不能切换到网络错误的界面，要不原来的数据就不了，用户懵逼。
 */
- (void) onLoaderMoreError;


/**
 没有更多数据了，给出提示，并且禁止加载更多的UI功能。
 */
- (void) onLoaderMoreEmpty;

@end