//
//  main.cpp
//  Lintcode-5
//
//  Created by JINGLUO on 22/11/18.
//  Copyright © 2018 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

// Solution 1
//int kthLargestElement(int n, std::vector<int> &nums) {
//    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
//    int i;
//    for(i = 0; i < nums.size(); ++ i) {
//        if (pq.size() < n) {
//            pq.push(nums[i]);
//        } else {
//            int top = pq.top();
//            if (top < nums[i]) {
//                pq.pop();
//                pq.push(nums[i]);
//            }
//        }
//    }
//    return pq.top();
//}

// Solution 2

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int partition(std::vector<int> &nums, int low, int high) {
    int pivot = nums[high];
    int i = low;
    int j;
    for (j = low; j < high; j ++) {
        if (nums[j] > pivot) {
            swap(nums[j], nums[i]);
            i += 1;
        }
    }
    swap(nums[i], nums[high]);
    return i;
}

void quickSort(std::vector<int> &nums, int low, int high) {
    if (low < high) {
        int pivot = partition(nums, low, high);
        quickSort(nums, low, pivot-1);
        quickSort(nums, pivot+1, high);
    }
}

int kthLargestElement(int n, std::vector<int> &nums) {
    int numsCount = int(nums.size());
    if (n > numsCount) {
        return -1;
    }
    quickSort(nums, 0, numsCount-1);
    return nums[n-1];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(8);
    std::cout << kthLargestElement(1, nums) << "\n";
    return 0;
}


/*
 Solution 1:
    - 使用priority_queue来存放最大的k个数，最后取出顶部数据，O(n) time, O(k) extra memory.
 
 Solution 2:
    - 使用快排思想，可以优化到O(NLogN) time, O(1) extra memory.
 */

