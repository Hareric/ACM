class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    
    vector<vector<int> > result;
    int k;
    int n;
    void backTrack(int l,int t, vector<int> r){
        if (t == k){
            result.push_back(r);
            return;
        }
        if (l > n){
            return;
        }
        r.push_back(l);
        backTrack(l+1, t+1, r);
        r.pop_back();
        backTrack(l+1, t, r);
    }
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        this->n = n;
        this->k = k;
        vector<int> r;
        backTrack(1, 0, r);
        return this->result;
    }
};
