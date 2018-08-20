//
//  main.cpp
//  Lintcode-1001
//
//  Created by Jing Luo on 19/8/18.
//  Copyright © 2018 Jing Luo. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

std::vector<int> updateForAsteroidCollision(std::vector<int> &asteroids) {
    std::vector<int> result;
    
    int i = 0;
    result.push_back(asteroids[i]);
    for (i = 1; i < asteroids.size(); i ++) {
        int lastInResult = result.back();
        if (lastInResult > 0) {
            if (asteroids[i] > 0) {
                result.push_back(asteroids[i]);
            } else {
                int currentNum = abs(asteroids[i]);
                if (lastInResult > currentNum) {
                    continue;
                } else if (lastInResult < currentNum) {
                    result.pop_back();
                    result.push_back(asteroids[i]);
                } else {
                    result.pop_back();
                }
            }
        } else {
            result.push_back(asteroids[i]);
        }
    }
    
    if (result.size() == asteroids.size()) {
        return result;
    }
    
    return updateForAsteroidCollision(result);
}

std::vector<int> asteroidCollision(std::vector<int> &asteroids) {
    // write your code here
    std::vector<int> result;
    result = updateForAsteroidCollision(asteroids);
    return result;
}

int main(int argc, const char * argv[]) {
    
    int n, i = 0;
    std::vector<int> obj, result;
    std::cin >> n;
    for (i = 0; i < n; i ++) {
        int a;
        std::cin >> a;
        obj.push_back(a);
    }
    
    result = asteroidCollision(obj);
    std::cout << (&result)->size() << "\n";
    
    return 0;
}
