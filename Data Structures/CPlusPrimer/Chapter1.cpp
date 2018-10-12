//
//  Chapter1.cpp
//  Data Structures
//
//  Created by Milo on 2018/9/17.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#include "Chapter1.hpp"
#include "Sales_item.h"
int dosomething() {
    Sales_item total;
    if (std::cin >> total) {
        Sales_item trans;
        while (std::cin >> trans) {
            if (total.isbn() == trans.isbn()) {
                total += trans;
            } else {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    } else {
        std::cerr << "NO data?" << std::endl;
        return -1;
    }
    return 0;
}
