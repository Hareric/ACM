/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    static bool cmp(const Interval &inA, const Interval &inB){
        return inA.start < inB.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        if(intervals.size()<=1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval>:: iterator it = intervals.begin() + 1;
        vector<Interval>:: iterator preit = intervals.begin();
        for(it; it!=intervals.end(); it++){
            if(it->start<= preit->end){
                preit->end = max(it->end,preit->end);
                intervals.erase(it);
                it--;
            }
            else{
                preit = it;
            }
        }
        return intervals;
    }
};
