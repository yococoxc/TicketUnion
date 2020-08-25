//
//  HomePagePresenterImpl.m
//  TicketUnion
//
//  Created by muzico on 2020/8/21.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "HomePagePresenterImpl.h"
#import "IHomePageCallback.h"

@implementation HomePagePresenterImpl

- (void)loadCategories {
    LQSRequestModel *categories = [self.mApi getCategories];
    categories.success(^(LQSRequestBean *bean) {
        
        if (bean.coreHttpResponseStatusCode == 200) {
            
            if ([bean.data lqs_isNSArray]) {
                [self updateCategories:bean.data];
            }
        } else {
            
        }
    }).failure(^(NSError *error, BOOL isServerError, LQSRequestBean *bean) {
        
    }).request();
}

- (void) updateCategories:(id)reuslt {
    for (id<IHomePageCallback> callback in self.callbacks) {
        [callback onCategoriesLoaded:reuslt];
    }
}

@end
