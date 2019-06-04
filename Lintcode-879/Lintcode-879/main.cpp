//
//  main.cpp
//  Lintcode-879
//
//  Created by JINGLUO on 4/6/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>

std::string mergeTwoString(std::string a, std::string b) {
    return "(" + a + "," + b + ")";
}

void emptyQueue(std::queue<std::string>* queue) {
    while (!queue->empty()) {
        queue->pop();
    }
}

void emptyStack(std::stack<std::string>* stack) {
    while (!stack->empty()) {
        stack->pop();
    }
}

std::string findContestMatch(int n) {
    std::queue<std::string> forwardQ = std::queue<std::string>();
    std::queue<std::string> tempForwardQ = std::queue<std::string>();
    
    std::stack<std::string> backwardQ = std::stack<std::string>();
    std::stack<std::string> tempBackwardQ = std::stack<std::string>();
    
    int i, j;
    for (i = 1; i <= n/2; i ++) {
        forwardQ.push(std::to_string(i));
    }
    for (j = i; j <= n; j ++) {
        backwardQ.push(std::to_string(j));
    }
    int count = int(forwardQ.size());
    int tempCount;
    while (1) {
        std::string first = forwardQ.front();
        forwardQ.pop();
        
        std::string last = backwardQ.top();
        backwardQ.pop();
        
        tempCount = int(forwardQ.size());
        std::string result = mergeTwoString(first, last);
        if (count == 1) {
            return result;
        }
        if (tempCount >= count/2) {
            tempForwardQ.push(result);
        } else {
            tempBackwardQ.push(result);
        }
        
        if (tempCount == 0) {
            forwardQ = tempForwardQ;
            backwardQ = tempBackwardQ;
            emptyQueue(&tempForwardQ); // 这里记得要请空
            emptyStack(&tempBackwardQ); // 同上
            count = int(forwardQ.size());
        }
    }
    return "";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << findContestMatch(2) << "\n";
    return 0;
}


/*
 ###算法
 普通模拟法，头尾数据相结合，直到全部两两合并
 
 ###代码实现
 ***有什么要注意的地方
    参照代码，已注释
 ***有什么要优化的地方
    1，其实可以用vector实现，全部都放在vector中，不需要开辟forward和backward2个空间
    2，用recursion实现，应该会简化代码 TODO
 
 ###时空复杂度
 time O(logN)
 space O(n), 其实是half n
 
 ###相关的题目有哪些
 
 */
