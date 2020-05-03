//
//  main.cpp
//  Lintcode-411
//
//  Created by Jing Luo on 5/3/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> grayCode(int n) {
    vector<int> result;
    if (n == 0) {
        result.push_back(0);
        return result;
    }
    
    result = grayCode(n-1);
    
    for (int i = int(result.size())-1; i >= 0; i --) {
        int num = result[i];
        num += 1 << (n-1);
        result.push_back(num);
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> result = grayCode(2);
    std::cout << "Hello, World!\n";
    return 0;
}


// 不是很懂公式
// https://www.cnblogs.com/yuzhangcmu/p/4121804.html
