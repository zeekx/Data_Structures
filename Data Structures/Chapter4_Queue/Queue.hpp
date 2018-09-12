//
//  Queue.hpp
//  Data Structures
//
//  Created by Milo on 2018/9/12.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include "List.hpp"

template <typename T>
class Queue: public List<T> {
public:
    void enqueue(T const& e) {
        this->insertAsLast(e);
    }
    
    T dequeue() {
        return this->remove(this->first());
    }
    
    T& front() {
        return this->first()->data;
    }
};

#endif /* Queue_hpp */
