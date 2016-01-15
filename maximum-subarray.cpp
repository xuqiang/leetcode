/*

Maximum Subarray
 
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include "common.h"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
 		if(nums.size() == 0) return 0;
 		int global = nums[0];
 		int local = nums[0];
 		for(int i = 1; i < nums.size(); ++i) {
 			local = max( nums[i], local + nums[i] );
 			global = max( local, global );
 		}       
 		return global;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}