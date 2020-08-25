//
//  LQSPopSelectController.h
//  XLQSKit
//
//  Created by muzico on 2020/7/7.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <XLQSKit/XLQSKit.h>
#import "LQSListAdapterManager.h"

#import "LQSPopSelectHeadView.h"
#import "LQSPopSelectFootView.h"

@class LQSPopSelectController;


typedef void(^LQSPopSelectControllerSetupCellBlock)(LQSPopSelectController *controller,LQSListItemView *content,id dataSource, NSInteger index);

typedef void(^LQSPopSelectControllerSelectCellBlock)(LQSPopSelectController *controller,id dataSource, NSInteger index);

@interface LQSPopSelectController : LQSFixController

@property(nonatomic,strong) LQSPopSelectHeadView *headView;
@property(nonatomic,assign) CGFloat headViewHeight;

@property(nonatomic,strong) LQSPopSelectFootView *footView;
@property(nonatomic,assign) CGFloat footViewHeight;


@property(nonatomic,strong) NSArray *cellDataSource;
@property(nonatomic,assign) CGFloat cellHeight;
@property(nonatomic,strong) Class cellViewClass;
@property(nonatomic,copy) LQSPopSelectControllerSetupCellBlock setupCellBlock;
@property(nonatomic,copy) LQSPopSelectControllerSelectCellBlock selectCellBlock;


@property(nonatomic,assign) CGFloat gapHeight;
@property(nonatomic,strong) UIColor *gapColor;


/**
 这个值，提供设置前一个选择的值，方便有需要的时候用。
 */
@property(nonatomic,assign) CGFloat previousIndex;

- (void) pressedControlToCancel;

@end
