class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int comp(char c, string s, int left, int right){
        int local = -1;
        for(int i=left; i<right; i++){
            if (c==s[i])
                local = i;
        }
        return local;
    }
    int lengthOfLongestSubstring(string s) {
        // write your code here
        const int l = s.length();
        if(l==0)
            return 0;
        else if(l==1)
            return 1;
            
        int book[l];
        for(int i=0; i<l; i++){
            book[i] = 0;
        }
        
        int m = 1;
        book[0] = 1;
        int left = 0;
        int ll;
        for(int i=1; i<l; i++){
            ll = comp(s[i], s, left, i);
            if(ll == -1){
                book[i] = book[i-1] + 1;
                m = max(book[i], m);
            }
            else{
                book[i] = i - ll;
                left = ll + 1;
            }
        }
        
        return m;
    }
};
