/*

Permutations

Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

求不重复元素的 全排列

*/


#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include "common.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    	vector<vector<int> > res;
    	if(nums.size() == 0) return res;
    	vector<int> tmp;
    	cal( nums, 0, res, tmp );
    	return res;
    }
    void cal( vector<int>& nums, int index, vector<vector<int> >& res, vector<int>& tmp ) {
    	if(index == nums.size()) {
    		res.push_back( tmp );
    		return ;
    	}
    	for(int i = index; i < nums.size(); ++i) {
    		swap( nums[index], nums[i] );
    		tmp.push_back( nums[index] );
    		cal( nums, index + 1, res, tmp );
    		tmp.pop_back();
    		swap( nums[index], nums[i] );
    	}
    }
 };

int main(int argc, char* argv[]) {
	retrun 0;
}