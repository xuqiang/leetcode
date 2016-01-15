/*
Longest Common Prefix

write a function to find the longest common prefix string amongst an array of strings.



*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include "common.h"

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string res;
        if(n == 0) return res;
        for(int i = 0; i < strs[0].size(); ++i) {
        	char ch = strs[0][i];
        	for(int j = 1; j < strs.size(); j++) {
        		if( strs[j].size() == i || strs[j][i] != ch )
        			return res;
        	}
        	res.push_back(ch);
        }
        return res;
    }
};


int main(int argc, char* argv[]) {
	vector<string> strs = { "abab", "aba", "abc" };
	Solution s;
	cout << s.longestCommonPrefix(strs) << endl;


	return 0;
}