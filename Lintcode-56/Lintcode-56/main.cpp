//
//  main.cpp
//  Lintcode-56
//
//  Created by Luo, Jing on 14/4/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Solution 1: HashMap暴力法，time O(n), space O(n)
vector<int> twoSum(vector<int> &numbers, int target) {
    map<int, vector<int>> map;
    for (int i = 0; i < numbers.size(); i ++) {
        if (map.find(numbers[i]) == map.end()) {
            map[numbers[i]] = {i};
        } else {
            vector<int> current = map[numbers[i]];
            current.push_back(i);
            map[numbers[i]] = current;
        }
    }
    for (int i = 0; i < numbers.size(); i ++) {
        int pair = target-numbers[i];
        if (map.find(pair) != map.end()) {
            if (pair == numbers[i] && map[pair].size() > 1) {
                return {map[pair][0], map[pair][1]};
            } else if (pair != numbers[i]) {
                return {i, map[pair][0]};
            }
        }
    }
    return {-1,-1};
}

// Solution 2: two pointers，需要排序并记录number和index的pair，所以time O(NLogN), space O(n)

int main(int argc, const char * argv[]) {
    vector<int> numbers = {15, 2, 7, 11, 2};
    vector<int> result = twoSum(numbers, 4);
    std::cout << result.size() << "\n";
    return 0;
}


/*
###算法
模拟题
 
###时空复杂度
Time Complexity: O(N)
Space Complexity: O(N)

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/

