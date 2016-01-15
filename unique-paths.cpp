/*

 A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

*/

#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <stack>
#include "common.h"

using namespace std;


class Solution {
public:
	/* 递归解法
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) return 1;
        else 
        	return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }*/
    int uniquePaths(int m, int n) {
    	if(m == 1 || n == 1) return 1;
		vector<vector<int> > table(m, vector<int>(n, 1));
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				table[i][j] = table[i-1][j] + table[i][j-1];
			}
		}
		return table[m-1][n-1];
	}
};

int main(int argc, char* argv[]) {
	return 0;
}