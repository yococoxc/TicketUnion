//
//  LQSPredefined.h
//  LQSKit
//
//  Created by muzico on 2018/7/26.
//  Copyright © 2018年 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

UIEdgeInsets LQS_SafeAreaInsets(void);



typedef void(^LQSCallbackIdBlock)(id object);
typedef void(^LQSCallbackEmptyBlock)(void);
typedef void(^LQSCallbackButtonBlock)(UIButton *button);
typedef void(^LQSCallbackViewControllerBlock)(UIViewController *viewController);
typedef void(^LQSCallbackIndexBlock)(NSInteger index);
typedef void(^LQSCallbackStringIndexBlock)(NSString *string,NSInteger index);
typedef void(^LQSCallbackStringBlock)(NSString *string);
typedef void(^LQSCallbackString2Block)(NSString *string,NSString *otherString);


typedef void(^LQSCallbackDictionaryBlock)(NSDictionary *dictionary);
typedef void(^LQSCallbackArrayBlock)(NSArray *array);


typedef void(^LQSCallbackUIntegerBlock)(NSUInteger uIntegerValue);
typedef void(^LQSCallbackIntegerBlock)(NSInteger integerValue);
typedef void(^LQSCallbackBoolBlock)(BOOL boolValue);
typedef void(^LQSCallbackDoubleBlock)(double doubleValue);
typedef void(^LQSCallbackFloatBlock)(float floatValue);
typedef void(^LQSCallbackCGFloatBlock)(CGFloat cgFloatValue);

@interface LQSPredefined : NSObject

@end
