//
//  main.cpp
//  Lintcode-6
//
//  Created by Luo, Jing on 23/3/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
    vector<int> result;
    
    int Alength = int(A.size());
    int Blength = int(B.size());
    int i = 0, j = 0;
    while (i < Alength && j < Blength) {
        if (A[i] < B[j]) {
            result.push_back(A[i]);
            i++;
        } else {
            result.push_back(B[j]);
            j++;
        }
    }
    if (i != Alength) {
        result.insert(result.end(), A.begin()+i, A.end());
    } else if (j != Blength) {
        result.insert(result.end(), B.begin()+j, B.end());
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> A = {1,2,3,4,5,27,33,43,98,109};
    vector<int> B = {3,5,8,28};
    vector<int> result = mergeSortedArray(A, B);
    std::cout << result.size();
    return 0;
}
