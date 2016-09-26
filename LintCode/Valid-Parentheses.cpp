class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        //Write your code here
        int kuohao = 0;
        int zhongkuohao = 0;
        int dakuohao = 0;
        stack<char> sta;
        for (int i=0; i<s.length(); i++){
            if ( (s[i]==']'&&sta.top()=='[') || (s[i]=='}'&&sta.top()=='{') || (s[i]==')'&&sta.top()=='(')){
                sta.pop();
            }
            else{
                sta.push(s[i]);
            }
        }
        if (sta.size()>0){
            return false;
        }
        else{
            return true;
        }

    }
};
