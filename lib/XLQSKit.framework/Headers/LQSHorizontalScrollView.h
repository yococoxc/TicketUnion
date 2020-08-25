//
//  LQSHorizontalScrollView.h
//  LQSKit
//
//  Created by muzico on 2020/1/14.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LQSCollectionViewSectionColorImageLayout.h"
#import "LQSListAdapterManager.h"


@class LQSHorizontalScrollView;


@protocol LQSHorizontalScrollViewDelegate <NSObject>

@optional
- (void) lqsHorizontalScrollView:(LQSHorizontalScrollView *)scrollView setupCellContentView:(LQSListItemView *)view withDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;

- (void) lqsHorizontalScrollView:(LQSHorizontalScrollView *)scrollView didSelectCellWithDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;

@end



@interface LQSHorizontalScrollView : UIView<UICollectionViewDataSource,LQSCollectionViewSectionColorImageLayout,UIScrollViewDelegate>

@property(nonatomic,strong,readonly) LQSAirThroughView *backgroundView;

@property(nonatomic,strong,readonly) UICollectionView *collectionView;


@property(nonatomic,strong,readonly) UIPageControl *pageControl;
//35
@property(nonatomic,assign) CGFloat pageControlHeight;
//10
@property(nonatomic,assign) CGFloat pageControlBottomGap;



@property(nonatomic,strong,readonly) LQSAirThroughView *foregroundView;

@property(nonatomic,strong) NSArray *arrayDataSource;

@property(nonatomic,weak) id<LQSHorizontalScrollViewDelegate> delegate;


@property(nonatomic,assign) CGFloat contentHeight;

- (void) reloadData;

@end

