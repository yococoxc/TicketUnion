//
//  UIFont+LQS.h
//  LQSKit
//
//  Created by muzico on 2019/5/24.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>


/**
 暂时为苹方所用
 */
//typedef NS_ENUM(NSUInteger, LQSFontWeightStyle) {
//    LQSFontWeightStyleMedium,// 中黑体
//    LQSFontWeightStyleSemibold,// 中粗体
//    LQSFontWeightStyleLight,// 细体
//    LQSFontWeightStyleUltralight,// 极细体
//    LQSFontWeightStyleRegular,// 常规体
//    LQSFontWeightStyleThin,// 纤细体
//};

@interface UIFont (LQS)

/**
 苹方字体
 
 @param fontWeight 字体粗细（字重)
 @param fontSize 字体大小
 @return 返回指定字重大小的苹方字体
 */
//+ (UIFont *) lqs_pingFangSCWithWeight:(LQSFontWeightStyle)fontWeight size:(CGFloat)fontSize;


+ (UIFont *) lqs_defualtWeightWithSize:(CGFloat)fontSize;
+ (UIFont *) lqs_weight:(UIFontWeight)fontWeight size:(CGFloat)fontSize;


@end
