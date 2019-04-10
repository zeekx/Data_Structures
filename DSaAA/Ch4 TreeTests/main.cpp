//
//  main.c
//  Ch4 TreeTests
//
//  Created by zeek on 2019/4/6.
//  Copyright © 2019 Musca. All rights reserved.
//

#include <stdio.h>
#include <gtest/gtest.h>

int main(int argc, const char * argv[]) {
    ::testing::InitGoogleTest(&argc, (char **)&argv);
    return RUN_ALL_TESTS();
}
