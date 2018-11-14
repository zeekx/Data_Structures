//
//  StackApply.cpp
//  Data Structures Tests
//
//  Created by Milo on 2018/9/10.
//  Copyright © 2018年 Zeek. All rights reserved.
//

#include <gtest/gtest.h>
#include <array>
#include <vector>
#include "Stack.hpp"

using namespace std;

void convert(Stack<char>& stack, int n, int base) {
      std::array<char, 17> digit = {'0', '1', '2' ,'3' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9'
        ,'A' ,'B' ,'C' ,'D', 'E', 'F' };
    while (n > 0) {
        stack.push(digit[n % base]);
        n /= base;
    }
}

TEST(StackApplyTest, convert) {
    auto stack = new Stack<char>();
    convert(*stack, 89, 2);
    string result;
    while (!stack->empty()) {
        result += stack->pop();
    }
    ASSERT_EQ("1011001", result);
}

void trim(const char exp[], int& low, int& high) {
    while (low < high && exp[low] != '(' && exp[low] != ')') {
        low++;
    }
    
    while (low < high && exp[high] != '(' && exp[high] != ')') {
        high--;
    }
}

int divide(const char exp[], int low, int high) {
    int mid = low; int crc = 1;
    while (0 < crc && ++mid < high) {
        if (exp[mid] == '(') {
            crc--;
        } else if (exp[mid] == ')') {
            crc++;
        }
    }
    return mid;
}

bool paren_r(const char exp[], int low, int high) {
    trim(exp, low, high);
    if (low > high) {
        return  true;
    }
    if (exp[low] != '(' || exp[high] != ')') {
        return  false;
    }
    
    int mid = divide(exp, low, high);
    if (mid > high || ((exp[mid] == '(' || exp[mid] == ')') && low >= high)) {
        return  false;
    }
    
    return paren_r(exp, low + 1, mid - 1) && paren_r(exp, mid + 1, high);
}


bool paren_i(const char expression[], int low, int high) {
    Stack<char> s;
    for (int i = 0; i <= high; i++) {
        switch (expression[i]) {
            case '(':
            case '[':
            case '{':
                s.push(expression[i]);
                break;
                
            case ')':
                if (s.empty() || s.pop() != '(') {
                    return false;
                }
                break;
                
            case ']':
                if (s.empty() || s.pop() != '[') {
                    return false;
                }
                break;

            case '}':
                if (s.empty() || s.pop() != '{') {
                    return false;
                }
                break;

            default:
                break;
        }//switch
    }//for
    return s.empty();
}

bool paren(const char expression[], int low, int high) {
    return paren_r(expression, low, high);
}

TEST(DISABLED_Match, case1) {
    std::string a = "a / ( b [i-1][j+1] + c[i+1][j-1]) * 2";
    ASSERT_TRUE(paren(a.data(), 0, (int)a.length() - 1));
}


TEST(DISABLED_Match, case2) {
    std::string b = "(()";//a / ( b [i-1][j+1]) + c[i+1][j-1]) * 2";
    ASSERT_FALSE(paren(b.data(), 0, (int)b.length() - 1));
}


TEST(DISABLED_Match, case3) {
    std::string c = "a/(b+c)*2";
    ASSERT_TRUE(paren(c.data(), 0, (int)c.length() - 1));
}



template <typename T> class Point {
public:
    T x;
    T y;
    
public:
    Point() {
        
    }
    
    Point(T x, T y) {
        this->x = x;
        this->y = y;
    }
    
    
    Point& operator=(const Point& pnt) {
        this->x = pnt.x;
        this->y = pnt.y;
        return *this;
    }
};

class Queen {
public:
    Point<int> position;
    
    Queen(int x = 0, int y = 0) {
        this->position.x = x;
        this->position.y = y;
    }
    
    Queen(const Point<int>& position) {
        this->position = position;
    }
    
    bool operator==(const Queen& queen) {
        return position.x == queen.position.x
        || position.y == queen.position.y
        || (position.x + position.y == queen.position.x + queen.position.y)
        || (position.x - position.y == queen.position.x - queen.position.y) ;
    }
    
    bool operator!=(const Queen& queen) {
        return !(this->operator==(queen));
    }
    
};

const int gris_size = 18;


inline bool canPlaceQueenIn(const Queen *queen, Stack<Queen> queens) {
    for (Queen q : queens) {
        if (q == (*queen) ) {
            return false;
        }
    }
    return true;
}

//void dr(int row, int col, Stack<Queen>* queens, int size) {
//    if (row == 0) {
//        queens->clear();
//    }
//    for (int i = 0; i < size && row < size; i++) {
//        auto pnt = new Point<int>();
//        pnt->x = row;
//        pnt->y = i;
//        auto queen = new Queen();
//        queen->position = *pnt;
//        if (canPlaceQueenIn(queen, *queens)) {
//            queens->push(*queen);
//            dr(row + 1, 0, queens, size);
//        } else {
//
//        }
//    }
//}

void di(Stack<Queen>* queens, const int size) {
    int col = 0;
        for (int i = 0; i < size; i++) {
            for (int j = col; j < size; j++) {
                auto queen = Queen(Point<int>(i, j));
                if (canPlaceQueenIn(&queen, *queens)) {
                    queens->push(queen);
                    if (queens->size() == size) {
                        return;
                    } else {
                        break;
                    }
                }
            }//for
            
            if (i == queens->size() - 1) { //this line is OK.
                col = 0;
            } else {
               col = queens->pop().position.y + 1;
                i -= 2;// Backtracking
            }
        }//for
}

void di_(int row, int col, Stack<Queen>* queens, const int size) {
    Stack<Queen> solu;
    Queen q(0, 0);
    
    int nSolu = 0;
    do {
        int nCheck = 0;
        if (size <= solu.size() || size <= q.position.y) {
            q = solu.pop();
            q.position.y ++;
        } else {
            while (q.position.y < size && solu.find(q) ) {
                q.position.y++;
                nCheck++;
            }
            
            if (size > q.position.y) {
                solu.push(q);
                if (size <= solu.size()) {
                    nSolu ++;
                }
                q.position.x++;
                q.position.y = 0;
            }
        }
    } while (0 < q.position.x || q.position.y < size);
    
    while (!solu.empty()) {
        auto pnt = solu.pop().position;
        std::cout << pnt.x << ", " << pnt.y << std::endl;
    }
}

TEST(Grid, place) {
    auto queens = Stack<Queen>();
    di(&queens, gris_size);
    for (int i = 0; i < queens.size(); i++) {
        auto pnt = queens[i].position;
        std::cout << pnt.x << ", " << pnt.y << std::endl;
    }
    
    for (int i = 0; i < queens.size(); i++) {
        for (int j = 0; j < queens.size(); j++) {
            if (i != j) {
                ASSERT_TRUE( queens[i] != queens[j]);
            }
        }
    }
}

namespace {

    class QueenTest: public ::testing::Test {
    };
    
    TEST_F(QueenTest, equal__0_0__1_1) {
        auto point1 = new Point<int>();
        point1->x = 0;
        point1->y = 0;
        auto queen1 = new Queen();
        queen1->position = *point1;
        
        Point<int> point2;
        point2.x = 1;
        point2.y = 1;
        
        auto queen2 = new Queen();
        queen2->position = point2;
        
        ASSERT_TRUE(queen1->operator==(*queen2));
    }
    
    TEST_F(QueenTest, equal__0_0__3_3) {
        auto point1 = new Point<int>();
        point1->x = 0;
        point1->y = 0;
        auto queen1 = new Queen();
        queen1->position = *point1;
        
        Point<int> point2;
        point2.x = 3;
        point2.y = 3;
        
        auto queen2 = new Queen();
        queen2->position = point2;
        
        ASSERT_TRUE(queen1->operator==(*queen2));
    }
    
    TEST_F(QueenTest, equal__1_0__2_1) {
        auto point1 = new Point<int>();
        point1->x = 1;
        point1->y = 0;
        auto queen1 = new Queen();
        queen1->position = *point1;
        
        Point<int> point2;
        point2.x = 2;
        point2.y = 1;
        
        auto queen2 = new Queen();
        queen2->position = point2;
        
        ASSERT_TRUE(queen1->operator==(*queen2));
    }
    
    TEST_F(QueenTest, equal__1_0__3_2) {
        auto point1 = new Point<int>();
        point1->x = 1;
        point1->y = 0;
        auto queen1 = new Queen();
        queen1->position = *point1;
        
        Point<int> point2;
        point2.x = 3;
        point2.y = 2;
        
        auto queen2 = new Queen();
        queen2->position = point2;
        
        ASSERT_TRUE(queen1->operator==(*queen2));
    }
    
    TEST_F(QueenTest, equal__3_1__2_2) {
        auto point1 = new Point<int>();
        point1->x = 3;
        point1->y = 1;
        auto queen1 = new Queen();
        queen1->position = *point1;
        
        Point<int> point2;
        point2.x = 2;
        point2.y = 2;
        
        auto queen2 = new Queen();
        queen2->position = point2;
        
        ASSERT_TRUE(queen1->operator==(*queen2));
    }
    
    TEST_F(QueenTest, equal__0_0__0_0) {
        auto point1 = new Point<int>();
        point1->x = 0;
        point1->y = 0;
        auto queen1 = new Queen();
        queen1->position = *point1;
        
        Point<int> point2;
        point2.x = 0;
        point2.y = 0;
        
        auto queen2 = new Queen();
        queen2->position = point2;
        
        ASSERT_TRUE(queen1->operator==(*queen2));
    }
}




