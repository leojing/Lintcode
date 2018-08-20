//
//  main.cpp
//  Lintcode-427
//
//  Created by JINGLUO on 19/8/18.
//  Copyright © 2018 JINGLUO. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> findParenthesis(int n, int left, int right, std::string parenthesis, std::vector<std::string>&existPairs) {
    if (left == n && right == n) {
        existPairs.push_back(parenthesis);
        return existPairs;
    }
    
    char last = parenthesis.back();
    if (last == '(') {
        if (left == n && right < n) {
            findParenthesis(n, left, right+1, parenthesis+')', existPairs);
        } else if (left < n && right < n) {
            findParenthesis(n, left+1, right, parenthesis+'(', existPairs);
            findParenthesis(n, left, right+1, parenthesis+')', existPairs);
        } else {
            return existPairs;
        }
    } else if (last == ')') {
        if (left == n) {
            findParenthesis(n, left, right+1, parenthesis+')', existPairs);
        } else {
            if (left == right) {
                findParenthesis(n, left+1, right, parenthesis+'(', existPairs);
            } else if (left > right) {
                findParenthesis(n, left+1, right, parenthesis+'(', existPairs);
                findParenthesis(n, left, right+1, parenthesis+')', existPairs);
            } else {
                return existPairs;
            }
        }
    }
    
    return existPairs;
}

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> result;
    result = findParenthesis(n, 1, 0, "(", result);
    return result;
}

int main(int argc, const char * argv[]) {
    
    int n;
    std::cin >> n;
    std::vector<std::string> result;
    result = generateParenthesis(n);
    std::cout << result.size();
    
    return 0;
}
