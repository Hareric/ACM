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
        int t = 0;  // 连续相同的数字的个数
        while (true){
            if (i+t>=nums.size()){
                break;
            }
            if (nums[i] == nums[i+t])
                t++;
            else
                break;
        }
        for (int tt=1; tt<=t; tt++){
            for (int ttt=0; ttt<tt; ttt++){
                subset.push_back(nums[i]);
            }
            backTrack(i+t, subset);
            for (int ttt=0; ttt<tt; ttt++){
                subset.pop_back();
            }
        }
        backTrack(i+t, subset);

        
        return;
    }
    
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
    	// write your code here
    	sort(nums.begin(), nums.end());
    	this->nums = nums;
    	vector<int> subset;
    	backTrack(0, subset);
    	return this->subsetList;
    	
    }
};
