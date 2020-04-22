//
//  main.cpp
//  Lintcode-911
//
//  Created by Luo, Jing on 22/4/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int maxSubArrayLen(vector<int> &nums, int k) {
    int i = 0;
    int sum = 0;
    int result = -1;
    map<int, int> sumMapping;
    sumMapping[0] = 0; // 注意0要初始化
    for (auto s:nums) {
        sum += s;
        if (sum == k) { // 如果当前就是
            result = i+1;
        } else if (sumMapping.find(sum-k) != sumMapping.end()) {
            result = max(result, i - sumMapping[sum-k]);
        }
        if (sumMapping.find(sum) == sumMapping.end()) { // 注意这里如果已经存在，则不更新，要保证是取最小的位置，这样才能得到最长的区间
            sumMapping[sum] = i;
        }
        i ++;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, -1, 5, 9, -2, 3};
    std::cout << maxSubArrayLen(nums, 3) << "\n";
    return 0;
}



/*
###算法
前缀和+two sum+hashmap：
如果sum[i] + k = sum[j]的话， k = sum[j] - sum[i]
因此dictionary里面每次检查当前的前缀和加上k如果不存在的话，我们就把前缀和加k的值放进去。如果某次前缀和存在于字典中，说明当前的加和减去之前保存的位置的加和的差值等于k.
 
###时空复杂度
Time Complexity: O(n)
Space Complexity: O(n)

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/
