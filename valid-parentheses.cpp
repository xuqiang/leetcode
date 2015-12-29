/*

Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/

#include <iostream>
#include <vector>
#include <string>
#include "common.h"

using namespace std;

class Solution {
public:
	bool match(char a, char b) {
		if( (a == ')' && b == '(') || (a == ']' && b == '[') ||
			( a == '}' && b == '{' ) )
			return true;
		else 
			return false; 
	}
    bool isValid(string s) {
        if(s.size() <= 1) return false; 
        vector<char> v;
        v.push_back( s[0] );
       	for(int i = 1; i < s.size(); ++i) {
       		if(match(s[i], v.back())) {
       			v.pop_back();
       		} else {
       			v.push_back( s[i] );
       		}
       	}
       	if(v.size() == 0) 
       		return true;
       	else
       		return false;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	cout << "() " << s.isValid("()") << endl;
  	return 0;
}
