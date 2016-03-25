/*

Basic Calculator

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23

*/

/*

两个stack，一个存数字一个存符号。如果遇到数字直接存到数字stack；如果遇到符号，有几种情况：

1.当前符号比上一个符号优先级高，比如* 高于+，那么直接进栈

2.当前符号低于上一个，那么就要把所有已经在stack里面优先于当前符号的全算完，再推进当前符号

3.当前符号是“（”，直接push

4.当前符号是“）”，就要把所有“（”以前的符号全部算完

这道题只有“+”号与“-”号，不用判断符号的优先级。

*/

class Solution {
private:
    bool isOK(char op1, char op2) {
        if (op1 == '*' || op1 == '/' || op2 == ')') return true;
        else return op2 == '+' || op2 == '-';
    }
    int calc(int a, int b, char op) {
        if (op == '+') return a + b;
        else if (op == '-') return a - b;
        else if (op == '*') return a * b;
        else return a / b;
    }
public:
    int calculate(string s) {
        stack<int> stk_val;
        stack<char> stk_op;
        int res = 0, tmp;
        for (int i = 0; i <= s.length(); ++i) {
            //操作数
            if (i < s.length() && isdigit(s[i])) {
                res = 0;
                while (i < s.length() && isdigit(s[i])) {
                    res *= 10;
                    res += s[i++] - '0';
                }
                stk_val.push(res);
            }
            //运算符
            if (i == s.length() || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == ')') {
                while (!stk_op.empty() && stk_op.top() != '(' && (i == s.length() || isOK(stk_op.top(), s[i]))) {
                    tmp = stk_val.top();
                    stk_val.pop();
                    stk_val.top() = calc(stk_val.top(), tmp, stk_op.top());
                    stk_op.pop();
                }
                if (i == s.length()) break;
                else if (s[i] == ')') stk_op.pop();
                else stk_op.push(s[i]);
            } else if (s[i] == '(') {
                stk_op.push(s[i]);
            }
        }
        return stk_val.top();
    }
};