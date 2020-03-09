//
//  main.cpp
//  Lintcode-99
//
//  Created by Luo, Jing on 9/3/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>

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

// Solution 1:
void reorderList1(ListNode * head) {
    if (head == NULL) {
        return;
    }
    stack<ListNode *> stack;
    queue<ListNode *> queue;
    while (head) {
        stack.push(head);
        queue.push(head);
        head = head->next;
    }
    int count = int(stack.size());
    int half = count/2;
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;
    while (half --) {
        ListNode *first = queue.front();
        ListNode *second = stack.top();
        queue.pop();
        stack.pop();
        current->next = first;
        current = current->next;
        current->next = second;
        current = current->next;
    }
    if (count % 2 == 1) {
        ListNode *last = queue.front();
        last->next = NULL;
        current->next = last;
    } else {
        current->next = NULL;
    }
}

// Solution 2:
ListNode *reverseListNode(ListNode * head) {
    ListNode *temp = NULL, *current = head, *pre = NULL;
    while (current) {
        temp = current->next;
        current->next = pre;
        pre = current;
        current = temp;
    }
    return pre;
}

ListNode *findMid(ListNode * head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

void reorderList(ListNode * head) {
    ListNode *mid = findMid(head);
    ListNode *secondHalf = reverseListNode(mid);
    ListNode *leftTemp, *rightTemp;
    while (secondHalf) {
        leftTemp = head->next;
        rightTemp = secondHalf->next;
        head->next = secondHalf;
        head = leftTemp;
        secondHalf->next = head;
        secondHalf = rightTemp;
    }
    if (head) {
        head->next = NULL;
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

    reorderList(node1);
    return 0;
}



/*
###算法
 Solution 1:
 1, 用stack和queue分别存下所有节点
 2, 然后根据stack先进后出，queue先进先出的特别，去除前后对应的点，进行拼接

 Solution 2:
 1. 找中点，快慢指针，慢指针最后指向的节点一定是不会reorder的前半部分的最后一个，同样可以知道慢指针的下一个一定是需要reorder部分的第一个节点
 2. 将需要reorder的右半部分reverse，便于不断逼近中点
 3. 合并两段链表
 
###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###时空复杂度
Time complexity: O(n)
Space complexity: solution 1为O(n),因为开辟了stack和queue用于存放nodes，solution 2为O(1)

###相关的题目有哪些
*/
