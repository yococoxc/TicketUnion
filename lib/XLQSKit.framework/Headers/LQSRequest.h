//
//  LQSRequest.h
//  LQSKit
//
//  Created by muzico on 2018/7/20.
//  Copyright © 2018年 muzico. All rights reserved.
//


/**
 2019-07-08
 加入【忽略证书的验证，直接信任】的支持。
 */

#import <Foundation/Foundation.h>
#import "LQSRequestParse.h"

@class LQSRequest;
@class LQSRequestResult;

typedef void(^LQSRequestBlock)(LQSRequest* request);
typedef void(^LQSRequestResultBlock)(LQSRequest* request, LQSRequestResult* result);

@interface LQSRequestResult : NSObject

@property(nonatomic,copy)NSData* data;
@property(nonatomic,copy) NSURLResponse* response;
@property(nonatomic,copy) NSError* error;

@property(nonatomic,copy) NSString* jsonString;
@property(nonatomic,copy) id json;

@end



@interface LQSRequest : NSObject

@property(nonatomic,assign) BOOL canLogDeallocInfo;

@property(nonatomic,strong) NSString* tag;


@property(nonatomic,strong) NSString* URLString;

/**
 *  设置超时时间。
 */
@property(nonatomic,assign) NSTimeInterval timeoutInterval;

/**
 *  请求方式默认是GET。
 */
@property(nonatomic,strong) NSString* HTTPMethod;

/**
 *  设置目标。
 */
@property(nonatomic,weak) id target;


/**
 *  参数。
 *  格式为 key1=value1&key2=value2&...
 *  比起其他设置参数，优先级最高。比设置 parameter 高，比 - (void) setHTTPBody:(NSString*)value forKey:(NSString*)key; 高
 */
@property(nonatomic,copy) NSString *HTTPBodyString;


/**
 *  参数。
 *  要追加参数，请用下面的方法：
 *  - (void) setHTTPBody:(NSString*)value forKey:(NSString*)key;
 */
@property(nonatomic) NSDictionary* parameter;

/**
 *  核心请求体。
 */
@property(nonatomic,strong) NSMutableURLRequest* URLRequest;


/**
 *  当该属性有值时，将以 [NSURLSession sessionWithConfiguration:config] 方式创建 NSURLSession。
 *  否则将会继续以 [NSURLSession sharedSession] 方式创建 NSURLSession。
 *
 *
 *  关于 connectionProxyDictionary 的资料。https://developer.apple.com/library/archive/documentation/Networking/Conceptual/SystemConfigFrameworks/SC_UnderstandSchema/SC_UnderstandSchema.html
 */
@property(nonatomic,strong) NSURLSessionConfiguration *sessionConfiguration;

/**
 *  下面四个方法，将会配置 sessionConfiguration 的 connectionProxyDictionary 属性。
 *  若 sessionConfiguration 为 nil，将会自动创建。
 */
- (void) proxyWithHTTP:(NSString *)httpServer port:(NSInteger)port;
- (void) proxyWithHTTP:(NSString *)httpServer port:(NSInteger)port enable:(BOOL)enable;

- (void) proxyWithHTTPS:(NSString *)httpsServer port:(NSInteger)port;
- (void) proxyWithHTTPS:(NSString *)httpsServer port:(NSInteger)port enable:(BOOL)enable;

/**
 *  核心对象。
 *  默认为[NSURLSession sharedSession] 方式创建出来，还有通过 sessionConfiguration 配置出来的。
 */
@property(nonatomic,strong) NSURLSession *session;


#pragma mark - 配置请求
/**
 *  设置请求头。
 */
- (void) setValue:(NSString*)value forHTTPHeaderField:(NSString *)key;
/**
 *  设置参数body参数。单个。
 */
- (void) setHTTPBody:(NSString*)value forKey:(NSString*)key;

#pragma mark - 配置处理方法
/**
 *  startBlock 配置请求开始前的处理。
 *  endBlock   配置请求结束后的处理。
 */
- (void) setupStartBlock:(LQSRequestBlock)startBlock
                endBlock:(LQSRequestBlock)endBlock;
/**
 *  配置请求完的处理。
 *
 *  successBlock 是请求成功的处理。
 *  failureBlock 是请求失败的处理。
 *
 *  finishBlock  是请求完成的处理，包括成功与失败。
 *  当这个被配置而存在时，上述的successBlock、failureBlock都不会被执行。
 */
- (void) setupSuccessBlock:(LQSRequestResultBlock)successBlock
              failureBlock:(LQSRequestResultBlock)failureBlock;
- (void) setupFinishBlock:(LQSRequestResultBlock)finishBlock;
#pragma mark - 执行方法
/**
 *  进行请求操作。
 */
- (void) request;
- (void) GetRequest;
- (void) PostRequest;
/**
 *  进行唯一的请求操作。
 */
- (void) requestWithOnly:(BOOL*)isOnly;
- (void) GetRequestWithOnly:(BOOL*)isOnly;
- (void) PostRequestWithOnly:(BOOL*)isOnly;

+ (instancetype) requestWithURLString:(NSString *)urlString
                                param:(id)param
                                start:(LQSRequestBlock)start
                              success:(LQSRequestResultBlock)success
                              failure:(LQSRequestResultBlock)failure
                                  end:(LQSRequestBlock)end;

@end

