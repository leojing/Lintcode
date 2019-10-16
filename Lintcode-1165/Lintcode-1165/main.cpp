//
//  main.cpp
//  Lintcode-1165
//
//  Created by Jing LUO on 16/10/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

// 递归遍历，每个结点只需遍历一次，故时间复杂度为O(m)（t的节点数）。而使用了递归，最差情况下递归调用的深度为O(m)，所以空间复杂度为O(m)。
bool isEqualTree(TreeNode *a, TreeNode *b) {
    if ((a == NULL && b != NULL) || (a != NULL && b == NULL)) {
        return false;
    }
    if (a == NULL && b == NULL) {
        return true;
    }
    if (a->val != b->val) {
        return false;
    }
    bool leftTree = isEqualTree(a->left, b->left);
    bool rightTree = isEqualTree(a->right, b->right);
    return leftTree && rightTree;
}

// 非递归遍历，每个结点只需遍历一次，故时间复杂度为O(n)（s的节点数）。而使用了栈，空间复杂度为二叉树的高度，故空间复杂度为O(n)。
bool isSubtree(TreeNode * s, TreeNode * t) {
    if (s == NULL || t == NULL) {
        return false;
    }
    stack<TreeNode *> trees;
    trees.push(s);
    while (!trees.empty()) {
        TreeNode *tree = trees.top();
        trees.pop();
        if (tree != NULL && tree->val == t->val) {
            if (isEqualTree(tree, t)) {
                return true;
            }
        }
        if (tree->left != NULL) {
            trees.push(tree->left);
        }
        if (tree->right != NULL) {
            trees.push(tree->right);
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(3);
    TreeNode *node1 = new TreeNode(4);
    TreeNode *node2 = new TreeNode(5);
    TreeNode *node3 = new TreeNode(1);
    TreeNode *node4 = new TreeNode(2);

    root->left = node1;
    root->right = node2;

    node1->left = node3;
    node1->right = node4;

    TreeNode *root1 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(1);
    TreeNode *node6 = new TreeNode(2);

    root1->left = node5;
    root1->right = node6;

    std::cout << isSubtree(root, root1) << "\n";
    return 0;
}



/*
###算法
二叉树遍历，遍历s的所有子节点，如果val和t的val一样，那么就判断s的这个subtree是否和t相等
二叉树分析：https://blog.csdn.net/u013309870/article/details/61207136

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###时空复杂度
Time complexity: O(n*m)，n为s的节点数，m为t节点数，具体分析参考代码注释
Space complexity: O(n*m)，n为s的节点数，m为t节点数，具体分析参考代码注释

###相关的题目有哪些
1198. Most frequent subtree sum
921. Count Univalue subtree
*/
