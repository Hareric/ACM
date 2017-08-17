class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        
        set<vector<int> > res;
        if (nums.size() < 4){
            return vector<vector<int> >(res.begin(), res.end());
        }
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-3; i++){
            
            for (int j=i+1; j<nums.size()-2; j++){
                int x = j + 1, y = nums.size()-1, newTarget = target-nums[i]-nums[j];
                while(x<y){
                    if(nums[x]+nums[y]==newTarget){
                        res.insert({nums[i], nums[j], nums[x], nums[y]});
                        x++; y--;
                    }
                    else if (nums[x]+nums[y]>newTarget){
                        y--;
                    }
                    else{
                        x++;
                    }
                }
            }
        }
        return vector<vector<int> >(res.begin(), res.end());
    }
};

