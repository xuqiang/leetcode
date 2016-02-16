/*

Search in Rotated Sorted Array II

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

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
    bool search(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size();
        while(first != last) {
        	const int mid = first + (last - first) / 2;
        	if(nums[mid] == target) {
        		return true;
        	}
        	// 有重复元素 不能包含等于 例如对于序列 [ 1, 3, 1, 1 ]
        	if( nums[first] < nums[mid] ) {
        		if(nums[first] <= target && target < nums[mid]) {
        			last = mid;
        		} else {
        			first = mid + 1;
        		}
        	} else if( nums[first] > nums[mid] ) {
        		if( nums[mid] < target && target <= nums[ last - 1 ] ) {
        			first  = mid + 1;
        		} else {
        			last = mid;
        		}
        	} else {
        		// 忽略掉 重复元素
        		first ++;
        	}
        }
        return false;
    }
};


int main(int argc, char* argv[]) {
	return 0;
}
