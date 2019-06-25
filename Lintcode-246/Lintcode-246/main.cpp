//
//  main.cpp
//  Lintcode-246
//
//  Created by JINGLUO on 25/6/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
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

std::vector<std::vector<int>> results;

void helper(TreeNode * root, int target, int level, std::vector<int> &result) {
    
    result.push_back(root->val);
    int temp = target;
    int i, j;
    for (i = level; i >= 0; i --) { // 对每一个level的点，都做一遍查找
        temp -= result[i];
        if (temp == 0) { // 找到目标值
            std::vector<int> tempResult;
            for ( j = i; j <= level; j ++) {
                tempResult.push_back(result[j]);
            }
            results.push_back(tempResult);
        }
    }
    if (root->left != NULL) {
        helper(root->left, target, level + 1, result);
        result.pop_back();
    }
    if (root->right != NULL) {
        helper(root->right, target, level + 1, result);
        result.pop_back();
    }
}

std::vector<std::vector<int>> binaryTreePathSum2(TreeNode * root, int target) {
    if (root == NULL) {
        return results;
    }
    std::vector<int> result;
    helper(root, target, 0, result);
    return results;
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(-2);
    TreeNode *node2 = new TreeNode(1);
    TreeNode *node3 = new TreeNode(2);

    root->left = node1;
    
    node1->left = node2;
    node2->left = node3;
    
    std::vector<std::vector<int>> result = binaryTreePathSum2(root, 2);
    std::cout << "Hello, World!\n";
    return 0;
}


/*
 ###算法
 先把每一條从根节点出发的路徑都加到result裡面來，同376
 從當前 level 一步一步往回推 當發現 target == 0
 把這串路徑做為答案 加入results

 ###代码实现
 ***有什么要注意的地方
 参考注释代码
 ***有什么要优化的地方
 
 ###时空复杂度
 time O(h的3次)？？？？
 space O(n)
 
 ###相关的题目有哪些
 Lintcode 376. Binary Tree Path Sum
 Lintcode 472. Binary Tree Path Sum III
 */

