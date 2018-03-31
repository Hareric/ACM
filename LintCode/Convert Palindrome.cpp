class Solution {
public:
    /**
     * @param str: String
     * @return: String
     */
     
     
    bool isPalindrome(string &str){
        for (int i=0; i<(str.length()/2); i++){
            if (str[i] != str[str.length()-i-1]){
                return false;
            }
        }
        return true;
        
    } 
    
    string convertPalindrome(string &str) {
        // Write your code here
        string dubstr = string(str);
        for (int i=0; i<str.length(); i++){
            dubstr = str[i] + dubstr;
        }
        string result = dubstr;
        for (int i=1; i<=str.length(); i++){  //从中往前一个一个截去并判断是否为回文字符串
            string s;
            s = string(dubstr,0, str.length()-i) + str;
            if (isPalindrome(s)){
                result = s;
            }
        }
        return result;
    }
};
