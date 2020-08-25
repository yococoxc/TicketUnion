//
//  ITicketCallback.h
//  TicketUnion
//
//  Created by muzico on 2020/8/21.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "IBaseViewCallback.h"

@protocol ITicketCallback <IBaseViewCallback>

@required
/**
 结果
 */
- (void) onTicketLoadedWithResult:(id)result withCover:(NSString *)cover;

@end

