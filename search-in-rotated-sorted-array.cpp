/*

Search in Rotated Sorted Array

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.
 
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
    int search(vector<int>& nums, int target) {
    	int i = 0; 
    	int j = nums.size();
    	while(i != j) {
    		int mid = i + (j - i) / 2;
    		if(nums[mid] == target) {
    			return mid;
    		}
    		// 前半部分有序
    		if( nums[i] <= nums[mid] ) {
    			if( nums[i] <= target && target < nums[mid] ) {
    				// 在前半部分
    				j = mid;
    			} else {
    				i = mid + 1;
    			}
    		} else {
    			// 前半部分无序 后半部分有序
    			if( nums[mid] < target && target <= nums[j - 1] ) {
    				// 在后半部分
    				i = mid + 1;
    			} else {
    				j = mid ;
    			}
    		}
    	}
    	return -1;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}