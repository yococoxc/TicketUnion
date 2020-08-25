//
//  LQSProcessRecord.h
//  XLQSKit
//
//  Created by muzico on 2020/8/5.
//  Copyright © 2020 muzico. All rights reserved.
//

#import <Foundation/Foundation.h>

#define LQSProcessRecordDefaultInfo ([NSString stringWithFormat:@"%s  %s  %d",[LQSDate dateString],__func__,__LINE__])
#define LQSProcessRecordDefaultAction ([LQSProcessRecord recordString:LQSProcessRecordDefaultInfo];)


NS_ASSUME_NONNULL_BEGIN

@interface LQSProcessRecord : NSObject

/**
 记录内容。
 */
+ (void) recordString:(NSString *)aString;

+ (void) txtFlieRecordString:(NSString *)aString;

@end

NS_ASSUME_NONNULL_END
