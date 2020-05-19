//
//  main.cpp
//  Lintcode-804
//
//  Created by Jing Luo on 5/11/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> Location;

struct cmp {
    bool operator()(const Location &a, const Location &b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};

void dfs(vector<vector<int>> &grid, int n, int m, int x, int y, int index) {
    grid[x][y] = index;
    vector<int> direction = {0,1,0,-1,1,0,-1,0};
    for (int i = 0; i < direction.size(); i += 2) {
        int newX = x + direction[i];
        int newY = y + direction[i+1];
        if (newX < 0 || newX >= n) {
            continue;
        }
        if (newY < 0 || newY >= m) {
            continue;
        }
        if (grid[newX][newY] == 0) {
            continue;
        }
        if (grid[newX][newY] == 1) {
            dfs(grid, n, m, newX, newY, index);
        }
    }
}

vector<Location> shirkIsland(vector<Location> &a) {
    int minX = INT_MAX, minY = INT_MAX;
    for (auto node: a) {
        if (node.first < minX) {
            minX = node.first;
        }
        if (node.second < minY) {
            minY = node.second;
        }
    }
    for (int i = 0; i < a.size(); i ++) {
        Location node = a[i];
        node.first = node.first - minX;
        node.second = node.second - minY;
        a[i] = node;
    }
    return a;
}

bool helpCheck(vector<Location> &a, vector<Location> &b) {
    a = shirkIsland(a);
    b = shirkIsland(b);
    sort(a.begin(), a.end(), cmp());
    sort(b.begin(), b.end(), cmp());
    if (a.size() != b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); i ++) {
        if (a[i].first != b[i].first || a[i].second != b[i].second) {
            return false;
        }
    }
    return true;
}

bool isSameIsland(vector<Location> &a, vector<Location> &b) {
    if (a.size() != b.size()) {
        return false;
    }
    if (a.size() == 0) {
        return true;
    }
    
    a = shirkIsland(a);
    b = shirkIsland(b);
    
    int bWidth = -1, bHeight = -1;
    for (auto node: b) {
        if (bWidth < node.first) {
            bWidth = node.first;
        }
        if (bHeight < node.second) {
            bHeight = node.second;
        }
    }
    
    // No rotate and flip
    if (helpCheck(a, b)) {
        return true;
    }

    vector<Location> newIsland;
    // Rotate b to 90 degree
    for (auto node: b) {
        Location temp;
        temp.first = node.second;
        temp.second = bHeight - node.first;
        newIsland.push_back(temp);
    }
    if (helpCheck(newIsland, a)) {
        return true;
    }
    newIsland.clear();
    
    // Rotate b to 180 degree
    for (auto node: b) {
        Location temp;
        temp.first = bHeight - node.first;
        temp.second = bWidth- node.second;
        newIsland.push_back(temp);
    }
    if (helpCheck(newIsland, a)) {
        return true;
    }
    newIsland.clear();
    
    // Rotate b to 270 degree
    for (auto node: b) {
        Location temp;
        temp.first = bWidth - node.second;
        temp.second = node.first;
        newIsland.push_back(temp);
    }
    if (helpCheck(newIsland, a)) {
        return true;
    }
    newIsland.clear();
    
    // Flip top-bottom
    for (auto node: b) {
        Location temp;
        temp.first = bHeight - node.first;
        temp.second = node.second;
        newIsland.push_back(temp);
    }
    if (helpCheck(newIsland, a)) {
        return true;
    }
    newIsland.clear();

    // Flip left-right
    for (auto node: b) {
        Location temp;
        temp.first = node.first;
        temp.second = bWidth - node.second;
        newIsland.push_back(temp);
    }
    if (helpCheck(newIsland, a)) {
        return true;
    }
    newIsland.clear();

    return false;
}

int numDistinctIslands2(vector<vector<int>> &grid) {
    int n = int(grid.size());
    if (n == 0) {
        return 0;
    }
    int m = int(grid[0].size());
    if (m == 0) {
        return 0;
    }
    // Mark all islands with index
    int index = 2; // index from 2 as 0, 1 are marks for sea and island
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == 1) {
                dfs(grid, n, m, i, j, index);
                index ++;
            }
        }
    }
    // filter out all islands as vector
    map<int, vector<Location>> mapping;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            int index = grid[i][j];
            if (index == 0) {
                continue;
            }
            if (mapping.find(index) == mapping.end()) {
                vector<Location> island;
                island.push_back(Location(i, j));
                mapping[index] = island;
                continue;
            }
            mapping[index].push_back(Location(i, j));
        }
    }
    vector<vector<Location>> islands;
    map<int, vector<Location>>::iterator it = mapping.begin();
    while (it != mapping.end()) {
        vector<Location> island = it->second;
        sort(island.begin(), island.end(), cmp());
        islands.push_back(island);
        it ++;
    }
    // Check if two island are same
    int count = int(islands.size());
    vector<vector<Location>> q;
    for (int i = 0; i < count; i ++) {
        if (q.empty()) {
            q.push_back(islands[i]);
            continue;
        }
        int qSize = int(q.size());
        bool isExsit = false;
        for (int j = 0; j < qSize; j ++) {
            if (isSameIsland(islands[i], q[j])) {
                isExsit = true;
            }
        }
        if (!isExsit) {
            q.push_back(islands[i]);
        }
    }
    return int(q.size());
}

int main(int argc, const char * argv[]) {
                                     vector<vector<int>> grid =
                                     {{1,0,1,0,0,1,0,0,1,1,0,0,0,1,1,1,1,0,1,1,0,1,0,0,0,0,0,0,1,1,0,1,0,0,1,0,0,0,0,1,0,1,0,0,1,1,0,1,0,0},{1,1,0,1,0,0,1,0,1,1,0,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,1,0,0,1,1,1,1,1,0,0,1,0,0,0,1,0,1,1,1,1,1,0,0,1},{1,1,0,0,1,0,0,1,0,1,0,1,1,0,0,1,0,0,1,1,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,1,1,0,1,0,0,0,1,1,1,0,0,1,1,0},{1,1,1,0,0,0,0,1,0,1,0,1,1,0,0,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,1,0,0,1,0,1},{0,0,1,0,1,0,0,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,0,0,1,1,1,0,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,1,1,0,1,0},{0,0,1,1,1,0,0,1,0,1,1,0,0,1,1,1,0,0,1,0,0,1,0,0,1,1,1,1,0,1,0,0,1,1,1,1,1,1,0,0,1,0,0,1,0,1,1,0,1,1},{0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,1,1,1,1,1,0,1,1,1,1},{1,1,1,1,1,0,1,1,0,1,1,0,0,0,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,1,0,1,1,0,1,0,0,1,0,1,0},{0,0,0,1,0,1,1,0,1,0,1,1,0,1,0,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,1,1,0,1,0,1,1},{1,1,0,0,0,1,0,0,1,0,0,0,0,1,0,1,1,1,1,1,1,1,0,0,0,1,0,0,1,1,0,0,1,1,0,0,0,1,0,1,0,1,1,1,1,0,0,0,0,1},{0,1,0,1,0,1,1,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,0,0,0,1,0,0,1,0,1,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0},{0,0,1,0,0,0,0,0,1,0,0,1,1,0,0,0,1,1,1,0,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,1,0,0,1,1},{1,1,0,0,1,1,0,0,0,0,1,1,1,1,1,1,0,0,1,1,0,0,1,1,0,1,0,1,0,0,0,1,1,1,0,0,0,1,0,1,1,1,1,0,0,0,1,0,0,0},{0,1,1,0,1,1,1,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,0,1,1,0,1,0,1,1,1,1,0,1,1,1,0,0,1,0,1,0,1,1,1,1,0,1,1,1},{1,0,1,0,1,1,1,1,1,0,1,0,0,0,1,1,1,1,0,1,1,1,1,0,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,0,0,0,1,0,1,1,0,1,0,0},{1,1,1,0,0,0,1,1,1,0,0,1,0,1,1,1,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1},{0,0,1,1,1,0,1,1,1,1,1,0,0,1,1,0,0,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,0,0,1,1,1,0,1,1,1,1,0,0,0,0,1,1,0,0},{1,1,1,0,0,0,1,0,1,1,1,1,1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,1,0,0,1},{0,0,1,0,1,1,1,1,0,0,0,1,0,1,1,0,0,1,0,0,1,1,1,0,1,1,1,0,0,1,0,0,0,1,0,0,1,0,0,1,1,0,1,0,1,1,1,0,0,0},{0,1,0,0,1,0,0,1,0,1,1,0,1,0,0,0,1,1,1,0,0,1,0,0,1,0,1,0,0,0,0,0,1,1,0,1,1,0,1,0,1,0,0,1,1,1,0,0,0,0},{1,0,0,0,0,1,1,1,1,0,0,0,1,1,0,1,1,0,1,0,1,0,1,0,0,1,1,0,1,1,0,1,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0},{1,0,1,0,0,1,1,0,1,1,0,0,1,0,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,1,0,1,0,1,1,1,0,1,1,1,1,0,0,1}};
    //{{0,0,0,0,1,0,1,1,0,0,1,0,1,1,0,1,1,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,1,1,1,1,1,1,0,1,1},{0,1,0,0,0,0,1,1,1,0,1,1,0,0,0,1,0,1,1,1,0,0,1,0,1,0,0,1,0,0,0,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1},{1,0,0,0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,1,0,0,1,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,1,1,1,0,1,1,0,1,0,1,1,1,1},{0,0,0,0,1,1,1,0,1,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,1,1,0,0,1,1,1,0,1,1,1,1,0,1,1,0,0,0,1,1},{0,0,0,0,1,1,1,1,0,1,1,0,0,1,1,1,0,1,1,1,0,1,1,0,0,0,1,0,1,1,1,1,1,0,1,1,0,1,1,0,1,0,0,0,0,0,1,0,0,1},{0,0,1,1,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,0,0,0,0,0,1,0,1},{0,1,0,1,0,0,1,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,0,0,0,0,1,1,0,1,1,0},{0,1,0,0,1,1,1,1,0,1,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,1,0,1,0,0,1,0,1,1,1,0,1,0,0,1,1,1,0,0,1,0,1,0},{0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,1,1,0,1,0,0,1,0,0}};
    //{{0,1,0,0,1,1,0,1,0,0,0,0,0,1,0},{0,1,0,0,0,1,0,1,1,1,0,1,0,1,0},{0,0,0,1,0,1,0,0,0,1,1,0,1,0,0},{0,0,1,1,1,1,0,0,0,0,0,1,1,1,1},{0,0,1,1,0,0,1,0,1,1,1,1,1,0,1},{0,1,1,1,0,0,1,0,1,1,0,1,0,0,1},{0,0,1,1,0,1,1,0,1,1,0,0,0,0,1},{1,0,1,1,1,0,1,1,1,1,0,0,1,1,0},{0,0,0,1,0,1,1,1,0,0,1,1,1,1,1},{0,0,1,1,1,0,0,1,0,0,0,1,0,0,1}};
    //{{1,1,0,0,1,1,0,1,0,0,0,0,0,0,1},{0,1,0,0,0,1,0,1,0,1,0,1,1,1,0},{1,0,0,1,1,1,1,1,0,1,0,1,1,1,0},{0,0,0,1,0,1,0,0,0,1,0,1,0,0,0},{1,1,1,1,0,1,0,0,0,1,1,0,0,1,0},{0,0,1,1,1,0,1,1,1,0,1,0,0,1,1},{1,0,0,1,0,1,0,1,0,1,0,0,1,0,1},{1,1,1,1,1,1,1,0,0,1,0,1,0,0,0},{1,0,0,1,1,1,0,0,1,0,1,0,0,0,0},{0,1,0,0,0,1,1,1,1,0,0,1,0,1,0}};
    //{{1,1,0,0,0},{1,0,0,0,0},{0,0,0,0,1},{0,0,0,1,1}};
    std::cout << numDistinctIslands2(grid) << "\n";
    return 0;
}


/*
 rotation:
 rotate 90 degree clockwise : (x, y) ==> (-y, x)
 rotate 180 degree clockwise: (x, y) ==> (-x, -y)
 rotate 270 degree clockwise: (x, y) ==> (y, -x)

 flip:
 top-bottom : (x, y) ==> (-x, y)
 left-right : (x, y) ==> (x, -y)
 */
