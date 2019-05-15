//
//  ComplexTests.cpp
//  ComplexTests
//
//  Created by Milo on 2019/5/15.
//  Copyright © 2019 Musca. All rights reserved.
//

#include <gtest/gtest.h>
#include "../Complex/Complex.hpp"

namespace {
    class ComplexTest: public ::testing::Test {
    public:
        
    };
    
    TEST_F(ComplexTest, operator_equal) {
        Complex a(1, 3);
        Complex b(1, 2);
        Complex c(1, 2);
        Complex d(3, 2);
        
        ASSERT_TRUE(b == c);
        ASSERT_FALSE(a == b);
        ASSERT_FALSE(c == d);
        ASSERT_FALSE(a == d);
    }
    
    TEST_F(ComplexTest, operator_plus) {
        Complex a(3, 3);
        Complex b(1, 2);
        Complex c(2, 1);
        
        auto sum = b + c;
        ASSERT_TRUE(sum == a);
    }
}
