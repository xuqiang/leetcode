/*
 
 Search Insert Position


Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/

#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include "common.h"

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	if(nums.size() <= 0) return 0;
  		int left = 0;
  		int right = nums.size() - 1;
  		int mid = 0;
  		while(left <= right) {
  			mid = left + ( right - left ) / 2;
  			if(nums[mid] > target) {
  				right = mid - 1;
  			} else if( nums[mid] < target ) {
  				left = mid + 1;
  			} else {
  				return mid;
  			}
  		}
  		return left;      
    }
};


int main(int argc, char* argv[]) {
	vector<int> nums = { 1 };
	const int target = 2;
	Solution s;
	cout << s.searchInsert(nums, target) << endl;
	return 0;
}