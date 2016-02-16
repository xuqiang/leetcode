/*
 
 3sum
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},
	多解
    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

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
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int> > res;
		if(nums.size() < 3) return res;

		sort( nums.begin(), nums.end() );
		const int target = 0;
		       
    }
};

int main(int argc, char* argv[]) {
	return 0;
}


