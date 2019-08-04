//
//  main.cpp
//  Lintcode-1227
//
//  Created by Jing LUO on 27/7/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <string>


bool helper(std::string &s, int subLen) {
    if (s.length() % subLen != 0 || subLen == s.length()) {
        return false;
    }
    for (int i = 0; i < s.length(); i += subLen) {
        std::string subString1 = s.substr(i, subLen);
        std::string subString2;
        if (i+subLen < s.length()) {
            std::string subString2 = s.substr(i+subLen, subLen);
            if (subString1 != subString2) {
                return false;
            }
        }
    }
    return true;
}

bool repeatedSubstringPattern(std::string &s) {
    char first = s[0];
    int len = int(s.length());
    for (int i = len-1; i >= 0; i --) {
        if(s[i] == first) {
            if (helper(s, len-i)) {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    std::string s = "aba";
    std::cout << repeatedSubstringPattern(s) << "\n";
    return 0;
}


/*
###算法
模拟题，最优解法为KMP

###代码实现
***有什么要注意的地方
***有什么要优化的地方

###时空复杂度
time O(len*v(len))，其中v(len)为len的因数个数（因为我们只需要对整除len的lenSub进行进一步判断）
space O(1)

###相关的题目有哪些
Lintcode 1207. Teemo Attacking
Lintcode 1001. Asteroid Collision
*/
