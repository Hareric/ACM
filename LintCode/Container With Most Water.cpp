class Solution {
public:
    /*
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        if (heights.size() <= 1){
            return 0;
        }
        int maxValue = 0, minHight=heights[0], temp;
        for (int i=1; i<heights.size(); i++){
            if (heights[i-1] < minHight){
                continue;
            }
            for (int j=i+1; j<=heights.size(); j++){
                temp = min(heights[i-1], heights[j-1]) * (j-i);
                if ( temp > maxValue){
                    maxValue = temp;
                    minHight = min(heights[i-1], heights[j-1]);
                }
            }
        }
        return maxValue;
                write your code here 
                
        // better answer
        // int ret = 0;  
        // int r = heights.size()-1;  
        // int l = 0;  
        // while (l < r)  
        // {  
        //     ret = max(ret,min(heights[l],heights[r])*(r-l));  
        //     if(heights[l]<heights[r])  
        //         l++;  
        //     else   
        //         r--;  
        // }  
        // return ret; 
    }
};
