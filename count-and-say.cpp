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
    string getNext(string &s) 
    {
        if(s == "") return "1";
        string temp = "";
        for(int i = 0; i < s.size(); i++) {
            int cnt = 1;
            while(i+1 < s.size() && s[i] == s[i+1]) {
                i++;
                cnt++;
            }
            stringstream ss;
            ss << cnt;
            temp += ss.str();
            temp += s[i];
        }
        return temp;
    }
    string countAndSay(int n) 
    {
        string s = "";
        if(n == 0) return s;
 
        for(int i = 0; i < n; i++) {
            s = getNext(s);            
        }           
        return s;
    }
};


int main(int argc, char* argv[] ) {
	return 0;
}

