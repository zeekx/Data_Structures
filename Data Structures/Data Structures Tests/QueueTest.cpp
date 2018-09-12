//
//  QueueTest.cpp
//  Data Structures
//
//  Created by Milo on 2018/9/12.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#include <gtest/gtest.h>
#include "Queue.hpp"

namespace {
    class QueueTest: public ::testing::Test {
    protected:
        Queue<int> queue;
    };
    
    TEST_F(QueueTest, empty) {
        ASSERT_TRUE(queue.empty());
        queue.enqueue(0);
        ASSERT_FALSE(queue.empty());
    }
    
    TEST_F(QueueTest, size) {
        queue.enqueue(3);
        EXPECT_EQ(queue.size(), 1);
        queue.enqueue(33);
        EXPECT_EQ(queue.size(), 2);
    }
    
    TEST_F(QueueTest, enqueue) {
        queue.enqueue(3);
        ASSERT_TRUE(queue.front() == 3);
    }
    
    TEST_F(QueueTest, dequeue) {
        int input = 3;
        queue.enqueue(input);
        queue.enqueue(33);
        ASSERT_TRUE(queue.dequeue() == input);
        ASSERT_TRUE(queue.dequeue() == 33);
    }
}
