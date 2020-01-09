//
//  main.cpp
//  Lintcode-594
//
//  Created by Jing LUO on 8/1/20.
//  Copyright © 2020 Jing LUO. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void kmpHash(string &target, vector<int> &hash) {
    if (target.size() <= 0) {
        return;
    }
    for (int i = 1; i <= target.size(); i ++) {
        string temp = target.substr(0, i);
        hash[i-1] = 0;
        for (int j = 1; j < i; j ++) {
            if (temp.substr(0, j) == temp.substr(temp.size()-j, j)) {
                hash[i-1] = j;
            }
        }
    }
}

int strStr2(const char* source, const char* target) {
    if (source == nullptr || target == nullptr) {
        return -1;
    }
    string s(source);
    string t(target);

    if (t.size() == 0) {
        return 0;
    }

    vector<int> hash = vector<int>(t.size());
    kmpHash(t, hash);

    int diff = int(s.size() - t.size());  // 要确保source剩余可匹配的字母至少有target的长度，少于的话就没必要继续了。
    int i = 0, j = 0, temp;
    while (i <= diff && diff >= 0) {
        temp = i;
        if (s[temp] == t[j]) {
            while (j < t.size()) {
                if (s[temp] != t[j]) {
                    break;
                }
                temp ++;
                j ++;
            }
            if (j == t.size()) {
                return i;
            }
            j = j - hash[j-1];
            i += j;
            if (hash[j-1] == 0) {
                j = 0;
            }
        } else {
            i ++;
            j = 0;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    const char* source = "tartarget";
    const char* target = "target";
    std::cout << strStr2(source, target) << "\n";
    return 0;
}

/*
###算法

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###时空复杂度
Time complexity: O(n+m)，n为source长度，m为target长度
Space complexity: O(1)

###相关的题目有哪些
*/
