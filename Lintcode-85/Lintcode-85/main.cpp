//
//  main.cpp
//  Lintcode-85
//
//  Created by Luo, Jing on 11/4/20.
//  Copyright © 2020 Luo, Jing. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/* Solution 1: 类似quick sort找到第k个，但是会time limit exceed
int partation(vector<int> &nums, int start, int end) {
    int i, j = start, pivot = nums[end];
    for (i = start; i <= end; i ++) {
        if (nums[i] < pivot) {
            swap(nums[i], nums[j]);
            j ++;
        }
    }
    swap(nums[j], nums[end]);
    return j;
}

int findK(vector<int> &nums, int start, int end, int k) {
    if (start > end) {
        return -1;
    }
    int pivot = partation(nums, start, end);
    if (pivot == k) {
        return nums[pivot];
    }
    if (pivot > k) {
        return findK(nums, start, pivot-1, k);
    } else {
        return findK(nums, pivot+1, end, k);
    }
}

vector<int> medianII(vector<int> &nums) {
    vector<int> result;
    int size = int(nums.size());
    for (int i = 0; i < size; i ++) {
        int k = findK(nums, 0, i, i/2);
        result.push_back(k);
    }
    return result;
}
 */

// Solution 2: 用大小堆
vector<int> medianII(vector<int> &nums) {
    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    for (int i = 0; i < int(nums.size()); i ++) {
        if (maxHeap.empty()) {
            maxHeap.push(nums[i]);
            result.push_back(maxHeap.top());
            continue;
        }
        int maxSize = int(maxHeap.size());
        int minSize = int(minHeap.size());
        int topMax = maxHeap.top();
        if (maxSize == minSize) {
            int topMin = minHeap.top();
            if (nums[i] < topMin) {
                maxHeap.push(nums[i]);
            } else {
                minHeap.pop();
                minHeap.push(nums[i]);
                maxHeap.push(topMin);
            }
            result.push_back(maxHeap.top());
        } else {
            if (nums[i] <= topMax) {
                maxHeap.pop();
                maxHeap.push(nums[i]);
                minHeap.push(topMax);
            } else {
                minHeap.push(nums[i]);
            }
            result.push_back(maxHeap.top());
        }
    }
    return result;
}

// Solution 3: insertion sort, 但是时间复杂度就是O(n^2)

int main(int argc, const char * argv[]) {
    vector<int> nums = {5,-10,4};//{4,5,1,3,2,6,0};
    vector<int> result = medianII(nums);
    std::cout << result.size() << "\n";
    return 0;
}



/*
###算法
 用 maxheap 保存左半部分的数，用 minheap 保存右半部分的数。
 把所有的数一左一右的加入到每个部分。左边部分最大的数就一直都是 median。
 这个过程中，可能会出现左边部分并不完全都 <= 右边部分的情况。这种情况发生的时候，交换左边最大和右边最小的数即可。
 

 拓展: 动态维护中位数一般都用双堆解决: 同理 动态维护第K大数
 例如 动态维护第3大. 先add进前三个数, 前三个数大根堆,后面数子是小根堆, 定义第三大就是大根堆的首 ---- > (1,2,3)(4,5,6). 每次和maxHeap 比,如果小,加入大根堆,大add进小根堆,维护小根堆的大小
 
 ###时空复杂度
 Time Complexity: O(NLog(N)),heap的插入是log(N)的复杂度，因此是N*log(N)
 Space Complexity: O(N)
  
###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/


