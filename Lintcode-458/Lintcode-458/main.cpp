//
//  main.cpp
//  Lintcode-458
//
//  Created by JINGLUO on 22/11/18.
//  Copyright © 2018 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

// Solution 1
/*
int binarySearch(std::vector<int> &nums, int target, int s, int e) {
    int result = -1;
    if (e >= s) {
        int mid = (e - s) / 2 + s;
        if (nums[mid] > target) {
            return binarySearch(nums, target, s, mid-1);
        }
        if (nums[mid] == target) {
            result = mid;
        }
        int rightResult = binarySearch(nums, target, mid+1, e);
        if (rightResult > result) {
            return rightResult;
        }
        return result;
    }
    return -1;
}

int lastPosition(std::vector<int> &nums, int target) {
    return int(binarySearch(nums, target, 0, int(nums.size()) - 1));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(5);
    int result = lastPosition(nums, 5);
    std::cout << result << "\n";
    return 0;
}
 */


// Solution 2
int helper(std::vector<int> &nums, int start, int end, int target) {
    int result = -1;
    if (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] <= target) {  // 因为是要找最后一个，所以 <= 的情况下，都要找右边的
            start = mid;
        } else {
            end = mid;
        }
        return helper(nums, start, end, target);
    }
    
    if (nums[end] == target) { // 注意 先返回end的，因为是找最后一个
        return end;
    }
    if (nums[start] == target) {
        return start;
    }
    
    return result;
}

int lastPosition(std::vector<int> &nums, int target) {
    if (nums.size() == 0) {  // 注意edge case
        return -1;
    }
    return helper(nums, 0, int(nums.size())-1, target);
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {1,2,2,4,5,5};
    std::cout << lastPosition(nums, 5) << "\n";
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

