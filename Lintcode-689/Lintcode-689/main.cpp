//
//  main.cpp
//  Lintcode-689
//
//  Created by Jing LUO on 10/7/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
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

bool exsitNode(TreeNode * root, int target) {
    if (root == NULL) {
        return false;
    }
    if (root->val == target) {
        return true;
    }
    
    return exsitNode(root->left, target) || exsitNode(root->right, target);
}

std::vector<int> helper(TreeNode * root, int n) {
    std::vector<int> result;
    if (root == NULL) {
        return result;
    }
    
    result.push_back(root->val);
    int target = n - root->val;
    if (target < root->val && exsitNode(root->left, target)) {
        result.push_back(n - root->val);
        return result;
    }
    if (target > root->val && exsitNode(root->right, target)) {
        result.push_back(n - root->val);
        return result;
    }
    
    std::vector<int> leftResult = helper(root->left, n);
    if (leftResult.size() > 0) {
        return leftResult;
    }
    
    std::vector<int> rightResult = helper(root->right, n);
    if (rightResult.size() > 0) {
        return rightResult;
    }
    
    return std::vector<int>();
}

std::vector<int> twoSum(TreeNode * root, int n) {
    return helper(root, n);
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(5);
    TreeNode *node3 = new TreeNode(1);
    TreeNode *node4 = new TreeNode(3);
    
    root->left = node1;
    root->right = node2;
    
    node1->left = node3;
    node1->right = node4;
    
    std::vector<int> result = twoSum(root, 9);
    std::cout << result.size() << "\n";
    return 0;
}
