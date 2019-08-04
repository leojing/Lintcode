//
//  main.cpp
//  Lintcode-135
//
//  Created by JINGLUO on 3/8/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>


// 去重 + 排序
std::vector<int> removeDuplicateCandinate(std::vector<int> &candidates) {
    std::vector<int> noDuplicateCandidates;
    std::sort(candidates.begin(), candidates.end());
    for (int i = 0; i < candidates.size(); i ++) {
        if (noDuplicateCandidates.size() == 0) {
            noDuplicateCandidates.push_back(candidates[i]);
        }
        int current = noDuplicateCandidates.back();
        if (candidates[i] != current) {
            noDuplicateCandidates.push_back(candidates[i]);
        }
    }
    return noDuplicateCandidates;
}

// dfs 进行排列组合，寻找以combination开头的所有组合，放到result里。index记录从哪里开始找，不然会有很多重复的结果，因为[2,3,2]和[2,2,3]是一样的，需要去重，用index可以不需要去重了。用sum记录combination内所有数的和，省的要去遍历combination求和。
void dfs(int target, int index, std::vector<int> &noDuplicateCandidates, std::vector<std::vector<int>> &result, std::vector<int> &combination, int sum) {
    if (sum == target) {
        result.push_back(combination);
        return;
    }
    
    for (int i = index; i < noDuplicateCandidates.size(); i ++) {
        if (sum + noDuplicateCandidates[i] <= target) {
            combination.push_back(noDuplicateCandidates[i]);
            sum += noDuplicateCandidates[i];
            dfs(target, i, noDuplicateCandidates, result, combination, sum);
            // 注意这里要回溯下
            combination.pop_back();
            sum -= noDuplicateCandidates[i];
        } else {
            return;
        }
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> noDuplicateCandidates = removeDuplicateCandinate(candidates);
    
    for (int i = 0; i < noDuplicateCandidates.size(); i ++) {
        if (noDuplicateCandidates[i] <= target) {
            std::vector<int> combination = std::vector<int>();
            combination.push_back(noDuplicateCandidates[i]);
            dfs(target, i, noDuplicateCandidates, result, combination, noDuplicateCandidates[i]);
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    std::vector<int> candidates = {6,3,2,7,2,3,};
    std::vector<std::vector<int>> result = combinationSum(candidates, 7);
    std::cout << "Hello, World!\n";
    return 0;
}



/*
 ###算法
 dfs
 
 ###代码实现
 ***有什么要注意的地方
 参考注释代码
 ***有什么要优化的地方
 
 ###时空复杂度分析
 Time O(n)
 Space O(1)
 
 ###相关题目
 Lintcode 717. Tree Longest Path With Same Value
 Lintcode 619. Binary Tree Longest Consecutive Sequence III
 Lintcode 596. Minimum Subtree
 Lintcode 124. Longest Consecutive Sequence
 */
