//
//  main.cpp
//  Lintcode-423
//
//  Created by JINGLUO on 26/8/18.
//  Copyright © 2018 JINGLUO. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

bool isValidParentheses(std::string &s) {
    std::stack<char> stack;
    int i;
    for (i = 0; i < s.length(); i ++) {
        if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (stack.empty()) {
                return false;
            }
        }
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack.push(s[i]);
        } else if (s[i] == ')') {
            if (stack.top() == '(') {
                stack.pop();
            } else {
                return false;
            }
        } else if (s[i] == ']') {
            if (stack.top() == '[') {
                stack.pop();
            } else {
                return false;
            }
        } else if (s[i] == '}') {
            if (stack.top() == '{') {
                stack.pop();
            } else {
                return false;
            }
        }
    }
    
    if (stack.empty()) {
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    std::string s;
    std::cin >> s;
    std::cout << isValidParentheses(s);
    return 0;
}
