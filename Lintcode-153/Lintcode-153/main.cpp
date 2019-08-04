//
//  main.cpp
//  Lintcode-153
//
//  Created by JINGLUO on 3/8/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

// dfs 进行排列组合，寻找以combination开头的所有组合，放到result里。index记录从哪里开始找，不然会有很多重复的结果。用sum记录combination内所有数的和，省的要去遍历combination求和。
void dfs(int target, int index, std::vector<int> &candidates, std::set<std::vector<int>> &result, std::vector<int> &combination, int sum) {
    if (sum == target) {
        result.insert(combination);
        return;
    }
    
    for (int i = index+1; i < candidates.size(); i ++) {
        if (sum + candidates[i] <= target) {
            combination.push_back(candidates[i]);
            sum += candidates[i];
            dfs(target, i, candidates, result, combination, sum);
            // 注意这里要回溯下
            combination.pop_back();
            sum -= candidates[i];
        } else {
            return;
        }
    }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target) {
    std::set<std::vector<int>> result;
    std::sort(candidates.begin(), candidates.end());

    for (int i = 0; i < candidates.size(); i ++) {
        if (candidates[i] <= target) {
            std::vector<int> combination = std::vector<int>();
            combination.push_back(candidates[i]);
            dfs(target, i, candidates, result, combination, candidates[i]);
        }
    }
    
    std::vector<std::vector<int>> output(result.size());
    std::copy(result.begin(), result.end(), output.begin());
    return output;
}

int main(int argc, const char * argv[]) {
    std::vector<int> candidates = {7,1,2,5,1,6,10};
    std::vector<std::vector<int>> result = combinationSum2(candidates, 8);
    std::cout << "Hello, World!\n";
    return 0;
}
