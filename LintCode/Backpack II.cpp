class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int maxValue = 0;
    
    bool isContinue(vector<pair<int, int> > &value_size, int i, int currentValue, int currentSize, int m){
        for(i; i<value_size.size(); i++){
            currentValue+=value_size[i].first;
            currentSize+=value_size[i].second;
            if (currentSize>=m){
                break;
            }
        }
        if (currentValue<=maxValue){
            return false;
        }
        return true;
    }
    void backtrack(int &m, vector<pair<int, int> > &value_size, int i, int currentValue, int currentSize){
        
        if (currentValue>maxValue){
            maxValue = currentValue;
        }
        if (i==value_size.size()){
            return;
        }
        if(currentSize+value_size[i].second<=m){
            backtrack(m, value_size, i+1, currentValue+value_size[i].first, currentSize+value_size[i].second);
        }
        if(isContinue(value_size, i+1, currentValue, currentSize, m)){
            backtrack(m, value_size, i+1, currentValue, currentSize);
        }
    }
    
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return (a.first * 1.0 /a.second) > (b.first * 1.0 /b.second);
        
    }
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        vector<pair<int, int> > value_size;
        for(int i=0; i<A.size(); i++){
            value_size.push_back(pair<int, int> (V[i], A[i]));
        }
        sort(value_size.begin(), value_size.end(), cmp);
        backtrack(m, value_size, 0, 0, 0);
        return maxValue;
    }
};
