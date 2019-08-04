//
//  main.cpp
//  Lintcode-127
//
//  Created by Jing LUO on 3/8/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>

struct DirectedGraphNode {
    int label;
    std::vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

std::map<DirectedGraphNode*, int> getInDegree(std::vector<DirectedGraphNode*>& graph) {
    std::map<DirectedGraphNode*, int> map;
    for (int i = 0; i < graph.size(); i ++) {
        if (map.find(graph[i]) == map.end()) {
            map[graph[i]] = 0;
        }
        for (int j = 0; j < graph[i]->neighbors.size(); j ++) {
            DirectedGraphNode *neighbor = graph[i]->neighbors[j];
            if (map.find(neighbor) == map.end()) {
                map[neighbor] = 0;
            }
            map[neighbor] = map[neighbor] + 1;
        }
    }
    return map;
}

// Solution 1: bfs
/*
std::vector<DirectedGraphNode*> topSort(std::vector<DirectedGraphNode*>& graph) {
    std::vector<DirectedGraphNode*> result;
    std::map<DirectedGraphNode*, int> degree = getInDegree(graph);
    std::queue<DirectedGraphNode*> queue;

    if (graph.size() == 0) {
        return result;
    }

    for (int i = 0; i < graph.size(); i ++) {
        if (degree[graph[i]] == 0) {
            queue.push(graph[i]);
        }
    }

    while (queue.size() > 0) {
        DirectedGraphNode *node = queue.front();
        queue.pop();
        result.push_back(node);
        for (int i = 0; i < node->neighbors.size() ; i ++) {
            DirectedGraphNode *neighbor = node->neighbors[i];
            degree[neighbor] = degree[neighbor] - 1;
            if (degree[neighbor] == 0) {
                queue.push(neighbor);
            }
        }
    }

    return result;
}
*/

// Solution 2: dfs

void dfs(DirectedGraphNode *node, std::vector<DirectedGraphNode*>& result, std::map<DirectedGraphNode*, int>& degree) {
    if (degree[node] == -1) {
        return;
    }

    if (degree[node] == 0) {
        degree[node] = -1;
        result.push_back(node);
    }

    for (int i = 0; i < node->neighbors.size(); i ++) {
        DirectedGraphNode *neighbor = node->neighbors[i];
        degree[neighbor] = degree[neighbor] - 1;
        dfs(neighbor, result, degree);
    }
}

std::vector<DirectedGraphNode*> topSort(std::vector<DirectedGraphNode*>& graph) {
    std::vector<DirectedGraphNode*> result;
    std::map<DirectedGraphNode*, int> degree = getInDegree(graph);

    for (int i = 0; i < graph.size(); i ++) {
        if (degree[graph[i]] == 0) {
            dfs(graph[i], result, degree);
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    DirectedGraphNode *node0 = new DirectedGraphNode(0);
    DirectedGraphNode *node1 = new DirectedGraphNode(1);
    DirectedGraphNode *node2 = new DirectedGraphNode(2);
    DirectedGraphNode *node3 = new DirectedGraphNode(3);
    DirectedGraphNode *node4 = new DirectedGraphNode(4);
    DirectedGraphNode *node5 = new DirectedGraphNode(5);

    node0->neighbors = {node1, node2, node3};
    node1->neighbors = {node4};
    node2->neighbors = {node4, node5};
    node3->neighbors = {node4, node5};

    std::vector<DirectedGraphNode*> graph = {node3,node4,node5,node0,node1,node2,};
    std::vector<DirectedGraphNode*> result = topSort(graph);
    std::cout << "Hello, World!\n";
    return 0;
}


/*
###算法
不需要分层的bfs
满足此算法的条件: 拓扑排序

###代码实现
 第一步： 统计每个点的indegree
 第二步：将每个indegree为0的点放入到一个queue中作为起始点
 第三步：不断从queue中拿出一个点放入result，去掉这个点所有的边，其他点的相应的indegree-1
 第四步：一旦发现新的indegree为0的点，重新放入到queue中

***有什么要注意的地方
***有什么要优化的地方

###时空复杂度
time O(v+e)， v为graph中总的节点数, e为graph中总的边数。
space O(v)

###相关的题目有哪些
615. Course Schedule
616. Course Schedule II
*/

