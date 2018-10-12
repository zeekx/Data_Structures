//
//  QueueApply.cpp
//  Data Structures Tests
//
//  Created by Milo on 2018/9/13.
//  Copyright © 2018年 Zeek. All rights reserved.
//


#include "Queue.hpp"
#include <gtest/gtest.h>

struct Customer {
public:
    int window;
    unsigned int time;
    Customer(): window(0), time(0) {
        
    }
    
    Customer(int window, unsigned int time) {
        this->window = window;
        this->time = time;
    }

};


unsigned int bestWindow( Queue<Customer> windows[], int numberOfWindows) {
    int minSize = windows[0].size(), bestWindowIndex = 0;
    for (int i = 1; i < numberOfWindows; i++) {
        if (windows[i].size() < minSize) {
            minSize = windows[i].size();
            bestWindowIndex = i;
        }
    }
    return bestWindowIndex;
}

void simulate(int numberOfWindows, int serverTime) {
    auto windows = new  Queue<Customer>[numberOfWindows];
    for (int now = 0; now < serverTime; now++) {
        if (rand() % (numberOfWindows + 1)) {
            auto c = Customer(1 + rand() % 98, bestWindow(windows, numberOfWindows));
            windows[c.window].enqueue(c);
        }
        
        for (int i = 0; i < numberOfWindows; i++) {
            if (!windows[i].empty()) {
                auto time = --windows[i].front().time;
                if (time <= 0) {    //All work done.
                    windows[i].dequeue();
                }
            }
        }//for
    }//for
    delete []windows;
}



TEST(Window, Best) {
    auto windows = new Queue<Customer>[2];
    windows[0].enqueue(Customer(0, 1));
    windows[0].enqueue(Customer(0, 2));
    windows[0].enqueue(Customer(0, 3));
    windows[0].enqueue(Customer(0, 4));
    
    windows[1].enqueue(Customer(1, 11));
    windows[1].enqueue(Customer(1, 12));
    ASSERT_TRUE(bestWindow(windows, 2) == 1);
}
