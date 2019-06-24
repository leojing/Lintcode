//
//  main.cpp
//  Lintcode-596
//
//  Created by Jing LUO on 24/6/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
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

int sum = INT_MAX;
TreeNode *resultNode = NULL;

int helper(TreeNode * root) {
    if (root == NULL) { //edge case
        return 0;
    }
    int left = helper(root->left);
    int right = helper(root->right);
    int result = left + right + root->val;
    if (result < sum) {
        sum = result;
        resultNode = root;
    }
    return result;
}

TreeNode * findSubtree(TreeNode * root) {
    helper(root);
    return resultNode;
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(-5);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(1);
    TreeNode *node4 = new TreeNode(2);
    TreeNode *node5 = new TreeNode(-4);
    TreeNode *node6 = new TreeNode(-5);
    TreeNode *node7 = new TreeNode(2);
    TreeNode *node8 = new TreeNode(3);
    
    root->left = node1;
    root->right = node2;
    
    node1->left = node3;
    node1->right = node4;
    
    node2->left = node5;
    node2->right = node6;
    
    node3->left = node7;
    node3->right = node8;
    
    std::cout << findSubtree(root) << "\n";
    return 0;
}


/*
 ###算法
 Divide & conquer + Recursion
 
 ###代码实现
 ***有什么要注意的地方
 Subtree的定义
 ***有什么要优化的地方
 BCR is O(n), time complexity已经是最优解， same as space complexity
 
 ###时空复杂度
 time O(n), binary tree的遍历
 space O(h), 因为开辟了一个global变量 resultTNode, 所以需要一颗tree通常占用的内存,即tree的高度
 
 ###相关的题目有哪些
 */
