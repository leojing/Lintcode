//
//  main.cpp
//  Lintcode-655
//
//  Created by Jing Luo on 5/21/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string addStrings(string &num1, string &num2) {
    stack<int> result;
    stack<int> digital1;
    stack<int> digital2;
    for (auto c: num1) {
        digital1.push(c - '0');
    }
    for (auto c: num2) {
        digital2.push(c - '0');
    }
    int sum = 0;
    int mod = 0;
    // 先处理长度相等的部分
    while (!digital1.empty() && !digital2.empty()) {
        int first = digital1.top();
        int second = digital2.top();
        sum += first + second;
        mod = sum % 10;
        result.push(mod);
        sum = sum / 10;
        digital1.pop();
        digital2.pop();
    }
    // 如果有一个数还没有结束，则直接用这个数填补后面的
    digital1 = digital2.empty() ? digital1 : digital2;
    while (!digital1.empty()) {
        int first = digital1.top();
        sum += first;
        mod = sum % 10;
        result.push(mod);
        sum = sum / 10;
        digital1.pop();
    }
    // 注意最后一位是否有进位
    if (sum != 0) {
        result.push(sum % 10);
    }
    string str = "";
    while (!result.empty()) {
        str += to_string(result.top());
        result.pop();
    }
    return str;
}

int main(int argc, const char * argv[]) {
    string num1 = "999";
    string num2 = "1544";
    std::cout << addStrings(num1, num2) << "\n";
    return 0;
}
