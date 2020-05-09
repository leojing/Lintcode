//
//  main.cpp
//  Lintcode-425
//
//  Created by Jing Luo on 5/6/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void dfs(vector<string> &result, map<char, vector<char>> mapping, string &digits, string current, int index) {
    if (index == digits.size()) {
        result.push_back(current);
    }
    if (mapping.find(digits[index]) == mapping.end()) {
        return;
    }
    vector<char> chars = mapping[digits[index]];
    for (int i = 0; i < chars.size(); i ++) {
        current += chars[i];
        dfs(result, mapping, digits, current, index+1);
        current = current.substr(0, current.size()-1);
    }
}

vector<string> letterCombinations(string &digits) {
    if (digits.size() == 0) { // Edge case, 一定要先处理，WA了一把
        return {};
    }
    vector<string> result;
    map<char, vector<char>> mapping;
    mapping['0'] = {' '};
    mapping['2'] = {'a','b','c'};
    mapping['3'] = {'d','e','f'};
    mapping['4'] = {'g','h','i'};
    mapping['5'] = {'j','k','l'};
    mapping['6'] = {'m','n','o'};
    mapping['7'] = {'p','q','r', 's'};
    mapping['8'] = {'t','u','v'};
    mapping['9'] = {'w','x', 'y', 'z'};
    dfs(result, mapping, digits, "", 0);
    return result;
}

int main(int argc, const char * argv[]) {
    string digits = "234";
    vector<string> result = letterCombinations(digits);
    std::cout << "\n";
    return 0;
}



// 经典dfs
