//
//  main.cpp
//  Lintcode-143
//
//  Created by Jing LUO on 14/7/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>

void swap(std::vector<int> &colors, int a, int b) {
    int tem = colors[a];
    colors[a] = colors[b];
    colors[b] = tem;
}

int partition(std::vector<int> &colors, int target1, int target2, int start, int end) {
    if (start < end && target1 < target2) {
        int left = start;
        int right = end;
        int mid = target1 + (target2 - target1)/2;
        while (left <= right) {
            while (left <= right && colors[left] <= mid) {
                left ++;
            }
            while (left <= right && colors[right] > mid) {
                right --;
            }
            if (left < right) {
                swap(colors, left, right);
                left ++;
                right --;
            }
        }
        return right;
    }
    return -1;
}

void helper(std::vector<int> &colors, int k1, int k2, int start, int end) {
    if (start < end) {
        int part = partition(colors, k1, k2, start, end);
        int midColor = k1 + (k2-k1)/2;
        if (part == -1) {
            return;
        }
        helper(colors, k1, midColor, start, part);
        helper(colors, midColor+1, k2, part+1, end);
    }
}

void sortColors2(std::vector<int> &colors, int k) {
    helper(colors, 1, k, 0, int(colors.size()) - 1);
}

int main(int argc, const char * argv[]) {
    std::vector<int> colors = {2,1,1,2,2,3,2,3,3,3,5,6,7,8,5,4,8,9,7};//{3,2,2,1,2};//{2,1,1,2,2};
    sortColors2(colors, 10);
    std::cout << "Hello, World!\n";
    return 0;
}
