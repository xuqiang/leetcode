/*

Triangle


Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

*/

/*
 
dp思路

For the kth level:
minpath[i] = min( minpath[i], minpath[i+1]) + triangle[k][i]; 

从下 到 上 计算

*/

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
	    int n = triangle.size();
	    vector<int> minlen(triangle.back());
	   	for (int layer = n-2; layer >= 0; layer--) { 
	   		// For each layer 
	        for (int i = 0; i <= layer; i++) {
	        	// Check its every 'node'
	            // Find the lesser of its two children, and sum the current value in the triangle with it.
	            minlen[i] = min(minlen[i], minlen[i+1]) + triangle[layer][i]; 
	        }
	    }
	    return minlen[0];
	}
};