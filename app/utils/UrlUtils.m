//
//  UrlUtils.m
//  TicketUnion
//
//  Created by muzico on 2020/8/21.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "UrlUtils.h"

@implementation UrlUtils


+ (NSString *) getDiscoveryContentUrlWithCategoryId:(NSString *)categoryId withPage:(NSString *)page {
    NSString *temp = [NSString stringWithFormat:@"discovery/%@/%@",categoryId,page];
    return temp;
}

+ (NSString *) getOnSellUrlWithDefaultPage:(NSString *)defaultPage {
    NSString *temp = [NSString stringWithFormat:@"onSell/%@",defaultPage];
    return temp;
}

+ (NSString *) getTypContentUrlWithCategoryId:(NSString *)categoryId {
    NSString *temp = [NSString stringWithFormat:@"recommend/%@",categoryId];
    return temp;
}

@end
