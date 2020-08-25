//
//  OnSellPagePresenterImpl.m
//  TicketUnion
//
//  Created by muzico on 2020/8/21.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "OnSellPagePresenterImpl.h"
#import "IOnSellPageCallback.h"
#import "UrlUtils.h"

@interface OnSellPagePresenterImpl ()

@property(nonatomic,readonly) NSInteger defaultPage;
@property(nonatomic,assign) NSInteger mCurrentPage;
@property(nonatomic,assign) BOOL mIsLoading;
@property(nonatomic,assign) BOOL mIsLoadingMore;

@end


@implementation OnSellPagePresenterImpl



#pragma mark - IOnSellPagePresenter
- (void) getOnSellContent {
    if (self.mIsLoading) {
        return;
    }
    self.mIsLoading = YES;
    
    //通知UI状态为加载中..
//    if (self.mOnSellPageCallback) {
//        [self.mOnSellPageCallback onLoading];
//    }
    
    //获取特惠内容
    self.mCurrentPage = self.defaultPage;
    NSString *pageString = [NSString stringWithFormat:@"%ld",self.mCurrentPage];
    NSString *targetURL = [UrlUtils getOnSellUrlWithDefaultPage:pageString];
    
    LQSWeakSelf
    LQSRequestModel *task = [self.mApi getOnSellGoodsWithURL:targetURL];
    task.success(^(LQSRequestBean *bean) {
        if (bean.coreHttpResponseStatusCode == 200) {
            NSArray *result = [bean.data lqs_jsonQuery:@"tbk_dg_optimus_material_response/result_list/map_data"];
            [weakSelf handlerContentResult:result];
            weakSelf.mIsLoading = NO;
        } else {
            [weakSelf handlerLoadedFailure];
            weakSelf.mIsLoading = NO;
        }
    }).failure(^(NSError *error, BOOL isServerError, LQSRequestBean *bean) {
        [weakSelf handlerLoadedFailure];
    }).request();
    
}

- (void) loaderMore {
    if (self.mIsLoadingMore) {
        return;
    }
    self.mIsLoadingMore = YES;
    
    self.mCurrentPage++;
    
    //加载更多内容
    NSString *pageString = [NSString stringWithFormat:@"%ld",self.mCurrentPage];
    NSString *targetURL = [UrlUtils getOnSellUrlWithDefaultPage:pageString];
    
    LQSWeakSelf
    LQSRequestModel *task = [self.mApi getOnSellGoodsWithURL:targetURL];
    task.success(^(LQSRequestBean *bean) {
        
        if (bean.coreHttpResponseStatusCode == 200) {
            NSArray *result = [bean.data lqs_jsonQuery:@"tbk_dg_optimus_material_response/result_list/map_data"];
            [weakSelf handlerContentResult:result];
            weakSelf.mIsLoadingMore = NO;
        } else {
            [weakSelf handleLoaderMoreError];
            weakSelf.mIsLoadingMore = NO;
            weakSelf.mCurrentPage--;
        }
    }).failure(^(NSError *error, BOOL isServerError, LQSRequestBean *bean) {
        [weakSelf handleLoaderMoreError];
        weakSelf.mIsLoadingMore = NO;
        weakSelf.mCurrentPage--;
    }).request();
}

- (void) reload {
    //重新加载
    [self getOnSellContent];
}


#pragma mark -
- (void) onLoading {
    for (id<IBaseViewCallback> callback in self.callbacks) {
        [callback onLoading];
    }
}
- (void) onEmpty {
    for (id<IBaseViewCallback> callback in self.callbacks) {
        [callback onEmpty];
    }
}
- (void) onError {
    for (id<IBaseViewCallback> callback in self.callbacks) {
        [callback onError];
    }
}


#pragma mark -
- (void) handlerContentResult:(id)result {
    if (result == nil || [result lqs_length] == 0) {
        for (id<IOnSellPageCallback> callback in self.callbacks) {
            [callback onEmpty];
        }
    } else {
        for (id<IOnSellPageCallback> callback in self.callbacks) {
            [callback onSellContentLoaded:result];
        }
    }
}

- (void) handlerLoadedFailure {
    for (id<IOnSellPageCallback> callback in self.callbacks) {
        [callback onError];
    }
}

- (void) handlerLoaderMore:(id)result {
    if (result == nil || [result lqs_length] == 0) {
        for (id<IOnSellPageCallback> callback in self.callbacks) {
            [callback onLoaderMoreEmpty];
        }
    } else {
        for (id<IOnSellPageCallback> callback in self.callbacks) {
            [callback onLoaderMoreResult:result];
        }
    }
}

- (void) handleLoaderMoreError {
    for (id<IOnSellPageCallback> callback in self.callbacks) {
        [callback onLoaderMoreError];
    }
}

#pragma mark -
- (NSInteger) defaultPage {
    return 1;
}


@end
