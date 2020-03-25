//
//  main.cpp
//  Lintcode-106
//
//  Created by Luo, Jing on 16/3/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
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

// Time: O(N), Space: O(N)
vector<int> flatListNode(ListNode * head) {
    vector<int> result;
    while (head) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

// Time: O(logN), Space: O(logN)
TreeNode * makeTreeNode(vector<int> nodes, int start, int end) {
    if (end < start) {
        return NULL;
    }
    int mid = start + (end-start)/2;
    TreeNode *root = new TreeNode(nodes[mid]);
    if (mid == start) {
        root->left = NULL;
        TreeNode *right = makeTreeNode(nodes, mid+1, end);
        root->right = right;
    } else if (mid == end) {
        root->right = NULL;
        TreeNode *left = makeTreeNode(nodes, start, mid-1);
        root->left = left;
    } else {
        TreeNode *left = makeTreeNode(nodes, start, mid-1);
        TreeNode *right = makeTreeNode(nodes, mid+1, end);
        root->left = left;
        root->right = right;
    }
    return root;
}

TreeNode * sortedListToBST1(ListNode * head) {
    if (head == NULL) {
        return NULL;
    }
    vector<int> nodes = flatListNode(head);
    int length = int(nodes.size());
    return makeTreeNode(nodes, 0, length-1);
}

// Soultion 3:

ListNode *mainHead;

// Time: O(N), Space: O(1)
int findListSize(ListNode * head) {
    int count = 0;
    while (head) {
        head = head->next;
        count ++;
    }
    return count;
}

// Time: O(logN), Space: O(logN)
TreeNode * convertToTreeNode(int start, int end) {
    if (start > end) {
        return NULL;
    }
    if (mainHead == NULL) {
        return NULL;
    }
    
    int mid = start + (end - start)/2;
    TreeNode *left = convertToTreeNode(start, mid-1);
    
    TreeNode *current = new TreeNode(mainHead->val);
    current->left = left;
    
    mainHead = mainHead->next;
    TreeNode *right = convertToTreeNode(mid+1, end);
    current->right = right;
    
    return current;
}

TreeNode * sortedListToBST(ListNode * head) {
    if (head == NULL) {
        return NULL;
    }
    mainHead = head;
    int size = findListSize(head);
    return convertToTreeNode(0, size-1);
}

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(6);
    ListNode *node7 = new ListNode(7);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    TreeNode *result1 = sortedListToBST1(node1);
    TreeNode *result = sortedListToBST(node1);
    return 0;
}

/*
###算法
 Solution 1:
 Recursion + exra space, convert list to array
 reduce time but increase space
 ###时空复杂度
 Time Complexity: The time complexity comes down to just O(N) now since we convert the linked list to an array initially and then we convert the array into a BST. Accessing the middle element now takes O(1) time and hence the time complexity comes down.
 Space Complexity: Since we used extra space to bring down the time complexity, the space complexity now goes up to O(N) This is due to the array we construct initially.

 Solution 2:
 Recursion
 本题先利用快慢指针找到链表的中点，然后把中点之前的链表断开，让中点做treeNode，
 递归， 让left部分为前一半链表做成的BST， right为后一半链表做成的BST，可以基本保持平衡
 def sortedListToBST(self, head) --> return head of BST
 注意这里的 find middle 不同于 https://www.lintcode.com/problem/middle-of-linked-list/description?_from=ladder&&fromId=1 template, 找到middle 要在它之前break，所以需要 prev, 对于这种情况 1->2, 选择2 作为mid,在之前break类似 https://www.lintcode.com/problem/middle-of-the-linked-list/description

 易错点 1-> 2 这种情况，选择2 作为middle_head返回，这样才能断开成 1 和 2， 如果选择1 作为middle_head，会出现死循环。 因此有以下：
 def find_middle(self, head): 模版中， 其中 应该是 fast = head 而不是 fast = head .next
 易错点
 def sortedListToBST(self, head) 要做 以下
 if head.next is None:
 return TreeNode(head.val)
 否则 middle_head = self.find_middle(head) 出现死循环
 
 ###时空复杂度
 Time Complexity: O(NlogN)，bst 总共logn层，每一层花费 n时间去找 middle of linked list
 Space Complexity: O(logN). Since we are resorting to recursion, there is always the added space complexity of the recursion stack that comes into picture. This could have been O(N) for a skewed tree, but the question clearly states that we need to maintain the height balanced property. This ensures the height of the tree to be bounded by O(logN). Hence, the space complexity is O(logN).
 
 Solution 3:
 inorder + recursion
 
 ###时空复杂度
 time O(n)
 space O(logn)
 https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/solution/
 
###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###相关的题目有哪些
453. Flatten Binary Tree to Linked List
177. Convert Sorted Array to Binary Search Tree With Minimal Height
378. Convert Binary Tree to Doubly Linked List
*/
