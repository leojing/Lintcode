//
//  main.cpp
//  Lintcode-98
//
//  Created by Luo, Jing on 11/3/20.
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

ListNode * connectLists(ListNode *left, ListNode *mid, ListNode *right) {
    ListNode *dummy = new ListNode(0);
    ListNode *current = NULL;
    // 要注意考虑left为NULL的情况
    if (left != NULL) {
        dummy->next = left;
        ListNode *leftTail = left;
        while (leftTail) {
            if (leftTail->next == NULL) {
                break;
            }
            leftTail = leftTail->next;
        }
        current = leftTail;
    } else {
        current = dummy;
    }
    // 要注意考虑mid为NULL的情况
    if (mid != NULL) {
        ListNode *midTail = mid;
        while (midTail) {
            if (midTail->next == NULL) {
                break;
            }
            midTail = midTail->next;
        }
        current->next = mid;
        current = midTail;
    }
    current->next = right;
    return dummy->next;
}

ListNode * findMid(ListNode * head) {
    ListNode *fast, *slow = NULL;
    while (head && head->next) {
        slow = head->next;
        fast = head->next->next;
        head = head->next;
    }
    return slow;
}

// 思路是quick sort
// 建立3个list，leftDummy是所有比mid值小的nodes，midDummy是所有和mid相等的nodes，rightDummy是所有比mid大的nodes。
// 然后进行递归拼接，先divide，再conquer
ListNode * sortList(ListNode * head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    ListNode *leftDummy = new ListNode(0);
    ListNode *leftTail = leftDummy;
    ListNode *rightDummy = new ListNode(0), *rightTail = rightDummy;
    ListNode *midDummy = new ListNode(0), *midTail = midDummy;
    
    // 找到mid作为pivot
    ListNode *mid = findMid(head);
    
    while (head) {
        if (head->val < mid->val) {
            // 建立小于mid的list
            leftTail->next = head;
            leftTail = leftTail->next;
        } else if ((head->val > mid->val)) {
            // 建立大于mid的list
            rightTail->next = head;
            rightTail = rightTail->next;
        } else {
            // 此处之所以用mid的list是因为要考虑到与mid值相等的node可能有很多个的情况
            midTail->next = head;
            midTail = midTail->next;
        }
        head = head->next;
    }
    // 注意⚠️：这里要将tail截断，不如会跟着后面其他乱序的nodes
    leftTail->next = NULL;
    rightTail->next = NULL;
    midTail->next = NULL;
    
    // 递归得到left和right list
    ListNode *left = sortList(leftDummy->next);
    ListNode *right = sortList(rightDummy->next);
    // 将left，mid，right 三个list进行拼接
    return connectLists(left, midDummy->next, right);
}

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(12);
    ListNode *node2 = new ListNode(42);
    ListNode *node3 = new ListNode(33);
    ListNode *node4 = new ListNode(42);
    ListNode *node5 = new ListNode(15);
    ListNode *node6 = new ListNode(296);
    ListNode *node7 = new ListNode(67);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    ListNode *result = sortList(node1);
    return 0;
}


/*
###算法
 1. 思路是quick sort
 2. 建立3个list，leftDummy是所有比mid值小的nodes，midDummy是所有和mid相等的nodes，rightDummy是所有比mid大的nodes。
 3. 然后进行递归拼接，先divide，再conquer

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###时空复杂度
Time complexity: O(NLogN), N为head的长度
Space complexity: O(1),没有开辟额外的容器来存放nodes，只是建立新的Listnode

###相关的题目有哪些
173. Insertion Sort List
*/
