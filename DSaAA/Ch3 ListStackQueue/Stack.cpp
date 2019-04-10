//
//  Stack.c
//  Ch3 ListStackQueue
//
//  Created by zeek on 2019/4/5.
//  Copyright © 2019 Musca. All rights reserved.
//

#include "Stack.hpp"
#include "../DSaAA/ErrorHandle.h"


#include <stdlib.h>
#include <memory.h>

struct Node {
    ElementType element;
    PtrToNode   next;
};

bool IsEmtpy(Stack s) {
    return s->next == NULL;
}

Stack CreateStack(void) {
    Stack s = (PtrToNode)malloc(sizeof(struct Node));
    memset(s, 0, sizeof(struct Node));
    if (s == NULL) {
        return NULL;
    }
    return s;
}

void DisposeStack(Stack *s) {
    PtrToNode p = (*s)->next;
    while (p != NULL) {
        PtrToNode next = p->next;
        free(p);
        p = next;
    }
    free(*s);
    *s = NULL;
}

void MakeEmptyStack(Stack s) {
    if (s == NULL) {
        Error("Must use CreateStack first");
    } else {
        while (!IsEmtpy(s)) {
            Pop(s);
        }
    }
}

void Push(ElementType e, Stack s) {
    PtrToNode newTop = (PtrToNode)malloc(sizeof(Node));
    if (newTop == NULL) {
        Error("Out of Space!!!");
    } else {
        newTop->element = e;
        newTop->next = s->next;
        s->next = newTop;
    }
}

ElementType Top(Stack s) {
    return s->next->element;
}

ElementType Pop(Stack s) {
    PtrToNode top = s->next;
    if (!IsEmtpy(s)) {
        s->next = top->next;
        ElementType e = top->element;
        free(top);
        top = NULL;
        return e;
    } else {
        Error("Empty Stack");
    }
    return 0;
}

