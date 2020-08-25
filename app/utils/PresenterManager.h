//
//  PresenterManager.h
//  TicketUnion
//
//  Created by muzico on 2020/8/21.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "HomePagePresenterImpl.h"
#import "CategoryPagePresenterImpl.h"
#import "QrCodeScanPresenterImpl.h"
#import "OnSellPagePresenterImpl.h"
#import "SearchPagePresenterImpl.h"
#import "SelectedPagePresenterImpl.h"
#import "TicketPresenterImpl.h"


@interface PresenterManager : NSObject

+ (HomePagePresenterImpl *) getHomePagePresenterImpl;
+ (CategoryPagePresenterImpl *) getCategoryPagePresenterImpl;
+ (QrCodeScanPresenterImpl *) getQrCodeScanPresenterImpl;
+ (OnSellPagePresenterImpl *) getOnSellPagePresenterImpl;
+ (SearchPagePresenterImpl *) getSearchPagePresenterImpl;
+ (SelectedPagePresenterImpl *) getSelectedPagePresenterImpl;
+ (TicketPresenterImpl *) getTicketPresenterImpl;


@end
