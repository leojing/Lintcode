//
//  main.cpp
//  Lintcode-420
//
//  Created by Luo, Jing on 13/4/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n) {
    if (n == 1) {
        return "1";
    }
    if (n == 2) {
        return "11";
    }
    string S = "11";
    string result = "";
    n -= 2;
    while (n --) {
        char temp = S[0];
        int count = 1;
        for (int i = 1; i < S.size(); i ++) {
            if (S[i] == temp) {
                count ++;
                continue;
            }
            result += to_string(count);
            result += temp;
            temp = S[i];
            count = 1;
        }
        // 循环结束后，要再加上最后一个数字的count&say
        result += to_string(count);
        result += temp;
        S = result;
        result = ""; // 注意每次result要清除
    }
    return S;
}

int main(int argc, const char * argv[]) {
    string result = countAndSay(9);
    std::cout << result << "\n";
    return 0;
}


/*
###算法
 模拟题
  
 ###时空复杂度
 Time Complexity: O(n*字符串的长度))
 Space Complexity: O(1)
  
###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/
