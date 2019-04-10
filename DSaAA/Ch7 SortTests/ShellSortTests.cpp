//
//  ShellSortTests.cpp
//  Ch7 SortTests
//
//  Created by Milo on 2019/4/9.
//  Copyright © 2019 Musca. All rights reserved.
//

#include <stdio.h>
#include <gtest/gtest.h>
#include "../Ch7 Sort/ShellSort.hpp"
#include "../Ch7 Sort/Sort.hpp"

namespace {
    TEST(ShellSort, Simple) {
        
        ElementType array[] = {81,94,11,96,12,
                                35,17,95,28,58,
                                41, 75, 15 };
        
        ElementType sortArray[] = {11,12,15,17,28,
                                    35,41,58,75,84,
                                    94,95,96};
        
        ShellSort(array, sizeof(array) / sizeof(ElementType));
        ASSERT_TRUE( compareArray(sortArray, sizeof(sortArray)/sizeof(ElementType),
                                  array, sizeof(array)/sizeof(ElementType)));
        
    }
}
