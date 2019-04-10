//
//  ShellSort.c
//  DSaAA
//
//  Created by Milo on 2019/4/9.
//  Copyright © 2019 Musca. All rights reserved.
//

#include "ShellSort.hpp"
#include "Sort.hpp"
#include <math.h>

void ShellSort(ElementType array[], const int n) {
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }
    
    while (h >= 1) {
        for (int i = h; i < n; i ++) {
            for (int j = i; j > h && array[j-h] > array[j]; j -= h) {
                ElementType t = array[j];
                array[j] = array[j-h];
                array[j-h] = t;
            }
            
        }
        printArray(array);
        h = h / 3;
    }

}
