//
//  InsertSortTests.cpp
//  Ch7 SortTests
//
//  Created by Milo on 2019/4/8.
//  Copyright © 2019 Musca. All rights reserved.
//

#include <gtest/gtest.h>
#include "../Ch7 Sort/InsertionSort.hpp"
#include "../Ch7 Sort/Sort.hpp"

TEST(Sort, InsertionSort) {
    ElementType array[] = {34, 8, 64, 51, 32, 21};
//    ElementType array[] = {34, 64, 51, 32, 21, 8};
    ElementType sortArray[] = {8,21,32,34,51,64};
    insertionSort(array, sizeof(array) / sizeof(ElementType));
    ASSERT_TRUE( compareArray(sortArray, sizeof(sortArray)/sizeof(ElementType),
                              array, sizeof(array)/sizeof(ElementType)));
}


TEST(Sort, InsertionSort1Elements) {
    ElementType array[] = {34};
    ElementType sortArray[] = {34};
    insertionSort(array, sizeof(array) / sizeof(ElementType));
    ASSERT_TRUE( compareArray(sortArray, sizeof(sortArray)/sizeof(ElementType),
                              array, sizeof(array)/sizeof(ElementType)));
}

TEST(Sort, InsertionSort2Elements) {
    ElementType array[] = {34,8};
    ElementType sortArray[] = {8,34};
    insertionSort(array, sizeof(array) / sizeof(ElementType));
    ASSERT_TRUE( compareArray(sortArray, sizeof(sortArray)/sizeof(ElementType),
                              array, sizeof(array)/sizeof(ElementType)));
}
