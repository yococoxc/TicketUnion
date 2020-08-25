//
//  LQSCodeResignView.h
//  XLQSKit
//
//  Created by muzico on 2020/5/27.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef void (^LQSCodeResignCompleted)(NSString *content);
typedef void (^LQSCodeResignUnCompleted)(NSString *content);

@interface LQSCodeResignView : UIView

@property (copy, nonatomic) LQSCodeResignCompleted codeResignCompleted;
@property (copy, nonatomic) LQSCodeResignUnCompleted codeResignUnCompleted;

@property(nonatomic,strong) UIColor *codeColor;
@property(nonatomic,strong) UIColor *lineColor;
@property(nonatomic,strong) UIColor *promptLineColor;

@property(nonatomic,readonly) NSString *content;

- (instancetype) initWithCodeBits:(NSInteger)codeBits;

@end

