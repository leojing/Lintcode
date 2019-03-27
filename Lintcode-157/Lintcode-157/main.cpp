//
//  main.cpp
//  Lintcode-157
//
//  Created by JINGLUO on 27/3/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>

bool isUnique(std::string &str) {
    int i;
    std::set<char> result;
    for (i = 0; i < str.size(); i ++) {
        if (result.find(str[i]) != result.end()) {
            return false;
        } else {
            result.insert(str[i]);
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::string str = "ABBC";
    std::cout << "Is Unique " << isUnique(str) << "\n";
    return 0;
}


/*
 BUD
 BCR O(n)
 */
