class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        map<string, int> m;
        for(int i=0; i<strs.size(); i++){
            string t = strs[i];
            sort(t.begin(), t.end());
            if(m.find(t)!=m.end()){
                m[t] ++;
            }
            else{
                m[t] = 1;
            }
        }
        vector<string> res;
        for(int i=0; i<strs.size(); i++){
            string t = strs[i];
            sort(t.begin(), t.end());
            if (m.find(t)!=m.end()&&m[t]>1){
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};
