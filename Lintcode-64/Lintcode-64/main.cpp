//
//  main.cpp
//  Lintcode-64
//
//  Created by Luo, Jing on 29/3/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>

void mergeSortedArray(int A[], int m, int B[], int n) {
    int i = m - 1;
    int j = n - 1;
    int index = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (A[i] > B[j]) {
            A[index] = A[i];
            i --;
        } else {
            A[index] = B[j];
            j --;
        }
        index --;
    }
    while (i >= 0) {
        A[index] = A[i];
        i --;
        index --;
    }
    while (j >= 0) {
        A[index] = B[j];
        j --;
        index --;
    }
}

int main(int argc, const char * argv[]) {
    int A[8] = {1,2,3,4};
    int B[] = {1,4,6,7};
    mergeSortedArray(A, 4, B, 4);
    std::cout << A << "\n";
    return 0;
}



/*
###算法
 因为A足够大，所以将A，B从后往前遍历，每次取较大的值，赋在A的最后一位（m+n-1），依次递减，绝对不会和前面的A重叠，因为是从m+n-1开始往前存
 
 ###时空复杂度
 Time Complexity: O(n+m)
 Space Complexity: O(1). 因为用的是A来存放结果，所有不需要额外开辟新的空间
  
###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###相关的题目有哪些
839. Merge two sorted interval lists
212. Space replacement
6. Merge two sorted arrays
*/
