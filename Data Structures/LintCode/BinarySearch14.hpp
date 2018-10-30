//
//  int binarySearch(vector<int> &nums, int target) {         int low = 0, high = nums.hpp
//  Data Structures
//
//  Created by Milo on 2018/10/30.
//  Copyright © 2018 Zeek. All rights reserved.
//

#ifndef BinarySearch14_hpp
#define BinarySearch14_hpp

#include <vector>
using namespace std;
class BinarySearch14 {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &nums, int target) {
        int low = -1, high = (int)nums.size();
        while (low + 1 != high) {
            int mid = ((high - low) >> 1) + low;
            if (nums[mid] < target) {
                low = mid;
            } else {
                high = mid;
            }

        }
        int i = high;
        if (i >= nums.size() || nums[i] != target) {
            return -1;
        }
        return i;
    }
};

#endif /* BinarySearch14_hpp */
