//
// Created by muzico on 2020/8/22.
// Copyright (c) 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol IQrCodeScanPageCallback <NSObject>
/**
 解释成功
 */
- (void) onHandleSuccess;

/**
 解释失败
 */
- (void) onHandleFailure;

@end