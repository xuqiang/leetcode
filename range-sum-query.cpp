/*

Range Sum Query

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

使用数组保存累积和

*/

#include <iostream>
#include <vector>
#include <string>
#include "common.h"

using namespace std;


class NumArray {
public:
	std::vector<int> acc;
    
    NumArray(vector<int> &nums) {
    	int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
        	sum += nums[i];
        	acc.push_back( sum );
        }
    }

    int sumRange(int i, int j) {
        return (i == 0) ? ( acc[j] ) : ( acc[j] - acc[i  - 1] );
    }

};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);


int main(int argc, char* argv[]) {
	vector<int> nums = { -2, 0, 3, -5, 2, -1 };
	NumArray numArray( nums );
	cout << numArray.sumRange(0, 1) << endl;
	cout << numArray.sumRange(1, 2) << endl;
	return 0;
}