//
//  ISelectedPagePresenter.h
//  TicketUnion
//
//  Created by muzico on 2020/8/22.
//  Copyright © 2020 muzico. All rights reserved.
//


#import <Foundation/Foundation.h>

@protocol ISelectedPagePresenter <NSObject>

/**
 
 */
- (void) getPickType;

/**
 
 */
- (void) getPickContentById:(NSString *)categoryId;

@end

