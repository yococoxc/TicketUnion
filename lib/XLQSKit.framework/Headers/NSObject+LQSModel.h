//
//  NSObject+LQSModel.h
//  LQSKit
//
//  Created by muzico on 2019/9/2.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSObject (LQSModelCustomContent)


+ (instancetype) lqs_objectWithKeyValues:(id)keyValues;

+ (NSMutableArray *) lqs_objectArrayWithKeyValuesArray:(NSArray *)keyValuesArray;


//+ (instancetype) lqs_objectWithKeyValues:(id)keyValues;
//
//+ (NSMutableArray *) lqs_objectArrayWithKeyValuesArray:(NSArray *)keyValuesArray;


+ (NSDictionary *) lqs_replacedKeyFromPropertyName;

+ (NSDictionary *) lqs_defineArrayTypeFromPropertyName;

@end

