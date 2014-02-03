//
//  main.m
//  ios
//
//  Created by mucbuc on 2/2/14.
//  Copyright (c) 2014 markymark. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "AppDelegate.h"
#import "impl.h"

int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        std::cout << "error: expected test server url" << std::endl;
        return 1;
    }
    else
    	impl::run_test( argv[1] );
    
    @autoreleasepool {
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
