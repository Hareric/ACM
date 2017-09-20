class Solution {
public:
    /*
     * @param A: An integer array
     * @param queries: The query list
     * @return: The number of element in the array that are smaller that the given integer
     */
    
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        vector<int> ret;
        sort(A.begin(), A.end());
        for (int i=0; i<queries.size(); i++){
            ret.push_back(0);
            for (int j=0; j<A.size(); j++){
                if (A[j] < queries[i]){
                    ret[i]++;
                }
                else{
                    break;
                }
            }
        }
        return ret;
    }
};
