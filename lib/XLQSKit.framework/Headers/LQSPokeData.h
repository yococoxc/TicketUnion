//
//  LQSPokeData.h
//  XLQSKit
//
//  Created by muzico on 2020/7/31.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "LQSObject.h"

@interface LQSPokeData : NSObject

+ (instancetype) sharedData;

/**
 寄放对象
 */
- (void) setObject:(id)anObject forKey:(NSString *)aKey;


- (void) setLQSObjectWithInteger:(NSInteger)aValue forKey:(NSString *)aKey;
- (void) setLQSObjectWithFloat:(CGFloat)aValue forKey:(NSString *)aKey;
- (void) setLQSObjectWithBOOL:(BOOL)aValue forKey:(NSString *)aKey;


/**
获取对象
*/
- (id) objectForKey:(NSString *)aKey;


- (LQSObject *) lqsObjectForKey:(NSString *)aKey;



/**
获取次对象，然后从寄放种删除对象
*/
- (id) onceObjectForKey:(NSString *)aKey;


- (LQSObject *) onceLQSObjectForKey:(NSString *)aKey;

/**
删除对象
*/
- (void) removeObjectForKey:(NSString *)aKey;





@end

