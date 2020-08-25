//
//  PickListItem.h
//  TicketUnion
//
//  Created by muzico on 2020/8/22.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PickListItem : UIView

@property (weak, nonatomic) IBOutlet UIView *otherView;
@property (weak, nonatomic) IBOutlet UILabel *otherLabel;

@property (weak, nonatomic) IBOutlet UIImageView *imageView;
@property (weak, nonatomic) IBOutlet UILabel *priceLabel;
@property (weak, nonatomic) IBOutlet UIButton *button;
@property (weak, nonatomic) IBOutlet UILabel *tipLabel;

@end

NS_ASSUME_NONNULL_END
