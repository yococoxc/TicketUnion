//
//  PickListItem.m
//  TicketUnion
//
//  Created by muzico on 2020/8/22.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "PickListItem.h"
#import <XLQSKit/XLQSKit.h>

@implementation PickListItem

- (void) awakeFromNib {
    [super awakeFromNib];
    
    
    self.lqs_layerCornerRadius = 8;
    [self lqs_setLayerBorderWidth:1 color:@"#c0c0c0"];
}

@end
