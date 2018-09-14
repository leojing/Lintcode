//
//  main.cpp
//  Lintcode-577
//
//  Created by JINGLUO on 12/9/18.
//  Copyright © 2018 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

struct cmp {
    bool operator()(std::tuple<int, int, Interval> &a, std::tuple<int, int, Interval> &b) {
        return std::get<2>(a).start > std::get<2>(b).start;
    }
};

std::vector<Interval> merge(std::vector<Interval> &intervals) {
    if (intervals.size() <= 1) {
        return intervals;
    }
    
    std::vector<Interval> result;
    
    int start = intervals[0].start;
    int end = intervals[0].end;
    
    for (auto interval : intervals) {
        if (interval.start <= end) {
            end = std::max(end, interval.end);
        } else {
            Interval a(start, end);
            result.push_back(a);
            start = interval.start;
            end = interval.end;
        }
    }
    
    Interval a(start, end);
    result.push_back(a);
    
    return result;
}

std::vector<Interval> mergeKSortedIntervalLists(std::vector<std::vector<Interval>> &intervals) {
    std::priority_queue<std::tuple<int, int, Interval>, std::vector<std::tuple<int, int, Interval>>, cmp> Q;
    
    for (int i = 0; i < intervals.size(); i++) {
        if (!intervals[i].empty()) {
            Q.push(std::make_tuple(i, 0, intervals[i][0]));
        }
    }
    
    std::vector<Interval> result;
    while (!Q.empty()) {
        std::tuple<int, int, Interval> head = Q.top();
        Q.pop();
        
        result.push_back(intervals[std::get<0>(head)][std::get<1>(head)]);
        std::get<1>(head)++;
        if (std::get<1>(head) < intervals[std::get<0>(head)].size()) {
            std::get<2>(head) = intervals[std::get<0>(head)][std::get<1>(head)];
            Q.push(head);
        }
    }
    
    return merge(result);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Interval a = Interval(1, 3);
    Interval b = Interval(4, 7);
    Interval c = Interval(6, 8);
    std::vector<Interval> aVector = {a, b , c};
    Interval d = Interval(1, 2);
    Interval e = Interval(9, 10);
    std::vector<Interval> bVector = {d, e};

    std::vector<std::vector<Interval>> aa = {aVector, bVector};
    std::vector<Interval> result = mergeKSortedIntervalLists(aa);
    std::cout << "Hello, World!\n";
    return 0;
}


/*
 也可用二分法，和104，486类似。
 本题若用priority_queue解法，关键在于使用tuple进行二维数组操作。
 */
