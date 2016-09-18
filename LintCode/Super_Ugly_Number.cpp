class Solution {
public:
    /**
     * @param n a positive integer
     * @param primes the given prime list
     * @return the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // Write your code here

        vector<int> l(primes.size(), 0);
        vector<int> uglyList(1,1);
        for (int i=1; i<n; i++)
        {
            int tempMin = uglyList[l[0]] * primes[0];
            int lMin = 0;
            for (int j=1; j<primes.size(); j++)
            {
                if ((uglyList[l[j]] * primes[j]) < tempMin)
                {
                    tempMin = uglyList[l[j]] * primes[j];
                    lMin = j;
                }
            }
            l[lMin] ++;
            uglyList.push_back(tempMin);
            for (int j=0; j<primes.size(); j++)
            {
                if ((uglyList[l[j]] * primes[j]) == tempMin)
                    l[j]++;
            }
        }
        return uglyList.back();
    }
};
