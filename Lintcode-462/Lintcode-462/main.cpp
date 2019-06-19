//
//  main.cpp
//  Lintcode-462
//
//  Created by JINGLUO on 19/6/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

int helperForFirstPosition(std::vector<int> &A, int target, int start, int end) {
    int mid;
    while (start + 1 < end) {
        mid = start + (end - start) / 2;
        if (A[mid] >= target) {
            end = mid;
        } else {
            start = mid;
        }
        return helperForFirstPosition(A, target, start, end);
    }
    if (A[start] == target) {
        return start;
    }
    if (A[end] == target) {
        return end;
    }
    return -1;
}

int helperForLastPosition(std::vector<int> &A, int target, int start, int end) {
    int mid;
    while (start + 1 < end) {
        mid = start + (end - start) / 2;
        if (A[mid] <= target) {
            start = mid;
        } else {
            end = mid;
        }
        return helperForLastPosition(A, target, start, end);
    }
    if (A[end] == target) {
        return end;
    }
    if (A[start] == target) {
        return start;
    }
    return -1;
}

int totalOccurrence(std::vector<int> &A, int target) {
    int ASize = int(A.size());
    if (ASize == 0) {
        return 0;
    }
    int first = helperForFirstPosition(A, target, 0, ASize - 1);
    int last = helperForLastPosition(A, target, 0, ASize - 1);
    if (first == -1 || last == -1) {
        return 0;
    }
    return last - first + 1;
}

int main(int argc, const char * argv[]) {
    std::vector<int> A = {1,2,2,4,5,6,7};
    std::cout << totalOccurrence(A, 6) << "\n";
    return 0;
}


/*
 ###算法
 二分法，找到目标值的first position，和last position，相减即为target的个数
 
 ###代码实现
 ***有什么要注意的地方
 参考代码注释
 ***有什么要优化的地方
 BCR is O(logN), time complexity已经是最优解， same as space complexity
 
 ###时空复杂度
 time O(logN), first position O(logN) + last position O(logN) = O(2LogN) == O(logN)
 space O(1)
 
 ###相关的题目有哪些
 Lintcode 61. Search for a Range
 */

