/*

Unique Paths II

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
*/

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        int m = obstacleGrid.size();
        if(m <= 0){
            return 0;
        }
        int n = obstacleGrid[0].size();
        if(n <= 0){
            return 0;
        }
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        
        int map[101][101];
        map[0][0]=1;
        for(int i = 1; i < m; i++){
            if(obstacleGrid[i][0]==1)
                map[i][0] = 0;
            else
                map[i][0] = map[i-1][0];
        } 
        for(int i = 1;i < n; i++){
             if(obstacleGrid[0][i] == 1)
                map[0][i] = 0;
            else
                map[0][i] = map[0][i-1];
        } 
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    map[i][j] = 0;
                }
                else
                    map[i][j] = map[i-1][j] + map[i][j-1];
            }
            
        return map[m-1][n-1];
    }
};