/*

N-Queens

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/



class Solution {
public:
    bool isValid(vector<string> &board, int x, int y) {
        for (int i = 0; i < x; ++i) {
            if (board[i][y] == 'Q') return false;
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                if (i != x && j != y && i-j == x-y && board[i][j] == 'Q')
                    return false;
                if (i != x && j != y && i+j == x+y && board[i][j] == 'Q')
                    return false;
            }
        }
        return true;
    }
    
    void solveHelper(vector<vector<string> > &res, vector<string> &board, int idx) {
        if (idx == board.size()) {
            res.push_back(board);
            return;
        }
        for (int i = 0; i < board.size(); ++i) {
            board[idx][i] = 'Q';
            if (isValid(board, idx, i)) {
                solveHelper(res, board, idx + 1);
            }
            board[idx][i] = '.';
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> board;
        string row;
        for (int i = 0; i < n; ++i) {
            row.push_back('.');
        }
        for (int i = 0; i < n; ++i) {
            board.push_back(row);
        }
        solveHelper(res, board, 0);
        return res;
    }
};