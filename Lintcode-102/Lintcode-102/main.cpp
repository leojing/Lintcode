//
//  main.cpp
//  Lintcode-102
//
//  Created by JINGLUO on 23/10/18.
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

bool hasCycle(ListNode * head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    
    ListNode *fast = head->next->next;
    ListNode *slow = head->next;
    while (fast && slow && fast->next) {
        if (fast == slow) {
            return true;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}


/*
 Solution without using extra space:
    这个思路太巧妙了，用2个指针，一快（走2步）一慢（走y1步）去走，如果没有loop，则两者永远不会碰到，到结尾时返回false，如果有loop，两个指针必定会在某个节点遇到，则返回true。
    难点：还没想明白为什么一个走1步，一个走2步必定会遇到对方，如果是一个走1步，一个走3步，还能成立嘛？这个算数学思考，和hk讨论后，觉得是只要一快一慢，不管几步，总能遇见对方^_^
 */
