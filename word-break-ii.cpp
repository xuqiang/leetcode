/*

 Word Break II


 Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].


*/



class Solution {
public:
    void breakWord(vector<string> &res, string &s, unordered_set<string> &dict, string str, int idx, vector<bool> &dp) {
        string substr;
        for (int len = 1; idx + len < s.length() + 1; ++len) {
            if (dp[idx + len] && dict.count(s.substr(idx,len)) > 0) {
                substr = s.substr(idx, len);
                if (idx + len < s.length()) {
                    breakWord(res, s, dict, str + substr + " ", idx + len, dp);
                } else {
                    res.push_back(str + substr);
                    return;
                }
            }
        }
    }
    
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 0; i < s.length(); ++i) {
            if (dp[i]) {
                for (int len = 1; i + len < s.length() + 1; ++len) {
                    if (dict.count(s.substr(i, len)) > 0) {
                        dp[i + len] = true;
                    }
                }
            }
        }
        vector<string> res;
        if (dp[s.length()]) 
            breakWord(res, s, dict, "", 0, dp);
        return res;
    }
};
