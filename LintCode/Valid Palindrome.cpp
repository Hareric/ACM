class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
        if (s.length()<=1){
            return true;
        }
        transform(s.begin(), s.end(), s.begin(), ::toupper);  
        int begin = 0;
        int end = s.length()-1;
        
        while (begin<end){
            if (!(isalpha(s[begin])||isdigit(s[begin]))){
                begin++;
                continue;
            }
            if (!(isalpha(s[end])||isdigit(s[end]))){
                end--;
                continue;
            }
            if (s[begin]!=s[end]){
                return false;
            }
            else{
                begin++;
                end--;
            }
        }
        return true;
    }
};
