class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double squareSum(vector<int> A){
        double re = 0;
        for(int i=0; i<A.size(); i++){
            re += pow(A[i], 2);
        }
        return re;
    }
    double multiSum(vector<int> A, vector<int> B){
        double re = 0;
        for(int i=0; i<A.size(); i++){
            re += A[i] * B[i];
        }
        return re;
    }
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        if(A.size()!=B.size()){
            return 2.0;
        }
        double A0 = pow(squareSum(A), 0.5);
        double B0 = pow(squareSum(B), 0.5);
        if(A0==0||B0==0){
            return 2.0;
        }
        return multiSum(A, B) / (A0 * B0);
    }
};
