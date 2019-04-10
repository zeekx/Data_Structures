//
//  main.c
//  Ch7 SortTests
//
//  Created by Milo on 2019/4/8.
//  Copyright © 2019 Musca. All rights reserved.
//

#include <gtest/gtest.h>

#include <math.h>
int main(int argc, const char * argv[]) {
    for (int i =0; i < 7; i++) {
        int h = 9 * pow(4, i) - 9 * pow(2, i) + 1;
        printf("%d,", h);
    }
    ::testing::InitGoogleTest(&argc, (char **)&argv);
    return RUN_ALL_TESTS();
}
