//
//  main.cpp
//  Lintcode-171
//
//  Created by Luo, Jing on 1/15/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<string> anagrams(vector<string> &strs) {
    vector<string> result;
    map<string, vector<string>> mapping;
    for (int i = 0; i < strs.size(); i ++) {
        string cur = strs[i];
        sort(cur.begin(), cur.end());
        if (mapping.find(cur) == mapping.end()) {  // 初始化mapping值
            mapping[cur] = vector<string>();
        }
        mapping[cur].push_back(strs[i]);
    }
    map<string, vector<string>>::iterator it = mapping.begin();
    while (it != mapping.end()) {
        vector<string> anagrams = it->second;
        if (anagrams.size() > 1) {
            result.insert(result.end(), anagrams.begin(), anagrams.end());
        }
        it ++;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> strs = {"lint", "intl", "inlt", "code"};
    std::cout << anagrams(strs).size() << "\n";
    return 0;
}


/*
###算法
普通模拟法
###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###时空复杂度
Time complexity: O(N*MlogM)，N为strs个数，M为strs中string的最大长度
Space complexity: O(n)

###相关的题目有哪些
129. Rehashing
186. Max Points on a Line
48. Majority Number III
49. Sort Letters by Case
32. Minimum Window Substring
*/
