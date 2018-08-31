//
//  main.cpp
//  Data Structures
//
//  Created by yubinqiang on 16/10/31.
//  Copyright © 2016年 Zeek. All rights reserved.
//

#include <iostream>
#include <array>


int main(int argc, const char * argv[]) {
    std::array<int, 5> A = {1,2,3,4,5};
    reverse(&A, 0, A.size() - 1);
    for (int i = 0; i < A.size(); i++) {
        std::cout<< A[i] << "\n";
    }
    return 0;
}
