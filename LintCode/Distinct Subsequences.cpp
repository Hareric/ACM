class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
     
  
    int numDistinct(string &S, string &T) {
        // write your code here
        int s = S.size()+1, t=T.size()+1;
        if (t <= 1){
            return 1;
        }
        int DP[s][t];
        memset( DP, 0, s*t*sizeof(int) );
        for (int i=0; i<=S.size(); i++){
            DP[i][0] = 1;
        }
        for (int i=1; i<=S.size(); i++){
            for (int j=1; j<=T.size(); j++){
                if (S[i-1]==T[j-1]){
                    DP[i][j] = DP[i-1][j-1] + DP[i-1][j];
                }
                else {
                    DP[i][j] = DP[i-1][j];
                }
            }
        }
        return DP[S.size()][T.size()];
    }
};
