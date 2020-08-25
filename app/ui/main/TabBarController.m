//
//  TabBarController.m
//  TicketUnion
//
//  Created by muzico on 2020/8/22.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "TabBarController.h"
#import "HomeVC.h"
#import "OnSellVC.h"
#import "SelectedVC.h"
#import "SearchVC.h"

#import <XLQSKit/XLQSKit.h>

@interface TabBarController ()

@end

@implementation TabBarController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    
    NSMutableArray *array = [NSMutableArray array];
    [array addObject:[HomeVC lqs_createWithTabBarItemBlock:^(UITabBarItem *item) {
        item.title = @"推荐";
        item.lqs_selectedTitleColor = @"#F5A623";
        item.lqs_titleColor = @"#B5B5B5";
    }]];
    [array addObject:[OnSellVC lqs_createWithTabBarItemBlock:^(UITabBarItem *item) {
        item.title = @"特惠";
        item.lqs_selectedTitleColor = @"#F5A623";
        item.lqs_titleColor = @"#B5B5B5";
    }]];
    [array addObject:[SelectedVC lqs_createWithTabBarItemBlock:^(UITabBarItem *item) {
        item.title = @"精选";
        item.lqs_selectedTitleColor = @"#F5A623";
        item.lqs_titleColor = @"#B5B5B5";
    }]];
    [array addObject:[SearchVC lqs_createWithTabBarItemBlock:^(UITabBarItem *item) {
        item.title = @"搜索";
        item.lqs_selectedTitleColor = @"#F5A623";
        item.lqs_titleColor = @"#B5B5B5";
    }]];
    self.viewControllers = array;
}


@end
