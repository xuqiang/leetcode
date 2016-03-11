/*

Generate Parentheses


Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"


假设在位置k我们还剩余left个左括号和right个右括号，如果left>0，则我们可以直接打印左括号，而不违背规则。
能否打印右括号，我们还必须验证left和right的值是否满足规则，如果left>=right，则我们不能打印右括号，
因为打印会违背合法排列的规则，否则可以打印右括号。如果left和right均为零，则说明我们已经完成一个合法排列，
可以将其打印出来。通过深搜，

*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> res;
    	string one;
    	generate(n, n, one, res);
    	return res;    
    }

private:
	void generate(int leftNum, int rightNum, string s, vector<string> &result) {
        if(leftNum == 0 && rightNum == 0) {
            result.push_back(s);
        }
        if(leftNum > 0) {
            generate(leftNum - 1,rightNum, s + '(', result);
        }
        if(rightNum > 0 && leftNum < rightNum) {
            generate(leftNum, rightNum - 1, s + ')',result);
        }
	}

};


int main(int argc, char* argv[]) {

	Solution s;
	vector<string> res = s.generateParenthesis(2);
	for(auto& s : res) {
		cout << s << endl;
	}
	return 0;
}