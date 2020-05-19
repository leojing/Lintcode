//
//  main.cpp
//  Lintcode-888
//
//  Created by Jing Luo on 5/19/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool validWordSquare(vector<string> &words) {
    int n = int(words.size());
    bool result = true;
    for (int i = 0; i < n; i ++) {
        string temp = "";
        for (int j = 0; j < n; j ++) {
            if (words[j][i] >= 'a' && words[j][i] <= 'z') { // 当某些字符串较短时，不能把换行字符加进去
                temp += words[j][i];
            }
        }
        if (temp != words[i] || temp == "") {
            return false;
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> words = {"abcd", "bnrt", "crm","dt"};
    std::cout << validWordSquare(words) << "\n";
    return 0;
}



/*
###算法
模拟题
 
###时空复杂度
Time Complexity: O(n*n)
Space Complexity: O(1)

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/

