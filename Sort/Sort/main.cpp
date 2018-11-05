//
//  main.cpp
//  Sort
//
//  Created by JINGLUO on 1/11/18.
//  Copyright © 2018 JINGLUO. All rights reserved.
//

#include <iostream>
#include <queue>

// Bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n; ++ i) {
        for (j = 0; j <  n - i - 1; ++ j) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Insert sort
void insertSort(int arr[], int n) {
    int i, j, temp;
    for (i = 1; i < n; ++ i) {
        temp = arr[i];
        for (j = i-1; j >= 0; -- j) {
            if (arr[j] > temp) {
                arr[j+1] = arr[j];
            } else {
                break;
            }
        }
        arr[j+1] = temp;
    }
}

// Quick sort
int partition(int arr[], int s, int e) {
    int i;
    int point;
    int value = arr[e];
    std::queue<int> smallQ, largeQ;
    for (i = s; i < e; ++ i) {
        if (arr[i] < value) {
            smallQ.push(arr[i]);
        } else {
            largeQ.push(arr[i]);
        }
    }
    point = int(smallQ.size());
    i = s;
    while (!smallQ.empty()) {
        arr[i] = smallQ.front();
        smallQ.pop();
        i ++;
    }
    arr[i++] = value;
    while (!largeQ.empty()) {
        arr[i] = largeQ.front();
        largeQ.pop();
        i ++;
    }
    return point;
}

void quickSort_implement(int arr[], int s, int e) {
    if (s+1 == e) {
        return;
    }
    
    int point = partition(arr, s, e);
    if (point-1 > s) {
        quickSort_implement(arr, s, point-1);
    }
    if (point+1 < e) {
        quickSort_implement(arr, point+1, e);
    }
}

void quickSort(int arr[], int n) {
    quickSort_implement(arr, 0, n-1);
}

// Merge sort
void merge(int arr[], int s, int e, int m) {
    std::queue<int> leftQ, rightQ;
    int i,j = s;
    for (i = s; i < m; i ++) {
        leftQ.push(arr[i]);
    }
    for (i = m; i <= e; i ++) {
        rightQ.push(arr[i]);
    }
    while (!leftQ.empty() && !rightQ.empty()) {
        if (leftQ.front() < rightQ.front()) {
            arr[j++] = leftQ.front();
            leftQ.pop();
        } else {
            arr[j++] = rightQ.front();
            rightQ.pop();
        }
    }
    while (!leftQ.empty()) {
        arr[j++] = leftQ.front();
        leftQ.pop();
    }
    while (!rightQ.empty()) {
        arr[j++] = rightQ.front();
        rightQ.pop();
    }
}

void mergeSort_implement(int arr[], int s, int e) {
    if (e == s) {
        return;
    }
    int mid = (e-s)/2 + s;
    mergeSort_implement(arr, s, mid);
    mergeSort_implement(arr, mid+1, e);
    merge(arr, s, e, mid);
}

void mergeSort(int arr[], int n) {
    mergeSort_implement(arr, 0, n-1);
}

// Print array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {5,2,6,3,4,1,22,53,2,6,2,5,3,233,4,353,5,4,2342,434};
    int size = sizeof(a)/sizeof(a[0]);
    bubbleSort(a, size);
    std::cout << "Bubble sort: ";
    printArray(a, size);
    std::cout << "\n";
    
    insertSort(a, size);
    std::cout << "Insert sort: ";
    printArray(a, size);
    std::cout << "\n";
    
    quickSort(a, size);
    std::cout << "Quick sort: ";
    printArray(a, size);
    std::cout << "\n";

    mergeSort(a, size);
    std::cout << "Merge sort: ";
    printArray(a, size);
    std::cout << "\n";
    return 0;
}


/*
 Quick sort:
 Solution 1:
 不考虑空间消耗的话，partition() 分区函数可以写得非常简单。我们申请两个临时数组，分别存放大于和下于分界点pivot的子数组。
 Solution 2: TODO
 如果不想占用额外空间，就需要在原地完成分区操作
 */
