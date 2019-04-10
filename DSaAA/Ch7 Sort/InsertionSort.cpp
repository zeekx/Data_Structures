//
//  InsertionSort.cpp
//  Ch7 Sort
//
//  Created by Milo on 2019/4/8.
//  Copyright © 2019 Musca. All rights reserved.
//


//#include <stdio.h>
#include "InsertionSort.hpp"
#include "Sort.hpp"

void insertionSort(ElementType array[], const int n) {
    int j;
    for (int i = 1; i < n; i++) {
        ElementType min = array[i];
        for(j = i; j > 0 && array[j-1] > min; j--) {
            array[j] = array[j-1];
        }
        array[j] = min;
        printArray(array);
    }
}
