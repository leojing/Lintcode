//
//  main.cpp
//  Lintcode-534
//
//  Created by Jing LUO on 3/12/19.
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

int houseRobber2(vector<int> &nums) {
    if (nums.size() == 0) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }
    vector<int>::const_iterator begin = nums.begin();
    vector<int>::const_iterator end = nums.begin() + nums.size() - 1;
    // get sub array nums[0]...nums[size-2], ignore last element
    vector<int> first_arr(begin, end);
    long long first = houseRobber(first_arr);

    // get sub array nums[1]...nums[size-1], ignore first element
    end = nums.begin() + nums.size();
    vector<int> last_arr(begin+1, end);
    long long last = houseRobber(last_arr);

    return max(first, last);
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {3,4,3,7};
    std::cout << houseRobber2(nums) << "\n";
    return 0;
}


/*
 ###算法
 dp算法和392. house robber一样，只是这里抢劫规则变成数组可头尾相连成环，因此需求一遍不抢最后一户的值，再求一遍不抢第一户的值，取最大的那个。
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
 515. Paint House
 514. Paint Fence
 366. Fibonacci
 111. Climbing Stairs
 */


