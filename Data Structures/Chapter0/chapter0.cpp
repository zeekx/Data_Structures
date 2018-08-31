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

//------------------
void swap(int *a, int *b) {
    int p = *b;
    *b = *a;
    *a = p;
}
void _reverse_R(std::array<int, 5> *pArray, int low, int high) {
    if (low < high) {
        swap(&(*pArray)[low], &(*pArray)[high]);
        _reverse_R(pArray, low + 1, high - 1);
    }
}

void _reverse_I(std::array<int, 5> *pArray, int low, int high) {
    while (low < high) {
        swap(&(*pArray)[low++], &(*pArray)[high--]);
    }
}
void reverse(std::array<int, 5> *pArray, int low, int high) {
    return _reverse_R(pArray, low, high);
}

