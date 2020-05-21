//
//  main.cpp
//  Lintcode-514
//
//  Created by Jing Luo on 5/21/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int numWays(int n, int k) {
    vector<int> dp(n+1); // 注意初始化size要是n+1，不然会memory/running error
    dp[0] = k;
    dp[1] = k*k;
    for (int i = 2; i <= n; i ++) {
        dp[i] = (dp[i-1] + dp[i-2]) * (k-1);
    }
    return int(dp[n-1]);
}

int main(int argc, const char * argv[]) {
    std::cout << numWays(3, 2) << "\n";
    return 0;
}

/*
###算法
f(n) = (k-1)(f(n-1)+f(n-2))
用DP，DP[i]表示第i个柱子最多的选择数。在计算DP[i]时，考虑两种情况：
和第i－1柱子不同颜色，则可以有(k-1) * DP[i-1]个选择
和第i－1柱子相同颜色，此时要求i－1柱子和i－2柱子不同颜色（即第一种情况，只是换成了第i－1根柱子和第i－2根柱子不同颜色），所以有(k-1) * DP[i-2]个选择
因此总选择数为(k-1) * (DP[i-1] + DP[i-2])
因为只和前两个柱子相关，所以可以用滚动数组来优化空间


###时空复杂度
Time Complexity: O(n)
Space Complexity: O(n)

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/

