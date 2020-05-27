//
//  main.cpp
//  Lintcode-1301
//
//  Created by Jing Luo on 5/27/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 将细胞转换的4种状态用不同数字表示
 0->0 = 0
 0->1 = 2
 1->0 = 3
 1->1 = 1
 */
void gameOfLife(vector<vector<int>> &board) {
    vector<int> dir = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};
    int n = int(board.size());
    if (n == 0) {
        return;
    }
    int m = int(board[0].size());
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            int count = 0;
            for (int k = 0; k < 16; k += 2) {
                int newX = dir[k] + i;
                int newY = dir[k+1] + j;
                if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                    if (board[newX][newY] == 1 || board[newX][newY] == 3) {
                        count ++;
                    }
                }
            }
            // 1->0
            if (count < 2 && (board[i][j] == 1 || board[i][j] == 3)) {
                board[i][j] = 3;
            }
            // 1->1
            if ((count == 2 || count == 3) && (board[i][j] == 1 || board[i][j] == 3)) {
                board[i][j] = 1;
            }
            // 1->0
            if (count > 3 && (board[i][j] == 1 || board[i][j] == 3)) {
                board[i][j] = 3;
            }
            // 0->1
            if (count == 3 && (board[i][j] == 0 || board[i][j] == 2)) {
                board[i][j] = 2;
            }
        }
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (board[i][j] == 2) {
                board[i][j] = 1;
            }
            if (board[i][j] == 3) {
                board[i][j] = 0;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    gameOfLife(board);
    std::cout << board.size() << "\n";
    return 0;
}



/*
###算法
模拟题，唯一tricky的地方就是要求in place，所以需要将细胞和转换后的两种状态用一个int表示，规则在顶部
 
###时空复杂度
Time Complexity: O(n*m)
Space Complexity: O(1)

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/

