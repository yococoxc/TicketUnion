//
//  LQSFixView.h
//  LQSKit
//
//  Created by muzico on 2019/1/13.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LQSViewItem.h"

#import "LQSAirThroughView.h"

@interface LQSFixView : UIView

@property(nonatomic, strong) UIView *navigationBarest;
@property(nonatomic, strong) UIView *navigationBarer;
@property(nonatomic, strong) UIView *navigationBar;

@property(nonatomic, strong) id topests;
@property(nonatomic, strong) id topers;
@property(nonatomic, strong) id tops;

@property(nonatomic, strong) id headests;
@property(nonatomic, strong) id headers;
@property(nonatomic, strong) id heads;

@property(nonatomic, strong) UIView *body;
@property (nonatomic, assign) UIEdgeInsets bodyInset;

@property(nonatomic, strong) id foots;
@property(nonatomic, strong) id footers;
@property(nonatomic, strong) id footests;

@property(nonatomic, strong) id bottoms;
@property(nonatomic, strong) id bottomers;
@property(nonatomic, strong) id bottomests;

@property(nonatomic, strong) UIView *tabBar;
@property(nonatomic, strong) UIView *tabBarer;
@property(nonatomic, strong) UIView *tabBarest;


/**
 建议使用LQSAirThroughFixView 或 LQSAirThroughView 之类的视图作为backgroundView，foregroundView的基类。
 */



@property(nonatomic, strong) LQSAirThroughView *bodyForegroundView;


@property(nonatomic, strong) LQSAirThroughView *anyActivityView;


@property(nonatomic, strong) UIView *backgroundView;

@property(nonatomic, strong) UIView *foregroundView;


//44
@property(nonatomic, assign) CGFloat navigationBarHeight;
//44
@property(nonatomic, assign) CGFloat navigationBarerHeight;
//44
@property(nonatomic, assign) CGFloat navigationBarestHeight;

@property(nonatomic, assign) CGFloat headestHeight;
@property(nonatomic, assign) CGFloat headerHeight;
@property(nonatomic, assign) CGFloat headHeight;

@property(nonatomic, assign) CGFloat footHeight;
@property(nonatomic, assign) CGFloat footerHeight;
@property(nonatomic, assign) CGFloat footestHeight;

@property(nonatomic, assign) CGFloat topHeight;
@property(nonatomic, assign) CGFloat toperHeight;
@property(nonatomic, assign) CGFloat topestHeight;


@property(nonatomic, assign) CGFloat bottomHeight;
@property(nonatomic, assign) CGFloat bottomerHeight;
@property(nonatomic, assign) CGFloat bottomestHeight;

//49
@property(nonatomic, assign) CGFloat tabBarHeight;
//49
@property(nonatomic, assign) CGFloat tabBarerHeight;
//49
@property(nonatomic, assign) CGFloat tabBarestHeight;




//- (void) reloadData;
//
- (void) reloadLayout;

@end
