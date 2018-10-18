//
//  main.cpp
//  Lintcode-36
//
//  Created by JINGLUO on 18/10/18.
//  Copyright © 2018 JINGLUO. All rights reserved.
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

ListNode *revertListNode(ListNode *node) {
    ListNode *pre = NULL;
    ListNode *next = NULL;
    while (node) {
        next = node->next;
        node->next = pre;
        pre = node;
        node = next;
    }
    
    return pre;
}

ListNode * reverseBetween(ListNode * head, int m, int n) {
    if (!head) {
        return NULL;
    }
    if (m == n) {
        return head;
    }
    ListNode *needRevertList = NULL, *lastNode = NULL;
    int index = 1;
    ListNode *temp = head;
    ListNode *firstBreakList = NULL, *secondBreakList = NULL;
    while (temp) {
        if (index+1 == m) {
            firstBreakList = temp;
        } else if (index == m) {
            // 分配了temp及其后面的所有node给needRevertList
            needRevertList = temp;
        } else if (index > m && index < n) {
            lastNode = temp;
        } else if (index == n) {
            secondBreakList = temp->next;
            // 到达n后，获得needRevertList的lasNode，将其置NULL截断，得到真正的needRevertList
            lastNode = temp;
            lastNode->next = NULL;
            break;
        }
        temp = temp->next;
        index += 1;
    }
    
    needRevertList = revertListNode(needRevertList);
    if (m > index) {
        needRevertList = head;
    }
    if (firstBreakList) {
        firstBreakList->next = needRevertList;
    } else {
        // 如果m==1，firstBreakList会为NULL，直接将needRevertList作为开头
        firstBreakList = needRevertList;
        head = firstBreakList;
    }
    while (needRevertList) {
        if (needRevertList->next) {
            needRevertList = needRevertList->next;
        } else {
            needRevertList->next = secondBreakList;
            break;
        }
    }
    return head;
}

int main(int argc, const char * argv[]) {
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    ListNode *e = new ListNode(5);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = NULL;
    std::cout << reverseBetween(a, 44, 4);
    return 0;
}


/*
 Soultion:
    找到第m-1(firstBreakList)、m、n、n+1(secondBreakList)四个节点，将m到n反转，拼接新的List：firstBreakList->(n...m)->secondBreakList
 
 注意一点：List这种结构，只要没有给这个Node指明新的pre，next关系，它原来的关联node就都还存在，与你对处于它中间的关联node做任何处理无关
 */
