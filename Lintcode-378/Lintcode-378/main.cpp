//
//  main.cpp
//  Lintcode-378
//
//  Created by JINGLUO on 24/6/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

class DoublyListNode {
public:
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int val) {
        this->val = val;
        this->prev = this->next = NULL;
    }
};

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
// 先用inorder顺序transverse得到所有nodes
// 根据array顺序，生产DoublyListNode

void helper(TreeNode *root, std::vector<int> *array) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        array->push_back(root->val);
        return;
    }
    helper(root->left, array);
    array->push_back(root->val);
    helper(root->right, array);
}

DoublyListNode * bstToDoublyList(TreeNode * root) {
    if (root == NULL) {
        return NULL;
    }
    std::vector<int> array = std::vector<int>();
    helper(root, &array);
    DoublyListNode *result = new DoublyListNode(-1); // create a dummy first node
    DoublyListNode *temp = result;
    int i = 0;
    while (i < array.size()) {
        DoublyListNode *curr = new DoublyListNode(array[i]);
        curr->prev = temp;
        temp->next = curr;
        temp = curr;
        i ++;
    }
    return result->next;
}

// Solution 2:
// 不用额外开辟数组来按inorder顺序保存所有node
// 直接在transverse过程中生成DoublyListNode

DoublyListNode *result1 = new DoublyListNode(-1); // create a dummy first node
DoublyListNode *temp = result1;

void helper1(TreeNode * root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        DoublyListNode *curr = new DoublyListNode(root->val);
        curr->prev = temp;
        temp->next = curr;
        temp = curr;
        return;
    }
    helper1(root->left);
    DoublyListNode *curr = new DoublyListNode(root->val);
    curr->prev = temp;
    temp->next = curr;
    temp = curr;
    helper1(root->right);
}

DoublyListNode * bstToDoublyList1(TreeNode * root) {
    if (root == NULL) {
        return NULL;
    }
    helper1(root);
    return result1->next;
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(4);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(5);
    TreeNode *node3 = new TreeNode(1);
    TreeNode *node4 = new TreeNode(3);
    
    root->left = node1;
    root->right = node2;
    
    node1->left = node3;
    node1->right = node4;
    
    DoublyListNode *result = bstToDoublyList(root);
    DoublyListNode *result1 = bstToDoublyList1(root);
    std::cout << result << result1 <<"\n";
    return 0;
}


/*
 ###算法
 Recursion, inorderz
 
 ###代码实现
 ***有什么要注意的地方
 参考注释代码
 ***有什么要优化的地方
 
 ###时空复杂度
 time O(n), binary tree的inorder遍历
 space O(n)
 
 ###相关的题目有哪些
 Lintcode 242. Convert Binary Tree to Linked Lists by Depth
 Lintcode 453. Flatten Binary Tree to Linked List
 Lintcode 106. Convert Sorted List to Binary Search Tree
 */
