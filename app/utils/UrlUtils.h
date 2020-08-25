//
//  UrlUtils.h
//  TicketUnion
//
//  Created by muzico on 2020/8/21.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>



@interface UrlUtils : NSObject

+ (NSString *) getDiscoveryContentUrlWithCategoryId:(NSString *)categoryId withPage:(NSString *)page;

+ (NSString *) getOnSellUrlWithDefaultPage:(NSString *)defaultPage;

+ (NSString *) getTypContentUrlWithCategoryId:(NSString *)categoryId;

@end
