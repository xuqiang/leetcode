/*

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.



*/


class Solution {
public:
    int numDecodings(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //注意处理字符串中字符为0的情况
        int len = s.size();
        if(len == 0)return 0;
        int dp[len+1];//dp[i]表示s[0...i-1]的解码方法数目
        dp[0] = 1;
        if(s[0] != '0')dp[1] = 1;
        else dp[1] = 0;
        for(int i = 2; i <= len; i++)
        {
            if(s[i-1] != '0')
                dp[i] = dp[i-1];
            else dp[i] = 0;
            if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))
                dp[i] += dp[i-2];
        }
        return dp[len];
    }
};