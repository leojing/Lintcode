//
//  main.cpp
//  Lintcode-92
//
//  Created by Jing LUO on 13/10/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/* Solution 1:
int backPack(int m, vector<int> &A) {
    vector<vector<bool>> dp(A.size()+1,vector<bool>(m+1));
    int i,j;
    for (i = 0; i <= A.size(); i ++) {
        for (j = 0; j <= m; j ++) {
                dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (i = 1; i <= A.size(); i ++) {
        for (j = 0; j <= m; j ++) {
            dp[i][j] = dp[i-1][j];
            if (j >= A[i-1] && dp[i-1][j - A[i-1]]) {
                dp[i][j] = 1;
            }
        }
    }

    for (int i = m; i >= 0; i --) {
        if (dp[A.size()][i]) {
            return i;
        }
    }
    return 0;
}*/

// Solution 2:
int backPack(int m, vector<int> &A) {
    vector<int> dp(m+1);
    for (int i = 0; i < A.size(); i++) {
        for (int j = m; j > 0; j--) {
            if (j >= A[i]) {
                dp[j] = max(dp[j], dp[j - A[i]] + A[i]);
            }
        }
    }
    return dp.back();
}

int main(int argc, const char * argv[]) {
    vector<int> A = {3,4,8,5};
    std::cout << backPack(10, A) << "\n";
    return 0;
}



/*
###算法
0-1背包问题，动态规划
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


