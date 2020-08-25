//
//  BaseVC.m
//  TicketUnion
//
//  Created by muzico on 2020/8/22.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "BaseVC.h"


@interface BaseVC ()

@property (nonatomic, assign) VCState currentState;
@property (nonatomic, strong) UIView *mLoadingView;
@property (nonatomic, strong) UIView *mSuccessView;
@property (nonatomic, strong) UIView *mErrorView;
@property (nonatomic, strong) UIView *mEmptyView;


@end

@implementation BaseVC

- (instancetype) initWithTitle:(NSString *) title {
    if (self = [super initWithNibName:nil bundle:nil]) {
        
        if (self.tabBarItem) {
            self.tabBarItem.title = title;
        }
        
    }
    return self;
}



- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    
    
    [self loadStatesView];
    [self initView];
    [self initListener];
    [self initPresenter];
    [self loadData];
}

- (void) viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    [self onResume];
}

- (void) viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
    
    [self onPause];
}


#pragma mark -
- (void) onResume {
    
}
- (void) onPause {
    
}



#pragma mark -
- (void) loadStatesView {
    
}
- (void) setupState:(VCState)state {
    self.currentState = state;
    
//    self.mSuccessView.hidden = self.currentState == VCStateSuccess ? YES : NO;
//    self.mLoadingView.hidden = self.currentState == VCStateLoading ? YES : NO;
//    self.mErrorView.hidden = self.currentState == VCStateError ? YES : NO;
//    self.mEmptyView.hidden = self.currentState == VCStateEmpty ? YES : NO;
}

#pragma mark -
- (void) initView {
    
}

- (void) initListener {
    
}

- (void) initPresenter {
    
}

- (void) loadData {
    
}



@end
