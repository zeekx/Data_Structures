//
//  main.cpp
//  Chapter4_Stack
//
//  Created by zeek on 2018/8/30.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#include <iostream>
#include "Stack.hpp"
#include <assert.h>
int main(int argc, const char * argv[]) {
//    std::cout << stack->top() << std::endl;
    int v1 = 0,v2 = 0;
    while (std::cin >> v1) {
        v2 += v1;
    }
    std::cout << v2 << std::endl;
    return 0;
}
