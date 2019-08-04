//
//  main.cpp
//  Lintcode-1263
//
//  Created by Jing LUO on 29/7/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <string>

bool isSubsequence(std::string &s, std::string &t) {
    int i = 0, j = 0;
    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) {
            i ++;
        }
        j ++;
    }
    if (i == s.length()) {
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    std::string s = "abc";
    std::string t = "abfsswsg";
    std::cout << isSubsequence(s, t) << "\n";
    return 0;
}


/*
###算法
two pointer

###代码实现
***有什么要注意的地方
***有什么要优化的地方

###时空复杂度
time O(s.len+t.len)
space O(1)

###相关的题目有哪些
Lintcode 1024. Number of Matching Subsequences
*/
