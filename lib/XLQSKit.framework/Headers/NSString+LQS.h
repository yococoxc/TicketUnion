//
//  NSString+LQS.h
//  LQSKit
//
//  Created by muzico on 2018/7/20.
//  Copyright © 2018年 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSString (LQS)


- (BOOL) lqs_containsString:(NSString*)string;

/*
 不推荐使用，建议使用 lqs_isNotEmpty 来代替。
- (BOOL) lqs_isEmpty;
*/

@property(nonatomic,readonly) BOOL lqs_isNotEmpty;

/**
 判断是否纯数字，不含任何符号。
 */
@property(nonatomic,readonly) BOOL lqs_isPureNumberString;
/**
 判断是否纯数字，不含任何符号。，而且只有11个字符构成。
 */
@property(nonatomic,readonly) BOOL lqs_isPureNumberString11;

/**
 iOS 13 开始，苹果不推荐使用 MD5 加密，推荐 SHA256 或其他
 */
@property(nonatomic,readonly) NSString* lqs_MD5;

@property(nonatomic,readonly) NSString* lqs_SHA256;

@property(nonatomic,readonly) NSURL* lqs_NSURL;
@property(nonatomic,readonly) NSURL* lqs_toNSURL;
@property(nonatomic,readonly) NSURLRequest* lqs_NSURLRequest;
@property(nonatomic,readonly) NSURLRequest* lqs_toNSURLRequest;


@property(nonatomic,readonly) NSURL* lqs_toFileURL;


/**
 字符串转URL识别的编码，如：【你好啊】转成【%E4%BD%A0%E5%A5%BD%E5%95%8A】。
 */
@property(nonatomic,readonly) NSString* lqs_URLCharacter;
@property(nonatomic,readonly) NSString* lqs_toURLCharacter;




/**
 字符串转二维码。
 */
- (UIImage *) lqs_QRCodeWithSize:(CGFloat)size;

@end
