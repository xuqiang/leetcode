/*
 
 Trapping Rain Water

 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

 
 需要计算的面积 min( max_left, max_right ) - height 

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "common.h"

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        int* max_left = new int[n]();
        int* max_right = new int[n]();
        for (int i = 1; i < n; ++i) {
        	max_left[i] = max( max_left[i - 1], height[i - 1] );
        	max_right[ n - 1 - i] = max( max_right[ n - i ], height[ n - i ] );
        }
        int sum = 0;
        for(int i = 0 ; i < n; ++i) {
        	int h = min( max_right[i], max_left[i] );
        	if( h > height[i] ) {
        		sum += ( h - height[i] );
        	}
        }
        return sum;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}