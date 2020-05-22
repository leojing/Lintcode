//
//  main.cpp
//  Lintcode-407
//
//  Created by Jing Luo on 5/23/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
    stack<int> sumList;
    int sum = 1;
    int mod = 0;
    int n = int(digits.size()) - 1;
    while (n >= 0) {
        sum += digits[n];
        mod = sum % 10;
        sumList.push(mod);
        sum = sum / 10;
        n --;
    }
    if (sum != 0) {
        sumList.push(sum % 10);
    }
    vector<int> result;
    while (!sumList.empty()) {
        result.push_back(sumList.top());
        sumList.pop();
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> digits = {9,9,9};
    vector<int> result = plusOne(digits);
    std::cout << result.size() << "\n";
    return 0;
}
