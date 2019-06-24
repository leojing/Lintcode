//
//  main.cpp
//  Lintcode-376
//
//  Created by JINGLUO on 24/6/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

std::vector<std::vector<int>> results = std::vector<std::vector<int>>();

void helper(TreeNode * root, int target, std::vector<int> *result) {
    result->push_back(root->val);
    
    if (root->left == NULL && root->right == NULL) {
        if (target == root->val) {
            results.push_back(*result);
        }
        return;
    }
    if (root->left != NULL) {
        helper(root->left, target - root->val, result);
        result->pop_back();
    }
    if (root->right != NULL) {
        helper(root->right, target - root->val, result);
        result->pop_back();
    }
}

std::vector<std::vector<int>> binaryTreePathSum(TreeNode * root, int target) {
    if (root == NULL) {
        return results;
    }
    std::vector<int> *result = new std::vector<int>();
    helper(root, target, result);
    return results;
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(-5);
    TreeNode *node3 = new TreeNode(4);
    TreeNode *node4 = new TreeNode(5);
    TreeNode *node5 = new TreeNode(6);
    
    root->left = node1;
    root->right = node2;
    
    node1->left = node3;
    
    node2->left = node4;
    node2->right = node5;

    std::vector<std::vector<int>> result = binaryTreePathSum(root, 2);
    std::cout << "Hello, World!\n";
    return 0;
}


/*
 ###算法
 用Recursion实现的traversal遍历+backtracking
 
 ###代码实现
 - null判断又忘记了
 - if (root->left != NULL) {
        helper(root->left, target - root->val, result);
        result->pop_back();
    }
 这里需要判断不为NULL，再进入helper，否则pop_back()会因为进入了NULL而把之前有用的value给pop掉，一定记得要pop_back()，把没用的value pop出去
 
 ###时空复杂度分析
 Time O(n)
 Space O(n)
 
 ###相关题目
 Lintcode 1353. Sum Root to Leaf Numbers
 Lintcode 863. Binary Tree Path Sum IV
 Lintcode 472. Binary Tree Path Sum III
 Lintcode 246. Binary Tree Path Sum II
 */
