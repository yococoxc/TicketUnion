//
//  LQSDatePickerHeadView.h
//  reApp
//
//  Created by muzico on 2020/7/6.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, LQSDatePickerHeadViewStyle) {
    LQSDatePickerHeadViewStyleLeftCancelRightSure,
    LQSDatePickerHeadViewStyleLeftCancel,
};

@interface LQSDatePickerHeadView : UIView

@property(nonatomic,strong) UIButton *cancelButton;

@property(nonatomic,strong) UIButton *sureButton;

@property(nonatomic,assign) LQSDatePickerHeadViewStyle style;

@end

