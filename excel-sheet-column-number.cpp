/*

Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int p = 1;
        for( int i = s.size() - 1; i >= 0; i-- ) {
        	res += ( s[i] - 'A' + 1 ) * p;
        	p *= 26;
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	cout << "AA = " << s.titleToNumber("AA") << endl;
	cout << "A = " << s.titleToNumber("A") << endl;
}