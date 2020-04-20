//
//  main.cpp
//  Lintcode-1186
//
//  Created by Luo, Jing on 20/4/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, string> encodeMap;
map<string, string> decodeMap;
int k = 0;

string encode(string &longUrl) {
    if (encodeMap.find(longUrl) != encodeMap.end()) {
        return encodeMap[longUrl];
    }
    encodeMap[longUrl] = to_string(k++);
    decodeMap[encodeMap[longUrl]] = longUrl;
    return encodeMap[longUrl];
}

string decode(string shortUrl) {
    return decodeMap[shortUrl];
}

int main(int argc, const char * argv[]) {
    string encodeA = "http:nvjdf.jief.vjdf";
    string a = encode(encodeA);
    std::cout << a << "\n";
    string encodeB = "http:ngoogle.df";
    string b = encode(encodeB);
    string A = decode("1");
    std::cout << A << "\n";
    return 0;
}
