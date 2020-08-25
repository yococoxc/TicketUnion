//
//  LQSLayoutContainerControl.h
//  LQSKit
//
//  Created by muzico on 2020/1/14.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LQSLayoutContainerControl : UIControl

@property(nonatomic,strong) UIView *child;

+ (instancetype) containerWithChild:(UIView *)child;

@end
