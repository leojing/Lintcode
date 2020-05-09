//
//  main.cpp
//  Lintcode-516
//
//  Created by Jing Luo on 5/9/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/* 传统二维dp，time O(n*k*k)，会超时
 int minCostII(vector<vector<int>> &costs) {
     int n = int(costs.size());
     if (n == 0) {
         return 0;
     }
     int K = int(costs[0].size());
     int result = INT_MAX;
     vector<vector<int>> dp(n, vector<int>(K));
     for (int i = 0; i < K; i ++) {
         dp[0][i] = costs[0][i];
     }
     for (int i = 1; i < n; i ++) {
         for (int j = 0; j < K; j ++) {
             dp[i][j] = INT_MAX;
             for (int k = 0; k < K; k ++) {
                 if (k != j) {
                     dp[i][j] = min(dp[i][j], dp[i-1][k] + costs[i][j]);
                 }
             }
         }
     }
     for (int i = 0; i < K; i ++) {
         result = min(result, dp[n-1][i]);
     }
     return result;
 }
 */

// 基于上面的解法，优化的点在于第二个k循环，通过记录最小值和倒数第二小的值，就可以代替k循环去找最小值，因为不是+最小值，就是+倒数第二小的值（如果最小值在当前点上面，不能取一样的颜色）
// time O(nk), space O(nk)
int minCostII(vector<vector<int>> &costs) {
    int n = int(costs.size());
    if (n == 0) {
        return 0;
    }
    int K = int(costs[0].size());
    int result = INT_MAX;
    int firstMin = INT_MAX;
    int firstMinIndex = INT_MAX;
    int secondMin = INT_MAX;
    int secondMinIndex = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(K));
    for (int i = 0; i < K; i ++) {
        dp[0][i] = costs[0][i];
        // 判断最小值和第二小的值要注意，错了好几把
        if (dp[0][i] < firstMin) {
            secondMin = firstMin;
            secondMinIndex = firstMinIndex;
            firstMin = dp[0][i];
            firstMinIndex = i;
            continue;
        }
        if (dp[0][i] < secondMin && dp[0][i] >= firstMin) {
            secondMin = dp[0][i];
            secondMinIndex = i;
        }
    }
    for (int i = 1; i < n; i ++) {
        int tFirstMin = INT_MAX;
        int tFirstMinIndex = INT_MAX;
        int tSecondMin = INT_MAX;
        int tSecondMinIndex = INT_MAX;
        for (int j = 0; j < K; j ++) {
            dp[i][j] = INT_MAX;
            if (j == firstMinIndex) { // 如果上一排的最小值和当前颜色一样，则不取。+倒数第二小的值
                dp[i][j] = costs[i][j] + dp[i-1][secondMinIndex];
            } else { // 反之则取最小值
                dp[i][j] = costs[i][j] + dp[i-1][firstMinIndex];
            }
            if (dp[i][j] < tFirstMin) {
                // 注意这里如果最小值更新了，那么倒数第二小的值就是之前的最小值
                tSecondMin = tFirstMin;
                tSecondMinIndex = tFirstMinIndex;
                tFirstMin = dp[i][j];
                tFirstMinIndex = j;
                continue;
            }
            if (dp[i][j] < tSecondMin && dp[i][j] >= tFirstMin) {
                tSecondMin = dp[i][j];
                tSecondMinIndex = j;
            }
        }
        firstMin = tFirstMin;
        firstMinIndex = tFirstMinIndex;
        secondMin = tSecondMin;
        secondMinIndex = tSecondMinIndex;
    }
    for (int i = 0; i < K; i ++) {
        result = min(result, dp[n-1][i]);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> costs = {{1,2,1,3},{1,2,18,5},{4,8,8,10}};
    //{{1,5,6},{14,15,5},{4,3,3},{15,15,9},{9,2,7},{6,5,7},{19,4,4},{6,13,3},{8,16,20},{18,7,9}};
    //{{14,2,11},{11,14,5},{14,3,10}};
    std::cout << minCostII(costs) << "\n";
    return 0;
}
