//
//  LQSObject.h
//  XLQSKit
//
//  Created by muzico on 2020/7/31.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface LQSObject : NSObject

@property(nonatomic,assign) BOOL boolValue;
@property(nonatomic,assign) int intValue;
@property(nonatomic,assign) NSInteger integerValue;
@property(nonatomic,assign) CGFloat floatValue;
@property(nonatomic,copy) NSString *stringValue;


+ (instancetype) objectWithInteger:(NSInteger)integerValue;
+ (instancetype) objectWithFloat:(CGFloat)floatValue;
+ (instancetype) objectWithBOOL:(BOOL)boolValue;
+ (instancetype) objectWithString:(NSString *)stringValue;

@end

