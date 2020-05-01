//
//  main.cpp
//  Lintcode-167
//
//  Created by Jing Luo on 5/1/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
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

ListNode * addLists(ListNode * l1, ListNode * l2) {
    if (l1 == NULL && l2 == NULL) { // Edge case, 0 + 0 = 0
        return new ListNode(0);
    }
    ListNode *result = NULL;
    ListNode *current = NULL;
    int mod = 0;
    int sum = 0;
    while (l1 != NULL || l2 != NULL) {
        int first = 0;
        if (l1 != NULL) {
            first = l1->val;
            l1 = l1->next;
        }
        int second = 0;
        if (l2 != NULL) {
            second = l2->val;
            l2 = l2->next;
        }
        sum = first + second + mod;
        mod = sum / 10;
        int dig = sum % 10;
        ListNode *temp = new ListNode(dig);
        if (result == NULL) {
            result = temp;
            current = result;
        } else {
            current->next = temp;
            current = current->next;
        }
    }
    if (sum / 10 != 0) {
        ListNode *temp = new ListNode(sum / 10);
        current->next = temp;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(9);
    ListNode *node2 = new ListNode(9);
//    ListNode *node3 = new ListNode(6);
    node1->next = node2;
//    node2->next = node3;
    
//    ListNode *node4 = new ListNode(5);
    ListNode *node5 = new ListNode(9);
//    ListNode *node6 = new ListNode(2);
//    ListNode *node7 = new ListNode(1);
//    node4->next = node5;
//    node5->next = node6;
//    node6->next = node7;

    ListNode *result = addLists(node1, node5);
    std::cout << "\n";
    return 0;
}

/* test case:
 l1 = null, l2 = null
 l1 = 999, l2 = 9, 要考虑最后一位进位的情况
 l1 = 11232, l2 = 32
 l1 = 222, l2 = 124
 */
