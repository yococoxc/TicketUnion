//
//  LQSCarousel.h
//  XLQSKit
//
//  Created by muzico on 2020/7/2.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>


@class LQSCarousel;


@protocol LQSCarouselDataSource <NSObject>

@optional
- (UICollectionViewCell *) lqsCarousel:(LQSCarousel *)carousel cellWithData:(id)data atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index;

@end

@protocol LQSCarouselDelegate <NSObject>

@optional
- (void) lqsCarousel:(LQSCarousel *)carousel didSelectWithData:(id)data atIndex:(NSInteger)index;

//- (void) lqsCarousel:(LQSCarousel *)carousel didEndScrollAtIndex:(NSInteger)index indexPathRow:(NSInteger)indexPathRow;

- (void) lqsCarousel:(LQSCarousel *)carousel setupPageControlWithCurrentPage:(NSInteger)index;

@end

@interface LQSCarousel : UIView

@property (nonatomic, readonly) UIPageControl *pageControl;


@property(nonatomic,strong) NSArray* datas;

@property(nonatomic,weak) id<LQSCarouselDataSource> dataSource;

@property(nonatomic,weak) id<LQSCarouselDelegate> delegate;

//开始
- (void) startAction;

//暂停
- (void) pauseAction;

//结束的时候一定要调用释放，否则内存泄露
- (void) stopAction;


/**
 通过 identifier 和 index 获取到cell。
 用于setupCell 中。
 内置 CommonCollectionCell 对象，可以通过type1，type2，type3，type4，type5，type6，type7，type8，type9，type10，type11，type12 获取。
 */
- (id) cellWithReuseIdentifier:(NSString *)identifier atIndex:(NSInteger)index;
- (id) cellWithReuseIdentifier:(NSString *)identifier atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index;

/**
 重写这个可以配置 cell。
 
 SHFFootballClassroomADViewDataSource 会失效。
 */
- (UICollectionViewCell *) setupCellWithData:(id)data atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index;


@end

