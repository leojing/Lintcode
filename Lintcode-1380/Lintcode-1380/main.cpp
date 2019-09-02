//
//  main.cpp
//  Lintcode-1380
//
//  Created by Jing LUO on 1/9/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

class Log {
public:
    std::string ID;
    std::string content;
    std::string original;
    int index;
    bool isPureNumber;
    Log(std::string ID, std::string content, std::string original, int index, bool isPureNumber) {
        this->ID = ID;
        this->content = content;
        this->original = original;
        this->index = index;
        this->isPureNumber = isPureNumber;
    }
};

bool isPureNumber(std::string content) {
    if (content == "") {
        return false;
    }
    for (int i = 0; i < content.length(); i ++) {
        if ((content[i] >= '0' && content[i] <= '9')) { // 这个地方两个都写成了 >= , 导致WA了2边，细节一定要仔细，不能写错
            return true;
        }
    }
    return false;
}

Log composeLog(std::string log, int index) {
    int firstSpace = 0;
    for (int i = 0; i < log.length(); i ++) {
        if (log[i] == ' ') {
            firstSpace = i;
            break;
        }
    }
    std::string idStr = log.substr(0, firstSpace);
    std::string contentStr = log.substr(firstSpace+1);
    return Log(idStr, contentStr, log, index, isPureNumber(contentStr));
}

//cmp函数的写法是关键
struct cmp
{
    bool operator()(const Log& lhs, const Log& rhs)
    {
        if (lhs.isPureNumber == true && rhs.isPureNumber == false) {
            return false;
        }
        if (lhs.isPureNumber == false && rhs.isPureNumber == false) {
            if(lhs.content == rhs.content) {
                return lhs.ID < rhs.ID;
            }
            return lhs.content < rhs.content;
        }
        if (lhs.isPureNumber == true && rhs.isPureNumber == true) {
            return lhs.index < rhs.index;
        }
        return true;
    }
};

std::vector<std::string> logSort(std::vector<std::string> &logs) {
    std::vector<std::string> result;
    std::vector<Log> logPairs;
    for (int i = 0; i < logs.size(); i ++) {
        logPairs.push_back(composeLog(logs[i], i));
    }
    std::sort(logPairs.begin(), logPairs.end(), cmp());
    for (int i = 0; i < logPairs.size(); i ++) {
        result.push_back(logPairs[i].original);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    std::vector<std::string> logs = //{"sdi"};
    {"zo4 4 7","a100 Act zoo", "a100 Actzoo", "a1 9 2 3 1","g9 act car", "ytf b ghh g bvj"};
    logSort(logs);
    std::cout << "Hello, World!\n";
    return 0;
}


/*
 ###算法
 普通遍历+sort

 ###代码实现
 ***有什么要注意的地方
 参考代码注释
 ***有什么要优化的地方

 ###时空复杂度
 Time complexity: O(NLogN),主要是sort的时间复杂度是NlogN
 Space complexity: O(N)

 ###相关的题目有哪些
 */


