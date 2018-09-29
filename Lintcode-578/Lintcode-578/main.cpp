//
//  main.cpp
//  Lintcode-578
//
//  Created by JINGLUO on 26/9/18.
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

bool foundA = false, foundB = false;

TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
    if (root == NULL) return NULL;
    
    TreeNode *left = lowestCommonAncestor(root->left, A, B);
    TreeNode *right = lowestCommonAncestor(root->right, A, B);
    
    if (root->val == A->val || root->val == B->val) {
        foundA = (root->val == A->val) || foundA;
        foundB = (root->val == B->val) || foundB;
        return root;
    }

    if (left && right) {
        return root;
    }
    
    return (left != NULL) ? left : right;
}

TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
    TreeNode  *result = lowestCommonAncestor(root, A, B);
    if (foundA && foundB) {
        return result;
    }
    return NULL;
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
    foundA = false;
    foundB = false;
    std::cout << "LCA(4, 5) = " << lowestCommonAncestor3(root, newNode(4), newNode(5))->val << "\n";
    
    foundA = false;
    foundB = false;
    std::cout << "nLCA(4, 6) = " << lowestCommonAncestor3(root, newNode(4), newNode(6))->val << "\n";
    
    foundA = false;
    foundB = false;
    std::cout << "nLCA(3, 4) = " << lowestCommonAncestor3(root, newNode(3), newNode(4))->val << "\n";
    
    foundA = false;
    foundB = false;
    std::cout << "nLCA(9, 4) = " << lowestCommonAncestor3(root, newNode(9), newNode(2))->val << "\n";
    return 0;
}



/*
 Similar to 88
 
 这题和 LCA 原题的区别主要是要找的 A 和 B 可能并不存在树里。所以我们要做出这两个改变
 
 用全局变量把 A 和 B 是否找到保存起来。最后在 main function 里面要查看是否都找到
 当 root 等于 A 或者 B 时不能直接返回root了。原题可以直接返回是因为两个 node 是保证存在的所以这情况下 LCA 一定是 root。
 现在 root 等于 A 或者 B 我们还是要继续往下找是否存在另外的一个
 不用 ResultType 的一个好处是：如果面试的时候出了一个原题，然后问这题做 follow up。如果从头开始写 result type 代码改动会比较大。一是比较容易写错，二是时间可能会不够。
 
 这个方法只需要增加两个全局变量并且改动 LCA 原题的代码两行即可。
 
 */

/*
 ResultType soultion
 

class ResultType {
public:
    bool a_exist, b_exist;
    TreeNode* node;
    ResultType(bool a, bool b, TreeNode* n) {
        a_exist = a;
        b_exist = b;
        node = n;
    }
};

TreeNode *lowestCommonAncestor3(TreeNode* root, TreeNode* A, TreeNode* B) {
    // write your code here
    ResultType rt = helper(root, A, B);
    if (rt.a_exist && rt.b_exist)
        return rt.node;
    else
        return NULL;
}

ResultType helper(TreeNode* root, TreeNode* A, TreeNode* B) {
    if (root == NULL)
        return ResultType(false, false, NULL);
    
    ResultType left_rt = helper(root->left, A, B);
    ResultType right_rt = helper(root->right, A, B);
    
    bool a_exist = left_rt.a_exist || right_rt.a_exist || root == A;
    bool b_exist = left_rt.b_exist || right_rt.b_exist || root == B;
    
    if (root == A || root == B)
        return ResultType(a_exist, b_exist, root);
    
    if (left_rt.node != NULL && right_rt.node != NULL)
        return ResultType(a_exist, b_exist, root);
    if (left_rt.node != NULL)
        return ResultType(a_exist, b_exist, left_rt.node);
    if (right_rt.node != NULL)
        return ResultType(a_exist, b_exist, right_rt.node);
    
    return ResultType(a_exist, b_exist, NULL);
}

*/
