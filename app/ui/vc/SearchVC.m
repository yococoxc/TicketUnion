//
//  SearchVC.m
//  TicketUnion
//
//  Created by muzico on 2020/8/22.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "SearchVC.h"

#import "SearchHistorySectionHeadAdapter.h"
#import "SearchHotSectionHeadAdapter.h"

#import "SearchSectionContentAdapter.h"

#import "SearchContentAdapter.h"

#import "SearchHeadView.h"

#import "SearchPagePresenterImpl.h"
#import "ISearchPageCallback.h"

@interface SearchVC ()<ISearchPageCallback>

@property(nonatomic,strong) SearchHeadView *headView;
@property(nonatomic,strong) LQSEasyListView *searchListView;
@property(nonatomic,strong) LQSEasyListView *contentListView;


@property(nonatomic,strong) SearchSectionContentAdapter *historyContentAdapter;
@property(nonatomic,strong) SearchSectionContentAdapter *hotContentAdapter;
@property(nonatomic,strong) SearchContentAdapter *listContentAdapter;


@property(nonatomic,strong) SearchPagePresenterImpl *presenter;

@end

@implementation SearchVC


#pragma mark -
- (void) initView {
    
    LQSWeakSelf
    self.aboveZoneView.lqs_backgroundColor = @"#F5A623";
    
    self.headView = [SearchHeadView lqs_autoXIB];
    self.headView.clearSearchBlock = ^{
        weakSelf.zoneView.body = weakSelf.searchListView;
    };
    self.headView.searchBlock = ^(NSString *string) {
        [weakSelf.presenter doSearch:string];
    };
    self.zoneView.headerViewItem = [LQSViewItem itemWithView:self.headView height:44];
    
    LQSEasyListView *searchListView = [LQSEasyListView listViewWithFlowLayout:[LQSCollectionViewAlignLayout layoutWithType:LQSCollectionViewAlignLayoutTypeLeft setupBlock:^(LQSCollectionViewAlignLayout *layout) {
        
        layout.minimumLineSpacing = 8;
        layout.minimumInteritemSpacing = 8;
        layout.sectionInset = UIEdgeInsetsMake(0, 16, 0, 16);
        
    }]];
    self.zoneView.body = searchListView;
    self.searchListView = searchListView;
    
    
    self.contentListView = [LQSEasyListView new];
    self.contentListView.lqs_backgroundColor = @"#f0f0f0";
    
    NSMutableArray *keepArray = [NSMutableArray array];
    {
        SearchHistorySectionHeadAdapter *adapter = [SearchHistorySectionHeadAdapter new];
        [keepArray addObject:adapter];
    }
    {
        self.historyContentAdapter = [SearchSectionContentAdapter new];
        self.historyContentAdapter.didSelectCell = ^(id dataSource, NSIndexPath *indexPath) {
            weakSelf.headView.textField.text = dataSource;
            [weakSelf.presenter doSearch:dataSource];
        };
        [keepArray addObject:self.historyContentAdapter];
        
        
        [self.historyContentAdapter setupDataSource:@[@"123213",@"sdf4444sdf",@"324234",@"gf222222hfg"]];
    }
    {
        SearchHotSectionHeadAdapter *adapter = [SearchHotSectionHeadAdapter new];
        [keepArray addObject:adapter];
    }
    {
        self.hotContentAdapter = [SearchSectionContentAdapter new];
        self.hotContentAdapter.didSelectCell = ^(id dataSource, NSIndexPath *indexPath) {
            weakSelf.headView.textField.text = dataSource;
            [weakSelf.presenter doSearch:dataSource];
        };
        [keepArray addObject:self.hotContentAdapter];
        
    }
    self.searchListView.adapters = keepArray;
    
    
    self.listContentAdapter = [SearchContentAdapter new];
    self.contentListView.adapter = self.listContentAdapter;
}

- (void) initListener {
    
    self.presenter = [SearchPagePresenterImpl new];
    [self.presenter registerCallback:self];
    //获取搜索推荐词
    [self.presenter getRecommendWords];
    [self.presenter getHistories];
}

- (void) initPresenter {
    
}

- (void) loadData {
    
}

#pragma mark - ISearchPageCallback
- (void) onSearchResultLoaded:(id)result {
    self.zoneView.body = self.contentListView;
    [self.listContentAdapter setupDataSource:result];
}
- (void) onLoaderMote:(id)result {
}
- (void) onLoaderMoreError {
    
}
- (void) onLoaderEmpty {
    
}
- (void) onHistoriesLoaded:(id)histories {
    [self.historyContentAdapter setupDataSource:histories];
}

- (void) onRecommenWordsLoaded:(id)recommendWord {
//    [self.hotContentAdapter setupDataSource:recommendWord];
    
    if ([recommendWord lqs_isNSArray]) {
        NSMutableArray *keepArray = [NSMutableArray array];
        for (NSDictionary *dic in recommendWord) {
            [keepArray lqs_addObjectNoNull:[dic lqs_objectForKey:@"keyword"]];
        }
        [self.hotContentAdapter setupDataSource:keepArray];
    }
}

- (void) onRecommendWordLoadError {
    
}


@end
