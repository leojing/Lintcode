//
//  main.cpp
//  Lintcode-614
//
//  Created by JINGLUO on 1/7/19.
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

class ResultType {
public:
    int max_length, max_down, max_up;
    ResultType(int len, int down, int up) {
        max_length = len;
        max_down = down;
        max_up = up;
    }
};

ResultType helper(TreeNode * root) {
    if (root == NULL) {
        return ResultType(0, 0, 0);
    }
    
    ResultType left = helper(root->left);
    ResultType right = helper(root->right);
    
    int down = 0, up = 0;
    if (root->left && root->left->val + 1 == root->val) {
        down = std::max(down, left.max_down + 1);
    }
    if (root->left && root->left->val - 1 == root->val) {
        up = std::max(up, left.max_up + 1);
    }
    
    if (root->right && root->right->val + 1 == root->val) {
        down = std::max(down, right.max_down + 1);
    }
    if (root->right && root->right->val - 1 == root->val) {
        up = std::max(up, right.max_up + 1);
    }
    
    int len = down + up + 1;
    len = std::max(len, std::max(left.max_length, right.max_length));
    return ResultType(len, down, up);
}

int longestConsecutive2(TreeNode * root) {
    if (root == NULL) {
        return 0;
    }
    ResultType result = helper(root);
    return result.max_length;
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(0);
    TreeNode *node3 = new TreeNode(3);
    
    root->left = node1;
    root->right = node2;
    
    node1->left = node3;
    
    std::cout << longestConsecutive2(root) << "\n";
    return 0;
}



/*
 ###算法
 分治法 。本题是从任意节点到任意节点， 将其路径拆分为 up 和down，以当前路径为起始点往下（左右子树）走， 也可以以当前路径为终止点， 从下网上走。
 down 为以当前点为起始点，向下走得到的最大连续路径长度，以0 为初始值
 up 为以当前点为终点， 从下向上走得到的最大连续路径的长度， 以0为初始值
 1
 /
 2 0
 /
 3
 
 如图所示
 以1 为起点， down 为 1 -》 2 -》 3， up 为 0 =》 1
 以2 为起点， down 为 2 -》 3， up 为 0
 max_len = max(up + 1 + down, left_len, right_len)
 注意 同一起始点并且作为终止点，在同一路径上，指left 或者 right, left_up 和left down 是互斥的， right 也是
 
 递归函数helper 返回的是以root 为根节点的树中的最大连续路径长度，而不是 以root为起始点或者终止点的最大连续路径的长度，
 最大连续路径，不一定经过root
 
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

