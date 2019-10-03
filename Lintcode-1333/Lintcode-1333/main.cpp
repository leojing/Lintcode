//
//  main.cpp
//  Lintcode-1333
//
//  Created by Jing LUO on 3/10/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>


long long helper(long long n, int index) {  // 假设n为10...001(32位)，index为0，即最后一位
    if (index == 31) {
        return n;
    }
    long long last = n & 1;  // 得到最后一位为1（如果最后一位是0，这里就是0），保证前面都为0
    long long rest = helper(n >> 1, index + 1); // 递归去取倒数第二位开始的反转结果，即长度为31的反转结果
    return rest + (last << (31 - index)); // 将last左移31位即得到1000.0000(32位)，j和rest相加就是将last移到rest的第一位
}

long long reverseBits(long long n) {
    return helper(n, 0);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << reverseBits(2) << "\n";
    return 0;
}
