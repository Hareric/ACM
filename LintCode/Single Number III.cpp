class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
     
    bool is1(int num, int index){
        return ( (num >> index) & 1 );
    }
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        int r = A[0];
        for(int i=1; i<A.size(); i++){
            r = r ^ A[i];
        }
        int l;
        for (int i=0; i<32; i++){
            if(is1(r, i)){
                l = i;
            }
        }
        vector<int> res(2, -1);
        for(int i=0; i<A.size(); i++){
            if(is1(A[i],l)){
                if(res[0]==-1){
                    res[0] = A[i];
                }
                else{
                    res[0] = res[0] ^ A[i];
                }
            }
            else{
                if(res[1]==-1){
                    res[1] = A[i];
                }
                else{
                    res[1] = res[1] ^ A[i];
                }
            }
        }
        return res;
    }
};
