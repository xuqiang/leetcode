/*

String to Integer (atoi)

*/


#include <iostream>
#include <vector>
#include <string>
#include "common.h"

using namespace std;


class Solution {
public:
    int myAtoi(string str) {
    	long long ret = 0;
    	const char* p = str.c_str();
    	while(*p == ' ' && p) p++;
    	
    	char minus = 0;
    	char plus = 0;
    	while(p && ( *p == '+' || *p == '-' )) {
    		if(*p == '+') {
    			plus ++;
    		} else if(*p == '-') {
    			minus++;
       		}
    		p++;
    	}
    	if(plus > 1 || minus > 1)
    		return 0;
    	if(plus != 0 && minus != 0) 
    		return 0;

    	while( *p == '0' && p ) p++;

    	while(*p != '\0') {
    		if(*p >= '0' && *p <= '9') {
    			ret = ret * 10 + *p - '0';
    			if(!minus && ret > INT_MAX) return INT_MAX;
    			if(minus && -ret < INT_MIN) return INT_MIN; 
    			p++;
    		} else 
    			break;

    	}
    	return minus ? -ret : ret; 
    }
};



int main(int argc, char* argv[]) {
	Solution s;
	cout << s.myAtoi("+123456") << endl;
	cout << s.myAtoi("+-2") << endl;
	cout << s.myAtoi(" ++1") << endl;
  	return 0;
}