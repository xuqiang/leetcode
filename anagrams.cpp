/*

Group Anagrams

Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

hash表实现

*/


class Solution {
public:
    // 字符串排序 hash方式
    string Sort(string a){
        int len = a.length();
        int cnt[27] = {0};
        for(int i = 0; i < a.length(); ++i){
            ++cnt[a[i] - 'a'];
        }
        string res = "";
        for(int i = 0; i < 27; ++i){
            int tmp = cnt[i];
            while(tmp){
                res += char(i + 'a');
                --tmp;
            }
        }
        return res;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map< string, vector<string> >map;
        for(int i = 0; i <strs.size(); ++i){
            string copy = strs[i];
            sort(copy.begin(), copy.end());
            // copy = Sort(copy);
            if(map.find(copy) == map.end()){
                vector<string> anagrams;
                anagrams.push_back(strs[i]);
                map[copy] = anagrams;
            }
            else map[copy].push_back(strs[i]);
        }
        
        vector< vector<string> >res;
        for(auto str : map){
            sort(str.second.begin(), str.second.end());
            vector<string> tmp = str.second;
            
            res.push_back(tmp);
        }
        return res;
    
    }
};