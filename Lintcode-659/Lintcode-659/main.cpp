//
//  main.cpp
//  Lintcode-659
//
//  Created by Jing Luo on 4/30/22.
//

#include <iostream>
#include <vector>

using namespace std;

string encodeStr(string &str) {
    return str + ":";
 }

string encode(vector<string> &strs) {
    // write your code here
    string result = "";
    for (auto str: strs) {
        result += encodeStr(str) + ";";
    }
    return result;
}

/*
 * @param str: A string
 * @return: dcodes a single string to a list of strings
 */
 string decodeStr(string &str) {
     return str.substr(0, str.length()-1);
 }

vector<string> decode(string &str) {
    // write your code here
    vector<string> result;
    string temp = "";
    for (int i = 0; i < str.length(); i ++) {
        if (str[i] == ';') {
            result.emplace_back(decodeStr(temp));
            temp = "";
            continue;
        }
        temp += str[i];
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> strs = {"linnnnttt","code","love","you"};
    string encoded = encode(strs);
    vector<string> decoded = decode(encoded);
    std::cout << encoded << "\n";
    return 0;
}
