//
//  main.cpp
//  Lintcode-14
//
//  Created by JINGLUO on 11/6/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

int helper(std::vector<int> &nums, int start, int end, int target) {
    int result = -1;
    if (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] >= target) {  // 因为是要找第一个，所以 >= 的情况下，都要找左边的
            end = mid;
        } else {
            start = mid;
        }
        return helper(nums, start, end, target);
    }
    
    if (nums[start] == target) {
        return start;
    }
    if (nums[end] == target) {
        return end;
    }

    return result;
}

int binarySearch(std::vector<int> &nums, int target) {
    if (nums.size() == 0) {  // 注意edge case
        return -1;
    }
    return helper(nums, 0, int(nums.size())-1, target);
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {1,2,2,2,2,4,4,5,7,7,8,9,9,10};
    std::cout << binarySearch(nums, 4) << "\n";
    return 0;
}


/*
 ###算法
 二分法，递归recursion
 
 ###代码实现
 ***有什么要注意的地方
 参照代码，已注释
 ***有什么要优化的地方
 
 ###时空复杂度
 time O(logN)
 space O(1)
 
 ###相关的题目有哪些
 
 */
