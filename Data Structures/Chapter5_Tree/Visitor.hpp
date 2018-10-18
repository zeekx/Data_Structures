//
//  Visitor.hpp
//  Data Structures
//
//  Created by Milo on 2018/10/18.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#ifndef Visitor_hpp
#define Visitor_hpp

#include <iostream>
template <typename T> class Visitor {
public:
    void operator() (T const& t) {
        std::cout << t << " " ;
    }
};

#endif /* Visitor_hpp */
