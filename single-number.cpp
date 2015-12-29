/*
Single Number

Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

一个数组中 只有一个数字 只存在一次 其他都存在两次 

*/

#include <iostream>
#include <vector>
#include <string>
#include "common.h"

using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
        	ans ^= nums[i];
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> nums = { 1, 2, 1, 3, 3 };
	cout << s.singleNumber(nums) << endl;
  	return 0;
}