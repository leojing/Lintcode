//
//  main.cpp
//  Lintcode-945
//
//  Created by Luo, Jing on 21/4/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

int leastInterval(string &tasks, int n) {
    int length = int(tasks.length());
    map<char, int> mapping;
    int longest = -1;
    for (int i = 0; i < length; i ++) {
        if (mapping.find(tasks[i]) == mapping.end()) {
            mapping[tasks[i]] = 1;
            continue;
        }
        mapping[tasks[i]] += 1;
        if (mapping[tasks[i]] > longest) {
            longest = mapping[tasks[i]];
        }
    }
    int count = 0;
    map<char, int>::iterator it = mapping.begin();
    while (it != mapping.end()) {
        if (mapping[it->first] == longest) {
            count ++;
        }
        it ++;
    }
    int result = n * (longest - 1) + longest + count - 1;
    return max(length, result);
}

int main(int argc, const char * argv[]) {
    string tasks = "AABBAB";
    std::cout << leastInterval(tasks, 2) << "\n";
    return 0;
}


/*
 （一）先探讨一种可以插空安排完所有任务的schedule模式：
 先找出执行频率最高的任务。最大出现频率的任务的出现频率是M次
 共有Mct个这种任务

 从Mct个这种任务里挑出来某一个这种任务（我们称其为任务A）进行安排。余下的这种任务共有（Mct - 1）个
 对于这个任务A，出现了M次，

 共有（M - 1）个长为N的idle time，此为(M - 1) * N
 执行自身M次。在第一步的基础上，累计时长共为(M - 1) * N + M。
 对于其他（Mct - 1）个和任务A执行频率相同的任务，这些任务除了最后一次执行A以外，都可以安排在多次执行任务A的间隙当中。
 最后一次执行的时候，一个一个安排在最后一次执行A之后，累计时长在之前计算的基础上加上 （Mct - 1）。

 即时间长度为：L = (M - 1) * N + M + Mct - 1
 这段时间内可能还存在slot，看题目给出的冷却时间N的大小。我们把其他执行频次更低的任务插空安排在这段时间里。
 如果给出任务的长度len(tasks) <= 这个长度 L，说明所有任务都可以这样安排完毕，即return该值

 （二）如果这种情况下安排不完，即插空已经把原先的frame“撑爆”了，执行所有任务的累计时间长度退化到len(tasks)。
 我们可以这样理解：（思路credit to 评论区C同学）

 在frame里，slot被撑爆的位置，扩大slot的长度。这次扩大slot是在原有的满足冷却时间的基础上增加冷却长度的，不会违反题目规定；
 在全部按照规则安排好所有任务之后，再把没有安排任务的空白slot缩回去，让任务和任务之间没有空白。
 这样安排下来，时间总长度为len(tasks)。
 （三）答案：以上两种情况哪个长return哪个。
 */
