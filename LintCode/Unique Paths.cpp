class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        if (m<=1||n<=1){
            return 1;
        }
        int pashNum[m][n];
        for (int i=0; i<m; i++)
            pashNum[i][0] = 1;
        for (int i=0; i<n; i++)
            pashNum[0][i] = 1;  
        for (int i=1;i<m; i++){
            for (int j=1; j<n; j++){
                pashNum[i][j] = pashNum[i-1][j] + pashNum[i][j-1];
            }
        }
        return pashNum[m-1][n-1];
    }
};
