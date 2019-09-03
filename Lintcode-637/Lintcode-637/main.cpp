//
//  main.cpp
//  Lintcode-637
//
//  Created by Jing LUO on 2/9/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <string>

bool isNumber(char a) {
    if (a < '0' || a > '9') {
        return false;
    }
    return true;
}

bool isInValidWithZero(std::string &abbr) {
    if (abbr.length() == 0) {
        return true;
    }
    if (abbr[0] == '0') {
        return true;
    }
    for (int i = 0; i < abbr.length()-1; i ++) {
        if (!isNumber(abbr[i]) && abbr[i+1] == '0') {
            return true;
        }
    }
    return false;
}

bool validWordAbbreviation(std::string &word, std::string &abbr) {
    if (word.length() == 0) {
        return false;
    }
    if (isInValidWithZero(abbr)) {
        return false;
    }
    int left, right, sum = 0;
    if (isNumber(abbr[0])) {
        left = -1;
        right = 0;
    } else {
        left = 0;
        right = 1;
    }
    while (right <= abbr.length()) { // =等于是为了cover以数字结尾的情况，因为这样的话right最后就会等于abbr.length()，也需要进行计算
        if (!isNumber(abbr[right]) || right == abbr.length()) {
            int num;
            if (left == -1) {
                num = std::stoi(abbr.substr(0, right));
            } else {
                if (right - left == 1) {
                    num = 0;
                } else {
                    num = std::stoi(abbr.substr(left+1, right-1-left));
                }
            }
            sum += num;
            if (left == -1) {
                sum -= 1;
            }
            if (word[sum + 1] != abbr[right]) {
                return false;
            } else {
                left = right;
                sum += 1;
            }
        }
        right ++;
        if (sum > word.length()) {
            return false;
        }
        if (sum == word.length()) {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    std::string word = "apple"; //"a"; //"a"; //"apple"; //"apple";
    std::string abbr = "a01ple";//"a"; //"1"; //"2ple";  //"ap3";
    std::cout << validWordAbbreviation(word, abbr) << "\n";
    return 0;
}



/*
###算法
模拟题，注意各种scenario【数字开头，数字结尾，单个字母，有0的情况】等

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###时空复杂度
Time complexity: O(n), n为abbr的length
Space complexity: O(1)

###相关的题目有哪些
639. Word Abbreviation
779. Generalized Abbreviation
*/


