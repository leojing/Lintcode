//
//  main.cpp
//  Lintcode-104
//
//  Created by JINGLUO on 9/9/18.
//  Copyright © 2018 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

/* Soultion 1:
 二分法，将list不断拆分为2个list进行merge，最后list中剩余2个item的时候进行两两merge
 *************/

ListNode *mergeSortedList(ListNode *first, ListNode *second) {
    ListNode *result = new ListNode(0), *current = result;
    
    while (first != NULL && second != NULL) {
        if (first->val < second->val) {
            ListNode *next = new ListNode(first->val);
            current->next = next;
            current = next;
            first = first->next;
        } else {
            ListNode *next = new ListNode(second->val);
            current->next = next;
            current = next;
            second = second->next;
        }
    }
    
    current->next = (first == NULL) ? second : first;
    
    return result->next;
}

ListNode *mergeListsByDivide(std::vector<ListNode *> &lists, int low, int high) {
    if (low == high) {
        return lists[low];
    } else if (high - low == 1) {
        return mergeSortedList(lists[low], lists[high]);
    } else {
        int mid = low + ((high-low) >> 1);
        ListNode *left = mergeListsByDivide(lists, low, mid);
        ListNode *right = mergeListsByDivide(lists, mid+1, high);
        return mergeSortedList(left, right);
    }
}

ListNode *mergeKLists1(std::vector<ListNode *> &lists) {
    if (lists.size() == 0) {
        return NULL;
    }
    if (lists.size() == 1) {
        return lists[0];
    }
    
    return mergeListsByDivide(lists, 0, lists.size()-1);
}

/* Soultion 2:
 将所有ListNode中的node取出存入priority_queue，进行排序后组建成新的ListNode
 *************/

struct CmpByValue {
    bool operator()(const ListNode* lhs, const ListNode* rhs) {
        return lhs->val > rhs->val;
    }
};

ListNode *mergeKLists2(std::vector<ListNode *> &lists) {
    std::priority_queue<ListNode* , std::vector<ListNode *>, CmpByValue> pq;
    
    for (int i = 0; i < lists.size(); i ++) {
        if (lists[i]) {
            pq.push(lists[i]);
        }
    }
    
    ListNode *result = new ListNode(0);
    ListNode *current = result;
    while (!pq.empty()) {
        ListNode *next = pq.top();
        pq.pop();
        current->next = next;
        current = next;
        // 下面这步很重要，需要注意，push进pq后，会进行自动排序，下次取next自然会得到最小的next
        if (next->next) {
            pq.push(next->next);
        }
    }

    return result->next;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<ListNode *> lists;
    ListNode *a = new ListNode(2);
    ListNode *b = new ListNode(4);
    a->next = b;
    lists.push_back(a);
    lists.push_back(NULL);
    lists.push_back(NULL);
    lists.push_back(NULL);
    ListNode *c = new ListNode(-1);
    lists.push_back(c);
    ListNode *d = new ListNode(3);
    lists.push_back(d);
    ListNode *result1 = mergeKLists1(lists);
    ListNode *result2 = mergeKLists2(lists);
    std::cout << result1 << "\n" << result2 << "\n";
    return 0;
}


/* Test case
 ***********
 
 []
 [2->4->null]
 [null,null,null]
 [2->null,null,-3->null]
 [7->null,49->null,73->null,58->null,30->null,72->null,44->null,78->null,23->null,9->null,40->null,65->null,92->null,42->null,87->null,3->null,27->null,29->null,40->null,12->null,3->null,69->null,9->null,57->null,60->null,33->null,99->null,78->null,16->null,35->null,97->null,26->null,12->null,67->null,10->null,33->null,79->null,49->null,79->null,21->null,67->null,72->null,93->null,36->null,85->null,45->null,28->null,91->null,94->null,57->null,1->null,53->null,8->null,44->null,68->null,90->null,24->null,96->null,30->null,3->null,22->null,66->null,49->null,24->null,1->null,53->null,77->null,8->null,28->null,33->null,98->null,81->null,35->null,13->null,65->null,14->null,63->null,36->null,25->null,69->null,15->null,94->null,29->null,1->null,17->null,95->null,5->null,4->null,51->null,98->null,88->null,23->null,5->null,82->null,52->null,66->null,16->null,37->null,38->null,44->null,1->null,97->null,71->null,28->null,37->null,58->null,77->null,97->null,94->null,4->null,9->null,31->null,45->null,75->null,35->null]
 
 */
