//
//  main.cpp
//  Lintcode-602
//
//  Created by Jing Luo on 5/3/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool cmp(const pair<int,int> &lhs, const pair<int, int> &rhs) {
    if (lhs.first == rhs.first) {
        // 这里是关键，width要升序排列，height要降序排列
        return lhs.second > rhs.second;
    }
    return lhs.first < rhs.first;
}

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

int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    int size = int(envelopes.size());
    vector<int> dp(size,1);
    sort(envelopes.begin(), envelopes.end(), cmp);
    vector<int> heights(size);
    for (int i = 0; i < size; i ++) {
        heights[i] = envelopes[i].second;
    }
    // 排序之后，就是找heights的最长子序列，这里不能用O(n^2)的dp，会超时，得用二分找最长子序列的方法 time O(NLogN)
    return longestIncreasingSubsequence(heights);
}

int main(int argc, const char * argv[]) {
    vector<pair<int, int>> envelopes = {{4,5},{4,6},{6,7},{2,3},{1,1}};
    //{{31,49},{31,45},{37,7},{12,2},{46,18},{44,10},{9,36},{47,44},{32,45},{18,18},{34,7},{23,28},{28,12},{6,33},{21,33},{30,18},{28,31},{43,41},{47,19},{18,50},{12,5},{29,10},{22,13},{17,21},{18,38},{28,46},{41,1},{49,21},{48,5},{40,21},{20,39},{27,13},{15,23},{28,48},{36,44},{18,7},{46,32},{9,41},{22,34},{49,35},{49,34},{22,3},{47,46},{39,25},{29,39},{29,39},{37,11},{41,49},{37,12},{34,1}};
    //{{15,8},{2,20},{2,14},{4,17},{8,19},{8,9},{5,7},{11,19},{8,11},{13,11},{2,13},{11,19},{8,11},{13,11},{2,13},{11,19},{16,1},{18,13},{14,17},{18,19}};
    //{{4,5},{4,6},{6,7},{2,3},{1,1}};
    std::cout << maxEnvelopes(envelopes) << "\n";
    return 0;
}


// https://labuladong.github.io/ebook/%E7%AE%97%E6%B3%95%E6%80%9D%E7%BB%B4%E7%B3%BB%E5%88%97/%E4%BF%A1%E5%B0%81%E5%B5%8C%E5%A5%97%E9%97%AE%E9%A2%98.html
