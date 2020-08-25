//
//  HomeContentGapAdapter.m
//  TicketUnion
//
//  Created by muzico on 2020/8/25.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "HomeContentGapAdapter.h"
#import "HomeContentGapView.h"

@implementation HomeContentGapAdapter

- (NSInteger) numberOfCell {
    return 1;
}

- (CGFloat) heightOfSizeForCellAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section {
    return 50;
}

- (void) setupCellContentView:(LQSListItemView *)view withDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section {
    view.contentViewClass = [HomeContentGapView class];
}


@end
