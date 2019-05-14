//
//  main.cpp
//  ComplexTests
//
//  Created by Milo on 2019/5/14.
//  Copyright © 2019 Musca. All rights reserved.
//

#include <iostream>
#include <gtest/gtest.h>

int main(int argc, const char * argv[]) {
    ::testing::InitGoogleTest(&argc, (char **)&argv);
    return RUN_ALL_TESTS();
}
