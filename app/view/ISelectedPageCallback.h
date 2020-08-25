//
// Created by muzico on 2020/8/22.
// Copyright (c) 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ISelectedPageCallback <NSObject>

- (void) onPickTypeLoaded:(id)result;

- (void) onContentListLoaded:(id)result;

@end
