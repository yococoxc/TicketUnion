//
//  LQSRequestBean.h
//  reApp
//
//  Created by muzico on 2020/8/1.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, LQSRequestBeanDataType) {
    LQSRequestBeanDataTypeUnknown,
    LQSRequestBeanDataTypeArray,
    LQSRequestBeanDataTypeDictionary,
    LQSRequestBeanDataTypeString,
    LQSRequestBeanDataTypeNumber,
    LQSRequestBeanDataTypeNull,
};

@interface LQSRequestBean : NSObject


@property(nonatomic,copy)NSData* coreData;
@property(nonatomic,copy) NSURLResponse* coreResponse;
@property(nonatomic,copy) NSHTTPURLResponse* coreHttpResponse;
@property(nonatomic,assign) NSInteger coreHttpResponseStatusCode;
@property(nonatomic,copy) NSError* coreError;
@property(nonatomic,copy) NSString* coreJsonString;
@property(nonatomic,copy) id coreJson;



@property(nonatomic,copy,readonly) NSString *ResultCD;

@property(nonatomic,copy,readonly) NSString *RequestUrl;

@property(nonatomic,copy,readonly) NSString *ErrorMsg;

/**
 返回内容的主体，data，或 Data
 */
@property(nonatomic,strong,readonly) id data;
/**
返回内容的主体，data，或 Data 中的 list。Data: { list : [] }
*/
@property(nonatomic,strong,readonly) NSArray *data_list;

/**
返回内容的主体，data，或 Data 中的 data。Data: { data : [] }
*/
@property(nonatomic,strong,readonly) id data_data;
/**
返回内容的主体，data，或 Data 中的 list。Data: { count : 123 }
*/
@property(nonatomic,strong,readonly) NSString *data_count;


@property(nonatomic,assign,readonly) LQSRequestBeanDataType dataType;
@property(nonatomic,readonly) NSArray *dataArray;
@property(nonatomic,readonly) NSDictionary *dataDictionary;
@property(nonatomic,readonly) NSString *dataString;
@property(nonatomic,readonly) NSNumber *dataNumber;



+ (instancetype) beanWithDataSource:(id)dataSource;

@end


/**
 本 Bean 设定为返回到数据结构为：
 ````
 {
 "RequestUrl": "api/V1/abc",
 "ResultCD": "200",
 "ErrorMsg": "操作成功",
 "Data": 返回内容。
 }
 ```
 */
