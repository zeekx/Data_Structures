//
//  main.cpp
//  Ch2
//
//  Created by Milo on 2019/5/16.
//  Copyright © 2019 Musca. All rights reserved.
//

#include <iostream>
#include <string>
#include "ExternInt.hpp"

using namespace std;

void snippets_init() {
    int a = 0;
    int b = {1};
    int c{2};
    int d(3);
    
    cout << a << b << c << d << endl;
}

void snippets_init_cast() {
    long double ld = 3.1415926536;
//    int a{ld}, b = {ld};
    int c(ld), d = ld;
    cout << "c:" << c << endl << "d:" << d << endl;
}

// 2.10
std::string global_string;
int global_int;
void varUnInit() {
    int local_int;
    std::string local_string;
    cout << "global_string" << global_string << "global_int" << global_int << endl;
    cout << "local_string" << local_string << "local_int" << local_int << endl;
}

//extern int extern_i = 4; // 不起作用
void sinppeter_extern() {
//    extern_i = 4;
    cout << "extern_i:" << extern_i << endl;
}

// 2.17

void ref_int() {
    int i, &ri = i;
    i = 5;
    ri = 10;
    cout << "i:" << i << " " << "ri:" << ri << endl;
    int &rri = ri;
    cout << "rri:" << rri << endl;
}


void sinppets_pptr() {
    int iVal = 1024;
    int *pi = &iVal;
    int **ppi = &pi;
    cout << "iVal:" << iVal << " *pi:" << *pi << " **ppi" << **ppi <<endl;
    cout << "&iVal" << &iVal << endl;
    cout << "&pi:" << &pi << " pi:" << pi << endl;
    cout << "&ppi:" << &ppi << " ppi:" << ppi << endl;
    cout << "*ppi" << *ppi << endl;
}

void sinppets_ref_ptr() {
    int i = 1;
    int *p;
    int *&r = p;
    
    r = &i;
    cout << "r:" << *r << endl;
    *r = 0;
    cout << "r:" << *r << " *p:" << *p << endl;
    
    int ii = 5;
    p = &ii;
    cout << "r:" << *r << " *p:" << *p << endl;
}

void sinppets_const_ref() {
    const int ci = 1024;
    const int &cr = ci;
//    cr = 41;
//    int &r = ci;
}

void sinppets_const_ref_init() {
    int i = 42;
    const int &r1 = i;
    const int &r2 = 43;
    const int &r3 = r1 * 2;
//    int &r4 = r1 * 2;
//    int &r5 = 2;
    
    cout << "i:" << i << " r1: " << r1 << " r2:" << r2 << " r3:" << r3 << endl;
}

// !!!
void sinppets_const_ref_init_cast() {
    double dValue = 3.14;
    int r(dValue);
    const int &ri = dValue;
//    int &ri(dValue);
    cout << "ri:" << ri << endl;
//    ri = 4;
//    cout << "after ri = 4, ri:" << ri << endl;
}

void sinppets_const_ptr() {
    const double pi = 3.14;
//    double &r = pi;
//    double *ptr = pi;
    const double *ptr = &pi;
//    *ptr = 3;
    cout << "*ptr:" << *ptr << endl;
    double p = 4;
    ptr = &p;
    cout << "*ptr:" << *ptr << endl;
}

void sinppets_const_ptr_const_var() {
    int err = 0;
    int *const cpErr = &err;
    const double pi = 3.14;
    const double * const ccp = &pi;
    
    int i = 3;
//    cpErr = &i;
    cout << "*cpErr:" << *cpErr << endl;
    *cpErr = 3;
    cout << "*cpErr:" << *cpErr << endl;
    
//    *ccp = 0;
    const double d = 2;
//    cpp = &d;
}

void sinppet_top_const_bottom_const() {
    int i = 0;
    int *const p1 = &i;
    const int ci = 42;
    const int *p2 = &ci;
    const int * const p3 = p2;
    const int &cr = ci;
    const int &r = i;
    
//    int *p = p3;
    p2 = p3;
    p2 = &i;
//    int &ri = ci;
    const int &r2 = i;
}

// 2.30
// 2.31
void topConst_bottomConst() {
    
    const int v2 = 0; int v1 = v2;
    int *p1 = &v1, &r1 = v1;
    
//    const int *p2 = &v2, * const *p3 = &i, &r2 = v2;
    const int *p2 = &v2, * const p3 = &v1, &r2 = v2;
    r1 = v2;
//    p1 = p2;
    p2 = p1;
//    p1 = p3;
    p2 = p3;
}

void sinppets_ref_and_ptr() {
    int i = 3;
    int *p = &i;
    int &r = *p;
    int *&rPtr = p;
}

int main(int argc, const char * argv[]) {
    sinppets_ref_and_ptr();
    return 0;
}
