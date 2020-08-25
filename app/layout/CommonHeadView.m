//
//  CommonHeadView.m
//  TicketUnion
//
//  Created by muzico on 2020/8/23.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "CommonHeadView.h"
#import <XLQSKit/XLQSKit.h>

@implementation CommonHeadView


+ (instancetype) viewWithTitle:(NSString *)title {
    CommonHeadView *temp = [CommonHeadView lqs_autoXIB];
    temp.label.textColor = [UIColor whiteColor];
    temp.lqs_backgroundColor = @"#F5A623";
    temp.label.text = title;
    
    return temp;
}

@end
