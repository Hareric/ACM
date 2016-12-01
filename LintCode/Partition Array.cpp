class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int p = 0;  
        for(int i=0;i<nums.size();i++)  
        {  
            if(nums[i]<k)  
            {  
                swap(nums[i],nums[p]);  
                p++;  
            }  
        }  
        return p;  
    }
};
