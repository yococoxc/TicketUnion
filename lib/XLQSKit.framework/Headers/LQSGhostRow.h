//
//  LQSGhostRow.h
//  XLQSKit
//
//  Created by muzico on 2020/8/12.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LQSGhostRowItem : NSObject

@property(nonatomic,strong) UIView *view;

@property(nonatomic,assign) CGFloat width;

@property(nonatomic,assign) CGFloat height;

+ (instancetype) itemWithView:(UIView *)view;

+ (instancetype) itemWithView:(UIView *)view size:(CGSize)size;

@end


@interface LQSGhostRow : UIView

@property(nonatomic,strong) NSArray<LQSGhostRowItem *> *items;

@property(nonatomic,assign) CGFloat gap;

@property(nonatomic,assign) UIEdgeInsets padding;


- (void) reloadLayout;

@end
