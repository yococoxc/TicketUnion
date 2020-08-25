//
//  LQSListAdapterManager.h
//  LQSKit
//
//  Created by muzico on 2020/1/8.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "LQSCollectionViewSectionColorImageLayout.h"

#import "LQSAirThroughView.h"


#import "LQSCollectionViewAlignLayout.h"


@class LQSListTableViewCell;
@class LQSListCollectionViewCell;

@interface LQSListItemView : UIView

@property(nonatomic,strong) UIView *contentView;

@property(nonatomic,strong) Class contentViewClass;

@end

@interface LQSListTableViewHeaderFooter : UITableViewHeaderFooterView

@property(nonatomic,strong) LQSListItemView *contentCell;

@end


@class LQSListAdapterManager;
@class LQSListAdapter;



typedef void(^LQSListAdapterDidSelectCellBlock)(id dataSource,NSIndexPath *indexPath);

typedef NS_ENUM(NSUInteger, LQSListAdapterType) {
    LQSListAdapterTypeTableView,
    LQSListAdapterTypeCollectionView,
};



@interface LQSListAdapterManagerView : UIView

@property(nonatomic,strong,readonly) LQSAirThroughView *foregroundView;
@property(nonatomic,strong,readonly) LQSAirThroughView *contentView;
@property(nonatomic,strong,readonly) LQSAirThroughView *backgroundView;

@end


typedef void(^LQSListAdapterManagerScrollOutOfHeightRange)(BOOL value);

@interface LQSListAdapterManager : NSObject <UITableViewDelegate,UITableViewDataSource,UICollectionViewDataSource,LQSCollectionViewSectionColorImageLayout,UIScrollViewDelegate>

@property(nonatomic,copy,readonly) NSString *cellIdentifier;
@property(nonatomic,copy,readonly) NSString *headerIdentifier;
@property(nonatomic,copy,readonly) NSString *footerIdentifier;

@property(nonatomic,assign,readonly) LQSListAdapterType type;
@property(nonatomic,readonly) LQSListAdapterManagerView *view;
@property(nonatomic,readonly) UIScrollView *scrollView;
@property(nonatomic,weak) UITableView *tableView;
@property(nonatomic,weak) UICollectionView *collectionView;

@property(nonatomic,strong) NSArray<LQSListAdapter *> *adapters;



/**
 滚动超出高度范围
 */
@property(nonatomic,copy) LQSListAdapterManagerScrollOutOfHeightRange scrollOutOfHeightRangeBlock;

+ (instancetype) tableViewManager;
/**
 默认LQSCollectionViewSectionColorImageLayout，但无法保证问题，所以建议多测试才使用这个。
 */
+ (instancetype) collectionViewManager;
+ (instancetype) collectionViewManagerWithLayout:(UICollectionViewLayout *)layout;
/**
 默认UICollectionViewFlowLayout。
 */
+ (instancetype) collectionViewManagerWithNormalFlowLayout;

/**
 默认LQSCollectionViewAlignLayout。
 */
+ (instancetype) collectionViewManagerWithAlignLayout;
+ (instancetype) collectionViewManagerWithAlignLayout:(LQSCollectionViewAlignLayoutType)type;

+ (instancetype) managerWithTableView:(UITableView *)tableView;
+ (instancetype) managerWithCollectionView:(UICollectionView *)collectionView;



- (void) reloadData;

@end

@interface LQSListAdapter : NSObject


@property(nonatomic,assign) BOOL haveGap;

/**
 假如 同一个 LQSListAdapter 被使用了，为了区分可以使用 tagIdentifier，将为 cellIdentifier、headerIdentifier、footerIdentifier 添加上这个标识。
 默认值为微秒时间戳。
 */
@property(nonatomic,copy) NSString *tagIdentifier;


@property(nonatomic,copy,readonly) NSString *cellGapIdentifier;
@property(nonatomic,copy,readonly) NSString *cellIdentifier;
@property(nonatomic,copy,readonly) NSString *headerIdentifier;
@property(nonatomic,copy,readonly) NSString *footerIdentifier;

@property(nonatomic,weak,readonly) LQSListAdapterManager *manager;

/**
 dataSource 对应 cell。
 */
@property(nonatomic,strong,readonly) NSMutableArray *dataSource;

/**
otherDataSource
 提供给开发者自由使用。可以用来记录header、footer的数据。
*/
@property(nonatomic,strong) id otherDataSource;

@property(nonatomic,weak) UITableView *tableView;
@property(nonatomic,weak) UICollectionView *collectionView;
@property(nonatomic,weak,readonly) LQSListAdapterManagerView *view;
@property(nonatomic,weak,readonly) UIScrollView *scrollView;

@property(nonatomic,assign,readonly) NSInteger row;

@property(nonatomic,assign,readonly) NSInteger section;

@property(nonatomic,readonly) CGFloat availableWidth;


/**
 选中cell。
 重写
 - (void) didSelectCellWithDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section
 会导致该属性失效。
 */
@property(nonatomic,copy) LQSListAdapterDidSelectCellBlock didSelectCell;


/**
 重置数据
 */
- (void) setupDataSource:(NSArray *)dataSource;
/**
 添加更多数据
 */
- (void) dataSourceAddMore:(NSArray *)dataSource;
/**
移除数据
*/
- (void) removeAllDataSource;
/**
刷新数据，UI更新
*/
- (void) reloadData;

- (void) setupTableView:(UITableView *)tableView;
- (void) setupCollectionView:(UICollectionView *)collectionView;

//注册默认的table cell:LQSListTableViewCell
- (void) registerTableCellWithIdentifier:(NSString *)reuseIdentifier;
//获取默认的table cell:LQSListTableViewCell
- (LQSListTableViewCell *) getTableCellWithIdentifier:(NSString *)reuseIdentifier;

//注册默认的collection cell:LQSListCollectionViewCell
- (void) registerCollectionCellWithIdentifier:(NSString *)reuseIdentifier;
//获取默认的collection cell:LQSListCollectionViewCell
- (LQSListCollectionViewCell *) getCollectionCellWithIdentifier:(NSString *)reuseIdentifier;
- (LQSListCollectionViewCell *) getCollectionCellWithIdentifier:(NSString *)reuseIdentifier loadContentViewClass:(Class)viewClass;
- (LQSListCollectionViewCell *) getCollectionCellWithIdentifier:(NSString *)reuseIdentifier loadContentViewClass:(Class)viewClass atIndexPath:(NSIndexPath *)indexPath;
- (LQSListCollectionViewCell *) getCollectionCellWithIdentifier:(NSString *)reuseIdentifier loadContentView:(UIView *)view;
- (LQSListCollectionViewCell *) getCollectionCellWithIdentifier:(NSString *)reuseIdentifier loadContentView:(UIView *)view atIndexPath:(NSIndexPath *)indexPath;


- (void) setupCellContentView:(LQSListItemView *)view withDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
- (void) setupCellGapContentView:(LQSListItemView *)view atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
- (void) setupHeaderContentView:(LQSListItemView *)view inSection:(NSInteger)section;
- (void) setupFooterContentView:(LQSListItemView *)view inSection:(NSInteger)section;


+ (instancetype) adapterWithDataSource:(NSArray *)dataSource;
+ (instancetype) adapterWithOtherDataSource:(id)otherDataSource;
+ (instancetype) adapterWithDataSource:(NSArray *)dataSource otherDataSource:(id)otherDataSource;


#pragma mark - 重写方法，进行配置内容
- (NSInteger) numberOfCell;

//设定 Cell 的大小。
- (CGSize) sizeForCellAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
//设定 Cell 的大小。
//默认宽度和CollectionView的一致。
- (CGFloat) heightOfSizeForCellAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;



//设定 CellGap 的大小。
- (CGSize) sizeForCellGapAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
//设定 CellGap 的大小。
//默认宽度和CollectionView的一致。
- (CGFloat) heightOfSizeForCellGapAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;




/**
 
*/
- (UIEdgeInsets) insetForSectionAtIndex:(NSInteger)section;

/**
 
*/
- (UIEdgeInsets) insetForHeaderAtIndex:(NSInteger)section;

/**
 
*/
- (UIEdgeInsets) insetForFooterAtIndex:(NSInteger)section;

/**
 TableView时：
 cell上下之间的间隔
 
 CollectionView时：
 垂直方向时，cell上下之间的间隔
 */
- (CGFloat) minimumLineSpacingForSectionAtIndex:(NSInteger)section;


/**
 TableView时：
 没有效果。
 
 CollectionView时：
 垂直方向时，cell左右之间的间隔
 */
- (CGFloat) minimumInteritemSpacingForSectionAtIndex:(NSInteger)section;



/**
 设定 Header 的大小。
 */
- (CGSize) sizeForHeaderInSection:(NSInteger)section;

/**
 设定 Header 的大小。
 
 TableView时：
 默认宽度和TableView的一致。

 CollectionView时：
 默认宽度和CollectionView的一致。
 没有特别声明，默认大小为垂直方向的情况，当为水平方向时，则相反。
*/
- (CGFloat) heightOfSizeForHeaderInSection:(NSInteger)section;



/**
 设定 Footer 的大小。
 */
- (CGSize) sizeForFooterInSection:(NSInteger)section;

/**
 设定 Footer 的大小。
 
 TableView时：
 默认宽度和TableView的一致。
 
 CollectionView时：
 默认宽度和CollectionView的一致。
 没有特别声明，默认大小为垂直方向的情况，当为水平方向时，则相反。
 */
- (CGFloat) heightOfSizeForFooterInSection:(NSInteger)section;

/**
 设定 section 背景颜色（与header、footer无关）
 
 TableView时：
 没有效果。
 
 CollectionView时：
 仅支持layout为LQSCollectionViewSectionColorImageLayout。
 */
- (UIColor *) backgroundColorForSection:(NSInteger)section;

/**
 设定 section 背景图片（与header、footer无关）
 
 TableView时：
 没有效果。
 
 CollectionView时：
 仅支持layout为LQSCollectionViewSectionColorImageLayout。
 */
- (UIImage *) backgroundImageForSection:(NSInteger)section;;

@end

@interface LQSListAdapter (RewriteMethod)

/**
 通过重写这个方法，可以重新配置 TableViewCell，但会导致下面方法失效：
 - (void) setupCellContentView:(LQSListItemView *)view withDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
 */
- (UITableViewCell *) tableViewCellWithDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
/**
通过重写这个方法，可以重新配置 CollectionViewCell，但会导致下面方法失效：
- (void) setupCellContentView:(LQSListItemView *)view withDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
*/
- (UICollectionViewCell *) collectionViewCellWithDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
- (UICollectionViewCell *) collectionViewCellGapAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;

/**
通过重写这个方法，可以重新配置 CollectionReusableView，但会导致下面方法失效：
 - (void) setupHeaderContentView:(LQSListItemView *)view inSection:(NSInteger)section;
 - (void) setupFooterContentView:(LQSListItemView *)view inSection:(NSInteger)section;
 - (UICollectionReusableView *) reusableViewOfHeaderAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
 - (UICollectionReusableView *) reusableViewOfFooterAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
*/
- (UICollectionReusableView *) reusableViewOfKind:(NSString *)kind atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
/**
通过重写这个方法，可以重新配置 CollectionReusableView，但会导致下面方法失效：
 - (void) setupHeaderContentView:(LQSListItemView *)view inSection:(NSInteger)section;
*/
- (UICollectionReusableView *) reusableViewOfHeaderAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;
/**
通过重写这个方法，可以重新配置 CollectionReusableView，但会导致下面方法失效：
 - (void) setupFooterContentView:(LQSListItemView *)view inSection:(NSInteger)section;
*/
- (UICollectionReusableView *) reusableViewOfFooterAtIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;




#pragma mark - 重写方法，进行配置内容
//选择 cell
- (void) didSelectCellWithDataSource:(id)dataSource atIndexPath:(NSIndexPath *)indexPath index:(NSInteger)index section:(NSInteger)section;



@end

@interface LQSListAdapterManager (TheViewHierarchy)

- (void) viewLayoutDidChange;

@end




@interface LQSListCollectionViewCell : UICollectionViewCell

@property(nonatomic,strong) LQSListItemView *contentCell;

@end

@interface LQSListCollectionReusableView : UICollectionReusableView

@property(nonatomic,strong) LQSListItemView *contentCell;

@end


@interface LQSListTableViewCell : UITableViewCell

@property(nonatomic,strong) LQSListItemView *contentCell;

@property(nonatomic,assign) CGFloat gap;
@property(nonatomic,assign) CGFloat sectionInsetTop;
@property(nonatomic,assign) CGFloat sectionInsetBottom;
@property(nonatomic,assign) CGFloat sectionInsetLeft;
@property(nonatomic,assign) CGFloat sectionInsetRight;

@end

