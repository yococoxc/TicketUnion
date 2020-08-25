//
//  NSMutableDictionary+LQS.h
//  XLQSKit
//
//  Created by muzico on 2020/8/4.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSMutableDictionary (LQS)

/**
 anObject 在保存的时候，会将 NSNumber 转成 NSString
 */
- (void) lqs_setObject:(id)anObject forKey:(NSString *)key;

@end

