class Solution {
public:
    /*
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> values) {
        // write your code here
        if(values.size()<3){
            return true;
        }
        if(values.size()==3){
            return values[0]+values[1]>values[2];
        }
        int maxValues[values.size()+2] = {0};
        maxValues[values.size()-1] = values[values.size()-1];
        maxValues[values.size()-2] = values[values.size()-1] + values[values.size()-2];
        maxValues[values.size()-3] = values[values.size()-2] + values[values.size()-3];
        int secondLocation = 0;
        for (int i=values.size()-4; i>=0; i--){
            int a = values[i] + min(maxValues[i+2], maxValues[i+3]);
            int b = values[i]+values[i+1]+min(maxValues[i+3], maxValues[i+4]);
            maxValues[i] = max(a, b);
            secondLocation = a > b ? 1 : 2;
        }
        return maxValues[0] > maxValues[secondLocation];
    }
};
