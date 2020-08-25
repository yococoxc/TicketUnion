//
//  LQSSafeAreaController.h
//  LQSKit
//
//  Created by muzico on 2018/12/29.
//  Copyright © 2018 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LQSContainerView.h"

@interface LQSSafeAreaController : UIViewController

@property(readonly) LQSContainerView *safeAreaView;

@property (nonatomic, readonly) UIView *aboveBoxView;
@property (nonatomic, readonly) UIView *belowBoxView;

@property (nonatomic, assign) UIEdgeInsets safeAreaViewInsets;

- (instancetype) initWithContentView:(UIView *)view;

@end
