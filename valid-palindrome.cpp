/*

Valid Palindrome

Given a string, determine if it is a palindrome回文, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

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
    bool isPalindrome(string s) {
        int len = s.length();
        if(len <= 1)return true;
        int i = 0, j = len - 1;
        while(i <= j) {
            if(isAlphanumeric(s[i]) == false)
                i++;
            else if(isAlphanumeric(s[j]) == false)
                j--;
            else {
                if(isSame(s[i], s[j]) == true)
                    {i++; j--;}
                else return false;
            }
        }
        return true;
    }
    bool isAlphanumeric(char c) {
        if((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z')||(c >= '0' && c <= '9'))
            return true;
        else 
            return false;
    }
    bool isSame(char a, char b) {
        if(a >= 'A' && a <= 'Z')
            a += 32;
        if(b >= 'A' && b <= 'Z')
            b += 32;
        return a == b;
    }
};

int main(int argc, char* argv[]) {
  	return 0;
}

