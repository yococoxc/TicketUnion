//
//  BasePresenter.h
//  TicketUnion
//
//  Created by muzico on 2020/8/21.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Api.h"
#import "IBaseViewCallback.h"


@interface BasePresenter : NSObject

@property(nonatomic,strong,readonly) Api *mApi;

@property(nonatomic,strong,readonly) NSMutableArray *callbacks;

- (void) registerCallback:(id)callback;

- (void) unregisterCallback:(id)callback;

- (void) reload;

@end

