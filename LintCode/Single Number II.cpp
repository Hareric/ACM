class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */

        bool isBit1(int num, int index)  {
        num = num >> index;
        return (num & 1);
    }

    int singleNumberII(vector<int> &A) {
        int n = A.size();
        int result = 0;
        for(int i = 0; i < 32; ++i) {
            int count = 0;
            for(int j = 0; j < n; ++j) {
                if(isBit1(A[j], i))
                    ++count;
            }
            result |= (count % 3) << i;
        }
        return result;
    }
};
