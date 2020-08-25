//
//  SearchSectionContentAdapter.m
//  TicketUnion
//
//  Created by muzico on 2020/8/23.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "SearchSectionContentAdapter.h"

@implementation SearchSectionContentAdapter



- (UIEdgeInsets) insetForSectionAtIndex:(NSInteger)section {
    return UIEdgeInsetsMake(0, 16, 0, 16);
}
- (CGFloat) minimumLineSpacingForSectionAtIndex:(NSInteger)section {
    return 8;
}
- (CGFloat) minimumInteritemSpacingForSectionAtIndex:(NSInteger)section {
    return 8;
}

- (CGSize) sizeForCellAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section {
    id temp = [self.dataSource lqs_objectAtIndex:index];
    if ([temp lqs_isNSString] == NO) {
        return CGSizeZero;
    }
    
    UILabel *label = [UILabel new];
    label.text = temp;
    label.lqs_fontSize = 14;
    CGSize labelSize = [label sizeThatFits:CGSizeMake(CGFLOAT_MAX, CGFLOAT_MAX)];
    return CGSizeMake(labelSize.width + 16, labelSize.height + 8);
}


- (void) setupCellContentView:(LQSListItemView *)view withDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section {
    view.contentViewClass = [UILabel class];
    if ([view.contentView isKindOfClass:[UILabel class]]) {
        UILabel *tempView = (id)view.contentView;
        tempView.textAlignment = NSTextAlignmentCenter;
        tempView.lqs_textColor = @"#0a0a0a";
        tempView.lqs_layerCornerRadius = 8;
        [tempView lqs_setLayerBorderWidth:1 color:@"#c0c0c0"];
        tempView.lqs_fontSize = 14;
        
        if ([dataSource lqs_isNSString]) {
            tempView.text = dataSource;
        }
    }
}




@end
