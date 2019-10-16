//
//  main.cpp
//  Lintcode-165
//
//  Created by Jing LUO on 16/10/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>

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

ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
    // 注意NULL情况的判断
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    ListNode *l1Next = l1->next;
    ListNode *l2Next = l2->next;
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1Next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2Next);
        return l2;
    }
    return NULL;
}

int main(int argc, const char * argv[]) {
    ListNode *lRoot = new ListNode(4);
    ListNode *l1 = new ListNode(13);
    ListNode *l2 = new ListNode(23);
    ListNode *l3 = new ListNode(78);
    lRoot->next = l1;
    l1->next = l2;
    l2->next = l3;

    ListNode *rRoot = new ListNode(1);
    ListNode *r1 = new ListNode(3);
    ListNode *r2 = new ListNode(34);
    ListNode *r3 = new ListNode(75);
    rRoot->next = r1;
    r1->next = r2;
    r2->next = r3;

    ListNode * result = mergeTwoLists(lRoot, rRoot);
    std::cout << result << "\n";
    return 0;
}



/*
###算法
递归，当对第一个node的val进行大小判断后，就可取出一个node，然后它的next就是剩下的两个ListNode进行merge的结果，递归下去

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###时空复杂度
Time complexity: O(n+m), n为l1的长度，m为l2的长度
Space complexity: O(1)

###相关的题目有哪些
839. Merge two sorted interval lists
6. Merge two sorted arrays
*/


