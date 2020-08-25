//
//  LQSZoneView.h
//  TestLayout
//
//  Created by muzico on 2020/6/5.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LQSViewItem.h"


@interface LQSZoneView : UIView

@property(nonatomic, strong,readonly) UIView *loadView;

#pragma mark -
#pragma mark - body 的上面
@property(nonatomic, strong) id navigationBarest;
@property(nonatomic, strong) id navigationBarer;
@property(nonatomic, strong) id navigationBar;

@property(nonatomic, strong) id topest;
@property(nonatomic, strong) id toper;
@property(nonatomic, strong) id top;

@property(nonatomic, strong) id headest;
@property(nonatomic, strong) id header;
@property(nonatomic, strong) id head;

#pragma mark -
#pragma mark - body 的左面
@property(nonatomic, strong) id sideLeftest;
@property(nonatomic, strong) id sideLefter;
@property(nonatomic, strong) id sideLeft;

@property(nonatomic, strong) id leftest;
@property(nonatomic, strong) id lefter;
@property(nonatomic, strong) id left;

@property(nonatomic, strong) id leadingest;
@property(nonatomic, strong) id leadinger;
@property(nonatomic, strong) id leading;

#pragma mark -
#pragma mark - 中心的 body
@property(nonatomic, strong) UIView *body;
@property (nonatomic, assign) UIEdgeInsets bodyInset;

#pragma mark -
#pragma mark - body 的右面
@property(nonatomic, strong) id trailing;
@property(nonatomic, strong) id trailinger;
@property(nonatomic, strong) id trailingest;

@property(nonatomic, strong) id right;
@property(nonatomic, strong) id righter;
@property(nonatomic, strong) id rightest;

@property(nonatomic, strong) id sideRight;
@property(nonatomic, strong) id sideRighter;
@property(nonatomic, strong) id sideRightest;

#pragma mark -
#pragma mark - body 的下面
@property(nonatomic, strong) id foot;
@property(nonatomic, strong) id footer;
@property(nonatomic, strong) id footest;

@property(nonatomic, strong) id bottom;
@property(nonatomic, strong) id bottomer;
@property(nonatomic, strong) id bottomest;

@property(nonatomic, strong) id tabBar;
@property(nonatomic, strong) id tabBarer;
@property(nonatomic, strong) id tabBarest;


#pragma mark -
- (void) reloadLayout;

@end


@interface LQSZoneView (easySetupDefaultValue)

//44
@property(nonatomic, assign) CGFloat navigationBarHeight;
//44
@property(nonatomic, assign) CGFloat navigationBarerHeight;
//44
@property(nonatomic, assign) CGFloat navigationBarestHeight;

//0
@property(nonatomic, assign) CGFloat topHeight;
//0
@property(nonatomic, assign) CGFloat toperHeight;
//0
@property(nonatomic, assign) CGFloat topestHeight;

//0
@property(nonatomic, assign) CGFloat headestHeight;
//0
@property(nonatomic, assign) CGFloat headerHeight;
//0
@property(nonatomic, assign) CGFloat headHeight;



//0
@property(nonatomic, assign) CGFloat sideLeftestWidth;
//0
@property(nonatomic, assign) CGFloat sideLefterWidth;
//0
@property(nonatomic, assign) CGFloat sideLeftWidth;

//0
@property(nonatomic, assign) CGFloat leftestWidth;
//0
@property(nonatomic, assign) CGFloat lefterWidth;
//0
@property(nonatomic, assign) CGFloat leftWidth;

//0
@property(nonatomic, assign) CGFloat leadingestWidth;
//0
@property(nonatomic, assign) CGFloat leadingerWidth;
//0
@property(nonatomic, assign) CGFloat leadingWidth;




//0
@property(nonatomic, assign) CGFloat trailingWidth;
//0
@property(nonatomic, assign) CGFloat trailingerWidth;
//0
@property(nonatomic, assign) CGFloat trailingestWidth;


//0
@property(nonatomic, assign) CGFloat rightWidth;
//0
@property(nonatomic, assign) CGFloat righterWidth;
//0
@property(nonatomic, assign) CGFloat rightestWidth;


//0
@property(nonatomic, assign) CGFloat sideRightWidth;
//0
@property(nonatomic, assign) CGFloat sideRighterWidth;
//0
@property(nonatomic, assign) CGFloat sideRightestWidth;


//0
@property(nonatomic, assign) CGFloat footHeight;
//0
@property(nonatomic, assign) CGFloat footerHeight;
//0
@property(nonatomic, assign) CGFloat footestHeight;

//0
@property(nonatomic, assign) CGFloat bottomHeight;
//0
@property(nonatomic, assign) CGFloat bottomerHeight;
//0
@property(nonatomic, assign) CGFloat bottomestHeight;

//49
@property(nonatomic, assign) CGFloat tabBarHeight;
//49
@property(nonatomic, assign) CGFloat tabBarerHeight;
//49
@property(nonatomic, assign) CGFloat tabBarestHeight;

@end

@interface LQSZoneView (easySetupNavigationBar)

@property(nonatomic, strong) UIView *navigationBarestView;
@property(nonatomic, strong) UIView *navigationBarerView;
@property(nonatomic, strong) UIView *navigationBarView;

@property(nonatomic, strong) LQSViewItem *navigationBarestViewItem;
@property(nonatomic, strong) LQSViewItem *navigationBarerViewItem;
@property(nonatomic, strong) LQSViewItem *navigationBarViewItem;

@property(nonatomic, strong) NSArray<UIView *> *navigationBarestViewArray;
@property(nonatomic, strong) NSArray<UIView *> *navigationBarerViewArray;
@property(nonatomic, strong) NSArray<UIView *> *navigationBarViewArray;

@property(nonatomic, strong) NSArray<LQSViewItem *> *navigationBarestViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *navigationBarerViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *navigationBarViewItemArray;

@end

@interface LQSZoneView (easySetupTop)

@property(nonatomic, strong) UIView *topestView;
@property(nonatomic, strong) UIView *toperView;
@property(nonatomic, strong) UIView *topView;

@property(nonatomic, strong) LQSViewItem *topestViewItem;
@property(nonatomic, strong) LQSViewItem *toperViewItem;
@property(nonatomic, strong) LQSViewItem *topViewItem;

@property(nonatomic, strong) NSArray<UIView *> *topestViewArray;
@property(nonatomic, strong) NSArray<UIView *> *toperViewArray;
@property(nonatomic, strong) NSArray<UIView *> *topViewArray;

@property(nonatomic, strong) NSArray<LQSViewItem *> *topestViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *toperViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *topViewItemArray;

@end

@interface LQSZoneView (easySetupHead)

@property(nonatomic, strong) UIView *headestView;
@property(nonatomic, strong) UIView *headerView;
@property(nonatomic, strong) UIView *headView;

@property(nonatomic, strong) LQSViewItem *headestViewItem;
@property(nonatomic, strong) LQSViewItem *headerViewItem;
@property(nonatomic, strong) LQSViewItem *headViewItem;

@property(nonatomic, strong) NSArray<UIView *> *headestViewArray;
@property(nonatomic, strong) NSArray<UIView *> *headerViewArray;
@property(nonatomic, strong) NSArray<UIView *> *headViewArray;

@property(nonatomic, strong) NSArray<LQSViewItem *> *headestViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *headerViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *headViewItemArray;

@end


@interface LQSZoneView (easySetupSideLef)

@property(nonatomic, strong) UIView *sideLeftestView;
@property(nonatomic, strong) UIView *sideLefterView;
@property(nonatomic, strong) UIView *sideLeftView;

@property(nonatomic, strong) LQSViewItem *sideLeftestViewItem;
@property(nonatomic, strong) LQSViewItem *sideLefterViewItem;
@property(nonatomic, strong) LQSViewItem *sideLeftViewItem;

@property(nonatomic, strong) NSArray<UIView *> *sideLeftestViewArray;
@property(nonatomic, strong) NSArray<UIView *> *sideLefterViewArray;
@property(nonatomic, strong) NSArray<UIView *> *sideLeftViewArray;

@property(nonatomic, strong) NSArray<LQSViewItem *> *sideLeftestViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *sideLefterViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *sideLeftViewItemArray;

@end

@interface LQSZoneView (easySetupLef)

@property(nonatomic, strong) UIView *leftestView;
@property(nonatomic, strong) UIView *lefterView;
@property(nonatomic, strong) UIView *leftView;

@property(nonatomic, strong) LQSViewItem *leftestViewItem;
@property(nonatomic, strong) LQSViewItem *lefterViewItem;
@property(nonatomic, strong) LQSViewItem *leftViewItem;

@property(nonatomic, strong) NSArray<UIView *> *leftestViewArray;
@property(nonatomic, strong) NSArray<UIView *> *lefterViewArray;
@property(nonatomic, strong) NSArray<UIView *> *leftViewArray;

@property(nonatomic, strong) NSArray<LQSViewItem *> *leftestViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *lefterViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *leftViewItemArray;

@end


@interface LQSZoneView (easySetupLeading)

@property(nonatomic, strong) UIView *leadingestView;
@property(nonatomic, strong) UIView *leadingerView;
@property(nonatomic, strong) UIView *leadingView;

@property(nonatomic, strong) LQSViewItem *leadingestViewItem;
@property(nonatomic, strong) LQSViewItem *leadingerViewItem;
@property(nonatomic, strong) LQSViewItem *leadingViewItem;

@property(nonatomic, strong) NSArray<UIView *> *leadingestViewArray;
@property(nonatomic, strong) NSArray<UIView *> *leadingerViewArray;
@property(nonatomic, strong) NSArray<UIView *> *leadingViewArray;

@property(nonatomic, strong) NSArray<LQSViewItem *> *leadingestViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *leadingerViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *leadingViewItemArray;

@end


@interface LQSZoneView (easySetupTrailing)

@property(nonatomic, strong) UIView *trailingestView;
@property(nonatomic, strong) UIView *trailingerView;
@property(nonatomic, strong) UIView *trailingView;

@property(nonatomic, strong) LQSViewItem *trailingestViewItem;
@property(nonatomic, strong) LQSViewItem *trailingerViewItem;
@property(nonatomic, strong) LQSViewItem *trailingViewItem;

@property(nonatomic, strong) NSArray<UIView *> *trailingestViewArray;
@property(nonatomic, strong) NSArray<UIView *> *trailingerViewArray;
@property(nonatomic, strong) NSArray<UIView *> *trailingViewArray;

@property(nonatomic, strong) NSArray<LQSViewItem *> *trailingestViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *trailingerViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *trailingViewItemArray;

@end



@interface LQSZoneView (easySetupRight)

@property(nonatomic, strong) UIView *rightestView;
@property(nonatomic, strong) UIView *righterView;
@property(nonatomic, strong) UIView *rightView;

@property(nonatomic, strong) LQSViewItem *rightestViewItem;
@property(nonatomic, strong) LQSViewItem *righterViewItem;
@property(nonatomic, strong) LQSViewItem *rightViewItem;

@property(nonatomic, strong) NSArray<UIView *> *rightestViewArray;
@property(nonatomic, strong) NSArray<UIView *> *righterViewArray;
@property(nonatomic, strong) NSArray<UIView *> *rightViewArray;

@property(nonatomic, strong) NSArray<LQSViewItem *> *rightestViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *righterViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *rightViewItemArray;

@end



@interface LQSZoneView (easySetupSideRight)

@property(nonatomic, strong) UIView *sideRightestView;
@property(nonatomic, strong) UIView *sideRighterView;
@property(nonatomic, strong) UIView *sideRightView;

@property(nonatomic, strong) LQSViewItem *sideRightestViewItem;
@property(nonatomic, strong) LQSViewItem *sideRighterViewItem;
@property(nonatomic, strong) LQSViewItem *sideRightViewItem;

@property(nonatomic, strong) NSArray<UIView *> *sideRightestViewArray;
@property(nonatomic, strong) NSArray<UIView *> *sideRighterViewArray;
@property(nonatomic, strong) NSArray<UIView *> *sideRightViewArray;

@property(nonatomic, strong) NSArray<LQSViewItem *> *sideRightestViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *sideRighterViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *sideRightViewItemArray;

@end


@interface LQSZoneView (easySetupFoot)

@property(nonatomic, strong) UIView *footestView;
@property(nonatomic, strong) UIView *footerView;
@property(nonatomic, strong) UIView *footView;

@property(nonatomic, strong) LQSViewItem *footestViewItem;
@property(nonatomic, strong) LQSViewItem *footerViewItem;
@property(nonatomic, strong) LQSViewItem *footViewItem;

@property(nonatomic, strong) NSArray<UIView *> *footestViewArray;
@property(nonatomic, strong) NSArray<UIView *> *footerViewArray;
@property(nonatomic, strong) NSArray<UIView *> *footViewArray;

@property(nonatomic, strong) NSArray<LQSViewItem *> *footestViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *footerViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *footViewItemArray;

@end

@interface LQSZoneView (easySetupBottom)

@property(nonatomic, strong) UIView *bottomestView;
@property(nonatomic, strong) UIView *bottomerView;
@property(nonatomic, strong) UIView *bottomView;

@property(nonatomic, strong) LQSViewItem *bottomestViewItem;
@property(nonatomic, strong) LQSViewItem *bottomerViewItem;
@property(nonatomic, strong) LQSViewItem *bottomViewItem;

@property(nonatomic, strong) NSArray<UIView *> *bottomestViewArray;
@property(nonatomic, strong) NSArray<UIView *> *bottomerViewArray;
@property(nonatomic, strong) NSArray<UIView *> *bottomViewArray;

@property(nonatomic, strong) NSArray<LQSViewItem *> *bottomestViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *bottomerViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *bottomViewItemArray;

@end


@interface LQSZoneView (easySetupTabBar)

@property(nonatomic, strong) UIView *tabBarestView;
@property(nonatomic, strong) UIView *tabBarerView;
@property(nonatomic, strong) UIView *tabBarView;

@property(nonatomic, strong) LQSViewItem *tabBarestViewItem;
@property(nonatomic, strong) LQSViewItem *tabBarerViewItem;
@property(nonatomic, strong) LQSViewItem *tabBarViewItem;

@property(nonatomic, strong) NSArray<UIView *> *tabBarestViewArray;
@property(nonatomic, strong) NSArray<UIView *> *tabBarerViewArray;
@property(nonatomic, strong) NSArray<UIView *> *tabBarViewArray;

@property(nonatomic, strong) NSArray<LQSViewItem *> *tabBarestViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *tabBarerViewItemArray;
@property(nonatomic, strong) NSArray<LQSViewItem *> *tabBarViewItemArray;

@end
