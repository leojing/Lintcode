//
//  main.cpp
//  Lintcode-760
//
//  Created by Jing Luo on 5/3/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

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

void help(TreeNode * root, map<int, int> &mapping, int depth) {
    if (root == NULL) {
        return;
    }
    // 因为是从左到右遍历，所以最后一个肯定是最右边看到的值
    mapping[depth] = root->val;
    help(root->left, mapping, depth+1);
    help(root->right, mapping, depth+1);
}

vector<int> rightSideView(TreeNode * root) {
    vector<int> result;
    map<int, int> mapping;
    int depth = 0;
    help(root, mapping, depth);
    while (mapping.find(depth) != mapping.end()) {
        result.push_back(mapping[depth]);
        depth ++;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(0);
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);

    root->left = node1;
    root->right = node2;
    
    node1->left = node3;
    
    node2->left = node4;
    node2->right = node5;
    
    vector<int> result = rightSideView(root);
    std::cout << result.size() << "\n";
    return 0;
}


/*
###算法
题意是从右边看过去，每一层看到能看到的数字，等于就是找每一层的最右边的值，dfs递归每一层，先找左边的，再找右边的，一直更新mapping[depth]的值，就是最右边的值
 
###时空复杂度
Time Complexity: O(n)
Space Complexity: O(n)

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/
