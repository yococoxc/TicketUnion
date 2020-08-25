//
//  BaseVC.h
//  TicketUnion
//
//  Created by muzico on 2020/8/22.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <XLQSKit/XLQSKit.h>

typedef NS_ENUM(NSUInteger, VCState) {
    VCStateNone,
    VCStateLoading,
    VCStateSuccess,
    VCStateError,
    VCStateEmpty,
};


@protocol BaseVC <NSObject>

@required
- (void) initView;

- (void) initListener;

- (void) initPresenter;

- (void) loadData;

@end

@interface BaseVC : LQSZoneController<BaseVC>

- (instancetype) initWithTitle:(NSString *)title;

- (void) onResume;

- (void) onPause;

- (void) setupState:(VCState)state;

@end

