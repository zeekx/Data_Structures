//
//  Chapter0.cpp
//  Data Structures Tests
//
//  Created by Milo on 2018/8/30.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#include <gtest/gtest.h>
#include "../Chapter0/chapter0.hpp"
namespace  {
    TEST(Sum, Empty) {
        ASSERT_EQ(sum({}), 0);
    }
    
    TEST(Sum, _1_plus_2) {
        ASSERT_EQ(sum({1, 2}), 3);
    }

    
    TEST(Reverse, simple) {
        std::array<int, 5> arr = {1, 2, 3, 4, 5};
        reverse(&arr, 0, arr.size() - 1);
        ASSERT_EQ(arr[0], 5);
        ASSERT_EQ(arr[1], 4);
        ASSERT_EQ(arr[2], 3);
        ASSERT_EQ(arr[3], 2);
        ASSERT_EQ(arr[4], 1);
    }
}
