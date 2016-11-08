class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> numbers, int target) {
        // write your code here
        sort(numbers.begin(), numbers.end());
        int bestSum = numbers[0] + numbers[1] + numbers[2];
        for (int i = 1; i < numbers.size()-1; i++) {
            int start = i + 1, end = numbers.size() - 1;
            int sum = numbers[i-1] + numbers[i] + numbers[i+1];
                if (abs(target - sum) < abs(target - bestSum)) {
                    bestSum = sum;
                }

        }
        
        return bestSum;
    }
};
