//
//  main.cpp
//  Lintcode-460
//
//  Created by JINGLUO on 12/6/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

std::pair<int, int> helper(std::vector<int> &A, int target, int start, int end) {
    std::pair<int, int> result = std::pair<int, int>();
    int mid;
    if (start + 1 < end) {
        mid = start + (end - start) / 2;
        if (A[mid] == target) {
            result.first = mid;
            result.second = mid;
            return result;
        }
        if (A[mid] > target) {
            end = mid;
        } else {
            start = mid;
        }
        return helper(A, target, start, end);
    }
    if (target == A[start]) {
        result.first = start;
        result.second = start;
    } else if (target == A[end]) {
        result.first = end;
        result.second = end;
    } else {
        result.first = start;
        result.second = end;
    }
    return result;
}

std::vector<int> kClosestNumbers(std::vector<int> &A, int target, int k) {
    // Edge cases
    std::vector<int> result = std::vector<int>(); // std::vector<int> result(k), 这里不能用这种规定k个大小的初始化方式，因为这样的话默认result已经有{0,0,0...0}k个0的初始值，当后面我们result.push_back()的时候，会导致结果double，即{0,0,0...0,2,1,3...}
    if (A.size() == 0) {
        return result;
    }
    if (A.size() < k) { // 注意题意，要跟面试官确定edge case的处理规则
        return A;
    }
    std::pair<int, int> range = helper(A, target, 0, int(A.size()) - 1); // 经典二分，找到target所在的range
    // range找到后，two pointer，向左右两边移动对比，每次取较小的值
    int left = range.first;
    int right = range.second;
    while (k --) {
        if (left == right) {
            result.push_back(A[left]);
            left --; // 这里不要忘记left和right都要移动
            right ++;
        } else {
            int leftValue = left < 0 ? INT_MAX : abs(A[left] - target); // 这里需要注意，为防止越界，要赋一个int最大值给left，下面right同理
            int rightValue = (right > int(A.size()) - 1) ? INT_MAX : abs(A[right] - target);
            if (leftValue <= rightValue) {
                result.push_back(A[left]);
                left --;
            } else {
                result.push_back(A[right]);
                right ++;
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    std::vector<int> A = {1, 2, 3};
    std::vector<int> result = kClosestNumbers(A, 2, 3);
    std::cout << "Hello, World!\n";
    return 0;
}


/*
 ###算法
 先用二分法找到target所在的range，然后根据range.left和range.right（two pointer），分别像左右两边取较小的k个结果
 
 ###代码实现
 ***有什么要注意的地方
参考代码注释
 ***有什么要优化的地方
 BCR is O(longN + k), time complexity已经是最优解
 
 ###时空复杂度
 time O(longN + k)
 space O(k)
 
 ###相关的题目有哪些
 Lintcode 200. Longest Palindromic Substring
 Lintcode 1072. Find k-th Smallest Pair Distance
 Lintcode 612. K Closest Points
 Lintcode 459. Closest Number in Sorted Array
 */

