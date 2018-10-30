//
//  TwoSum56.h
//  LintCode
//
//  Created by Milo on 2018/10/30.
//  Copyright © 2018 Zeek. All rights reserved.
//

#ifndef TwoSum56_h
#define TwoSum56_h

#include <stdio.h>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class TwoSum56 {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        std::map<int, int> m;
        for (int i = 0; i < numbers.size(); i++) {
            if (m[numbers[i]] > 0) {
                return vector<int>{m[numbers[i]] - 1, i};
            }
            m[target - numbers[i]] = i + 1;
        }
        return vector<int>();
    }
};


#endif /* TwoSum56_h */
