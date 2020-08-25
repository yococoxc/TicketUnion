//
//  LQSWeakObjectManager.h
//  LQSKit
//
//  Created by muzico on 2018/12/29.
//  Copyright © 2018 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LQSWeakObjectItem : NSObject

@property(nonatomic,weak) id object;

@end

@interface LQSWeakObjectManager : NSObject


#pragma mark - 数组
#pragma mark -
@property(readonly) NSArray *array;

- (void) addItem:(LQSWeakObjectItem *)item;

- (void) addItemWithObject:(id)object;

- (void) removeItem:(LQSWeakObjectItem *)item;

- (void) removeItemWithObject:(id)object;

#pragma mark - 字典
#pragma mark -
@property(readonly) NSDictionary *dictionary;

- (void) setItem:(LQSWeakObjectItem *)item forKey:(NSString *)key;

- (void) setItemWithObject:(id)object forKey:(NSString *)key;

- (void) removeItemForKey:(NSString *)key;

@end
