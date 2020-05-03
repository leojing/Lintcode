//
//  main.cpp
//  Lintcode-927
//
//  Created by Jing Luo on 5/2/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void help(string &str, int start, int end) {
    int i = start, j = end;
    while (j > i) {
        swap(str[i], str[j]);
        i ++;
        j --;
    }
}

string reverseWords(string &str) {
    int size = int(str.size());
    help(str, 0, size-1);
    int start = 0;
    int end = 0;
    while (start < size) {
        if (str[start] != ' ') {
            end = start + 1;
            if (end >= size) { // 如果已经到达最后一个单词，要直接输出结果
                help(str, start, end-1);
                return str;
            }
            while (end < size) {
                if (str[end] == ' ') {
                    help(str, start, end-1);
                    start = end;
                    break;
                }
                if (end == size-1) { // 如果已经到达最后一个单词，要直接输出结果
                    help(str, start, end);
                    return str;
                }
                end ++;
            }
        } else {
            start ++;
        }
    }
    return str;
}

int main(int argc, const char * argv[]) {
    string str = "a bs ctr";//" hu hdui hfdi ash ";
    std::cout << reverseWords(str) << "\n";
    return 0;
}


/*
###算法
模拟题，注意最后一位退出条件
 
###时空复杂度
Time Complexity: O(n^2)
Space Complexity: O(1)

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/
