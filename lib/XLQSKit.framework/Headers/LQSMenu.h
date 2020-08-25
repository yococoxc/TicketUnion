//
//  LQSMenu.h
//  LQSKit
//
//  Created by muzico on 2018/7/25.
//  Copyright © 2018年 muzico. All rights reserved.
//

#import "LQSBasicViewTemplate.h"

#import "LQSMenuDetailView.h"

typedef NS_ENUM(NSUInteger, LQSMenuStyle) {
    LQSMenuStyleAverageDefault,
    LQSMenuStyleDynamicDefault,
    LQSMenuStyleAverageCustom,
    LQSMenuStyleDynamicCustom,
    LQSMenuStyleFixedWidthDefault,
    LQSMenuStyleFixedWidthCustom,
    LQSMenuStyleFixedWidthDefaultCenter,
    LQSMenuStyleFixedWidthCustomCenter,
    
    LQSMenuStyleAverageDefaultLeft,
    LQSMenuStyleDynamicDefaultLeft,
    LQSMenuStyleAverageCustomLeft,
    LQSMenuStyleDynamicCustomLeft,
    LQSMenuStyleFixedWidthDefaultLeft,
    LQSMenuStyleFixedWidthCustomLeft,
    LQSMenuStyleFixedWidthDefaultCenterLeft,
    LQSMenuStyleFixedWidthCustomCenterLeft,

    LQSMenuStyleAverageDefaultRight,
    LQSMenuStyleDynamicDefaultRight,
    LQSMenuStyleAverageCustomRight,
    LQSMenuStyleDynamicCustomRight,
    LQSMenuStyleFixedWidthDefaultRight,
    LQSMenuStyleFixedWidthCustomRight,
    LQSMenuStyleFixedWidthDefaultCenterRight,
    LQSMenuStyleFixedWidthCustomCenterRight,
    
    LQSMenuStyleAverageDefaultLeftRight,
    LQSMenuStyleDynamicDefaultLeftRight,
    LQSMenuStyleAverageCustomLeftRight,
    LQSMenuStyleDynamicCustomLeftRight,
    LQSMenuStyleFixedWidthDefaultLeftRight,
    LQSMenuStyleFixedWidthCustomLeftRight,
    LQSMenuStyleFixedWidthDefaultCenterLeftRight,
    LQSMenuStyleFixedWidthCustomCenterLeftRight,
};

@class LQSMenu;


typedef void(^LQSMenuSetupDetailViewBlock)(LQSMenuDetailView *detailView);

@protocol LQSMenuDataSource <NSObject>
@required
- (NSUInteger) numberOfViewsInLQSMenu:(LQSMenu *)menu;


@optional
//LQSMenuStyleAverageCustom、LQSMenuStyleDynamicCustom
- (UIView*) lqsMenu:(LQSMenu *)menu viewAtIndex:(NSUInteger)index;
//适用于LQSMenuStyleAverageDefault、LQSMenuStyleDynamicDefault
- (NSString* ) lqsMenu:(LQSMenu *)menu textAtIndex:(NSUInteger)index;

//指定大小。仅适用于LQSMenuStyleDynamicCustom。
//- (CGFloat) lqsMenu:(LQSMenu *)menu dynamicWidthOfViewAtIndex:(NSUInteger)index;
//指定大小。仅适用于LQSMenuStyleDynamicCustom。
- (CGFloat) lqsMenu:(LQSMenu *)menu dynamicWidthOfView:(UIView *)view atIndex:(NSUInteger)index;


//可以修改默认的 LQSMenuDetailView 实例。
- (void) lqsMenu:(LQSMenu *)menu setupWithLQSMenuDetailView:(LQSMenuDetailView*)detailView;


- (void) lqsMenu:(LQSMenu *)menu setupWithButton:(UIButton*)button;

@end


@protocol LQSMenuDelegate <NSObject>
@optional

- (BOOL) lqsMenu:(LQSMenu *)menu canSelectAtIndex:(NSInteger)index;

- (BOOL) lqsMenu:(LQSMenu *)menu canRepeatSelectAtIndex:(NSInteger)index;

- (void) lqsMenu:(LQSMenu *)menu didSelectAtIndex:(NSInteger)index;

//默认执行 currentSelect 为 0 值。返回 NO，将不会执行默认设置。
- (BOOL) actionOfLeftButtonInLQSMenu:(LQSMenu *)menu;

//默认调用 LQSMenuDetailView 实例。使用于 style 为 Default。返回 NO，将不会执行默认设置。
- (BOOL) actionOfRightButtonInLQSMenu:(LQSMenu *)menu;

@end


@interface LQSMenu : LQSBasicViewTemplate

@property(nonatomic,strong,readonly) UIScrollView* scrollView;

@property(nonatomic,strong,readonly) UIView* scrollContentView;

@property(nonatomic,strong,readonly) UIView* scrollLine;

@property(nonatomic,strong,readonly) UIButton* leftButton;
@property(nonatomic,strong,readonly) UIImageView* leftButtonIcon;
//20
@property(nonatomic,assign) CGFloat leftButtonIconSize;
//默认自适应，与高度同等大小。
@property(nonatomic,assign) CGFloat leftButtonWidth;

//LQS_Icon_Home_C
@property(nonatomic,strong) id leftButtonIconImage;

@property(nonatomic,strong,readonly) UIButton* rightButton;
@property(nonatomic,strong,readonly) UIImageView* rightButtonIcon;
//20
@property(nonatomic,assign) CGFloat rightButtonIconSize;
//默认自适应，与高度同等大小。
@property(nonatomic,assign) CGFloat rightButtonWidth;

//LQS_Icon_Arrow_Down_B
@property(nonatomic,strong) id rightButtonIconImage;


//默认点击右键触发默认事件 pressedRightButtonToDoSomething:
//将会出现LQSMenuDetailView，可以通过下面方法来修改
- (void) setupWithDetailView:(LQSMenuSetupDetailViewBlock)aBlock;


@property(nonatomic,assign) LQSMenuStyle style;

@property(nonatomic,weak) id<LQSMenuDataSource> dataSource;

@property(nonatomic,weak) id<LQSMenuDelegate> delegate;

//通过该值可以知道，style 为 Default 时，有多少 text。
@property(nonatomic,strong,readonly) NSArray* texts;

//默认值为0，不想在开始选中就设置为-1。
@property(nonatomic,assign) NSInteger currentSelect;


#pragma mark - button 属性设置
//YES
@property(nonatomic,assign) BOOL scrollViewAnimated;

//0
@property(nonatomic,assign) CGFloat gap;

//0。这个是测试，仅仅适用于 style 为 LQSMenuStyleFixedWidth 的时候。Center不适用。
@property(nonatomic,assign) CGFloat leftGap;
@property(nonatomic,assign) CGFloat rightGap;

//80。仅仅适用于 style 为 LQSMenuStyleFixedWidth 的时候。
@property(nonatomic,assign) CGFloat buttonFixedWidth;


//30。仅仅适用于 style 为 LQSMenuStyleDynamic 的时候。不适用于 LQSMenuStyleDynamicCustom。
@property(nonatomic,assign) CGFloat buttonMinimumWidth;

//10。仅仅适用于 style 为 LQSMenuStyleDynamic 的时候。不适用于 LQSMenuStyleDynamicCustom。
@property(nonatomic,assign) CGFloat buttonOffsetWidth;


//14
@property(nonatomic,assign) CGFloat buttonFontSize;
//nil，假如该值被设置了，就会采用该值来配置内容，无视上面的设置。
@property(nonatomic,assign) UIFont* buttonFont;

//#8B858D
@property(nonatomic,strong) id buttonTextColor;
//#0F0F0F
@property(nonatomic,strong) id buttonTextSelectedColor;


#pragma mark - scrollLine 属性设置
//-10
@property(nonatomic,assign) CGFloat scrollLineWidthOffset;
//4
@property(nonatomic,assign) CGFloat scrollLineHeight;
//指定宽度，假如一旦设置了，就会取消默认的设置。scrollLineWidthOffset 会失效。
@property(nonatomic,assign) CGFloat scrollLineWidth;
//3
@property(nonatomic,assign) CGFloat scrollLineBottom;
//0.3
@property(nonatomic,assign) NSTimeInterval scrollLineDuration;
//#BE00FA
@property(nonatomic,strong) id scrollLineColor;
//2
@property(nonatomic,assign) CGFloat scrollLineCornerRadius;

//是否将 scrollLine 设置到 menu 的button 后面显示。默认 NO。
@property(nonatomic,assign) BOOL scrollLineIsBack;


//获取到定制的视图集合
@property(nonatomic,strong,readonly) NSArray* customViews;

#pragma mark -

- (UIButton*) buttonWithTag:(NSInteger)tag;
- (UIView *) itemViewWithTag:(NSInteger)tag;


- (NSArray *) itemViewsWithNoTag:(NSInteger)tag;

@end
