//
//  Visit.hpp
//  Data Structures
//
//  Created by Milo on 2018/10/12.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#ifndef Visit_hpp
#define Visit_hpp

#include <iostream>

template <typename T>
class Visit {
    
    
public:
    void visit(const T& e) {
        std::cout << e;
    }
};
#endif /* Visit_hpp */
