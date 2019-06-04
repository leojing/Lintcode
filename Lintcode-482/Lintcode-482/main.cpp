//
//  main.cpp
//  Lintcode-482
//
//  Created by Jing LUO on 3/6/19.
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

int levelSum(TreeNode * root, int level, int targetLevel) {
    if (root == NULL || level > targetLevel) {
        return 0;
    }
    if (level == targetLevel) {
        return root->val;
    }
    
    int left = levelSum(root->left, level+1, targetLevel);
    int right = levelSum(root->right, level+1, targetLevel);
    return left + right;
}


int levelSum(TreeNode * root, int level) {
    if (root == NULL) {
        return 0;
    }
    return levelSum(root, 1, level);
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(3);
    TreeNode *node3 = new TreeNode(4);
    TreeNode *node4 = new TreeNode(5);
    TreeNode *node5 = new TreeNode(6);
    TreeNode *node6 = new TreeNode(7);
    TreeNode *node7 = new TreeNode(8);
    TreeNode *node8 = new TreeNode(9);
    
    root->left = node1;
    root->right = node2;
    
    node1->left = node3;
    node1->right = node4;
    
    node2->left = node5;
    node2->right = node6;
    
    node4->left = node7;
    node6->right = node8;
    
    std::cout << levelSum(root, 3) << "\n";
    return 0;
}


/*
 ###时空复杂度分析
 time 平均为O(n), 其实为到level层所以的点
 
 ###代码实现
 edge case的判断，除了null判断外，可以进行level > targetLevel就直接返回0的剪枝优化
 
 */
