//
//  main.cpp
//  Lintcode-434
//
//  Created by Jing LUO on 31/7/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};


// Solution 1: bfs, will Memory Limit Exceede
/*
int bfs(std::vector<std::vector<int>> &map) {
    std::queue<Point*> queue;
    std::set<Point*> visited = std::set<Point*>();
    std::vector<std::vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};

    int numOfIslands = 0;
    int n = int(map.size());
    int m = 0;
    if (n > 0) {
        m = int(map[0].size());
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            Point *point = new Point(i, j);
            if (visited.find(point) != visited.end()) {
                continue;
            }
            visited.insert(point);
            if (map[i][j] == 0) {
                continue;
            }
            numOfIslands ++;
            queue.push(point);
            while (queue.size() > 0) {
                Point *currentPoint = queue.front();
                queue.pop();
                for (int k = 0; k < 4; k ++) {
                    Point *newPoint = new Point(currentPoint->x+directions[k][0], currentPoint->y+directions[k][1]);
                    if (visited.find(newPoint) != visited.end()) {
                        continue;
                    }
                    if (newPoint->x < 0 || newPoint->x >= n || newPoint->y < 0 || newPoint->y >= m) {
                        continue;
                    }
                    visited.insert(newPoint);
                    if (map[newPoint->x][newPoint->y] == 1) {
                        map[newPoint->x][newPoint->y] = 0;
                        queue.push(newPoint);
                    }
                }
            }
        }
    }

    return numOfIslands;
}

std::vector<int> numIslands2(int n, int m, std::vector<Point> &operators) {
    std::vector<int> result;

    std::vector<std::vector<int>> map = std::vector<std::vector<int>>(n,std::vector<int>(m, 0));
    std::vector<std::vector<int>> tempMap = map;
    for (int i = 0; i < operators.size(); i ++) {
        if ((operators[i].x >= 0 && operators[i].x < n) && (operators[i].y >= 0 && operators[i].y < m)) {
            map[operators[i].x][operators[i].y] = 1;
        }
        tempMap = map;
        result.push_back(bfs(tempMap));
    }
    return result;
}
*/

// Solution 2: union find

bool isInIsland(int n, int m, int x, int y) {
    if ((x >= 0 && x < n) && (y >= 0 && y < m)) {
        return true;
    }
    return false;
}

int father[100000];

int find(int x) {
    if (father[x] == x) {
        return x;
    }
    return father[x] = find(father[x]);
}

bool Union(int x, int y) {
    if (father[x] == -1 || father[y] == -1) {
        return false;
    }
    int fX = find(x);
    int fY = find(y);
    if (fX != fY) {
        father[fY] = fX;
        return true;
    }
    return false;
}

std::vector<int> numIslands2(int n, int m, std::vector<Point> &operators) {
    std::vector<int> result;
    int directions[4][2] = {0,1,0,-1,1,0,-1,0};
    int count = 0;
    for (int i = 0; i < n * m; i ++) {
        father[i] = -1;
    }
    for (int i = 0; i < operators.size(); i ++) {
        int position = m * operators[i].x + operators[i].y;
        if (father[position] == -1) {
            father[position] = position;
            count ++;
        }
        for (int j = 0; j < 4; j ++) {
            int x = operators[i].x + directions[j][0];
            int y = operators[i].y + directions[j][1];
            int newPosition = m * x + y;
            if (isInIsland(n, m, x, y) == false) {
                continue;
            }
            if (Union(newPosition, position)) {
                count --;
            }
        }
        result.push_back(count);
    }
    return result;
}


int main(int argc, const char * argv[]) {
    Point p1 = Point(0, 1);
    Point p2 = Point(1, 2);
    Point p3 = Point(2, 1);
    Point p4 = Point(1, 0);
    Point p5 = Point(0, 2);
    Point p6 = Point(0, 0);
    Point p7 = Point(1, 1);
    std::vector<Point> operators = {p1, p2, p3, p4, p5, p6, p7};
    std::vector<int> result = numIslands2(3, 4, operators);
    std::cout << result.size() << "\n";
    return 0;
}


/*
 Solution 2:

 ###算法
 union find 并查集

 ###代码实现
 ***有什么要注意的地方
 ***有什么要优化的地方

 ###时空复杂度
 time 一个很小的数，参考：https://zh.wikipedia.org/wiki/%E5%B9%B6%E6%9F%A5%E9%9B%86
 space O(n*m)

 ###相关的题目有哪些
 1257, 860, 804, 677, 629, 589, 477, 433, 432
 */
