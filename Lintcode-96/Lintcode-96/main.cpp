//
//  main.cpp
//  Lintcode-96
//
//  Created by Luo, Jing on 2/17/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Solution 1:
ListNode * partition1(ListNode * head, int x) {
    ListNode *dummySmallNode = new ListNode(0);
    ListNode *currSmall = NULL;

    ListNode *dummyLargeNode = new ListNode(0);
    ListNode *currLarge = NULL;

    ListNode *current = head;
    while (current) {
        if (current->val < x) {
            if (currSmall != NULL) {
                currSmall->next = current;
            } else {
                dummySmallNode->next = current;
            }
            currSmall = current;
        } else {
            if (currLarge != NULL) {
                currLarge->next = current;
            } else {
                dummyLargeNode->next = current;
            }
            currLarge = current;
        }
        current = current->next;
    }
    if (currLarge != NULL) { // 要考虑到currLarge为NULL的情况
        currLarge->next = NULL;
    }
    if (currSmall != NULL) { // 要考虑到currSmall为NULL的情况
        currSmall->next = dummyLargeNode->next;
        return dummySmallNode->next;
    } else {
        return dummyLargeNode->next;
    }
}

// Solution 2: Solution 1的简化版解法是一样的
ListNode * partition(ListNode * head, int x) {
    ListNode *dummySmallNode = new ListNode(0);
    ListNode *currSmall = dummySmallNode;
    
    ListNode *dummyLargeNode = new ListNode(0);
    ListNode *currLarge = dummyLargeNode;
    
    ListNode *current = head;
    while (current) {
        if (current->val < x) {
            currSmall->next = current;
            currSmall = current;
        } else {
            currLarge->next = current;
            currLarge = current;
        }
        current = current->next;
    }
    currLarge->next = NULL;
    currSmall->next = dummyLargeNode->next;
    return dummySmallNode->next;
}

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(4);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(2);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(2);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    
    ListNode *result = partition(node1, 0);
    std::cout << result << "\n";
    return 0;
}


/*
 
 Test case:
 
 case 1:
 null
 0
 
 case 2:
 1->4->3->2->5->2->null
 3
 
 case 3:
 1->0->3->null  // currLarge为NULL
 4
 
 case 4:
 2->5->7->1->null  // currSmall为NULL
 0
 
 */



/*
###算法
 1, 创建两个dummy node, 一个用来记录比x小的nodes，一个记录大于等于x的nodes
 2, Solution 1 需要注意根据currLarge或者currSmall有没有NULL，即case 3，4的情况，决定输出结果，拼接或者直接返回某一个。Solution 2 不需要考虑

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###时空复杂度
Time complexity: O(n)
Space complexity: O(1)

###相关的题目有哪些
174. Remove Nth Node From End of List
167. Add Two Numbers172. Remove Element
100. Remove Duplicates from Sorted Array
101. Remove Duplicates from Sorted Array II
1292. Odd Even Linked List
31. Partition Array
*/

