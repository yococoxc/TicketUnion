//
//  XLQSKit.h
//  XLQSKit
//
//  Created by muzico on 2020/5/4.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for XLQSKit.
FOUNDATION_EXPORT double XLQSKitVersionNumber;

//! Project version string for XLQSKit.
FOUNDATION_EXPORT const unsigned char XLQSKitVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <XLQSKit/PublicHeader.h>

/**
 XLQSKit 最后修改时间为：
 2020-08-24 10:12 pm
 */


/*************************
 注     意
 
 *************************
 需要引入第三方库，
 本设计里面使用了：
 [暂无]
 
 
 **************************
 Build Settings -> Linking -> Other Linker Flags 加入 -ObjC 值。
 否则会奔溃。
 
 
 **************************
 需要引入库：
 WebKit.framework
 
 
 ************************/

#define LQSWeakSelf \
__weak typeof(self) weakSelf = self;

#pragma mark -
#import "LQSView.h"
#import "LQSController.h"
#import "LQSRequest.h"
#import "LQSRequestParse.h"
#import "LQSRequestResponse.h"
#import "LQSModel.h"
#import "LQS.h"
#import "LQSRequestImplement.h"
#import "LQSTabBarController.h"
#import "LQSAverageView.h"
#import "LQSViewController.h"
#import "LQSHeadViewController.h"
#import "LQSHeadView.h"
#import "LQSStore.h"
#import "LQSCollectionView.h"
#import "LQSHeadCollectionViewController.h"
#import "LQSWebView.h"
#import "LQSHeadWebViewController.h"
#import "LQSImageControl.h"
#import "LQSPredefined.h"
#import "LQSMenuDetailView.h"
#import "LQSMenuScrollPageView.h"
#import "LQSScrollPageView.h"
#import "LQSMenu.h"
#import "LQSViewTemplate.h"
#import "LQSViewTemplateCollection.h"
#import "LQSViewTemplateCollectionItem.h"
#import "LQSNotitia.h"
#import "LQSText.h"
#import "LQSDate.h"
#import "LQSBoxController.h"
#import "LQSNavigationController.h"

#import "LQSProjectAdapter.h"/*????*/
#import "LQSControllerTemplate.h"/*????*/

#import "LQSSideSlipView.h"/*侧滑*/
#import "LQSWeakObjectManager.h"
#import "LQSSafeAreaController.h"
#import "LQSContainerView.h"


#import "LQSTitleControl.h"


#import "LQSFixController.h"
#import "LQSFixView.h"
#import "LQSViewItem.h"


#import "LQSUICustodian.h"

#import "LQSCollectionViewSectionItem.h"
#import "LQSCollectionViewSection.h"


#import "CommonCollectionCell.h"
#import "CommonCollectionReusableView.h"


#import "LQSStickyScrollView.h"
#import "LQSStickyScrollView2.h"


/**
 2019-12-02添加
 */
#import "LQSIntent.h"

/**
 2019-12-03添加
 */
#import "LQSAbc.h"

/**
2019-12-06添加
 渐变色的视图
*/
#import "LQSGradientColorView.h"

/**
 2019-12-17添加
 放入多个VC在同一个VC中展示
 原型为VCContainer，创建于2019-5-20
 */
#import "LQSControllerContainerFixController.h"

/**
 2019-12-17添加
 原型为UICollectionViewAdapter，创建于2019-11-8
 */
#import "LQSUICollectionViewAdapter.h"

/**
2019-12-17添加
*/
#import "LQSAppManager.h"


/**
 2019-12-22添加
 */
#import "LQSCollectionViewSectionColorImageLayout.h"

/**
2019-12-25添加
*/
#import "LQSCollectionViewAdapterManager.h"


/**
2020-01-09添加
*/
#import "LQSListAdapterManager.h"

/**
2020-01-10添加
 该视图自身不会参加点击事件，但子视图会参与。
*/
#import "LQSAirThroughView.h"

/**
2020-01-14添加
*/
#import "LQSAirThroughFixView.h"
#import "LQSHorizontalScrollView.h"



/**
2020-05-27添加
 输入短信验证码
*/
#import "LQSCodeResignView.h"


/**
2020-06-15添加
*/
#import "LQSListGapAdapter.h"

/**
2020-07-02添加
 自制封装版的 Carousel，改自 CWCarousel 1.1.5
*/
#import "LQSCarousel.h"
#import "LQSListCarouselAdapter.h"



/**
2020-07-07添加
 时间选择器
*/
#import "LQSDatePickerController.h"

/**
2020-07-07添加
 从相册、拍照中获取图片，简便工具
*/
#import "LQSTakePhotoImage.h"

/**
2020-07-07添加
弹出选择器
*/
#import "LQSPopSelectController.h"


/**
2020-07-09添加
 简化版ListView
*/
#import "LQSEasyListView.h"


/**
2020-07-11添加
*/
#import "LQSEasyMenuScrollPageView.h"

/**
2020-07-11添加
*/
#import "LQSInputController.h"


/**
2020-07-15添加
*/
#import "LQSCustomRootController.h"



/**
2020-07-31添加
*/
#import "LQSPokeData.h"





/**
2020-08-01添加
 这个比起 LQSFixView 更加强大的 LQSZoneView。
*/
#import "LQSZoneView.h"
#import "LQSZoneController.h"







/**
2020-08-01添加
 ...........会用就用吧。
*/
#import "LQSRequestModel.h"
#import "LQSRequestBean.h"
#import "LQSRequestCallback.h"
#import "LQSInternalRequest.h"

/**
2020-08-04添加
*/
#import "NSMutableDictionary+LQS.h"




/**
2020-08-05添加
 进程记录器，记录代码的执行，定时生成记录文件。
*/
#import "LQSProcessRecord.h"





/**
2020-08-12添加
 row 布局
*/
#import "LQSGhostRow.h"

/**
2020-08-12添加
*/
#import "LQSGhostControlLabel.h"




/**
2020-08-24添加
*/
#import "LQSShrinkView.h"
#import "LQSShrinkMenuScrollPageView.h"


#pragma mark - LQS - Layout

/**
2020-01-14添加
*/
#import "LQSLayoutContainer.h"
#import "LQSLayoutContainerControl.h"









#pragma mark - LQS+
#import "NSObject+LQS.h"
#import "NSArray+LQS.h"
#import "NSDictionary+LQS.h"
#import "NSString+LQS.h"
#import "NSDate+LQS.h"
/**
2020-05-09添加
*/
#import "NSMutableArray+LQS.h"

#import "UIView+LQS.h"
#import "UIControl+LQS.h"
#import "UIButton+LQS.h"
#import "UILabel+LQS.h"
#import "UIImageView+LQS.h"
#import "UICollectionView+LQS.h"
#import "UITextField+LQS.h"

#import "UIViewController+LQS.h"
#import "UIAlertView+LQS.h"
#import "UITableViewCell+LQS.h"

#import "UIFont+LQS.h"
#import "UITextView+LQS.h"
#import "UIImage+LQS.h"

#import "UIApplication+LQS.h"
/**
2020-05-11添加
 JSON模型转换
*/
#import "NSObject+LQSModel.h"


/**
2020-08-22添加
*/
#import "UITabBarItem+LQS.h"


#pragma mark - Basic
#import "LQSBasicView.h"
#import "LQSBasicControl.h"
#import "LQSBasicTableViewCell.h"
#import "LQSBasicCollectionViewCell.h"
#import "LQSBasicCollectionReusableView.h"

#import "LQSBasicObject.h"

#import "LQSBasicViewTemplate.h"
#import "LQSBasicViewTemplateControl.h"
#import "LQSBasicControlTemplate.h"


#import "LQSWeightLayout.h"
#import "LQSCenterLayout.h"



#pragma mark - Easy
#import "EasyGroupView.h"


#pragma mark - beta 有待修改、完善的
#import "CommonTableView.h"
#import "CommonFormView2.h"
#import "CommonCollectionView.h"
#import "CommonPageScrollView2.h"
#import "CommonScrollView2.h"
#import "CommonDynamicFormView.h"
#import "CommonFixView.h"
#import "CommonControlBarView.h"
#import "CommonFormView.h"/*不要用这个*/




#pragma mark - 3rd
#import "LQSCWCarouselHeader.h"


/**
 2019-08-21
 加强、优化 LQSDate 对时间戳的处理。
 */


/**
 Xcode11编译版本。不支持32位。仅仅支持64位。
 */


/**
 2020-05-01
 移除UIWebView
 */
/**
 2020-05-09
 修改 CommonCollectionCell 的bug
 */



/**
 2020-07-01
 根据实际需求修改LQSMenuScrollView
 */
