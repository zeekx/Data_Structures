//
//  LintCode.cpp
//  Data Structures
//
//  Created by Milo on 2018/10/30.
//  Copyright © 2018 Zeek. All rights reserved.
//

#include "TwoSum56.h"
#include <gtest/gtest.h>

namespace  {
    class TwoSum56Test: public ::testing::Test {
    protected:
        void SetUp() override {

        }

        TwoSum56 s;
    };
    
    
    TEST_F(TwoSum56Test, twoSum) {
        vector<int> numbers {2, 7, 11, 15};
        const int target = 9;
        vector<int> v = s.twoSum(numbers, target);
        ASSERT_EQ(numbers[v[0]] + numbers[v[1]], 9);
        ASSERT_LT(v[0], v[1]);
    }
    
    TEST_F(TwoSum56Test, notFound) {
        vector<int> numbers {2, 8, 11, 15};
        const int target = 9;
        vector<int> v = s.twoSum(numbers, target);
        ASSERT_EQ(v.size(), 0);
    }

    
    TEST_F(TwoSum56Test, twoSum_end) {
        vector<int> numbers {11, 8, 11, 15, 2, 7};
        const int target = 9;
        vector<int> v = s.twoSum(numbers, target);
        ASSERT_EQ(numbers[v[0]] + numbers[v[1]], 9);
        ASSERT_LT(v[0], v[1]);
    }
    
    TEST_F(TwoSum56Test, twoSum_mid) {
        vector<int> numbers {11, 8, 2, 15, 2, 7};
        const int target = 9;
        vector<int> v = s.twoSum(numbers, target);
        ASSERT_EQ(numbers[v[0]] + numbers[v[1]], 9);
        ASSERT_LT(v[0], v[1]);
    }

    TEST_F(TwoSum56Test, twoSum_equal_target) {
        vector<int> numbers {11, 8, 9, 15, 2, 8, 0};
        const int target = 9;
        vector<int> v = s.twoSum(numbers, target);
        ASSERT_EQ(numbers[v[0]] + numbers[v[1]], 9);
        ASSERT_LT(v[0], v[1]);
    }
    
    TEST_F(TwoSum56Test, twoSum_size_0) {
        vector<int> numbers {9};
        const int target = 9;
        vector<int> v = s.twoSum(numbers, target);
        ASSERT_EQ(v.size(), 0);
    }



}
