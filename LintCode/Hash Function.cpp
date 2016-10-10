class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        int len = key.length();
        long sum = 0;
        for (int i=0; i<len; i++){
            int asc = (int)key[i];
            sum = sum * 33 % HASH_SIZE + (int)key[i];
        }
        return sum % HASH_SIZE;
    }
};
