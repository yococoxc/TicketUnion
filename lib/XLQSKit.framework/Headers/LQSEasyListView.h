//
//  LQSEasyListView.h
//  XLQSKit
//
//  Created by muzico on 2020/7/9.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LQSListAdapterManager.h"




/**
 LQSEasyListView 为 LQSListAdapterManager 的精简版。。。
 并不是完全支持 LQSListAdapter 的内容。
 
 目前支持：
 个数
 配置内容
 配置内容大小
 点击事件
 */

@interface LQSEasyListView : UIView<UICollectionViewDataSource,UICollectionViewDelegateFlowLayout,UIScrollViewDelegate>

@property(nonatomic,strong,readonly) UICollectionView *collectionView;
@property(nonatomic,readonly) UICollectionViewFlowLayout *collectionFlowLayout;
@property(nonatomic,strong,readonly) UICollectionViewLayout *collectionLayout;

/**
 dataSource 对应的是 cell的数据。
 dataSource 的个数等于 cell的个数。
 */
@property(nonatomic,strong,readonly) NSMutableArray *dataSource;

/**
 通过  LQSListAdapter 来配置内容。
 */
@property(nonatomic,strong) LQSListAdapter *adapter;
/**
通过多个  LQSListAdapter 来配置内容。
*/
@property(nonatomic,strong) NSArray *adapters;

/**
如果你不想通过 LQSListAdapter 来配置内容，可以选择重写方法来实现。
而 haveGap 就适用于该情况下是否有 cell gap。
*/
@property(nonatomic,assign) BOOL haveGap;

/**
 配置数据
 */
- (void) setupWithDataSource:(NSArray *)dataSource;
/**
移除数据
*/
- (void) removeAllDataSource;
/**
添加数据
*/
- (void) addMoreDataSource:(NSArray *)dataSource;



/**
 自定义 UICollectionViewFlowLayout。
 */
- (instancetype) initWithFlowLayout:(UICollectionViewFlowLayout *) collectionLayout;
/**
 自定义 UICollectionViewFlowLayout。
 */
+ (instancetype) listViewWithFlowLayout:(UICollectionViewFlowLayout *) collectionLayout;

/**
 UICollectionViewFlowLayout 为 LQSCollectionViewSectionColorImageLayout。
 开启section 背景颜色、图片自定义支持。
 */
+ (instancetype) listViewWithColorImageLayout;

@end



@interface LQSEasyListView (RewriteMethod)

#pragma mark - 重写方法
#pragma mark - 配置内容
- (UICollectionViewCell *) setupCellGapForItemAtIndexPath:(NSIndexPath *)indexPath;

- (UICollectionViewCell *) setupCellForItemAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
- (UICollectionViewCell *) setupCellForItemWithDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
- (void) setupCellWithItemView:(LQSListItemView *)itemView dataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;


#pragma mark - 配置大小
- (CGSize) setupSizeForItemAtIndexPath:(NSIndexPath *)indexPath;
- (CGFloat) setupHeightWithSizeForItemAtIndexPath:(NSIndexPath *)indexPath;

- (CGSize) setupSizeForItemGapAtIndexPath:(NSIndexPath *)indexPath;
- (CGFloat) setupHeightWithSizeForItemGapAtIndexPath:(NSIndexPath *)indexPath;

#pragma mark - 点击事件
- (void) didSelectItemAtIndexPath:(NSIndexPath *)indexPath;

@end

