class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        set<int> s_1(nums1.begin(), nums1.end());
        set<int> reSet;
        for(int i=0; i<nums2.size(); i++){
            if(s_1.find(nums2[i])!=s_1.end()){
                reSet.insert(nums2[i]);
            }
        }
        return vector<int>(reSet.begin(), reSet.end());
    }
};
