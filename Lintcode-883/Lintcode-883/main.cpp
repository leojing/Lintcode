//
//  main.cpp
//  Lintcode-883
//
//  Created by Jing Luo on 4/28/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// Solution 1: 找到所有0的位置，通过计算他们的间隔得到最大值, time O(N), space O(N)
int findMaxConsecutiveOnes(vector<int> &nums) {
    vector<int> locations;
    for (int i = 0; i < nums.size(); i ++) {
        if (nums[i] == 0) {
            locations.push_back(i);
        }
    }
    if (locations.size() == 1 || locations.size() == 0) {
        return int(nums.size());
    }
    int count = 0;
    int result = 0;
    int size = int(locations.size());
    for (int i = 0; i < size; i ++) {
        count = 0;
        if (i == 0) {
            count += locations[i] + 1;
        } else if (locations[i] - locations[i-1] > 1) {
            count += locations[i] - locations[i-1];
        }
        if (i + 1 < size) {
            if (locations[i+1] - locations[i] > 1) {
                count += locations[i+1] - locations[i] - 1;
            }
        }
        if (i == size - 1) {
            count += int(nums.size()) - 1 - locations[i];
        }
        result = max(result, count);
    }
    return result;
}

/* Solution 2: DP, time O(N), space O(N)
 Dp[i][0] 表示以第i个位置为结尾，没有反转过，最长的长度。
 Dp[i][1] 表示以第i个位置为结尾，最多反转过1次的最长的长度。

 分当前是0 还是1，两种状态分别转移。（可以知道的是，每次Dp[i][1]>=Dp[i][0]）

 空间可以优化到O(1), 即int Dp[10005][2];
 
int findMaxConsecutiveOnes(vector<int> &nums) {
    // write your code here
    int n = nums.size();
    int Dp[10005][2];
    if(nums[0] == 1) {
        Dp[0][0] = 1;
        Dp[0][1] = 1;
    } else {
        Dp[0][1] = 1;
        Dp[0][0] = 0;
    }
    int Max = 1;
    for(int i = 1; i < n; i++) {
        if(nums[i] == 0) {
            Dp[i][1] = 1 + Dp[i-1][0];
            Dp[i][0] = 0;
        } else {
            Dp[i][0] = 1 + Dp[i-1][0];
            Dp[i][1] = 1 + Dp[i-1][1];
        }
        Max = max(Max, Dp[i][1]);
    }
    return Max;
}
*/

// Solution 3: sliding window, 同向双指针，follow up可以处理flip k个0的题目，此题即k<=1的情况， time O(N), space O(1)

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,0,1,1,0};//{0,1,1,1,0,1,0,0,1,1,0,1,0,1,0};
    std::cout << findMaxConsecutiveOnes(nums) << "\n";
    return 0;
}
