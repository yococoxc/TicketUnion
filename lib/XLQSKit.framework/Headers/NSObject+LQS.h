//
//  NSObject+LQS.h
//  LQSKit
//
//  Created by muzico on 2018/7/20.
//  Copyright © 2018年 muzico. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@interface NSObject (LQS)

/**
 这个值没有任何特殊用途，你可以任意使用这个拓展。
 */
@property(strong) id lqs_viewHolderObject;



/**
 对数组、字典类型进行查询操作。
 格式，如：[0]/00/01/02w/[1]/04x
 其中：[0]，代表查询数组索引值为0
 
 2020-06-20加入。
 */
- (id) lqs_jsonQuery:(NSString *)query;
/**
 效果参照上面
 但假如对象是 NSNumber类型，则会转成 NSString。
 
 2020-06-20加入。
 */
- (id) lqs_jsonQueryAndNumberToString:(NSString *)query;



/**
数组，安全获取。
 符合有内容，不符合为nil。
 
 by2020-07-17
*/
- (id) lqs_objectAtIndex:(NSInteger)index;
/**
 字典，安全获取。
 将 NSNumber 转成 NSString 输出，其他不变。
 
 by2020-07-17
 
 null类型将转为 nil
 by2020-07-27
 */
- (id) lqs_objectForKey:(NSString *)key;

/**
 从字典中获取对象并转换成double。
 */
- (double) lqs_doubleForKey:(NSString *)key;

/**
 从字典中获取对象并转换成double。
 */
- (NSInteger) lqs_integerForKey:(NSString *)key;

/**
 字典中
 将浮点数字转成字符串，默认保留2位小数。
 by2020-08-20
 */
- (NSString *) lqs_stringWithFloatNumberForKey:(NSString *)key;
/**
字典中
将浮点数字转成字符串，保留1位小数。
by2020-08-20
*/
- (NSString *) lqs_stringWithFloatNumber1ForKey:(NSString *)key;
/**
字典中
将浮点数字转成字符串，保留3位小数。
by2020-08-20
*/
- (NSString *) lqs_stringWithFloatNumber3ForKey:(NSString *)key;
/**
字典中
将浮点数字转成字符串，保留4位小数。
by2020-08-20
*/
- (NSString *) lqs_stringWithFloatNumber4ForKey:(NSString *)key;


- (BOOL) lqs_isEqualToString:(NSString*)aString;


@property(nonatomic,readonly) NSString* lqs_toString;
@property(nonatomic,readonly) NSString* lqs_toXingString;


@property (nonatomic,readonly) UIViewController *lqs_currentViewController;
- (UIViewController *) lqs_currentViewControllerWithClass:(Class)aClass;


@property (nonatomic,readonly) UINavigationController *lqs_currentNavigationController;

- (BOOL) lqs_currentNavigationControllerPushViewController:(UIViewController*)viewController;
- (BOOL) lqs_currentNavigationControllerPushViewController:(UIViewController*)viewController animated:(BOOL)animated;


- (BOOL) lqs_currentNavigationControllerHidesBottomBarWhenPushViewController:(UIViewController*)viewController;
- (BOOL) lqs_currentNavigationControllerHidesBottomBarWhenPushViewController:(UIViewController*)viewController animated:(BOOL)animated;


- (NSArray*) lqs_currentNavigationControllerPopToRootViewController;
- (NSArray*) lqs_currentNavigationControllerPopToRootViewControllerAnimated:(BOOL)animated;

- (UIViewController*) lqs_currentNavigationControllerPopViewController;
- (UIViewController*) lqs_currentNavigationControllerPopViewControllerAnimated:(BOOL)animated;


- (void) lqs_currentControllerPresentViewController:(UIViewController *)viewController;
- (void) lqs_currentControllerPresentViewController:(UIViewController *)viewController animated:(BOOL)animated;
- (void) lqs_currentControllerPresentViewController:(UIViewController *)viewController animated:(BOOL)animated completion:(void (^)(void))completion;


- (void) lqs_currentControllerDismissViewController;
- (void) lqs_currentControllerDismissViewControllerAnimated:(BOOL)animated;
- (void) lqs_currentControllerDismissViewControllerAnimated:(BOOL)animated completion:(void (^)(void))completion;


@property(nonatomic,readonly) BOOL lqs_isUIFont;
@property(nonatomic,readonly) BOOL lqs_isNSArray;
@property(nonatomic,readonly) BOOL lqs_isNSDictionary;
@property(nonatomic,readonly) BOOL lqs_isNSString;
@property(nonatomic,readonly) BOOL lqs_isNSNumber;
@property(nonatomic,readonly) BOOL lqs_isUIView;
@property(nonatomic,readonly) BOOL lqs_isUILabel;
@property(nonatomic,readonly) BOOL lqs_isUICollectionView;
@property(nonatomic,readonly) BOOL lqs_isUITableView;
@property(nonatomic,readonly) BOOL lqs_isUIButton;
@property(nonatomic,readonly) BOOL lqs_isUIImageView;
@property(nonatomic,readonly) BOOL lqs_isUIImage;
@property(nonatomic,readonly) BOOL lqs_isUIControl;
@property(nonatomic,readonly) BOOL lqs_isUIWindow;
@property(nonatomic,readonly) BOOL lqs_isUINavigationController;
@property(nonatomic,readonly) BOOL lqs_isUIViewController;
@property(nonatomic,readonly) BOOL lqs_isUITabBarController;


@property(nonatomic,readonly) NSString* lqs_jsonString;
@property(nonatomic,readonly) id lqs_json;
@property(nonatomic,readonly) NSData* lqs_jsonData;

@property(nonatomic,readonly) NSUInteger lqs_length;




- (void) lqs_setupWithObject:(void(^)(NSObject* object))aBlock;


/**
 判断是否存在 setupWithDataSource: 方法，
 存在则调用它。
 */
- (void) lqs_call_setupWithDataSource:(id)dataSource;


@property(nonatomic,readonly) NSString* lqs_classString;
+ (NSString *) lqs_classString;




/**
 Swift 类名格式为：模块（工程） +  .  + 类名
 本方法只获取类名。
 */
@property(nonatomic,readonly) NSString* lqs_classStringX;
+ (NSString *) lqs_classStringX;






@end
