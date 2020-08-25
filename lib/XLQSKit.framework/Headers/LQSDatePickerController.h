//
//  LQSDatePickerController.h
//  reApp
//
//  Created by muzico on 2020/7/6.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "LQSFixController.h"
#import "LQSDatePickerHeadView.h"

typedef void(^LQSDatePickerControllerDatePickerBlock)(NSDate *date);

@interface LQSDatePickerController : LQSFixController

@property(nonatomic,strong) UIDatePicker *datePicker;


@property(nonatomic,strong) LQSDatePickerHeadView *headView;

@property(nonatomic,copy) LQSDatePickerControllerDatePickerBlock datePickerBlock;


- (void) presedControlToCancel;

- (void) pressedControlToSure;

@end

