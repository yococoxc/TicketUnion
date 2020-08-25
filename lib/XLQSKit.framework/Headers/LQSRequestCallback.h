//
//  LQSRequestCallback.h
//  reApp
//
//  Created by muzico on 2020/8/1.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>




@protocol LQSRequestCallback <NSObject>

- (void) onSuccessful:(id)anyObject;

- (void) onFaild:(NSString *)errorMsg withError:(NSError *)error;

- (void) onError:(NSError *)error;

- (void) onStart;

- (void) onEnd;

@end



typedef void(^LQSRequestCallbackStartOrEndBlock)(void);//开始或结束
typedef void(^LQSRequestCallbackSuccessBlock)(id data);//成功
typedef void(^LQSRequestCallbackFailureBlock)(NSString *errorMessage, NSError *error);//失败
typedef void(^LQSRequestCallbackErrorBlock)(NSError *error);//失败


@interface LQSRequestCallback : NSObject<LQSRequestCallback>

- (LQSRequestCallback *(^)(LQSRequestCallbackStartOrEndBlock)) start;
- (LQSRequestCallback *(^)(LQSRequestCallbackSuccessBlock)) success;
- (LQSRequestCallback *(^)(LQSRequestCallbackFailureBlock)) failure;
- (LQSRequestCallback *(^)(LQSRequestCallbackErrorBlock)) error;
- (LQSRequestCallback *(^)(LQSRequestCallbackStartOrEndBlock)) end;

@end
