class Solution {
public:
    /*
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
 
    int maxProfit(vector<int> prices) {
        if (prices.size()<2){
            return 0;
        }
        if (prices.size()==2){
            return max(0, prices[1]-prices[0]);
        }
        int dp1_x[prices.size()+1] = {0};
        int dpx_end[prices.size()+1] = {0};

        int i = 1;
        int minT = prices[i-1];
        for(int j=i+1; j<=prices.size(); j++){
            dp1_x[j] = 0;
            minT = min(minT, prices[j-2]);
            dp1_x[j] = max(dp1_x[j-1], prices[j-1]-minT);
            
        }
        
        int res = 0;
        int maxT = prices[prices.size()-1];
        dpx_end[prices.size()] = 0;
        for(int i=prices.size()-1; i>=2 ;i--){
            dpx_end[i] = 0;
            maxT = max(maxT, prices[i]);
            dpx_end[i] = max(dpx_end[i+1], maxT-prices[i-1]);
            res = max(dp1_x[i] + dpx_end[i], res);
            
        }

        return res;
    }
};
