//
//  SearchPagePresenterImpl.m
//  TicketUnion
//
//  Created by muzico on 2020/8/21.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "SearchPagePresenterImpl.h"

#import "ISearchPageCallback.h"


@interface SearchPagePresenterImpl ()

@property(nonatomic,assign) NSInteger currentPage;
@property(nonatomic,copy) NSString *keyword;
@property(nonatomic,assign) BOOL isLoadingMore;

@end

@implementation SearchPagePresenterImpl


#pragma mark - ISearchPagerPresenter
- (void) doSearch:(NSString *)keyword {
    if ([keyword lqs_isNSString] == NO) {
        return;
    }
    
    
    
    [self saveWithHistories:keyword];
    
    
    
    LQSWeakSelf
    self.keyword = keyword;
    self.currentPage = 1;
    NSString *pageString = [NSString stringWithFormat:@"%ld",self.currentPage];
    LQSRequestModel *task = [self.mApi doSearchWithKeyword:self.keyword page:pageString];
    task.success(^(LQSRequestBean *bean) {
        if (bean.coreHttpResponseStatusCode == 200) {
            [weakSelf handlerLoaderSuccess:[bean.data lqs_jsonQuery:@"tbk_dg_material_optional_response/result_list/map_data"]];
//            [weakSelf onRecommendWordsLoadSuccess:bean.data];
        } else {
//            [weakSelf onRecommendWordsLoadError];
        }
    }).failure(^(NSError *error, BOOL isServerError, LQSRequestBean *bean) {
//        [weakSelf onRecommendWordsLoadError];
    }).request();
}

- (void) loaderMore {
    if (self.isLoadingMore) {
        return;
    }
    self.isLoadingMore = YES;
    
    LQSWeakSelf
    self.currentPage++;
    NSString *pageString = [NSString stringWithFormat:@"%ld",self.currentPage];
    LQSRequestModel *task = [self.mApi doSearchWithKeyword:self.keyword page:pageString];
    task.success(^(LQSRequestBean *bean) {
        if (bean.coreHttpResponseStatusCode == 200) {
            [weakSelf handlerLoaderMoreSuccess:bean.data];
            
        } else {
            weakSelf.currentPage--;
//            [weakSelf onRecommendWordsLoadError];
        }
    }).failure(^(NSError *error, BOOL isServerError, LQSRequestBean *bean) {
        weakSelf.currentPage--;
//        [weakSelf onRecommendWordsLoadError];
    }).request();
}


- (void) research {
    
}

- (void) getHistories {
    NSArray *array = [LQSStore getWithStringToMD5:@"历史记录"];
    if ([array lqs_isNSArray]) {
        for (id<ISearchPageCallback> callback in self.callbacks) {
            [callback onHistoriesLoaded:array];
        }
    } else {
        for (id<ISearchPageCallback> callback in self.callbacks) {
//            [callback on];
            [callback onHistoriesLoaded:[NSArray array]];
        }
    }
}

- (void) deleteHistories {
    
}

- (void) getRecommendWords {
    LQSWeakSelf
    
    LQSRequestModel *task = [self.mApi getSearchRecommend];
    task.success(^(LQSRequestBean *bean) {
        if (bean.coreHttpResponseStatusCode == 200) {
            [weakSelf onRecommendWordsLoadSuccess:bean.data];
        } else {
            [weakSelf onRecommendWordsLoadError];
        }
    }).failure(^(NSError *error, BOOL isServerError, LQSRequestBean *bean) {
        [weakSelf onRecommendWordsLoadError];
    }).request();
}


#pragma mark - private
- (void) saveWithHistories:(NSString *)keyword {
    NSArray *array = [LQSStore getWithStringToMD5:@"历史记录"];
    
    NSMutableArray *keepArray = [NSMutableArray array];
    if ([array lqs_isNSArray]) {
        [keepArray addObjectsFromArray:array];
    }
    
    if ([keepArray lqs_containString:keyword] == NO) {
        [keepArray insertObject:keyword atIndex:0];
        [LQSStore setWithStringToMD5:@"历史记录" withObject:keepArray];
    } else {
        [keepArray removeObject:keyword];
        [keepArray insertObject:keyword atIndex:0];
        [LQSStore setWithStringToMD5:@"历史记录" withObject:keepArray];
    }
    
    [self getHistories];
}

- (void) onRecommendWordsLoadError {
    for (id<ISearchPageCallback> callback in self.callbacks) {
        [callback onRecommendWordLoadError];
    }
}
- (void) onRecommendWordsLoadSuccess:(id)result {
    for (id<ISearchPageCallback> callback in self.callbacks) {
        [callback onRecommenWordsLoaded:result];
    }
}

- (void) handlerLoaderSuccess:(id)result {
    for (id<ISearchPageCallback> callback in self.callbacks) {
        [callback onSearchResultLoaded:result];
    }
}

- (void) handlerLoaderFailure {
    for (id<ISearchPageCallback> callback in self.callbacks) {
//        [callback onload];
    }
}

- (void) handlerLoaderMoreSuccess:(id)result {
    for (id<ISearchPageCallback> callback in self.callbacks) {
        [callback onLoaderMote:result];
    }
}

- (void) handlerLoaderMoreFailure {
    
}

@end
