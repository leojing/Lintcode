//
//  main.cpp
//  Lintcode-82
//
//  Created by Jing LUO on 27/11/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int> &A) {
    // write your code here
    int result = 0;
    for (int i = 0; i < A.size(); i ++) {
        result ^= A[i];
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> A = {1,2,4,2,1,3,3};
    std::cout << singleNumber(A) << "\n";
    return 0;
}
