//
//  main.cpp
//  Lintcode-1361
//
//  Created by Jing Luo on 4/27/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string fulfillSpace(int num) {
    string result = "";
    while (num --) {
        result += " ";
    }
    return result;
}

vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> result;
    vector<int> lines;
    vector<int> totalForLine;
    int i = 0;
    int j = 0;
    int total = 0;
    int k = 0;
    // 先将单词分组截断
    while (i < words.size()) {
        if (k == 0 && words[i].size() <= maxWidth) {
            total += words[i].size();
            i ++;
            j ++;
            k ++;
            continue;
        }
        if (total + words[i].size() + 1 <= maxWidth) {
            total += words[i].size() + 1;
            i ++;
            j ++;
            k ++;
            continue;
        }
        lines.push_back(j - 1);
        totalForLine.push_back(total - k + 1);
        total = 0;
        k = 0;
    }
    lines.push_back(j - 1);
    totalForLine.push_back(total - k + 1);

    j = 0;
    string current = "";
    // 重组string
    for (int i = 0; i < words.size(); i ++) {
        int totalChar = totalForLine[j];
        int currentSize = lines[j] - lines[j-1];
        if (j == 0) {
            currentSize = lines[j] + 1;
        }
        // 处理只有一个单词的情况
        if (currentSize == 1) {
            current = words[i] + fulfillSpace(maxWidth - totalChar);
            result.push_back(current);
            j ++;
            current = "";
            continue;
        }
        // 处理最后一组，需要左移
        if (j == lines.size() - 1) {
            current += words[i];
            if (i != lines[j]) {
                current += fulfillSpace(1);
            } else {
                current += fulfillSpace(maxWidth - totalChar - currentSize + 1);
                result.push_back(current);
            }
            continue;
        }
        // 处理普通情况
        int everage = (maxWidth - totalChar) / (currentSize-1);
        int more = (maxWidth - totalChar) % (currentSize-1);
        current += words[i];
        if (i != lines[j]) {
            current += fulfillSpace(everage);
            // 从左往右填充多余的空格
            if ((j == 0 && i < more) || (j != 0 && (i - lines[j-1] - 1 < more))) {
                current += fulfillSpace(1);
            }
        } else {
            result.push_back(current);
            current = "";
            j ++;
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> words = {"Here","is","an","example","of","text","justification."};
    //{"This", "is","an","eple","of","text","justificjjn."};
    vector<string> result = fullJustify(words, 15);
    std::cout << result.size() << "\n";
    return 0;
}


/* Test case:
 只有一行
 刚好是maxWidth长度的单词
*/

/*
###算法
模拟题，根据不同情况进行解析
 
###时空复杂度
Time Complexity: O(n)
Space Complexity: O(n)

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/
