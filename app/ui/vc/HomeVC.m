//
//  HomeVC.m
//  TicketUnion
//
//  Created by muzico on 2020/8/22.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "HomeVC.h"

#import "HomePagePresenterImpl.h"
#import "HomeContentVC.h"
#import "IHomePageCallback.h"


@interface HomeVC ()<IHomePageCallback,LQSShrinkMenuScrollPageViewDelegate>


@property(nonatomic,strong) LQSShrinkMenuScrollPageView *myView;


@property(nonatomic,strong) HomePagePresenterImpl *presenter;


@end

@implementation HomeVC

- (void) dealloc {
    [self.presenter unregisterCallback:self];
}

- (void) initView {
    self.myView = [LQSShrinkMenuScrollPageView new];
    self.myView.delegate = self;
    self.zoneView.body = self.myView;
}

- (void) initListener {
    
}

- (void) initPresenter {
    self.presenter = [HomePagePresenterImpl new];
    [self.presenter registerCallback:self];
    
}

- (void) loadData {
    [self.presenter loadCategories];
}



#pragma mark -
- (void)onEmpty {
    
}

- (void)onError {
    
}

- (void)onLoading {
    
}

#pragma mark - IHomePageCallback
- (void) onCategoriesLoaded:(id)result {
    self.myView.menuDataSource = result;
    
    
    NSMutableArray *keepArray = [NSMutableArray array];
    for (NSDictionary *dic in result) {
        HomeContentVC *vc = [HomeContentVC new];
        vc.targetID = [dic lqs_objectForKey:@"id"];
        [keepArray addObject:vc];
    }
    self.myView.scrollPageDataSource = keepArray;
    
    
    [self.myView reloadData];
}

#pragma mark - LQSShrinkMenuScrollPageViewDelegate

- (void) lqsShrinkMenuScrollPageView:(LQSShrinkMenuScrollPageView *)shrinkMenuScrollPageView scrollWithIndex:(NSUInteger)index withScrollPage:(id)scrollPage {
    if ([scrollPage isKindOfClass:[HomeContentVC class]]) {
        HomeContentVC *vc = scrollPage;
        shrinkMenuScrollPageView.scrollView = vc.listView.collectionView;
    }
}


@end
