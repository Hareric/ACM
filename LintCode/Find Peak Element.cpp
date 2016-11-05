class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int find(vector<int> &A, int left, int right) {
        // write your code here
        int mid = (left + right) / 2;
        if (A[mid-1]<A[mid]&&A[mid]>A[mid+1]){
            return mid;
        }
        if(A[mid-1]>A[mid]){
            return find(A, left, mid);
        }
        if(A[mid]<A[mid+1]){
            return find(A, mid, right);
        }
        
    }
    int findPeak(vector<int> A) {
        // write your code here
        return find(A, 0, A.size()-1);
    }
};
