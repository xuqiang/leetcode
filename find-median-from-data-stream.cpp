/*

Find Median from Data Stream

Median is the middle value in an ordered integer list. If the size of the list is even,
 there is no middle value. So the median is the mean of the two middle value.

排序好流数据 查找中位数

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2

*/

#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include "common.h"

using namespace std;


class MedianFinder {
public:
    void addNum(int num) {
        maxH.push(num);
        int t = maxH.top();
        maxH.pop(); 
        minH.push(t);
        int m = maxH.size();
        int n = minH.size();
        if (n > m) {
            int t = minH.top();
            minH.pop(); maxH.push(t);
        }
    }

    double findMedian() { 
        int m = maxH.size();
        int n = minH.size();
        if (!m && !n) return 0.0;
        if (m == n) return (maxH.top() + minH.top()) / 2.0;
        return (m > n) ? maxH.top() : minH.top();
    }
private:
    priority_queue<int, vector<int>, less<int>> maxH;       // stores the smaller half
    priority_queue<int, vector<int>, greater<int>> minH;    // stores the larger half
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main() {
	return 0;
}

