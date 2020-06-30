//
//  main.cpp
//  Lintcode-77
//
//  Created by Jing Luo on 6/30/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>

using namespace std;

int longestCommonSubsequence(string &A, string &B) {
    int n = int(A.size());
    int m = int(B.size());
    int LCS[n+1][m+1];
    LCS[0][0] = 0;
    for (int i = 1; i <= n; i ++) {
        LCS[i][0] = 0;
    }
    for (int i = 1; i <= m; i ++) {
        LCS[0][i] = 0;
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (A[i-1] == B[j-1]) {
                LCS[i][j] = LCS[i-1][j-1]+1;
            } else {
                LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]);
            }
        }
    }
    return LCS[n][m];
}

int main(int argc, const char * argv[]) {
    string A = "ABCD";
    string B = "EACB";
    std::cout << longestCommonSubsequence(A, B) << "\n";
    return 0;
}


/*
###算法
两个字符串的动态规划一般建立二维数组
dp[i][j]：对于长度为i,j的字符串LCS为dp[i][j]
若当前数字相等，则dp[i][j] = dp[i-1][j-1] + 1
否则，dp[i][j] =max(dp[i-1][j], dp[i][j-1]) // 去掉A的尾巴或者去掉B的尾巴，取大的那个作当前dp[i][j]的值

###时空复杂度
Time Complexity: O(n*m)
Space Complexity: O(n*m)

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/
