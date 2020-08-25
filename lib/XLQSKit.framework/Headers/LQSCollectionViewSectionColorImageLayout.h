//
//  LQSCollectionViewSectionColorImageLayout.h
//  LQSKit
//
//  Created by muzico on 2019/12/22.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol LQSCollectionViewSectionColorImageLayout <UICollectionViewDelegateFlowLayout>
@optional
- (UIColor*) lqsCollectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout backgroundColorForSection:(NSInteger)section;
- (UIImage*) lqsCollectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout backgroundImageForSection:(NSInteger)section;
@end

@interface LQSCollectionViewSectionColorImageLayout : UICollectionViewFlowLayout

@end
