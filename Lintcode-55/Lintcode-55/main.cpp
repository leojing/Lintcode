//
//  main.cpp
//  Lintcode-55
//
//  Created by Jing LUO on 19/9/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

bool compareStrings(std::string &A, std::string &B) {
    if (A.length() == 0 && B.length() == 0) {
        return true;
    }
    if (A.length() == 0) {
        return false;
    }
    std::map<char, int> result;
    for (int i = 'A'; i <= 'Z'; i ++) {
        result[i] = 0;
    }
    for (int i = 0; i < A.length(); i ++) {
        result[A[i]] ++;
    }
    for (int i = 0; i < B.length(); i ++) {
        result[B[i]] --;
    }
    for (int i = 'A'; i <= 'Z'; i ++) {
        if (result[i] < 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    std::string A = "ABGFVS"; // "";    // "";     // "SHJ";
    std::string B = "GGGVF";  // "";    // "ABC";  // "";
    std::cout << compareStrings(A, B) << "\n";
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
Time complexity: O(N),因为大写字符最多26个，所以遍历他们的时间复杂度为O(1),不会随着字符串长度而改变，所以最多就是花费在遍历字符串的长度
Space complexity: O(1)因为大写字符最多26个，所以存储他们的空间复杂度为O(1),不会随着字符串长度而改变

###相关的题目有哪些
13. Implement strStr()
54. String to Integer (atoi)
133. Longest Word
193. Longest Valid Parentheses
9. Fizz Buzz
*/


