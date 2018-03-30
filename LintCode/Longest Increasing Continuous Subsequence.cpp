class Solution {
public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int> &A) {
        // write your code here
        if (A.size() <= 1){
            return A.size();
        }
        int temp_max_1=1, temp_max_2 = 1;
        int result = 1;
        for (int i=1; i<A.size(); i++){
            if (A[i] < A[i-1]){
                temp_max_1 += 1;
                result = max(result, temp_max_1);
            }
            else{
                temp_max_1 = 1;
                
            }
            if (A[i] > A[i-1]){
                temp_max_2 += 1;
                result = max(result, temp_max_2);
            }
            else{
                temp_max_2 = 1;
                
            }
            
        }
        return result;

        
    }
};
