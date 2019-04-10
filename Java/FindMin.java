public class Solution {
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    public int findMin(int[] nums) 
    {
        // write your code here
        if(nums.length==1)
            return nums[0];
        if(nums.length == 2)
            return Math.min(nums[0], nums[1]);
        boolean isUp; // 是否为递增排序
        if(nums[0]<nums[1] && nums[1]<nums[2])
            isUp = true;
        else if(nums[0]>nums[1] && nums[1] > nums[2])
            isUp = false;
        else
        {
            return Math.min(Math.min(nums[0],nums[1]),nums[2]);
        }
        return recursion(nums, 0, nums.length-1, isUp);
        
    }
    
    public int recursion(int[] nums, int start, int end, boolean isUp)
    {
        if(end - start <=1)
        {
            return Math.min(nums[start], nums[end]);
        }
        int mid = (start + end) / 2;
        if (isUp)
        {
            if(nums[mid]>nums[end])
                return recursion(nums, mid, end, isUp);
            else
                return(recursion(nums, start, mid, isUp));
        }
        else
        {
           if(nums[mid]>nums[end])
                return recursion(nums, start, mid, isUp);
            else
                return(recursion(nums, mid, end, isUp));
        }
    }
}
