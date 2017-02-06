class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
     
    vector<vector<int> > subsetList;
    vector<int> nums;
    void backTrack(int i, vector<int> subset){
        if (i == nums.size()){
            subsetList.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        backTrack(i+1, subset);
        subset.pop_back();
        backTrack(i+1, subset);
        
        return;
    }
    
    
    
    vector<vector<int> > subsets(vector<int> &nums) {
    	// write your code here
    	this->nums = nums;
    	vector<int> subset;
    	backTrack(0, subset);
    	return this->subsetList;
    	
    }
};
