//
//  StackTest.cpp
//  Data Structures Tests
//
//  Created by zeek on 2018/8/31.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#include <gtest/gtest.h>
#include "Stack.hpp"

namespace {
    class StackTest: public ::testing::Test {
    protected:
        void SetUp() override {
            
        }
        
        Stack<int> stack_;
    };
    
    TEST_F(StackTest, push) {
        int input = 3;
        stack_.push(input);
        ASSERT_EQ(input, stack_.top());
        ASSERT_EQ(stack_.size(), 1);
    }

    TEST_F(StackTest, push2) {
        int input1 = 3, input2 = 6;
        stack_.push(input1);
        stack_.push(input2);
        ASSERT_EQ(input2, stack_.top());
        ASSERT_EQ(stack_.size(), 2);
    }

    
    TEST_F(StackTest, pop) {
        int input = 33;
        stack_.push(input);
        ASSERT_EQ(stack_.pop(), input);
        ASSERT_EQ(stack_.size(), 0);
    }
    
    TEST_F(StackTest, top) {
        int top = 6;
        stack_.push(3);
        stack_.push(top);
        ASSERT_EQ(top, stack_.top());
    }

}
