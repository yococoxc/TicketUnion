//
//  LQSViewItem.h
//  LQSKit
//
//  Created by muzico on 2019/1/13.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface LQSViewItem : NSObject

@property (strong, nonatomic) UIView *view;

/**
 
 默认为0
 */
@property (assign, nonatomic) CGFloat height;

/**
 用的不多，，，，试试加上去吧
 */
@property (assign, nonatomic) CGFloat width;


@property (assign, nonatomic) UIEdgeInsets inset;





/**
 用来记录height 是否已经被设置值了。
 */
@property (assign, nonatomic) BOOL didHeight;

@property (assign, nonatomic) BOOL didWidth;

+ (instancetype) itemWithHeight:(CGFloat)height;
+ (instancetype) itemWithView:(UIView *)view height:(CGFloat)height;
+ (instancetype) itemWithView:(UIView *)view;
+ (instancetype) itemWithView:(UIView *)view height:(CGFloat)height inset:(UIEdgeInsets)inset;
+ (instancetype) itemWithViewColor:(id)color;
+ (instancetype) itemWithViewColor:(id)color height:(CGFloat)height;
+ (instancetype) itemWithViewColor:(id)color height:(CGFloat)height inset:(UIEdgeInsets)inset;


+ (instancetype) itemWithView:(UIView *)view height:(CGFloat)height width:(CGFloat)width;
+ (instancetype) itemWithViewColor:(id)color height:(CGFloat)height width:(CGFloat)width;

@end
