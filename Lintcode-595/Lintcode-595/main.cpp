//
//  main.cpp
//  Lintcode-595
//
//  Created by JINGLUO on 30/6/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

int maxSum = 0;

void helper(TreeNode * root, int sum) {
    if (sum > maxSum) {
        maxSum = sum;
    }
    
    if (root == NULL) {
        return;
    }
    if (root->left != NULL && (root->left->val == root->val + 1)) { // 如果left为root的连续上升子节点，即值+1，那么sum+1，继续递归
        helper(root->left, sum + 1);
    } else {
        helper(root->left, 1); // 否则，将left作为新的起始点，sum = 1
    }
    
    if (root->right != NULL && (root->right->val == root->val + 1)) { // right同理left
        helper(root->right, sum + 1);
    } else {
        helper(root->right, 1);
    }
}

int longestConsecutive(TreeNode * root) {
    if (root == NULL) {
        return 0;
    }
    helper(root, 1);
    return maxSum;
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(3);
    TreeNode *node5 = new TreeNode(3);
    TreeNode *node6 = new TreeNode(3);
    TreeNode *node7 = new TreeNode(4);

    root->left = node1;
    root->right = node2;
    
    node1->left = node3;
    node1->right = node4;

    node2->left = node5;
    node2->right = node6;

    node6->right = node7;

    std::cout << longestConsecutive(root) << "\n";
    return 0;
}


/*
 ###算法
 用DFS实现的traversal遍历
 
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
 Lintcode 614. Binary Tree Longest Consecutive Sequence II
 Lintcode 596. Minimum Subtree
 Lintcode 124. Longest Consecutive Sequence
 */
