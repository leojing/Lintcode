//
//  main.cpp
//  Lintcode-156
//
//  Created by Luo, Jing on 14/4/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

struct cmp {
    bool operator()(const Interval& lhs, const Interval& rhs) {
        if (lhs.start == rhs.start) {
            return lhs.end < rhs.end;
        }
        return lhs.start < rhs.start;
    }
};

vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.size() == 1 || intervals.size() == 0) {
        return intervals;
    }
    sort(intervals.begin(), intervals.end(), cmp());
    int k = 0;
    int start = intervals[0].start;
    int end = intervals[0].end;
    for (int i = 1; i < intervals.size(); i ++) {
        if (intervals[i].start <= end) {
            end = max(intervals[i].end, end); // 注意，如果是(1,3),(2,6),(3,5)这样的数据，要注意取最大的作为end
            continue;
        }
        intervals[k++] = Interval(start, end);
        start = intervals[i].start;
        end = intervals[i].end;
    }
    intervals[k] = Interval(start, end); // 最后一组结果，别忘记放进去
    vector<Interval> result = {intervals.begin(), intervals.begin()+k+1};
    return result;
}

int main(int argc, const char * argv[]) {
    vector<Interval> intervals = {Interval(8,10), Interval(1,2), Interval(2,6), Interval(1,3), Interval(3,5), Interval(15,16)};
    vector<Interval> result = merge(intervals);
    std::cout << result.size() << "\n";
    return 0;
}


/*
###算法
模拟题，先排序，根据顺序，一个一个merge，并且用merge好的新区间，从0开始替换intervals的值，避免开辟新的空间
 
###时空复杂度
Time Complexity: O(NLog(N)),主要排序用了NLogN的时间，之后就是N的遍历
Space Complexity: O(1)，因为是放回到原来的intervals数组里的，所有没有额外开辟空间

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/

