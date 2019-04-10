//
//  SearchTree.hpp
//  Ch4 Tree
//
//  Created by zeek on 2019/4/6.
//  Copyright © 2019 Musca. All rights reserved.
//

#ifndef SearchTree_hpp
#define SearchTree_hpp

#include <stdio.h>

typedef int ElementType;
typedef const char*(*_const_char_ptr_int_func_ptr)(ElementType);


struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

struct TreeNode {
    ElementType element;
    SearchTree left;
    SearchTree right;
};

SearchTree SearchTreeCreate(ElementType rootValue);
SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType x, SearchTree T);
Position FindMin(ElementType x, SearchTree T);
Position FindMax(ElementType x, SearchTree T);
SearchTree Insert(ElementType x, SearchTree T);
SearchTree Delete(ElementType x, SearchTree T);
ElementType Retrieve(Position p);


void InTrav(SearchTree T, _const_char_ptr_int_func_ptr func_ptr);
#endif /* SearchTree_hpp */
