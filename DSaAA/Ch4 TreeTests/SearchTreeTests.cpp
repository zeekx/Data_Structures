//
//  SearchTreeTests.cpp
//  Ch4 TreeTests
//
//  Created by Milo on 2019/4/10.
//  Copyright © 2019 Musca. All rights reserved.
//

#include <stdio.h>
#include <gtest/gtest.h>
#include "../Ch4 Tree/SearchTree.hpp"

TEST(Search, create) {
    SearchTree t = SearchTreeCreate(1);
    ASSERT_TRUE(t->element == 1);
    ASSERT_TRUE(t != NULL);
}

TEST(SerachTree, MakeEmpty) {
    SearchTree t = SearchTreeCreate(0);
    ASSERT_TRUE(MakeEmpty(t) == NULL);
}

const char* visitor(ElementType e) {
    static char buffer[128];
    if (e != 0) {
        size_t offset = strlen(buffer);
        sprintf(buffer + offset, "%d,", e);
    } else {
        if (strlen(buffer) > 0) {
            buffer[strlen(buffer)-1] = '\0';
        }
    }
    return buffer;
}

TEST(SerachTree, Insert) {
    SearchTree t = SearchTreeCreate(6);
    
    Insert(2, t);
    Insert(8, t);
    
    Insert(1, t);
    Insert(4, t);
    
    Insert(3, t);
    InTrav(t, visitor);
    
    ASSERT_TRUE(strcmp("1,2,3,4,6,8", visitor(0)) == 0);
}


TEST(SerachTree, Find) {
    SearchTree t = SearchTreeCreate(6);
    
    Insert(2, t);
    Insert(8, t);
    
    Insert(1, t);
    Insert(4, t);
    Insert(3, t);
    
    ASSERT_TRUE(Find(3, t) != NULL);
}

TEST(SerachTree, NotFound) {
    SearchTree t = SearchTreeCreate(6);
    
    Insert(2, t);
    Insert(8, t);
    
    Insert(1, t);
    Insert(4, t);
    
    ASSERT_TRUE(Find(3, t) == NULL);
}




