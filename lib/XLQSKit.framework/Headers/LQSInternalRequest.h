//
//  LQSInternalRequest.h
//  reApp
//
//  Created by muzico on 2020/8/1.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LQSRequestBean.h"
#import "LQSRequestModel.h"

/**
 前身为CommondRequest，
 由于与其他项目冲突于是更名加入到全家桶中。
 这个属于内置请求器，但当你不需要这个时，放弃即可。
 */


typedef void(^LQSInternalRequestStartBlock)(void);//开始
typedef void(^LQSInternalRequestSuccessBlock)(LQSRequestBean *bean);//成功
typedef void(^LQSInternalRequestFailureBlock)(NSError *error, BOOL isServerError, LQSRequestBean *bean);//失败
typedef void(^LQSInternalRequestEndBlock)(void);//结束


@interface LQSInternalRequest : NSObject

+ (void) postWithURL:(NSString *)url
          HTTPHeader:(NSDictionary *)HTTPHeader
      HTTPBodyString:(NSString *)HTTPBodyString
               param:(id)param
               start:(LQSInternalRequestStartBlock)start
             success:(LQSInternalRequestSuccessBlock)success
             failure:(LQSInternalRequestFailureBlock)failure
                 end:(LQSInternalRequestEndBlock)end
           HUDToView:(id)view;



+ (void) getWithURL:(NSString *)url
         HTTPHeader:(NSDictionary *)HTTPHeader
              param:(id)param
              start:(LQSInternalRequestStartBlock)start
            success:(LQSInternalRequestSuccessBlock)success
            failure:(LQSInternalRequestFailureBlock)failure
                end:(LQSInternalRequestEndBlock)end
          HUDToView:(id)view;


+ (void) requestWithURL:(NSString *)url param:(id)param  header:(NSDictionary *)header;

@end

