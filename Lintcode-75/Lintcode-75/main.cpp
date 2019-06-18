//
//  main.cpp
//  Lintcode-75
//
//  Created by JINGLUO on 18/6/19.
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

int findPeak(std::vector<int> &A) {
    int count = int(A.size());
    if (count == 0 || count == 1) {
        return 0;
    }
    return helper(A, 0, count - 1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> nums = {1,2,3,8,1};
    //{1, 2, 3, 4};
    //{10, 9, 8, 7};
    //{1, 2, 4, 8, 9, 3};
    std::cout << findPeak(nums) << "\n";
    return 0;
}




/*
 ###算法
 二分法，找到mid，通过和mid-1，mid+1比较，判断出mid这个数处于上升、下降或者peak（结果，return peak）。题目说可能有多处peak，但是不影响这个算法，只要遇到peak，直接返回就行
 
 ###代码实现
 ***有什么要注意的地方
 参考代码注释
 ***有什么要优化的地方
 BCR is O(longN), time complexity已经是最优解， same as space complexity
 
 ###时空复杂度
 time O(longN)
 space O(1)
 
 ###相关的题目有哪些
 Lintcode 585. Find peak element-----这两题代码几乎一摸一样，只是一个返回index，一个返回nums[index]
 */

