//
//  main.cpp
//  Lintcode-159
//
//  Created by JINGLUO on 16/6/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

int helper(std::vector<int> &nums, int start, int end) {
    int mid;
    if (start + 1 < end) {
        mid = start + (end - start) / 2;
        if (nums[mid] > nums[start] && nums[mid] < nums[end]) {
            end = mid;
        } else if (nums[mid] > nums[start]) {
            start = mid;
        } else if (nums[mid] < nums[end]) {
            end = mid;
        }
        return helper(nums, start, end);
    }
    if (nums[start] < nums[end]) {
        return nums[start];
    }
    return nums[end];
}

int findMin(std::vector<int> &nums) {
    if (nums.size() == 0) {
        return -1;
    }
    return helper(nums, 0, int(nums.size()) - 1);
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {2};
    std::cout << findMin(nums) << "\n";
    return 0;
}



/*
 ###算法
 二分法，找到mid，根据最小值在的区间，不断朝最小值的区间缩小范围，直到最后2位数，start和end，答案就是nums[start]和nums[end]中的一个，只可能2种情况，要么{7,0}样式，要么{0,7}样式，取小的那个就行
 
 ###代码实现
 ***有什么要注意的地方
 参考代码注释
 ***有什么要优化的地方
 BCR is O(longN), time complexity已经是最优解， same as space complexity
 
 ###时空复杂度
 time O(longN)
 space O(1)
 
 ###相关的题目有哪些
 Lintcode 160. Find Minimum in Rotated Sorted Array II
 Lintcode 63. Search in Rotated Sorted Array II
 */

