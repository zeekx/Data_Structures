//
//  Tree.cpp
//  Ch4 Tree
//
//  Created by zeek on 2019/4/6.
//  Copyright © 2019 Musca. All rights reserved.
//

#include "Tree.hpp"
#include <stdlib.h>
#include "../DSaAA/ErrorHandle.h"

struct TreeNode {
    ElementType element;
    PtrToNode firstChild;
    PtrToNode nextSibling;
};

Tree TreeCreate(ElementType rootValue) {
    Tree t = (PtrToNode)malloc(sizeof(TreeNode));
    PtrToNode root = (PtrToNode)malloc(sizeof(TreeNode));
    root->element = rootValue;
    t->firstChild = root;
    if (t == NULL || root == NULL) {
        FatalError("Out of space!!!");
    }
    return t;
}

PtrToNode TreeLastSibling(PtrToNode node) {
    PtrToNode last = node;
    while (last->nextSibling != NULL) {
        last = last->nextSibling;
    }
    return last;
}

void TreeInsertChild(PtrToNode parentNode, PtrToNode childNode) {
    
}

void TreeInsertSibling(PtrToNode brotherNode, PtrToNode siblingNode) {
    
}

void TreePost(Tree tree) {
    
}
