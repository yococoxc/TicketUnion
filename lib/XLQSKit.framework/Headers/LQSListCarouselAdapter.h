//
//  LQSListCarouselAdapter.h
//  XLQSKit
//
//  Created by muzico on 2020/7/2.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <XLQSKit/XLQSKit.h>
#import "LQSCarousel.h"



@interface LQSListCarouselAdapter : LQSListAdapter<LQSCarouselDataSource,LQSCarouselDelegate>

@property(nonatomic,strong) LQSCarousel *carousel;

/**
 重写这个编辑内容。默认为UIImageView
 */
- (void) setupCarouselCell:(CommonCollectionCell *)cell withDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index;
/**
 基于上面简化的。
 */
- (void) setupImageView:(UIImageView *)imageView withData:(id)data;

@end

