//
//  main.cpp
//  Lintcode-35
//
//  Created by Luo, Jing on 14/4/20.
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

ListNode * reverse(ListNode * head) {
    if (head == NULL) {
        return NULL;
    }
    ListNode *pre = NULL, *temp;
    while (head) {
        temp = head->next;
        head->next = pre;
        pre = head;
        head = temp;
    }
    return pre;
}

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    ListNode *result = reverse(node1);
    std::cout << result << "\n";
    return 0;
}
