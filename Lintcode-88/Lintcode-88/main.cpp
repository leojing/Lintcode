//
//  main.cpp
//  Lintcode-88
//
//  Created by JINGLUO on 23/9/18.
//  Copyright © 2018 JINGLUO. All rights reserved.
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

// This function returns pointer to LCA of two given values A and B.
// This function assumes that A and B are present in Binary Tree
TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
    // Base case
    if (root == NULL) return NULL;
    
    // If either A or B matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->val == A->val || root->val == B->val) {
        return root;
    }
    
    // Look for keys in left and right subtrees
    TreeNode *left = lowestCommonAncestor(root->left, A, B);
    TreeNode *right = lowestCommonAncestor(root->right, A, B);
    
    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left && right) {
        return root;
    }
    
    // Otherwise check if left subtree or right subtree is LCA
    return (left != NULL) ? left : right;
}

TreeNode* newNode(int key)
{
    TreeNode *temp = new TreeNode(key);
    temp->left = temp->right = NULL;
    return temp;
}

int main(int argc, const char * argv[]) {
    TreeNode * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    std::cout << "LCA(4, 5) = " << lowestCommonAncestor(root, newNode(4), newNode(5))->val << "\n";
    std::cout << "nLCA(4, 6) = " << lowestCommonAncestor(root, newNode(4), newNode(6))->val << "\n";
    std::cout << "nLCA(3, 4) = " << lowestCommonAncestor(root, newNode(3), newNode(4))->val << "\n";
    std::cout << "nLCA(2, 4) = " << lowestCommonAncestor(root, newNode(2), newNode(4))->val << "\n";
    return 0;
}
