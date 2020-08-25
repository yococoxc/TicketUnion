//
//  TicketPresenterImpl.m
//  TicketUnion
//
//  Created by muzico on 2020/8/21.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "TicketPresenterImpl.h"
#import "UrlUtils.h"
#import "ITicketCallback.h"


@interface TicketPresenterImpl ()

@property(nonatomic,copy) NSString *mCover;

@end


@implementation TicketPresenterImpl

#pragma mark - ITicketPresenter
- (void) loadTicketByItemWithURL:(NSString *)url withTitle:(NSString *)title withCover:(NSString *)cover {
    self.mCover = cover;
    
    NSMutableDictionary *dic = [NSMutableDictionary dictionary];
    [dic lqs_setObject:url forKey:@"url"];
    [dic lqs_setObject:title forKey:@"title"];
    
    LQSRequestModel *task = [self.mApi getTicketByUrl:dic];
    task.success(^(LQSRequestBean *bean) {
        if (bean.coreHttpResponseStatusCode == 200) {
            [self updateUiWithResponse:bean.data];
        } else {
            
        }
    }).failure(^(NSError *error, BOOL isServerError, LQSRequestBean *bean) {
        [self handlerFailure];
    }).request();
}

#pragma mark - Priavte
- (void) handlerFailure {
    for (id<IBaseViewCallback> callback in self.callbacks) {
        [callback onError];
    }
}
- (void) updateUiWithResponse:(id) result {
    for (id<ITicketCallback> callback in self.callbacks) {
        [callback onTicketLoadedWithResult:[result lqs_jsonQuery:@"tbk_tpwd_create_response/data/model"] withCover:self.mCover];
    }
}

@end
