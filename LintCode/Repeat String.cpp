class Solution {
public:
    /**
     * @param A: string A to be repeated
     * @param B: string B
     * @return: the minimum number of times A has to be repeated
     */
    int repeatedString(string &A, string &B) {
        // write your code here
        int result = 0;
        for (int j=0; j<A.length();j++){
            if (B[0]==A[j]){
                result ++;
                for (int a=0,b=j; a<B.length(); a++, b++){
                    if (b == A.length()){
                        b = 0;
                        if (B[a]==A[b]){
                            result++;
                            continue;
                        }
                        else{
                            result = 0;
                            break;
                        }
                    }
                    if (B[a]==A[b]){
                        continue;
                    }
                    else{
                        result = 0;
                        break;
                    }
                }
            }
            if (result>0){
                break;
            }
        }
        
        if (result > 0){
            return result;
        }
        else{
            return -1;
        }
    }
};
