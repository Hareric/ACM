class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        // write your code here
        int temp_max = 0;
        int result = nums[0];
        int t = 0;  // 用来计算累积值
        for (int i=0; i<nums.size(); i++){
            if (i>0 && nums[i-1]>0){
                continue;
            }
            if (nums[i] > 0){
                temp_max = 0;
                t = 0;
                for (int j=i; j<nums.size(); j++){
                    t += nums[j];
                    if (t > 0){  // 若累积值大于0， 则将该子串的和加起来
                        temp_max += t;
                        t = 0;
                    }
                }
                result = max(result, temp_max);
            }
        }
        return result;
    }
};
