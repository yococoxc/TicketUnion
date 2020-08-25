//
//  UITextField+LQS.h
//  LQSKit
//
//  Created by muzico on 2018/8/9.
//  Copyright © 2018年 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIFont+LQS.h"

@interface UITextField (LQS)

+ (instancetype) lqs_view;

- (void) lqs_setupWithTextField:(void(^)(UITextField* textField))aBlock;



@property(nonatomic,assign) UIFontWeight lqs_fontWeight;

@property(nonatomic) CGFloat lqs_fontSize;
@property(nonatomic) id lqs_textColor;
@property(nonatomic) id lqs_placeholderColor;


@end
