class Solution {
public:
    /**
     * @param nums: an array
     * @param k: a target value
     * @return: the maximum length of a subarray that sums to k
     */
     
    int maxSubArrayLen(vector<int> &nums, int k) {
        // Write your code here
        int l = nums.size();
        int book[l];
        int result = 0;
        book[l-1] = 0;
        for (int i=0; i<l; i++){
            book[l-1] += nums[i];
        }
        if (book[l-1] == k){
            return l;
        }
        for (int i=1; i<l; i++){
            for (int j=l-1-i; j<l; j++){
                if (j == l-1){
                    book[j] = book[j] - nums[i-1];
                }
                else{
                    book[j] = book[j+1] - nums[j+1];    
                }
                if (book[j] == k){
                    return l-i;
                }
                
            }
        }
        return 0;
    }
};
