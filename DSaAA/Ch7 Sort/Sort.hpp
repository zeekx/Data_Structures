//
//  Sort.hpp
//  DSaAA
//
//  Created by Milo on 2019/4/9.
//  Copyright © 2019 Musca. All rights reserved.
//

#ifndef Sort_hpp
#define Sort_hpp

#include <stdio.h>
#include <stdbool.h>

typedef int ElementType;
const char* printArray(ElementType array[]);
bool compareArray(const ElementType left[], int countOfLeft,
                  const ElementType right[], int countOfRight);

#endif /* Sort_hpp */
