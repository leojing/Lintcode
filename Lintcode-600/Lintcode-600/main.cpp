//
//  main.cpp
//  Lintcode-600
//
//  Created by JINGLUO on 19/6/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

int minX, minY, maxX, maxY;
std::vector<std::vector<int>> dire = {{0,1}, {0,-1}, {1,0}, {-1,0}};

//Solution 1:

void helper(std::vector<std::vector<char>> &image, int x, int y, char mark) {
    int rows = int(image.size());
    int columns = int(image[0].size());
    if (x < 0 || x >= rows || y < 0 || y >= columns || image[x][y] == mark || image[x][y] == '0') { // 剪枝 + edge case. image[x][y] == mark 保证不重复地走已经走过的点。image[x][y] == '0' 是因为所有的‘1’都相连，所以没必要走为‘0’的点，只要走‘1’的点就可以通过4个方向找打所有其他‘1’， 这样的话，其实递归的次数为‘1’的个数，但是不影响time complexity仍然为O(M*N)
        return;
    }
    // 更新边界值
    if (minX > x) {
        minX = x;
    }
    if (maxX < x) {
        maxX = x;
    }
    if (minY > y) {
        minY = y;
    }
    if (maxY < y) {
        maxY = y;
    }
    // 标记为已走过的点
    image[x][y] = mark;
    for (int i = 0; i < 4; i ++) {
        int newX = x + dire[i][0];
        int newY = y + dire[i][1];
        helper(image, newX, newY, mark);
    }
}

int minArea1(std::vector<std::vector<char>> &image, int x, int y) {
    int rows = int(image.size());
    if (rows == 0) {
        return 0;
    }
    int columns = int(image[0].size());
    if (columns == 0) {
        return 0;
    }
    minX = x;
    maxX = x;
    minY = y;
    maxY = y;
    helper(image, x, y, 'a');
    return (maxX - minX + 1) * (maxY - minY + 1);
}


/*
###算法
DFS递归查找

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
BCR is O(M*logN), 用solution 2的二分法可以优化，solution 1通过剪枝，已经最优。Space complexity is O(1), 没有开辟额外空间，已经最优

###时空复杂度
time O(M*N)
space O(1)

###相关的题目有哪些
*/



// Solution 2:

int helperForPosition(std::vector<char> &A, char target, int start, int end, bool isFirst) {
    int mid;
    while (start + 1 < end) {
        mid = start + (end - start) / 2;
        if (A[mid] - '0' == target - '0') {
            if (isFirst) {
                end = mid;
            } else {
                start = mid;
            }
            return helperForPosition(A, target, start, end, isFirst);
        } else {
            // 如果不等于目标值，要向左右两边都搜索 or check哪边有‘1’就向哪边搜
            int left = helperForPosition(A, target, start, mid, isFirst);
            int right = helperForPosition(A, target, mid, end, isFirst);
            // 判断的顺序很重要，是否找first position决定了先返回left还是right
            if (isFirst) {
                if (left != -1) {
                    return left;
                } else {
                    return right;
                }
            } else {
                if (right != -1) {
                    return right;
                } else {
                    return left;
                }
            }
        }
    }
    // 判断的顺序很重要，是否找first position决定了先返回start还是end
    if (isFirst) {
        if (A[start] - '0' == target - '0') {
            return start;
        }
        if (A[end] - '0' == target - '0') {
            return end;
        }
    } else {
        if (A[end] - '0' == target - '0') {
            return end;
        }
        if (A[start] - '0' == target - '0') {
            return start;
        }
    }
    return -1;
}

int minArea2(std::vector<std::vector<char>> &image, int x, int y) {
    int rows = int(image.size());
    if (rows == 0) {
        return 0;
    }
    int columns = int(image[0].size());
    if (columns == 0) {
        return 0;
    }
    int r = 0; // 用来记录有多少层包含‘1’
    minX = INT_MAX;
    maxX = INT_MIN;
    for (int i = 0; i < image.size(); i ++) {
        std::vector<char> row = image[i];
        int first = helperForPosition(row, '1', 0, int(image[i].size() - 1), true);
        int last = helperForPosition(row, '1', 0, int(image[i].size() - 1), false);
        if (first != -1 && last != -1) {
            r ++;
            // 不断去更新X的边界
            if (first < minX) {
                minX = first;
            }
            if (last > maxX) {
                maxX = last;
            }
        }
    }
    return r * (maxX - minX + 1);
}


/*
###算法
二分法

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
BCR is O(logN), time complexity已经是最优解， same as space complexity

###时空复杂度
time O(M*logN), M(rows)次first position O(logN) + last position O(logN) = O(2LogN) == O(M*logN)
space O(N)

###相关的题目有哪些
*/


int main(int argc, const char * argv[]) {
    std::vector<std::vector<char>> image = {{'0','0','1','1'}, {'0','1','1','0'}, {'0','1','0','0'}};
    std::cout << minArea2(image, 0, 2) << "\n";
    std::cout << minArea1(image, 0, 2) << "\n";
    return 0;
}
