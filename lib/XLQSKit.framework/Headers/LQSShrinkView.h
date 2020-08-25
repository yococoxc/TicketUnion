//
//  LQSShrinkView.h
//  XLQSKit
//
//  Created by muzico on 2020/8/24.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LQSShrinkView : UIView

@property(nonatomic,strong) UIView *headView;
//100
@property(nonatomic,assign) CGFloat headHeight;

@property(nonatomic,strong) UIView *middleView;
//44
@property(nonatomic,assign) CGFloat middleHeight;

@property(nonatomic,strong) UIView *contentView;

//记录需要监听的scrollView
@property(nonatomic,strong) UIScrollView *scrollView;

@end

