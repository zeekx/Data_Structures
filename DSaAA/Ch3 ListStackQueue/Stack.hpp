//
//  Stack.h
//  Ch3 ListStackQueue
//
//  Created by zeek on 2019/4/5.
//  Copyright © 2019 Musca. All rights reserved.
//

#ifndef Stack_h
#define Stack_h
        
#include <stdio.h>
#include <stdbool.h>

typedef char ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;


bool IsEmtpy(Stack s);
Stack CreateStack(void);
void DisposeStack(Stack *s);
void MakeEmptyStack(Stack s);
void Push(ElementType e, Stack s);
ElementType Top(Stack s);
ElementType Pop(Stack s);
#endif /* Stack_h */
