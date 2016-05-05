/*
 反转 元音字母
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isVowels(char c) {
		char ch;
		if( c <= 'Z' ) {
			ch = c + 32;
		} else {
			ch = c;
		}
		return ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o')
			|| (ch == 'u'));
	}
    string reverseVowels(string s) {
        string res;
        res.resize(s.size());
        for(int i = 0, j = s.size() - 1; i < s.size(); i++) {
        	if( isVowels(s[i]) == false ) {
        		res[i] = s[i];
        	} else {
        		while( j >= 0 && (isVowels(s[j]) == false)) { j--; };
        		res[i] = s[j];
        		j--;		// 下次从下个字符开始
        	}
        }
        return res;
    }
};

int main() {

	Solution s;
	string str = "aA";
	cout << s.reverseVowels(str) << endl;
	return 0;
}