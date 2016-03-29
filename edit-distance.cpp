/*

Edit Distance


Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

*/



class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        if (len1 == 0) return len2;
        if (len2 == 0) return len1;
        vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1));
        for (int i = 0; i <= len1; ++i) dp[i][0] = i;
        for (int j = 0; j <= len2; ++j) dp[0][j] = j;
        int cost;
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                cost = (word1[i-1] == word2[j - 1]) ? 0 : 1;
                dp[i][j] = min(dp[i-1][j-1] + cost, min(dp[i][j-1] + 1, dp[i-1][j] + 1));
            }
        }
        return dp[len1][len2];
    }
};