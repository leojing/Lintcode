//
//  main.cpp
//  Lintcode-447
//
//  Created by JINGLUO on 12/6/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

int helper(std::vector<int>& reader, int start, int end, int target) {
    int mid;
    if (start + 1 < end) {
        mid = start + (end - start) / 2;
        if (reader[mid] >= target) {
            end = mid;
        } else {
            start = mid;
        }
        return helper(reader, start, end, target);
    }
    if (reader[start] == target) {
        return start;
    }
    if (reader[end] == target) {
        return end;
    }
    return -1;
}

int searchBigSortedArray(std::vector<int>& reader, int target) {
    int start = 0, end = 1;
    while (reader[end] < target) { // 二分法的逆向使用（倍增法），确定左右边界
        start = end + 1;
        end = (end + 1) * 2 - 1;
    }
    return helper(reader, start, end, target); // 普通查找第一个position的二分法
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> reader = {1,3,6,9,21,34,53,54,56,67,78,98,102,103,135,135,135,234};
    std::cout << searchBigSortedArray(reader, 135) << "\n";
    return 0;
}


/*
 ###算法
 二分法的逆向使用（倍增法）结合二分法。即首先通过倍增的方式找到首个超过目标值的元素的坐标；然后以（此坐标）为右边界，（此坐标的一半） 为左边界，在这个区间内搜索目标元素。

 ###代码实现
 ***有什么要注意的地方
 ***有什么要优化的地方
 
 ###时空复杂度
 time O(log(k))  k为目标元素首次出现的下标
 space O(1)
 
 ###相关的题目有哪些
 
 */

