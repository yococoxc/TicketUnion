//
//  HomeContentCarouselAdapter.m
//  TicketUnion
//
//  Created by muzico on 2020/8/25.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "HomeContentCarouselAdapter.h"
#import "YYWebImage.h"

@implementation HomeContentCarouselAdapter


- (void) setupImageView:(UIImageView *)imageView withData:(id)data {
    NSString *pict_url = [data lqs_objectForKey:@"pict_url"];
    
    NSString *url = pict_url;
    if ([url hasPrefix:@"//"]) {
        url = [NSString stringWithFormat:@"https:%@",pict_url];
    }
    
    [imageView yy_setImageWithURL:[NSURL URLWithString:url] placeholder:nil];
}

@end
