//
//  HomeContentVC.m
//  TicketUnion
//
//  Created by muzico on 2020/8/23.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "HomeContentVC.h"
#import "ICategoryPagerCallback.h"
#import "UIUtils.h"

#import "HomeContentCarouselAdapter.h"

#import "HomeContentGapAdapter.h"
#import "SearchContentAdapter.h"

#import "CategoryPagePresenterImpl.h"

@interface HomeContentVC ()<ICategoryPagerCallback>

@property(nonatomic,copy) NSString *mMaterialId;


@property(nonatomic,strong) HomeContentCarouselAdapter *carouselAdapter;

@property(nonatomic,strong) SearchContentAdapter *adapter;

@property(nonatomic,strong) CategoryPagePresenterImpl *presenter;


@end

@implementation HomeContentVC

#pragma mark -
- (void) initView {
    self.listView = [LQSEasyListView new];
    self.listView.lqs_backgroundColor = @"#f0f0f0";
    self.zoneView.body = self.listView;
    
    self.carouselAdapter = [HomeContentCarouselAdapter new];
    
    
    self.adapter = [SearchContentAdapter new];
//    [self.adapter setupDataSource:@[@"1",@"2",@"3",@"4",@"1",@"2",@"3",@"4",@"1",@"2",@"3",@"4",@"1",@"2",@"3",@"4"]];
    
    NSMutableArray *keepArray = [NSMutableArray array];
    [keepArray addObject:self.carouselAdapter];
    [keepArray addObject:[HomeContentGapAdapter new]];
    [keepArray addObject:self.adapter];
    self.listView.adapters = keepArray;
}

- (void) initListener {
    
}

- (void) initPresenter {
    self.presenter = [CategoryPagePresenterImpl new];
    [self.presenter registerCallback:self];
}

- (void) loadData {
    [self.presenter getCategoryContentById:self.targetID];
}


#pragma mark -
- (void) onResume {
    //可见的我们去调用开始轮播
    
}
- (void) onPause {
    //不可见的时候暂停轮播
    
}

#pragma mark - IBaseViewCallback
- (void) onLoading {
    [self setupState:VCStateLoading];
}

- (void) onError {
    [self setupState:VCStateError];
}

- (void) onEmpty {
    [self setupState:VCStateEmpty];
}

#pragma mark - ICategoryPagerCallback
- (void) onContentLoaded:(NSArray *)contents {
    //数据列表加载到了
    [self.adapter setupDataSource:contents];
    
    
    [self setupState:VCStateSuccess];
}

- (NSString *) getCategoryId {
    return self.mMaterialId;
}

- (void) onLoaderMoreError {
    [UIUtils toastWithText:@"网络异常，请稍后重试"];

    //结束底部刷新
}
- (void) onLoaderMoreEmpty {
    [UIUtils toastWithText:@"没有更多商品"];

    //结束底部刷新
}
- (void) onLoaderMoreLoaded:(NSArray *)contents {
    //添加到适配器数据的底部
    
    //结束底部刷新
    
    [UIUtils toastWithText:[NSString stringWithFormat:@"加载了%ld条数据",contents.count]];
}
- (void) onLooperListLoaded:(NSArray *)contents {
    [self.carouselAdapter setupDataSource:contents];
}

@end
