//
//  LQSGradientColorView.h
//  LQSKit
//
//  Created by muzico on 2019/12/6.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>



@interface LQSGradientColorView : UIView

/**
 * 起点和终点表示的坐标系位置，(0,0)表示左上角，(1,1)表示右下角
 */

@property(nonatomic,strong) NSArray *colors;
//0.5, 0
@property(nonatomic,assign) CGPoint startPoint;
//0.5, 1
@property(nonatomic,assign) CGPoint endPoint;

- (void) startColor:(id)startColor endColor:(id)endColor;

@end

