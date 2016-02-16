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

排序 两头夹逼

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

		auto last = nums.end();
		for(auto i = nums.begin(); i < last - 2; ++i) {
			auto j = i + 1;			// 查找左侧
			if( i > nums.begin() && *i == *(i - 1) ) continue;
			auto k = last - 1;
			while(j < k) {
				int tot = *i + *j + *k;
				if( tot < target ) {
					++j;
					while( *j == *(j - 1) && j < k ) ++j;
				} else if(tot > target) {
					--k;
					while( *k == *(k + 1) && j < k ) --k;
				} else {
					res.push_back( { *i, *j, *k } );
					++j;
					--k;
					while( *j == *(j - 1) && *k == *(k + 1) && j < k ) ++j;
				}
			}
		}
		return res;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}


