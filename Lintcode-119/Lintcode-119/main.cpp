//
//  main.cpp
//  Lintcode-119
//
//  Created by Jing LUO on 29/7/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

int minDistance(std::string &word1, std::string &word2) {
    // write your code here
    int word1Len = int(word1.length());
    int word2Len = int(word2.length());
    std::vector<std::vector<int>> dp(word1Len+1, std::vector<int>(word2Len+1));  // dp里2个纬度包含的不是word1和word2的index，而是分别取几个字母
    for (int i = 0; i <= word1Len; i ++) {
        dp[i][0] = i; // 表示word1取前i个，word2一个不取，需要i次操作
    }
    for (int i = 0; i <= word2Len; i ++) {
        dp[0][i] = i; // 表示word2取前i个，word1一个不取，需要i次操作
    }
    for (int i = 1; i <= word1Len; i ++) {
        for (int j = 1; j <= word2Len; j ++) {
            if (word1[i-1] == word2[j-1]) {  // 判断的时候要-1，因为是需要index，而i和j表示的是个数
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = dp[i-1][j-1]+1;
                dp[i][j] = std::min(dp[i][j], std::min(dp[i-1][j]+1, dp[i][j-1]+1));
            }
        }
    }
    return dp[word1Len][word2Len];
}

int main(int argc, const char * argv[]) {
    std::string word1 = "horse";
    std::string word2 = "ros";
    std::cout << minDistance(word1, word2) << "\n";
    return 0;
}


/*
###算法
DP，解题报告参考：http://fisherlei.blogspot.com/2012/12/leetcode-edit-distance.html

###代码实现
***有什么要注意的地方
***有什么要优化的地方

###时空复杂度
time O(word1.len*word2.len)
space O(word1.len*word2.len)

###相关的题目有哪些
Lintcode 1024. Number of Matching Subsequences
*/
