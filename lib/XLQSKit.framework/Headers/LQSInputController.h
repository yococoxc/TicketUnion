//
//  LQSInputController.h
//  reApp
//
//  Created by muzico on 2020/7/11.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <XLQSKit/XLQSKit.h>
#import "LQSInputView.h"


@interface LQSInputController : UIViewController

@property(nonatomic,copy) LQSCallbackStringBlock okBlock;
@property(nonatomic,copy) LQSCallbackEmptyBlock customOkBlock;



@property(nonatomic,strong) LQSInputView *inputView;
@property(nonatomic,assign) CGFloat inputViewHeight;

@property(nonatomic,copy) NSString *placeholder;
@property(nonatomic,copy) NSString *contentString;

@property(nonatomic,copy) NSString *buttonTitle;

@property(nonatomic,assign) UIKeyboardType keyboardType;


/**
 自定义 inputView 时，指定哪个 对象成为响应者。
 */
@property(nonatomic,weak) UIResponder *becomeFirstResponderView;
@property(nonatomic,weak) UIControl *cancelControl;
@property(nonatomic,weak) UIControl *sureControl;

@end
