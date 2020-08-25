//
//  IBaseViewCallback.h
//  TicketUnion
//
//  Created by muzico on 2020/8/21.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol IBaseViewCallback <NSObject>

@required
/**
 加载中
 */
- (void) onLoading;

/**
 网络错误
 */
- (void) onError;

/**
 内容为空
 */
- (void) onEmpty;

@end
