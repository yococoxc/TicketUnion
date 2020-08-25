//
//  LQSCollectionViewAlignLayout.h
//  XLQSKit
//
//  Created by muzico on 2020/5/19.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>



typedef NS_ENUM(NSUInteger, LQSCollectionViewAlignLayoutType) {
    LQSCollectionViewAlignLayoutTypeLeft,
    LQSCollectionViewAlignLayoutTypeCenter,
    LQSCollectionViewAlignLayoutTypeRight,
};

/**
 对齐布局，但暂时不支持水平方向。
 */
@interface LQSCollectionViewAlignLayout : UICollectionViewFlowLayout

//cell对齐方式
@property (nonatomic,assign) LQSCollectionViewAlignLayoutType type;

- (instancetype) initWthType:(LQSCollectionViewAlignLayoutType)type;

+ (instancetype) layoutWithType:(LQSCollectionViewAlignLayoutType)type;


+ (instancetype) layoutWithType:(LQSCollectionViewAlignLayoutType)type setupBlock:(void(^)(LQSCollectionViewAlignLayout *layout))aBlock;

@end
