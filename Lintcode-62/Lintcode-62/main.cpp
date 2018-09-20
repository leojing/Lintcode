//
//  main.cpp
//  Lintcode-62
//
//  Created by JINGLUO on 19/9/18.
//  Copyright © 2018 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

bool isVaildForDividSearch(std::vector<int> &A, int target, int start, int end) {
    if (start == end) return false;
    
    if (A[start] < A[end]) {
        if (target > A[start] && target < A[end]) {
            return true;
        }
        return false;
    } else {
        if (target > A[start] || target < A[end]) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

int dividSearch(std::vector<int> &A, int target, int low, int high) {
    if (A.size() == 0) {
        return -1;
    }
    
    if (high - low == 1) {
        if (A[low] == target) {
            return low;
        } else if (A[high] == target) {
            return high;
        }
    }
    
    int mid = (high - low) >> 1;
    mid += low;
    int a = -1, b = -1;
    
    if (isVaildForDividSearch(A, target, low, mid)) {
        a = dividSearch(A, target, low, mid);
    } else if (A[low] == target) {
        return low;
    } else if (A[mid] == target) {
        return mid;
    }
    
    if (isVaildForDividSearch(A, target, mid+1, high)) {
        b = dividSearch(A, target, mid+1, high);
    } else if (A[mid+1] == target) {
        return mid+1;
    } else if (A[high] == target) {
        return high;
    }
    
    if (a != -1) {
        return a;
    }
    if (b != -1) {
        return b;
    }
    return -1;
}

int search(std::vector<int> &A, int target) {
    return dividSearch(A, target, 0, A.size() - 1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> obj = {1,2,3,4,5,6,7,9,-2,-1,0};
    std::cout << search(obj, -2) << "\n";
    return 0;
}


/* Soultion:
    二分法，关键是用isVaildForDividSearch()判断这半边的数据s是否符合条件进行下一轮二分
*/
