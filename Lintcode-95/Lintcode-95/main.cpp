//
//  main.cpp
//  Lintcode-95
//
//  Created by JINGLUO on 24/6/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>

class TreeNode {
public:
    long val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

bool help(TreeNode *root, long min, long max) {
    if (root == NULL) {
        return true;
    }
    if (root->val <= min || root->val >= max) { // 如果root本身不在min-max范围内，则直接返回false，否则，去判断root->left和root->right是否满足条件
        return false;
    }
    bool left = help(root->left, min, root->val);
    bool right = help(root->right, root->val, max);
    return left && right; // 只有left和right均满足，才是valid
}

bool isValidBST(TreeNode * root) {
    if (root == NULL) {
        return true;
    }
    long min = LONG_LONG_MIN; // 注意要用Long，不然int会越界
    long max = LONG_LONG_MAX;
    return help(root, min, max);
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(2);
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(4);
    TreeNode *node3 = new TreeNode(0);
    TreeNode *node4 = new TreeNode(5);
    
    root->left = node1;
    root->right = node2;
    
    node2->left = node3;
    node2->right = node4;

    std::cout << isValidBST(root) << "\n";
    return 0;
}



/*
 ###算法
 Divide and conquer,对于s所有left node，必定满足min< left < root, 对于所有right node，必定满足 root < right < max
 or
 inorder transverse --- 利用二叉树在inorder情况下，必定是升序的特性
 1、二叉查找树中序遍历一定是一个递增的序列，判断它是否是合法的二叉查找树(BST)，可采用中序遍历算法，记录上一个结点lastnode，如果存在上一个结点的值大于当前结点值，则false；
 
 ###代码实现
 ***有什么要注意的地方
 参考注释代码
 ***有什么要优化的地方
 
 ###时空复杂度
 time O(n)
 space O(1)
 
 ###相关的题目有哪些
 */
