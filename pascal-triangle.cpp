/*
 
 Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    	vector<vector<int> > res;
        if(numRows == 0) return res;
        const vector<int> first_row = vector<int> { 1 };
        if(numRows >= 1) {
        	res.push_back(first_row);
        }
        for( int i = 1; i < numRows; ++i ) {
        	vector<int> row;
        	row.push_back(1);
        	for(int j = 0; j <= (int)(res[i - 1].size()) - 2; j++) {
        		row.push_back( res[i-1][j] + res[i-1][j+1] );
        	}
        	row.push_back(1);
        	res.push_back( row );
        }
        return res;
    }

};

int main(int argc, char* argv[]) {
	Solution s;
	vector<vector<int> > res = s.generate(5);
	cout << "finish" << endl;
	for(auto& i : res) {
		for(auto& j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}