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
        if (nums.empty()) {
            return -1;
        }
        size_t low = 0, high = nums.size() - 1;
        while (low <= high) {
            size_t mid = ((high - low) >> 1) + low;
            if (nums[mid] >= target) {
                if (low == high) {
                    return (int)mid;
                }
                high = (nums[mid] == target) ? mid : mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            }
//            else {
//                high = mid - 1;
//            }
        }
        return -1;
    }
};

#endif /* BinarySearch14_hpp */
