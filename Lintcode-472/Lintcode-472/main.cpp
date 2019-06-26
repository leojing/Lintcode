//
//  main.cpp
//  Lintcode-472
//
//  Created by JINGLUO on 26/6/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

class ParentTreeNode {
public:
    int val;
    ParentTreeNode *parent, *left, *right;
};

std::vector<std::vector<int>> results;

// what does "from" mean, which node is the current comes, need to make sure not go back to the "from" for tranverse
void searchPathFrom(ParentTreeNode * root, int target, ParentTreeNode *from, std::vector<int> &result) {
    result.push_back(root->val);
    
    if (target == root->val) {
        results.push_back(result);
        // return; 这里在相等的情况下，不能直接return，因为万一后面有0，那么后面的0就没法加入结果中，e.g. {1,0,0,0}
    }
    
    if (root->parent != NULL && from != root->parent) {
        searchPathFrom(root->parent, target - root->val, root, result);
        result.pop_back();
    }
    
    if (root->right != NULL && from != root->right) {
        searchPathFrom(root->right, target - root->val, root, result);
        result.pop_back();
    }
    
    if (root->left != NULL && from != root->left) {
        searchPathFrom(root->left, target - root->val, root, result);
        result.pop_back();
    }
}

void helper(ParentTreeNode * root, int target) {
    if (root == NULL) {
        return;
    }
    std::vector<int> result;
    searchPathFrom(root, target, NULL, result);
    helper(root->left, target);
    helper(root->right, target);
}

std::vector<std::vector<int>> binaryTreePathSum3(ParentTreeNode * root, int target) {
    if (root == NULL) {
        return results;
    }
    helper(root, target);
    return results;
}

int main(int argc, const char * argv[]) {
    ParentTreeNode *root = new ParentTreeNode();
    root->val = 1;
    
    ParentTreeNode *node1 = new ParentTreeNode;
    node1->val = 0;
    
    ParentTreeNode *node2 = new ParentTreeNode;
    node2->val = 0;
    
    ParentTreeNode *node3 = new ParentTreeNode;
    node3->val = 0;
    
    root->parent = NULL;
    root->left = node1;
    root->right = node2;
    
    node1->parent = root;
    node1->left = node3;
    node1->right = NULL;

    node2->parent = root;
    node2->left = NULL;
    node2->right = NULL;

    node3->parent = node1;
    node3->left = NULL;
    node3->right = NULL;
    
    std::vector<std::vector<int>> result = binaryTreePathSum3(root, 1);
    std::cout << "Hello, World!\n";
    return 0;
}



/*
 ###算法
 DFS + DFS， 双重DFS， 注意不但要求从root 节点开始满足条件的path，还要从，root。left 和right 节点出发寻找满足节点的条件
 所以 第一重 DFS，先遍历所以node
 第二重 DFS， 就是真正的findSum， 从当前node出发，往三个方向寻找，注意如果node已经存在与from node中，则不用再找。不然 1-》2 —》 1 -》 2 满足6. 但实际上不是正确路径
 
 ###代码实现
 ***有什么要注意的地方
 参考注释代码
 ***有什么要优化的地方
 
 ###时空复杂度
 time O(？？？）好难算🤯
 space O(n)
 
 ###相关的题目有哪些
 Lintcode 376. Binary Tree Path Sum
 Lintcode 246. Binary Tree Path Sum II
 */

