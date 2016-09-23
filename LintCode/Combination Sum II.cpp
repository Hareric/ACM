class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > books;  
    int sum = 0;
    
    bool comp(vector<int> &vec1, vector<int> &vec2){
        if (vec1.size()!=vec2.size())
            return false;
        for (int i=0; i<vec1.size(); i++){
            if (vec1[i]!=vec2[i]){
                return false;
            }
        }
        return true;
    }
    
    bool isIn(vector<int> &book){
        for (int i=0; i<books.size(); i++){
            if (comp(book, books[i])){
                return true;
            }
        }
        return false;
    }
    
    void backTrack(vector<int> &candidates, int &target, int i, vector<int> &book){
         if (i==candidates.size()){
             int temp = 0;
             vector<int> vecTemp;
             for (int t=0; t<book.size(); t++){
                if (book[t] == 1){
                    temp += candidates[t];
                    vecTemp.push_back(candidates[t]);
                }
            }
            if (temp==target&&(!isIn(vecTemp))){
                    books.push_back(vecTemp);
             }
             return;
         }
         if (sum+candidates[i]<=target){
             book[i] = 1;
             sum += candidates[i];
             backTrack(candidates, target, i+1, book);
             book[i] = 0;
             sum -= candidates[i];
         }
         if(true){
             book[i] = 0;
             backTrack(candidates, target, i+1, book);
         }
     }
     
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        // write your code here
        sort(candidates.begin(), candidates.end());
        vector<int> book(candidates.size(), 0);
        backTrack(candidates, target, 0, book);
        return books;
    }
};
