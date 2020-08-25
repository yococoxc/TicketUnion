//
//  LQSEasyMenuScrollPageView.h
//  reApp
//
//  Created by muzico on 2020/7/10.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <XLQSKit/XLQSKit.h>


@interface LQSEasyMenuScrollPageView : UIView

@property(nonatomic,readonly) LQSMenu *menu;

@property(nonatomic,readonly) LQSScrollPageView *scrollPageView;


/**
 字典，key为 name，value 就是要显示的内容。
 字符串，直接显示的内容。
 */
@property(nonatomic,strong) NSArray *menuDataSource;

/**
 view 或者 viewcontroller
 */
@property(nonatomic,strong) NSArray *pages;


@property(nonatomic,assign) NSUInteger selectedIndex;

@property(nonatomic,readonly) id currentObject;


- (void) reloadData;

@end
