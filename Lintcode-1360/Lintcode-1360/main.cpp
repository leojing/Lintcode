//
//  main.cpp
//  Lintcode-1360
//
//  Created by Jing LUO on 26/9/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>

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

// Solution 1: 中序遍历法
void serializeTree(TreeNode * root, vector<string> *treeNodes) {
    if (root == NULL) {
        treeNodes->push_back("#"); // 为了保证得到的序列化数组不会丢失树中间的NULL，NULL用#代替
        return;
    }
    serializeTree(root->left, treeNodes);
    treeNodes->push_back(to_string(root->val));
    serializeTree(root->right, treeNodes);
}

bool isSymmetric1(TreeNode * root) {
    vector<string> treeNodes;
    serializeTree(root, &treeNodes);
    int nodeCount = int(treeNodes.size());
    for (int i = 0; i < nodeCount >> 1; i ++) {
        if (treeNodes[i] != treeNodes[nodeCount-1-i]) {
            return false;
        }
    }
    return true;
}

// Solution 2: 递归
bool helper(TreeNode *left, TreeNode *right) {
    if (left == NULL && right == NULL) {  // 两边都是NULL，也是相等，返回true
        return true;
    }
    if (left != NULL && right != NULL) {  // 两边不为NULL，如果相等，返回true，否则返回false
        if (left->val == right->val) {
            if (helper(left->left, right->right) && helper(left->right, right->left)) {
                return true;
            }
        }
        return false;
    }
    return false;  // 其中一边为NULL，直接返回false
}

bool isSymmetric(TreeNode * root) {
    if (root == NULL) {
        return true;
    }
    return helper(root->left, root->right);
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
//    TreeNode *node4 = new TreeNode(4);
//    TreeNode *node5 = new TreeNode(4);
    TreeNode *node6 = new TreeNode(3);
//    TreeNode *node7 = new TreeNode(1);

    root->left = node1;
    root->right = node2;

    node1->left = node3;
//    node1->right = node4;

//    node2->left = node5;
    node2->right = node6;

    std::cout << isSymmetric(root) << "\n";
    return 0;
}



/*
###算法
中序遍历/递归

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###时空复杂度
Time complexity: O(n)，n为node个数
Space complexity: solution 1为O(n)，solution 2为O(1)

###相关的题目有哪些
*/

