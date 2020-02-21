//
//  main.cpp
//  Lintcode-511
//
//  Created by Luo, Jing on 2/19/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>
#include <set>

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

// Solution 1

ListNode * swapNodes(ListNode * head, int v1, int v2) {
    // Test case1
    if (head == NULL) {
        return head;
    }
    ListNode *firstKeyNode = NULL;
    ListNode *secondKeyNode = NULL;
    ListNode *firstPreNode = NULL;
    ListNode *secondPreNode = NULL;
    ListNode *dummy = new ListNode(INT_MAX);
    dummy->next = head;
    
    ListNode *current = dummy;
    // Find two key nodes
    while (current) {
        if (current->next == NULL) {
            break;
        }
        if (current->next->val == v1 || current->next->val == v2) {
            if (firstKeyNode == NULL) {
                firstKeyNode = current->next;
                firstPreNode = current;
            } else if (secondKeyNode == NULL) {
                secondKeyNode = current->next;
                secondPreNode = current;
            }
        }
        current = current->next;
    }
    
    // Test case2
    if (firstKeyNode == NULL || secondKeyNode == NULL) {
        return dummy->next;
    }
    
    ListNode *temp = secondKeyNode->next;
    // Test case3
    // Swap: if first and second are next to each other
    if (firstKeyNode->next == secondKeyNode) {
        firstPreNode->next = secondKeyNode;
        secondKeyNode->next = firstKeyNode;
        firstKeyNode->next = temp;
        return dummy->next;
    }

    // Test case4
    // Swap: if first and second are not next to each other
    firstPreNode->next = secondKeyNode;
    secondKeyNode->next = firstKeyNode->next;
    secondPreNode->next = firstKeyNode;
    firstKeyNode->next = temp;
    return dummy->next;
}


//Solution 2: Swap values not nodes, it's not allowed by the problem description.

ListNode * swapNodes2(ListNode * head, int v1, int v2) {
    if (head == NULL) {
        return head;
    }
    ListNode *current = head;
    bool isV1Exist = false;
    bool isV2Exist = false;
    while (current) {
        if (current->val == v1) {
            isV1Exist = true;
        } else if (current->val == v2) {
            isV2Exist = true;
        }
        current = current->next;
    }
    if (!isV1Exist || !isV2Exist) {
        return head;
    }
    current = head;
    while (current) {
        if (current->val == v1) {
            current->val = v2;
        } else if (current->val == v2) {
            current->val = v1;
        }
        current = current->next;
    }
    return head;
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
    ListNode *result = swapNodes(node1, 1, 2);
    std::cout << "Hello, World!\n";
    return 0;
}

/*
 Test case1:
 null
 2,5
 
 Test case2:
 1->2->null
 2,4
 
 Test case3:
 1->2->3->4->null
 2,3
 
 Test case4:
 1->2->3->4->null
 2,4
 
 */


/*
###算法
 Solution 1:
 1, 首先要创建一个dummy node, 永远指向链表的头结点，最后返回的是dummy.next
 2, 找到v1, v2对应的nodes，根据不同情况，可分为v1、v2相邻和不相邻，需要单独处理翻转的算法

 Solution 2:
 直接找到对应的点，替换value，题目中明确不可以用这种投机取巧的方法
 
###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###时空复杂度
Time complexity: O(n)
Space complexity: O(1)

###相关的题目有哪些
451. Swap Nodes in Pairs
*/
