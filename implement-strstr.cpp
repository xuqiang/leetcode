/*

implement strStr

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
  		int i = 0;
  		int j = 0;
  		while( i < haystack.size() && j < needle.size() ) {
  			if(haystack[i] == needle[j]) {
  				i ++;
  				j++;
  			} else {
  				i = i - j + 1;
  				j = 0;
  			}
  		}      
  		return (needle[j]) ? -1 : (i - j);
    }
};

int main(int argc, char* argv[]) {
	string haystack = "abc";
	string needle = "ab";
	Solution s;
	cout << s.strStr(haystack, needle) << endl;
	
	return 0;

}