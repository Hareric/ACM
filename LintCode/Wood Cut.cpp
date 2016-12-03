class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        int first = 1,last = 1,mid,kk;
        for (const auto &elem : L)
            last = max(last, elem);
        while(first+1<last){
            int mid = first + (last - first) / 2;
            kk = getCount(L, mid);
            if(kk<k){
                last = mid;
            }
            else{
                first = mid;
            }
        }
        if(first!=last){
            int s=getCount(L,first),r=getCount(L,last);
            if(r>=k){
                kk = r;
                mid = last;
            }
            else{
                kk = s;
                mid = first;
            }
        }
        if(kk>=k){
            return mid;
        }
        return 0;
    }
private: 
    int getCount(vector<int> L, int len) {
            int sum = 0;
            for (const auto &elem : L)
                sum += elem / len;
            return sum;
    }
};
