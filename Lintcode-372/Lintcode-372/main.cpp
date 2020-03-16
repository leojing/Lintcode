//
//  main.cpp
//  Lintcode-372
//
//  Created by Luo, Jing on 16/3/20.
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

// 注意审题，给的是要删除的节点，所以等于要用node的next节点代替node
void deleteNode(ListNode * node) {
    if (node == NULL) {
        return;
    }
    ListNode *next = node->next;
    if (next) {
        node->val = next->val;
        node->next = next->next;
    } else {
        node = NULL;
    }
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
    deleteNode(node3);
    return 0;
}
