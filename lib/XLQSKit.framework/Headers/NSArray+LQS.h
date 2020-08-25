//
//  NSArray+LQS.h
//  LQSKit
//
//  Created by muzico on 2018/7/20.
//  Copyright © 2018年 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (LQS)

- (BOOL) lqs_isEqualToArray:(NSArray<NSString*>*)array;

/*升序*/
- (NSArray *) lqs_sortByASC;

/*降序*/
- (NSArray *) lqs_sortByDESC;

/**从数组中随机获取一个内容*/
- (id) lqs_randomValue;

/**
 是否包含这个字符串
 */
- (BOOL) lqs_containString:(NSString *)string;

- (NSArray *) lqs_subarrayWithRange:(NSRange)range;

@end



