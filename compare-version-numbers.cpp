/*

Compare Version Numbers


Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37



*/


#include <iostream>
#include <vector>
#include <string>
#include "common.h"

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
		int size1 = version1.size();
		int size2 = version2.size();
		int i = 0;
		int j = 0;
		for( ; i < size1 || j < size2; ++i, ++j) {
			int sum1 = 0;
			while(i < size1 && version1[i] != '.' ) {
				sum1 = sum1 * 10 + (version1[i] - '0');
				i++;
			}
			int sum2 = 0;
			while(j < size2 && version2[j] != '.') {
				sum2 = sum2 * 10 + (version2[j] - '0');
				j++;
			}
			if( sum1 > sum2 ) 
				return 1;
			else if(sum1 < sum2) 
				return -1;
 		}   
 		return 0;     
    }
};


int main(int argc, char* argv[]) {
	Solution s;
	cout << s.compareVersion("1.0", "1.1") << endl;
 	return 0;
}