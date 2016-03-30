/*

Longest Valid Parentheses

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.


使用一个stack，只存左括号的下标，last变量存放最后一个无法匹配的')'，遍历字符串，如果遇到'('，下标就放入栈中，如果入到')'，则分两种情况，一种是栈为空，那么说明')'无法被匹配，更新last，另一种栈不为空，那么pop出一个'('，此时如果栈为空，说明可以得到完整的符合要求的长度，长度为i-last，如果栈不为空，说明栈还有'('没有被匹配，那么目前合法的长度为i-st.top()，时间复杂度为O(n)



*/


class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0, last = -1; //ans表示最大合法长度，last最后一个无法匹配的')'的下标
        stack<int> st;
        for(int i=0; i<s.length(); ++i)
            if( s[i] == '(' ) st.push(i);   //遇到左括号，就放入左括号的下标
            else {  //遇到右括号
                if( st.empty() )    //如果栈空，更新last
                    last = i;
                else {  //栈非空
                    st.pop();   //pop出一个'('
                    if( st.empty() ) ans = max(ans, i-last);    //此时如果栈空，那么就是个完整的合法长度，即i-last
                    else ans = max(ans, i-st.top());    //如果栈非空，那么局部合法长度即为i-st.top()
                }
            }
        return ans;
    }
};