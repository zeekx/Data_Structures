//
//  main.cpp
//  Data Structures Tests
//
//  Created by Milo on 2018/7/5.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#include <iostream>
#include <gtest/gtest.h>

#include "ListNode.hpp"
#include "List.hpp"

int main(int argc, const char * argv[]) {
    ::testing::InitGoogleTest(&argc, (char **)&argv);
    return RUN_ALL_TESTS();
}


namespace {
    class ListTests: public ::testing::Test {
        
    };
}

TEST_F(ListTests, insert) {
    List<int> *list = new List<int>();
    list->insertAsLast(10);
    EXPECT_EQ(list->size(), 1);
}


TEST_F(ListTests, remove) {
    List<int> *list = new List<int>();
    list->insertAsLast(10);
    list->insertAfter(list->first(), 11);
    list->remove(list->last());
    EXPECT_EQ(list->size(), 1);

    list->remove(list->last());
    EXPECT_EQ(list->size(), 0);
}
