class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInter(string &s, string &subS1, string &subS2, int k, int i, int j){
        if(i==subS1.length() && j==subS2.length()){
            return true;
        }
        if(i!=subS1.length() && s[k]==subS1[i]){
            if(isInter(s, subS1, subS2, k+1, i+1, j)){
                return true;
            }
        }
        if(j!=subS2.length() && s[k]==subS2[j]){
            if(isInter(s, subS1, subS2, k+1, i, j+1)){
                return true;
            }
        }
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        if(s1.length()+s2.length()!=s3.length()){
            return false;
        }
        if(s3.length()==0){
            return true;
        }
        return isInter(s3, s1, s2, 0,0,0);
    }
};
