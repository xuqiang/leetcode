/*

Search a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "common.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        const size_t M = matrix.size();
        const size_t N = matrix.front().size();

        int first = 0;
        int last = M * N;
        while( first <  last ) {
        	int mid = first + (last - first) / 2;
        	int value = matrix[ mid / N ][ mid % N ];
        	if(value == target) 
        		return true;
        	else if( value < target ) {
        		first = mid + 1;
        	} else {
        		last = mid;
        	}
        }

        return false;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}