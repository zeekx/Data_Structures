//
//  ListTests.cpp
//  Data Structures Tests
//
//  Created by Milo on 2018/8/30.
//  Copyright © 2018年 Zeek. All rights reserved.
//


#include "List.hpp"
#include "ListNode.hpp"
#include <gtest/gtest.h>

namespace {
    class DISABLED_ListTests: public ::testing::Test {
        
    };


    TEST_F(DISABLED_ListTests, insert) {
        List<int> *list = new List<int>();
        list->insertAsLast(10);
        EXPECT_EQ(list->size(), 1);
    }
    
    
    TEST_F(DISABLED_ListTests, remove) {
        List<int> *list = new List<int>();
        list->insertAsLast(10);
        list->insertAfter(list->first(), 11);
        list->remove(list->last());
        EXPECT_EQ(list->size(), 1);
        
        list->remove(list->last());
        EXPECT_EQ(list->size(), 0);
    }
}
