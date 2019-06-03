//
//  main.cpp
//  Lintcode-1201
//
//  Created by JINGLUO on 3/6/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

std::vector<int> nextGreaterElements(std::vector<int> &nums) {
    std::vector<int> result = std::vector<int>();
    int temp = 0;
    for (int i = 0; i < nums.size(); i ++) {
        temp = i + 1;
        while (1) { // while(temp != i), 如果不等的出口放在while里，那么后面temp到达末尾，变为0后，就会错过这个出口，导致死循环，e.g. {5,4,3,2,1}
            if (temp == nums.size()) {
                temp = 0;
            }
            if (nums[temp] > nums[i] || temp == i) { // temp != i 的 出口放在这里，用temp == i 跳出while
                break;
            } else {
                temp ++;
            }
        }
        if (temp != i) {
            result.push_back(nums[temp]);
        } else {
            result.push_back(-1);
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {5,4,3,2,1}; //{1};
    std::vector<int> result = nextGreaterElements(nums);
    return 0;
}


/*
###算法
 普通模拟法，注意跳出while的边界
 
###代码实现
 参照代码，已注释
 
###时空复杂度
 time O(n^2)
*/
