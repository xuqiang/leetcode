/*
 *
 * Write a function that takes a string as input and returns the string reversed.
 *
 * Example:
 * Given s = "hello", return "olleh".
 *
 */ 

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        if(s.size() <= 0) return string("");
        
        string res;
        const int len = s.size();
        for( int i = len - 1;  i >= 0; i-- ) {
            res.push_back(s[i]);
        }
        return res;
    }
};

int main() {
	Solution s;
	string str = "hello";
	cout << s.reverseString(str) << endl;
	return 0;
}
