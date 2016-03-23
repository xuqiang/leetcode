/*

Combination Sum

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 

*/


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        if(candidates.size() == 0) return res;

        sort( candidates.begin(), candidates.end() );

        vector<int> one;
        dfs( candidates, target,  one, res, 0);
    	return res;
    }

    void dfs( vector<int>& candidates, int target, vector<int>& one, vector<vector<int> >& res, int index) {
    	if(target < 0) return ;
    	if(target == 0) {
    		res.push_back(one);
    		return ;
    	}

    	for(int i = index; i < candidates.size(); ++i) {
    		int num = candidates[i];
    		one.push_back(num);

    		dfs(candidates, target - num, one, res, i);
    		one.erase( one.end() - 1 );
    	}

    }

};