//
//  LQSPopSelectFootView.h
//  reApp
//
//  Created by muzico on 2020/7/7.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface LQSPopSelectFootView : UIView

@property(nonatomic,weak) UIButton *button;
/**
 默认字体大小自适应，加上 sizeFitOffSet 偏移值。
 默认为 57
 */
@property(nonatomic,assign) CGFloat sizeFitOffSet;

/**
 无视上面规则，直接采用这种计算宽度。
 默认不生效，一旦设定后即生效。
 */
@property(nonatomic,assign) CGFloat insetButtonLeft;
@property(nonatomic,assign) CGFloat insetButtonRight;

@end

