//
//  main.cpp
//  Lintcode-107
//
//  Created by JINGLUO on 8/7/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

bool wordBreak(std::string &s, std::unordered_set<std::string> &dict) {
    if (s.size() == 0) {
        return true;
    }
    int shortest = INT_MAX;
    int longest = INT_MIN;
    std::unordered_set<std::string>::iterator iter;
    for (iter = dict.begin(); iter != dict.end(); ++ iter) {
        std::string iterS = *iter;
        int sSize = int(iterS.size());
        if (shortest > sSize) {
            shortest = sSize;
        }
        if (longest < sSize) {
            longest = sSize;
        }
    }
    std::vector<bool> dp(int(s.size()-1)); // 不用map，用vector记录，否则Memory Limit Exceede
    for (int i = 0; i < s.size(); ++ i) {
        std::string currentS = s.substr(0, i+1);
        dp[i] = (dict.find(currentS) != dict.end());
        if (dp[i]) { // 注意剪枝，否则TLE
            continue;
        }
        for (int j = shortest; j <= longest; ++ j) { // 通过缩小到只查找单词的长度区间来剪枝
            if (i+1-j > 0) {
                std::string firstS = s.substr(0, i+1-j);
                std::string endS = s.substr(i+1-j, j);
                dp[i] = (dict.find(endS) != dict.end()) && dp[i-j];
                if (dp[i]) { // 注意剪枝，否则TLE
                    break;
                }
            }
        }
    }
    return dp[int(s.size())-1];
}

int main(int argc, const char * argv[]) {
    std::unordered_set<std::string> dict;
    dict.insert("lint");
    dict.insert("co");
    dict.insert("de");
    dict.insert("a");
    dict.insert("2");
    dict.insert("de");
    dict.insert("ide");
    dict.insert("b");
    dict.insert("ab");
    std::string s = "lintcode";
    std::cout << wordBreak(s, dict) << "\n";
    return 0;
}



/*
###算法
dp, 注意剪枝，否则TLE；还有不用map，用vector记录，否则Memory Limit Exceede
 
###代码实现
***有什么要注意的地方
参考注释代码
***有什么要优化的地方

###时空复杂度
time O(？？？)
space O(s.size)

###相关的题目有哪些
680. Split String
582. Word Break II
119. Edit Distance
118. Distinct Subsequences
163. Unique Binary Search Trees
164. Unique Binary Search Trees II
29. Interleaving String
*/

