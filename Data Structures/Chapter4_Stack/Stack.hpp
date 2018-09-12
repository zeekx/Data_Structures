//
//  Stack.hpp
//  Data Structures
//
//  Created by zeek on 2018/8/30.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <algorithm>
#include <vector>
template <typename T> class Stack: public std::vector<T> {
public: void push(T const &e) {
    this->push_back(e);
}
    
public: T pop() {
    auto e = this->back();
    this->pop_back();
    return e;
}
    
public: T& top() {
    return (*this)[this->size() - 1];
}
    
public: bool find(const T& e) {
    return std::find(std::begin(*this), std::end(*this), e) != std::end(*this);
    }

};
#endif /* Stack_hpp */
