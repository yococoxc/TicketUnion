//
//  PickerContentListAdapter.m
//  TicketUnion
//
//  Created by muzico on 2020/8/22.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "PickerContentListAdapter.h"
#import "PickListItem.h"

#import "YYWebImage.h"

@implementation PickerContentListAdapter

- (UIEdgeInsets) insetForSectionAtIndex:(NSInteger)section {
    return UIEdgeInsetsMake(8, 8, 8, 8);
}

- (CGFloat) minimumLineSpacingForSectionAtIndex:(NSInteger)section {
    return 8;
}

- (CGSize) sizeForCellAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section {
    CGFloat width = self.collectionView.lqs_width - 8 - 8;
    CGFloat height = 16 + width + 35;
    return CGSizeMake(width, height);
}

- (void) setupCellContentView:(LQSListItemView *)view withDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section {
    
    
    view.contentViewClass = [PickListItem class];
    if ([view.contentView isKindOfClass:[PickListItem class]]) {
        PickListItem *tempView = (id)view.contentView;
        
        NSString *url = [NSString stringWithFormat:@"%@",[dataSource lqs_objectForKey:@"pict_url"]];
        [tempView.imageView yy_setImageWithURL:[NSURL URLWithString:url] placeholder:nil];
        
        
        if ([[dataSource lqs_objectForKey:@"coupon_click_url"] lqs_length] == 0) {
            tempView.button.hidden = YES;
            tempView.priceLabel.hidden = YES;
            tempView.tipLabel.hidden = NO;
            tempView.otherView.hidden = YES;
        } else {
            tempView.button.hidden = NO;
            tempView.priceLabel.hidden = NO;
            tempView.tipLabel.hidden = YES;
            

            tempView.priceLabel.text = [NSString stringWithFormat:@"原价：%@",[dataSource lqs_objectForKey:@"zk_final_price"]];
            
            if ([[dataSource lqs_objectForKey:@"coupon_info"] lqs_length] == 0) {
                tempView.otherView.hidden = YES;
            } else {
                tempView.otherView.hidden = NO;
                tempView.otherLabel.text = [dataSource lqs_objectForKey:@"coupon_info"];
            }
        }
    }
}

@end
