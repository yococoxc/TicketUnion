//
//  SearchContentAdapter.m
//  TicketUnion
//
//  Created by muzico on 2020/8/23.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "SearchContentAdapter.h"

#import "SearchContentItemView.h"
#import "SearchContentItemView2.h"

#import "YYWebImage.h"

@implementation SearchContentAdapter

- (void) setupCollectionView:(UICollectionView *)collectionView {
    [self registerCollectionCellWithIdentifier:@"aaaa"];
    
    [self registerCollectionCellWithIdentifier:@"bbbb"];
}

- (CGFloat) heightOfSizeForCellAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section {
//    return 100;
    
    id dataSource = [self.dataSource lqs_objectAtIndex:index];
    if (dataSource) {
        
        NSString *zk_final_price = [dataSource lqs_objectForKey:@"zk_final_price"];
        
        NSString *coupon_amount = [dataSource lqs_objectForKey:@"coupon_amount"];
        if (zk_final_price && coupon_amount) {
            return 120;
        } else {
            return 100;
        }
        
    }
    return 0;
}
- (CGFloat) minimumLineSpacingForSectionAtIndex:(NSInteger)section {
    return 8;
}

- (UICollectionViewCell *) collectionViewCellWithDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section {
    
    
    if ([dataSource lqs_isNSDictionary]) {
        NSString *zk_final_price = [dataSource lqs_objectForKey:@"zk_final_price"];
        
        NSString *coupon_amount = [dataSource lqs_objectForKey:@"coupon_amount"];
        
        if (zk_final_price && coupon_amount) {
            LQSListCollectionViewCell * cell = [self.collectionView dequeueReusableCellWithReuseIdentifier:@"aaaa" forIndexPath:indexPath];
            
            cell.contentCell.contentViewClass = [SearchContentItemView2 class];
            if ([cell.contentCell.contentView isKindOfClass:[SearchContentItemView2 class]]) {
                SearchContentItemView2 *tempView = (id)cell.contentCell.contentView;
                
                if ([dataSource lqs_isNSDictionary]) {
                    tempView.titleLabel.text = [dataSource lqs_objectForKey:@"title"];
                    double tempValue = [dataSource lqs_doubleForKey:@"zk_final_price"] - [dataSource lqs_doubleForKey:@"coupon_amount"];
                    tempView.nowPriceLabel.text = [NSString stringWithFormat:@"券后价：%.2lf",tempValue];
                    tempView.priceLabel.text = [NSString stringWithFormat:@"¥%@",[dataSource lqs_objectForKey:@"zk_final_price"]];
                    tempView.numberLabel.text = [NSString stringWithFormat:@"%@人已购买",[dataSource lqs_objectForKey:@"volume"]];
                    tempView.infoLabel.text = [NSString stringWithFormat:@"省%@元",[dataSource lqs_objectForKey:@"coupon_amount"]];
                    NSString *url = [NSString stringWithFormat:@"%@",[dataSource lqs_objectForKey:@"pict_url"]];
                    if ([url hasPrefix:@"http://"] || [url hasPrefix:@"https://"]) {
                        
                    } else if ([url hasPrefix:@"//"]) {
                        url = [NSString stringWithFormat:@"https:%@",url];
                    }
                    [tempView.imageView yy_setImageWithURL:[NSURL URLWithString:url] placeholder:nil];
                }
            }
            
            return cell;
        } else {
            LQSListCollectionViewCell * cell = [self.collectionView dequeueReusableCellWithReuseIdentifier:@"bbbb" forIndexPath:indexPath];
            
            cell.contentCell.contentViewClass = [SearchContentItemView class];
            if ([cell.contentCell.contentView isKindOfClass:[SearchContentItemView class]]) {
                SearchContentItemView *tempView = (id)cell.contentCell.contentView;
                
                if ([dataSource lqs_isNSDictionary]) {
                    tempView.titleLabel.text = [dataSource lqs_objectForKey:@"title"];
//                    NSLog(@"%@",dataSource);
                    
                    tempView.priceLabel.text = [NSString stringWithFormat:@"¥%@",[dataSource lqs_objectForKey:@"zk_final_price"]];
                    tempView.otherLabel.text = [NSString stringWithFormat:@"%@人已购买",[dataSource lqs_objectForKey:@"volume"]];

                    NSString *url = [NSString stringWithFormat:@"%@",[dataSource lqs_objectForKey:@"pict_url"]];
                    
                    
                    if ([url hasPrefix:@"http://"] || [url hasPrefix:@"https://"]) {
                        
                    } else if ([url hasPrefix:@"//"]) {
                        url = [NSString stringWithFormat:@"https://%@",url];
                    }
                    [tempView.imageView yy_setImageWithURL:[NSURL URLWithString:url] placeholder:nil];
                }
            }
            
            return cell;
        }
    }
    
    
    
    LQSListCollectionViewCell * cell = [self.collectionView dequeueReusableCellWithReuseIdentifier:@"bbbb" forIndexPath:indexPath];
    cell.contentCell.contentViewClass = [SearchContentItemView class];
    return cell;
}

@end
