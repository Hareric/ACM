class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        if(A.length()==0 || B.length()==0){
            return 0;
        }
        int lcs[A.length()][B.length()];
        for (int i=0; i<A.length(); i++){
            for (int j=0; j<B.length(); j++){
                lcs[i][j] = 0;
            }
        }
        for (int i=0; i<B.length(); i++){
            if (A[0]==B[i]){
                for (int j=i; j<B.length(); j++){
                    lcs[0][j] = 1;
                }
                break;
            }
        }
        for (int i=0; i<A.length(); i++){
            if(B[0]==A[i]){
                for (int j=i; j<A.length(); j++){
                    lcs[j][0] = 1;
                }
                break;
            }
            
        }
        
        for(int i=1; i<A.length(); i++){
            for(int j=1; j<B.length(); j++){
                if (A[i]==B[j]){
                    lcs[i][j] = max(lcs[i-1][j-1] + 1, max(lcs[i-1][j],lcs[i][j-1]));
                }
                else{
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                }
            }
        }
        return lcs[A.length()-1][B.length()-1];
    }
};
