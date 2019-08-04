//
//  main.cpp
//  Lintcode-433
//
//  Created by JINGLUO on 4/8/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>

int bfs(std::vector<std::vector<bool>> &grid) {
    std::queue<std::pair<int, int>> queue;
    std::vector<std::vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    
    int numOfIslands = 0;
    int n = int(grid.size());
    int m = 0;
    if (n > 0) {
        m = int(grid[0].size());
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            std::pair<int, int> position = std::make_pair(i, j);
            if (grid[i][j] == 0) {
                continue;
            }
            numOfIslands ++;
            queue.push(position);
            while (queue.size() > 0) {
                std::pair<int, int> currentPosition = queue.front();
                queue.pop();
                for (int k = 0; k < 4; k ++) {
                    std::pair<int, int> newPosition = std::make_pair(currentPosition.first+directions[k][0], currentPosition.second+directions[k][1]);
                    if (newPosition.first < 0 || newPosition.first >= n || newPosition.second < 0 || newPosition.second >= m) {
                        continue;
                    }
                    if (grid[newPosition.first][newPosition.second] == 0) {
                        continue;
                    }
                    grid[newPosition.first][newPosition.second] = 0;
                    queue.push(newPosition);
                }
            }
        }
    }
    
    return numOfIslands;
}

int numIslands(std::vector<std::vector<bool>> &grid) {
    return bfs(grid);
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<bool>> grid = {{1,1,0,0,0},{0,1,0,0,1},{0,0,0,1,1},{0,0,0,0,0},{0,0,0,0,1}};
    std::cout << numIslands(grid) << "\n";
    return 0;
}


/*
###算法
bfs

###代码实现
***有什么要注意的地方
***有什么要优化的地方

###时空复杂度
time O(n*m)
space O(n*m)

###相关的题目有哪些
860, 804, 677, 663, 589, 477, 434
*/
