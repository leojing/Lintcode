//
//  main.cpp
//  Lintcode-76
//
//  Created by Jing Luo on 5/4/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


// Solution 1: time O(n^2), space O(n)
int longestIncreasingSubsequence1(vector<int> &nums) {
    int size = int(nums.size());
    vector<int> dp(size, 1);
    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < i; j ++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < dp.size(); i++) {
        res = max(res, dp[i]);
    }
    return res;
}

// Solution 2: ptiance sort, time O(NLogN), space O(N)
int longestIncreasingSubsequence(vector<int> &nums) {
    int size = int(nums.size());
    vector<int> top(size);
    // 牌堆数初始化为 0
    int piles = 0;
    for (int i = 0; i < size; i ++) {
        int left = 0, right = piles;
        /***** 搜索左侧边界的二分查找 *****/
        while (left < right) {
            int mid = left + (right - left)/2;
            if (nums[i] > top[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        /*********************************/
        
        // 没找到合适的牌堆，新建一堆
        if (left == piles) {
            piles ++;
        }
        // 把这张牌放到牌堆顶
        top[left] = nums[i];
    }
    // 牌堆数就是 LIS 长度
    return piles;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,3,4,1,6,4};
    std::cout << longestIncreasingSubsequence(nums) << "\n";
    return 0;
}
