//
//  main.cpp
//  Lintcode-8
//
//  Created by Luo, Jing on 3/3/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void rotateString(string &str, int offset) {
    int length = int(str.length());
    if (length == 0) {
        return;
    }
    offset = offset % length;
    if (offset == 0) {
        return;
    }
    str = str.substr(length-offset, offset).append(str.substr(0, length-offset));
}

int main(int argc, const char * argv[]) {
    string str = "abcdefg";
    rotateString(str, 1);
    std::cout << str << "\n";
    return 0;
}
