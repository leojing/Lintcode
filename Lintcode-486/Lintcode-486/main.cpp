//
//  main.cpp
//  Lintcode-486
//
//  Created by JINGLUO on 12/9/18.
//  Copyright © 2018 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

std::vector<int> mergeTwoSortedArray(std::vector<int> &first, std::vector<int> &second) {
    std::vector<int> result;
    int i = 0, j = 0;
    while (i < first.size() && j < second.size()) {
        if (first[i] <= second[j]) {
            result.push_back(first[i]);
            ++i;
        } else {
            result.push_back(second[j]);
            ++j;
        }
    }
    
    while (i < first.size()) {
        result.push_back(first[i]);
        ++i;
    }
    while (j < second.size()) {
        result.push_back(second[j]);
        ++j;
    }
    
    return result;
}

std::vector<int> mergeArraysByDivide(std::vector<std::vector<int>> &arrays, int low, int high) {
    if (low == high) {
        return arrays[low];
    } else if (high - low == 1) {
        return mergeTwoSortedArray(arrays[low], arrays[high]);
    } else {
        int mid = low + ((high-low) >> 1);
        std::vector<int> left = mergeArraysByDivide(arrays, low, mid);
        std::vector<int> right = mergeArraysByDivide(arrays, mid+1, high);
        return mergeTwoSortedArray(left, right);
    }
}

std::vector<int> mergekSortedArrays(std::vector<std::vector<int>> &arrays) {
    std::vector<int> result;
    
    if (arrays.size() == 0) {
        return {};
    }
    if (arrays.size() == 1) {
        result = arrays[0];
    }
    
    result = mergeArraysByDivide(arrays, 0, arrays.size()-1);
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<std::vector<int>> arrays;
    std::vector<int> a = {1,3,5,7};
    std::vector<int> b = {2,4,6,8};
    std::vector<int> c = {0,8,9,10};
    arrays.push_back(a);
    arrays.push_back(b);
    arrays.push_back(c);
    std::vector<int> result = mergekSortedArrays(arrays);
    std::cout << &result << "\n";
    return 0;
}



/*
 similar solution to 104
 */

/* Test case
 [1,3,4,5,7,38,73],[2,4,6],[0,8,9,10,11]
 */
