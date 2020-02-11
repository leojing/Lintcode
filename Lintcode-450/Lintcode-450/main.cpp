//
//  main.cpp
//  Lintcode-450
//
//  Created by Luo, Jing on 2/9/20.
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

ListNode * helper(ListNode * head, int k) {
    ListNode *nk = head;
    for (int i = 0; i < k; i ++) {
        if (nk == NULL) { // 当剩余未翻转的node个数不足k个时，不需要再翻转，直接返回
            return NULL;
        }
        nk = nk->next;
    }
    
    if (nk == NULL) {
        return NULL;  // 注意这里要返回NULL，而不是任何ListNode，表面head之后的不需要做任何翻转，在reverseKGroup（）中会做处理
    }
    
    // reverse
    ListNode *n1 = head->next;
    ListNode *nkplus = nk->next;
    ListNode *temp = NULL;
    
    ListNode *prev = NULL;
    ListNode *cur = n1;
    while (cur != nkplus) {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    
    // connect
    head->next = nk;
    n1->next = nkplus;
    return n1;
}

ListNode * reverseKGroup(ListNode * head, int k) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    head = dummy;
    while (head) {
        head = helper(head, k);
        if (head == NULL) {
            break;
        }
    }
    return dummy->next;
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
    std::cout << reverseKGroup(node1, 3) << "\n";
    return 0;
}

/*
###算法
 1, 首先要创建一个dummy node, 永远指向链表的头结点，最后返回的是dummy.next
 2, 在翻转特定范围里的链表时，我们可以考虑在每次翻转之后得到新的head, head 永远都指向下一个要翻转的链表范围的头结点。当head == none 时，则跳出while 循环，并返回dummy.next
 3, 对于翻转部分(n1 ~ nk), n1 = head.next, nk = head,要首先看看在从n1走k步的过程中会不会碰到none,如果碰到，说明已经到末尾，则直接返回none,该部分不用翻转。否则，找到nk之后的点nkplus = nk.next, 然后按照模板reverse (n1~nk)部分，最后要把head 节点和nkplus 与reversed后的链表connect起来

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###时空复杂度
Time complexity: O(n)
Space complexity: O(1)

###相关的题目有哪些
767. Reverse Array
451. Swap Nodes in Pairs
170. Rotate List
36. Reverse Linked List II
35. Reverse Linked List
*/
