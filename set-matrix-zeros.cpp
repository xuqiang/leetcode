/*
 
 Set Matrix Zeroes

 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

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
    void setZeroes(vector<vector<int>>& matrix) {
    	if( matrix.size() <= 0 ) return ;
  		const size_t m = matrix.size();
  		const size_t n = matrix[0].size();
  		
  		vector<bool> row(m, false);
  		vector<bool> col(n, false);

  		for(size_t i = 0; i < m ; ++i) {
  			for(size_t j = 0; j < n; ++j) {
  				if( matrix[i][j] == 0 ) {
  					row[i] = col[j] = true;
  				}
  			}
  		}
  		for(size_t i = 0; i < m; ++i) {
  			if(row[i]) {
  				std::fill( &matrix[i][0], &matrix[i][0] + n, 0 );
  			}
  		}
  		for(size_t j = 0; j < n; ++j) {
  			if(col[j]) {
  				for( size_t i = 0; i < m ; ++i ) {
  					matrix[i][j] = 0;
  				}
  			}
  		}
  		return ;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}