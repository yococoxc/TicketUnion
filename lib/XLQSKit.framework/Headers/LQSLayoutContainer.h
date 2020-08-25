//
//  LQSLayoutContainer.h
//  LQSKit
//
//  Created by muzico on 2020/1/14.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LQSAirThroughView.h"

@interface LQSLayoutContainer : LQSAirThroughView

@property(nonatomic,strong) UIView *child;

+ (instancetype) containerWithChild:(UIView *)child;

@end
