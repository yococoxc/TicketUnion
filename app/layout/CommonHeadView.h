//
//  CommonHeadView.h
//  TicketUnion
//
//  Created by muzico on 2020/8/23.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CommonHeadView : UIView
@property (weak, nonatomic) IBOutlet UILabel *label;

+ (instancetype) viewWithTitle:(NSString *)title;
@end

NS_ASSUME_NONNULL_END
