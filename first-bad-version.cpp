/*
 First Bad Version

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

需要考虑二分查找溢出的情况
int mid = i + (j - i) / 2;

*/

#include <stack>
#include <iostream>
#include <string>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1;
        int j = n;
        while( i <= j ) {
        	int mid = i + (j - i) / 2;
        	if(isBadVersion(mid) == true) {
        		j = mid - 1;
        	} else {
        		i = mid + 1;
        	}
        }
        if(isBadVersion(i)) return i;
        else return j;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}