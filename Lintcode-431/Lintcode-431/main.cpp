//
//  main.cpp
//  Lintcode-431
//
//  Created by Jing LUO on 30/7/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

struct UndirectedGraphNode {
    int label;
    std::vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};


// Solution 1: Union find

std::map<int, int> father;

int find(int x) {
    if (father.find(x) == father.end() || father[x] == x) {
        return x;
    }
    return father[x] = find(father[x]);
}

std::vector<std::vector<int>> connectedSet(std::vector<UndirectedGraphNode*> nodes) {
    std::map<int, std::set<int>*> connectSet;
    std::vector<std::vector<int>> result;

    for (int i = 0; i < nodes.size(); i ++) {
        int start = nodes[i]->label;
        int fStart = find(start);
        for (int j = 0; j < nodes[i]->neighbors.size(); j ++) {
            int end = nodes[i]->neighbors[j]->label;
            int fEnd = find(end);
            if (fStart != fEnd) {
                father[fEnd] = fStart;  // 将2个father联通
                int target = find(fStart);
                if (connectSet[target] == NULL) {
                    connectSet[target] = new std::set<int>();
                }
                connectSet[target]->insert(start);
                connectSet[target]->insert(end);
            }
        }
    }

    std::map<int, std::set<int>*>::iterator iter = connectSet.begin();
    for (iter = connectSet.begin(); iter != connectSet.end(); iter ++) {
        std::set<int>* input = iter->second;
        std::vector<int> output(input->begin(), input->end());
        result.push_back(output);
    }
    return result;
}



// Solution 2: bfs
/*
std::vector<int> bfs(UndirectedGraphNode *node, std::set<int> &visited) {
    std::queue<UndirectedGraphNode*> queue;
    std::vector<int> result;
    queue.push(node);
    while (queue.size() > 0) {
        UndirectedGraphNode *n = queue.front();
        queue.pop();
        if (visited.find(n->label) == visited.end()) {
            result.push_back(n->label);
            visited.insert(n->label);
        }
        for (int i = 0; i < n->neighbors.size(); i ++) {
            UndirectedGraphNode *neighbor = n->neighbors[i];
            if (visited.find(neighbor->label) == visited.end()) {
                queue.push(neighbor);
            }
        }
    }
    std::sort(result.begin(), result.end());
    return result;
}

std::vector<std::vector<int>> connectedSet(std::vector<UndirectedGraphNode*> nodes) {
    std::vector<std::vector<int>> result;
    std::set<int> visited;

    for (int i = 0; i < nodes.size(); i ++) {
        UndirectedGraphNode *node = nodes[i];
        std::vector<int> r = bfs(node, visited);
        if (r.size() > 0) {
            result.push_back(r);
        }
    }
    return result;
}
*/

int main(int argc, const char * argv[]) {
    UndirectedGraphNode *node1 = new UndirectedGraphNode(1);
    UndirectedGraphNode *node2 = new UndirectedGraphNode(2);
    UndirectedGraphNode *node3 = new UndirectedGraphNode(3);
    UndirectedGraphNode *node4 = new UndirectedGraphNode(4);
    UndirectedGraphNode *node5 = new UndirectedGraphNode(5);

    node1->neighbors = {node4, node2};
    node3->neighbors = {node5};
    node2->neighbors = {node4, node1};
    std::vector<UndirectedGraphNode *> nodes = {node1,node2,node3}; //{1}
    connectedSet(nodes);
    return 0;
}


/*
Solution 2:

###算法
bfs

###代码实现
***有什么要注意的地方
***有什么要优化的地方

###时空复杂度
time O(v+e)， v为graph中总的节点数, e为graph中总的边数。
space O(v)

###相关的题目有哪些
178. Graph Valid Tree
432. Find the Weak Connected Component in the Directed Graph
*/

