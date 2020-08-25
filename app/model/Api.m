//
//  Api.m
//  TicketUnion
//
//  Created by muzico on 2020/8/21.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "Api.h"

@interface Api ()

@property(nonatomic,readonly) NSString *baseURL;

@end

@implementation Api


- (NSString *) baseURL {
    return @"https://api.sunofbeach.net/shop/";
}

/**
 获取到分类
 */
- (LQSRequestModel *) getCategories {
    return LQSRequestModelGet.url(self.baseURL).urlPath(@"discovery/categories");;
}

/**
根据分类，获取到内容
*/
- (LQSRequestModel *) getContentListByMaterialIdWithURL:(NSString *)url {
    return LQSRequestModelGet.url(self.baseURL).urlPath(url);
}

/**
获取淘口令
*/
- (LQSRequestModel *) getTicketByUrl:(NSDictionary *)parames {
    return LQSRequestModelPost.url(self.baseURL).urlPath(@"tpwd").parames(parames).headers(@{@"Content-Type": @"application/json"}).bodyString([parames lqs_toString]);
}

/**
获取特惠内容
*/
- (LQSRequestModel *) getOnSellGoodsWithURL:(NSString *)url {
    return LQSRequestModelGet.url(self.baseURL).urlPath(url);
}

/**
获取精选的类型
*/
- (LQSRequestModel *) getPickTypeList {
    return LQSRequestModelGet.url(self.baseURL).urlPath(@"recommend/categories");
}

/**
获取精选内容
*/
- (LQSRequestModel *) getPickContentListWithURL:(NSString *)url {
    return LQSRequestModelGet.url(self.baseURL).urlPath(url);
}

/**
搜索
*/
- (id) doSearchWithKeyword:(NSString *)keyword page:(NSString *)page {
    NSMutableDictionary *dic = [NSMutableDictionary dictionary];
    [dic lqs_setObject:keyword forKey:@"keyword"];
    [dic lqs_setObject:page forKey:@"page"];
    return LQSRequestModelGet.url(self.baseURL).urlPath(@"search").parames(dic);
}

/**
获取搜索推荐
*/
- (id) getSearchRecommend {
    return LQSRequestModelGet.url(self.baseURL).urlPath(@"search/recommend");
}

@end
