/*

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

类似问题remove-element 

*/ 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if(nums.size() == 0) return 0;

		int j = 1;
		for(int i = 1; i <= nums.size() - 1; ++i) {
			if( nums[i] == nums[i - 1] ) {
				continue;
			} else {
				nums[j] = nums[i];
				j++;
			}
		}       
		return j; 
    }
};

int main(int argc, char* argv[]) {
	vector<int> nums = { 1, 2, 3, 3, 3, 4, 5 };
	Solution s;
	int i = s.removeDuplicates(nums);
	for(int j = 0; j < i; ++j) {
		cout << nums[j] << " ";
	}
	cout << endl;
	return 0;
}