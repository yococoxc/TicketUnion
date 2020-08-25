//
//  OnSellListAdapter.m
//  TicketUnion
//
//  Created by muzico on 2020/8/22.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "OnSellListAdapter.h"

#import "OnSellListItem.h"
#import "YYWebImage.h"


@interface OnSellListAdapter ()

@property(nonatomic,assign) CGFloat imageSize;

@end


@implementation OnSellListAdapter


- (UIEdgeInsets) insetForSectionAtIndex:(NSInteger)section {
    return UIEdgeInsetsMake(8, 8, 8, 8);
}

- (CGFloat) minimumLineSpacingForSectionAtIndex:(NSInteger)section {
    return 8;
}

- (CGSize) sizeForCellAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section {
    CGFloat width = (self.collectionView.lqs_width - 8 - 8 - 8) / 2.0;
    
    self.imageSize = width;
    
    CGFloat height = 8 + width + 8 + 28 + 8 + 14 + 8;
    return CGSizeMake(width, height);
}

- (void) setupCellContentView:(LQSListItemView *)view withDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section {
    
    view.contentViewClass = [OnSellListItem class];
    if ([view.contentView isKindOfClass:[OnSellListItem class]]) {
        OnSellListItem *tempView = (id)view.contentView;
        tempView.titleLabel.text = [dataSource lqs_objectForKey:@"title"];
        tempView.priceLabel.text = [dataSource lqs_objectForKey:@"zk_final_price"];
        
        
        CGFloat tempValue = [dataSource lqs_doubleForKey:@"zk_final_price"] - [dataSource lqs_doubleForKey:@"coupon_amount"];
        tempView.otherLabel.text = [NSString stringWithFormat:@"券后价：%.2f", tempValue];
        
        
        NSString *url = [NSString stringWithFormat:@"https:%@",[dataSource lqs_objectForKey:@"pict_url"]];
        [tempView.imageView yy_setImageWithURL:[NSURL URLWithString:url] placeholder:nil];
    }
}

@end
