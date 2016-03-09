/*
 
 Power of Three

 Given an integer, write a function to determine if it is a power of three.

*/
#include <stack>
#include <iostream>
#include <string>

#include "common.h"

using namespace std;


class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        else if (n%3 == 0) return isPowerOfThree(n/3);
        else return false;
    }
};

int main(int argc, char* argv[] ) {
	
}