/*

Distinct Subsequences


Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

从个字符串S的尾部开始扫描，找到第一个和T最后一个字符相同的位置k，那么有下面两种匹配：a. T的最后一个字符和S[k]匹配，b. T的最后一个字符不和S[k]匹配。a相当于子问题:从S[0...lens-2]中删除几个字符得到T[0...lent-2]，b相当于子问题：从S[0...lens-2]中删除几个字符得到T[0...lent-1]


设dp[i][j]是从字符串S[0...i]中删除几个字符得到字符串T[0...j]的不同的删除方法种类，有上面递归的分析可知，动态规划方程如下

如果S[i] = T[j], dp[i][j] = dp[i-1][j-1]+dp[i-1][j]
如果S[i] 不等于 T[j], dp[i][j] = dp[i-1][j]
初始条件：当T为空字符串时，从任意的S删除几个字符得到T的方法为1
*/


class Solution {
public:
    int numDistinct(string S, string T) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int lens = S.length(), lent = T.length();
        if(lent == 0)return 1;
        else if(lens == 0)return 0;
        int dp[lens+1][lent+1];
        memset(dp, 0 , sizeof(dp));
        for(int i = 0; i <= lens; i++)dp[i][0] = 1;
        for(int i = 1; i <= lens; i++)
        {
            for(int j = 1; j <= lent; j++)
            {
                if(S[i-1] == T[j-1])
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[lens][lent];
    }
};