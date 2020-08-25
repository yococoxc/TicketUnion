//
//  NSDictionary+LQS.h
//  LQSKit
//
//  Created by muzico on 2018/7/20.
//  Copyright © 2018年 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (LQS)

/**
 安全获取。
 一切对象将会变成  NSString，nil 除外。
 */
- (NSString*) lqs_toStringWithObjectForKey:(NSString*)key;



@end
