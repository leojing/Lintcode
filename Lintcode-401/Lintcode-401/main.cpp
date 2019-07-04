//
//  main.cpp
//  Lintcode-401
//
//  Created by JINGLUO on 24/11/18.
//  Copyright © 2018 JINGLUO. All rights reserved.
//

#include <iostream>
#include <queue>
#include <set>
#include <tuple>

class Node {
public:
    int val, X, Y;
    Node(int v, int x, int y) {
        val = v;
        X = x;
        Y = y;
    }
};

struct CustomCompare
{
    bool operator()(const Node& lhs, const Node& rhs)
    {
        return lhs.val > rhs.val; // priority_queue 这个比大小是反过来的，如果希望最小的在top，那么left > right
    }
};

int visitMatrix(std::vector<std::vector<int>> &matrix, int k, std::priority_queue<Node, std::vector<Node>, CustomCompare> &pq, std::set<std::tuple<int, int>> &visited) {
    int row = int(matrix.size());
    int colum = int(matrix[0].size());
    pq.push(Node(matrix[0][0], 0, 0)); // 现将0，0的点放入，这个肯定是最小的
//    k --;
    while (--k) {
        Node top = pq.top();
        pq.pop();
        if (top.X + 1 < row) { // 保证没有越界
            std::tuple<int, int> t = std::make_tuple(top.X + 1,top.Y);
            if (visited.find(t) == visited.end()) { // 保证只放入没有找过的点，找过的点就不需要重复放入了
                pq.push(Node(matrix[top.X + 1][top.Y], top.X + 1, top.Y));
                visited.insert(t);
            }
        }
        if (top.Y + 1 < colum) { // 保证没有越界
            std::tuple<int, int> t = std::make_tuple(top.X,top.Y + 1);
            if (visited.find(t) == visited.end()) { // 保证只放入没有找过的点，找过的点就不需要重复放入了
                pq.push(Node(matrix[top.X][top.Y + 1], top.X, top.Y + 1));
                visited.insert(t);
            }
        }
    }
    Node result = pq.top();
    return result.val;
}

int kthSmallest(std::vector<std::vector<int>> &matrix, int k) {
    if (matrix.size() == 0) {
        return 0;
    }
    std::priority_queue<Node, std::vector<Node>, CustomCompare> pq;
    std::set<std::tuple<int, int>> visited;
    return visitMatrix(matrix, k, pq, visited);
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> matrix;
    std::vector<int> row1, row2, row3;
    row1.push_back(1);
    row2.push_back(2);
    row3.push_back(3);
    row1.push_back(4);

    row3.push_back(5);
    row2.push_back(6);
    row1.push_back(7);
    row2.push_back(8);

    row1.push_back(9);
    row2.push_back(10);
    row3.push_back(11);
    row3.push_back(12);

    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    std::cout << kthSmallest(matrix, 10) << "\n";
    return 0;
}


/*
###算法
模拟题，不能用DFS，否则会TLE

###代码实现
***有什么要注意的地方
参考注释代码
***有什么要优化的地方

###时空复杂度分析
Time O(KlogT)，查找K次，每次进行（一次pq.pop()=logT，两次pq.push()=2logT）,T为pq的大小，每次删减操作需要的时间为logT
Space O(n)，n为pq的大小，也是n is the maximum of the width and height of the matrix.

###相关题目
Leetcode 988. Smallest String Starting From Leaf
*/
