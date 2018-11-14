//
//  main.cpp
//  LintCode
//
//  Created by Milo on 2018/10/30.
//  Copyright © 2018 Zeek. All rights reserved.
//

#include <iostream>

long long trailingZeros(long long n) {
    // write your code here, try to do it without arithmetic operators.
    long long c = 0;
    while (n > 4) {
        c += (n / 5);
        n /= 5;
    }
    
    return c;
}

int main(int argc, const char * argv[]) {
    assert(trailingZeros(11) == 2);
    assert(trailingZeros(29) == 6);
    assert(trailingZeros(100) == 24);
    
    assert(trailingZeros(1001171717) == 250292920);
    
    return 0;
}
