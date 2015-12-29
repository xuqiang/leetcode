/*

Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving 
the order of characters. No two characters may map to the same character 
but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

*/


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "common.h"

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	if(s.size() != t.size()) return false;
    	unordered_map<char, char> source;
    	unordered_map<char, char> target;
    	for(int i = 0; i < s.size(); ++i) {
    		if( source.find( s[i] ) != source.end() &&  source[ s[i] ] != t[i] )
    			return false;
    		if( target.find( t[i] ) != target.end() && target[ t[i] ] != s[i] )
    			return false;
    		source[ s[i] ] = t[i];
    		target[ t[i] ] = s[i];
    	} 
    	return true;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	cout << s.isIsomorphic("egg", "add") << endl;
	cout << s.isIsomorphic("foo", "bar") << endl;
	cout << s.isIsomorphic("ab", "aa") << endl;
	cout << s.isIsomorphic("ab", "ca") << endl;
	
  	return 0;
}


