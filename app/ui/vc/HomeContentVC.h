//
//  HomeContentVC.h
//  TicketUnion
//
//  Created by muzico on 2020/8/23.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "BaseVC.h"

@interface HomeContentVC : BaseVC


@property(nonatomic,copy) NSString *targetID;

@property(nonatomic,strong) LQSEasyListView *listView;

@end
