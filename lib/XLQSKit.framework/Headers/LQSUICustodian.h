//
//  LQSUICustodian.h
//  LQSKit
//
//  Created by muzico on 2019/1/10.
//  Copyright © 2019 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface LQSUICustodian : NSObject

@property(nonatomic,weak) UIView *targetView;

@property(nonatomic) NSString *text;
@property(nonatomic) UIImage *image;

+ (instancetype) custodianWithView:(id)view;

@end
