//
//  main.cpp
//  Lintcode-822
//
//  Created by Jing LUO on 3/10/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

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

// Solution 1: 递归写法
vector<int> reverseStore(ListNode * head) {
    if (head == NULL) {
        return vector<int>();
    }
    vector<int> res = reverseStore(head->next);
    res.push_back(head->val);
    return res;
}


// Solution 2: 非递归写法
vector<int> reverseStore2(ListNode * head) {
    vector<int> res;
    stack<int> stk;
    while (head != NULL) {
        stk.push(head->val);
        head = head->next;
    }
    while (!stk.empty()) {
        res.push_back(stk.top());
        stk.pop();
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}


/*
###算法
模拟题

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###时空复杂度
Time complexity: 两个solution都是O(n),n为h节点个数
Space complexity: 两个solution都是O(n)，solution 1中递归函数每次调用，里面的变量和函数名/参数都要从stack内存中申请空间存放，其实2个方法都有用stack内存

###相关的题目有哪些
*/

