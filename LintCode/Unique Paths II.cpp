class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        int pathNum[m][n];
        for (int i=0; i<m; i++){
            if (obstacleGrid[i][0] == 1){
                for (int j=i; j<m; j++){
                    pathNum[j][0] = 0;
                }
                break;
            }
            else{
                pathNum[i][0] = 1;
            }
        }
        for (int i=0; i<n; i++){
            if (obstacleGrid[0][i] == 1){
                for (int j=i; j<n; j++){
                    pathNum[0][j] = 0;
                }
                break;
            }
            else{
                pathNum[0][i] = 1;
            }
        }
        for (int i=1; i<m; i++){
            for (int j=1; j<n; j++){
                if(obstacleGrid[i][j]==1){
                    pathNum[i][j] = 0;
                }
                else{
                    pathNum[i][j] = pathNum[i-1][j] + pathNum[i][j-1];
                }
            }
        }
        return pathNum[m-1][n-1];
    }
};
