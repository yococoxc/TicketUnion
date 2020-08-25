//
//  LQSFixController.h
//  LQSKit
//
//  Created by muzico on 2019/1/15.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LQSFixView.h"

@class LQSFixView;

@interface LQSFixController : UIViewController

@property (nonatomic, strong) UIImageView *backgroundImageView;


@property (nonatomic, readonly) LQSFixView *fixView;
@property (nonatomic, strong) UIImageView *fixBackgroundImageView;

@property (nonatomic, readonly) UIView *aboveBoxView;
@property (nonatomic, strong) UIImageView *aboveBoxBackgroundImageView;

@property (nonatomic, readonly) UIView *belowBoxView;
@property (nonatomic, strong) UIImageView *belowBoxBackgroundImageView;

@property (nonatomic, assign) UIEdgeInsets fixViewInset;

- (instancetype) initWithContentView:(UIView *)view;

@end

