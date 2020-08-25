//
//  PresenterManager.m
//  TicketUnion
//
//  Created by muzico on 2020/8/21.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "PresenterManager.h"

@implementation PresenterManager


+ (HomePagePresenterImpl *) getHomePagePresenterImpl {
    return [HomePagePresenterImpl new];
}
+ (CategoryPagePresenterImpl *) getCategoryPagePresenterImpl {
    return [CategoryPagePresenterImpl new];
}
+ (QrCodeScanPresenterImpl *) getQrCodeScanPresenterImpl {
    return [QrCodeScanPresenterImpl new];
}
+ (OnSellPagePresenterImpl *) getOnSellPagePresenterImpl {
    return [OnSellPagePresenterImpl new];
}
+ (SearchPagePresenterImpl *) getSearchPagePresenterImpl {
    return [SearchPagePresenterImpl new];
}
+ (SelectedPagePresenterImpl *) getSelectedPagePresenterImpl {
    return [SelectedPagePresenterImpl new];
}
+ (TicketPresenterImpl *) getTicketPresenterImpl {
    return [TicketPresenterImpl new];
}

@end
