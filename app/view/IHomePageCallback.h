//
// Created by muzico on 2020/8/22.
// Copyright (c) 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IBaseViewCallback.h"

@protocol IHomePageCallback <IBaseViewCallback>

- (void) onCategoriesLoaded:(id)result;

@end