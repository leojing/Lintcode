//
//  main.cpp
//  Lintcode-371
//
//  Created by Jing LUO on 8/10/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

void helper(vector<int> *result, string current, int index, int n) {
    if (index == n) { // 已经递归到n位数，直接退出
        return;
    }
    int start = (index == 0) ? 1 : 0; // 注意第一位不能为0，0也不需要放入result，所以当遍历第一层的时候，排除掉0，之后的所有层，都需要有0
    for (int i = start; i <= 9; i ++) { // 在每一位数上，遍历添加start-9
        current.append(to_string(i)); // 添加一位数字到current
        result->push_back(stoi(current)); // 每次得到的current转换成int放入结果
        helper(result, current, index + 1, n); // 基于当前current的值，进行下一位数字的递归，即往current后添加一位新数字（从0-9循环）
        current = current.substr(0, current.size()-1);  // 这里注意要回溯下，把current的最后一位去掉，再添加下一个数字
    }
}

vector<int> numbersByRecursion(int n) {
    vector<int> result;
    helper(&result, "", 0, n);
    sort(result.begin(), result.end());  // 注意要进行排序
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> result = numbersByRecursion(3);
    std::cout << result.size() << "\n";
    return 0;
}


/*
###算法
有点类似Permutation的递归解法

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###时空复杂度
Time complexity: O(10的N次),每一位上都要进行10次便利，一共进行N轮
Space complexity: O(10的N次)

###相关的题目有哪些
15. Permutation
*/
