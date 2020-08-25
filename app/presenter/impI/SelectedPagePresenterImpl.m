//
//  SelectedPagePresenterImpl.m
//  TicketUnion
//
//  Created by muzico on 2020/8/21.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "SelectedPagePresenterImpl.h"
#import "UrlUtils.h"
#import "ISelectedPageCallback.h"

@implementation SelectedPagePresenterImpl

#pragma mark - ISelectedPagePresenter
- (void) getPickType {
    [self onLoading];
    
    LQSRequestModel *task = [self.mApi getPickTypeList];
    task.success(^(LQSRequestBean *bean) {
        if (bean.coreHttpResponseStatusCode == 200) {
            NSArray *arr = bean.data;
            if ([arr isKindOfClass:[NSArray class]]) {
                [self handlerPickerTypeResult:arr];
            }
        } else {
            
        }
    }).failure(^(NSError *error, BOOL isServerError, LQSRequestBean *bean) {
        [self handlerFailure];
    }).request();
}

- (void) getPickContentById:(NSString *)categoryId {
    if (categoryId == nil) {
        return;
    }
    NSString *url = [UrlUtils getTypContentUrlWithCategoryId:categoryId];
    LQSRequestModel *task = [self.mApi getPickContentListWithURL:url];
    task.success(^(LQSRequestBean *bean) {
        if (bean.coreHttpResponseStatusCode == 200) {
            NSArray *arr = [bean.data lqs_jsonQuery:@"tbk_uatm_favorites_item_get_response/results/uatm_tbk_item"];
            if ([arr isKindOfClass:[NSArray class]]) {
                [self handleContentList:arr];
            }
        } else {
            
        }
    }).failure(^(NSError *error, BOOL isServerError, LQSRequestBean *bean) {
        [self handlerFailure];
    }).request();
}

#pragma mark -
- (void) reload {
    [self getPickType];
}

#pragma mark -
- (void) onLoading {
    for (id<IBaseViewCallback> callback in self.callbacks) {
        [callback onLoading];
    }
}
- (void) handlerFailure {
    for (id<IBaseViewCallback> callback in self.callbacks) {
        [callback onError];
    }
}
- (void) handlerPickerTypeResult:(id)result {
    if (result == nil || [result lqs_length] == 0) {
        for (id<IBaseViewCallback> callback in self.callbacks) {
            [callback onEmpty];
        }
    } else {
        for (id<ISelectedPageCallback> callback in self.callbacks) {
            [callback onPickTypeLoaded:result];
        }
    }
}
- (void) handleContentList:(id)result {
    if (result == nil || [result lqs_length] == 0) {
        for (id<IBaseViewCallback> callback in self.callbacks) {
            [callback onEmpty];
        }
    } else {
        for (id<ISelectedPageCallback> callback in self.callbacks) {
            [callback onContentListLoaded:result];
        }
    }
}



@end
