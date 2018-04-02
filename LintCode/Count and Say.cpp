class Solution {
public:
    /**
     * @param n: the nth
     * @return: the nth sequence
     */
     
    string nextNum(string s){
        string ss = "";
        char preC = s[0];
        int times = 1;
        for (int i=1; i<s.length(); i++){
            if (s[i] != preC){
                ss += to_string(times);
                ss += preC;
                times = 1;
                preC = s[i];
            }
            else{
                times ++;
            }
        }
        ss += to_string(times);
        ss += preC;
        return ss;
    }
    
    string countAndSay(int n) {
        // write your code here
        string result = "1";
        for (int i=1; i<n; i++){
            result = nextNum(result);
        }
        return result;
    }
};
