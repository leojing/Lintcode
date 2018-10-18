//
//  main.cpp
//  Lintcode-223
//
//  Created by JINGLUO on 17/10/18.
//  Copyright © 2018 JINGLUO. All rights reserved.
//

#include <iostream>

//Definition of singly-linked-list:
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

bool isPalindrome(ListNode * head) {
    if (!head || !head->next) {
        return true;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    // 寻找中间节点，fast指针走两步，slow指针走一步
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    // 将后半部分反转
    ListNode *secondHalf = revertListNode(slow->next);
    // 对比前后半部分ListNode，一样就返回true
    while (secondHalf) {
        if (secondHalf->val != head->val) {
            return false;
        }
        head = head->next;
        secondHalf = secondHalf->next;
    }
    return true;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *a = new ListNode(2);
    ListNode *b = new ListNode(3);
//    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(3);
    ListNode *e = new ListNode(22);
    a->next = b;
    b->next = d;
    d->next = e;
    e->next = NULL;
    std::cout << "Palindrome is " << isPalindrome(NULL) << "\n";
    return 0;
}
