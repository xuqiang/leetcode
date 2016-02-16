/*

3Sum Closest

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


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
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0;
        int min_gap = INT_MAX;
        sort( nums.begin(), nums.end() );
        for(auto a = nums.begin(); a != prev(nums.end(), 2); ++a) {
        	auto b = next(a);
        	auto c = prev( nums.end());
        	while( b < c) {
        		const int sum = *a + *b + *c;
        		const int gap = abs(sum - target);
        		if(gap < min_gap) {
        			result = sum;
        			min_gap = gap;
        		}
        		if(sum < target) ++b;
        		else --c;
        	}
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}