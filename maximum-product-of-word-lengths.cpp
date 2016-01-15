/*

maximum-product-of-word-lengths

Given a string array words, find the maximum value of length(word[i]) * length(word[j]) 
where the two words do not share common letters. You may assume that each word will contain
 only lower case letters. If no such two words exist, return 0.

给定数组 查找成绩最大值 但是这两个word不能有相同的单词

使用位运算 32位整数即可

*/


#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <string>
#include "common.h"

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> elements(n, 0);
        for(int i = 0; i < n; ++i) {
        	for(int j = 0; j < words[i].size(); ++j) {
        		elements[i] |= 1 << ( words[i][j]  - 'a' );
        	}
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
        	for(int j = i + 1; j < n ; ++j) {
        		if(  !(elements[i] & elements[j]) && words[i].length() * words[j].length()  > ans ) {
        			ans = words[i].length()  * words[j].length();
        		}

        	}
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}