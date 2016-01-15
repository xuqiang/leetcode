/*

Minimum Path Sum
 
 Given a m x n grid filled with non-negative numbers, 
 find a path from top left to bottom right which minimizes 
 the sum of all numbers along its path.

动态规划 

设dp[i][j]表示从左上角到grid[i][j]的最小路径和。那么dp[i][j] = grid[i][j] + min( dp[i-1][j], dp[i][j-1] );



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
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col;
        if(row == 0) return 0;
        else 
        	col = grid[0].size();
        vector<vector<int> >dp(row + 1, vector<int>(col + 1, INT_MAX));
        dp[0][1] = 0;
        for(int i = 1; i <= row; i++)
        	for(int j = 1; j <= col; j++)
        		 dp[i][j] = grid[i - 1][j - 1] + min(dp[i][j - 1], dp[i - 1][j]);
        return dp[row][col];
    }
};

int main(int argc, char* argv[]) {
	return 0;
}
