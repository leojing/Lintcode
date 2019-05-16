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

void visitMatrix(std::vector<std::vector<int>> &matrix, int k, std::priority_queue<int> &pq, std::set<std::tuple<int, int>> &visited, int x, int y) {
    int row = int(matrix.size());
    int colum = int(matrix[0].size());
    if (x < row && y < colum) {
        std::tuple<int, int> t = std::make_tuple(x,y);
        if (visited.find(t) != visited.end()) {
            return;
        }
        if (pq.size() < k) {
            pq.push(matrix[x][y]);
        } else {
            int top = pq.top();
            if (top > matrix[x][y]) {
                pq.pop();
                pq.push(matrix[x][y]);
            }
        }
        visited.insert(t);
        visitMatrix(matrix, k, pq, visited, x+1, y);
        visitMatrix(matrix, k, pq, visited, x, y+1);
    }
    return;
}

int kthSmallest(std::vector<std::vector<int>> &matrix, int k) {
    if (matrix.size() == 0) {
        return 0;
    }
    std::priority_queue<int> pq;
    std::set<std::tuple<int, int>> visited;
    visitMatrix(matrix, k, pq, visited, 0, 0);
    return pq.top();
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> matrix;
    std::vector<int> row1, row2, row3;
    row1.push_back(532);
    row1.push_back(22);
    row1.push_back(42);
    row1.push_back(5462);

    row2.push_back(24);
    row2.push_back(232);
    row2.push_back(432);
    row2.push_back(682);

    row3.push_back(8752);
    row3.push_back(243);
    row3.push_back(254);
    row3.push_back(345442);

//    matrix.push_back(row1);
//    matrix.push_back(row2);
//    matrix.push_back(row3);
    std::cout << kthSmallest(matrix, 10) << "\n";
    return 0;
}
