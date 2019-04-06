public class LongestCommonPrefix {
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    public static String longestCommonPrefix(String[] strs) 
    {
        // write your code here
        if (strs.length == 0)
            return "";
        
        return recursion(strs, 0, strs.length-1);
    }
    
    public static String recursion(String[] strs, int start, int end) 
    {
        // write your code here
        if(start==end)
            return strs[start];
        int mid = (start + end) / 2;
        return longestCommon(recursion(strs, start, mid), recursion(strs, mid+1, end));
        
    }
    public static String ss = new String();
    public static String longestCommon(String str1, String str2) 
    {
        // write your code here
        String s = "";
        int l = Math.min(str1.length(), str2.length());
        for(int i=0; i<l; i++)
        {
            if(str1.charAt(i)==str2.charAt(i))
                s += ss.valueOf(str1.charAt(i));
            else
                break;
        }
        return s;
    }
}
