//
//  main.cpp
//  Lintcode-38
//
//  Created by JINGLUO on 18/6/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

void helper(std::vector<std::vector<int>> &matrix, int r, int c, int target, int mark, int* result) {
    int n = int(matrix.size());
    int m = int(matrix[0].size());
    if (r >= n || c >= m || matrix[r][c] == mark || matrix[r][c] > target) { // edge case + 剪枝, matrix[r][c] > target，因为都是递增关系，所以如果已经比target大了，就没必要继续循环下去了
        return;
    }
    if (matrix[r][c] == target) {
        *result += 1;
        helper(matrix, r+1, c, target, mark, result); // 如果已经找到这一行的目标，那么这一行后面的就可以不用继续找了，直接去下一行
    } else {
        helper(matrix, r, c+1, target, mark, result);
        helper(matrix, r+1, c, target, mark, result);
    }
    matrix[r][c] = mark; // 找过的这个数字要mark掉
}

int searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    if (matrix.size() == 0) { // edge case
        return 0;
    }
    if (matrix[0].size() == 0) { // edge case
        return 0;
    }
    int result = 0;
    helper(matrix, 0, 0, target, matrix[0][0] - 1, &result);
    return result;
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> matrix = {{1,3,5,7}, {2,4,7,8}, {3,5,7,10}};
    std::cout << searchMatrix(matrix, 7) << "\n";
    return 0;
}


/*
 ###算法
模拟题，就是普通的搜索全部（n+m），所以BCR is O(m+n)
 
 ###代码实现
 ***有什么要注意的地方
参考代码注释
 ***有什么要优化的地方
 Challenge is O(m+n) time and O(1) extra space
 time complexity已经是最优解，通过剪枝，其实并不需要完全遍历所有点，一旦发现比target大，那么就不继续遍历后面的row或者Column。
 通过mark参数，将已经遍历过的点标记掉，以防重复遍历。这样space就是O(1),不需要开辟额外空间去mark
 
 ###时空复杂度
 time O(m+n)
 space O(1)
 
 ###相关的题目有哪些
 Lintcode 832. Count Negative Number
 Lintcode 465. Kth smallest Sum in Two sorted Arrays
 */

