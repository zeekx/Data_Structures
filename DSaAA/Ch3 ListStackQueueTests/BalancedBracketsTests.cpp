//
//  BalancedBracketsTests.c
//  Ch3 ListStackQueueTests
//
//  Created by zeek on 2019/4/5.
//  Copyright © 2019 Musca. All rights reserved.
//

#include <stdio.h>
#include <gtest/gtest.h>
#include "../Ch3 ListStackQueue/BalancedBrackets.hpp"

TEST(Stack, BalancedBrackets1) {
    const char *queueOfBrackets = "()[]";
    ASSERT_TRUE(isBalanced(queueOfBrackets));
}

TEST(Stack, BalancedBrackets2) {
    const char *queueOfBrackets = "([)]";
    ASSERT_FALSE(isBalanced(queueOfBrackets));
}
