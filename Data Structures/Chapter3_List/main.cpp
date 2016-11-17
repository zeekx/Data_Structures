//
//  main.cpp
//  Chapter3_List
//
//  Created by yubinqiang on 16/10/31.
//  Copyright © 2016年 Zeek. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include "List.hpp"

int main(int argc, const char * argv[]) {
    List<int> *list = new List<int>();
    list->insertAsLast(10);
    list->insertAsLast(11);
    list->insertAsLast(9);
    list->insertAsFirst(1);
    list->insertAfter(list->first(), 2);
    for (ListNode<int> *node = list->first(); node->succ != nullptr; node = node->succ) {
        std::cout << node->data << std::endl;
    }

    return 0;
}
