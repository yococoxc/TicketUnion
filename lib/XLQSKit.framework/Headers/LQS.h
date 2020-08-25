//
//  LQS.h
//  LQSKit
//
//  Created by muzico on 2018/7/20.
//  Copyright © 2018年 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


BOOL LQS_isBegin_iOS_7(void);
BOOL LQS_isBegin_iOS_8(void);
BOOL LQS_isBegin_iOS_9(void);
BOOL LQS_isBegin_iOS_10(void);
BOOL LQS_isBegin_iOS_11(void);
BOOL LQS_isBegin_iOS_12(void);
BOOL LQS_isBegin_iOS_13(void);
BOOL LQS_isBegin_iOS_14(void);


#define LQS_StringWithInteger(var) ([NSString stringWithFormat:@"%ld",var])
#define LQS_StringWithFloat(var) ([NSString stringWithFormat:@"%lf",var])
#define LQS_StringWithFloat_2(var) ([NSString stringWithFormat:@"%.2lf",var])

@interface LQS : NSObject

/**
 16 进制值:
 支持 3 位 16 进制值。（RGB）#abc <==> #aabbcc
 支持 4 位 16 进制值。（RGBA）#abcd <==> #aabbccdd
 支持 6 位 16 进制值。（RGB）
 支持 8 位 16 进制值。（RGBA）
 
 特殊值:
 R、Random、random，代表随机颜色。
 
 颜色的英文名（小写）:
 
 10进制值:
 RGB: 255,255,255
 RGBA: 255,255,255,255
 **/
+ (UIColor*) color:(id)aColor;

+ (UIImage*) image:(id)aImage;

+ (CGFloat) heightWithWidth:(CGFloat)width equalRatioWithOtherWidth:(CGFloat)otherWidth otherHeight:(CGFloat)otherHeight;


+ (CGFloat) valueFor5:(CGFloat)value5 for6:(CGFloat)value6 for6Plus:(CGFloat)value6Plus forX:(CGFloat)valueX;


//[from, to]
+ (int) randomIntValue:(int)from to:(int)to;
+ (NSInteger) randomIntegerValue:(NSInteger)from to:(NSInteger)to;
+ (NSUInteger) randomUnsignedIntegerValue:(NSUInteger)from to:(NSUInteger)to;

+ (void) callWithTel:(NSString*)tel toView:(id)view;


/**
 *  调用iOS自带的浏览器 Safari 打开指定的网址。
 */
+ (void) callSafariWithURL:(id)url;
+ (void) openURL:(NSURL *) url;



/**
 *  APP 文档的路径。
 */
+ (NSString *) documentDirectory;
/**
 *  APP 文档的路径。
 */
+ (NSString *) documentPath;
/**
 *  APP 主要包的路径。
 */
+ (NSString *) mainBundlePath;
/**
 *  来自APP 文档的资源的路径。
 */
+ (NSString *) pathFromDocumentWithResource:(NSString*)resource;
/**
 *  来自APP 主要包的资源的路径。
 */
+ (NSString *) pathFromMainBundleWithResource:(NSString*)resource;


#pragma mark - 相机授权
+ (BOOL) canUsageCamera;

#pragma mark - 相册授权
+ (BOOL) canUsageAlbum;

/**
 将图片保存到相册。内置判断打开相册的权限。
 */
+ (void) savedPhotosAlbumWithImage:(UIImage *)image completionHandler:(void(^)(NSError *error))completionHandler;

+ (BOOL) array:(NSArray<NSString*>*)array isEqualToArray:(NSArray<NSString*>*)otherArray;




+ (CGSize) sizeWithString:(NSString*)string font:(UIFont*)font;
+ (CGSize) sizeWithString:(NSString*)string width:(CGFloat)width font:(UIFont*)font;
+ (CGSize) sizeWithString:(NSString*)string height:(CGFloat)height font:(UIFont*)font;
+ (CGFloat) heightWithString:(NSString*)string width:(CGFloat)width font:(UIFont*)font;
+ (CGFloat) widthWithString:(NSString*)string height:(CGFloat)height font:(UIFont*)font;


+ (CGSize) sizeWithString:(NSString *)string font:(UIFont *)font lineBreakMode:(NSLineBreakMode)lineBreakMode withSize:(CGSize)size;
+ (CGSize) sizeWithString:(NSString *)string font:(UIFont *)font lineBreakMode:(NSLineBreakMode)lineBreakMode options:(NSStringDrawingOptions)options withSize:(CGSize)size;


+ (id) viewWithXIB:(NSString*)name;
+ (NSArray*) viewsWithXIB:(NSString*)name;

+ (id) viewWithXIB:(NSString*)name subviewWithTag:(NSInteger)subViewTag;
+ (id) viewsWithXIB:(NSString*)name tag:(NSInteger)tag subviewWithTag:(NSInteger)subViewTag;









#pragma mark - 二维码
+ (UIImage *)QRImageWithString:(NSString *)string size:(CGFloat)size;
+ (CIImage *)ciimageWithString:(NSString *)string;
/**
 *  根据CIImage生成指定大小的UIImage
 *
 *  @param image CIImage
 *  @param size  图片宽度
 */
+ (UIImage *) createNonInterpolatedUIImageFormCIImage:(CIImage *)image withSize:(CGFloat) size;



/* 通过总数、行数，计算列数 **/
+ (NSUInteger) columnFromCount:(NSUInteger)count row:(NSUInteger)row;


/* 将 数字中后面的 0 转变成中国的计算单位 十 到 秭 **/
+ (NSString *) ZeroToChinaCountingUnitStyleWithNumberString:(NSString *)numberString;
+ (NSString *) simpleZeroToChinaCountingUnitStyleWithNumberString:(NSString *)numberString;


+(NSData *) zipNSDataWithImage:(UIImage *)sourceImage;


+ (NSArray *) arrayWithObject:(id)object;

/**
 收起键盘
 */
+ (void) closeKeyboard;

@end
