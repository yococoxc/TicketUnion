//
//  LQSAbc.h
//  ssss
//
//  Created by muzico on 2019/12/3.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 路由 + intent => Erutis （局限在VC）
 Erutis 基础上改造成全方位 LQSAbc
 
 PS：
 Intent 的实现是 LQSIntent，路由的实现是LQSRouter。
 */

@class LQSAbc;


typedef void(^LQSAbcAPIStartBlock)(LQSAbc *item);//开始
typedef void(^LQSAbcAPISuccessBlock)(LQSAbc *item, id response, id dataSource);//成功
typedef void(^LQSAbcAPIFailureBlock)(LQSAbc *item, NSError *error, BOOL isServerError, id response);//失败
typedef void(^LQSAbcAPIEndBlock)(LQSAbc *item);//结束


@protocol LQSAbcDelegate <NSObject>
@optional
#pragma mark - 向 LQSAbc 实例 传递importObject对象（但不是必要）
- (NSObject *) lqsAbc:(LQSAbc *)abc importObjectWithKey:(NSString *)key code:(NSInteger)code userInfo:(NSDictionary *)userInfo;

#pragma mark - LQSAbc 实例执行的内容
- (void) lqsAbc:(LQSAbc *)abc actionWithKey:(NSString *)key code:(NSInteger)code userInfo:(NSDictionary *)userInfo;

@end

#pragma mark -
@protocol LQSAbcResultDelegate <NSObject>
@optional
#pragma mark - LQSAbc 实例的exportObject 所实现的方法。
- (void) lqsAbc:(LQSAbc *)abc resultWithKey:(NSString *)key code:(NSInteger)code userInfo:(NSDictionary *)userInfo;

@end

#pragma mark -
@protocol LQSAbcAPIDelegate <NSObject>
@optional
#pragma mark -
- (void) lqsAbc:(LQSAbc *)abc apiStartWithapiStartWithKey:(NSString *)key code:(NSInteger)code userInfo:(NSDictionary *)userInfo;
- (void) lqsAbc:(LQSAbc *)abc apiSuccessWithKey:(NSString *)key response:(id)response dataSource:(id)dataSource code:(NSInteger)code userInfo:(NSDictionary *)userInfo;
- (void) lqsAbc:(LQSAbc *)abc apiFailureWithKey:(NSString *)key response:(id)response error:(NSError *)error isServerError:(BOOL)isServerError code:(NSInteger)code userInfo:(NSDictionary *)userInfo;
- (void) lqsAbc:(LQSAbc *)abc apiEndWithKey:(NSString *)key code:(NSInteger)code userInfo:(NSDictionary *)userInfo;

@end

#pragma mark -
@interface NSObject ()<LQSAbcDelegate,LQSAbcResultDelegate,LQSAbcAPIDelegate>
@end

#pragma mark -
@interface LQSAbc : NSObject

@property(nonatomic,weak,readonly) id exportObject;

@property(nonatomic,weak,readonly) id importObject;

@property(nonatomic,strong) NSDictionary *extra;

#pragma mark - 注册 module 实例、module 实例类字符串
+ (BOOL) registerModule:(NSObject *)module forKey:(NSString *)key;

#pragma mark - 获取 LQSAbc 实例
+ (instancetype) abcForExportObject:(id)exportObject;
+ (instancetype) abcForImportObject:(id)importObject;

#pragma mark - 创建 LQSAbc 实例
+ (instancetype) abcWithObject:(id)exportObject;
+ (instancetype) abcWithObject:(id)exportObject importObject:(id)importObject;

#pragma mark - 执行 LQSAbc 实例，并且将 LQSAbc 进行缓存。
- (void) actionWithKey:(NSString *)key userInfo:(NSDictionary *)userInfo;
- (void) actionWithKey:(NSString *)key code:(NSInteger)code userInfo:(NSDictionary *)userInfo;

#pragma mark - exportObject 对象将会 执行LQSAbcResultDelegate
- (void) resultWithCode:(NSInteger)code userInfo:(NSDictionary *)userInfo;

#pragma mark - exportObject 对象将会 执行LQSAbcAPIDelegate
- (void) apiStart;
- (void) apiEnd;
- (void) apiSuccessWithResponse:(id)response dataSource:(id)dataSource;
- (void) apiFailureWithResponse:(id)response error:(NSError *)error isServerError:(BOOL)isServerError;

#pragma mark - 从缓存中移除。
/**
 从缓存中移除。并且会继续执行 removeNotExportObject。
 */
- (void) remove;

#pragma mark - 从缓存中移除没有ExportObject的。
+ (void) removeNotExportObject;

@end

