//
//  StackTests.c
//  Ch3 ListStackQueueTests
//
//  Created by zeek on 2019/4/5.
//  Copyright © 2019 Musca. All rights reserved.
//


#include <gtest/gtest.h>
#include "../Ch3 ListStackQueue/Stack.hpp"


TEST(Stack, Create) {
    Stack s = CreateStack();
    EXPECT_NE(s, nullptr);
}

TEST(Stack, Push) {
    Stack s = CreateStack();
    Push(96, s);
    EXPECT_FALSE(IsEmtpy(s));
}

TEST(Stack, Pop) {
    Stack s = CreateStack();
    ElementType e = 96;
    Push(e, s);
    
    EXPECT_FALSE(IsEmtpy(s));
}


TEST(Stack, Top) {
    Stack s = CreateStack();
    ElementType e = 96;
    Push(e, s);
    EXPECT_TRUE(e == Top(s));
}


TEST(Stack, MakeEmpty) {
    Stack s = CreateStack();
    Push(96, s);
    Push(96, s);
    MakeEmptyStack(s);
    EXPECT_TRUE(IsEmtpy(s));
}

TEST(Stack, Dispose) {
    Stack s = CreateStack();
    Push(96, s);
    DisposeStack(&s);
    EXPECT_TRUE(s == NULL);
}

