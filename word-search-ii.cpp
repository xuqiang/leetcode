/*

Word Search II

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].


所以先用所给的单词来构建字典树，然后在dfs搜索字典树中的单词，这样就避免了大量的重复比较。
另外如果搜索的路径已经不是字典树是的前缀了就可以直接剪枝返回了。




*/



class Solution {
public:
    struct TriNode {
        TriNode *ch[26];
        bool isWord;
        TriNode() : isWord(false) {
            for (auto &a : ch) a = NULL;
        }
    } *root;
    
    void insert(string word) {
        TriNode *p = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (p->ch[i] == NULL) p->ch[i] = new TriNode();
            p = p->ch[i];
        }
        p->isWord = true;
    }
    
    bool isPrefix(string word) {
        TriNode *p = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (p->ch[i] == NULL) return false;
            p = p->ch[i];
        }
        return true;
    }
    
    bool isWord(string word) {
        TriNode *p = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (p->ch[i] == NULL) return false;
            p = p->ch[i];
        }
        return p->isWord;
    }
    
    Solution() {
        root = new TriNode();
    }
    
    bool isValid(vector<vector<char>> &board, vector<vector<bool>> &visit, int x, int y) {
        int m = board.size(), n = board[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || visit[x][y]) return false;
        return true;
    }
    
    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &visit, set<string> &st, string &s, int x, int y) {
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        visit[x][y] = true;
        int xx, yy;
        for (int i = 0; i < 4; ++i) {
            xx = x + dx[i]; yy = y + dy[i];
            if (isValid(board, visit, xx, yy)) {
                s.push_back(board[xx][yy]);
                if (isWord(s)) st.insert(s);
                if (isPrefix(s)) dfs(board, visit, st, s, xx, yy);
                s.pop_back();
            }
        }
        visit[x][y] = false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.empty() || board[0].empty() || words.empty()) return res;
        for (auto &word : words) insert(word);
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        string s;
        set<string> st;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                s.push_back(board[i][j]);
                if (isWord(s)) st.insert(s);
                if (isPrefix(s)) dfs(board, visit, st, s, i, j);
                s.pop_back();
            }
        }
        for (auto &word : st) res.push_back(word);
        return res;
    }
};