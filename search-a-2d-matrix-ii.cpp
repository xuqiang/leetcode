/*

Search a 2D Matrix II

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

从右上角开始, 比较target 和 matrix[i][j]的值. 如果小于target, 则该行不可能有此数,  所以i++; 
如果大于target, 则该列不可能有此数, 所以j--. 遇到边界则表明该矩阵不含target

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;

        int i = 0, j = matrix[0].size() - 1;
        while(i < matrix.size() && j >= 0) {
        	int x = matrix[i][j];
        	if(target == x) return true;
        	else if(target < x) {
        		--j;
        	} else {
        		++i;
        	}
        }
        return false;
    }
};


