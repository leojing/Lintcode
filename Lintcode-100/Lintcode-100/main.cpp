//
//  main.cpp
//  Lintcode-100
//
//  Created by Luo, Jing on 14/4/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums) {
    if (nums.size() == 0 || nums.size() == 1) {
        return int(nums.size());
    }
    int k = 0;
    int last = nums[0];
    for (int i = 1; i < nums.size(); i ++) {
        if (nums[i] == last) {
            continue;
        }
        nums[k++] = last;
        last = nums[i];
    }
    nums[k] = last;
    return k+1;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1,2,3,3,3,4,5,5,6};
    std::cout << removeDuplicates(nums) << "\n";
    return 0;
}
