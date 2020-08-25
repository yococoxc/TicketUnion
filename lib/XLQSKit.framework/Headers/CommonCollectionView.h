//
//  CommonCollectionView.h
//  juhao
//
//  Created by muzico on 2018/12/2.
//  Copyright © 2018 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CommonCollectionCell.h"
#import "CommonCollectionReusableView.h"

/**
 引入 CommonCollectionCell、CommonCollectionReusableView的设计作为默认的Cell和ReusableView。
 省去cell的写法，直接用view代替，范例如下：
 
 
#pragma mark - 懒加载
- (CommonCollectionView *) collectionView {
    if (_collectionView == nil) {
        LQSWeakSelf
        
        CommonCollectionView *collectionView = [CommonCollectionView new];
        collectionView.column = 1;
        collectionView.cellHeight = 110;
        collectionView.collectionLayout.minimumLineSpacing = 1;
        collectionView.collectionLayout.minimumInteritemSpacing = 1;
        collectionView.collectionLayout.sectionInset = UIEdgeInsetsMake(15, 0, 0, 0);
        collectionView.setupCellBlock = ^(CommonCollectionView *collectionView, CommonCollectionCell *cell, id dataSource, NSIndexPath *indexPath, NSInteger index) {
            cell.contentCellClass = [YCNewsViewCell class];
            [cell.contentCell lqs_call_setupWithDataSource:dataSource];
        };
        collectionView.didSelectBlock = ^(CommonCollectionView *collectionView, id dataSource, NSIndexPath *indexPath, NSInteger index) {
            
            YCNewsDetailVC *vc = [YCNewsDetailVC new];
            
            if ([dataSource isKindOfClass:[NewsModel class]]) {
                NewsModel *model = dataSource;
                vc.newsContent = model.content;
                vc.newsTitle = model.subject;
                vc.newsTime = model.date;
            }
            
            [weakSelf lqs_currentNavigationControllerPushViewController:vc];
        };
        
        //下拉刷新数据
        collectionView.mj_header = [MJRefreshNormalHeader headerWithRefreshingTarget:self refreshingAction:@selector(headerWithRefresh)];
        //上拉加载新数据
        collectionView.mj_footer = [MJRefreshAutoNormalFooter footerWithRefreshingTarget:self refreshingAction:@selector(footerWithRefresh)];
        
        _collectionView = collectionView;
    }
    return _collectionView;
}
 
 */

@class CommonCollectionView;

typedef void(^CommonCollectionViewSetupBlock)(CommonCollectionView *collectionView);

typedef void(^CommonCollectionViewDidSelectBlock)(CommonCollectionView *collectionView, id dataSource, NSIndexPath *indexPath, NSInteger index);

typedef void(^CommonCollectionViewSetupCellBlock)(CommonCollectionView *collectionView, CommonCollectionCell *cell, id dataSource, NSIndexPath *indexPath, NSInteger index);


typedef void(^CommonCollectionViewSetupHeaderBlock)(CommonCollectionView *collectionView, CommonCollectionReusableView *header, NSIndexPath *indexPath);

typedef void(^CommonCollectionViewSetupFooterBlock)(CommonCollectionView *collectionView, CommonCollectionReusableView *footer, NSIndexPath *indexPath);

typedef void(^CommonCollectionViewScrollViewDidEndDeceleratingBlock)(CommonCollectionView *collectionView, NSInteger page);

@interface CommonCollectionView : UICollectionView

@property (strong, nonatomic) UICollectionViewFlowLayout *collectionLayout;

@property(assign, nonatomic) NSUInteger column;

@property (strong, nonatomic) NSArray *collectionDataSource;

@property(nonatomic,copy) CommonCollectionViewSetupBlock setupBlock;

@property(nonatomic,copy) CommonCollectionViewDidSelectBlock didSelectBlock;

@property(nonatomic,copy) CommonCollectionViewSetupCellBlock setupCellBlock;


@property(nonatomic,copy) CommonCollectionViewScrollViewDidEndDeceleratingBlock scrollViewDidEndDeceleratingBlock;

@property(nonatomic, strong) Class cellClass;
@property(nonatomic, copy) NSString *cellNibString;

@property(nonatomic, assign) CGFloat cellHeight;

@property(nonatomic, assign) CGFloat cellSizeScale;




#pragma mark - header
@property(nonatomic, assign) CGFloat headerHeight;

@property(nonatomic, strong) Class headerClass;

@property(nonatomic, copy) NSString *headerNibString;

@property(nonatomic,copy) CommonCollectionViewSetupHeaderBlock setupHeaderBlock;


#pragma mark - footer
@property(nonatomic, assign) CGFloat footerHeight;

@property(nonatomic, strong) Class footerClass;

@property(nonatomic, copy) NSString *footerNibString;

@property(nonatomic,copy) CommonCollectionViewSetupFooterBlock setupFooterBlock;

@end

