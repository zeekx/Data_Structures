//
//  TreeTest.cpp
//  Data Structures Tests
//
//  Created by Milo on 2018/9/10.
//  Copyright © 2018年 Zeek. All rights reserved.
//


#include <gtest/gtest.h>
#include "Tree.hpp"
namespace {
class BinTreeTest: public ::testing::Test {
protected:
    void SetUp() override {
        
    }
    
    BinTree<int> tree;
};

TEST_F(BinTreeTest, Root) {
    auto data = 10;
    tree.insertAsRoot(data);
    ASSERT_EQ(tree.root()->data, data);
}

TEST_F(BinTreeTest, insertAsLC) {
    auto lcData = 11;
    tree.insertAsRoot(0);
    auto l1 = tree.insertAsLC(tree.root(), lcData);
    tree.insertAsRC(tree.root(), 12);
    ASSERT_EQ(lcData, l1->data);
}

TEST_F(BinTreeTest, insertAsRC) {
    auto rcData = 11;
    tree.insertAsRoot(0);
    tree.insertAsLC(tree.root(), 12);
    auto r1 = tree.insertAsRC(tree.root(), rcData);
    ASSERT_EQ(rcData, r1->data);
}

TEST_F(BinTreeTest, secede) {
    tree.insertAsRoot(1);
    auto l1 = tree.insertAsLC(tree.root(), 11);
    tree.insertAsRC(tree.root(), 12);
    tree.insertAsLC(l1, 21);
    tree.insertAsRC(l1, 22);
    
    auto subtree = tree.secede(l1);
    ASSERT_EQ(subtree->root()->data, 11);
    ASSERT_EQ(subtree->root()->lChild->data, 21);
    ASSERT_EQ(subtree->root()->rChild->data, 22);
}

}
