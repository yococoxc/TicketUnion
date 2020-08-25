//
//  LQSCollectionViewSectionItem.h
//  LQSKit
//
//  Created by muzico on 2018/12/24.
//  Copyright © 2018 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>


@protocol LQSCollectionViewSectionItem

@required
- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath;

@optional
- (NSInteger) collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section;

- (CGSize) collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath;

- (UIEdgeInsets) collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout insetForSectionAtIndex:(NSInteger)section;

- (CGFloat) collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout minimumLineSpacingForSectionAtIndex:(NSInteger)section;

- (CGFloat) collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout minimumInteritemSpacingForSectionAtIndex:(NSInteger)section;


- (void) collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath;



- (CGSize) collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout referenceSizeForHeaderInSection:(NSInteger)section;

- (UICollectionReusableView *) collectionView:(UICollectionView *)collectionView viewForHeaderAtIndexPath:(NSIndexPath *)indexPath;

- (CGSize) collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout referenceSizeForFooterInSection:(NSInteger)section;

- (UICollectionReusableView *) collectionView:(UICollectionView *)collectionView viewForFooterAtIndexPath:(NSIndexPath *)indexPath;

@end

@interface LQSCollectionViewSectionItem : NSObject  <LQSCollectionViewSectionItem>

@property(nonatomic,weak) UICollectionView *collectionView;

@property(nonatomic,weak) UICollectionViewFlowLayout *collectionLayout;

//0
@property(nonatomic, assign) NSInteger itemsNumber;

//0,0
@property(nonatomic, assign) CGSize itemSize;

//0,0,0,0
@property(nonatomic, assign) UIEdgeInsets inset;

//0
@property(nonatomic, assign) CGFloat minimumLineSpacing;

//0
@property(nonatomic, assign) CGFloat minimumInteritemSpacing;




//0,0
@property(nonatomic, assign) CGSize headerSize;


//0,0
@property(nonatomic, assign) CGSize footerSize;



- (void) setupWithInitialization;

@end
