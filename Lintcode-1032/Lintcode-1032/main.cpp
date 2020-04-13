//
//  main.cpp
//  Lintcode-1032
//
//  Created by Luo, Jing on 13/4/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> result;

void dfsHelper(string &S, int index, string &currentS) {
    if (currentS.size() == S.size()) {
        result.push_back(currentS);
        return;
    }
    if (index >= S.size()) {
        return;
    }
    if (S[index] >= 'a' && S[index] <= 'z') {
        currentS += toupper(S[index]);
        dfsHelper(S, index+1, currentS);
        currentS = currentS.substr(0, currentS.size()-1);
    } else if (S[index] >= 'A' && S[index] <= 'Z') {
        currentS += tolower(S[index]);
        dfsHelper(S, index+1, currentS);
        currentS = currentS.substr(0, currentS.size()-1);
    }
    currentS += S[index];
    dfsHelper(S, index+1, currentS);
    currentS = currentS.substr(0, currentS.size()-1);
}

vector<string> letterCasePermutation(string &S) {
    string current = "";
    dfsHelper(S, 0, current);
    return result;
}

int main(int argc, const char * argv[]) {
    string S = "1";
    vector<string> result = letterCasePermutation(S);
    std::cout << result.size() << "\n";
    return 0;
}


/*
###算法
 递归+回溯
  
 ###时空复杂度
 Time Complexity: O(2^n))
 Space Complexity: O(2^n)
  
###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/
