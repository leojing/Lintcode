//
//  main.cpp
//  Lintcode-158
//
//  Created by Jing LUO on 17/9/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

bool anagram(std::string &s, std::string &t) {
    if (s.length() != t.length()) {
        return false;
    }
    if (s.length() == 0) {
        return true;
    }
    std::map<char, int> result;
    for (int i = 0; i <= 256; i ++) {
        result[i] = 0;
    }
    for (int i = 0; i < s.length(); i ++) {
        result[s[i]] ++;
    }
    for (int i = 0; i < t.length(); i ++) {
        result[t[i]] --;
    }
    for (int i = 0; i <= 256; i ++) {
        if (result[i] != 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    std::string s = "222@@@e";
    std::string t = "1@@1@12";
    std::cout << anagram(s, t) << "\n";
    return 0;
}


/*
###算法
模拟题

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###时空复杂度
Time complexity: O(N),因为ascii字符最多256个，所以遍历他们的时间复杂度为O(1),不会随着字符串长度而改变，所以最多就是花费在遍历字符串的长度
Space complexity: O(1)因为ascii字符最多256个，所以存储他们的空间复杂度为O(1),不会随着字符串长度而改变

###相关的题目有哪些
176. Route Between Two Nodes in Graph
53. Reverse Words in a String
54. String to Integer (atoi)
55. Compare Strings
181. Flip Bits
*/


