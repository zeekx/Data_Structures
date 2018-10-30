//
//  BinarySearch14.cpp
//  Data Structures
//
//  Created by Milo on 2018/10/30.
//  Copyright © 2018 Zeek. All rights reserved.
//

#include "BinarySearch14.hpp"
#include <gtest/gtest.h>

namespace  {
    class BinarySearch14Test: public ::testing::Test {
    protected:
        BinarySearch14 s;
    };
    
    TEST_F(BinarySearch14Test, binarySearch_empty) {
        vector<int> numbers;
        const int target = 3;
        ASSERT_EQ(s.binarySearch(numbers, target), -1);
    }

    
    TEST_F(BinarySearch14Test, binarySearch) {
        vector<int> numbers {1, 2, 3, 3, 4, 5, 10};
        const int target = 3;
        ASSERT_EQ(s.binarySearch(numbers, target), 2);
    }
    
    TEST_F(BinarySearch14Test, binarySearch_oneResult) {
        vector<int> numbers {1, 2, 3, 4, 5, 10};
        const int target = 3;
        ASSERT_EQ(s.binarySearch(numbers, target), 2);
    }
    
    TEST_F(BinarySearch14Test, binarySearch3) {
        vector<int> numbers { 2, 3, 3, 3, 3, 4};
        const int target = 3;
        ASSERT_EQ(s.binarySearch(numbers, target), 1);
    }
    
    TEST_F(BinarySearch14Test, binarySearch_allSame) {
        vector<int> numbers { 3, 3, 3, 3, 3, 3};
        const int target = 3;
        ASSERT_EQ(s.binarySearch(numbers, target), 0);
    }


}
