/*

Excel Sheet Column Title

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

*/


#include <stack>
#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n > 0) {
        	int m = n % 26;
        	if(m == 0) {
        		res.insert(res.begin(), 1, 'Z');
        		n --;
        	} else {
        		res.insert(res.begin(), 1, ( m - 1 + 'A' ) );
        	}
        	n /= 26;
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	cout << s.convertToTitle(26) << endl;
	cout << s.convertToTitle(28) << endl;
	return 0;
}

