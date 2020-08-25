//
//  CommonScrollView2.h
//  juhao
//
//  Created by muzico on 2018/12/4.
//  Copyright © 2018 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LQSViewItem.h"

typedef NS_ENUM(NSUInteger, CommonScrollViewDirection) {
    CommonScrollViewDirectionDirectionHorizontal,
    CommonScrollViewDirectionDirectionVertical,
};

@interface CommonScrollView2 : UIScrollView

@property (strong, nonatomic) NSArray<LQSViewItem *> *items;

@property(nonatomic,assign) CommonScrollViewDirection direction;


- (void) reloadData;

- (void) reloadLayout;

@end
