//
//  LQSLQSCWCarouselProtocol.h
//  XLQSKit
//
//  Created by muzico on 2020/7/2.
//  Copyright © 2020 muzico. All rights reserved.
//

#ifndef LQSCWCarouselProtocol_h
#define LQSCWCarouselProtocol_h

@class LQSCWCarousel;
@protocol LQSCWCarouselDelegate<NSObject>
/**
 轮播图点击代理
 @param carousel 轮播图实例对象
 @param index 被点击的下标
 */
- (void) lqscwCarousel:(LQSCWCarousel *)carousel didSelectedAtIndex:(NSInteger)index;

@optional

/**
 将要开始滑动时,会触发该代理
 @param carousel 轮播图控件
 @param index 开始滑动时,处于中心点图片的下标
 @param indexPathRow 开始滑动时,处于中心点图片的在控件内部的实际下标
 */
- (void) lqscwCarousel:(LQSCWCarousel *)carousel didStartScrollAtIndex:(NSInteger)index indexPathRow:(NSInteger)indexPathRow;


/**
 滑动结束后,会触发该代理
 @param carousel 轮播图控件
 @param index 结束滑动时,处于中心点图片的下标
 @param indexPathRow 结束滑动时,处于中心点图片在控件内部的实际下标
 */
- (void)lqscwCarousel:(LQSCWCarousel *)carousel didEndScrollAtIndex:(NSInteger)index indexPathRow:(NSInteger)indexPathRow;


- (void) lqscwCarousel:(LQSCWCarousel *)carousel setupPageControlWithCurrentPage:(NSInteger)index;

@end

@protocol LQSCWCarouselDatasource<NSObject>
///**
// 轮播图数量
// @return 轮播图展示个数
// */
//- (NSInteger)numbersForCarousel;
/**
 自定义每个轮播图视图
 @param carousel 轮播图控件
 @param indexPath 轮播图cell实际下标
 @param index 业务逻辑需要的下标
 @return 自定义视图
 */
- (UICollectionViewCell *) viewForLQSCWCarousel:(LQSCWCarousel *)carousel indexPath:(NSIndexPath *)indexPath index:(NSInteger)index;
@end


@protocol LQSCWCarouselPageControlProtocol<NSObject>
@required
/**
 总页数
 */
@property (nonatomic, assign) NSInteger         pageNumbers;
/**
 当前页
 */
@property (nonatomic, assign) NSInteger         currentPage;

- (void)setCurrentPage:(NSInteger)currentPage;
- (void)setPageNumbers:(NSInteger)pageNumbers;
@end
#endif /* LQSCWCarouselProtocol_h */

