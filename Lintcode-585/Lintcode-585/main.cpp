//
//  main.cpp
//  Lintcode-585
//
//  Created by JINGLUO on 14/6/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

// 升序：1
// 降序：2
// peak：3
int mountainLocationType(std::vector<int> &nums, int index) {
    int lastIndex = int(nums.size()) - 1;
    if (index == 0) {  // 第一个点 特殊判断
        if (index + 1 > lastIndex) {
            return 3;
        }
        if (nums[index] < nums[index + 1]) {
            return 1;
        } else {
            return 3;
        }
    }
    if (index == lastIndex) {  // 最后一个点 特殊判断
        if (index - 1 < 0) {
            return 3;
        }
        if (nums[index] > nums[index - 1]) {
            return 3;
        } else {
            return 2;
        }
    }
    if (nums[index] > nums[index - 1]) {
        if (nums[index] >= nums[index + 1]) {
            return 3;
        } else {
            return 1;
        }
    } else {
        return 2;
    }
}

int helper(std::vector<int> &nums, int start, int end) {
    int mid;
    if (start + 1 < end) {
        mid = start + (end - start) / 2;
        int type = mountainLocationType(nums, mid);
        if (type == 1) {
            start = mid;
        } else if (type == 2) {
            end = mid;
        } else {
            return mid;
        }
        return helper(nums, start, end);
    }
    if (mountainLocationType(nums, start) == 3) {
        return start;
    }
    if (mountainLocationType(nums, end) == 3) {
        return end;
    }
    return -1;
}

int mountainSequence(std::vector<int> &nums) {
    int count = int(nums.size());
    if (count == 0) {
        return 0;
    }
    int index = helper(nums, 0, count - 1);
    return nums[index];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> nums = {1,2,3,8,1};
    //{1, 2, 3, 4};
    //{10, 9, 8, 7};
    //{1, 2, 4, 8, 9, 3};
    std::cout << mountainSequence(nums) << "\n";
    return 0;
}



/*
 ###算法
 二分法，找到mid，判断这个数处于上升、下降或者peak（结果，return peak）
 
 ###代码实现
 ***有什么要注意的地方
 参考代码注释
 ***有什么要优化的地方
 BCR is O(longN), time complexity已经是最优解， same as space complexity
 这题能AC是没有{1,2,3,8,8,8,8,1}这种数据，如果有，那现在的代码没法AC，需要优化以包含解这种数据
 
 ###时空复杂度
 time O(longN)
 space O(1)
 
 ###相关的题目有哪些
 Lintcode 75. Find peak element
 */

