public class FindMaxLength {
    /**
     * @param nums: a binary array
     * @return: the maximum length of a contiguous subarray
     */
    public int findMaxLength(int[] nums) 
    {
        // Write your code here
        int res = 0;
        int[] dp = new int[nums.length];
        for(int i=0; i<nums.length; i++)
        {
            if(nums[i]==0)
                dp[i] = -1;
            else
                dp[i] = 1;
        }
        
        for(int j=1; j<nums.length; j++)
        {
            for(int i=0; i+j<nums.length; i++)
            {
                if(nums[i+j]==0)
                    dp[i] -= 1;
                else
                    dp[i] += 1;
                if(dp[i]==0)
                    res = j+1;
            }
        }
        return res;
    }
}
