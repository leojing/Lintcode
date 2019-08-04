//
//  main.cpp
//  Lintcode-610
//
//  Created by JINGLUO on 14/7/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

std::vector<int> result;

std::vector<int> twoSum7(std::vector<int> &nums, int target) {
    std::map<int, int> numIndex;
    int i;
    for (i = 0; i < nums.size(); ++ i) {
        int t = nums[i] - target;
        if (numIndex.find(t) != numIndex.end()) {
            result.push_back(numIndex[t] + 1);
            result.push_back(i + 1);
            return result;
        }
        t = nums[i] + target;
        if (numIndex.find(t) != numIndex.end()) {
            result.push_back(numIndex[t] + 1);
            result.push_back(i + 1);
            return result;
        }
        numIndex[nums[i]] = i;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {2, 7, 15, 24};
    std::vector<int> result = twoSum7(nums, 5);
    std::cout << result.size() << "\n";
    return 0;
}
