/*

Maximal Square


Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.


dp解法：

构造一个新的矩阵dp，dp[i][j]表示以点(i, j)为右下角的正方形的边长；状态转移方程：

dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;

对于题目所给的例子就有：

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0  
转化成：

1 0 1 0 0
1 0 1 1 1
1 1 1 2 1
1 0 0 1 0  

*/



class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int M = matrix.size(), N = matrix[0].size(), res = 0;
        vector<vector<int>> dp(M, vector<int>(N, 0));
        for (int i = 0; i < M; ++i) if (matrix[i][0] == '1') {
            dp[i][0] = 1; res = 1;
        }
        for (int j = 0; j < N; ++j) if (matrix[0][j] == '1') {
            dp[0][j] = 1; res = 1;
        }
        for (int i = 1; i < M; ++i) {
            for (int j = 1; j < N; ++j) {
                if (matrix[i][j] == '1') 
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};