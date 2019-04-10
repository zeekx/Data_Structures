//
//  Sort.cpp
//  DSaAA
//
//  Created by Milo on 2019/4/9.
//  Copyright © 2019 Musca. All rights reserved.
//

#include "Sort.hpp"

const char* printArray(ElementType array[]) {
    const int count = 6;//sizeof()/sizeof(ElementType);
    ElementType string[count];
    for (int i = 0; i < count; i+=1) {
        string[i] = array[i];
        printf("%i,", array[i]);
    }
    printf("\n");
    return "";
}

bool compareArray(const ElementType left[], int countOfLeft,
                  const ElementType right[], int countOfRight) {
    if (countOfLeft != countOfRight) {
        return false;
    }
    
    for (int i = 0; i < countOfLeft; i++) {
        if (left[i] != right[i]) {
            return false;
        }
    }
    return true;
}
