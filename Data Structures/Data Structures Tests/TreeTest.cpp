//
//  TreeTest.cpp
//  Data Structures Tests
//
//  Created by Milo on 2018/9/10.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"


#include <gtest/gtest.h>
#include "BinaryTree.hpp"
#include <string>

namespace {
    template <typename T>
    class MockVisitor: public Visitor<T> {
    public:
        std::string out;
        void operator() (T const& t) {
            out += t;
        }
    };
    
    class BinTreeTest: public ::testing::Test {
    protected:

        void SetUp() override {
            
            auto root = charTree.insertAsRoot('i');
            auto d = charTree.insertAsLC(root, 'd');
            auto l = charTree.insertAsRC(root, 'l');
            auto c = d->insertAsLC('c');
            auto h = d->insertAsRC('h');
            
            auto a = c->insertAsLC('a');
            auto b = a->insertAsRC('b');
            
            auto f = h->insertAsLC('f');
            auto e = f->insertAsLC('e');
            auto g = f->insertAsRC('g');
            
            auto k = l->insertAsLC('k');
            auto n = l->insertAsRC('n');
            
            auto j = k->insertAsLC('j');
            
            auto m = n->insertAsLC('m');
            auto p = n->insertAsRC('p');
            auto o = p->insertAsLC('o');
        }

        void TearDown() override {
            
        }
        
        BinaryTree<int> tree;
        
        BinaryTree<char> charTree;
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
    
    TEST_F(BinTreeTest, travePrev_R) {
        MockVisitor<char> visitor;
        travPre_R(charTree.root(), visitor);
        ASSERT_EQ(visitor.out, "idcabhfeglkjnmpo");
    }
    
    TEST_F(BinTreeTest, traveIn) {
        MockVisitor<char> visitor;
        travIn_R(charTree.root(), visitor);
        ASSERT_EQ(visitor.out, "abcdefghijklmnop");
    }
    
    TEST_F(BinTreeTest, travePost_R) {
        MockVisitor<char> visitor;
        travPost_R(charTree.root(), visitor);
        ASSERT_EQ(visitor.out, "bacegfhdjkmopnli");
    }
    
    TEST_F(BinTreeTest, traveLevel) {
        MockVisitor<char> visitor;
        charTree.travLevel(visitor);
        ASSERT_EQ(visitor.out, "idlchknafjmpbego");
    }
    
    TEST_F(BinTreeTest, travePrev_I) {
        MockVisitor<char> visitor;
        travPre_I(charTree.root(), visitor);
        ASSERT_EQ(visitor.out, "idcabhfeglkjnmpo");
    }

    TEST_F(BinTreeTest, traveIn_I) {
        MockVisitor<char> visitor;
        travIn_I(charTree.root(), visitor);
        ASSERT_EQ(visitor.out, "abcdefghijklmnop");
    }
    
//    TEST_F(BinTreeTest, travePost_I) {
//        MockVisitor<char> visitor;
//        travePost_I(charTree.root(), visitor);
//        ASSERT_EQ(visitor.out, "bacegfhdjkmopnli");
//    }

    TEST_F(BinTreeTest, expression) {
        std::string exp("ab+cde+*+"); //a+b+c*(d+e)
        std::string operators = "+*";

        Stack<BinTree<char> *> stack;
        for (auto ch : exp) {
            if (operators.find(ch) != std::string::npos) {
                auto tree = new BinTree<char>();
                tree->insertAsRoot(ch);
                
                tree->attachAsRC(tree->root(), stack.pop());
                tree->attachAsLC(tree->root(), stack.pop());
                stack.push(tree);
            } else if (std::isalpha(ch)) {
                auto subtree = new BinTree<char>();
                subtree->insertAsRoot(ch);
                stack.push(subtree);
            }
        }
        
        MockVisitor<char> visitor;
        if (!stack.empty()) {
            travePost(stack.pop()->root(), visitor);
        }
        
        ASSERT_EQ(exp, visitor.out);
    }
}
#pragma clang diagnostic pop
