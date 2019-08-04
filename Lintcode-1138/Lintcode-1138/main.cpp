//
//  main.cpp
//  Lintcode-1138
//
//  Created by Jing LUO on 26/7/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>

bool canPlaceFlowers(std::vector<int> &flowerbed, int n) {
    if (flowerbed.size() == 1) {
        if (n == 1 && flowerbed[0] == 0) {
            return true;
        }
        return false;
    }

    for (int i = 0; i < flowerbed.size() - 1; i ++) {
        if (i == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) { // 第一个
            flowerbed[i] = 1;
            n --;
            continue;
        }
        if (flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
            flowerbed[i] = 1;
            n --;
        }
        if (i == flowerbed.size()-2 && flowerbed[i] == 0 && flowerbed[i+1] == 0) { // 倒数第二个
            flowerbed[i+1] = 1;
            n --;
            continue;
        }
    }
    return n <= 0;
}

int main(int argc, const char * argv[]) {
    std::vector<int> flowers = {1,0,0,0,1};
    std::cout << canPlaceFlowers(flowers, 2);
    return 0;
}


/*
###算法
贪心

###代码实现
***有什么要注意的地方
注意第一个和倒数第二个的边界判断
***有什么要优化的地方

###时空复杂度
time O(n), space O(1)

###相关的题目有哪些
Lintcode 1207. Teemo Attacking
Lintcode 1001. Asteroid Collision
*/
