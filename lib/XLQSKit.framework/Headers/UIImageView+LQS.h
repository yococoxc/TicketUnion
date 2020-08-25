//
//  UIImageView+LQS.h
//  LQSKit
//
//  Created by muzico on 2018/7/20.
//  Copyright © 2018年 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImageView (LQS)

- (void) lqs_setImage:(id)aImage;


@property(nonatomic) id lqs_image;




- (void) lqs_setupWithImageView:(void(^)(UIImageView* imageView))aBlock;


+ (instancetype) lqs_image:(id)aImage;
+ (instancetype) lqs_imageViewWithImage:(id)image;
+ (instancetype) lqs_imageViewWithBackgroundColor:(id)backgroundColor;
+ (instancetype) lqs_imageViewWithImage:(id)image backgroundColor:(id)backgroundColor;

@end
