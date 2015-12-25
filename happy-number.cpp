/*

happy number

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

数字11有如下的计算过程：

1^2 + 1^2 = 2
2^2 = 4
4^2 = 16
1^2 + 6^2 = 37
3^2 + 7^2 = 58
5^2 + 8^2 = 89
8^2 + 9^2 = 145
1^2 + 4^2 + 5^2 = 42
4^2 + 2^2 = 20
2^2 + 0^2 = 4

可以看出 如果计算出来的结果有重复 并且不是1 那么可以判断不是 happy number
否则 是 happy number
*/
#include <vector>
#include <iostream>
#include <unordered_map>
#include "common.h"

using namespace std;


class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n != 1) {
        	int sum = 0;
        	while(n > 0) {
        		sum += ( (n % 10) * (n % 10) );
        		n /= 10;
        	}
        	n = sum;
        	if(s.find(n) != s.end()) break;
        	else 
        		s.insert(n);
        }
        return n == 1;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}

