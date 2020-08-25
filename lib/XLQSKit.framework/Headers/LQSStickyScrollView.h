//
//  LQSStickyScrollView.h
//  testAAAA
//
//  Created by muzico on 2019/10/14.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LQSStickyScrollView : UIView

#pragma mark -
@property(nonatomic,strong,readonly) UIScrollView *scrollView;

#pragma mark -
//100
@property(nonatomic,assign) CGFloat headViewHeight;
@property(nonatomic,strong) UIView *headView;

//0
@property(nonatomic,assign) CGFloat middleViewHeight;
@property(nonatomic,strong) UIView *middleView;

@property(nonatomic,strong) UIView *footView;

#pragma mark - 
//0.3
@property(nonatomic,assign) CGFloat layoutAnimationDuration;
//50
@property(nonatomic,assign) CGFloat upOffset;
//50
@property(nonatomic,assign) CGFloat downOffset;

@end
