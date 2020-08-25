//
//  UITextView+LQS.h
//  LQSKit
//
//  Created by muzico on 2019/7/18.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIFont+LQS.h"

@interface UITextView (LQS)


@property(nonatomic,assign) UIFontWeight lqs_fontWeight;
@property(nonatomic) CGFloat lqs_fontSize;
@property(nonatomic) id lqs_textColor;

+ (instancetype) lqs_view;

@end
