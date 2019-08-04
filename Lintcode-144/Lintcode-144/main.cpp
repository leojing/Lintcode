//
//  main.cpp
//  Lintcode-144
//
//  Created by Jing LUO on 10/7/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>

void swap(std::vector<int> &A, int a, int b) {
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

void rerange(std::vector<int> &A) {
    int left = 0;
    int right = int(A.size()) - 1;
    while (left < right) {
        // 从左往右找到第一个不应该在左边的
        while (left < right && A[left] < 0) {
            left ++;
        }

        // 从右往左找到第一个不应该在右边的
        while (left < right && A[right] > 0) {
            right --;
        }

        // 将找到的left位置的值和right位置的值进行交换
        swap(A, left, right);
    }
    if (right > int(A.size() / 2)) {
        left = 1;
    } else {
        left = 0;
    }
    while (left < right && right < A.size()) {
        swap(A, left, right);
        left += 2;
        right ++;
    }
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {28,2,-22,-27,2,9,-33,-4,-18,26,25,34,-35,-17,2,-2,32,35,-8};
    rerange(nums);
    std::cout << "Hello, World!\n";
    return 0;
}
