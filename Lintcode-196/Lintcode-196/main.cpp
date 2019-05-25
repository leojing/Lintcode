//
//  main.cpp
//  Lintcode-196
//
//  Created by JINGLUO on 25/5/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

int findMissing(std::vector<int> &nums) {
    int start = 0, result = 0;
    for (int i = 0; i < nums.size(); i ++) {
        int diff = nums[i] - start;
        result = result + diff;
        start ++;
    }
    result = result - start;
    return abs(result);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> nums = {4,6,5,7,0,1,3};
    std::cout << findMissing(nums) << "\n";
    return 0;
}
