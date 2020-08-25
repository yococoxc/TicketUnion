//
//  Api.h
//  TicketUnion
//
//  Created by muzico on 2020/8/21.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XLQSKit/XLQSKit.h>

@interface Api : NSObject

/**
 获取到分类
 */
- (LQSRequestModel *) getCategories;

/**
根据分类，获取到内容
*/
- (LQSRequestModel *) getContentListByMaterialIdWithURL:(NSString *)url;

/**
获取淘口令
*/
- (LQSRequestModel *) getTicketByUrl:(NSDictionary *)parames;

/**
获取特惠内容
*/
- (LQSRequestModel *) getOnSellGoodsWithURL:(NSString *)url;

/**
获取精选的类型
*/
- (LQSRequestModel *) getPickTypeList;

/**
获取精选内容
*/
- (LQSRequestModel *) getPickContentListWithURL:(NSString *)url;

/**
搜索
*/
- (LQSRequestModel *) doSearchWithKeyword:(NSString *)keyword page:(NSString *)page;

/**
获取搜索推荐
*/
- (LQSRequestModel *) getSearchRecommend;

@end


