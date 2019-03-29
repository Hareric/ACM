public class Solution {
    /**
     * @param n: n pairs
     * @return: All combinations of well-formed parentheses
     */
     
    public static boolean isLegal(String s)
    {
        char[] tmp = s.toCharArray();
        int n = 0;
        for (int i=0; i<tmp.length; i++)
        {
            if (tmp[i] == '(')
            {
                n++;
            }else
            {
                n--;
                if (n<0)
                    return false;
            }
        }
        return true;
    }
     
    static ArrayList<String> res = new ArrayList<String>(); 
    public static void backTrack(int left, int right, String s)
    {
        if (left==0 && right==0)
            res.add(s);
        if(left>0 && isLegal(s+"("))
        {
            backTrack(left-1, right, s+"(");
        }
        if(right>0 &&isLegal(s+")"))
        {
            backTrack(left, right-1, s+")");
        }
    }
     
     
     
     
     
    public static List<String> generateParenthesis(int n) 
    {
        // write your code here
        res.clear();
        String s = "";
        backTrack(n, n, s);
        return res;
    }
}
