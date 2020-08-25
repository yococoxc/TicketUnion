//
//  BasePresenter.m
//  TicketUnion
//
//  Created by muzico on 2020/8/21.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "BasePresenter.h"


@interface BasePresenter ()

@property(nonatomic,strong,readwrite) NSMutableArray<id<IBaseViewCallback>> *callbacks;

@property(nonatomic,strong,readwrite) Api *mApi;

@end



@implementation BasePresenter


- (void) registerCallback:(id)callback {
    if (callback) {
        [self.callbacks addObject:callback];
    }
}

- (void) unregisterCallback:(id)callback {
    if (callback) {
        [self.callbacks removeObject:callback];
    }
}

- (void) reload {
    
}

#pragma mark -
- (NSMutableArray *) callbacks {
    if (_callbacks == nil) {
        _callbacks = [NSMutableArray array];
    }
    return _callbacks;
}
- (Api *) mApi {
    if (_mApi == nil) {
        _mApi = [Api new];
    }
    return _mApi;
}

@end
