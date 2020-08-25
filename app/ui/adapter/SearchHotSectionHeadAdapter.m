//
//  SearchHotSectionHeadAdapter.m
//  TicketUnion
//
//  Created by muzico on 2020/8/23.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "SearchHotSectionHeadAdapter.h"
#import "SearchSectionHeadView.h"

@implementation SearchHotSectionHeadAdapter

- (NSInteger) numberOfCell {
    return 1;
}


- (UIEdgeInsets) insetForSectionAtIndex:(NSInteger)section {
    return UIEdgeInsetsMake(16, 16, 4, 16);
}

- (CGFloat) heightOfSizeForCellAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section {
    return 44;
}

- (void) setupCellContentView:(LQSListItemView *)view withDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section {
    view.contentViewClass = [SearchSectionHeadView class];
    if ([view.contentView isKindOfClass:[SearchSectionHeadView class]]) {
        SearchSectionHeadView *tempView = (id)view.contentView;
        tempView.label.text = @"热门搜索";
        tempView.button.hidden = YES;
    }
}

@end
