//
//  main.cpp
//  Lintcode-33
//
//  Created by Jing LUO on 6/8/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

std::vector<std::vector<int>> solutions;
std::vector<std::vector<std::string>> result;

bool canBePlace(int c, std::vector<int> &solution) {
    if (solution.size() == 0) {
        return true;
    }
    int r = int(solution.size());  // c放在第solution.size()行
    for (int i = 0; i < solution.size(); i ++) {
        int tempX = i;  // row即为solution里面元素的index
        int tempY = solution[i];
        if ((tempX - r == tempY - c) || (tempX - r == c - tempY)) {
            return false;
        }
        if (tempY == c) {
            return false;
        }
    }
    return true;
}

std::vector<std::string> draw(int n, std::vector<int> &solution) {
    std::vector<std::string> queenMap;
    for (int i = 0; i < solution.size(); i ++) {
        std::string queens(n, '.');
        int y = solution[i] % n;
        queens.replace(y, 1, "Q");
        queenMap.push_back(queens);
    }
    return queenMap;
}

void dfs(int n, std::vector<int> &solution) {
    if (solution.size() == n) {
        solutions.push_back(solution);
        result.push_back(draw(n, solution));
        return;
    }

    for (int i = 0; i < n; i ++) {
        if (canBePlace(i, solution)) {
            solution.push_back(i);
            dfs(n, solution);
            solution.pop_back();
        }
    }
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
    if (n == 0) {
        return result;
    }
    std::vector<int> solution;
    dfs(n, solution);
    return result;
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<std::string>> result = solveNQueens(12);
    std::cout << result.size() << "\n";
    return 0;
}


/*
 ###算法
 dfs

 ###代码实现
 ***有什么要注意的地方
 参考代码注释
 ***有什么要优化的地方
 写得太复杂了，可以不需要构造map存储

 ###时空复杂度
 Complexity Analysis --组合问题的复杂度的分析
 Time complexity : O(N!). There is N possibilities to put the first queen, not more than N (N - 1) to put the second one, not more than N(N - 1)(N - 2) for the third one etc. In total that results in O(N!) time complexity.
 Space complexity : O(N) （permutation need O(n), visited need 3, boards need O(n))

 以下是时间复杂度的推导；
 根据master method公式 T(n) = aT(n/b) + f(n)
 那么此题则有总公式 T(n) = nT(n-1) + O(n)
 其中nT(n-1) 为recursion解决sub-problems的总共时间
 O(n)为调用当前第一层dfs函数所用时间，即for loop 然后check canBePlace用的时间，因为每次check 是O(1)时间即check if in set()用时O(1)，for loop n次因此为O(n)

 以下进行每一层推导：
 当前层总时间 = 当前个数 * 当前时间
 第一层： T(n) = 1 * O(n)
 第二层：T(n-1) = O(n)*O(n-1) * O(n-1)
 第三层：T(n-2) = O(n)*O(n-1) * O(n-2) *O(n-1)
 ...
 最后一层：T(1) = O(n!)*O(1)
 总共时间：O(n!) + O(n!/2!) + O(n!/3!) + ... + O(n!/n!) ==> O(n!)

 ###相关的题目有哪些
 802. Sudoku Solver
 778. Pacific Atlantic Water flow
 152. Combinations
 */


