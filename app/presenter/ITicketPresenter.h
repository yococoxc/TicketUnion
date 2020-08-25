//
//  ITicketPresenter.h
//  TicketUnion
//
//  Created by muzico on 2020/8/22.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ITicketPresenter <NSObject>


/**
 获取淘口令
 */
- (void) loadTicketByItemWithURL:(NSString *)url withTitle:(NSString *)title withCover:(NSString *)cover;

@end

