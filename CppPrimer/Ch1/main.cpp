//
//  main.cpp
//  Ch1
//
//  Created by Milo on 2019/5/15.
//  Copyright © 2019 Musca. All rights reserved.
//

#include <iostream>
#include "Sales_item.h"

using namespace std;

// 1.4.4
void occurs() {
    int currVal = 0, val = 0;
    if (cin >> currVal) {
        int cnt = 1;
        while (cin >> val) {
            if (val == currVal) {
                ++cnt;
            } else {
                cout << currVal << " occurs " << cnt << " times " << endl;
                currVal = val;
                cnt = 1;
            }
        }
        cout << currVal << " occurs " << cnt << " times " << endl;
    }
}

// 1.21
void readTwoSales_item() {
    Sales_item book1, book2;
    std::cin >> book1 >> book2;
    auto book = book1 + book2;
    std::cout << book << std::endl;
}



//1.22
void readAllSales_item() {
    Sales_item book;
    Sales_item sum;
    while (cin >> book) {
        sum += book;
    }
    cout << "sum:" << sum << endl;
}


// 1.23
// 1.24
void Sales_item_occurs() {
    Sales_item currentBook, newBook;
    if (cin >> currentBook) {
        int cnt = 1;
        while (cin >> newBook) {
            if (newBook.isbn() == currentBook.isbn()) {
                cnt ++;
            } else {
                cout << currentBook.isbn() << " sales " << cnt << " times" << endl;
                currentBook = newBook;
                cnt = 1;
            }
        }
        cout << currentBook.isbn() << " sales " << cnt << " times" << endl;
    }
}
int main(int argc, const char * argv[]) {
    
    Sales_item_occurs();
    return 0;
}
