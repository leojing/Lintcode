//
//  main.cpp
//  Lintcode-211
//
//  Created by JINGLUO on 26/3/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

std::map<char, int> createMap(std::string &A) {
    std::map<char, int> AMap;
    int i = 0;
    for (i = 0; i < A.size(); i ++) {
        char a = A[i];
        AMap[a] = AMap[a] + 1;
    }
    return AMap;
}

bool Permutation(std::string &A, std::string &B) {
    if (A.size() != B.size()) {
        return false;
    }
    std::map<char, int> AMap = createMap(A);
    std::map<char, int> BMap = createMap(B);
    int i;
    for (i = 0; i < 257; i ++) {
        if (AMap[char('a')+i] != BMap[char('a')+i]) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::string a = "ABNC8";
    std::string b = "ACBN8";
    std::cout << "Permutation is " << Permutation(a, b) << "\n";
    return 0;
}
