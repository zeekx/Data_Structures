//
//  TreeTests.cpp
//  Ch4 TreeTests
//
//  Created by zeek on 2019/4/6.
//  Copyright © 2019 Musca. All rights reserved.
//

#include <stdio.h>
#include <gtest/gtest.h>
#include "../Ch4 Tree/Tree.hpp"

TEST(Tree, create) {
    Tree tree = TreeCreate(65);
    ASSERT_FALSE(tree == NULL);
}
