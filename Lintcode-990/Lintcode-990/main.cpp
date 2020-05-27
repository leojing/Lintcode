//
//  main.cpp
//  Lintcode-990
//
//  Created by Jing Luo on 5/27/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>

using namespace std;

/* 这种写法也能跑出正确结果，思路和后面正确的解法是一模一样的，典型的dfs，但是会TLE，能不开辟新的空间和参数，就尽量不要，能不用SLT中封装好的map或者vector，就尽量不要用
 vector<vector<int>> valids = {
     {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
     {1,2,4,6,8,10,12,14},
     {1,3,6,9,12,15},
     {1,2,4,8,12,},
     {1,5,10,15},
     {1,2,3,6,12},
     {1,7,14},
     {1,2,4,8},
     {1,3,9},
     {1,2,5,10},
     {1,11},
     {1,2,3,4,6,12},
     {1,13},
     {1,2,7,14},
     {1,3,5,15}
 };

 int result = 0;

 void dfs(int N, int index, map<int, bool> &visited, vector<int> &current) {
     if (current.size() == N) {
         result += 1;
         return;
     }
     if (index >= N) {
         return;
     }
     for (int i = 0; i < valids[index].size(); i ++) {
         int t = valids[index][i];
         if (!visited[t] && t <= N) {
             visited[t] = 1;
             current.push_back(t);
             dfs(N, index + 1, visited, current);
             current = {current.begin(), current.end()-1};
             visited[t] = 0;
         }
     }
 }

 int countArrangement(int N) {
     map<int, bool> visited;
     vector<int> current;
     dfs(N, 0, visited, current);
     return result;
 }
 */

int result = 0;

void dfs(int N, int index, bool visited[16]) {
    if (index == N+1) {
        result += 1;
        return;
    }
    for (int i = 1; i <= N; i ++) {
        if (visited[i] == false && (i%index == 0 || index%i == 0)) {
            visited[i] = true;
            dfs(N, index + 1, visited);
            visited[i] = false;
        }
    }
}

int countArrangement(int N) {
    bool visited[16] = {false}; // 记得要初始化
    dfs(N, 1, visited);
    return result;
}

int main(int argc, const char * argv[]) {
    std::cout << countArrangement(12) << "\n";
    return 0;
}


/*
###算法
典型的dfs+backtracking
 
###时空复杂度
Time Complexity: O(n!)
Space Complexity: O(n)

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/
