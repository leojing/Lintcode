//
//  main.cpp
//  Lintcode-1293
//
//  Created by Jing Luo on 6/1/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int mergeSort(vector<int> &sums, int lower, int upper, int start, int end) {
    if (end - start <= 1) {
        return 0;
    }
    int mid = start + (end - start) / 2;
    int count = 0, l = mid, r = mid;
    count = mergeSort(sums, lower, upper, start, mid) + mergeSort(sums, lower, upper, mid, end);
    for (int i = start; i < mid; i ++) {
        while (l < end && sums[l] - sums[i] < lower) {
            l ++;
        }
        while (r < end && sums[r] - sums[i] <= upper) {
            r ++;
        }
        count += r - l;
    }
    inplace_merge(sums.begin()+start, sums.begin()+mid, sums.begin()+end);
    return count;
}

int countRangeSum(vector<int> &nums, int lower, int upper) {
    int result = 0;
    int n = int(nums.size());
    if (n == 0) {
        return result;
    }
    vector<int> sums(n+1); // 这里要多放一个，第一个为0
    for (int i = 0 ; i < n; i ++) {
        sums[i+1] = sums[i] + nums[i];
    }
    result = mergeSort(sums, lower, upper, 0, n+1);
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums =
    {-2, 5, -1}; // 2,6
//    {0,-3,-3,1,1,2}; // 3,5
    std::cout << countRangeSum(nums, -2, 2) << "\n";
    return 0;
}


/*
###算法
前缀和+merge sort/二分，根据公式pre2-pre1=lower-->upper，可通过每次便利start-->mid,来找到pre2的范围，之间的个数即start-mid这个范围内的解，利用二分或者merge sort的思想完成O(NLogN)的遍历，得到的和即为最终解


###时空复杂度
Time Complexity: O(NLogN)
Space Complexity: O(N)，用来存放prefixSum

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/

