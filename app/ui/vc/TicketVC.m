//
//  TicketVC.m
//  TicketUnion
//
//  Created by muzico on 2020/8/22.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "TicketVC.h"


#import "TicketHeadView.h"
#import "TicketView.h"

#import "ITicketCallback.h"
#import "PresenterManager.h"


#import "YYWebImage.h"

@interface TicketVC ()<ITicketCallback>

@property(nonatomic,strong) TicketView *ticketView;
@property(nonatomic,strong) TicketPresenterImpl *presenter;

@end

@implementation TicketVC

- (void) dealloc {
    [self.presenter unregisterCallback:self];
}

#pragma mark -
- (void) initView {
    self.aboveZoneView.lqs_backgroundColor = @"#F5A623";
    
    TicketHeadView *headView = [TicketHeadView lqs_autoXIB];
    [headView.backButton lqs_addTarget:self action:@selector(pressedButtonToBack)];
    self.zoneView.headerViewItem = [LQSViewItem itemWithView:headView height:44];
    
    TicketView *view = [TicketView lqs_autoXIB];
    self.zoneView.body = view;
    self.ticketView = view;
}

- (void) initListener {
    
}

- (void) initPresenter {
    self.presenter = [PresenterManager getTicketPresenterImpl];
    [self.presenter registerCallback:self];
}

- (void) loadData {
    [self.presenter loadTicketByItemWithURL:self.url withTitle:self.titleString withCover:self.cover];
}

#pragma mark -
- (void) onLoading {
    
}

- (void) onError {
    
}

- (void) onEmpty {
    
}


#pragma mark - ITicketCallback
- (void) onTicketLoadedWithResult:(id)result withCover:(NSString *)cover {
    self.ticketView.label.text = result;
    [self.ticketView.imageView yy_setImageWithURL:[NSURL URLWithString:cover] placeholder:nil];
}

#pragma mark -
- (void) pressedButtonToBack {
    [self lqs_currentNavigationControllerPopViewController];
}

@end
