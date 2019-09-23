//
//  main.cpp
//  Lintcode-1713
//
//  Created by Jing LUO on 23/9/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

string reformattedEmail(string email) {
    bool hasPlus = false;
    bool isLocal = true;
    string newEmail;
    for (int i = 0; i < email.size(); i ++) {
        if (email[i] == '+') {
            hasPlus = true;
        }
        if (email[i] == '@') {
            hasPlus = false;
            isLocal = false;
        }
        if (hasPlus) {
            continue;
        }
        if (!isLocal) {
            newEmail.append(email.substr(i,1));
        } else {
            if (email[i] != '.') {
                newEmail.append(email.substr(i,1));
            }
        }
    }
    return newEmail;
}

int numUniqueEmails(vector<string> &emails) {
    set<string> *result = new set<string>();
    for (int i = 0; i < emails.size(); i ++) {
        if (emails[i].size() == 0) {
            continue;
        }
        string newEmail = reformattedEmail(emails[i]);
        result->insert(newEmail);
    }
    return int(result->size());
}

int main(int argc, const char * argv[]) {
    vector<string> emails = {"test.email+alex@lintcode.com","test.e.mail+bob.cathy@lintcode.com","testemail+david@lin.tcode.com"};
    std::cout << numUniqueEmails(emails) << "\n";
    return 0;
}


/*
###算法
模拟题，for循环emails肯定是不可避免的，主要优化在reformattedEmail(),虽然可以先找到第一个'+'和'@'，再for循环去掉多余的'.',但是实现起来感觉还是繁琐，然后就想到了，其实一个for从头走到尾，把合格的字符添加到newEmail就可以了。

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方

###时空复杂度
Time complexity: O(n*m)，n为email个数，m为每个email的长度
Space complexity: O(n)，n为email个数

###相关的题目有哪些
*/

