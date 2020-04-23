//
//  main.cpp
//  Lintcode-640
//
//  Created by Luo, Jing on 22/4/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

bool isOneEditDistance(string &s, string &t) {
    int sLength = int(s.size());
    int tLength = int(t.size());
    int diff = abs(sLength - tLength);
    if (diff >= 2 || s == t) {
        return false;
    }
    bool hasDiff = false;
    if (diff == 0) {
        for (int i = 0; i < sLength; i ++) {
            if (s[i] != t[i]) {
                if (hasDiff) { // 如果之前已经出现过diff，直接返回false
                    return false;
                }
                hasDiff = true;
            }
        }
    } else {
        // 要保证s始终是短的那个，方便统一处理
        if (sLength > tLength) {
            swap(s, t);
            swap(sLength, tLength);
        }
        int i = 0, j = 0;
        while (i < sLength) {
            if (s[i] != t[j]) {
                if (hasDiff) { // 如果之前已经出现过diff，直接返回false
                    return false;
                }
                j ++; // 有diff的情况，只挪动长的string
                hasDiff = true;
            } else {
                i ++;
                j ++;
            }
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    string s = "bcde";//"abdws";//"bcde";//"a";
    string t = "abcde";//"abdw";//"abcde";//"a";
    std::cout << isOneEditDistance(s, t) << "\n";
    return 0;
}



/*
###算法
模拟题，根据不同情况进行解析
 
###时空复杂度
Time Complexity: O(n)
Space Complexity: O(1)

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/

