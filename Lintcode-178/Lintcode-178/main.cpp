//
//  main.cpp
//  Lintcode-178
//
//  Created by Jing LUO on 29/7/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>


// Solution 1：

// 将每个点和它的邻接点用map对应起来，一个点可以有很多个neighbors
void mapNodes(std::vector<std::vector<int>> &edges, std::map<int, std::vector<int> *> &nodesMap) {
    for (int i = 0; i < edges.size(); i ++) {
        int start = edges[i][0];
        int end = edges[i][1];
        if (nodesMap[start] == NULL) {
            nodesMap[start] = new std::vector<int>();
        }
        nodesMap[start]->push_back(end);

        if (nodesMap[end] == NULL) {
            nodesMap[end] = new std::vector<int>();
        }
        nodesMap[end]->push_back(start);
    }
}

// 从某一个点开始查找，bfs遍历它的所有邻接点放入queue，再重复取出放入，直到queue为空
void bfs(int start, std::map<int, std::vector<int> *> &nodesMap, std::set<int> &visited) {
    std::queue<int> queue;
    queue.push(start);
    while (queue.size() > 0) {
        int node = queue.front();
        queue.pop();
        if (visited.find(node) != visited.end()) {
            continue;
        }
        visited.insert(node);
        std::vector<int> neighbours = *nodesMap[node];
        for (int i = 0; i < neighbours.size(); i ++) {
            queue.push(neighbours[i]);
        }
    }
}

// 一颗valid tree的条件有3个，1-n个点，2-n-1条edge，3-没有环（判断有没有环可以用并查集），只要满足任意2点，即为valid，这个solution是用满足1，2来判断
bool validTree(int n, std::vector<std::vector<int>> &edges) {
    if (n == 0 || edges.size() != n-1) {
        return false;
    }
    if (n == 1 && edges.size() == 0) {
        return true;
    }
    std::map<int, std::vector<int> *> nodesMap;
    mapNodes(edges, nodesMap);
    int start = edges[0][0];
    std::set<int> visited;
    bfs(start, nodesMap, visited);
    return visited.size() == n;
}


// Solution 2:

// 一颗valid tree的条件有3个，1-n个点，2-n-1条edge，3-没有环（判断有没有环可以用并查集），只要满足任意2点，即为valid，这个solution是用满足2，3来判断

int find(int x, std::vector<int> &father) {
    if (father[x] == -1 || father[x] == x) {
        return x;
    }
    return find(father[x], father);
}

bool validTree2(int n, std::vector<std::vector<int>> &edges) {
    std::vector<int> father(n, -1);

    if (n == 0 || edges.size() != n-1) {
        return false;
    }
    if (n == 1 && edges.size() == 0) {
        return true;
    }
    for (int i = 0; i < edges.size(); i ++) {
        int start = edges[i][0];
        int end = edges[i][1];
        int fStart = find(start, father);
        int fEnd = find(end, father);
        if (fStart == fEnd) { // 表示有共同father，已经有环
            return false;
        }
        father[fStart] = fEnd;  // 将2个father联通
    }
    return true;
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}}; // {}
    std::cout << validTree(5, edges) << "\n";
    std::cout << validTree2(5, edges) << "\n";
    return 0;
}


/*
Solution 1:

###算法
bfs

###代码实现
***有什么要注意的地方
***有什么要优化的地方

###时空复杂度
time O(v+e)， v为graph中总的节点数, e为graph中总的边数。
space O(v)

###相关的题目有哪些
814. Shortest Path in Undirected Graph
750. Portal
589. Connecting Graph
431. Connected Component in Undirected Graph
*/



/*
 Solution 2:

 ###算法
 union find 并查集

 ###代码实现
 ***有什么要注意的地方
 ***有什么要优化的地方

 ###时空复杂度
 time 一个很小的数，参考：https://zh.wikipedia.org/wiki/%E5%B9%B6%E6%9F%A5%E9%9B%86
 space O(n)

 ###相关的题目有哪些
 814. Shortest Path in Undirected Graph
 750. Portal
 589. Connecting Graph
 431. Connected Component in Undirected Graph
 */
