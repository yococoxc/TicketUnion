//
//  LQSCollectionViewSection.h
//  LQSKit
//
//  Created by muzico on 2018/12/24.
//  Copyright © 2018 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LQSCollectionViewSectionItem.h"

@interface LQSCollectionViewSection : UICollectionView

@property(nonatomic,weak) UICollectionViewFlowLayout *collectionLayout;

@property(nonatomic,strong) NSArray<LQSCollectionViewSectionItem *> *collectionDataSource;


@end
