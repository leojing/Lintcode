//
//  main.cpp
//  Lintcode-1395
//
//  Created by Jing Luo on 4/29/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void dfs(int x, int father, int n, int &ansSize, int &ansNode, vector<vector<int>> &tree, vector<int> &dp) {
    int maxTree = 0;
    dp[x] = 1;
    for (int i = 0; i < tree[x].size(); i ++) {
        int y = tree[x][i];
        if (y == father) {
            continue;
        }
        dfs(y, x, n, ansSize, ansNode, tree, dp);
        dp[x] += dp[y];
        maxTree = max(maxTree, dp[y]);
    }
    maxTree = max(maxTree, n - dp[x]);
    if (maxTree < ansSize || (maxTree == ansSize && x < ansNode)) {
        ansSize = maxTree;
        ansNode = x;
    }
}

int getBarycentre(vector<int> &x, vector<int> &y) {
    int n = int(x.size()) + 1;
    int ansSize = INT_MAX;
    int ansNode = INT_MAX;

    vector<vector<int>> tree(n+1);
    vector<int> dp(n+1);
    for (int i = 0; i < int(x.size()); i ++) {
        tree[x[i]].push_back(y[i]);
        tree[y[i]].push_back(x[i]);
    }
    dfs(1, 0, n, ansSize, ansNode, tree, dp);
    return ansNode;
}

int main(int argc, const char * argv[]) {
    vector<int> x = {1,2,2};
    vector<int> y = {2,3,4};
    std::cout << getBarycentre(x, y) << "\n";
    return 0;
}


/*
 考点

 树形 DP

 题解

 随意选择一个点作为树的根节点，比如 1 结点。
 dp[i] 代表以 i 为根的子树的结点个数，dp[i] = sum(dp[j]) + 1。
 则以 i 为根的子树的最大结点个数为 max(max(dp[j]), n - dp[i])。
 在 DFS 的过程中维护答案即可。
 
 https://zhuanlan.zhihu.com/p/37273746
 */


// 题都没读懂，完全看答案的，需要返工
