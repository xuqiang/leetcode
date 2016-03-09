/*

Pascal's Triangle II

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

 
*/

#include <stack>
#include <iostream>
#include <string>

#include "common.h"

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> array;
        for(int i = 0; i <= rowIndex; ++i) {
        	for(int j = i - 1; j > 0; j--) {
        		array[j] = array[j - 1] + array[j];
        	}
        	array.push_back(1);
        }
        return array;
        
    }
};

int main(int argc, char* argv[] ) {
	
}