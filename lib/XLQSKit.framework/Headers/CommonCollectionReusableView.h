//
//  CommonCollectionReusableView.h
//  zyp2p
//
//  Created by muzico on 2019/1/16.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CommonCollectionReusableView : UICollectionReusableView

@property(nonatomic,strong) UIView *contentCell;

@property(nonatomic,strong) Class contentCellClass;

@end
