/*
 
 构造累加数组

*/

class NumMatrix {
private:
    vector<vector<int>> acc;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty()) return;
        int n = matrix.size(), m = matrix[0].size();
        acc.resize(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; ++i) acc[i][0] = 0;
        for (int j = 0; j <= m; ++j) acc[0][j] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                acc[i][j] = acc[i][j-1] + acc[i-1][j] - acc[i-1][j-1] + matrix[i-1][j-1];
            }
        } 
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return acc[row2 + 1][col2 + 1] - acc[row1][col2 + 1] - acc[row2 + 1][col1] + acc[row1][col1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);