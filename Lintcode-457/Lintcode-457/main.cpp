//
//  main.cpp
//  Lintcode-457
//
//  Created by JINGLUO on 22/11/18.
//  Copyright © 2018 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

int binarySearch(std::vector<int> &nums, int target, int s, int e) {
    if (e >= s) {
        int mid = (e - s) / 2 + s;
        if (target == nums[mid]) {
            return mid;
        } else if (target > nums[mid]) {
            return binarySearch(nums, target, mid+1, e);
        }
        return binarySearch(nums, target, s, mid-1);
    }
    return -1;
}

int findPosition(std::vector<int> &nums, int target) {
    return int(binarySearch(nums, target, 0, int(nums.size()) - 1));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(5);
    int result = findPosition(nums, 5);
    std::cout << result << "\n";
    return 0;
}
