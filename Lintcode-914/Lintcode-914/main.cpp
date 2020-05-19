//
//  main.cpp
//  Lintcode-914
//
//  Created by Jing Luo on 5/19/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> generatePossibleNextMoves(string &s) {
    if (s.size() == 0) {
        return {};
    }
    vector<string> result;
    for (int i = 0; i < s.size() - 1; i ++) {
        if (s[i] == '+' && s[i+1] == '+') {
            string temp = s;
            temp[i] = '-';
            temp[i+1] = '-';
            result.push_back(temp);
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    string s = "--++--++-";
    vector<string> result = generatePossibleNextMoves(s);
    std::cout << result.size() << "\n";
    return 0;
}



/*
###算法
模拟题
 
###时空复杂度
Time Complexity: O(n)
Space Complexity: O(n)

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/

