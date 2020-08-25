//
//  AppDelegate.m
//  TicketUnion
//
//  Created by muzico on 2020/8/21.
//  Copyright © 2020 muzico. All rights reserved.
//

#import "AppDelegate.h"
#import "NavigationController.h"
#import "TabBarController.h"

@interface AppDelegate ()

@property(nonatomic,strong) UINavigationController *rootNavigationController;

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    self.rootNavigationController = [LQSCustomRootController navgationControllerClass:[NavigationController class] withRootViewControllerClass:[TabBarController class] scene:nil toWindow:self.window];
    
    return YES;
}


#pragma mark - UISceneSession lifecycle


- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options {
    // Called when a new scene session is being created.
    // Use this method to select a configuration to create the new scene with.
    return [[UISceneConfiguration alloc] initWithName:@"Default Configuration" sessionRole:connectingSceneSession.role];
}


- (void)application:(UIApplication *)application didDiscardSceneSessions:(NSSet<UISceneSession *> *)sceneSessions {
    // Called when the user discards a scene session.
    // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
    // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
}


@end
