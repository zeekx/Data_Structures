//
//  main.cpp
//  Complex
//
//  Created by Milo on 2019/5/14.
//  Copyright © 2019 Musca. All rights reserved.
//

#include <iostream>
#include "Complex.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Complex c(1, 1);
    cout << c << endl;
    
    const Complex cc;
    -cc;
    return 0;
}
