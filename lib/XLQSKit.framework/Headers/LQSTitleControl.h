//
//  LQSTitleControl.h
//  LQSKit
//
//  Created by muzico on 2019/2/28.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LQSTitleControl : UIControl

@property(nonatomic,strong) UIImageView *backgroundImageView;


@property(nonatomic,strong) UIImageView *leftImageView;
@property(nonatomic,strong) UIImageView *rightImageView;
@property(nonatomic,strong) UIImageView *topImageView;
@property(nonatomic,strong) UIImageView *bottomImageView;

@property(nonatomic,strong) UILabel *titleLabel;
//5,5,5,5
@property(nonatomic,assign) UIEdgeInsets titleInsets;

@property(nonatomic,assign) CGSize leftImageSize;
@property(nonatomic,assign) CGSize rightImageSize;
@property(nonatomic,assign) CGSize topImageSize;
@property(nonatomic,assign) CGSize bottomImageSize;

@end
