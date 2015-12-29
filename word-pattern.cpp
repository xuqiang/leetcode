/*
 Word Pattern

 Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection 双射 between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
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
	void split( const string& s, vector<string>& sp ) {
		stringstream ss(s);
		string p;
		while( ss >> p ) {
			sp.push_back(p);
		}
	}
    bool wordPattern(string pattern, string str) {
    	vector<string> sp;
        split( str, sp );


        if(  pattern.size() != sp.size() ) 
        	return false;

        unordered_map<char, string> rel1;
        unordered_map<string, char> rel2;
        for(int i = 0; i < pattern.size(); ++i) {
        	char ch = pattern[i];
        	string s = sp[i];

        	if(rel1.find(ch) != rel1.end() && rel1[ch] != s) {
        			return false;
        	} 
        	if(rel2.find(s) != rel2.end() && rel2[s] != ch) {
        		return false;
        	}

        	rel1[ ch ] = s;
        	rel2[ s ] = ch;
        }
        return true;
    }
};


int main(int argc, char* argv[]) {
	Solution s;
	cout << s.wordPattern("abba", "dog cat cat dog") << endl;
  	return 0;
}
