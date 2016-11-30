class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void swi(vector<int> &A, int i, int j){
        A[i] += A[j];
        A[j] -= A[i];
        A[i] += A[j];
        A[j] = -A[j];
    }
    void rerange(vector<int> &A) {
        // write your code here
        int front=0,end=A.size()-1;
        while(front<=end){
            if(A[front]<0){
                front++;
                continue;
            }
            if(A[end]>0){
                end--;
                continue;
            }
            swi(A, front, end);
        }
        
        if(A.size() % 2==0){
            front = 1;end = A.size()-2;
        }
        else if(A[A.size()/2]<0){
            front = 1;end = A.size()-1;
        }
        else{
            front = 0;end = A.size()-2;
        }
        while(front<end){
            swi(A, front, end);
            front += 2;
            end -= 2;
        }
        
    }
};
