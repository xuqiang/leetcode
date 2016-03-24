/*


Letter Combinations of a Phone Number

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

*/



class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0) return res;
        string tmpres(digits.size(), ' ');
        dfs(digits, 0, tmpres, res);
        return res;
    }

    void dfs(const string &digits, int index, string &tmpres, vector<string>&res) {
        string numap[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(index == digits.size()) {
            res.push_back(tmpres);
            return;
        }
        for(int i = 0; i < numap[digits[index] - '0'].size(); i++) {
            tmpres[index] = numap[digits[index] - '0'][i];
            dfs(digits, index+1, tmpres, res);
        }
    }
};