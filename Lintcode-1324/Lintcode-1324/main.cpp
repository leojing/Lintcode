//
//  main.cpp
//  Lintcode-1324
//
//  Created by Jing Luo on 4/29/20.
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

int countPrimes(int n) {
    int count = 0;
    for (int i = 2; i < n; i ++) {
        if (isPrimes(i)) {
            count += 1;
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    std::cout <<  countPrimes(5) << "\n";
    return 0;
}

/*
###算法
 Solution 1:
假如n是合数，必然存在非1的两个约数p1和p2，其中p1<=sqrt(n)，p2>=sqrt(n)。由此我们可以改进上述方法优化循环次数。我们继续分析，其实质数还有一个特点，就是它总是等于 6x-1 或者 6x+1，其中 x 是大于等于1的自然数。

    如何论证这个结论呢，其实不难。首先 6x 肯定不是质数，因为它能被 6 整除；其次 6x+2 肯定也不是质数，因为它还能被2整除；依次类推，6x+3 肯定能被 3 整除；6x+4 肯定能被 2 整除。那么，就只有 6x+1 和 6x+5 (即等同于6x-1) 可能是质数了。所以循环的步长可以设为 6，然后每次只判断 6 两侧的数即可。
 
 ###时空复杂度
 Time Complexity: O(n*判断质数的时间)
 Space Complexity: O(1)

 Solution 2:
 埃拉托斯特尼Eratosthenes筛法：
 https://zh.m.wikipedia.org/zh/%E5%9F%83%E6%8B%89%E6%89%98%E6%96%AF%E7%89%B9%E5%B0%BC%E7%AD%9B%E6%B3%95
 Input: an integer n > 1
  
 Let A be an array of Boolean values, indexed by integers 2 to n,
 initially all set to true.
  
  for i = 2, 3, 4, ..., not exceeding sqrt {n}
   if A[i] is true:
     for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n :
       A[j] := false
  
 Output: all i such that A[i] is true.
 
 Time O(n log log n)
 
###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/


 
