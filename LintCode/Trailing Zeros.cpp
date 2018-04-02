class Solution {
public:
    /*
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
    long long trailingZeros(long long n) {
        // write your code here, try to do it without arithmetic operators.
        long long result = 0;
        while (n >= 5){
            n /= 5;
            result += n; 
        }
        return result;
    }
};
