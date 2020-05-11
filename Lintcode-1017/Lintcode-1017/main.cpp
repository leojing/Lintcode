//
//  main.cpp
//  Lintcode-1017
//
//  Created by Jing Luo on 5/11/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

// 形如AA的十六进制数必定是17的倍数，我们只要判断离原数最接近的17的倍数是多少即可。
string helper(string str) {
    string dec_to_hex = "0123456789abcdef", res = "";
    
    int dec = stoi(str, nullptr, 16);
    int q = dec / 17;
    if (dec % 17 > 8) { // 如果mod出来的数超过了一半，那就取后面的17的倍数，会使得差值更小
        q += 1;
    }
    res = res + dec_to_hex[q] + dec_to_hex[q];
    return res;
}

string similarRGB(string &color) {
    return "#" + helper(color.substr(1, 2)) + helper(color.substr(3, 2)) + helper(color.substr(5, 2));
}

int main(int argc, const char * argv[]) {
    string color = "#09f166";
    std::cout << similarRGB(color) << "\n";
    return 0;
}
