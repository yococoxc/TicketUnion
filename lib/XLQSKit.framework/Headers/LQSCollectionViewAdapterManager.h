//
//  LQSCollectionViewAdapterManager.h
//  LQSKit
//
//  Created by muzico on 2019/12/17.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "LQSCollectionViewSectionColorImageLayout.h"
#import "CommonCollectionReusableView.h"
#import "CommonCollectionCell.h"

@class LQSCollectionViewAdapterManager;
@class LQSCollectionViewAdapter;

@interface LQSCollectionViewAdapterManager : NSObject<UICollectionViewDataSource,LQSCollectionViewSectionColorImageLayout,UIScrollViewDelegate>

@property(nonatomic,copy,readonly) NSString *cellIdentifier;
@property(nonatomic,copy,readonly) NSString *headerIdentifier;
@property(nonatomic,copy,readonly) NSString *footerIdentifier;

@property(nonatomic,weak) UICollectionView *collectionView;

@property(nonatomic,strong) NSArray<LQSCollectionViewAdapter *> *adapters;

@property(nonatomic,readonly) LQSCollectionViewAdapter *firstAdapter;

/**
 默认会构建出一个UICollectionView实例。
 该实例的layout将默认为LQSCollectionViewSectionColorImageLayout。
 */
+ (instancetype) manager;
/**
 通过 adapter 创建一个默认的 manager。
 */
+ (instancetype) managerWithAdapter:(LQSCollectionViewAdapter *)adapter;

/**
 引入一个UICollectionView实例来管理。
 */
+ (instancetype) managerWithCollectionView:(UICollectionView *)collectionView;

@end




@interface LQSCollectionViewAdapter : NSObject

@property(nonatomic,copy,readonly) NSString *cellIdentifier;
@property(nonatomic,copy,readonly) NSString *headerIdentifier;
@property(nonatomic,copy,readonly) NSString *footerIdentifier;


@property(nonatomic,weak,readonly) LQSCollectionViewAdapterManager *manager;

@property(nonatomic,strong,readonly) NSMutableArray *dataSource;

@property(nonatomic,weak,readonly) UICollectionView *collectionView;

@property(nonatomic,assign,readonly) NSInteger row;

@property(nonatomic,assign,readonly) NSInteger section;


- (void) reloadData;

#pragma mark - 重写方法，进行配置内容
/**
 从 Manager 获取 UICollectionView对象成功后，会调用该方法，重写该方法即可配置内容。
 */
- (void) setupCollectionView:(UICollectionView *)collectionView;

#pragma mark - 重写方法，进行配置内容
- (NSInteger) numberOfCell;
- (UICollectionViewCell *) cellWithDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
/**
 该方法分化出 reusableViewOfHeader、reusableViewOfFooter，一旦重写该方法，会导致分化的方法无效。
 */
- (UICollectionReusableView *) reusableViewOfKind:(NSString *)kind atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
- (UICollectionReusableView *) reusableViewOfHeaderAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
- (UICollectionReusableView *) reusableViewOfFooterAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;

- (void) setupCell:(CommonCollectionCell *)cell withDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
- (void) setupHeader:(CommonCollectionReusableView *)header atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
- (void) setupFooter:(CommonCollectionReusableView *)footer atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;

#pragma mark - 重写方法，进行配置内容
//设定 Cell 的大小。
- (CGSize) sizeForCellAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
//设定 Cell 的大小。
//默认宽度和CollectionView的一致。
- (CGFloat) heightOfSizeForCellAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
- (UIEdgeInsets) insetForSectionAtIndex:(NSInteger)section;
//垂直方向时，cell上下之间的间隔
- (CGFloat) minimumLineSpacingForSectionAtIndex:(NSInteger)section;
//垂直方向时，cell左右之间的间隔
- (CGFloat) minimumInteritemSpacingForSectionAtIndex:(NSInteger)section;
//设定 Header 的大小。
- (CGSize) sizeForHeaderInSection:(NSInteger)section;
//设定 Header 的大小。
//默认宽度和CollectionView的一致。
//没有特别声明，默认大小为垂直方向的情况，当为水平方向时，则相反。
- (CGFloat) heightOfSizeForHeaderInSection:(NSInteger)section;
//设定 Footer 的大小。
- (CGSize) sizeForFooterInSection:(NSInteger)section;
//设定 Footer 的大小。
//默认宽度和CollectionView的一致。
//没有特别声明，默认大小为垂直方向的情况，当为水平方向时，则相反。
- (CGFloat) heightOfSizeForFooterInSection:(NSInteger)section;

//设定 section 背景颜色（与header、footer无关）
//仅支持layout为LQSCollectionViewSectionColorImageLayout。
- (UIColor *) backgroundColorForSection:(NSInteger)section;
//设定 section 背景图片（与header、footer无关）
//仅支持layout为LQSCollectionViewSectionColorImageLayout。
- (UIImage *) backgroundImageForSection:(NSInteger)section;


#pragma mark - 重写方法，进行配置内容
//选择 cell
- (void) didSelectCellWithDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;


#pragma mark - 注册对象
- (void) registerCellClass:(Class)cellClass forIdentifier:(NSString *)reuseIdentifier;
- (void) registerCellNib:(UINib *)cellNib forIdentifier:(NSString *)reuseIdentifier;
- (void) registerHeaderClass:(Class)headerClass forIdentifier:(NSString *)reuseIdentifier;
- (void) registerHeaderNib:(UINib *)headerNib forIdentifier:(NSString *)reuseIdentifier;
- (void) registerFooterClass:(Class)footerClass forIdentifier:(NSString *)reuseIdentifier;
- (void) registerFooterNib:(UINib *)footerNib forIdentifier:(NSString *)reuseIdentifier;

#pragma mark - 获取对象
//通过 reuseIdentifier 获取已经注册的 Cell
- (UICollectionViewCell *) cellFromIdentifier:(NSString *)reuseIdentifier forIndexPath:(NSIndexPath *)indexPath;
//通过 reuseIdentifier 获取已经注册的 Header
- (UICollectionReusableView *) headerFromIdentifier:(NSString *)reuseIdentifier forIndexPath:(NSIndexPath *)indexPath;
//通过 reuseIdentifier 获取已经注册的 Footer
- (UICollectionReusableView *) footerFromIdentifier:(NSString *)reuseIdentifier forIndexPath:(NSIndexPath *)indexPath;

@end
