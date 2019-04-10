//
//  SearchTree.cpp
//  Ch4 Tree
//
//  Created by zeek on 2019/4/6.
//  Copyright © 2019 Musca. All rights reserved.
//

#include <string.h>

#include "SearchTree.hpp"
#include "../DSaAA/ErrorHandle.hpp"


SearchTree SearchTreeCreate(ElementType rootValue) {
    SearchTree root = (SearchTree)malloc(sizeof(TreeNode));
    if (root == NULL) {
        FatalError("Out of space!!!");
    }
    root->element = rootValue;
    root->left = NULL;
    root->right = NULL;

    return root;
}

SearchTree MakeEmpty(SearchTree T) {
    if (T->left != NULL) {
        MakeEmpty(T->left);
    }
    
    if (T->right != NULL) {
        MakeEmpty(T->right);
    }
    free(T);
    return NULL;
}

void InTrav(SearchTree T, _const_char_ptr_int_func_ptr func_ptr) {
    if (T->left != NULL) {
        InTrav(T->left, func_ptr);
    }
    
    func_ptr(T->element);
    
    if (T->right != NULL) {
        InTrav(T->right, func_ptr);
    }
}

Position Find(ElementType x, SearchTree T) {
    if (T->element > x) {
        if (T->left == NULL) {
            return NULL;
        } else {
            return Find(x, T->left);
        }
    } else if (T->element < x) {
        if (T->right == NULL) {
            return NULL;
        } else {
            return Find(x, T->right);
        }
    }
    
    return T;
}

Position FindMin(ElementType x, SearchTree T) {
    return NULL;
}

Position FindMax(ElementType x, SearchTree T) {
    return NULL;
}

SearchTree Insert(ElementType x, SearchTree T) {
    if (T == NULL) {
        Position e = (Position)malloc(sizeof(struct TreeNode));
        if (e == NULL) {
            FatalError("Out of space!");
        }
        e->left = NULL;
        e->right = NULL;
        e->element = x;
        T = e;
    }
    if (T->element > x) {
        T->left = Insert(x, T->left);
    } else if (T->element < x) {
        T->right = Insert(x, T->right);
    }
    return T;
}

SearchTree Delete(ElementType x, SearchTree T) {
    return NULL;
}

ElementType Retrieve(Position p) {
    return 0;
}
