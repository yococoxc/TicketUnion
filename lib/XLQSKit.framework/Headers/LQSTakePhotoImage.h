//
//  LQSTakePhotoImage.h
//  reApp
//
//  Created by muzico on 2020/7/7.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 从相册、拍照中获取图片
 */


typedef void(^LQSTakePhotoImagelock)(UIImage *image);

@interface LQSTakePhotoImage : NSObject

+ (instancetype) showWithController:(UIViewController *)vc image:(LQSTakePhotoImagelock)imageBlock;

+ (instancetype) showWithController:(UIViewController *)vc allowsEditing:(BOOL)allowsEditing image:(LQSTakePhotoImagelock)imageBlock;

@end
