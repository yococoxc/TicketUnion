//
//  UIView+LQS.h
//  LQSKit
//
//  Created by muzico on 2018/7/20.
//  Copyright © 2018年 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (LQS)

- (void) lqs_setBackgroundColor:(id)aColor;

- (void) lqs_setBackgroundColor:(id)aColor alpha:(CGFloat)alpha;

/**
* 设置该值默认 masksToBounds 为 NO。
*/
- (void) lqs_setLayerShadowColor:(id)aColor opacity:(CGFloat)opacity size:(CGSize)size;//不推荐
- (void) lqs_setLayerShadowColor:(id)aColor opacity:(CGFloat)opacity offset:(CGSize)offset radius:(CGFloat)shadowRadius;//推荐
- (void) lqs_setLayerShadowColor:(id)aColor opacity:(CGFloat)opacity offset:(CGSize)offset radius:(CGFloat)shadowRadius cornerRadius:(CGFloat)cornerRadius;//推荐





- (void) lqs_setLayerBorderWidth:(CGFloat)width borderColor:(id)aColor;
- (void) lqs_setLayerBorderWidth:(CGFloat)width color:(id)aColor;

/**
 * 设置该值默认 masksToBounds 为 YES。
 */
- (void) lqs_setLayerCornerRadius:(CGFloat)cornerRadius;

- (void) lqs_setLayerMasksToBounds:(BOOL)masksToBounds;

+ (instancetype) lqs_backgroundColor:(id)aColor;


@property(nonatomic,readonly) CGFloat lqs_x;
@property(nonatomic,readonly) CGFloat lqs_y;
@property(nonatomic,readonly) CGFloat lqs_width;
@property(nonatomic,readonly) CGFloat lqs_height;
@property(nonatomic,readonly) CGFloat lqs_left;
@property(nonatomic,readonly) CGFloat lqs_right;
@property(nonatomic,readonly) CGFloat lqs_top;
@property(nonatomic,readonly) CGFloat lqs_bottom;

/**
 视图生成图像。
 */
@property(nonatomic,readonly) UIImage *lqs_makeImage;


@property(nonatomic) id lqs_backgroundColor;

/**
 * 设置该值默认 masksToBounds 为 YES。
 */
@property(nonatomic) CGFloat lqs_layerCornerRadius;
@property(nonatomic) BOOL lqs_layerMasksToBounds;



@property(nonatomic,assign) UIRectCorner lqs_roundedCorners;
@property(nonatomic,assign) CGSize lqs_roundedRadii;
- (void) lqs_setupRoundedCornersWithRoundingCorners:(UIRectCorner)corners cornerRadii:(CGSize)cornerRadii;
- (void) lqs_setupRoundedCornersWithSize:(CGSize)size roundingCorners:(UIRectCorner)corners cornerRadii:(CGSize)cornerRadii;
- (void) lqs_setupRoundedCornersWithBounds:(CGRect)bounds roundingCorners:(UIRectCorner)corners cornerRadii:(CGSize)cornerRadii;


- (void) lqs_setupWithView:(void(^)(UIView* view))aBlock;


- (id) lqs_viewWithTag:(NSInteger)tag;




- (instancetype) lqs_initXIB;
- (instancetype) lqs_initWithXIB;
- (instancetype) lqs_initWithXIB:(NSString*)name;
+ (instancetype) lqs_viewXIB;
+ (instancetype) lqs_viewWithXIB;
+ (instancetype) lqs_viewWithXIB:(NSString*)name;

+ (id) lqs_autoXIB;
+ (id) lqs_autoWithXIB;
+ (id) lqs_autoWithXIB:(NSString*)name;

@end
