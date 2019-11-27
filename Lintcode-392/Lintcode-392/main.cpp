//
//  main.cpp
//  Lintcode-392
//
//  Created by Jing LUO on 27/11/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

long long houseRobber(vector<int> &A) {
    if (A.size() == 0) {
        return 0;
    }
    long long first = A[0], second = 0, current = first;
    for (int i = 1; i < A.size(); i ++) {
        current = max(first, A[i]+second);
        second = first;
        first = current;
    }
    return current;
}

int main(int argc, const char * argv[]) {
    vector<int> A = {2};//{5,2,1,3};
    std::cout << houseRobber(A) << "\n";
    return 0;
}


// WA了两把，第一把没有用long long型first second，直接update数组A[int], 2数相加导致越界，第二把没考虑到当数组里只有一个数时，current应该等于first，而把current赋default值为0



/*
###算法
一维dp，要么选前一个数（但是这样就不能加当前数，不然会触发警报），要么跳过它，选再前面一个数，这样可以和当前数相加，看看哪种方案值更大。

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###时空复杂度
Time complexity: O(n)
Space complexity: O(1), 用first second current记录当前值，前一个值，再前一个值，所以只有O(1)新内存开辟

###相关的题目有哪些
1142. Non-negative Integers without Consecutive Ones
866. Coin Path
535. House Robber III
534. House Robber II
515. Paint House
514. Paint Fence
366. Fibonacci
111. Climbing Stairs
*/


