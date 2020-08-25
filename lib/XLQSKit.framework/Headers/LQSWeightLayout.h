//
//  LQSWeightLayout.h
//  LQSKit
//
//  Created by muzico on 2019/2/28.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface LQSWeightLayoutItem : NSObject

@property(nonatomic, assign) CGFloat weight;

@property(nonatomic, assign) CGFloat width;

@property(nonatomic, strong) UIView *view;

- (instancetype) initWithView:(UIView *)view withWeight:(CGFloat)weight;

+ (instancetype) itemWithView:(UIView *)view withWeight:(CGFloat)weight;


- (instancetype) initWithView:(UIView *)view withWidth:(CGFloat)width;

+ (instancetype) itemWithView:(UIView *)view withWidth:(CGFloat)width;

@end


typedef NS_ENUM(NSUInteger, LQSWeightLayoutDirection) {
    LQSWeightLayoutDirectionHorizontal,
    LQSWeightLayoutDirectionVertical,
};


@interface LQSWeightLayout : UIView

@property(nonatomic,assign) LQSWeightLayoutDirection direction;

@property(nonatomic,strong) NSArray *items;

@end
