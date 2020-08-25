//
//  LQSCenterLayout.h
//  LQSKit
//
//  Created by muzico on 2019/3/2.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, LQSCenterLayoutDirection) {
    LQSCenterLayoutDirectionHorizontal,
    LQSCenterLayoutDirectionVertical,
};

@interface LQSCenterLayout : UIView

@property(nonatomic, strong, readonly) UIScrollView *scrollView;

@property(nonatomic, strong) NSArray<UIView *> *items;

@property(nonatomic, assign) LQSCenterLayoutDirection direction;

//44
@property(nonatomic, assign) CGFloat itemSize;

//8
@property(nonatomic, assign) CGFloat gap;

- (void) reloadData;

@end
