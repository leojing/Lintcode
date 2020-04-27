//
//  main.cpp
//  Lintcode-1212
//
//  Created by Jing Luo on 4/27/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums) {
    int result = 0;
    int count = 0;
    for (auto num: nums) {
        if (num == 1) {
            count += 1;
        } else {
            // 注意，如果最后一个数字不是1，则result不会被更新
            if (count > result) {
                result = count;
            }
            // 遇0，则清零重新计算
            count = 0;
        }
    }
    // 所以要在for循环外面再做最后一次更新
    if (count > result) {
        result = count;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1};
    std::cout << findMaxConsecutiveOnes(nums) << "\n";
    return 0;
}


/*
###算法
模拟题
 
###时空复杂度
Time Complexity: O(n)
Space Complexity: O(1)

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/
