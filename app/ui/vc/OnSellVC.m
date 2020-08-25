//
//  OnSellVC.m
//  TicketUnion
//
//  Created by muzico on 2020/8/22.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "OnSellVC.h"
#import "IOnSellPageCallback.h"
#import "UIUtils.h"

#import "CommonHeadView.h"
#import "PresenterManager.h"


#import "OnSellListAdapter.h"

@interface OnSellVC ()<IOnSellPageCallback>

@property(nonatomic,strong) OnSellPagePresenterImpl *presenter;
@property(nonatomic,strong) OnSellListAdapter *adapter;

@end

@implementation OnSellVC


- (void) dealloc {
    if (self.presenter) {
        [self.presenter unregisterCallback:self];
    }
}

#pragma mark - IBaseViewCallback
- (void)onEmpty {
    [self setupState:VCStateEmpty];
}

- (void)onError {
    [self setupState:VCStateError];
}

- (void)onLoading {
    [self setupState:VCStateLoading];
}

#pragma mark - IOnSellPageCallback
- (void) initView {
    
    self.aboveZoneView.lqs_backgroundColor = @"#F5A623";
    
    UIView *headView = [CommonHeadView viewWithTitle:@"特惠宝贝"];
    self.zoneView.headerViewItem = [LQSViewItem itemWithView:headView height:44];
    
    
    LQSEasyListView *listView = [LQSEasyListView new];
    listView.lqs_backgroundColor = @"#f0f0f0";
    self.zoneView.body = listView;
    
    
    self.adapter = [OnSellListAdapter new];
    listView.adapter = self.adapter;
}

- (void) initListener {
    //下拉刷新配置
    
    //适配器配置
}

- (void) initPresenter {
    self.presenter = [PresenterManager getOnSellPagePresenterImpl];
    [self.presenter registerCallback:self];
    [self.presenter getOnSellContent];
}

- (void) loadData {
    [self.presenter getOnSellContent];
}


#pragma mark - IOnSellPageCallback
- (void) onSellContentLoaded:(id)result {
//    NSLog(@"onSellContentLoaded ====>>> %@",result);
    [self.adapter setupDataSource:result];
}

- (void) onLoaderMoreResult:(id)result {
    //结束底部刷新
}

- (void) onLoaderMoreError {
    [UIUtils toastWithText:@"网络异常,请稍后重试."];
    //结束底部刷新
    
}

- (void) onLoaderMoreEmpty {
    [UIUtils toastWithText:@"没有更多的内容..."];
    //结束底部刷新
    
}


@end
