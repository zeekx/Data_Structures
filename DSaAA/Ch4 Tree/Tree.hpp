//
//  Tree.hpp
//  Ch4 Tree
//
//  Created by zeek on 2019/4/6.
//  Copyright © 2019 Musca. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>

typedef char ElementType;
typedef struct TreeNode *PtrToNode;

struct TreeNode;
typedef PtrToNode Tree;

Tree TreeCreate(ElementType);
void TreeInsertChild(PtrToNode parentNode, PtrToNode childNode);
PtrToNode TreeLastSibling(PtrToNode node);
void TreeInsertSibling(PtrToNode brotherNode, PtrToNode siblingNode);
void TreePost(Tree tree);
#endif /* Tree_hpp */
