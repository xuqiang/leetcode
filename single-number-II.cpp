/*

single number II

Given an array of integers, every element appears three times except for one. Find that single one.

*/

#include <iostream>
#include <vector>
#include <string>
#include "common.h"

using namespace std;



class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	/*
    	用一个 32 长的数组存储对于所有数的二进制展开
    	每一个位上总共 “1” 的个数和，最后看那些位上 “1” 的个数不是 3 的倍数，那么这一位在 ans 中就是 1。
    	*/
    	int bitnum [32] = { 0 };
        int res = 0;
        for(int i = 0; i < 32; i++) {
            for(int j = 0; j < nums.size(); j++){
                bitnum[i] += (nums[j] >> i) & 1;
            }
            res |= (bitnum[i] % 3) << i;
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> nums = { 1, 1, 1, 3 };
	cout << s.singleNumber(nums) << endl;
  	return 0;
}