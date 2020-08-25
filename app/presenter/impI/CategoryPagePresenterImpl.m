//
//  CategoryPagePresenterImpl.m
//  TicketUnion
//
//  Created by muzico on 2020/8/21.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "CategoryPagePresenterImpl.h"
#import "UrlUtils.h"

#import "ICategoryPagerCallback.h"


@interface CategoryPagePresenterImpl ()

@property(nonatomic,assign) NSInteger currentPage;

@property(nonatomic,assign) BOOL isLoadingMore;

@end


@implementation CategoryPagePresenterImpl


#pragma mark - ICategoryPagePresenter
- (void) getCategoryContentById:(NSString *)categoryId {
    if ([categoryId lqs_isNSString] == NO) {
        return;
    }
    
    self.currentPage = 1;
    NSString *page = [NSString stringWithFormat:@"%ld",self.currentPage];
    NSString *url = [UrlUtils getDiscoveryContentUrlWithCategoryId:categoryId withPage:page];
    LQSRequestModel *task = [self.mApi getContentListByMaterialIdWithURL:url];
    task.success(^(LQSRequestBean *bean) {
        
        if (bean.coreHttpResponseStatusCode == 200) {
            [self handlerContentResponseWithResult:bean.data withCategoryId:categoryId];
        } else {
            
        }
    }).failure(^(NSError *error, BOOL isServerError, LQSRequestBean *bean) {
        [self handlerFailure:categoryId];
    }).request();
}

- (void) loaderMore:(NSString *)categoryId {
    if (self.isLoadingMore) {
        return;
    }
    self.isLoadingMore = YES;
}

- (void) reload:(NSString *)categoryId {
    
}



#pragma mark - private
- (id) createTaskWithCategoryId:(NSString *)categoryId withTargetPage:(NSString *)targetPage {
    NSString *url = [UrlUtils getDiscoveryContentUrlWithCategoryId:categoryId withPage:targetPage];
    return [self.mApi getContentListByMaterialIdWithURL:url];
}
- (void) onLoadingWithCategoryId:(NSString *)categoryId {
    
}

- (void) onLoading:(NSString *) categoryId {

}

- (void) handlerContentResponseWithResult:(id)result withCategoryId:(NSString *)categoryId {
    NSArray *arr = [result lqs_subarrayWithRange:NSMakeRange([result lqs_length]-5, 5)];
    
    for (id<ICategoryPagerCallback>callback in self.callbacks) {
        [callback onContentLoaded:result];
        [callback onLooperListLoaded:arr];
    }
}
- (void) handlerLoaderMoreSuccessWithResult:(id)result withCategoryId:(NSString *)categoryId {
    
}
- (void) handlerLoaderMoreError:(NSString *) categoryId {

}
- (void) handlerFailure:(NSString *)categoryId {

}


@end
