//
//  PickTypeAdapter.m
//  TicketUnion
//
//  Created by muzico on 2020/8/22.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "PickTypeAdapter.h"


#import "PickerTypeItem.h"

@implementation PickTypeAdapter

- (CGFloat) heightOfSizeForCellAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section {
    return 44;
}

- (void) setupCellContentView:(LQSListItemView *)view withDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section {
    
    view.contentViewClass = [PickerTypeItem class];
    if ([view.contentView isKindOfClass:[PickerTypeItem class]]) {
        PickerTypeItem *tempView = (id)view.contentView;
        tempView.label.text = [dataSource lqs_objectForKey:@"favorites_title"];
        
        if (self.currentIndex == index) {
            tempView.lqs_backgroundColor = @"#f0f0f0";
        } else {
            tempView.lqs_backgroundColor = @"#ffffff";
        }
    }
}

- (void) didSelectCellWithDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section {
    self.currentIndex = index;
    [self reloadData];
    
    if (self.didSelectCell) {
        self.didSelectCell(dataSource, indexPath);
    }
}

@end
