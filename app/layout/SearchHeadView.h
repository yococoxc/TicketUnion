//
//  SearchHeadView.h
//  TicketUnion
//
//  Created by muzico on 2020/8/23.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <XLQSKit/XLQSKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SearchHeadView : UIView
@property (weak, nonatomic) IBOutlet UITextField *textField;
@property (weak, nonatomic) IBOutlet UIButton *button;
@property(nonatomic,copy) LQSCallbackEmptyBlock clearSearchBlock;

@property(nonatomic,copy) LQSCallbackStringBlock searchBlock;

@end

NS_ASSUME_NONNULL_END
