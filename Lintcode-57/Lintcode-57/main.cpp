//
//  main.cpp
//  Lintcode-57
//
//  Created by Jing LUO on 2/7/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>

std::vector<std::vector<int>> results;

void helper(std::vector<int> &numbers, int mid) { // mid为主指针
    int left = mid - 1, right = mid + 1; // left，right为一对副指针
    std::vector<int> result;
    while (left >= 0 && right < int(numbers.size())) {
        int sum = numbers[mid] + numbers[left] + numbers[right];
        if (sum == 0) {
            result.push_back(numbers[left]);
            result.push_back(numbers[mid]);
            result.push_back(numbers[right]);
            if (std::count(results.begin(), results.end(), result) == 0) { //注意题目要求返回unique triplets，在sum == 0移动指针后需要检查重复。
                results.push_back(result);
            }
            result.clear(); // 找到一组目标后，不要移动主指针，需要继续移动2个副指针，因为可能还有其他匹配方式，此时需要清空result中前一组的结果
            left -= 1;
            right += 1;
        } else if (sum > 0) {
            left -= 1;
        } else {
            right += 1;
        }
    }
}

std::vector<std::vector<int>> threeSum(std::vector<int> &numbers) {
    std::sort(numbers.begin(), numbers.end(), std::less<int>());
    //用for loop和双指针进行降维操作，与two sum一样如果sum < 0移动左指针，如果sum > 0移动右指针，等于0 的时候记录。
    for (int i = 1; i < int(numbers.size()-1); i ++) {
        helper(numbers, i);
    }
    return results;
}

int main(int argc, const char * argv[]) {
    std::vector<int> numbers = {-1, 0, 1, 2, -1, -2}; // {0,0,0,0};
    std::vector<std::vector<int>> result = threeSum(numbers);
    std::cout << result.size() << "\n";
    return 0;
}


/*
 ###算法
one for loop plus two pointers
 
 ###代码实现
 ***有什么要注意的地方
 参考注释代码
 ***有什么要优化的地方
 
 ###时空复杂度分析
 Time O(n^2)
 Space O(1)
 
 ###相关题目
 Lintcode 918. 3Sum Smaller
 Lintcode 382. Triangle Count
 Lintcode 59. 3Sum Closest
 Lintcode 58. 4Sum
 Lintcode 56. Two Sum
 */
