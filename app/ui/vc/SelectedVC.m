//
//  SelectedVC.m
//  TicketUnion
//
//  Created by muzico on 2020/8/22.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "SelectedVC.h"
#import "ISelectedPageCallback.h"
#import "SelectedPagePresenterImpl.h"

#import "CommonHeadView.h"
#import "PresenterManager.h"
#import "PickTypeAdapter.h"
#import "PickerContentListAdapter.h"

#import "TicketVC.h"

@interface SelectedVC ()<ISelectedPageCallback>

@property(nonatomic,strong) SelectedPagePresenterImpl *presenter;
@property(nonatomic,strong) PickTypeAdapter *typeAdapter;
@property(nonatomic,strong) PickerContentListAdapter *listAdapter;

@end

@implementation SelectedVC

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

#pragma mark - ISelectedPageCallback
- (void) initView {
    
    self.aboveZoneView.lqs_backgroundColor = @"#F5A623";
    
    UIView *headView = [CommonHeadView viewWithTitle:@"精选宝贝"];
    self.zoneView.headerViewItem = [LQSViewItem itemWithView:headView height:44];
    
    
    
    LQSEasyListView *menuListView = [LQSEasyListView new];
    menuListView.lqs_backgroundColor = @"#ffffff";
    self.zoneView.leading = menuListView;
    self.zoneView.leadingWidth = 120;
    
    LQSEasyListView *listView = [LQSEasyListView new];
    listView.lqs_backgroundColor = @"#f0f0f0";
    self.zoneView.body = listView;
    
    LQSWeakSelf
    
    
    self.typeAdapter = [PickTypeAdapter new];
    self.typeAdapter.didSelectCell = ^(id dataSource, NSIndexPath *indexPath) {
        NSString *favorites_id = [dataSource lqs_jsonQueryAndNumberToString:@"favorites_id"];
        [weakSelf.presenter getPickContentById:favorites_id];
    };
    menuListView.adapter = self.typeAdapter;
    
    
    self.listAdapter = [PickerContentListAdapter new];
    self.listAdapter.didSelectCell = ^(id dataSource, NSIndexPath *indexPath) {
        
        TicketVC *vc = [TicketVC new];
        
        vc.url = [dataSource lqs_objectForKey:@"click_url"];
        vc.titleString = [dataSource lqs_objectForKey:@"title"];
        vc.cover = [dataSource lqs_objectForKey:@"pict_url"];
        
        [[UIApplication sharedApplication].lqs_rootViewController lqs_currentNavigationControllerPushViewController:vc];
    };
    listView.adapter = self.listAdapter;
}

- (void) initListener {
    //下拉刷新配置
    
    //适配器配置
}

- (void) initPresenter {
    self.presenter = [PresenterManager getSelectedPagePresenterImpl];
    [self.presenter registerCallback:self];
}

- (void) loadData {
    [self.presenter getPickType];
}


#pragma mark - ISelectedPageCallback
- (void) onPickTypeLoaded:(id)result {
    self.typeAdapter.currentIndex = 0;
    [self.typeAdapter setupDataSource:result];
    
    NSString *favorites_id = [result lqs_jsonQueryAndNumberToString:@"[0]/favorites_id"];
    [self.presenter getPickContentById:favorites_id];
}

- (void) onContentListLoaded:(id)result {
    [self.listAdapter.collectionView setContentOffset:CGPointZero];
    [self.listAdapter setupDataSource:result];
}

@end
