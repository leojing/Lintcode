//
//  main.cpp
//  Lintcode-12
//
//  Created by JINGLUO on 22/8/18.
//  Copyright © 2018 JINGLUO. All rights reserved.
//

#include <iostream>
#include <stack>

std::stack<int> stack;
std::stack<int> minStack;

void MinStack() {
    // do intialization if necessary
}

/*
 * @param number: An integer
 * @return: nothing
 */
void push(int number) {
    // write your code here
    stack.push(number);
    if (minStack.empty()) {
        minStack.push(number);
    } else {
        if (minStack.top() >= number) {
            minStack.push(number);
        }
    }
}

/*
 * @return: An integer
 */
int pop() {
    // write your code here
    int top = stack.top();
    stack.pop();
    if (top == minStack.top() && !minStack.empty()) {
        minStack.pop();
    }
    return top;
}

/*
 * @return: An integer
 */
int min() {
    // write your code here
    return minStack.top();
}

int main(int argc, const char * argv[]) {
    push(3);
    push(2);
    push(1);

    std::cout << min() << "\n";
    std::cout << pop() << "\n";
    std::cout << min() << "\n";
    std::cout << pop() << "\n";
    std::cout << min() << "\n";
    return 0;
}
