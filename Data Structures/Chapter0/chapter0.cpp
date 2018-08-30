//
//  chapter0.cpp
//  Chapter0
//
//  Created by Milo on 2018/8/30.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#include "chapter0.hpp"


int _sum(std::array<int, 2> array, int count) {
    if (count < 1) {
        return 0;
    } else {
        return _sum(array, count - 1) + array[count - 1];
    }
}


int sum(std::array<int, 2> array ) {
    return _sum(array, array.size());
}
