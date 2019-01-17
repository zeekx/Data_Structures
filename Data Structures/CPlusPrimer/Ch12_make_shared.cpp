//
//  Ch12_make_shared.cpp
//  Data Structures
//
//  Created by Milo on 2019/1/17.
//  Copyright © 2019 Zeek. All rights reserved.
//

#include "Ch12_make_shared.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <stdio.h>

using namespace std;
void Ch12_make_shared_hpp_dosomething() {
    shared_ptr<int> p3 = make_shared<int>(34);
    cout << "p3 = " << *p3 << endl;
    shared_ptr<std::string> p4 = make_shared<string>(10, '9');
    cout << "p4 = " << *p4 << endl;
    
    shared_ptr<int> pInt = make_shared<int>();
    cout << "pInt = " << *pInt << endl;
    
    shared_ptr<bool> pBool = make_shared<bool>();
    cout << "pBool = " << *pBool << endl;
    
    shared_ptr<bool> pBoolAnother(pBool);
    cout << "pBoolAnother = " << *pBoolAnother << endl;
    *pBoolAnother = true;
    cout << "pBoolAnother = " << *pBoolAnother << endl;
    cout << "pBool = " << *pBool << endl;
    cout << "pBool" << "userCount = " << pBool.use_count() << endl;
    shared_ptr<bool> pBoolRetain = pBool;
    cout << "pBool" << "userCount = " << pBool.use_count() << endl;
}
