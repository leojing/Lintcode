//
//  main.cpp
//  Lintcode-474
//
//  Created by JINGLUO on 25/9/18.
//  Copyright © 2018 JINGLUO. All rights reserved.
//

#include <iostream>

class ParentTreeNode {
public:
    int val;
    ParentTreeNode *left, *right, *parent;
    ParentTreeNode(int val, ParentTreeNode *parentNode) {
        this->val = val;
        this->parent = parentNode;
        this->left = this->right = NULL;
    }
};

int heightOfNode(ParentTreeNode * node) {
    int height = 0;
    while (node) {
        height ++;
        node = node->parent;
    }
    
    return height;
}

// This function returns pointer to LCA of two given values A and B.
// This function assumes that A and B are present in Binary Tree
ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B) {
    int heightA = heightOfNode(A);
    int heightB = heightOfNode(B);
    ParentTreeNode *p, *q;
    if (heightA > heightB) {
        p = A;
        q = B;
    } else {
        p = B;
        q = A;
    }
    
    int height = abs(heightA - heightB);
    while (height) {
        p = p->parent;
        height --;
    }
    
    while (p && q) {
        if (p == q) {
            return p;
        }
        p = p->parent;
        q = q->parent;
    }
    
    return NULL;
}

ParentTreeNode* newNode(int key, ParentTreeNode *parentNode)
{
    ParentTreeNode *temp = new ParentTreeNode(key, parentNode);
    temp->left = temp->right = NULL;
    return temp;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ParentTreeNode * root = newNode(1, NULL);
    ParentTreeNode * node2 = newNode(2, root);
    ParentTreeNode * node3 = newNode(3, root);
    root->left = node2;
    root->right = node3;
    ParentTreeNode * node4 = newNode(4, node2);
    ParentTreeNode * node5 = newNode(5, node2);
    node2->left = node4;
    node2->right = node5;
    
    ParentTreeNode * node6 = newNode(6, node3);
    ParentTreeNode * node7 = newNode(7, node3);
    node3->left = node6;
    node3->right = node7;
    std::cout << "LCA(4, 5) = " << lowestCommonAncestorII(root, node4, node5)->val << "\n";
    std::cout << "nLCA(4, 6) = " << lowestCommonAncestorII(root, node4, node6)->val << "\n";
    std::cout << "nLCA(3, 4) = " << lowestCommonAncestorII(root, node3, node4)->val << "\n";
    std::cout << "nLCA(2, 4) = " << lowestCommonAncestorII(root, node2, node4)->val << "\n";
    return 0;
}

/*
 The best solution:
 A little creativity is needed here. Since we have the parent pointer, we could easily get the distance (height) of both nodes from the root. Once we knew both heights, we could subtract from one another and get the height’s difference (dh). If you observe carefully from the previous solution, the node which is closer to the root is always dh steps ahead of the deeper node. We could eliminate the need of marking visited nodes altogether. Why?
 
 The reason is simple, if we advance the deeper node dh steps above, both nodes would be at the same depth. Then, we advance both nodes one level at a time. They would then eventually intersect at one node, which is the LCA of both nodes. If not, one of the node would eventually reach NULL (root’s parent), which we conclude that both nodes are not in the same tree. However, that part of code shouldn’t be reached, since the problem statement assumed that both nodes are in the same tree.
 
    https://articles.leetcode.com/lowest-common-ancestor-of-a-binary-tree-part-ii/
 */
