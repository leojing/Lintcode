//
//  main.cpp
//  Lintcode-1042
//
//  Created by Jing Luo on 5/10/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool help(vector<vector<int>> &matrix, int n, int m, int x, int y) {
    int current = matrix[x][y];
    x += 1;
    y += 1;
    while (x < n && y < m) { // 注意不能越界
        if (current != matrix[x][y]) {
            return false;
        }
        current = matrix[x][y];
        x += 1;
        y += 1;
    }
    return true;
}

bool isToeplitzMatrix(vector<vector<int>> &matrix) {
    int n = int(matrix.size());
    if (n == 0) { // corner case
        return true;
    }
    int m = int(matrix[0].size());
    if (m == 0) { // corner case
        return true;
    }
    for (int i = 0; i < m; i ++) { // 枚举第一行为起始点的对角线
        bool res = help(matrix, n, m, 0, i);
        if (!res) {
            return false;
        }
    }
    for (int i = 0; i < n; i ++) { // 枚举第一列为起始点的对角线
        bool res = help(matrix, n, m, i, 0);
        if (!res) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {{}};//{{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    std::cout << isToeplitzMatrix(matrix) << "\n";
    return 0;
}



/*
###算法
模拟题，所有对角线元素都要一致，注意corner cases
 
###时空复杂度
Time Complexity: O(n^2)
Space Complexity: O(1)

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/

