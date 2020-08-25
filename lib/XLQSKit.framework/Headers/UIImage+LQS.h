//
//  UIImage+LQS.h
//  LQSKit
//
//  Created by muzico on 2019/8/14.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (LQS)

/**
 将图片背景白色设置为透明
 */
- (UIImage *) lqs_imageColorWhiteToTransparent;

/**
 将图片背景黑色设置为透明
 */
- (UIImage *) lqs_imageColorBlackToTransparent;

/**
 将图片的颜色设置为反色
 */
- (UIImage *) lqs_imageColorToInverted;


/**
 type：1（黑白），2（棕褐色、或者叫暖黄色），3（反色），其他值均为默认值（不明确）
 */
- (UIImage*) lqs_imageColorWithType:(char)type;

@end
