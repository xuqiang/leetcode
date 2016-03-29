/*

Longest Increasing Path in a Matrix

Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

dfs + 记忆搜索

*/


class Solution {
public:
    bool checkRange(vector<vector<int> >& matrix, int x, int y) {
        int n = matrix.size(), m = matrix[0].size();
        if(x < 0 || y < 0 || x >= n || y >= m)  return false;
        return true;
    }
    
    int dfs(vector<vector<int> >& matrix, vector<vector<int> >& dp, vector<vector<bool> >& vis, vector<vector<int> >& dir, int x, int y) {
        if(dp[x][y])  return dp[x][y];
        
        int MAX = -1;
        for(int i=0; i<dir.size(); ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(checkRange(matrix, nx, ny) && !vis[nx][ny] && matrix[nx][ny] > matrix[x][y]) {
                vis[nx][ny] = true;
                MAX = max(MAX, dfs(matrix, dp, vis, dir, nx, ny) + 1);
                vis[nx][ny] = false;
            }
        }
        
        if(MAX == -1) return 1;
        dp[x][y] = MAX;
        return dp[x][y];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0)  return 0;
        
        int m = matrix[0].size();
        vector<vector<int> > dp(n, vector<int>(m, 0));
        vector<vector<bool> > vis(n, vector<bool>(m, false));
        vector<vector<int> > dir(4);
        dir[0].push_back(-1); dir[0].push_back(0);
        dir[1].push_back(0);  dir[1].push_back(1);
        dir[2].push_back(1);  dir[2].push_back(0);
        dir[3].push_back(0);  dir[3].push_back(-1);
        
        int res = -1;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                vis[i][j] = true;
                dp[i][j] = dfs(matrix, dp, vis, dir, i, j);
                res = max(res, dp[i][j]);
                vis[i][j] = false;
            }
        }
        
        return res;
    }
};