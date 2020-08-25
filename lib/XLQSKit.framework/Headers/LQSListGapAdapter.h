//
//  LQSListGapAdapter.h
//  XLQSKit
//
//  Created by muzico on 2020/6/15.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <XLQSKit/XLQSKit.h>


@interface LQSListGapAdapter : LQSListAdapter

@property(nonatomic,assign) CGFloat height;


@property(nonatomic,strong) id color;

+ (instancetype) gapWithHeight:(CGFloat)height;
+ (instancetype) gapWithHeight:(CGFloat)height withColor:(id)color;

@end
