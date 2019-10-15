//
//  main.cpp
//  Lintcode-800
//
//  Created by Jing LUO on 15/10/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

double backpackIX(int n, vector<int> &prices, vector<double> &probability) {
    vector<double> dp(n+1);
    for (int i = 0; i <= n; i ++) {
        dp[i] = 1;
    }
    for (int i = 0; i < prices.size(); i ++) {
        for (int j = n; j >= 0; j --) {
            if (j >= prices[i]) {
                dp[j] = min(dp[j], dp[j - prices[i]] * (1 - probability[i])); // 因为是取被拒绝概率，所以这里要1-probability[i]
            }
        }
    }
    return 1 - dp[n];
}

int main(int argc, const char * argv[]) {
    vector<int> prices = {4,4,5};
    vector<double> probability = {0.1, 0.2, 0.3};
    std::cout << backpackIX(10, prices, probability) << "\n";
    return 0;
}


/*
###算法
01背包问题

二维DP - 可能会MLE(Memory Limit Exceeded)
dp[i][j] = MIN{dp[i][j], dp[i][j - prices[i]] * (1 - probability[i]}

dp[i][j]是在j万元的情况下，被前i所学校都拒绝的概率
初始值第一行全是1，因为0万元的情况下一所都无法申请所以一定都被拒
因为是算都不成功的概率所以取MIN，因为如果要求至少一所成功的最大概率换过来说就是一所都不成功的最小概率
总共n万元
一共m所学校
答案是1 - dp[m][n]
一维DP - 空间优化
dp[j] = MIN{dp[j], dp[i - prices[i]] * (1 - probability[i]}

从右往左，因为dp[i - prices[i]]要用到左边的数据
dp[j]是在总共j万元的情况下，被前i所学校都拒绝的概率
答案是1 - f[n]


###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###时空复杂度
Time complexity: O(N*M)
Space complexity: O(N)

###相关的题目有哪些
92
440
125
801
799
798
564
563
562
*/



