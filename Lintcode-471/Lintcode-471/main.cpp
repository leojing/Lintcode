//
//  main.cpp
//  Lintcode-471
//
//  Created by JINGLUO on 20/8/18.
//  Copyright © 2018 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

typedef std::pair<std::string, int> PAIR;
typedef std::map<std::string, int> MAP;
typedef std::vector<std::string> StringVector;

struct CmpByValue {
    bool operator()(const PAIR& lhs, const PAIR& rhs) {
        if (lhs.second == rhs.second) {
            return lhs.first < rhs.first;
        }
        return lhs.second > rhs.second;
    }
};


StringVector topKFrequentWords(StringVector &words, int k) {
    MAP wordNumberMap;
    std::vector<std::string> result;
    
    for (int i = 0; i < words.size(); i ++) {
        wordNumberMap[words[i]] ++;
    }
    
    std::vector<PAIR> pairedWord(wordNumberMap.begin(), wordNumberMap.end());
    sort(pairedWord.begin(), pairedWord.end(), CmpByValue());

    for (int i = 0; i < pairedWord.size(); i ++) {
        if (i < k) {
            result.push_back(pairedWord[i].first);
        } else {
            break;
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int k, i;
    StringVector words, result;
    for (i = 0; i < 80; i ++) {
        std::string word;
        std::cin >> word;
        words.push_back(word);
    }
    std::cin >> k;
    result = topKFrequentWords(words, k);
    for (i = 0; i < result.size(); i ++) {
        std::cout << result[i] << " ";
    }
    
    return 0;
}
