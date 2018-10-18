//
//  main.cpp
//  Chapter5_Tree
//
//  Created by Milo on 2018/9/3.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#include <iostream>
#include "Tree.hpp"
#include "BinNode.hpp"
#include "Visitor.hpp"


using namespace std;
int main(int argc, const char * argv[]) {
    BinTree<int> tree;
    tree.insertAsRoot(10);
    tree.insertAsLC(tree.root(), 11);
    tree.insertAsRC(tree.root(), 12);
    Visitor<int> visitor;
    travPre_R(tree.root(), visitor);
    return 0;
}
