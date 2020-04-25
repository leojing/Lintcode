//
//  main.cpp
//  Lintcode-428
//
//  Created by Luo, Jing on 25/4/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>

double myPow(double x, int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return x;
    }
    if (n == -1) { // 如果是负数，就是倒数
        return 1/x;
    }
    double half = myPow(x, int(n/2));
    if (n & 1) {
        if (n < 0) {
            return half * half * (1/x); // 注意这里如果是n负数，要乘以1/x倒数
        }
        return half * half * x;
    }
    return half * half;
}

int main(int argc, const char * argv[]) {
    std::cout << myPow(3, -4) << "\n";
    return 0;
}



/*
###算法
递归，注意n为负数或者奇数的情况
 
###时空复杂度
Time Complexity: O(logN)
Space Complexity: O(1)

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/

