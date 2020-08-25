//
//  LQSIntent.h
//  LQSIntent研究协会
//
//  Created by muzico on 2019/12/2.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@class LQSIntent;


@protocol LQSIntentDelegate <NSObject>

- (void) onViewControllerResultWithRequestCode:(int)requestCode resultCode:(int)resultCode data:(LQSIntent *)data;

@end




@interface LQSIntent : NSObject

//获取当前页面的 Intent对象
+ (instancetype) getIntent;

//创建 Intent对象，明确表示跳转的对象关系
+ (instancetype) intentWithActivity:(UIViewController *)activity andNewActivity:(Class)newActivityClass;

//加入数据
- (void) putExtra:(NSDictionary *)info;

//立即跳转到新页面
- (void) startActivity;
//立即跳转到新页面，并且向当前页面返回数据
- (void) startActivityForResult:(int)integerValue;

//获取数据
- (NSString *) getStringExtra:(NSString *)key;

//执行返回数据
- (void) setResultWithResultCode:(int)resultCode;

@end
