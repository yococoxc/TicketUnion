//
//  SearchHeadView.m
//  TicketUnion
//
//  Created by muzico on 2020/8/23.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "SearchHeadView.h"


@interface SearchHeadView ()<UITextFieldDelegate>



@end

@implementation SearchHeadView

- (void) awakeFromNib {
    [super awakeFromNib];
    
    self.textField.delegate = self;
    self.textField.clearButtonMode = UITextFieldViewModeAlways;
    [self.button lqs_addTarget:self action:@selector(pressedButtonToSearch)];
}
- (BOOL) textFieldShouldClear:(UITextField *)textField {
    if (self.clearSearchBlock) {
        self.clearSearchBlock();
    }
    return YES;
}

- (void) pressedButtonToSearch {
    if ([self.textField.text lqs_length] > 0) {
        if (self.searchBlock) {
            self.searchBlock(self.textField.text);
        }
    }
}

@end
