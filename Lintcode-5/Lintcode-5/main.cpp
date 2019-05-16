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
        if (nums[j] < pivot) {
            swap(nums[j], nums[i]);
            i += 1;
        }
    }
    swap(nums[i], nums[high]);
    return i;
}

void quickSort(std::vector<int> &nums, int low, int high, int k) {
    if (low < high) {
        int pivot = partition(nums, low, high);
        if (pivot > k) {
            quickSort(nums, low, pivot - 1, k);
        } else if (pivot < k) {
            quickSort(nums, pivot + 1, high, k);
        }
    }
}

int findKthLargest(std::vector<int>& nums, int k) {
    int numsCount = int(nums.size());
    if (k > numsCount) {
        return -1;
    }
    quickSort(nums, 0, numsCount-1, numsCount-k);
    return nums[numsCount-k];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> nums;
    nums.push_back(7);
    nums.push_back(6);
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    std::cout << findKthLargest(nums, 5) << "\n";
    return 0;
}


/*
 Solution 1:
    - 使用priority_queue来存放最大的k个数，最后取出顶部数据，O(n) time, O(k) extra memory.
 
 Solution 2:
    - 使用快排思想，可以优化到O(NLogN) time, O(1) extra memory.
 
 Optimization:
    - 一个很聪明的优化，因为我们要找第k个大的数，所以其实做二分的时候，可以只取k所在的那个区间的进行后面的排序，因为另一个区间的数组，无论如何都比k小，所以无所谓排不排序，这样可以把time优化到O(N)，省去了二分的logN
 */

