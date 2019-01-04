//
//  main.cpp
//  Chapter6_Graph
//
//  Created by Milo on 2018/10/18.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#include <iostream>
#include "Graph.hpp"
#include "GraphMatrix.hpp"

class A {
public:
    virtual void f() = 0;
    virtual void f2() = 0;
};

class B: public A {
public:
    virtual void f() {
        
    }
};



int main(int argc, const char * argv[]) {
    GraphMatrix<char, int> graph;
    graph.insert('a');
    graph.insert('b');
    std::cout << graph.description();
    return 0;
}
