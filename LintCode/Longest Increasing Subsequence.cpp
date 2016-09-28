class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        if(nums.size()==0){
            return 0;
        }
        else if(nums.size()==1){
            return 1;
        }
        vector<int> book(nums.size(), 1);
        int m = 1;
        for (int i=1; i<nums.size(); i++){
            int temp = 1;
            for (int j=0; j<i; j++){
                if (nums[i]>nums[j]){
                    temp = max(temp, book[j]+1);
                }
            book[i] = temp;
            m = max(m, temp);
            }
        }
        return m;
    }
};
