//
//  main.cpp
//  Lintcode-13
//
//  Created by Jing LUO on 8/1/20.
//  Copyright © 2020 Jing LUO. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

// Solution 1: brute force
int strStr(string &source, string &target) {
    if (target.size() == 0) { // target为空时，返回0
        return 0;
    }
    int diff = int(source.size() - target.size());  // 要确保source剩余可匹配的字母至少有target的长度，少于的话就没必要继续了。
    int i = 0, j = 0, temp;
    while (i <= diff && diff >= 0) {
        temp = i;
        j = 0;
        if (source[temp] == target[j]) {
            while (j < target.size()) {
                if (source[temp] != target[j]) {
                    break;
                }
                temp ++;
                j ++;
            }
            if (j == target.size()) {
                return i;
            }
        }
        i ++;
    }
    return -1;
}

// Solution 2: KMP

int main(int argc, const char * argv[]) {
    string source = "source";
    string target = "ur";
    std::cout << strStr(source, target) << "\n";
    return 0;
}

/*
###算法
 Solution 1:遍历查找法,注意edge case的判断，e.g.target为空，target长度大于source

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###时空复杂度
Time complexity: O(n*m)，n为source长度，m为target长度
Space complexity: O(1)

###相关的题目有哪些
594. strStr II
*/


