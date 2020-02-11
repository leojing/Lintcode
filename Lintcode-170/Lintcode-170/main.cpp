//
//  main.cpp
//  Lintcode-170
//
//  Created by Luo, Jing on 2/11/20.
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

ListNode * rotateRight(ListNode * head, int k) {
    if (k == 0 || head == NULL) {
        return head;
    }
    int count = 0;
    ListNode *temp = head;
    ListNode *lastNode = NULL;
    while (temp) {
        count ++;
        lastNode = temp;  // Find last node as need to connect it with head.
        temp = temp->next;
    }
    // Consider for the case k > count, after rotate full rounds(nothing changes), need to rotate for rest k % count nodes.
    k = k % count;
    // After modulo operation, make the cases downsize to only 0 and k < count.
    if (k == 0) {
        return head;
    }
    temp = head;
    ListNode *newHead = NULL;
    int index = 0;
    // Find the break point
    while (index < count - k - 1) {
        temp = temp->next;
        index ++;
    }
    // Rotate two lists and connect them with new order
    newHead = temp->next;
    temp->next = NULL;
    lastNode->next = head;
    return newHead;
}

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(6);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    ListNode *resultNode = rotateRight(node1, 5);
    std::cout << resultNode << "\n";
    return 0;
}

/*
Test case:
k = 0
k < count
k = count
k > count
Do modulo operation, then the actual cases need to handle only 0 and < count
 
head == null
*/


/*
###算法
模拟题
 
###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###时空复杂度
Time complexity: O(n)
Space complexity: O(1)

###相关的题目有哪些
671. Rotate words
1334. Rotate Array
1790. Reverse String II
8. Rotate string
*/
