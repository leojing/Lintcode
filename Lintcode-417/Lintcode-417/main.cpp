//
//  main.cpp
//  Lintcode-417
//
//  Created by Jing LUO on 4/9/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <string>

// Remove space and '+'/'-' at s'head and rear
std::string prepareString(std::string &s) {
    int start = 0;
    int end = int(s.length())-1;
    while (s[start] == ' ') {
        start ++;
    }
    while (s[end] == ' ') {
        end --;
    }
    return s.substr(start, end-start+1);
}

// Special char exclude 0-9,'.'/'e'/'E'
bool invalidWithSpecialChar(std::string &s) {
    int start = 0;
    if (s[0] == '+' || s[0] == '-') {
        start = 1;
    }
    for (int i = start; i < s.length(); i ++) {
        if ((s[i] >= '0' && s[i] <= '9') || s[i] == '.' || s[i] == 'e' || s[i] == 'E') {
        } else {
            return true;
        }
    }
    return false;
}

// '.'/'e'/'E' occurs more than once
bool moreThanOnce(std::string &s) {
    int count = 0;
    for (int i = 0; i < s.length(); i ++) {
        if (s[i] == '.' || s[i] == 'e' || s[i] == 'E') {
            count ++;
        }
    }
    return count > 1;
}

// digital must occur at least once
// before or after '.'/'e'/'E', must has a digital
bool followTheNumberRules(std::string &s) {
    int count = 0;
    int digitalCount = 0;
    for (int i = 0; i < s.length(); i ++) {
        if (s[i] >= '0' && s[i] <= '9') {
            digitalCount ++;
        }
        if (s[i] == '.' || s[i] == 'e' || s[i] == 'E') {
            count = 0;
            if (i-1 >= 0) {
                if (s[i-1] >= '0' && s[i-1] <= '9') {
                    count ++;
                }
            }
            if (i+1 < s.length()) {
                if (s[i+1] >= '0' && s[i+1] <= '9') {
                    count++;
                }
            }
            if (s[i] == '.' && count == 0) {
                return false;
            }
            if ((s[i] == 'e' || s[i] == 'E') && count != 2) {
                return false;
            }
        }
    }
    return digitalCount > 0;
}

bool isNumber(std::string &s) {
    if (s.length() == 0) {
        return false;
    }
    std::string newS = prepareString(s);
    if (newS.length() == 0) {
        return false;
    }
    if (invalidWithSpecialChar(newS)) {
        return false;
    }
    if (moreThanOnce(newS)) {
        return false;
    }
    return followTheNumberRules(newS);
}

int main(int argc, const char * argv[]) {
    std::string s = "   ++233.1"; // " "; // " .1"; // "-34."; // "  +e"; // " +"; // "67e33E"; // " ++67Tchgj97"; // "66 87";
    std::cout << isNumber(s) << "\n";
    return 0;
}


/*
 首先应该明确合法的数字有哪些:

 整数, 例如 "122", "114"
 浮点数, 例如 "1.2", "2.", ".5", "1e10", "1E10"
 上面两种数加上符号, 即 "+" 或 "-", 只能出现在开头/一次
 "2.", ".5" 这两种形式可能让你有点迷惑, 你可以试一试, 在大多数编程语言中它们都是合法的字面量.

 为了方便, 我们可以先处理掉首尾的空白字符. 然后再判断第一个是否符号, 如果是也过滤掉.

 然后, 剩下的字符串就只能包含 0-9, ., e/E 这三类字符了, 如果含有这三类之外的, 直接返回 false 即可. 然后根据以下原则判断即可:

 小数点和 e/E 都至多只能出现 1 次，且不能同时出现
 如果含有小数点, 则小数点前后至少有一个数字, 一个孤立的小数点是非法的.
 如果含有 e/E, 则它的前后必须有数字.
 */

/*
 ###算法
 模拟题，明确需求，考虑好所有case即可

 ###代码实现
 ***有什么要注意的地方
 参考代码注释
 ***有什么要优化的地方

 ###时空复杂度
 Time complexity: O(s.length)
 Space complexity: O(1)

 ###相关的题目有哪些
 */

