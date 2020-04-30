//
//  main.cpp
//  Lintcode-1046
//
//  Created by Jing Luo on 5/1/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <math.h>

bool isPrimes(int n) {
    if (n <= 3) {
        return n > 1;
    }
    if (n % 6 != 1 && n % 6 != 5) {
        return false;
    }
    double s = sqrt(n);
    for (int i = 5; i <= int(s); i += 6) {
        if (n % i == 0 || n % (i+2) == 0) {
            return false;
        }
    }
    return true;
}

int countBits(int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n = n >> 1;
    }
    return count;
}

int countPrimeSetBits(int L, int R) {
    int result = 0;
    for (int i = L; i <= R; i ++) {
        int count = countBits(i);
        if (isPrimes(count)) {
            result += 1;
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    std::cout <<  countPrimeSetBits(6, 10) << "\n";
    return 0;
}
