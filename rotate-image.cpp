/*

Rotate Image

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

 原矩阵到转置矩阵是很容易计算的，那么从转置矩阵到选择矩阵就只需要reverse每行的元素就可

*/


class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		for(int i = 0, n = matrix.size(); i < n; ++i){
			for(int j = i + 1; j < n; ++j)
				swap(matrix[i][j], matrix[j][i]);
			reverse(matrix[i].begin(),matrix[i].end());        
		}
	}
};