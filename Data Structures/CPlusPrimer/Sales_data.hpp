//
//  Sales_data.hpp
//  Data Structures
//
//  Created by Milo on 2019/1/4.
//  Copyright © 2019 Zeek. All rights reserved.
//

#ifndef Sales_data_hpp
#define Sales_data_hpp

#include <stdio.h>
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;
};
#endif /* Sales_data_hpp */
