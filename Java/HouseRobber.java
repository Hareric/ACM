public class HouseRobber {
    /**
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    public long houseRobber(int[] A) 
    {
        // write your code here
        if(A.length <=0)
            return 0;
        if(A.length ==1)
            return A[0];
        if(A.length == 2)
            return Math.max(A[0], A[1]);
        long dp1 = A[0]; 
        long dp2 = Math.max(A[0], A[1]);
        long dp3 = Math.max(A[0]+A[2], A[1]);
        long tmp;
        for(int i=3; i<A.length; i++)
        {
            tmp = dp3;
            dp3 = A[i] + Math.max(dp1, dp2);
            dp1 = dp2;
            dp2 = tmp;
        }
        
        return Math.max(dp3, dp2);
    }
}
