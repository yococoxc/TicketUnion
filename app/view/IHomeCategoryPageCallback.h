//
//  IHomeCategoryPageCallback.h
//  TicketUnion
//
//  Created by muzico on 2020/8/22.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IBaseHomePagerCallback.h"

@protocol IHomeCategoryPageCallback <IBaseHomePagerCallback>

@required


/**
 
 */
- (void) onContentLoadedWithResult:(id)result withCategoryId:(NSString *)categoryId;

/**

 */
 - (void) onLoaderMoreEmpty:(NSString *)categoryId;

/**

 */
- (void) onLoaderMoreError:(NSString *)categoryId;


/**

 */
- (void) onLoaderMoreLoadedWithResult:(id)result withCategoryId:(NSString *)categoryId;


/**

 */
- (void) onLooperDataLoadedWithResult:(id)result withCategoryId:(NSString *)categoryId;

@end


