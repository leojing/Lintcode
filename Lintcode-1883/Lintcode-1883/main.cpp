//
//  main.cpp
//  Lintcode-1883
//
//  Created by Jing Luo on 5/6/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef pair<string, int> Word;

struct cmp {
    bool operator()(const Word &a, const Word &b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second;
    }
};

map<string, int> countForRequest(string request) {
    map<string, int> result;
    int i = 0;
    string word = "";
    while (i < request.size()) {
        if (request[i] >= 'A' && request[i] <= 'Z') {
            word += request[i] - 'A' + 'a';
        } else if (request[i] >= 'a' && request[i] <= 'z') {
            word += request[i];
        } else if (request[i] == ' ') {
            if (result.find(word) != result.end()) {
                result[word] += 1;
            } else {
                result[word] = 1;
            }
            word = "";
        }
        i ++;
    }
    if (result.find(word) != result.end()) {
        result[word] += 1;
    } else {
        result[word] = 1;
    }
    return result;
}

vector<string> TopkKeywords(int K, vector<string> &keywords, vector<string> &reviews) {
    vector<string> result;
    map<string, Word> wordForFeature;
    for (int i = 0; i < keywords.size(); i ++) {
        string feature = keywords[i];
        wordForFeature[feature] = Word(feature, 0);
    }
    
    for (int i = 0; i < reviews.size(); i ++) {
        map<string, int> review = countForRequest(reviews[i]);
        for (int j = 0; j < keywords.size(); j ++) {
            string feature = keywords[j];
            if (review.find(feature) != review.end()) {
                wordForFeature[feature].second += 1;
            }
        }
    }
    
    vector<Word> q;
    for (auto word: wordForFeature) {
        q.push_back(word.second);
    }
    sort(q.begin(), q.end(), cmp());
    int qSize = int(q.size());
    int n = K <= qSize ? K : qSize;
    for (int i = 0; i < n ; i ++) {
        result.push_back(q[i].first);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> keywords = {"a", "b"};
    vector<string> reviews = {"tt sy a b", "y a s", "b s a"};
    vector<string> result = TopkKeywords(1, keywords, reviews);
    std::cout << "Hello, World!\n";
    return 0;
}
