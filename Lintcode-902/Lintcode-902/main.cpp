//
//  main.cpp
//  Lintcode-902
//
//  Created by Jing LUO on 30/7/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <map>

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

// Solution 1:

int countNodes(TreeNode * root, std::map<TreeNode *, int> &numberOfChildren) {
    if (root == NULL) {
        return 0;
    }
    int left = countNodes(root->left, numberOfChildren);
    int right = countNodes(root->right, numberOfChildren);
    numberOfChildren[root] = left + right + 1;
    return left + right + 1;
}

int quickSelect(TreeNode * root, int k, std::map<TreeNode *, int> &numberOfChildren) {
    if (root == NULL) {
        return -1;
    }

    int left = 0;
    if (root->left != NULL) {
        left = numberOfChildren[root->left];
    }
    if (left >= k) {
        return quickSelect(root->left, k, numberOfChildren);
    }
    if (left + 1 == k) {
        return root->val;
    }
    return quickSelect(root->right, k-left-1, numberOfChildren);
}

int kthSmallest(TreeNode * root, int k) {
    std::map<TreeNode *, int> numberOfChildren;
    countNodes(root, numberOfChildren);
    return quickSelect(root, k, numberOfChildren);
}

// Solution 2: Inorder tranversal

int count = 0;
TreeNode *result;

void helper(TreeNode * root, int k) {
    if (root == NULL) {
        return;
    }
    helper(root->left, k);
    count ++;
    if (count == k) {
        result = root;
        return;
    }
    helper(root->right, k);
}

int kthSmallest2(TreeNode * root, int k) {
    helper(root, k);
    return result->val;
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(2);
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(3);
    root->left = node1;
    root->right = node2;
    std::cout << kthSmallest(root, 3) << "\n";
    std::cout << kthSmallest2(root, 3) << "\n";
    return 0;
}


//Challenge
//What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?


/*
Solution 1:

###算法
类似二分搜索
算法思想类似于Quick Select，这个算法的好处是，如果多次查询的话，给每个节点统计儿子个数这个过程只需要做一次。查询可以很快。
可以解决Challenge

###代码实现
***有什么要注意的地方
***有什么要优化的地方

###时空复杂度
time O(n)+O(logn) -> O(n) for best case(balanced binary tree)
     O(n)+O(n) -> O(n) for worst case(chain like binary tree)
so in general, best and worst are both O(n)+O(h), which means O(n)

space O(n)

###相关的题目有哪些
67. Binary Tree Inorder Traversal
1094. Second Minimum Node In a Binary Tree
*/


/*
Solution 2:

###算法
递归中序遍历，但是很容易stack overflow，比如chain like binary tree
不可以解决Challenge

###代码实现
***有什么要注意的地方
***有什么要优化的地方

###时空复杂度
time O(n)
space O(n)

###相关的题目有哪些
67. Binary Tree Inorder Traversal
1094. Second Minimum Node In a Binary Tree
*/
