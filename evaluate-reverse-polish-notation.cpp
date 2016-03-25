/*

Evaluate Reverse Polish Notation


Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

使用stack实现

*/

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = tokens.size();
        stack<int> S;
        for(int i = 0; i < len; i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" ||
                tokens[i] == "*" || tokens[i] == "/")
            {
                int op2 = S.top(); S.pop();
                int op1 = S.top(); S.pop();
                S.push( op(op1, op2, tokens[i][0]) );
            }
            else
                S.push(stoi(tokens[i]));
        }
        return S.top();
    }
    int op(int op1, int op2, char optor)
    {
        if(optor == '+')return op1 + op2;
        else if(optor == '-')return op1 - op2;
        else if(optor == '*')return op1 * op2;
        else return op1 / op2;
    }
};