//
//  main.cpp
//  Lintcode-919
//
//  Created by JINGLUO on 3/6/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

int minMeetingRooms(std::vector<Interval> &intervals) {
    int rooms = 0;
    int maxRooms = 0;
    std::vector<std::pair<int, int>> meetings = std::vector<std::pair<int, int>>();
    for (int i = 0; i < intervals.size(); i ++) {
        meetings.push_back(std::make_pair(intervals[i].start, 1));
        meetings.push_back(std::make_pair(intervals[i].end, -1));
    }
    std::sort(meetings.begin(), meetings.end());
    
    for (int i = 0; i < meetings.size(); i ++) {
        rooms += std::get<1>(meetings[i]);
        maxRooms = std::max(rooms, maxRooms);
    }
    return maxRooms;
}

int main(int argc, const char * argv[]) {
    std::vector<Interval> rooms = {Interval(0,30), Interval(5,10), Interval(15,20), Interval(20,30), Interval(25,40), Interval(45,60), Interval(40,55)};
    std::cout << minMeetingRooms(rooms) << "\n";
    return 0;
}


/*
 ###算法
 Method 1: queue/heap，未实现，TODO
 Method 2: 扫描线，上面👆代码已实现
 
 ###代码实现
 将meeting的其实和终止时间拆分成两个端点，分别给时间标记上会议开始或结束，放到meetings数组中
 对meetings数组按照时间先后顺序排序，然后扫描
 - 遇到会议时间是开始的，就把当前会议数量+1
 - 遇到会议时间是结束的，就把当前会议数量-1
 - 每扫描一个会议的时间端点，就更新当前会议的数量和最大会议的数量

 ###时空复杂度
 time O(n)
 space O(n)
 */


