//
//  LQSZoneController.h
//  TestLayout
//
//  Created by muzico on 2020/6/5.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "LQSZoneView.h"

@class LQSZoneView;

@interface LQSZoneController : UIViewController

@property (nonatomic, strong) UIImageView *backgroundImageView;

@property (nonatomic, readonly) LQSZoneView *zoneView;
@property (nonatomic, strong) UIImageView *zoneBackgroundImageView;

@property (nonatomic, readonly) UIView *aboveZoneView;
@property (nonatomic, strong) UIImageView *aboveZoneBackgroundImageView;

@property (nonatomic, readonly) UIView *belowZoneView;
@property (nonatomic, strong) UIImageView *belowZoneBackgroundImageView;

@property (nonatomic, assign) UIEdgeInsets zoneViewInset;

- (instancetype) initWithContentView:(UIView *)view;

@end
