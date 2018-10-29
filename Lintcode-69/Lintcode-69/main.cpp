//
//  main.cpp
//  Lintcode-69
//
//  Created by JINGLUO on 30/10/18.
//  Copyright © 2018 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

std::vector<std::vector<int>> levelOrder(TreeNode * root) {
    std::vector<std::vector<int>> result;

    if (root == NULL) return result;

    std::queue<TreeNode *> q;
    std::vector<int> temp;
    
    int size = 1;
    q.push(root);
    while (q.size() > 0) {
        if (size > 0) {
            TreeNode *node = q.front();
            temp.push_back(node->val);
            q.pop();
            
            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
            
            size -= 1;
            if (size == 0) {
                result.push_back(temp);
                temp.clear();
                size = q.size();
            }
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    TreeNode *a = new TreeNode(3);
    TreeNode *b = new TreeNode(9);
    TreeNode *c = new TreeNode(20);
    TreeNode *d = new TreeNode(15);
    TreeNode *e = new TreeNode(7);
    a->left = b;
    a->right = c;
    c->left = d;
    c->right = e;
    std::vector<std::vector<int>> result = levelOrder(a);
    std::cout << &result << "\n";
    return 0;
}


/*
 Solution 1:
 BFS
 二叉树的层次遍历通过队列来进行，先将root进队，进入循环。
 判断队列是否为空，记录size为队列中元素的个数，表示这一层级有多少个元素，不为空将此时队列中的元素一个一个出队，同时将子女入队。
 这样每次出队的元素都为一个层次中的。
 */
