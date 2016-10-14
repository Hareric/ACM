class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if (prices.size()<=1){
            return 0;
        }
        int pre = prices[0];
        vector<int>::iterator it=prices.begin();
        it++;
        for (it; it!=prices.end();){
            if (*it==pre){
                it = prices.erase(it);
            }
            else{
                pre = *it;
                it++;
            }
        }

        int book[prices.size()] ;
        book[0] = 0;
        for (int i=1; i<prices.size(); i++){
            book[i] = book[i-1];
            for (int j=0; j<i; j++){
                if (prices[i]>prices[j]){
                    book[i] = max(book[i], prices[i]-prices[j]);
                }
            }
        }
        return book[prices.size()-1];
    }
};
