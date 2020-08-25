//
//  IHomePagePresenter.h
//  TicketUnion
//
//  Created by muzico on 2020/8/21.
//  Copyright © 2020 muzico. All rights reserved.
//


#import <Foundation/Foundation.h>

@protocol IHomePagePresenter <NSObject>

/**
 加载默认数据
 */
- (void) loadCategories;

@end
