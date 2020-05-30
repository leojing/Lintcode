//
//  main.cpp
//  Lintcode-553
//
//  Created by Jing Luo on 5/30/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/* brout force会TLE
int helper(vector<vector<char>> &grid, int n, int m, int x, int y) {
    int count = 0;
    int dir[8] = {0, 1, 0, -1, 1, 0, -1, 0};
    for (int i = 0; i < 8; i += 2) {
        int newX = x + dir[i];
        int newY = y + dir[i+1];
        while (newX >= 0 && newX < n && newY >= 0 && newY < m) {
            if (grid[newX][newY] == 'E') {
                count ++;
            }
            if (grid[newX][newY] == 'W') {
                break;
            }
            newX += dir[i];
            newY += + dir[i+1];
        }
    }
    return count;
}

int maxKilledEnemies(vector<vector<char>> &grid) {
    int result = 0;
    int n = int(grid.size());
    if (n == 0) {
        return 0;
    }
    int m = int(grid[0].size());
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == '0') {
                result = max(result, helper(grid, n, m, i, j));
            }
        }
    }
    return result;
}*/

// 二维DP，对四个方向分别用DP求值，最后相加
void helper(vector<vector<char>> &grid, int n, int m, vector<vector<int>> &up, vector<vector<int>> &down, vector<vector<int>> &left, vector<vector<int>> &right) {
    // up
    // 初始化
    for (int i = 0; i < m; i ++) {
        if (grid[0][i] == 'E') {
            up[0][i] = 1;
        } else {
            up[0][i] = 0;
        }
    }
    // DP求后面的数据
    for (int i = 1; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == 'E') {
                // 如果是E，+1
                up[i][j] = up[i-1][j] + 1;
            } else if (grid[i][j] == 'W') {
                // 如果是W，清零
                up[i][j] = 0;
            } else {
                // 如果是0，则与之前的数据相同
                up[i][j] = up[i-1][j];
            }
        }
    }
    
    // down
    // 初始化
    for (int i = 0; i < m; i ++) {
        if (grid[n-1][i] == 'E') {
            down[n-1][i] = 1;
        } else {
            down[n-1][i] = 0;
        }
    }
    // DP求后面的数据
    for (int i = n-2; i >= 0; i --) {
        for (int j = m-1; j >= 0; j --) {
            if (grid[i][j] == 'E') {
                down[i][j] = down[i+1][j] + 1;
            } else
                if (grid[i][j] == 'W') {
                down[i][j] = 0;
            } else {
                down[i][j] = down[i+1][j];
            }
        }
    }
    
    // left
    // 初始化
    for (int i = 0; i < n; i ++) {
        if (grid[i][0] == 'E') {
            left[i][0] = 1;
        } else {
            left[i][0] = 0;
        }
    }
    // DP求后面的数据
    for (int i = 0; i < n; i ++) {
        for (int j = 1; j < m; j ++) {
            if (grid[i][j] == 'E') {
                left[i][j] = left[i][j-1] + 1;
            } else
                if (grid[i][j] == 'W') {
                left[i][j] = 0;
            } else {
                left[i][j] = left[i][j-1];
            }
        }
    }
    
    // right
    // 初始化
    for (int i = 0; i < n; i ++) {
        if (grid[i][m-1] == 'E') {
            right[i][m-1] = 1;
        } else {
            right[i][m-1] = 0;
        }
    }
    // DP求后面的数据
    for (int i = n-1; i >= 0; i --) {
        for (int j = m-2; j >= 0; j --) {
            if (grid[i][j] == 'E') {
                right[i][j] = right[i][j+1] + 1;
            } else
                if (grid[i][j] == 'W') {
                right[i][j] = 0;
            } else {
                right[i][j] = right[i][j+1];
            }
        }
    }
}

int maxKilledEnemies(vector<vector<char>> &grid) {
    int result = 0;
    int n = int(grid.size());
    if (n == 0) {
        return 0;
    }
    int m = int(grid[0].size());
    if (m == 0) {
        return 0;
    }
    vector<vector<int>> up(n, vector<int>(m)), down(n, vector<int>(m)), left(n, vector<int>(m)), right(n, vector<int>(m));
    helper(grid, n, m, up, down, left, right);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == '0') { // 只能放在0的位置，如果所有点都假设可以放，那E的位置会有重复计算的问题
                result = max(result, up[i][j] + down[i][j] + left[i][j] + right[i][j]);
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<char>> grid = {{}};
    //{};
    //{{'0','E','0','0','E','E','0','0'},{'E','0','0','E','E','0','W','E'},{'0','0','E','E','0','E','0','0'}};
    //{{'0', 'E', '0', '0'}, {'E', '0', 'W', 'E'}, {'0', 'E', '0', '0'}};
    std::cout << maxKilledEnemies(grid) << "\n";
    return 0;
}



/*
###算法
DP, 注意corner case，空数据{{}}和{} wa了两把，太不应该，从四个方向up，down，left，right分别用DP求出能得到的值，最后相加取最大值，不用担心重复计算的问题，因为bomb只会放在0的位置
 
###时空复杂度
Time Complexity: O(n*m)
Space Complexity: O(n*m)

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/

