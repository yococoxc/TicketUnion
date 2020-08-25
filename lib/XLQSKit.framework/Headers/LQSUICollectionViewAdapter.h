//
//  LQSUICollectionViewAdapter.h
//  LQSKit
//
//  Created by muzico on 2019/12/17.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class LQSUICollectionViewAdapter;



typedef void(^LQSUICollectionViewAdapterDidSelectBlock)(id adapter, UICollectionView *collectionView, id dataSource, NSIndexPath *indexPath, NSInteger index);


@interface LQSUICollectionViewAdapterCell : UICollectionViewCell

@property(nonatomic,strong) UIView *contentCell;

@property(nonatomic,strong) Class contentCellClass;


@end


@interface LQSUICollectionViewAdapterReusableView : UICollectionReusableView

@property(nonatomic,strong) UIView *contentCell;

@property(nonatomic,strong) Class contentCellClass;


@end



@interface LQSUICollectionViewAdapter : NSObject<UICollectionViewDataSource,UICollectionViewDelegateFlowLayout>


@property(nonatomic,readonly) NSArray *array;

@property(nonatomic,copy) NSString *cellIdentifier;

@property(nonatomic,copy) LQSUICollectionViewAdapterDidSelectBlock didSelectBlock;


@property(nonatomic,weak,readonly) UICollectionViewFlowLayout *collectionLayout;


@property(nonatomic,weak,readonly) UICollectionView *collectionView;


@property(nonatomic,copy) NSString *headerIdentifier;

@property(nonatomic,copy) NSString *footerIdentifier;



+ (instancetype) adapterWithArray:(NSArray *)array;
- (instancetype) initWithArray:(NSArray *)array;
+ (instancetype) adapter;


/**
数据清除
*/
- (void) dataClear;
/**
 数据添加
 */
- (void) dataAddObject:(id)dataSource;
- (void) dataReplaceObjectAtIndex:(NSUInteger)index withObject:(id)dataSource;
- (void) dataAddObjectsFromArray:(NSArray *)array;
/**
 数据删除
 */
- (void) dataRemoveObject:(id)dataSource;
- (void) dataRemoveObjectAtIndex:(NSUInteger)index;
/**
 通知数据改变
 */
- (void) notifyDataSetChanged;

/**
重写实现配置方法。
*/
- (void) setupCollectionView:(UICollectionView *)collectionView;

/**
重写实现配置方法。
*/
- (void) setupCollectionView:(UICollectionView *)collectionView count:(NSUInteger)count array:(NSArray *)array;

/**
 重写实现配置方法。配置 cell
 */
- (void) setupCellWithCollectionView:(UICollectionView *) collectionView cell:(LQSUICollectionViewAdapterCell *)cell dataSource:(id)dataSource indexPath:(NSIndexPath *)indexPath index:(NSInteger)index;


/**
重写实现配置方法。配置 header
*/
- (void) setupCellWithCollectionView:(UICollectionView *) collectionView header:(LQSUICollectionViewAdapterReusableView *)header indexPath:(NSIndexPath *)indexPath index:(NSInteger)index;
/**
重写实现配置方法。配置 footer
*/
- (void) setupCellWithCollectionView:(UICollectionView *) collectionView footer:(LQSUICollectionViewAdapterReusableView *)footer indexPath:(NSIndexPath *)indexPath index:(NSInteger)index;

- (void) setupDidSelectWithCollectionView:(UICollectionView *)collectionView dataSource:(id)dataSource didSelectItemAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index;

@end


@interface UICollectionView (LQSAdapter)

@property(nonatomic,strong) LQSUICollectionViewAdapter *lqs_adapter;

@end

