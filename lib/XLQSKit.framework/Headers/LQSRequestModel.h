//
//  LQSRequestModel.h
//  reApp
//
//  Created by muzico on 2020/8/1.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "LQSRequestBean.h"
#import "LQSRequestCallback.h"


#define LQSRequestModelInstantiation ([LQSRequestModel new])
#define LQSRequestModelPost ([LQSRequestModel modelWithPost])
#define LQSRequestModelGet ([LQSRequestModel modelWithGet])

typedef void(^LQSRequestModelSuccessBlock)(LQSRequestBean *bean);//成功
typedef void(^LQSRequestModelFailureBlock)(NSError *error, BOOL isServerError, LQSRequestBean *bean);//失败

@interface LQSRequestModel : NSObject


/**
 链接
 */
@property (nonatomic,copy) NSString *URLString;

/**
 URL路径，会拼接到 URLString 后面。
 */
@property (nonatomic,copy) NSString *URLPathString;
/**
 方法。
 默认为POST.
 */
@property (nonatomic,copy) NSString *HTTPMethod;
/**
 头部信息
 */
@property (nonatomic,strong) NSDictionary *HTTPHeader;
/**

*/
@property (nonatomic,copy) NSString *HTTPBodyString;
/**
 参数
 */
@property (nonatomic,strong) NSDictionary *parameter;

/**
requestWithDoSomething 方法时，可以获得最终 请求 URL
*/
@property (nonatomic,strong) NSString *targetURLString;



+ (instancetype) modelWithPost;
+ (instancetype) modelWithGet;


- (LQSRequestModel *(^)(NSString *)) url;
- (LQSRequestModel *(^)(NSString *)) urlPath;
- (LQSRequestModel *(^)(NSString *)) method;

- (LQSRequestModel *(^)(NSString *)) bodyString;
- (LQSRequestModel *(^)(NSDictionary *)) headers;
- (LQSRequestModel *(^)(NSDictionary *)) parames;

- (LQSRequestModel *(^)(LQSRequestModelSuccessBlock)) success;
- (LQSRequestModel *(^)(LQSRequestModelFailureBlock)) failure;
- (LQSRequestModel *(^)(void)) request;


/**
 request() 执行后。会执行下面的方法进行内置请求。如有特殊要求，可以重新这个方法。
 目前只是post请求处理了，
 */
- (void) requestWithDoSomething;

@end

