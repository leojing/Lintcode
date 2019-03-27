//
//  main.cpp
//  Lintcode-5
//
//  Created by JINGLUO on 22/11/18.
//  Copyright © 2018 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

// Solution 1
int kthLargestElement(int n, std::vector<int> &nums) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int i;
    for(i = 0; i < nums.size(); ++ i) {
        if (pq.size() < n) {
            pq.push(nums[i]);
        } else {
            int top = pq.top();
            if (top < nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    return pq.top();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> nums;
    nums.push_back(3);
    nums.push_back(9);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(8);
    std::cout << kthLargestElement(2, nums) << "\n";
    return 0;
}


/*
 Solution 1:
    - 使用priority_queue来存放最大的k个数，最后取出顶部数据，O(n) time, O(k) extra memory.
 
 Solution 2:
    - 使用快排思想，可以优化到O(n) time, O(1) extra memory.
 */

