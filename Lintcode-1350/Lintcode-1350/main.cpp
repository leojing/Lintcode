//
//  main.cpp
//  Lintcode-1350
//
//  Created by Luo, Jing on 13/4/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string convertToTitle(int n) {
    long mod, left = n;
    string result = "";
    while (left != 0) {
        mod = left % 26;
        left = left / 26;
        if (mod == 0) { // 注意这里在‘Z’的时候，需要特殊处理
            mod = 26;
            left -= 1;
        }
        char t = 'A' + mod - 1;
        result += t;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(int argc, const char * argv[]) {
    std::cout << convertToTitle(78) << "\n";
    return 0;
}
