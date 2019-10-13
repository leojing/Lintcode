//
//  main.cpp
//  Lintcode-563
//
//  Created by Jing LUO on 13/10/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/* Solution 1:
int backPackV(vector<int> &nums, int target) {
    vector<vector<int>> dp(nums.size()+1,vector<int>(target+1));
    int i,j;
    for (i = 0; i <= nums.size(); i ++) {
        for (j = 0; j <= target; j ++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (i = 1; i <= nums.size(); i ++) {
        for (j = 0; j <= target; j ++) {
            dp[i][j] = dp[i-1][j];
            if (j >= nums[i-1] && dp[i-1][j - nums[i-1]]) {
                dp[i][j] += dp[i-1][j - nums[i-1]];
            }
        }
    }

    return dp[nums.size()][target];
}
*/

// Solution 2:
int backPackV(vector<int> &nums, int target) {
    vector<int> dp(target+1);
    dp[0] = 1;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = target; j > 0; j--) {
            if (j >= nums[i]) {
                dp[j] += dp[j - nums[i]];
            }
        }
    }
    return dp.back();
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,4,2,3,3,7};
    std::cout << backPackV(nums, 6) << "\n";
    return 0;
}

/*
 ###算法
 0-1背包问题，动态规划
 和92类似，只是那里是bool判断能不能fullfill，这里是有多少种方案，因此需要相加
 解题报告：https://www.jianshu.com/p/20944028d1a7

 ###代码实现
 ***有什么要注意的地方
 参考代码注释
 ***有什么要优化的地方

 ###时空复杂度
 Time complexity: O(N*M)
 Space complexity: Solutino 1为O(N*M)， Solution 2为O(M)

 ###相关的题目有哪些
 1538
 800
 749
 724
 700
 669
 588
 564
 563
 562
 440
 279
 125
 */


