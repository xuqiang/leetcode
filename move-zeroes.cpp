/*
 
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

给定数组 将为0的元素移到数组的末尾 

两个指针 i j i遍历数组 j维护非0元素的末尾指针

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0, j = 0; i < nums.size(); ++i) {
        	if(nums[i] != 0) {
        		swap( nums[i], nums[j++] );
        	}
        }
    }
};

int main() {	
	vector<int> nums = { 0, 1, 0, 3, 12 };
	Solution s;
	s.moveZeroes(nums);
	for(auto& i : nums) {
		cout << i << " ";
	}
	cout << endl;
}