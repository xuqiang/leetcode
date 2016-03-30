/*

 Word Ladder II


 Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.

*/


class Solution {
public:
    typedef unordered_set<string>::iterator HashIter;
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        queue<string> Q;
        Q.push(start); Q.push("");
        bool hasFound = false;
        unordered_map<string,vector<string> >prePath;//前驱路径
        unordered_set<string> hashtable;//保证bfs时插入队列的元素不存在重复
        while(Q.empty() == false) {
            string str = Q.front(), strCopy = str;
            Q.pop();
            if(str != "") {
                int strLen = str.length();
                for(int i = 0; i < strLen; i++) {
                    char tmp = str[i];
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        if(c == tmp)continue;
                        str[i] = c;
                        if(str == end)
                        {
                            hasFound = true;
                            prePath[end].push_back(strCopy);
                            //找到了一条最短路径，当前单词的其它转换就没必要
                            goto END;
                        }
                        if(dict.find(str) != dict.end())
                        {
                            prePath[str].push_back(strCopy);
                            //保证bfs时插入队列的元素不存在重复
                            if(hashtable.find(str) == hashtable.end())
                                {Q.push(str); hashtable.insert(str);}
                        }
                    }
                    str[i] = tmp;
                }
            }
            else if(Q.empty() == false)//到当前层的结尾，且不是最后一层的结尾
            {
                if(hasFound)break;
                //避免进入死循环，把bfs上一层插入队列的元素从字典中删除
                for(HashIter ite = hashtable.begin(); ite != hashtable.end(); ite++)
                    dict.erase(*ite);
                hashtable.clear();
                Q.push("");
            }
        END: ;
        }
        vector<vector<string> > res;
        if(prePath.find(end) == prePath.end())return res;
        vector<string> tmpres;
        tmpres.push_back(end);
        ConstructResult(prePath, res, tmpres, start, end);
        return res;
    }
    
private:
    //从前驱路径中回溯构造path
    void ConstructResult(unordered_map<string,vector<string> > &prePath, 
        vector<vector<string> > &res, vector<string> &tmpres, 
        string &start, string &end) {
        if(start == end) {
            reverse(tmpres.begin(), tmpres.end());
            res.push_back(tmpres);
            reverse(tmpres.begin(), tmpres.end());
            return;
        }
        vector<string> &pre = prePath[end];
        for(int i = 0; i < pre.size(); i++) {
            tmpres.push_back(pre[i]);
            ConstructResult(prePath, res, tmpres, start, pre[i]);
            tmpres.pop_back();
        }
        
    }
};