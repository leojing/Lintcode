//
//  main.cpp
//  Lintcode-547
//
//  Created by Luo, Jing on 29/3/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Solution 1:
// one array adds to set, check each value of second array
// Time: O(NLogN), Space: O(n)
vector<int> intersection1(vector<int> &nums1, vector<int> &nums2) {
    set<int> nums1Set;
    set<int> resultSet;
    int nums1Size = int(nums1.size());
    while (nums1Size--) {
        nums1Set.insert(nums1[nums1Size]);
    }
    int nums2Size = int(nums2.size());
    while (nums2Size--) {
        int current = nums2[nums2Size];
        if (nums1Set.find(current) != nums1Set.end()) {
            resultSet.insert(current);
        }
    }
    vector<int> result(resultSet.size());
    copy(resultSet.begin(), resultSet.end(), result.begin());
    sort(result.begin(), result.end());
    return result;
}

// Solution 2:
// Two pointer: two arrays sort, then compare
// Time: O(NLogN), Space: O(n)
vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    set<int> resultSet;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int nums1Size = int(nums1.size());
    int nums2Size = int(nums2.size());
    int i = 0, j = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) {
            resultSet.insert(nums1[i]);
            i ++;
            j ++;
        } else if (nums1[i] > nums2[j]) {
            j ++;
        } else {
            i ++;
        }
    }
    vector<int> result(resultSet.size());
    copy(resultSet.begin(), resultSet.end(), result.begin());
    sort(result.begin(), result.end());
    return result;
}

// Solution 3:
// Binary search, sort nums1, then search element of nums2 in nums1

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1,2,4,3,6,3,7,2,1};
    vector<int> nums2 = {2,3,4,6,7,2};
    vector<int> result = intersection(nums1, nums2);
    std::cout << result.size() << "\n";
    return 0;
}
