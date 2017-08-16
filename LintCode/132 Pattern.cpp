class Solution {
public:
    /**
     * @param nums a list of n integers
     * @return true if there is a 132 pattern or false
     */
    bool find132pattern(vector<int>& nums) {
        // Write your code here
        if (nums.size() <= 2){
            return false;
        }
        int minNum = nums[0], maxNum = nums[0];
        for (int i=1; i<nums.size(); i++){
            if (nums[i] > minNum && nums[i] < maxNum){
                return true;
            }
            if (nums[i] < minNum){
                minNum = nums[i];
                continue;
            }
            else if ( nums[i] > maxNum){
                maxNum = nums[i];
                continue;
            }
        }
    }
};
