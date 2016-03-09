/*

Count and Say

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

第i+1个字符串是第i个字符串的读法，第一字符串为 “1”

比如第四个字符串是1211，它的读法是 1个1、1个2,2个1，因此第五个字符串是111221。

*/

#include <stack>
#include <iostream>
#include <string>

#include "common.h"

using namespace std;


class Solution {
public:
    string countAndSay(int n) {
       string prev = "1";
       while(--n > 0) {
       	string next;
       	for(int i = 0; i < prev.size(); ++i) {
       		int count = 1;
       		while( (i + 1) < prev.size() && prev[i] == prev[i + 1] ) {
       			count ++;
       		} 
       		next.append( to_string(count) + to_string( prev[i] ) );
       	}
       	prev = next;
       }
       return prev;
    }
};


int main(int argc, char* argv[] ) {
	return 0;
}

