//
//  Chapter3.cpp
//  Data Structures
//
//  Created by Milo on 2019/1/8.
//  Copyright © 2019 Zeek. All rights reserved.
//

#include "Chapter3.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void UpperCaption() {
    std::string s("hello,world");
    if (s.begin() != s.end()) {
        (*s.begin()) = toupper(*s.begin());
        std::cout << s << std::endl;
    }
}

void UpperFirstWord() {
    std::string s("hello world");
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it) {
        *it = toupper(*it);
    }
    std::cout << s << std::endl;
}

void UpperFirstWordConstIterator() {
    std::string s("hello world");
    
    //    std::string::const_iterator b = s.begin();
    std::string::iterator b = s.begin();
    *b = toupper(*b);
    std::cout << s << std::endl;
}

void outputText() {
    vector<std::string> txt{"abc", "123", "", "ABC"};
    
    for (auto it = txt.begin(); it != txt.end() && !it->empty(); ++it) {
        cout << *it ;
    }
    cout << endl;
}
