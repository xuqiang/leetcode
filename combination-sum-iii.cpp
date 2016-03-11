/*

combination-sum-iii

深度优先遍历 dfs

Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]

*/


class Solution {
public:
    void dfs(int k, int n, int idx, int sum, int cnt, vector<int> &path, vector<vector<int> > &res) {
        if (sum > n || cnt > k || idx > 10) return;
        if (sum == n && cnt == k) {
            res.push_back(path);
            return;
        }
        dfs(k, n, idx + 1, sum, cnt, path, res);
        path.push_back(idx);
        dfs(k, n, idx + 1, sum + idx, cnt + 1, path, res);
        path.pop_back();
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(k, n, 1, 0, 0, path, res);
        return res;
    }
};