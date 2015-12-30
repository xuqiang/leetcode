/*

Add Binary

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1001"
Return "100".

技巧 使用进位标志plus

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include "common.h"

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
  		int i = a.size() - 1; 	int j = b.size() - 1;
  		string res;
  		int plus = 0;
  		while(i >= 0 || j >= 0 ) {
  			int bitsum = plus;
  			if( i >= 0 ) {
  				bitsum += (a[i] - '0');
  			}
  			if(j >= 0) {
  				bitsum += ( b[j] - '0' );
  			}
  			res.insert(0, 1, bitsum % 2 + '0' );
  			plus = bitsum / 2;
  			i --; 	j --;
  		}      
  		if(plus == 1) {
  			res.insert(0, 1, '1' );
  		}
  		return res;
    }
};


int main(int argc, char* argv[]) {
	Solution s;
	cout << s.addBinary("1", "1") << endl;
	cout << s.addBinary("0", "0") << endl;
  	return 0;
}

