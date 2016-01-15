/*
missing number

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is
 missing from the array.

For example,
Given nums = [0, 1, 3] return 2.


求和 相减 即可

*/

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <string>
#include "common.h"

using namespace std;


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
        	sum += nums[i];
        }
        const int n = nums.size();
        return 0.5 * n * (n + 1) - sum;
    }
};


int main(int argc, char* argv[]) {
	return 0;
}
